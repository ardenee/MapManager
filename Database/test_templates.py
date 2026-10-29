from pathlib import Path
import sqlite3,xml.etree.ElementTree as ET,tempfile,shutil
root=Path(__file__).resolve().parent.parent
src=ET.parse(root/"Settings"/"Settings.xml").getroot()
p=root/"Database"/"templates"/"settings.sqlite3"
with sqlite3.connect("file:"+p.as_posix()+"?mode=ro",uri=True) as db:
 assert db.execute("PRAGMA integrity_check").fetchone()[0]=="ok"
 payload=db.execute("SELECT XmlData FROM SettingsDocument WHERE Id=1").fetchone()[0]
 copy=ET.fromstring(payload)
 assert len(copy.find("GameSettings"))==len(src.find("GameSettings"))==17
 assert len(copy.find("GameTypes"))==len(src.find("GameTypes"))==17
 for x,y in zip(src.find("GameSettings"),copy.find("GameSettings")):
  assert ET.tostring(x,encoding="unicode")==ET.tostring(y,encoding="unicode")
  gid=int(x.get("id"))
  scalar={c.tag:(c.text or "") for c in x.find("GameData") if len(c)==0}
  row=db.execute("SELECT "+",".join('"'+n+'"' for n in scalar)+" FROM GameSettings WHERE gameid=?",(gid,)).fetchone()
  assert row is not None
  assert [str(x) if x is not None else "" for x in row]==list(scalar.values()),gid
  assert db.execute("SELECT count(*) FROM GameNestedData WHERE GameId=?",(gid,)).fetchone()[0]==7
 assert db.execute("SELECT LastSeletedGame FROM Settings").fetchone()[0]==int(src.findtext("LastGameType"))
 print("PASS: 17 games, all 35 scalar values/profile, seven nested sections/profile, full XML parity")
for name,table in (("cache","Files"),("logs","LogEntries")):
 with sqlite3.connect("file:"+(root/"Database"/"templates"/(name+".sqlite3")).as_posix()+"?mode=ro",uri=True) as db:
  assert db.execute("PRAGMA integrity_check").fetchone()[0]=="ok"
  assert db.execute("SELECT count(*) FROM "+table).fetchone()[0]==0
  print("PASS: "+name+" template integrity and empty "+table)
with tempfile.TemporaryDirectory() as tmp:
 dest=Path(tmp)/"settings.sqlite3"
 shutil.copy2(p,dest)
 with sqlite3.connect(dest) as db:
  db.execute("BEGIN IMMEDIATE")
  db.execute("UPDATE Settings SET LastSeletedGame=?",(3,))
  updated=payload.replace("<LastGameType>2</LastGameType>","<LastGameType>3</LastGameType>",1)
  assert updated!=payload
  db.execute("UPDATE SettingsDocument SET XmlData=? WHERE Id=1",(updated,))
  db.commit()
 with sqlite3.connect(dest) as db:
  assert db.execute("select LastSeletedGame from Settings").fetchone()[0]==3
  assert ET.fromstring(db.execute("select XmlData from SettingsDocument").fetchone()[0]).findtext("LastGameType")=="3"
 db.close()
 print("PASS: transactional SQLite settings save/reload")
