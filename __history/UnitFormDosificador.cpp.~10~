//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormDosificador.h"
#include "UnitFormFormulas.h"
#include "UnitFormSimulacion.h"
#include "UnitFormConfigDepositos.h"
#include "UnitDatos.h"
#include "UnitTareas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TDeposito"
#pragma resource "*.dfm"
TFormDosificador *FormDosificador;
//---------------------------------------------------------------------------
__fastcall TFormDosificador::TFormDosificador(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDosificador::Button_SimulacionClick(TObject *Sender)
{
	FormSimulacion->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormDosificador::Timer1Timer(TObject *Sender)
{
	ActualizarGUI();
}
//---------------------------------------------------------------------------


void __fastcall TFormDosificador::ButtonFormulasClick(TObject *Sender)
{
	FormFormulas->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormDosificador::Simulacin1Click(TObject *Sender)
{
 	FormSimulacion->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormDosificador::Formulas1Click(TObject *Sender)
{
	FormFormulas->Show();
}
//---------------------------------------------------------------------------






void __fastcall TFormDosificador::ButtonConfigurarDepositosClick(TObject *Sender)

{
	FormConfigDepositos->ShowModal();
}
//---------------------------------------------------------------------------




void __fastcall TFormDosificador::FormPaint(TObject *Sender)
{
	 TPoint PtDeposito[] = {Point(0, 0), Point(PaintBoxDep1->Width*0.5, PaintBoxDep1->Height), Point(PaintBoxDep1->Width, 0), Point(0,0)};

	/*PaintBoxDep1->Canvas->Brush->Color=clRed;
	PaintBoxDep1->Canvas->Polygon(PtDeposito, 3); */

	/*PaintBoxDep1->Canvas->MoveTo(0, 0);
	PaintBoxDep1->Canvas->LineTo(PaintBoxDep1->Width*0.5, PaintBoxDep1->Height);
	PaintBoxDep1->Canvas->LineTo(PaintBoxDep1->Width, 0);
	PaintBoxDep1->Canvas->LineTo(0, 0);
	PaintBoxDep1->Canvas->Brush->Color = clRed;
	PaintBoxDep1->Canvas->FloodFill(50,50,clRed,fsBorder); */

	if (deposito[0].EstadoValvula())
	{
		//ShowMessage("GREEN");
		FormDosificador->PaintBoxDep1->Canvas->Brush->Color=clGreen;
		FormDosificador->PaintBoxDep1->Canvas->Polygon(PtDeposito, 3);
	}else{
		//ShowMessage("RED");
		FormDosificador->PaintBoxDep1->Canvas->Brush->Color=clRed;
		FormDosificador->PaintBoxDep1->Canvas->Polygon(PtDeposito, 3);
	}

	if (deposito[1].EstadoValvula())
	{
		//ShowMessage("GREEN");
		FormDosificador->PaintBoxDep2->Canvas->Brush->Color=clGreen;
		FormDosificador->PaintBoxDep2->Canvas->Polygon(PtDeposito, 3);
	}else{
		//ShowMessage("RED");
		FormDosificador->PaintBoxDep2->Canvas->Brush->Color=clRed;
		FormDosificador->PaintBoxDep2->Canvas->Polygon(PtDeposito, 3);
	}

	if (deposito[2].EstadoValvula())
	{
		//ShowMessage("GREEN");
		FormDosificador->PaintBoxDep3->Canvas->Brush->Color=clGreen;
		FormDosificador->PaintBoxDep3->Canvas->Polygon(PtDeposito, 3);
	}else{
		//ShowMessage("RED");
		FormDosificador->PaintBoxDep3->Canvas->Brush->Color=clRed;
		FormDosificador->PaintBoxDep3->Canvas->Polygon(PtDeposito, 3);
	}

	if (deposito[3].EstadoValvula())
	{
		//ShowMessage("GREEN");
		FormDosificador->PaintBoxDep4->Canvas->Brush->Color=clGreen;
		FormDosificador->PaintBoxDep4->Canvas->Polygon(PtDeposito, 3);
	}else{
		//ShowMessage("RED");
		FormDosificador->PaintBoxDep4->Canvas->Brush->Color=clRed;
		FormDosificador->PaintBoxDep4->Canvas->Polygon(PtDeposito, 3);
	}

	if (deposito[4].EstadoValvula())
	{
		//ShowMessage("GREEN");
		FormDosificador->PaintBoxDep5->Canvas->Brush->Color=clGreen;
		FormDosificador->PaintBoxDep5->Canvas->Polygon(PtDeposito, 3);
	}else{
		//ShowMessage("RED");
		FormDosificador->PaintBoxDep5->Canvas->Brush->Color=clRed;
		FormDosificador->PaintBoxDep5->Canvas->Polygon(PtDeposito, 3);
	}

	TPoint PtBascula[] =  {Point(0, 0), Point(0, 0.5*PaintBoxBasc->Height), Point(0.48*PaintBoxBasc->Width, PaintBoxBasc->Height), Point(0.52*PaintBoxBasc->Width, PaintBoxBasc->Height), Point(PaintBoxBasc->Width, 0.5*PaintBoxBasc->Height), Point(PaintBoxBasc->Width, 0), Point(0, 0)};

	PaintBoxBasc->Canvas->Brush->Color=clRed;
	PaintBoxBasc->Canvas->Polygon(PtBascula, 6);

	Shape4->Brush->Color = deposito[0].Color();
}
//---------------------------------------------------------------------------

