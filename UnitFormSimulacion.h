//---------------------------------------------------------------------------

#ifndef UnitFormSimulacionH
#define UnitFormSimulacionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSimulacion : public TForm
{
__published:	// IDE-managed Components
	TTrackBar *TrackBarDeposito1;
	TButton *Button_Exit;
	TLabel *LabelDeposito1;
	TLabel *Label2;
	TButton *ButtonDep1;
	TLabel *LabelVal1;
	TTrackBar *TrackBarDeposito2;
	TTrackBar *TrackBarDeposito3;
	TTrackBar *TrackBarDeposito4;
	TTrackBar *TrackBarDeposito5;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *LabelDeposito2;
	TLabel *LabelDeposito3;
	TLabel *LabelDeposito4;
	TLabel *LabelDeposito5;
	TTrackBar *TrackBarBascula;
	TLabel *Label1;
	TLabel *LabelBascula;
	TLabel *LabelVal2;
	TButton *ButtonDep2;
	TLabel *LabelVal3;
	TButton *ButtonDep3;
	TLabel *LabelVal4;
	TButton *ButtonDep4;
	TLabel *LabelVal5;
	TButton *ButtonDep5;
	TLabel *LabelValBasc;
	TButton *ButtonDep6;
	TLabel *Label3;
	TTrackBar *TrackBarMezcladora;
	TLabel *LabelMez;
	TButton *ButtonMez;
	TLabel *LabelValMez;
	void __fastcall Button_ExitClick(TObject *Sender);
	void __fastcall TrackBarDeposito1Change(TObject *Sender);
	void __fastcall ButtonDep1Click(TObject *Sender);
	void __fastcall TrackBarDeposito2Change(TObject *Sender);
	void __fastcall TrackBarDeposito3Change(TObject *Sender);
	void __fastcall TrackBarDeposito4Change(TObject *Sender);
	void __fastcall TrackBarDeposito5Change(TObject *Sender);
	void __fastcall TrackBarBasculaChange(TObject *Sender);
	void __fastcall ButtonDep2Click(TObject *Sender);
	void __fastcall ButtonDep3Click(TObject *Sender);
	void __fastcall ButtonDep4Click(TObject *Sender);
	void __fastcall ButtonDep5Click(TObject *Sender);
	void __fastcall ButtonDep6Click(TObject *Sender);
	void __fastcall TrackBarMezcladoraChange(TObject *Sender);
	void __fastcall ButtonMezClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSimulacion(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSimulacion *FormSimulacion;
//---------------------------------------------------------------------------
#endif
