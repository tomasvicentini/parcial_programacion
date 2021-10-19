#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "imput.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define FALSE 1
#define TRUE 0
//tipos de plastico
#define HDPE 1
#define LDPE 2
#define PP 3


struct
{
	int id;
	char nombre[51];
	char cuit[15];
	char direccion[51];
	char localidad[51];
	int isEmpty;
}typedef Cliente;

/// @brief Inicializa campo list.isEmpty de la lista de clientes
///
/// @param list
/// @param len
/// @return flag
int initClientes(Cliente* list, int len);

/// @brief valida que se haya ingresado un registro en la lista
///
/// @param list
/// @param len
/// @return acceso
int ValidarCargaRegistros(Cliente list[], int len);

/// @brief ingresa datos de un cliente
///
/// @param list
/// @param tam
/// @return retorno
int CargaDeCliente(Cliente* list, int tam);

/// @brief carga datos ingresados de un cliente
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param cuit
/// @param direccion
/// @param localidad
/// @return id
int agregarCliente(Cliente* list, int len, int id, char name[],char cuit[],char direccion[],char localidad[]);

/// @brief encuentra cliente por id
///
/// @param list
/// @param len
/// @param id
/// @return retorno
int findClienteById(Cliente* list, int len,int id);

/// @brief muestra listado de clientes con toda su informacion
///
/// @param listado
/// @param tam
void mostrarListadoDeClientes(Cliente listado[], int tam);

/// @brief modificar un cliente seleccionado por id
///
/// @param listado
/// @param tam
void modificarCliente(Cliente listado[], int tam);

/// @brief da de baja un cliente con el campo isEmpty
///
/// @param list
/// @param len
/// @param id
/// @return retorno
int removeCliente(Cliente* list, int len, int id);

/// @brief elimina un cliente seleccionado por id
///
/// @param listado
/// @param tam
void eliminarCliente(Cliente listado[], int tam);

/// @brief cuenta los clientes cargados por el usuario
///
/// @param listado
/// @param tam
/// @return contador
int contarClientesCargados(Cliente listado[], int tam);



#endif /* CLIENTE_H_ */
