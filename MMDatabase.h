#ifndef MMDatabaseH
#define MMDatabaseH

#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>

// The three SQLite files live in the user's writable application data, never
// under Program Files or the debugger's working directory.
namespace MMDatabase
{
    inline UnicodeString DataFolder()
    {
        UnicodeString local = GetEnvironmentVariable(L"LOCALAPPDATA");
        if (local.IsEmpty())
            local = IncludeTrailingPathDelimiter(ExtractFilePath(ParamStr(0))) + L"Data";
        const UnicodeString folder = IncludeTrailingPathDelimiter(local) + L"MapManager";
        if (!ForceDirectories(folder) && !DirectoryExists(folder))
            throw Exception(L"Unable to create Map Manager data directory: " + folder);
        return IncludeTrailingPathDelimiter(folder);
    }

    inline UnicodeString DatabasePath(const UnicodeString &name)
    {
        return DataFolder() + name;
    }

    inline UnicodeString EnsureDatabase(const UnicodeString &name)
    {
        const UnicodeString target = DatabasePath(name);
        if (!FileExists(target))
        {
            const UnicodeString source =
                IncludeTrailingPathDelimiter(ExtractFilePath(ParamStr(0))) +
                L"Database\\templates\\" + name;
            if (!FileExists(source))
                throw Exception(L"Missing Map Manager SQLite database template: " + source);
            if (!::CopyFileW(source.c_str(), target.c_str(), TRUE) &&
                !FileExists(target))
                throw Exception(L"Unable to initialize Map Manager database: " + target +
                    L" (Windows error " + IntToStr(static_cast<int>(::GetLastError())) + L")");
        }
        return target;
    }

    inline void EnsureAllDatabases()
    {
        EnsureDatabase(L"settings.sqlite3");
        EnsureDatabase(L"cache.sqlite3");
        EnsureDatabase(L"logs.sqlite3");
    }
}

#endif
