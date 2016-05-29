//---------------------------------------------------------------------------

#ifndef UnitFormNuevoPedidoH
#define UnitFormNuevoPedidoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormNuevoPedido : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *ComboBoxFormula;
	TLabel *Label3;
	TEdit *EditCantidad;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label4;
	TComboBox *ComboBoxPrioridad;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBoxFormulaChange(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNuevoPedido(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNuevoPedido *FormNuevoPedido;
//---------------------------------------------------------------------------
#endif
