/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imput.h"
//#include "cliente.h"
//#include "pedido.h"
#include "nexo.h"


#define TAMC 100
#define TAMP 1000


int main(void)
{
	setbuf(stdout,NULL);

	Cliente listaCliente[TAMC] =   {{1, "ViewSonic SA" , "1230456780" , "Iguazu 104" , "Avellaneda", FALSE },
            						{2, "Logitech SRL" , "3100593550" , "Tatooine 333" , "Crucesita", FALSE },
									{3, "Canyon" , "2934567430" , "Naboo 231" , "Wilde", FALSE },
									{4, "Samsung" , "305468930" , "Lothal 55" , "Quilmes", FALSE },
									{5, "Coca-Cola Company" , "2035698450" , "Lothal 950" , "Burzaco", FALSE }} ;
	Pedido listaPedido[TAMP] = {{1, 1 , 200 , "Pendiente" , 0,0,0, FALSE },
								{2, 4 , 150 , "Pendiente" , 0,0,0, FALSE },
								{3, 2 , 300 , "Pendiente" , 0,0,0, FALSE },
								{4, 3 , 50 , "Pendiente" , 0,0,0, FALSE },
								{5, 1 , 150.50 , "Pendiente" , 0,0,0, FALSE }} ;
	//AuxiliarPedidos listaContPedidos[TAMC];
	/*Tipo listaTipo[4] = {{1, "HDPE"},
						 {2,"LDPE"},
					     {3,"PP"}};*/
	int opcion;
	int iniEmp = 0; //BORRAR CUANDO SAQUES LOS CLIENTES HARCODEADOS
	int alta,altaPedidos;

	//iniEmp = initClientes(listaCliente, TAMC);

	if(iniEmp == 0)
	{
		do
		{
			printf("------NOMINA DE EMPLEADOS------\n"
					"1. ALTA DE CLIENTE\n"
					"2. MODIFICAR DATOS DE CLIENTE\n"
					"3. BAJA DE CLIENTE\n"
					"4. CREAR PEDIDO DE RECOLECCION\n"
					"5. PROCESAR RESIDUOS\n"
					"6. IMPRIMIR CLIENTES\n"
					"7. IMPRIMIR PEDIDOS PENDIENTES\n"
					"8. IMPRIMIR PEDIDOS PROCESADOS\n"
					"9. IMPRIMIR CANT DE PEDIDOS PENDIENTES POR LOCALIDAD INGRESADA\n"
					"10. CANT KG PROPILENO PROMEDIO POR CLIENTE\n"
					"20. SALIR\n");
			opcion = PedirEnteroValidar("Ingrese la opcion: ", "Opcion incorrecta!!!", 1, 20);

			switch(opcion)
			{
				case 1:  //INFORMAR EL ID DEL CLIENTE QUE SE DIO DE ALTA SI ES EXITOSA LA CARGA
					alta = CargaDeCliente(listaCliente, TAMC);
					if(alta!=-1)
					{
						printf("\nEmpleado ID=%d cargado con exito!\n\n",alta);
					}
					else
					{
						printf("\n\nError! Espacio de clientes insuficientes.\n\n");
					}
					break;

				case 2: //Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					if(alta==0)
					{
						modificarCliente(listaCliente, TAMC);
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					break;

				case 3:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					if(alta==0)
					{
						eliminarCliente(listaCliente, TAMC);
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					break;

				case 4:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					if(alta==0)
					{
						CargaDePedido(listaPedido, listaCliente, TAMP, TAMC);
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					break;

				case 5:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						ProcesarResiduos(listaPedido, listaCliente, TAMP, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 6:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						MostrarListaClientesConCantPedidosPendientes(listaPedido, TAMP, listaCliente, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 7:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						MostrarListaPedidosPendientes(listaPedido, TAMP, listaCliente, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 8:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						MostrarListaPedidosProcesados(listaPedido, TAMP, listaCliente, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 9:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						MostrarLocalidadesConCantPedidosPendientes(listaPedido, TAMP, listaCliente, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 10:
					alta = ValidarCargaRegistros(listaCliente, TAMC);
					altaPedidos = ValidarCargaPedidos(listaPedido, TAMP);
					if(alta==0 && altaPedidos==0)
					{
						PromedioKilosPropilenoPorCliente(listaPedido, TAMP, listaCliente, TAMC);
					}
					else if(alta!=0)
					{
						printf("\nERROR!!! Primero debe cargar minimo un cliente.\n\n");
					}
					else
					{
						printf("\nERROR!!! Primero debe cargar minimo un pedido.\n\n");
					}
					break;

				case 20:
					printf("\n¡Hasta Luego!");
					break;
			}

		}while(opcion!=20);
	}
	return EXIT_SUCCESS;
}
