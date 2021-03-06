//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitProcesos.h"
#include "UnitFormDosificador.h"
#include "UnitDatos.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool proceso_iniciado, parar_proceso;
enum Estado{disponibilidad, dosificar, mezclado, finaliza, parada_automatica};
Estado estado;

int dosi_id_pedido, dosi_formula, dosi_prioridad;
float dosi_cantidad;

void IniciarProceso (void)
{
	proceso_iniciado = true;
	parar_proceso = false;

	//AQUI COMPROBAMOS EL PEDIDO QUE VAMOS A PROCESAR
	dosi_id_pedido = LeerIdPedido();
	BuscarPedido(dosi_id_pedido);
	estado = disponibilidad;
}

void PararProceso (void)
{
	parar_proceso = true;
	proceso_iniciado = false;
}

bool InfoProceso (void){return proceso_iniciado;}

//COMPROBACI�N DE PEDIDO EN ARCHIVO
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
			ShowMessage(id_pedido_pendiente);
			ShowMessage(id_pedido_finalizado);
			if(id_pedido_finalizado == id_pedido_pendiente)
			{
				rewind(F_finalizados);
				break;
			}
		}
		if (id_pedido_finalizado != id_pedido_pendiente) {
			dosi_formula = id_formula_pendiente;
			dosi_cantidad = cantidad_pendiente;
			//ShowMessage (dosi_formula);
			//ShowMessage (dosi_cantidad);
			break;
		}
	}
	fclose(F_pendientes);
	fclose(F_finalizados);
}

int LeerIdPedido(void)
{
	FILE *F;
	int id_pedido;

	F = fopen("file_idPedidoAFabricar.txt", "r");   //Abro para leer
	if (!F) ShowMessage("Error abriendo el archivo file_idPedidoAFabricar.txt");

	fscanf(F, "%d", &id_pedido);

	fclose(F);
	return id_pedido;
}

void GuardarIdPedido (int id_pedido)
{
	FILE *F;

	F = fopen("file_idPedidoAFabricar.txt", "w"); //Abri fichero sobreescritura
	if (!F) ShowMessage("Error abriendo el archivo file_idPedidoAFabricar.txt");

	fprintf(F, "%d", id_pedido);

	fclose(F);
}

void BuscarPedido (int id_pedido)
{
	FILE *F;
	char text[80];

	F = fopen("file_pedidosPendientes.txt", "r");   //Abro para leer
	if (!F) ShowMessage("Error abriendo el archivo file_pedidosPendientes.txt");

	while(!feof(F))
	{
		fscanf(F, "%d %d %f %d", &dosi_id_pedido, &dosi_formula, &dosi_cantidad, &dosi_prioridad);
		//ShowMessage(cantidad);

		if(dosi_id_pedido == id_pedido){
			sprintf(text, "Se va a tramitar el pedido n�: %d\n*Formula n�: %d, %s\n*Cantidad(kg): %.2f", dosi_id_pedido, dosi_formula, formula[dosi_formula].Nombre(), dosi_cantidad);
			ShowMessage(text);
			//fclose(F);
			return;
		}
	}
	ShowMessage("No hay ning�n pedido pendiente. \nRealice un nuevo pedido!");
	estado = parada_automatica;
}

void Proceso (void)
{
	static float cantidad_necesaria[3];
	static float peso_acumulado;
	static int materias_necesarias[3];
	static int depositos_necesarios[3];
	static int disponible=0;
	static char text[40];
	static int i = 0;
	static tiempo=0;

	if(proceso_iniciado | parar_proceso)
	{
		switch (estado){ //MAQUINA DE ESTADOS
		case disponibilidad:
			//COMPROBAMOS QUE DISPONEMOS DE SUFICIENTE MATERIA
			//MATERIA 1
			for(int i=0; i<3; i++)
			{
				materias_necesarias[i] = formula[dosi_formula].IdMateria(i);
				cantidad_necesaria[i] = formula[dosi_formula].Proporcion(i) * dosi_cantidad;
				depositos_necesarios[i] = materia[materias_necesarias[i]].IdDeposito();

				//ShowMessage(materias_necesarias[i] = formula[dosi_formula].IdMateria(i));
				//ShowMessage((deposito[materia[materias_necesarias[i]].IdDeposito()].Cantidad()));

				if(deposito[depositos_necesarios[i]].Cantidad() < cantidad_necesaria[i]) //Si lo que hay en el deposito es menor que lo necesario
				{
					sprintf(text, "El Deposito %d no tiene suficiente %s", materia[materias_necesarias[i]].IdDeposito()+1, materia[materias_necesarias[i]].Nombre());
					ShowMessage(text);
				}else{
					disponible++;
                }
			   //ShowMessage(cantidad_necesitada[i]);
			   //ShowMessage(formula[dosi_formula].Proporcion(i));
			}
			if (disponible == 3) {
				ShowMessage("Cantidad en depositos disponible");
				estado = dosificar;
				disponible = 0;
				i=0;
				peso_acumulado=0;
				FormDosificador->TimerProceso->Enabled = true;//Habilito el timer de proceso
			}else{
				estado = parada_automatica;  //Si no hay disponibilidad en cualquiera de los depositos para el proceso
				Proceso();
            }
			break;
		case dosificar:
			//REALIZAMOS LA DOSIFICACI�N Y PESADO
			//DOSIFICACI�N
			if(bascula.Peso() < (cantidad_necesaria[i]+peso_acumulado))
			{
				deposito[depositos_necesarios[i]].Abrir();
			}else{
				deposito[depositos_necesarios[i]].Cerrar();
				peso_acumulado = bascula.Peso();
				i++; //Siguiente materia

				if(i==3)  //Finalizaci�n de dosificaci�n
				{
					i=0;
					estado = mezclado;
					tiempo = 0;
                }
			}
			if (parar_proceso) estado = parada_automatica;
			break;
		case mezclado:
			//ABRIMOS VALVULA DE B�SCULA Y ENCENDEMOS MOTOR MEZCLADORA
			//ABRIR VALVULA

			if (tiempo < 100)  //A los 10 segundos
			{
				bascula.Abrir();
			}else{
				bascula.Cerrar();
				mezcladora.MotorOn();
				if (tiempo == 200)
				{
					mezcladora.MotorOff();
					mezcladora.Abrir();
					tiempo=0;
					estado = finaliza;
					ShowMessage("Pedido Finalizado");
				}
			}
			tiempo++;
			if (parar_proceso) estado = parada_automatica;
			break;
		case finaliza:
			//GENERAMOS REPORTE EN "PEDIDOS_TERMINADOS.TXT"
			//MOSTRAMOS AL USUARIO QUE SE HA TERMINADO EL PEDIDO
			GuardarIdPedido(dosi_id_pedido+1); //Actualizo el pedido siguiente
			GenerarReporte(dosi_id_pedido, dosi_formula, dosi_cantidad);
			FormDosificador->TimerProceso->Enabled = false;//Deshabilito el timer de proceso
			break;

		case parada_automatica:
			//PARAMOS EL PROCESO FORZADAMENTE E INFORMAMOS AL USUARIO
			FormDosificador->TimerProceso->Enabled = false;//Deshabilito el timer de proceso
			proceso_iniciado = false;
			FormDosificador->ShapeProceso->Brush->Color = clRed;
			FormDosificador->ButtonInitProcess->Caption = "INICIAR PROCESO";

			for (int i=0; i<5; i++)
			{
				deposito[i].Cerrar();
			}

			bascula.Cerrar();
			mezcladora.Cerrar();
			disponible = 0;
			proceso_iniciado = false;

			ShowMessage("Proceso terminado automaticamente debido a error");
			break;
		default: break;
		}


	}
}
