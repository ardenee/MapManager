//---------------------------------------------------------------------------
#ifndef TMMFileListH
#define TMMFileListH
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include <vcl.h>
/*
class TMMFileList : public TList
{
	typedef TList inherited;
private:
	PFileInfo __fastcall GetFile(int Index);
protected:
	virtual void __fastcall Notify(void* Ptr, TListNotification Action);
public:
	__fastcall TMMFileList();
	__fastcall ~TMMFileList();
	PFileInfo __fastcall AddFile();
	bool __fastcall AddFile(TMM_FileInfo aFile);
	bool __fastcall AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum=0, int aBelongsTo=0, unsigned long aCRC32=0);
	int  __fastcall AddFiles(PFileList aNewList);
	int  __fastcall Copy(PFileList aOldList);
	bool __fastcall CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile);
	TMM_FileInfo __fastcall GetFileStruct(int Index);
	TMM_FileInfo __fastcall ToStruct(PFileInfo aFile);
	HIDESBASE int __fastcall Add(PFileInfo aFile);
	__property PFileInfo Files[int Index] = {read=GetFile};
};
*/
//--------------------------------------------------------------------------------------------------
//namespace container {
//--------------------------------------------------------------------------------------------------
//template <class Type>

class TMMFileList : public TPersistent
{
	typedef TList inherited;
private:
	PFileInfo __fastcall GetFile(int Index);
	int __fastcall GetCount();
protected:
	virtual void __fastcall Notify(void* Ptr, TListNotification Action);
public:
	TList* List;
	__fastcall TMMFileList();
	__fastcall ~TMMFileList();
	PFileInfo __fastcall AddFile();
	bool __fastcall AddFile(TMM_FileInfo aFile);
	bool __fastcall AddFile(AnsiString aFileName, __int64 aFileSize, AnsiString aFileDate, bool aInstalled, int aNum=0, int aBelongsTo=0, unsigned long aCRC32=0);
	int  __fastcall AddFiles(PFileList aNewList);
	int  __fastcall Copy(PFileList aOldList);
    void __fastcall Clear();
	bool __fastcall CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile);
	TMM_FileInfo __fastcall GetFileStruct(int Index);
	TMM_FileInfo __fastcall ToStruct(PFileInfo aFile);
	HIDESBASE int __fastcall Add(PFileInfo aFile);
	__property PFileInfo Files[int Index] = {read=GetFile};
	__property int Count = {read=GetCount};
};
/*-2-1-07

class TMMFileList : public TList
{
	typedef TList inherited;
private:
	PFileInfo __fastcall GetFile(int Index);
protected:
	virtual void __fastcall Notify(void* Ptr, TListNotification Action);
public:
	__fastcall TMMFileList();
	__fastcall ~TMMFileList();
	PFileInfo __fastcall AddFile();
	bool __fastcall AddFile(TMM_FileInfo aFile);
	bool __fastcall AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum=0, int aBelongsTo=0, unsigned long aCRC32=0);
	int  __fastcall AddFiles(PFileList aNewList);
	int  __fastcall Copy(PFileList aOldList);
	bool __fastcall CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile);
	TMM_FileInfo __fastcall GetFileStruct(int Index);
	TMM_FileInfo __fastcall ToStruct(PFileInfo aFile);
	HIDESBASE int __fastcall Add(PFileInfo aFile);
	__property PFileInfo Files[int Index] = {read=GetFile};
};
*/

/*
class TMMFileList
{
protected:
	virtual void __fastcall Notify(void* Ptr, TListNotification Action);
private:
   TList* elements;
   int    __fastcall FCapacity(void);
   void   __fastcall SetCapacity(int quantity);
   int    __fastcall FCount(void)const;
   void   __fastcall SetCount(int quantity);
   Type*  __fastcall Get(int index)const;
   void   __fastcall Put(int index, Type* item);
public:
   __fastcall TMMFileList();
   __fastcall ~TMMFileList();
   int   __fastcall Add(Type* item);
   void  __fastcall Clear(void);
   void  __fastcall Delete(int index);
   void  __fastcall Exchange(int index1, int index2);
   Type* __fastcall First(void);
   int   __fastcall IndexOf(Type* Item);
   void  __fastcall Insert(int Index, Type* Item);
   Type* __fastcall Last(void);
   void  __fastcall Pack(void);
   int   __fastcall Remove(Type* Item);
   void  __fastcall Erase(void); //delete also the memory of the component stored in the elemente
   Type* __fastcall operator [](int num)const;
   __property int   Capacity         = {read=FCapacity, write=SetCapacity};
   __property int   Count            = {read=FCount,    write=SetCount};
   __property Type* Items[int Index] = {read=Get,       write=Put};
};
*/
//--------------------------------------------------------------------------------------------------
////template <class Type>
/*
__fastcall TMMFileList::TMMFileList()
{
  elements = new TList();
};
//--------------------------------------------------------------------------------------------------
////template <class Type>
int __fastcall  TMMFileList::FCapacity(void)
{
   return elements->Capacity;
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall  TMMFileList::SetCapacity(int quantity)
{
   elements->Capacity = quantity;
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
int __fastcall TMMFileList::FCount(void)const
{
   return elements->Count;
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::SetCount(int quantity)
{
   elements->Count = quantity;
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Put(int index,Type* item)
{
   elements->Items[index] = item;
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
Type* __fastcall  TMMFileList::Get(int index)const
{
   return reinterpret_cast<Type*>(elements->Items[index]);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
Type* __fastcall TMMFileList::operator [](int val)const
{
   return reinterpret_cast<Type*>(elements->Items(val));
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
int __fastcall TMMFileList::Add(Type* item)
{
   return elements->Add(item);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Clear(void)
{
   elements->Clear();
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Erase(void)   //As clear but erase the element
{
   for(int i = 0 ; i < elements->Count ; i++)
   {
      Type* p;
      p = reinterpret_cast<Type*>(elements->Items[i]);
      delete p;
   }
   elements->Clear();
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Delete(int index)
{
   elements->Delete(index);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Exchange(int index1, int index2)
{
   elements->Exchange(index1,index2);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
Type* __fastcall TMMFileList::First(void)
{
   return reinterpret_cast<Type*>(elements->First());
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
int __fastcall TMMFileList::IndexOf(Type* Item)
{
   return elements->IndexOf(Item);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Insert(int Index, Type* Item)
{
   elements->Insert(Index,Item);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
Type* __fastcall TMMFileList::Last(void)
{
   return reinterpret_cast<Type*>(elements->Last());
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Pack(void)
{
   elements->Pack();
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
int __fastcall TMMFileList::Remove(Type*  Item)
{
   return elements->Remove(Item);
};
//--------------------------------------------------------------------------------------------------
//template <class Type>
__fastcall TMMFileList::~TMMFileList()
{

   for(int i = 0 ; i < elements->Count ; i++)
   {
      Type* p;
      p = reinterpret_cast<Type*>(elements->Items[i]);
      delete p;
   }
   delete elements;
};
//---------------------------------------------------------------------------
//template <class Type>
void __fastcall TMMFileList::Notify(void* Ptr, TListNotification Action)
{
    if(Action==lnDeleted)
        delete static_cast<Type*>(Ptr);
}
*/
//--------------------------------------------------------------------------------------------------
//}  // end of namespace
//--------------------------------------------------------------------------------------------------

#endif

