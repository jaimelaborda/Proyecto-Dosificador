//---------------------------------------------------------------------------

#ifndef UnitDatosH
#define UnitDatosH

class CDeposito
{
	double capacidad;
	bool estado_valvula;

public:
	void Capacidad (int _capacidad);
	int Capacidad (void);

	bool Valvula (void);
	void Valvula (bool _estado_valvula);
	bool ToggleValvula (void);
};

extern CDeposito deposito[5];
//---------------------------------------------------------------------------
#endif
