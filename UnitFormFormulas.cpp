//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormFormulas.h"
#include "UnitDatos.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFormulas *FormFormulas;

static int item_index = 0;
//---------------------------------------------------------------------------
__fastcall TFormFormulas::TFormFormulas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormFormulas::ComboBoxFormulaChange(TObject *Sender)
{
	item_index = ComboBoxFormula->ItemIndex;

	LabeledEditNombre->Text = AnsiString(formula[item_index].Nombre());
	EditDescripcion->Text = AnsiString(formula[item_index].Descripcion());

	ComboBoxMateria1->ItemIndex = formula[item_index].IdMateria(0);
	ComboBoxMateria2->ItemIndex = formula[item_index].IdMateria(1);
	ComboBoxMateria3->ItemIndex = formula[item_index].IdMateria(2);

	TrackBarProporcion1->Position = formula[item_index].Proporcion(0)*100;
	TrackBarProporcion2->Position = formula[item_index].Proporcion(1)*100;
	TrackBarProporcion3->Position = formula[item_index].Proporcion(2)*100;

}
//---------------------------------------------------------------------------


void __fastcall TFormFormulas::TrackBarProporcion1Change(TObject *Sender)
{
	LabelProporcion1->Caption = AnsiString(TrackBarProporcion1->Position) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::TrackBarProporcion2Change(TObject *Sender)
{
	LabelProporcion2->Caption = AnsiString(TrackBarProporcion2->Position) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::TrackBarProporcion3Change(TObject *Sender)
{
	LabelProporcion3->Caption = AnsiString(TrackBarProporcion3->Position) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::ButtonExitClick(TObject *Sender)
{
	FormFormulas->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::ButtonSaveClick(TObject *Sender)
{
	char nombre[10], descripcion[60];

	wcstombs(nombre, LabeledEditNombre->Text.w_str(), 10);  //Convierte *w_char del Edit en *char
	formula[item_index].Nombre(nombre);

	wcstombs(descripcion, EditDescripcion->Text.w_str(), 60);  //Convierte *w_char del Edit en *char
	formula[item_index].Descripcion(descripcion);

	formula[item_index].IdMateria(0, ComboBoxMateria1->ItemIndex);
	formula[item_index].IdMateria(1, ComboBoxMateria2->ItemIndex);
	formula[item_index].IdMateria(2, ComboBoxMateria3->ItemIndex);

	formula[item_index].Proporcion(0, (double)TrackBarProporcion1->Position/100);
	formula[item_index].Proporcion(1, (double)TrackBarProporcion2->Position/100);
	formula[item_index].Proporcion(2, (double)TrackBarProporcion3->Position/100);
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::Button1Click(TObject *Sender)
{
	GuardarArchivoFormulas();
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::ButtonRecuperarClick(TObject *Sender)
{
	LeerArchivoFormulas();
}
//---------------------------------------------------------------------------

void __fastcall TFormFormulas::FormShow(TObject *Sender)
{
	LeerArchivoFormulas();

	//COMBOBOX FORMULAS
	ComboBoxFormula->Clear();
	for(int i=0; i<5; i++)
	{
		ComboBoxFormula->Items->Add(formula[i].Nombre());
	}
	//COMBOBOX MATERIA1
	ComboBoxMateria1->Clear();
	for(int i=0; i<10; i++)
	{
		ComboBoxMateria1->Items->Add(materia[i].Nombre());
	}
	//COMBOBOX MATERIA12
	ComboBoxMateria2->Clear();
	for(int i=0; i<10; i++)
	{
		ComboBoxMateria2->Items->Add(materia[i].Nombre());
	}
	//COMBOBOX MATERIA3
	ComboBoxMateria3->Clear();
	for(int i=0; i<10; i++)
	{
		ComboBoxMateria3->Items->Add(materia[i].Nombre());
	}
}
//---------------------------------------------------------------------------

