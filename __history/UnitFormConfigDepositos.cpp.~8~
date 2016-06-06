//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormConfigDepositos.h"
#include "UnitFormEditMaterias.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDeposito"
#pragma resource "*.dfm"
TFormConfigDepositos *FormConfigDepositos;

int id_deposito = 0, id_materia = 0;
//---------------------------------------------------------------------------
__fastcall TFormConfigDepositos::TFormConfigDepositos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::ComboBoxDepChange(TObject *Sender)
{
	id_deposito = ComboBoxDep->ItemIndex;

	ComboBoxMateria->ItemIndex = IdMateria(id_deposito);
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::ButtonGuardarClick(TObject *Sender)
{
	//ShowMessage(id_deposito);
	deposito[id_deposito].Color(ColorBox->Selected);

	materia[id_materia].IdDeposito(id_deposito);
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::ButtonExitClick(TObject *Sender)
{
	GuardarArchivoMaterias();
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::ButtonNuevaMateriaClick(TObject *Sender)
{
	FormEditMaterias->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::FormShow(TObject *Sender)
{
	LeerArchivoMaterias();

	FormConfigDepositos->ComboBoxMateria->Clear();

	for(int i=0; i<10; i++){
		FormConfigDepositos->ComboBoxMateria->Items->Add(materia[i].Nombre());
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormConfigDepositos::ColorBoxChange(TObject *Sender)
{
	Deposito1->Color = ColorBox->Selected;
}
//---------------------------------------------------------------------------


void __fastcall TFormConfigDepositos::ComboBoxMateriaChange(TObject *Sender)
{
	id_materia = ComboBoxMateria->ItemIndex;
}
//---------------------------------------------------------------------------

