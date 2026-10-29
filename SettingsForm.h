//---------------------------------------------------------------------------

#ifndef SettingsFormH
#define SettingsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "TMMFiles.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TStatusBar *StatusBar1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet4;
    TGroupBox *GroupBox1;
    TComboBox *ComboBox1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TButton *Button1;
    TButton *Button6;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TLabel *Label3;
    TEdit *Edit2;
    TComboBox *ComboBox2;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *Edit3;
    TLabel *Label6;
    TEdit *Edit4;
    TLabel *Label7;
    TEdit *Edit5;
    TGroupBox *GroupBox2;
    TLabel *Label8;
    TEdit *Edit6;
    TCheckBox *CheckBox4;
    TGroupBox *GroupBox3;
    TLabel *Label9;
    TEdit *Edit7;
    TCheckBox *CheckBox5;
    TLabel *Label10;
    TComboBox *ComboBox3;
    TLabel *Label11;
    TComboBox *ComboBox4;
    TCheckBox *CheckBox9;
    TGroupBox *GroupBox4;
    TLabel *Label12;
    TEdit *Edit8;
    TComboBox *ComboBox5;
    TLabel *Label13;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Save1;
    TMenuItem *Load1;
    TMenuItem *ToFile1;
    TMenuItem *FromFile1;
    TMenuItem *N1;
    TMenuItem *Close1;
    TButton *Button2;
    TButton *Button3;
    TLabel *Label14;
    TComboBox *ComboBox6;
    TLabel *Label15;
    TComboBox *ComboBox7;
    TButton *Button4;
    TButton *Button5;
    TButton *Button7;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TButton *Button8;
    TTabSheet *TabSheet5;
    TGroupBox *GroupBox5;
    TLabel *Label16;
    TEdit *Edit9;
    TButton *Button9;
    TTabSheet *TabSheet6;
    TGroupBox *GroupBox6;
    TLabel *Label17;
    TEdit *Edit10;
    TButton *Button10;
    TTabSheet *TabSheet7;
    TGroupBox *GroupBox7;
    TLabel *Label18;
    TEdit *Edit11;
    TButton *Button11;
    TTabSheet *TabSheet8;
    TGroupBox *GroupBox8;
    TLabel *Label19;
    TEdit *Edit12;
    TButton *Button12;
    TCheckBox *CheckBox6;
    TLabel *Label20;
    TEdit *Edit13;
    TTabSheet *TabSheet9;
    TGroupBox *GroupBox9;
    TLabel *Label21;
    TEdit *Edit14;
    TButton *Button13;
    TTabSheet *TabSheet10;
    TGroupBox *GroupBox10;
    TLabel *Label22;
    TEdit *Edit15;
    TLabel *Label23;
    TEdit *Edit16;
    TLabel *Label24;
    TEdit *Edit17;
    TButton *Button14;
    TLabel *Label25;
    TEdit *Edit18;
    TEdit *Edit19;
    TLabel *Label26;
    TEdit *Edit20;
    TLabel *Label27;
    TEdit *Edit21;
    TLabel *Label28;
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall ToRegistry1Click(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall FromRegistry1Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall ComboBox2Change(TObject *Sender);
    void __fastcall CheckBox4Click(TObject *Sender);
    void __fastcall ComboBox3Change(TObject *Sender);
    void __fastcall ComboBox6Change(TObject *Sender);
    void __fastcall ComboBox7Change(TObject *Sender);
    void __fastcall ComboBox4Change(TObject *Sender);
    void __fastcall CheckBox5Click(TObject *Sender);
    void __fastcall CheckBox9Click(TObject *Sender);
    void __fastcall ComboBox5Change(TObject *Sender);
    void __fastcall FromFile1Click(TObject *Sender);
    void __fastcall ToFile1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CheckBox3Click(TObject *Sender);
    void __fastcall CheckBox6Click(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall Button10Click(TObject *Sender);
    void __fastcall Button11Click(TObject *Sender);
    void __fastcall Button12Click(TObject *Sender);
    void __fastcall Button13Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm4(TComponent* Owner);
    void __fastcall GetSettings();
    void __fastcall SetSettings();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
