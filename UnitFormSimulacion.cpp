//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormSimulacion.h"
#include "UnitDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSimulacion *FormSimulacion;
//---------------------------------------------------------------------------
__fastcall TFormSimulacion::TFormSimulacion(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSimulacion::Button_ExitClick(TObject *Sender)
{
	FormSimulacion->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarDeposito1Change(TObject *Sender)
{
	deposito[0].Cantidad(TrackBarDeposito1->Position);
	LabelDeposito1->Caption=AnsiString(deposito[0].Cantidad()/10) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep1Click(TObject *Sender)
{
	if (deposito[0].ToggleValvula()) {
		FormSimulacion->LabelVal1->Caption="ABIERTA";
	}else{
    	FormSimulacion->LabelVal1->Caption="CERRADA";
    }
}
//---------------------------------------------------------------------------



void __fastcall TFormSimulacion::TrackBarDeposito2Change(TObject *Sender)
{
	deposito[1].Cantidad(TrackBarDeposito2->Position);
	LabelDeposito2->Caption=AnsiString(deposito[1].Cantidad()/10) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarDeposito3Change(TObject *Sender)
{
	deposito[2].Cantidad(TrackBarDeposito3->Position);
	LabelDeposito3->Caption=AnsiString(deposito[2].Cantidad()/10) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarDeposito4Change(TObject *Sender)
{
	deposito[3].Cantidad(TrackBarDeposito4->Position);
	LabelDeposito4->Caption=AnsiString(deposito[3].Cantidad()/10) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarDeposito5Change(TObject *Sender)
{
	deposito[4].Cantidad(TrackBarDeposito5->Position);
	LabelDeposito5->Caption=AnsiString(deposito[4].Cantidad()/10) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarBasculaChange(TObject *Sender)
{
	bascula.Peso(TrackBarBascula->Position);
	LabelBascula->Caption=AnsiString(bascula.Peso()/50) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep2Click(TObject *Sender)
{
	if (deposito[1].ToggleValvula()) {
		FormSimulacion->LabelVal2->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelVal2->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep3Click(TObject *Sender)
{
	if (deposito[2].ToggleValvula()) {
		FormSimulacion->LabelVal3->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelVal3->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep4Click(TObject *Sender)
{
	if (deposito[3].ToggleValvula()) {
		FormSimulacion->LabelVal4->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelVal4->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep5Click(TObject *Sender)
{
	if (deposito[4].ToggleValvula()) {
		FormSimulacion->LabelVal5->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelVal5->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonDep6Click(TObject *Sender)
{
	if (bascula.ToggleValvula()) {
		FormSimulacion->LabelValBasc->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelValBasc->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::TrackBarMezcladoraChange(TObject *Sender)
{
	mezcladora.Cantidad(TrackBarMezcladora->Position);
	LabelMez->Caption=AnsiString(mezcladora.Cantidad()/100) + " %";
}
//---------------------------------------------------------------------------

void __fastcall TFormSimulacion::ButtonMezClick(TObject *Sender)
{
	if (mezcladora.ToggleValvula()) {
		FormSimulacion->LabelValMez->Caption="ABIERTA";
	}else{
		FormSimulacion->LabelValMez->Caption="CERRADA";
	}
}
//---------------------------------------------------------------------------

