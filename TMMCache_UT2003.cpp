//---------------------------------------------------------------------------
#pragma hdrstop
#include <IniFiles.hpp>
#include <Registry.hpp>
#include "TMMCache_UT2003.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TMMCache_UT2003::TMMCache_UT2003()
    : TMMCache()
{
    CacheFileName = "";
}
//----------------------------------------------------------------------------
void __fastcall TMMCache_UT2003::SetStringValue(const int Index, const AnsiString Value)
{
    switch(Index)
    {
        case 0 : FCacheFileName  = Value; break;
    }
}
//----------------------------------------------------------------------------
// Default Functions
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::GetCacheFileList(TStrings* CacheFolderFiles)
{
    GetCacheFolderFileList(CacheFolderFiles);
    // only validate with files in cache.ini file if using it

        TStrings* CacheFileFiles = new TStringList;
        GetCacheFileFileList(CacheFileFiles);
        
        for(int i=0;i<CacheFileFiles->Count;i++)
        {
            for(int x=0;x<CacheFolderFiles->Count;x++)
            {
				if(!TMMCache::GetStr1FromCacheString(CacheFolderFiles->Strings[x]).Compare(CacheFileFiles->Strings[i] + ".uxx"))
                {
                    CacheFolderFiles->Delete(x);
                    break;
                }
			}
        }

        delete CacheFileFiles;


    return CacheFolderFiles->Count;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::ConvertFiles(TStrings* FileList)
{
    for(int i=0;i<FileList->Count;i++)
    {    // format should be cache file_name:real_file_name:Folder_name
		if(TMMCache::SmartBackup)                            // folder                                            // real file name
			if(FileExists(TMMCache::GameRootFolder  + "\\" + TMMCache::GetStr3FromCacheString(FileList->Strings[i]) + "\\" + TMMCache::GetStr2FromCacheString(FileList->Strings[i])))                           // folder                                            // real file name
				RenameFile(TMMCache::GameRootFolder + "\\" + TMMCache::GetStr3FromCacheString(FileList->Strings[i]) + "\\" + TMMCache::GetStr2FromCacheString(FileList->Strings[i]), TMMCache::GameRootFolder + "\\" + TMMCache::GetStr3FromCacheString(FileList->Strings[i]) + "\\" + TMMCache::GetStr2FromCacheString(FileList->Strings[i]) + ".bak");

		if(TMMCache::CacheOverRide)                      // folder                                            // real file name
			DeleteFile(TMMCache::GameRootFolder     + "\\" + GetStr3FromCacheString(FileList->Strings[i]) + "\\" + GetStr2FromCacheString(FileList->Strings[i]));

		if(TMMCache::CacheRemove)                                   // cache file name                                                                       // folder                            // real file name
			RenameFile(ExtractFilePath(CacheFileName) + TMMCache::GetStr1FromCacheString(FileList->Strings[i]) ,TMMCache::GameRootFolder + "\\" + TMMCache::GetStr3FromCacheString(FileList->Strings[i]) + "\\" + TMMCache::GetStr2FromCacheString(FileList->Strings[i]));
        else
        {
			UnicodeString OldFile = ExtractFilePath(CacheFileName) + TMMCache::GetStr1FromCacheString(FileList->Strings[i]);
			UnicodeString NewFile = TMMCache::GameRootFolder + "\\" + TMMCache::GetStr3FromCacheString(FileList->Strings[i]) + "\\" + TMMCache::GetStr2FromCacheString(FileList->Strings[i]);                                     // cache file name                                                       // folder                                             // real file name
            CopyFile(OldFile.w_str(), NewFile.w_str(), true);
        }
    }

    return FileList->Count;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::RemoveInvalidCacheFiles(void) // requires cache.ini file
{
    int Total = 0;
    TStrings* FileList = new TStringList;
    GetCacheFolderFileList(FileList);

    if(FileExists(FCacheFileName))
    {
    	TStrings* CacheFileList = new TStringList;
        TIniFile* CacheFile = new TIniFile(CacheFileName);

        if(CacheFile->SectionExists("Cache"))
        {
    	    CacheFile->ReadSection("Cache", CacheFileList);

    	    for(int i=0;i<CacheFileList->Count;i++) // remove invalid cache file entrys
    	    {
	        if(!FileExists(ExtractFilePath(CacheFileName) + CacheFileList->Strings[i] + ".uxx"))
                {   // found a match, so delete it, only keeping the invalid files
                    CacheFile->DeleteKey("Cache", CacheFileList->Strings[i]);
                    i--;
                    Total++;
                    break;
    	        }
    	    }
    	    
    	    for(int i=0;i<FileList->Count;i++) // make sure folder files are in cache file
    	    {
                if(!CacheFile->ValueExists("Cache", FileList->Strings[i]))
                {
					DeleteFile(TMMCache::GameRootFolder + TMMCache::GetFilesFolder(ExtractFileExt(TMMCache::GetStr3FromCacheString(FileList->Strings[i]))) + "\\" + TMMCache::GetStr1FromCacheString(FileList->Strings[i]));
                    i--;
                }
    	    }
        }

        delete CacheFileList;
        delete CacheFile;
    }
   
   delete FileList;
   return Total;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::RemoveInstalledCacheFiles(void) // requires cache.ini file
{
    int Total = 0;
    TStrings* CacheFileList = new TStringList;

    if(FileExists(FCacheFileName))
    {
        TIniFile* CacheFile = new TIniFile(CacheFileName);

        if(CacheFile->SectionExists("Cache"))
        {
    	    CacheFile->ReadSection("Cache", CacheFileList);

    	    for(int i=0;i<CacheFileList->Count;i++)
    	    {
				if(!FileExists(TMMCache::GameRootFolder + "\\" + TMMCache::GetFilesFolder(ExtractFileExt(CacheFile->ReadString("Cache", CacheFileList->Strings[i], "Error Reading File"))) + "\\" + CacheFile->ReadString("Cache", CacheFileList->Strings[i], "Error Reading File")))
    	    	{
    	    	    if(DeleteFile(ExtractFilePath(CacheFileName) + CacheFileList->Strings[i] + ".uxx"))
    	    	        Total++;
    	    	}
    	    }
        }

        delete CacheFile;
    }

   return Total;
}
//----------------------------------------------------------------------------
// secondary functions, used by default functions
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::GetInstalledCacheFiles(TStrings* CacheFileList) // requires use of cache.ini file for now
{
    if(FileExists(FCacheFileName))
    {
        TIniFile* CacheFile = new TIniFile(CacheFileName);

        if(CacheFile->SectionExists("Cache"))
        {
    	    CacheFile->ReadSection("Cache", CacheFileList);

    	    for(int i=0;i<CacheFileList->Count;i++)
    	    {
				if(!FileExists(TMMCache::GameRootFolder + "\\" + TMMCache::GetFilesFolder(ExtractFileExt(CacheFile->ReadString("Cache", CacheFileList->Strings[i], "Error Reading File"))) + "\\" + CacheFile->ReadString("Cache", CacheFileList->Strings[i], "Error Reading File")))
    	    	{
    	    	    CacheFileList->Delete(i);
    	    	    i--;
    	        }
    	    }
        }

        delete CacheFile;
    }

    return CacheFileList->Count;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::GetInvaledCacheFiles(TStrings* FileList) // can only validate using the cache.ini file for now
{
    GetCacheFolderFileList(FileList);

    if(FileExists(FCacheFileName))
    {
    	TStrings* CacheFileList = new TStringList;
        TIniFile* CacheFile = new TIniFile(CacheFileName);

        if(CacheFile->SectionExists("Cache"))
        {
    	    CacheFile->ReadSection("Cache", FileList);

    	    for(int i=0;i<FileList->Count;i++)
    	    {
    	        for(int x=0;x<FileList->Count;x++)
    	        {
    	            if(!FileList->Strings[x].Compare(FileList->Strings[i] + ".uxx"))
                    {   // found a match, so delete it, only keeping the invalid files
                        FileList->Delete(x);
                        break;
                    }
    	        }
    	    }
        }

        delete CacheFileList;
        delete CacheFile;
    }

    return FileList->Count;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::ClearCache(void)
{
    int Total = 0;
    TStrings* FileList = new TStringList;
    GetCacheFolderFileList(FileList);
    
    for(int i=0;i<FileList->Count;i++)
    {
		if(DeleteFile(TMMCache::GameRootFolder + TMMCache::GetFilesFolder(ExtractFileExt(TMMCache::GetStr3FromCacheString(FileList->Strings[i]))) + TMMCache::GetStr2FromCacheString(FileList->Strings[i])))
            Total++;
    }

    delete FileList;
    return Total;
}
//----------------------------------------------------------------------------
int __fastcall TMMCache_UT2003::GetCacheFileFileList(TStrings* FileList)
{
    TIniFile* CacheFile = new TIniFile(FCacheFileName);
    
    if(CacheFile->SectionExists("Cache"))
    {
    	CacheFile->ReadSection("Cache", FileList);
    	
    	for(int i=0;i<FileList->Count;i++)
    	    FileList->Strings[i] = FileList->Strings[i] + ":" + CacheFile->ReadString("Cache", FileList->Strings[i], "Error Reading Cache File") + ":" + TMMCache::GetFilesFolder(ExtractFileExt(CacheFile->ReadString("Cache", FileList->Strings[i], "Error Reading Cache File")));
    }

    delete CacheFile;
    return FileList->Count;
}
//----------------------------------------------------------------------------

