//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormNuevoPedido.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNuevoPedido *FormNuevoPedido;

int id_formula = 0;
//---------------------------------------------------------------------------
__fastcall TFormNuevoPedido::TFormNuevoPedido(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormNuevoPedido::FormShow(TObject *Sender)
{
	LeerArchivoFormulas();
	ComboBoxFormula->Clear();
	for(int i=0; i<5; i++)
	{
		ComboBoxFormula->Items->Add(formula[i].Nombre());
	}

	EditCantidad->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFormNuevoPedido::Button1Click(TObject *Sender)
{
	NuevoPedido(id_formula, EditCantidad->Text.ToDouble(), ComboBoxPrioridad->ItemIndex);
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNuevoPedido::ComboBoxFormulaChange(TObject *Sender)
{
	id_formula = ComboBoxFormula->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TFormNuevoPedido::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

