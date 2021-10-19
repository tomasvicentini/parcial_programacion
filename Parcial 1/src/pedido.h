#ifndef PEDIDO_H_
#define PEDIDO_H_
#include "imput.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#define PENDIENTE 1
//#define COMPLETADO 0

struct
{
	int id;
	int idCliente;
	float kilos;
	char estado[15];
	float kHDPE;
	float kLDPE;
	float kPP;
	float isEmpty;
}typedef Pedido;

typedef struct
{
    int id;
    int contador;
}AuxiliarPedidos;

typedef struct
{
    int id;
    float suma;
}AucumuladorPedidos;

/// @brief valida que se haya ingresado al menos un pedido
///
/// @param list
/// @param len
/// @return acceso
int ValidarCargaPedidos(Pedido list[], int len);

/// @brief
///
/// @param listado
/// @param tam
/// @return
int contarPedidosCargados(Pedido listado[], int tam);

#endif /* PEDIDO_H_ */
