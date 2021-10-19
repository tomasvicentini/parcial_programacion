#ifndef NEXO_H_
#define NEXO_H_
#include "imput.h"
#include "pedido.h"
#include "cliente.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipoPlastico.h"

/// @brief carga un pedido
///
/// @param listaPedidos
/// @param listaClientes
/// @param tam
/// @param tamCliente
void CargaDePedido(Pedido listaPedidos[],Cliente listaClientes[], int tam, int tamCliente);

/// @brief muestra pedido y el nombre del cliente
///
/// @param pedido
/// @param listaClientes
/// @param tamCliente
void MostrarPedido (Pedido pedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra registros de pedidos y el cliente que lo realizo
///
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarListaPedidos (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief carga kilos de plasticos reciclados - HDPE | LDPE | PP
///
/// @param listaPedidos
/// @param listaClientes
/// @param tamPedido
/// @param tamCliente
void ProcesarResiduos(Pedido listaPedidos[],Cliente listaClientes[],int tamPedido, int tamCliente);

/// @brief muestra lista de clientes y su cantidad de pendidos PENDIENTES
/// campos: "ID","NOMBRE EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD", "CANT PEDIDOS"
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarListaClientesConCantPedidosPendientes(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra registros de la lista de clientes y su cantidad de pendidos PENDIENTES
///
/// @param pedido
/// @param listaClientes
/// @param tamCliente
void MostrarPedidoPendientes (Pedido pedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra lista de clientes y su cantidad de pendidos PENDIENTES
/// campos: "ID PEDIDO", "CUIT", "DIRECCION", "KILOS"
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarListaPedidosPendientes (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra registros de la lista de clientes y su cantidad de pendidos PROCESADOS
///
/// @param pedido
/// @param listaClientes
/// @param tamCliente
void MostrarPedidoProcesados (Pedido pedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra lista de clientes y su cantidad de pendidos PROCESADOS
/// campos: "ID PEDIDO", "CUIT", "DIRECCION", "HDPE", "LDPE", "PP"
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarListaPedidosProcesados (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra localidad de clientes y su cantidad de pendidos PENDIENTES por localidad
/// campos: "ID CLIENTE", "LOCALIDAD", "CANT PEDIDOS"
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarLocalidadesConCantPedidosPendientes(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra lista de pedidos PENDIENTES y cliente con nombre y localidad
///
/// @param pedido
/// @param listaClientes
/// @param tamCliente
void MostrarPedidoPendientesConLocalidad (Pedido pedido, Cliente listaClientes[], int tamCliente);

/// @brief muestra lista de pedidos PENDIENTES y cliente con nombre y localidad
/// campos: "ID PEDIDO","NOMBRE EMPRESA", "LOCALIDAD", "KILOS", "HDPE", "LDPE", "PP", "ESTADO"
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void MostrarListaPedidosPendientesConLocalidad (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);

/// @brief calcula y muestra suma, cantidad de pedidos y promedio de kilos de propileno procesado
///
/// @param listaPedidos
/// @param tamPedido
/// @param listaClientes
/// @param tamCliente
void PromedioKilosPropilenoPorCliente(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente);


































#endif
