//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitProcesos.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool proceso_iniciado, parar_proceso;
enum Estado{inicializacion, configuracion, disponibilidad, dosificar, mezclado, finaliza, parada};
Estado estado;

int dosi_formula;
double dosi_cantidad;

void IniciarProceso (void)
{
	proceso_iniciado = true;
	estado = inicializacion;
}

void PararProceso (void)
{
	parar_proceso = true;
}

bool InfoProceso (void){return proceso_iniciado;}

//COMPROBACIÓN DE PEDIDO EN ARCHIVO
void ArchivoComprobacion(void)
{
	int id_pedido_pendiente, id_pedido_finalizado, id_formula_pendiente, id_formula_finalizado, prioridad;
	double cantidad_pendiente, cantidad_finalizado;

	FILE* F_pendientes, *F_finalizados;

	F_pendientes = fopen("file_pedidosPendientes.txt", "r");   //Abro para leer
	if (!F_pendientes) ShowMessage("Error abriendo el archivo file_pedidosPendientes.txt");

	F_finalizados = fopen("file_pedidosFinalizados.txt", "r");   //Abro para leer
	if (!F_finalizados) ShowMessage("Error abriendo el archivo file_pedidosFinalizados.txt");

	while (!feof(F_pendientes))
	{
		fscanf(F_pendientes, "%d %d %f %d", &id_pedido_pendiente, &id_formula_pendiente, &cantidad_pendiente, &prioridad);

		while(!feof(F_finalizados))
		{
			fscanf(F_finalizados, "%d %d %f %d", &id_pedido_finalizado, &id_formula_finalizado, &cantidad_finalizado, &prioridad);
			if(id_pedido_finalizado == id_pedido_pendiente)
			{
				rewind(F_finalizados);
				break;
			}
		}
		if (id_pedido_finalizado != id_pedido_pendiente) {
			dosi_formula = id_formula_pendiente;
			dosi_cantidad = cantidad_pendiente;
			ShowMessage (dosi_formula);
			ShowMessage (dosi_cantidad);
			break;
		}
	}
	fclose(F_pendientes);
	fclose(F_finalizados);
}

void Proceso (void)
{
	if(proceso_iniciado)
	{
		switch (estado){ //MAQUINA DE ESTADOS
		case inicializacion:
			parar_proceso = false;
			estado = configuracion;
			break;
		case configuracion:
			//AQUI COMPROBAMOS EL PEDIDO QUE VAMOS A PROCESAR
			ArchivoComprobacion();

			break;
		case disponibilidad:
			//COMPROBAMOS QUE DISPONEMOS DE SUFICIENTE MATERIA
			break;
		case dosificar:
			//REALIZAMOS LA DOSIFICACIÓN Y PESADO
			break;
		case mezclado:
			//ABRIMOS VALVULA DE BÁSCULA Y ENCENDEMOS MOTOR MEZCLADORA
			break;
		case finaliza:
			//GENERAMOS REPORTE EN "PEDIDOS_TERMINADOS.TXT"
			//MOSTRAMOS AL USUARIO QUE SE HA TERMINADO EL PEDIDO

			if(parar_proceso)
			{
				estado = parada;
			}else{
				estado = inicializacion;
			}
			break;
		case parada:
			//NO HACEMOS NADA
			break;



		default: break;
		}


	}
}
