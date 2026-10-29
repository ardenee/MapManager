from pathlib import Path
import sqlite3,xml.etree.ElementTree as ET
ROOT=Path(__file__).resolve().parent.parent
TEMPL=Path(__file__).resolve().parent/"templates"
TEMPL.mkdir(parents=True,exist_ok=True)
LEGACY=Path(r"C:\Users\arden\source\repos\Map Manager\mm-setup\Win32\Debug\settings.sqlite3")
XML=ROOT/"Settings/Settings.xml"
assert XML.exists()
dest=TEMPL/"settings.sqlite3"
if dest.exists():dest.unlink()
db=sqlite3.connect(dest)
source_script=ROOT/"Database"/"legacy_settings.sql"
if source_script.exists():
 db.executescript(source_script.read_text(encoding="utf-8"))
else:
 assert LEGACY.exists(), "Missing both portable Database/legacy_settings.sql and original historical DB"
 src=sqlite3.connect(f"file:{LEGACY.as_posix()}?mode=ro",uri=True)
 src.backup(db)
 src.close()
tree=ET.parse(XML);games=tree.getroot()
profiles=games.find("GameSettings")
assert len(profiles)==17
items=list(profiles)
db.execute("CREATE TABLE IF NOT EXISTS SettingsDocument (Id INTEGER PRIMARY KEY CHECK (Id=1), XmlData TEXT NOT NULL, Version INTEGER NOT NULL DEFAULT 1)")
db.execute("CREATE TABLE IF NOT EXISTS GameNestedData (GameId INTEGER NOT NULL, Section TEXT NOT NULL, XmlData TEXT NOT NULL, PRIMARY KEY (GameId,Section))")
db.execute("CREATE TABLE IF NOT EXISTS SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL)")
db.execute("INSERT OR REPLACE INTO SchemaVersion VALUES ('settings',1)")
xml_content=XML.read_text(encoding="utf-8-sig")
db.execute("INSERT OR REPLACE INTO SettingsDocument(Id,XmlData,Version) VALUES (1,?,1)",(xml_content,))
selected=int(games.findtext("LastGameType","2"))
db.execute("DELETE FROM Settings")
db.execute("INSERT INTO Settings(LastSeletedGame) VALUES (?)",(selected,))
db.execute("DELETE FROM GameSettings")
db.execute("DELETE FROM GameNestedData")
# Extend the recovered schema for all scalar XML fields that the 2005 DB
# lacked (MapsExt, MusicExt, ScreenShotExt, TexturesExt, etc.).
old_cols={c[1] for c in db.execute("PRAGMA table_info(GameSettings)")}
scalar=[x.tag for x in items[0].find("GameData") if len(x)==0]
for field in scalar:
 if field not in old_cols:
  db.execute('ALTER TABLE GameSettings ADD COLUMN "'+field+'" TEXT')
cols=[c[1] for c in db.execute("PRAGMA table_info(GameSettings)") if c[1] not in ("id","gameid")]
for elem in items:
 gid=int(elem.get("id"))
 fields=elem.find("GameData")
 vals={c.tag:(c.text or "") for c in fields if len(c)==0}
 missing=[col for col in cols if col not in vals]
 assert not missing, (gid,missing)
 insert=["gameid"]+cols
 db.execute("INSERT INTO GameSettings("+",".join('"'+x+'"' for x in insert)+") VALUES ("+",".join("?" for x in insert)+")",[gid]+[vals[c] for c in cols])
 for sect in fields:
  if len(sect):
   db.execute("INSERT INTO GameNestedData(GameId,Section,XmlData) VALUES (?,?,?)",(gid,sect.tag,ET.tostring(sect,encoding="unicode")))
db.commit()
print("SETTINGS",dest,"SIZE",dest.stat().st_size,"TABLES",[row[0] for row in db.execute("select name from sqlite_master where type='table' and name not like 'sqlite_%'")])
print("XML profiles",len(items),"DB profiles",db.execute("select count(*) from GameSettings").fetchone()[0],"NESTED",db.execute("select count(*) from GameNestedData").fetchone()[0],"DOC_SIZE",db.execute("select length(XmlData) from SettingsDocument").fetchone()[0])
assert db.execute("PRAGMA integrity_check").fetchone()[0]=="ok"
assert db.execute("select XmlData from SettingsDocument where Id=1").fetchone()[0]==xml_content
db.close()
cache=TEMPL/"cache.sqlite3"
if cache.exists():cache.unlink()
c=sqlite3.connect(cache)
c.executescript("""CREATE TABLE IF NOT EXISTS Files (
ID INTEGER PRIMARY KEY AUTOINCREMENT, Num INTEGER NOT NULL, BelongsTo INTEGER DEFAULT 0,
FileName BLOB, FileSize INTEGER DEFAULT 0, FileDate TEXT, FileLocation TEXT,
Installed INTEGER NOT NULL DEFAULT 0, CRC32 TEXT);
CREATE INDEX IF NOT EXISTS IX_Files_Location ON Files(FileLocation, FileName);
CREATE TABLE IF NOT EXISTS SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL);
INSERT OR REPLACE INTO SchemaVersion VALUES ('cache',1);
""")
c.commit();assert c.execute("pragma integrity_check").fetchone()[0]=="ok"
print("CACHE",cache,"SCHEMA_READY",c.execute("select count(*) from Files").fetchone()[0]);c.close()
logs=TEMPL/"logs.sqlite3"
if logs.exists():logs.unlink()
c=sqlite3.connect(logs)
c.executescript("""CREATE TABLE IF NOT EXISTS LogEntries (
Id INTEGER PRIMARY KEY AUTOINCREMENT, GameType INTEGER, FileName TEXT NOT NULL,
FileLocation TEXT, FileSize INTEGER DEFAULT 0, FileDate TEXT, CRC32 TEXT,
Operation TEXT, CreatedAt TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP);
CREATE INDEX IF NOT EXISTS IX_LogEntries_Game ON LogEntries(GameType, CreatedAt);
CREATE TABLE IF NOT EXISTS SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL);
INSERT OR REPLACE INTO SchemaVersion VALUES ('logs',1);
""")
c.commit();assert c.execute("pragma integrity_check").fetchone()[0]=="ok"
print("LOGS",logs,"SCHEMA_READY");c.close()
schematxt=[]
for name in ["settings","cache","logs"]:
 x=sqlite3.connect(TEMPL/(name+".sqlite3"))
 schematxt.append("-- "+name+".sqlite3\n"+"\n".join(str(row[0])+";" for row in x.execute("select sql from sqlite_master where type in ('table','index') and sql is not null order by type desc,name"))+"\n")
 x.close()
(ROOT/"Database"/"SCHEMA.md").write_text("# Map Manager database schemas\n\nRecovered from the original historical settings/cache SQLite files. Three binary templates are versioned. SettingsDocument stores all 17 profiles and nested menus/tables/icons in SQLite; GameSettings is a relational snapshot. Active runtime changes persist through SettingsDocument and Settings; other historical relational snapshots are not currently updated by the UI. Logs schema is reserved for future XML logs migration.\n\n"+"".join(t+"\n" for t in schematxt),encoding="utf-8")
print("Schema documented")
