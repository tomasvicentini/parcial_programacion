#include "cliente.h"
#include "pedido.h"

int ValidarCargaPedidos(Pedido list[], int len)
{
    int i;
    int acceso = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            acceso = 0;
        }
    }
    return acceso;
}

int contarPedidosCargados(Pedido listado[], int tam)
{
	int contador = 0;

	for(int i=0;i<tam;i++)
	{
		if(listado[i].isEmpty==FALSE)
		{
			contador++;
		}
	}
	return contador;
}
