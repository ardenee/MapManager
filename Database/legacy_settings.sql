-- Original Map Manager 2005 settings.sqlite3 database: schema and reference values.
BEGIN TRANSACTION;
CREATE TABLE "CacheFiles" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	INTEGER,
	`folder`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER DEFAULT 2
);
INSERT INTO "CacheFiles" VALUES(1,'System','.sch','System',2,NULL);
INSERT INTO "CacheFiles" VALUES(2,'System','.u','System',2,NULL);
INSERT INTO "CacheFiles" VALUES(3,'Sounds','.uax','Sounds',2,NULL);
INSERT INTO "CacheFiles" VALUES(4,'System','.ude','System',2,NULL);
INSERT INTO "CacheFiles" VALUES(5,'Animations','.ukx','Animations',2,NULL);
INSERT INTO "CacheFiles" VALUES(6,'System','.upl','System',2,NULL);
INSERT INTO "CacheFiles" VALUES(7,'StaticMeshes','.usx','StaticMeshes',2,NULL);
INSERT INTO "CacheFiles" VALUES(8,'Textures','.utx','Textures',2,NULL);
INSERT INTO "CacheFiles" VALUES(9,'Cache','.uxx','Cache',2,NULL);
INSERT INTO "CacheFiles" VALUES(10,'Benchmark','.bat','Help',2,NULL);
INSERT INTO "CacheFiles" VALUES(11,'Map','.ut2','Maps',2,2);
INSERT INTO "CacheFiles" VALUES(12,'Archive','.exe','System',2,2);
INSERT INTO "CacheFiles" VALUES(13,'Archive','.zip','Help',2,2);
INSERT INTO "CacheFiles" VALUES(14,'Archive','.rar','Help',2,2);
INSERT INTO "CacheFiles" VALUES(15,'Archive','.uz2','Help',2,2);
INSERT INTO "CacheFiles" VALUES(16,'Cache','.bat','System',2,2);
INSERT INTO "CacheFiles" VALUES(17,'Cache','.det','System',2,2);
INSERT INTO "CacheFiles" VALUES(18,'Cache','.dll','System',2,2);
INSERT INTO "CacheFiles" VALUES(19,'Cache','.est','System',2,2);
INSERT INTO "CacheFiles" VALUES(21,'System','.frt','System',2,2);
INSERT INTO "CacheFiles" VALUES(22,'ForceFeedback','ifr','System',2,2);
INSERT INTO "CacheFiles" VALUES(23,'System','ini','System',2,2);
INSERT INTO "CacheFiles" VALUES(24,'System','.int','System',2,2);
INSERT INTO "CacheFiles" VALUES(25,'System','.itt','System',2,2);
INSERT INTO "CacheFiles" VALUES(26,'System','.log','Help',2,2);
INSERT INTO "CacheFiles" VALUES(27,'System','.md5','Help',2,2);
INSERT INTO "CacheFiles" VALUES(28,'Music','.ogg','Music',2,2);
INSERT INTO "CacheFiles" VALUES(29,'System','.sch','System',2,2);
INSERT INTO "CacheFiles" VALUES(33,'Animations','.ukx','System',2,2);
INSERT INTO "CacheFiles" VALUES(39,'Demo','.dem','Demos',2,2);
INSERT INTO "CacheFiles" VALUES(40,'BMP','.bmp','ScreenShots',2,2);
INSERT INTO "CacheFiles" VALUES(41,'JPG','.jpg','ScreenShots',2,2);
INSERT INTO "CacheFiles" VALUES(43,'Music','.mp3','Music',2,2);
CREATE TABLE "FileExts" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER
);
INSERT INTO "FileExts" VALUES(1,'Map','.ut2',2,0);
INSERT INTO "FileExts" VALUES(2,'Archive','.exe',2,1);
INSERT INTO "FileExts" VALUES(3,'Archive','.zip',2,1);
INSERT INTO "FileExts" VALUES(4,'Archive','.rar',2,1);
INSERT INTO "FileExts" VALUES(5,'Archive','.uz2',2,1);
INSERT INTO "FileExts" VALUES(6,'Cache','.bat',2,2);
INSERT INTO "FileExts" VALUES(7,'Cache','.det',2,2);
INSERT INTO "FileExts" VALUES(8,'Cache','.dll',2,2);
INSERT INTO "FileExts" VALUES(9,'Cache','.est',2,2);
INSERT INTO "FileExts" VALUES(10,'Cache','.exe',2,2);
INSERT INTO "FileExts" VALUES(11,'System','.frt',2,2);
INSERT INTO "FileExts" VALUES(12,'ForceFeedback','ifr',2,2);
INSERT INTO "FileExts" VALUES(13,'System','ini',2,2);
INSERT INTO "FileExts" VALUES(14,'System','.int',2,2);
INSERT INTO "FileExts" VALUES(15,'System','.itt',2,2);
INSERT INTO "FileExts" VALUES(16,'System','.log',2,2);
INSERT INTO "FileExts" VALUES(17,'System','.md5',2,2);
INSERT INTO "FileExts" VALUES(18,'Music','.ogg',2,6);
INSERT INTO "FileExts" VALUES(19,'System','.sch',2,3);
INSERT INTO "FileExts" VALUES(20,'System','.u',2,3);
INSERT INTO "FileExts" VALUES(21,'Sounds','.uax',2,3);
INSERT INTO "FileExts" VALUES(22,'System','.ude',2,3);
INSERT INTO "FileExts" VALUES(23,'Animations','.ukx',2,3);
INSERT INTO "FileExts" VALUES(24,'System','.upl',2,3);
INSERT INTO "FileExts" VALUES(25,'StaticMeshes','.usx',2,3);
INSERT INTO "FileExts" VALUES(26,'Textures','.utx',2,3);
INSERT INTO "FileExts" VALUES(27,'Cache','.uxx',2,3);
INSERT INTO "FileExts" VALUES(28,'Benchmark','.bat',2,3);
INSERT INTO "FileExts" VALUES(29,'Demo','.dem',2,8);
INSERT INTO "FileExts" VALUES(30,'BMP','.bmp',2,9);
INSERT INTO "FileExts" VALUES(31,'JPG','.jpg',2,9);
INSERT INTO "FileExts" VALUES(32,'Textures','.utx',2,7);
INSERT INTO "FileExts" VALUES(33,'Music','.mp3',2,6);
INSERT INTO "FileExts" VALUES(34,'Music','.ogg',2,6);
CREATE TABLE "FileFilters" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`value`	TEXT,
	`game`	INTEGER,
	`type`	INTEGER
);
INSERT INTO "FileFilters" VALUES(1,'SFX Archives','.exe',2,1);
INSERT INTO "FileFilters" VALUES(2,'RAR Archives','.rar',2,1);
INSERT INTO "FileFilters" VALUES(3,'UT2004 Maps','.ut2',2,1);
INSERT INTO "FileFilters" VALUES(4,'Unreal Umods','.ut2mod',2,1);
INSERT INTO "FileFilters" VALUES(5,'Unreal UCC Archives','.uz2',2,1);
INSERT INTO "FileFilters" VALUES(6,'Zip Archives','.zip',2,1);
INSERT INTO "FileFilters" VALUES(7,'ForceFeedback','ifr',2,2);
INSERT INTO "FileFilters" VALUES(8,'System','ini',2,2);
INSERT INTO "FileFilters" VALUES(9,'System','.int',2,2);
INSERT INTO "FileFilters" VALUES(10,'System','.itt',2,2);
INSERT INTO "FileFilters" VALUES(11,'System','.log',2,2);
INSERT INTO "FileFilters" VALUES(12,'System','.md5',2,2);
INSERT INTO "FileFilters" VALUES(13,'Benchmark','.bat',2,2);
INSERT INTO "FileFilters" VALUES(14,'System','.sch',2,2);
INSERT INTO "FileFilters" VALUES(15,'System','.u',2,2);
INSERT INTO "FileFilters" VALUES(16,'Sounds','.uax',2,2);
INSERT INTO "FileFilters" VALUES(17,'System','.ude',2,2);
INSERT INTO "FileFilters" VALUES(18,'Animations','.ukx',2,2);
INSERT INTO "FileFilters" VALUES(19,'System','.upl',2,2);
INSERT INTO "FileFilters" VALUES(20,'StaticMeshes','.usx',2,2);
INSERT INTO "FileFilters" VALUES(21,'Textures','.utx',2,2);
INSERT INTO "FileFilters" VALUES(22,'Cache','.uxx',2,2);
INSERT INTO "FileFilters" VALUES(25,'Bomming Run','BR',2,0);
INSERT INTO "FileFilters" VALUES(26,'Capture The Flag','CTF',2,0);
INSERT INTO "FileFilters" VALUES(27,'Death Ball','DB',2,0);
INSERT INTO "FileFilters" VALUES(28,'Death Match','DM',2,0);
INSERT INTO "FileFilters" VALUES(29,'Double Domination','DOM',2,0);
INSERT INTO "FileFilters" VALUES(30,'Happy Fun Ball','HFB',2,0);
INSERT INTO "FileFilters" VALUES(31,'CTF-Com B Pack 2','CTF-CBP2',2,0);
INSERT INTO "FileFilters" VALUES(32,'CTF-Flag Pack 2','CTF-FP2',2,0);
INSERT INTO "FileFilters" VALUES(33,'CTF-D$K','CTF-{D$K}',2,0);
INSERT INTO "FileFilters" VALUES(34,'CTF-2004','CTF-(2K4)',2,0);
INSERT INTO "FileFilters" VALUES(35,'Death Match 1on1','DM-1ON1',2,0);
INSERT INTO "FileFilters" VALUES(36,'Death Match CBP2','DM-CBP2',2,0);
INSERT INTO "FileFilters" VALUES(37,'Archives','0',2,3);
INSERT INTO "FileFilters" VALUES(38,'Cache','1',2,3);
INSERT INTO "FileFilters" VALUES(39,'Smart Backup','2',2,3);
INSERT INTO "FileFilters" VALUES(40,'OGG','.ogg',2,6);
INSERT INTO "FileFilters" VALUES(41,'MP3','.mp3',2,6);
INSERT INTO "FileFilters" VALUES(42,'WAV','.wav',2,6);
INSERT INTO "FileFilters" VALUES(43,'JPG','.jpg',2,9);
INSERT INTO "FileFilters" VALUES(44,'BMP','.bmp',2,9);
CREATE TABLE "FileIcons" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`gametype`	INTEGER,
	`iconid`	INTEGER DEFAULT 0
);
INSERT INTO "FileIcons" VALUES(0,'.exe',3,1);
INSERT INTO "FileIcons" VALUES(1,'.html',2,2);
INSERT INTO "FileIcons" VALUES(2,'.ut2',2,3);
INSERT INTO "FileIcons" VALUES(3,'.uax',2,4);
INSERT INTO "FileIcons" VALUES(4,'.ogg',2,5);
CREATE TABLE "FileTypes" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`filegrouptype`	INTEGER NOT NULL DEFAULT 0,
	`ext`	TEXT,
	`gametype`	INTEGER
);
INSERT INTO "FileTypes" VALUES(0,0,'.ut2',2);
INSERT INTO "FileTypes" VALUES(1,1,'.zip',2);
INSERT INTO "FileTypes" VALUES(2,1,'.rar',2);
INSERT INTO "FileTypes" VALUES(3,1,'.exe',2);
INSERT INTO "FileTypes" VALUES(4,2,'.uxx',2);
INSERT INTO "FileTypes" VALUES(5,3,'.sqlite3',2);
INSERT INTO "FileTypes" VALUES(6,4,'.ogg',2);
INSERT INTO "FileTypes" VALUES(7,4,'.mp3',2);
INSERT INTO "FileTypes" VALUES(8,5,'.utx',2);
INSERT INTO "FileTypes" VALUES(9,6,'.dem',2);
INSERT INTO "FileTypes" VALUES(10,7,'.jpg',2);
INSERT INTO "FileTypes" VALUES(11,7,'.bmp',2);
INSERT INTO "FileTypes" VALUES(22,1,'.ut2',2);
INSERT INTO "FileTypes" VALUES(23,1,'.ut2mod',2);
INSERT INTO "FileTypes" VALUES(24,1,'.uz2',2);
CREATE TABLE "FileTypesGroups" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO "FileTypesGroups" VALUES(0,'Maps');
INSERT INTO "FileTypesGroups" VALUES(1,'Archives');
INSERT INTO "FileTypesGroups" VALUES(2,'Cache');
INSERT INTO "FileTypesGroups" VALUES(3,'Logs');
INSERT INTO "FileTypesGroups" VALUES(4,'Music');
INSERT INTO "FileTypesGroups" VALUES(5,'Textures');
INSERT INTO "FileTypesGroups" VALUES(6,'Demos');
INSERT INTO "FileTypesGroups" VALUES(7,'ScreenShots');
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
);
CREATE TABLE `GameTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO "GameTypes" VALUES(0,'NotSpecified');
INSERT INTO "GameTypes" VALUES(1,'Unreal');
INSERT INTO "GameTypes" VALUES(2,'UT2004');
INSERT INTO "GameTypes" VALUES(3,'TheWheelOfTime');
INSERT INTO "GameTypes" VALUES(4,'KlingonHonorGuard');
INSERT INTO "GameTypes" VALUES(5,'Rune');
INSERT INTO "GameTypes" VALUES(6,'Undying');
INSERT INTO "GameTypes" VALUES(7,'DeusEx');
INSERT INTO "GameTypes" VALUES(8,'XComEnforcer');
INSERT INTO "GameTypes" VALUES(9,'DeepSpaceNine');
INSERT INTO "GameTypes" VALUES(10,'NerfArenaBlast');
INSERT INTO "GameTypes" VALUES(11,'UT2003');
INSERT INTO "GameTypes" VALUES(12,'ArmyOperations');
INSERT INTO "GameTypes" VALUES(13,'HarryPotterSorcerersStone');
INSERT INTO "GameTypes" VALUES(14,'HarryPotterChamberSecrets');
INSERT INTO "GameTypes" VALUES(15,'Unreal2');
INSERT INTO "GameTypes" VALUES(16,'SplinterCell');
CREATE TABLE `InstallTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO "InstallTypes" VALUES(0,'.zip');
INSERT INTO "InstallTypes" VALUES(1,'.rar');
INSERT INTO "InstallTypes" VALUES(2,'.ut2umod');
INSERT INTO "InstallTypes" VALUES(3,'.exe');
INSERT INTO "InstallTypes" VALUES(4,'.ut2');
INSERT INTO "InstallTypes" VALUES(5,'.uz2');
CREATE TABLE "MenuGroups" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	INTEGER
);
INSERT INTO "MenuGroups" VALUES(0,'Maps');
INSERT INTO "MenuGroups" VALUES(1,'Archives');
INSERT INTO "MenuGroups" VALUES(2,'Cache');
INSERT INTO "MenuGroups" VALUES(3,'Logs');
INSERT INTO "MenuGroups" VALUES(4,'Music');
INSERT INTO "MenuGroups" VALUES(5,'Textures');
INSERT INTO "MenuGroups" VALUES(6,'Demos');
INSERT INTO "MenuGroups" VALUES(7,'ScreenShots');
CREATE TABLE "Menus" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`gametype`	INTEGER,
	`name`	TEXT,
	`ext`	TEXT,
	`menutype`	INTEGER
);
INSERT INTO "Menus" VALUES(0,3,'Zip Archives','.zip',2);
INSERT INTO "Menus" VALUES(1,2,'RAR Archives','.rar',1);
INSERT INTO "Menus" VALUES(2,2,'Unreal 2004 Umods','.ut2mod',1);
INSERT INTO "Menus" VALUES(3,2,'SFX Archives','.exe',1);
INSERT INTO "Menus" VALUES(4,2,'UT2004 Maps','.ut2',1);
INSERT INTO "Menus" VALUES(5,2,'Unreal UCC Archives','.uz2',1);
INSERT INTO "Menus" VALUES(6,2,'Benchmark','.bat',1);
INSERT INTO "Menus" VALUES(7,2,'System','.det',2);
INSERT INTO "Menus" VALUES(8,2,'System','.dll',2);
INSERT INTO "Menus" VALUES(9,2,'System','.est',2);
INSERT INTO "Menus" VALUES(10,2,'System','.exe',2);
INSERT INTO "Menus" VALUES(11,2,'System','.frt',2);
INSERT INTO "Menus" VALUES(12,2,'ForceFeedback','.ifr',2);
INSERT INTO "Menus" VALUES(13,2,'System','.ini',2);
INSERT INTO "Menus" VALUES(14,2,'System','.int',2);
INSERT INTO "Menus" VALUES(15,2,'System','.itt',2);
INSERT INTO "Menus" VALUES(16,2,'System','.log',2);
INSERT INTO "Menus" VALUES(17,2,'System','.md5',2);
INSERT INTO "Menus" VALUES(18,2,'Music','.ogg',2);
INSERT INTO "Menus" VALUES(19,2,'System','.sch',2);
INSERT INTO "Menus" VALUES(20,2,'System','.u',2);
INSERT INTO "Menus" VALUES(21,2,'Sounds','.uax',2);
INSERT INTO "Menus" VALUES(22,2,'System','.ude',2);
INSERT INTO "Menus" VALUES(23,2,'Animations','.ukx',2);
INSERT INTO "Menus" VALUES(24,2,'System','.upl',2);
INSERT INTO "Menus" VALUES(25,2,'StaticMeshes','.usx',2);
INSERT INTO "Menus" VALUES(26,2,'Maps','.ut2',2);
INSERT INTO "Menus" VALUES(27,2,'Textures','.utx',2);
INSERT INTO "Menus" VALUES(28,2,'Cache','.uxx',2);
INSERT INTO "Menus" VALUES(29,2,'Help','default',2);
INSERT INTO "Menus" VALUES(30,2,'Archives','0',2);
INSERT INTO "Menus" VALUES(31,2,'Cache','1',3);
INSERT INTO "Menus" VALUES(32,2,'Smart Backup','2',3);
INSERT INTO "Menus" VALUES(33,2,'Bomming Run','BR',0);
INSERT INTO "Menus" VALUES(34,2,'Capture The Flag','CTF',0);
INSERT INTO "Menus" VALUES(35,2,'Death Ball','DB',0);
INSERT INTO "Menus" VALUES(36,2,'Death Match','DM',0);
INSERT INTO "Menus" VALUES(37,2,'Double Domination','DOM',0);
INSERT INTO "Menus" VALUES(38,2,'Happy Fun Ball','HFB',0);
INSERT INTO "Menus" VALUES(39,2,'CTF-Com B Pack 2','CTF-CBP2',0);
INSERT INTO "Menus" VALUES(40,2,'CTF-Flag Pack 2','CTF-FP2',0);
INSERT INTO "Menus" VALUES(41,2,'CTF-D$K','CTF-{D$K}',0);
INSERT INTO "Menus" VALUES(42,2,'CTF-2004','CTF-(2K4)',0);
INSERT INTO "Menus" VALUES(43,2,'Death Match 1on1','DM-1ON1',0);
INSERT INTO "Menus" VALUES(44,2,'Death Match CBP2','DM-CBP2',0);
INSERT INTO "Menus" VALUES(45,2,'Death Match DE','DM-DE-',0);
INSERT INTO "Menus" VALUES(46,2,'UT2004 Maps','.ut2',0);
CREATE TABLE `Settings` (
	`LastSeletedGame`	INTEGER
);
INSERT INTO "Settings" VALUES(2);
DELETE FROM "sqlite_sequence";
INSERT INTO "sqlite_sequence" VALUES('GameTypes',17);
INSERT INTO "sqlite_sequence" VALUES('FileTypesGroups',8);
INSERT INTO "sqlite_sequence" VALUES('FileTypes',24);
INSERT INTO "sqlite_sequence" VALUES('InstallTypes',8);
INSERT INTO "sqlite_sequence" VALUES('MenuGroups',8);
INSERT INTO "sqlite_sequence" VALUES('Menus',47);
INSERT INTO "sqlite_sequence" VALUES('FileExts',34);
INSERT INTO "sqlite_sequence" VALUES('FileFilters',44);
INSERT INTO "sqlite_sequence" VALUES('FileIcons',4);
INSERT INTO "sqlite_sequence" VALUES('CacheFiles',43);
COMMIT;
