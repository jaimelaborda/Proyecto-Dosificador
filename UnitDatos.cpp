//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitDatos.h"
#include <stdio.h>
#include <string.h>


//VALVULA-----------------------------------------------------------------------

void CValvula::Abrir (void) {estado_valvula = true;}
void CValvula::Cerrar (void) {estado_valvula = false;}
bool CValvula::ToggleValvula (void) {estado_valvula = !estado_valvula; return estado_valvula;}
bool CValvula::EstadoValvula (void) {return estado_valvula;}

//DEPOSITO----------------------------------------------------------------------

void CDeposito::Cantidad (int _cantidad)
{
	cantidad = _cantidad;
}

int CDeposito::Cantidad (void)
{
	return (cantidad);
}

void CDeposito::Color (TColor _color)
{
	color = _color;
}

TColor CDeposito::Color (void)
{
	return color;
}

//FORMULAS--------------------------------------------------------------------

void CFormula::IdFormula(int _id_formula)
{
	id_formula = _id_formula;
}
int CFormula::IdFormula(void)
{
	return id_formula;
}
void CFormula::IdMateria(int pos, int _id_materia)
{
	id_materia[pos] = _id_materia;
}
int CFormula::IdMateria(int pos)
{
	return id_materia[pos];
}
void CFormula::Proporcion(int pos, double _proporcion)
{
	proporcion[pos] = _proporcion;;
}
double CFormula::Proporcion(int pos)
{
	return proporcion[pos];
}
void CFormula::Nombre(char *_nombre)
{
	strcpy(nombre, _nombre);
}
char* CFormula::Nombre(void)
{
	return nombre;
}
void CFormula::Descripcion(char *_descripcion)
{
	strcpy(descripcion, _descripcion);
}
char* CFormula::Descripcion(void)
{
	return descripcion;
}
void GuardarArchivoFormulas(void)
{
	FILE* F;

	F = fopen("file_formulas.bin", "wb");

	if (!F) ShowMessage("Error abriendo el archivo");

	fwrite(formula, sizeof(CFormula), 5, F);

	fclose(F);
}
void LeerArchivoFormulas(void)
{
	FILE* F;

	F = fopen("file_formulas.bin", "rb");

	if (!F) ShowMessage("Error abriendo el archivo");

	fread(formula, sizeof(CFormula), 5, F);

	fclose(F);
}


//BASCULA-----------------------------------------------------------------------
void CBascula::Peso (double _peso ){peso = _peso;}
double CBascula::Peso (void) {return peso;}

//MEZCLADORA-----------------------------------------------------------------------
void CMezcladora::MotorOn(void) {motor_state = true;}
void CMezcladora::MotorOff(void){motor_state = false;}
bool CMezcladora::MotorState(void) {return motor_state;}
void CMezcladora::Cantidad(double _cantidad) {cantidad = _cantidad;}
double CMezcladora::Cantidad(void) {return cantidad;}

//MATERIA-----------------------------------------------------------------------
void CMateria::Nombre(char *_nombre){strcpy(nombre, _nombre);}
char* CMateria::Nombre(void){return nombre;}

void CMateria::Id(int _id){id = _id;}
int CMateria::Id(void){return id;}

void CMateria::IdDeposito(int _id_deposito){id_deposito = _id_deposito;}
int CMateria::IdDeposito(void){return id_deposito;}

int IdMateria(int id_deposito)
{
	 for (int i = 0; i < 10; i++) {
		 if (materia[i].IdDeposito() == id_deposito)
			return i;
	 }
	 return 0;
}

void GuardarArchivoMaterias(void)
{
	FILE* F;

	F = fopen("file_materias.bin", "wb");

	if (!F) ShowMessage("Error abriendo el archivo");

	fwrite(materia, sizeof(CMateria), 10, F);

	fclose(F);
}
void LeerArchivoMaterias(void)
{
	FILE* F;

	F = fopen("file_materias.bin", "rb");

	if (!F) ShowMessage("Error abriendo el archivo");

	fread(materia, sizeof(CMateria), 10, F);

	fclose(F);
}

//PEDIDOS
void NuevoPedido(int _id_formula, double _cantidad, int _prioridad)
{
	FILE* F;
	int id_pedido, id_pedido_ultimo=0, id_formula, prioridad;
	double cantidad;

	F = fopen("file_pedidosPendientes.txt", "r");   //Abro para leer
	if (!F) ShowMessage("Error abriendo el archivo");

	while (!feof(F))
	{
		fscanf(F, "%d %d %f %d", &id_pedido, &id_formula, &cantidad, &prioridad);
		//ShowMessage(id_pedido);

		if(id_pedido > id_pedido_ultimo) id_pedido_ultimo = id_pedido;
	}
	fclose(F);

	F = fopen("file_pedidosPendientes.txt", "a");   //Abro con cursor al final para escribir
	if (!F) ShowMessage("Error abriendo el archivo");

	fprintf(F, "%d %d %.2f %d\n", id_pedido_ultimo+1, _id_formula, _cantidad, _prioridad);

	fclose(F);
}

void GenerarReporte(int id, int formula, float cantidad)
{
	FILE *F;

	F = fopen("file_pedidosFinalizados.txt", "a");   //Abro con cursor al final para escribir
	if (!F) ShowMessage("Error abriendo el archivo");

	fprintf(F, "%d %d %.2f\n", id, formula, cantidad);

	fclose(F);
}

//DECLARACIÓN VARIABLES ---------------------------------------------------------------
CDeposito deposito[5];
CMateria materia[10];
CFormula formula[5];
CBascula bascula;
CMezcladora mezcladora;
//---------------------------------------------------------------------------
#pragma package(smart_init)
