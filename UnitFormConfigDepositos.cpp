//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormConfigDepositos.h"
#include "UnitFormEditMaterias.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConfigDepositos *FormConfigDepositos;

int id_deposito = 0;
//---------------------------------------------------------------------------
__fastcall TFormConfigDepositos::TFormConfigDepositos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::ComboBoxDepChange(TObject *Sender)
{
	id_deposito = ComboBoxDep->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::ButtonGuardarClick(TObject *Sender)
{
    //ShowMessage(id_deposito);
	deposito[id_deposito].Color(ColorBox->Selected);
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::ButtonExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::ButtonNuevaMateriaClick(TObject *Sender)
{
	FormEditMaterias->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::FormPaint(TObject *Sender)
{
	ComboBoxMateria->Clear();

	for(int i=0; i<10; i++){
		ComboBoxMateria->Items->Add(materia[i].Nombre());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::FormShow(TObject *Sender)
{
	LeerArchivoMaterias();
}
//---------------------------------------------------------------------------

