//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitTareas.h"
#include "UnitDatos.h"
#include "UnitFormDosificador.h"




void ActualizarGUI (void)
{
	/*ACTUALIZAR DEPÓSITOS*/
	FormDosificador->Deposito1->Cantidad = (float)deposito[0].Cantidad()/1000;
	FormDosificador->Deposito2->Cantidad = (float)deposito[1].Cantidad()/1000;
	FormDosificador->Deposito3->Cantidad = (float)deposito[2].Cantidad()/1000;
	FormDosificador->Deposito4->Cantidad = (float)deposito[3].Cantidad()/1000;
	FormDosificador->Deposito5->Cantidad = (float)deposito[4].Cantidad()/1000;
	FormDosificador->ProgressBarBascula->Position = (int)bascula.Peso();
	FormDosificador->ShapeMezcladora->Height = - mezcladora.Cantidad()*124/10000;

	if(deposito[0].EstadoValvula()) FormDosificador->Shape1->Brush->Color = deposito[0].Color();
		else FormDosificador->Shape1->Brush->Color = clMedGray;
	if(deposito[1].EstadoValvula()) FormDosificador->Shape2->Brush->Color = deposito[1].Color();
		else FormDosificador->Shape2->Brush->Color = clMedGray;
	if(deposito[2].EstadoValvula()) FormDosificador->Shape3->Brush->Color = deposito[2].Color();
		else FormDosificador->Shape3->Brush->Color = clMedGray;
	if(deposito[3].EstadoValvula()) FormDosificador->Shape4->Brush->Color = deposito[3].Color();
		else FormDosificador->Shape4->Brush->Color = clMedGray;
	if(deposito[4].EstadoValvula()) FormDosificador->Shape5->Brush->Color = deposito[4].Color();
		else FormDosificador->Shape5->Brush->Color = clMedGray;
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
