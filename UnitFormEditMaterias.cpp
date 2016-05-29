//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditMaterias.h"
#include "UnitFormConfigDepositos.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditMaterias *FormEditMaterias;

int item_index = 0;
//---------------------------------------------------------------------------
__fastcall TFormEditMaterias::TFormEditMaterias(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEditMaterias::FormShow(TObject *Sender)
{
	int i;

	LeerArchivoMaterias();
	ComboBoxMateria->Clear();

	for(i=0; i<10; i++){
		ComboBoxMateria->Items->Add(materia[i].Nombre());
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormEditMaterias::Button1Click(TObject *Sender)
{
	char nombre[10];

	wcstombs(nombre, LabeledEditMateria->Text.w_str(), 10);  //Convierte *w_char del Edit en *char
	materia[item_index].Nombre(nombre);

	materia[item_index].Id(LabeledEditId->Text.ToInt());

	GuardarArchivoMaterias();

	FormConfigDepositos->ComboBoxMateria->Clear();

	for(int i=0; i<10; i++){
		FormConfigDepositos->ComboBoxMateria->Items->Add(materia[i].Nombre());
	}

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormEditMaterias::ComboBoxMateriaChange(TObject *Sender)
{
	item_index = ComboBoxMateria->ItemIndex;

	LabeledEditId->Text = item_index;
	LabeledEditMateria->Text = AnsiString(materia[item_index].Nombre());
}
//---------------------------------------------------------------------------
void __fastcall TFormEditMaterias::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

