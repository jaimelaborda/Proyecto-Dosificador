//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitDatos.h"

void CDeposito::Capacidad (int _capacidad)
{
	capacidad = _capacidad;
}

int CDeposito::Capacidad (void)
{
	return (capacidad);
}

bool CDeposito::Valvula (void)
{
	return estado_valvula;
}

void CDeposito::Valvula (bool _estado_valvula)
{
	estado_valvula = _estado_valvula;
}

bool CDeposito::ToggleValvula (void)
{
	estado_valvula = !estado_valvula;
	return estado_valvula;
}

CDeposito deposito[5];
//---------------------------------------------------------------------------
#pragma package(smart_init)
