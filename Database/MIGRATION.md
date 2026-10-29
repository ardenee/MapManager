# Map Manager SQLite migration - 29 October 2026

## Recovered evidence

The historical Map Manager/mm-setup/Win32/Debug/settings.sqlite3 was a genuine SQLite DB with Settings, GameSettings, GameTypes, Menus, MenuGroups, InstallTypes, FileExts, FileFilters, FileIcons, FileTypes, FileTypesGroups and CacheFiles. The historical cache.sqlite3 Files table provided the cache schema. The old settings.sqlite3.sql was a partial SQL text export and had been accidentally renamed settings.sqlite3 in DEV: it has been restored under the correct SQL filename.

The Settings.xml source contains 17 game profiles and 17 game types. Each profile has 35 scalar fields and 7 nested sections: MenuTypes, InstallTypes, Icons, DisplayMenus, Servers, Tables, TablesAlignment. The template builder imports all profiles and 119 complex nested sections, and preserves their complete XML-compatible structure in the SettingsDocument table. The historical GameSettings schema was extended with the five scalar fields it omitted.

## Runtime behavior

- On first startup MMDatabase.h creates %LOCALAPPDATA%/MapManager, and copies versioned templates for settings.sqlite3, cache.sqlite3 and logs.sqlite3 if missing. Existing databases are NEVER overwritten.
- The initial Settings XML document is imported if present. If no XML ships with the app, the settings SQLite template already includes the complete defaults. On subsequent launches the settings document is loaded from SQLite, NOT from a settings XML file.
- GUI accessors continue using the old in-memory XML binding classes, so menus, icons, games and tables retain their original behavior while storage is SQLite.
- SaveSettings writes the complete settings document, selected game ID, current game's relational scalar settings and seven nested groups in a transaction, using prepared dbExpress parameters. On form close, TMapManager deletes TMMSettings, whose destructor calls SaveSettings. UI setting-change events also call SaveSettings.
- The initial cache Files schema is created with zero rows, rather than packaging obsolete 2016 user cache data. The existing cache reader/writer uses cache.sqlite3.
- A logs.sqlite3 template is created, but old logs XML operations are NOT yet converted. The LogEntries schema is reserved for that separate migration.

## Database and template paths

User data: %LOCALAPPDATA%/MapManager/settings.sqlite3, cache.sqlite3, logs.sqlite3

Version-controlled templates: Database/templates/*.sqlite3

IDE output templates: Win64x/Release/Database/templates/*.sqlite3

Templates are regenerated from Database/build_templates.py and Database/legacy_settings.sql, using Settings/Settings.xml as the source input. No original legacy checkout is required to regenerate them.

## Verified

- Historical source DB integrity: OK; original schema/rows inspected
- 17 XML profiles and all 119 per-game nested sections present in generated settings SQLite
- All three initial templates: PRAGMA integrity_check OK
- dbExpress SQL prepared parameter save with a 194927-character XML document: passed (ExecSQL(false), not ExecSQL(true))
- Full Win64 Modern/Release clean rebuild: passed
- Runtime first launch with isolated LOCALAPPDATA: three SQLite DBs created and SettingsDocument saved; 17 profiles and 119 nested sections preserved
- Runtime second launch from an isolated executable folder without XML or templates: process remained running and existing SQLite data remained intact
- Actual GUI form close, archive operations, complete logs conversion, and in-place migration of a pre-existing older-schema SQLite DB are NOT yet certified

Do not remove the XML binding code until the GUI itself has been converted to query the normalized database schema. Persisting the XML-compatible document IN SQLite is a storage migration, not a complete elimination of legacy XML in-memory objects.
