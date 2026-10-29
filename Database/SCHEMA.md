# Map Manager database schemas

Recovered from the original historical settings/cache SQLite files. Three binary templates are versioned. SettingsDocument stores all 17 profiles and nested menus/tables/icons in SQLite; GameSettings is a relational snapshot. The application writes SettingsDocument, Settings, the active GameSettings row, and its seven GameNestedData sections transactionally. Historical reference tables such as FileFilters and Menus are retained for schema compatibility but not yet live writable UI tables. Logs schema is reserved for future XML logs migration.

-- settings.sqlite3
CREATE TABLE "CacheFiles" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	INTEGER,
	`folder`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER DEFAULT 2
);
CREATE TABLE "FileExts" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER
);
CREATE TABLE "FileFilters" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER
);
CREATE TABLE "FileIcons" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`gametype`	INTEGER,
	`iconid`	INTEGER DEFAULT 0
);
CREATE TABLE "FileTypes" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`filegrouptype`	INTEGER NOT NULL DEFAULT 0,
	`ext`	TEXT,
	`gametype`	INTEGER
);
CREATE TABLE "FileTypesGroups" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
CREATE TABLE GameNestedData (GameId INTEGER NOT NULL, Section TEXT NOT NULL, XmlData TEXT NOT NULL, PRIMARY KEY (GameId,Section));
CREATE TABLE `GameSettings` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`gameid`	INTEGER,
	`ArchiveFolder`	TEXT,
	`ArchiveSubFolders`	INTEGER NOT NULL DEFAULT 1,
	`CacheFolder`	TEXT,
	`CacheFile`	TEXT DEFAULT 'cache.ini',
	`CacheMode`	INTEGER NOT NULL DEFAULT 1,
	`ColArrange`	INTEGER NOT NULL DEFAULT 1,
	`ColorCodeText`	INTEGER NOT NULL DEFAULT 1,
	`DemoExt`	TEXT DEFAULT '.dem',
	`DemosFolder`	TEXT,
	`FilterRequired`	INTEGER NOT NULL DEFAULT 1,
	`GameEXE`	TEXT,
	`GameFolder`	TEXT,
	`GameMode`	INTEGER NOT NULL DEFAULT 0,
	`GameTag`	TEXT,
	`InstallMode`	INTEGER NOT NULL DEFAULT 1,
	`InstallType`	INTEGER NOT NULL DEFAULT 1,
	`LogFile`	TEXT DEFAULT 'logs.sqlite3',
	`LoadArchivesType`	INTEGER NOT NULL DEFAULT 3,
	`MapFolder`	TEXT,
	`MapSubFolders`	INTEGER NOT NULL DEFAULT 1,
	`ProgramFolder`	TEXT,
	`PlayGameString`	TEXT,
	`RegKey`	TEXT,
	`ScreenShotsFolder`	TEXT,
	`ServerEXE`	TEXT,
	`SmartBackup`	INTEGER NOT NULL DEFAULT 1,
	`SmartGameTypeInstall`	INTEGER NOT NULL DEFAULT 1,
	`SmartUninstall`	INTEGER NOT NULL DEFAULT 1,
	`TextureFolder`	TEXT,
	`UserFile`	TEXT
, "MapsExt" TEXT, "ScreenShotExt" TEXT, "MusicExt" TEXT, "MusicFolder" TEXT, "TexturesExt" TEXT);
CREATE TABLE `GameTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
CREATE TABLE `InstallTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
CREATE TABLE "MenuGroups" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	INTEGER
);
CREATE TABLE "Menus" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`gametype`	INTEGER,
	`name`	TEXT,
	`ext`	TEXT,
	`menutype`	INTEGER
);
CREATE TABLE SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL);
CREATE TABLE `Settings` (
	`LastSeletedGame`	INTEGER
);
CREATE TABLE SettingsDocument (Id INTEGER PRIMARY KEY CHECK (Id=1), XmlData TEXT NOT NULL, Version INTEGER NOT NULL DEFAULT 1);
CREATE TABLE sqlite_sequence(name,seq);

-- cache.sqlite3
CREATE TABLE Files (
ID INTEGER PRIMARY KEY AUTOINCREMENT, Num INTEGER NOT NULL, BelongsTo INTEGER DEFAULT 0,
FileName BLOB, FileSize INTEGER DEFAULT 0, FileDate TEXT, FileLocation TEXT,
Installed INTEGER NOT NULL DEFAULT 0, CRC32 TEXT);
CREATE TABLE SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL);
CREATE TABLE sqlite_sequence(name,seq);
CREATE INDEX IX_Files_Location ON Files(FileLocation, FileName);

-- logs.sqlite3
CREATE TABLE LogEntries (
Id INTEGER PRIMARY KEY AUTOINCREMENT, GameType INTEGER, FileName TEXT NOT NULL,
FileLocation TEXT, FileSize INTEGER DEFAULT 0, FileDate TEXT, CRC32 TEXT,
Operation TEXT, CreatedAt TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP);
CREATE TABLE SchemaVersion (Key TEXT PRIMARY KEY, Version INTEGER NOT NULL);
CREATE TABLE sqlite_sequence(name,seq);
CREATE INDEX IX_LogEntries_Game ON LogEntries(GameType, CreatedAt);
