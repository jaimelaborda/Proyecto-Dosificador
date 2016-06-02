//---------------------------------------------------------------------------

#ifndef UnitProcesosH
#define UnitProcesosH
//---------------------------------------------------------------------------
#endif

void IniciarProceso (void);
void PararProceso (void);
bool InfoProceso (void);
void Proceso (void);
int LeerIdPedido(void); //Función que devuelve el Id del Pedido que se ha de realizar
void GuardarIdPedido(int id_pedido); //Función que guarda el Id del pedido que se acaba de realizar
void BuscarPedido (int id_pedido);

