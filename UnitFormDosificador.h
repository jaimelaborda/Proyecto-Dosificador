//---------------------------------------------------------------------------

#ifndef UnitFormDosificadorH
#define UnitFormDosificadorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TDeposito.h"
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDosificador : public TForm
{
__published:	// IDE-managed Components
	TButton *Button_Simulacion;
	TTimer *TimerGUI;
	TDeposito *Deposito1;
	TDeposito *Deposito2;
	TDeposito *Deposito3;
	TDeposito *Deposito4;
	TDeposito *Deposito5;
	TLabel *Label1;
	TMainMenu *MainMenuDosificador;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TGroupBox *GroupBoxControlPanel;
	TButton *ButtonFormulas;
	TMenuItem *Archivo1;
	TMenuItem *Vistas1;
	TMenuItem *Simulacin1;
	TMenuItem *Formulas1;
	TButton *ButtonConfigurarDepositos;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TPaintBox *PaintBoxDep1;
	TPaintBox *PaintBoxDep2;
	TPaintBox *PaintBoxDep3;
	TPaintBox *PaintBoxDep4;
	TPaintBox *PaintBoxDep5;
	TPaintBox *PaintBoxBasc;
	TShape *ShapeValvulaBasc;
	TImage *Image1;
	TShape *Shape6;
	TShape *ShapeMezcladora;
	TImage *Image2;
	TShape *ShapeValvMezcladora;
	TGroupBox *GroupBox1;
	TButton *ButtonRealizarPedido;
	TProgressBar *ProgressBarBascula;
	TShape *ShapeStateMezcladora;
	TButton *ButtonInitProcess;
	TTimer *TimerProceso;
	TShape *ShapeProceso;
	TLabel *LabelPeso;
	TMenuItem *Salir1;
	TMenuItem *Ayuda1;
	TMenuItem *Sobre1;
	TImage *Image3;
	void __fastcall Button_SimulacionClick(TObject *Sender);
	void __fastcall TimerGUITimer(TObject *Sender);
	void __fastcall ButtonFormulasClick(TObject *Sender);
	void __fastcall Simulacin1Click(TObject *Sender);
	void __fastcall Formulas1Click(TObject *Sender);
	void __fastcall ButtonConfigurarDepositosClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall ButtonRealizarPedidoClick(TObject *Sender);
	void __fastcall ButtonInitProcessClick(TObject *Sender);
	void __fastcall TimerProcesoTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Salir1Click(TObject *Sender);
	void __fastcall Sobre1Click(TObject *Sender);




private:	// User declarations
public:		// User declarations
	__fastcall TFormDosificador(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDosificador *FormDosificador;
//---------------------------------------------------------------------------
#endif
