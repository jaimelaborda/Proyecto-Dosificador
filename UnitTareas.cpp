//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitTareas.h"
#include "UnitDatos.h"
#include "UnitFormDosificador.h"

void Control (void)
{
   //woajajajajxd
}



void ActualizarGUI (void)
{
	/*ACTUALIZAR DEPÓSITOS*/
	FormDosificador->Deposito1->Cantidad = (float)deposito[0].Cantidad()/1000;
	FormDosificador->Deposito2->Cantidad = (float)deposito[1].Cantidad()/1000;
	FormDosificador->Deposito3->Cantidad = (float)deposito[2].Cantidad()/1000;
	FormDosificador->Deposito4->Cantidad = (float)deposito[3].Cantidad()/1000;
	FormDosificador->Deposito5->Cantidad = (float)deposito[4].Cantidad()/1000;
	//FormDosificador->Bascula->Cantidad = (float)bascula.Peso()/10000;
	FormDosificador->ShapeMezcladora->Height = - mezcladora.Cantidad()*124/10000;

	//ShowMessage(FormDosificador->Deposito1->Color);
	FormDosificador->Deposito1->Color = deposito[0].Color();
	FormDosificador->Deposito1->Paint();

}


//---------------------------------------------------------------------------
#pragma package(smart_init)
