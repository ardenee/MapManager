//---------------------------------------------------------------------------

#ifndef SearchFormH
#define SearchFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TListView *ListView1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TPopupMenu *PopupMenu1;
    TMenuItem *SaveToFile1;
    TMenuItem *RemoveSelected1;
    TMenuItem *DeleteSelected1;
    TMenuItem *UninstallSelected1;
    TMenuItem *DisplayInfo1;
    TMenuItem *N1;
    TSaveDialog *SaveDialog1;
    void __fastcall SaveToFile1Click(TObject *Sender);
    void __fastcall DisplayInfo1Click(TObject *Sender);
    void __fastcall RemoveSelected1Click(TObject *Sender);
    void __fastcall ListView1Data(TObject *Sender, TListItem *Item);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
    __fastcall ~TForm2();
    TMMFileList* Files;
    void __fastcall AddFiles(TMMFileList* files);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
