BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS `Menus` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`gametype`	INTEGER,
	`name`	TEXT,
	`ext`	TEXT,
	`menutype`	INTEGER
);
INSERT INTO `Menus` VALUES (1,3,'Zip Archives','.zip',2);
INSERT INTO `Menus` VALUES (2,3,'RAR Archives','.rar',2);
INSERT INTO `Menus` VALUES (3,3,'Unreal 2004 Umods','.ut2mod',2);
INSERT INTO `Menus` VALUES (4,3,'SFX Archives','.exe',2);
INSERT INTO `Menus` VALUES (5,3,'UT2004 Maps','.ut2',2);
INSERT INTO `Menus` VALUES (6,3,'Unreal UCC Archives','.uz2',2);
INSERT INTO `Menus` VALUES (7,3,'Benchmark','.bat',3);
INSERT INTO `Menus` VALUES (8,3,'System','.det',3);
INSERT INTO `Menus` VALUES (9,3,'System','.dll',3);
INSERT INTO `Menus` VALUES (10,3,'System','.est',3);
INSERT INTO `Menus` VALUES (11,3,'System','.exe',3);
INSERT INTO `Menus` VALUES (12,3,'System','.frt',3);
INSERT INTO `Menus` VALUES (13,3,'ForceFeedback','.ifr',3);
INSERT INTO `Menus` VALUES (14,3,'System','.ini',3);
INSERT INTO `Menus` VALUES (15,3,'System','.int',3);
INSERT INTO `Menus` VALUES (16,3,'System','.itt',3);
INSERT INTO `Menus` VALUES (17,3,'System','.log',3);
INSERT INTO `Menus` VALUES (18,3,'System','.md5',3);
INSERT INTO `Menus` VALUES (19,3,'Music','.ogg',3);
INSERT INTO `Menus` VALUES (20,3,'System','.sch',3);
INSERT INTO `Menus` VALUES (21,3,'System','.u',3);
INSERT INTO `Menus` VALUES (22,3,'Sounds','.uax',3);
INSERT INTO `Menus` VALUES (23,3,'System','.ude',3);
INSERT INTO `Menus` VALUES (24,3,'Animations','.ukx',3);
INSERT INTO `Menus` VALUES (25,3,'System','.upl',3);
INSERT INTO `Menus` VALUES (26,3,'StaticMeshes','.usx',3);
INSERT INTO `Menus` VALUES (27,3,'Maps','.ut2',3);
INSERT INTO `Menus` VALUES (28,3,'Textures','.utx',3);
INSERT INTO `Menus` VALUES (29,3,'Cache','.uxx',3);
INSERT INTO `Menus` VALUES (30,3,'Help','default',3);
INSERT INTO `Menus` VALUES (31,3,'Archives','0',4);
INSERT INTO `Menus` VALUES (32,3,'Cache','1',4);
INSERT INTO `Menus` VALUES (33,3,'Smart Backup','2',4);
INSERT INTO `Menus` VALUES (34,3,'Bomming Run','BR',5);
INSERT INTO `Menus` VALUES (35,3,'Capture The Flag','CTF',5);
INSERT INTO `Menus` VALUES (36,3,'Death Ball','DB',5);
INSERT INTO `Menus` VALUES (37,3,'Death Match','DM',5);
INSERT INTO `Menus` VALUES (38,3,'Double Domination','DOM',5);
INSERT INTO `Menus` VALUES (39,3,'Happy Fun Ball','HFB',5);
INSERT INTO `Menus` VALUES (40,3,'CTF-Com B Pack 2','CTF-CBP2',5);
INSERT INTO `Menus` VALUES (41,3,'CTF-Flag Pack 2','CTF-FP2',5);
INSERT INTO `Menus` VALUES (42,3,'CTF-D$K','CTF-{D$K}',5);
INSERT INTO `Menus` VALUES (43,3,'CTF-2004','CTF-(2K4)',5);
INSERT INTO `Menus` VALUES (44,3,'Death Match 1on1','DM-1ON1',5);
INSERT INTO `Menus` VALUES (45,3,'Death Match CBP2','DM-CBP2',5);
INSERT INTO `Menus` VALUES (46,3,'Death Match DE','DM-DE-',5);
CREATE TABLE IF NOT EXISTS `MenuGroups` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	INTEGER
);
INSERT INTO `MenuGroups` VALUES (1,'Maps');
INSERT INTO `MenuGroups` VALUES (2,'Archives');
INSERT INTO `MenuGroups` VALUES (3,'Cache');
INSERT INTO `MenuGroups` VALUES (4,'Logs');
INSERT INTO `MenuGroups` VALUES (5,'Music');
INSERT INTO `MenuGroups` VALUES (6,'Textures');
INSERT INTO `MenuGroups` VALUES (7,'Demos');
INSERT INTO `MenuGroups` VALUES (8,'ScreenShots');
CREATE TABLE IF NOT EXISTS `InstallTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO `InstallTypes` VALUES (1,'.zip');
INSERT INTO `InstallTypes` VALUES (2,'.rar');
INSERT INTO `InstallTypes` VALUES (3,'.ut2umod');
INSERT INTO `InstallTypes` VALUES (4,'.exe');
INSERT INTO `InstallTypes` VALUES (5,'.ut2');
INSERT INTO `InstallTypes` VALUES (6,'.uz2');
CREATE TABLE IF NOT EXISTS `GameTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO `GameTypes` VALUES (1,'NotSpecified');
INSERT INTO `GameTypes` VALUES (2,'Unreal');
INSERT INTO `GameTypes` VALUES (3,'UT2004');
INSERT INTO `GameTypes` VALUES (4,'TheWheelOfTime');
INSERT INTO `GameTypes` VALUES (5,'KlingonHonorGuard');
INSERT INTO `GameTypes` VALUES (6,'Rune');
INSERT INTO `GameTypes` VALUES (7,'Undying');
INSERT INTO `GameTypes` VALUES (8,'DeusEx');
INSERT INTO `GameTypes` VALUES (9,'XComEnforcer');
INSERT INTO `GameTypes` VALUES (10,'DeepSpaceNine');
INSERT INTO `GameTypes` VALUES (11,'NerfArenaBlast');
INSERT INTO `GameTypes` VALUES (12,'UT2003');
INSERT INTO `GameTypes` VALUES (13,'ArmyOperations');
INSERT INTO `GameTypes` VALUES (14,'HarryPotterSorcerersStone');
INSERT INTO `GameTypes` VALUES (15,'HarryPotterChamberSecrets');
INSERT INTO `GameTypes` VALUES (16,'Unreal2');
INSERT INTO `GameTypes` VALUES (17,'SplinterCell');
CREATE TABLE IF NOT EXISTS `GameSettings` (
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
CREATE TABLE IF NOT EXISTS `GameIcons` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT,
	`gametype`	INTEGER
);
INSERT INTO `GameIcons` VALUES (1,'.exe',3);
INSERT INTO `GameIcons` VALUES (2,'.html',3);
INSERT INTO `GameIcons` VALUES (3,'.ut2',3);
INSERT INTO `GameIcons` VALUES (4,'.uax',3);
INSERT INTO `GameIcons` VALUES (5,'.ogg',3);
CREATE TABLE IF NOT EXISTS `FileTypesGroups` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`name`	TEXT
);
INSERT INTO `FileTypesGroups` VALUES (1,'Maps');
INSERT INTO `FileTypesGroups` VALUES (2,'Archives');
INSERT INTO `FileTypesGroups` VALUES (3,'Cache');
INSERT INTO `FileTypesGroups` VALUES (4,'Logs');
INSERT INTO `FileTypesGroups` VALUES (5,'Music');
INSERT INTO `FileTypesGroups` VALUES (6,'Textures');
INSERT INTO `FileTypesGroups` VALUES (7,'Demos');
INSERT INTO `FileTypesGroups` VALUES (8,'ScreenShots');
CREATE TABLE IF NOT EXISTS `FileTypes` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
	`filegrouptype`	INTEGER NOT NULL DEFAULT 0,
	`ext`	TEXT,
	`gametype`	INTEGER
);
INSERT INTO `FileTypes` VALUES (1,1,'.ut2',3);
INSERT INTO `FileTypes` VALUES (2,2,'.zip',3);
INSERT INTO `FileTypes` VALUES (3,2,'.rar',3);
INSERT INTO `FileTypes` VALUES (4,2,'.exe',3);
INSERT INTO `FileTypes` VALUES (5,3,'.uxx',3);
INSERT INTO `FileTypes` VALUES (6,4,'.sqlite3',3);
INSERT INTO `FileTypes` VALUES (7,5,'.ogg',3);
INSERT INTO `FileTypes` VALUES (8,5,'.mp3',3);
INSERT INTO `FileTypes` VALUES (9,6,'.utx',3);
INSERT INTO `FileTypes` VALUES (10,7,'.dem',3);
INSERT INTO `FileTypes` VALUES (11,8,'.jpg',3);
INSERT INTO `FileTypes` VALUES (12,8,'.bmp',3);
COMMIT;
