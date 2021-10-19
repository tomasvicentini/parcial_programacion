#include "nexo.h"

void CargaDePedido(Pedido listaPedidos[],Cliente listaClientes[], int tamPedido, int tamCliente)
{
  int i;
  int maximo;
  for (i = 0; i < tamPedido; i++)
  {
      if (listaPedidos[i].isEmpty == TRUE)
      {
    	  listaPedidos[i].id = i+1;
    	  mostrarListadoDeClientes(listaClientes, tamCliente);
		  listaPedidos[i].idCliente = PedirEnteroValidar("Ingrese el id del cliente: ", "Cliente inexistente!!!", 1, maximo = contarClientesCargados(listaClientes, tamCliente));
		  listaPedidos[i].kilos = PedirFloatValidar("Kilos: ", 0, 999999);
		  listaPedidos[i].kHDPE=0;
		  listaPedidos[i].kLDPE=0;
		  listaPedidos[i].kPP=0;
		  strcpy(listaPedidos[i].estado,"Pendiente");

		  //listaPedidos[i].nacionalidad =PedirEntero ("Ingrese la nacionalidad: 1/EEUU 2/CHINA 3/OTRO ");
		  //MostrarTipoDeProducto(listaClientes,tamTipo);

		  //("Ingrese el tipo: 1000/IPHONE 1001/MAC 1002/IPAD 1003/ACCESORIOS");

		  listaPedidos[i].isEmpty = FALSE;
		  break;
      }
  }
}

void ProcesarResiduos(Pedido listaPedidos[],Cliente listaClientes[],int tamPedido, int tamCliente)
{
  int maximo,id,opcion;
  int indice=-1;
  Pedido AuxPedido;

  do
  {
	  MostrarListaPedidos(listaPedidos, tamPedido, listaClientes, tamCliente);
	  id = PedirEnteroValidar("Ingrese el id del pedido: ", "Pedido inexistente!!!", 1, maximo = contarPedidosCargados(listaPedidos, tamPedido));

	  for(int i=0;i<tamPedido;i++)
	  {
		  if(listaPedidos[i].id==id && strcmp(listaPedidos[i].estado,"Pendiente")==0)
		  {
			  AuxPedido.kilos = listaPedidos[i].kilos;
			  AuxPedido.kHDPE = 0;
			  AuxPedido.kLDPE = 0;
			  AuxPedido.kPP = 0;
			  indice=i;
		  }
	  }

	  if(indice!=-1)
	  {
		  do
		  {
			  printf("\n------PROCESAR RESIDUOS------\n");
			  printf("Kilos recolectados: %.2fkg\nDisponibles: %.2fkg\n",listaPedidos[indice].kilos,AuxPedido.kilos);
			  printf("\t1- HDPE - Polietileno de alta densidad (%.2fkg):\n",AuxPedido.kHDPE);
			  printf("\t2- LDPE - Polietileno de baja densidad (%.2fkg):\n",AuxPedido.kLDPE);
			  printf("\t3- PP - Polipropileno (%.2fkg):\n",AuxPedido.kPP);
			  printf("\t4- CANCELAR\n");
			  if(AuxPedido.kilos==0)
			  {
				  printf("\t5- PROCESAR\n");
				  opcion = PedirEnteroValidar("Ingrese la opcion: ", "Opcion incorrecta!!!", 1, 5);
			  }
			  else
			  {
				  opcion = PedirEnteroValidar("Ingrese la opcion: ", "Opcion incorrecta!!!", 1, 4);
			  }

			  switch(opcion)
			  {
				  case 1:
					  AuxPedido.kHDPE = PedirFloatValidarConFloat("\nKg procesados de HDPE: ", 0, AuxPedido.kilos);
					  AuxPedido.kilos = AuxPedido.kilos-AuxPedido.kHDPE;
					  printf("\nKilos de HDPE ingresados!\n");
					  system("pause");
					  break;
				  case 2:
					  AuxPedido.kLDPE = PedirFloatValidarConFloat("\nKg procesados de LDPE: ", 0, AuxPedido.kilos);
					  AuxPedido.kilos = AuxPedido.kilos-AuxPedido.kLDPE;
					  printf("\nKilos de LDPE ingresados!\n");
					  system("pause");
					  break;
				  case 3:
					  AuxPedido.kPP = PedirFloatValidarConFloat("\nKg procesados de PP: ", 0, AuxPedido.kilos);
					  AuxPedido.kilos = AuxPedido.kilos-AuxPedido.kPP;
					  printf("\nKilos de PP ingresados!\n");
					  system("pause");
					  break;
				  case 4:
					  printf("\nProceso abortado por el usuario! Se reestablecen los pesos ingresados para cada tipo...\n\n");
					  break;
				  case 5:
					  listaPedidos[indice].kHDPE=AuxPedido.kHDPE;
					  listaPedidos[indice].kLDPE=AuxPedido.kLDPE;
					  listaPedidos[indice].kPP=AuxPedido.kPP;
					  strcpy(listaPedidos[indice].estado,"Procesado");
					  printf("\nPedido procesado!\n\n");
					  break;
			  }

		  }while(opcion!=4 && opcion!=5);

		  printf("¿Desea procesar otro pedido?\n");
		  printf("\t1-SI\n");
		  printf("\t2-NO");
		  opcion = PedirEnteroValidar("\nIngrese la opcion: ", "Opcion incorrecta!!!", 1, 2);
	  }
	  else
	  {
		  printf("\nEl pedido ya se encuentra PROCESADO!!!\n\n");
	  }
  }while(opcion!=2);
}

void MostrarPedido (Pedido pedido, Cliente listaClientes[], int tamCliente)
{
	for (int i=0; i<tamCliente; i++)
    {
        if (listaClientes[i].id == pedido.idCliente)
        {
            printf ("%10d | %30s | %8.2f | %8.2f | %8.2f | %8.2f | %12s |\n",   pedido.id,
																				listaClientes[i].nombre,
																				pedido.kilos,
																				pedido.kHDPE,
																				pedido.kLDPE,
																				pedido.kPP,
																				pedido.estado);
            break;
        }
    }

}

void MostrarListaPedidos (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("%10s | %30s | %8s | %8s | %8s | %8s | %12s |\n","ID PEDIDO","NOMBRE EMPRESA", "KILOS", "HDPE", "LDPE", "PP", "ESTADO");
	printf("--------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < tamPedido; i++)
	{
      if (listaPedidos[i].isEmpty == FALSE)
      {
	    MostrarPedido (listaPedidos[i], listaClientes, tamCliente);
	  }
    }
	printf("--------------------------------------------------------------------------------------------------------\n");
}

void MostrarPedidoPendientes (Pedido pedido, Cliente listaClientes[], int tamCliente)
{
	for (int i=0; i<tamCliente; i++)
    {
        if (listaClientes[i].id == pedido.idCliente)
        {
            printf ("%10d | %15s | %30s | %8.2f |\n",   pedido.id,
            											listaClientes[i].cuit,
														listaClientes[i].direccion,
														pedido.kilos);
            break;
        }
    }

}
void MostrarListaPedidosPendientes (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	printf("-------------------------PEDIDOS PENDIENTES-------------------------------\n");
	printf("--------------------------------------------------------------------------\n");
	printf("%10s | %15s | %30s | %8s |\n","ID PEDIDO", "CUIT", "DIRECCION", "KILOS");
	printf("--------------------------------------------------------------------------\n");
	for (int i = 0; i < tamPedido; i++)
	{
      if (listaPedidos[i].isEmpty == FALSE && strcmp(listaPedidos[i].estado,"Pendiente")==0)
      {
	    MostrarPedidoPendientes (listaPedidos[i], listaClientes, tamCliente);
	  }
    }
	printf("--------------------------------------------------------------------------\n");
}

void MostrarPedidoPendientesConLocalidad (Pedido pedido, Cliente listaClientes[], int tamCliente)
{
	for (int i=0; i<tamCliente; i++)
    {
        if (listaClientes[i].id == pedido.idCliente)
        {
            printf ("%10d | %30s | %30s | %8.2f | %8.2f | %8.2f | %8.2f | %12s |\n",    pedido.id,
																						listaClientes[i].nombre,
																						listaClientes[i].localidad,
																						pedido.kilos,
																						pedido.kHDPE,
																						pedido.kLDPE,
																						pedido.kPP,
																						pedido.estado);
            break;
        }
    }

}
void MostrarListaPedidosPendientesConLocalidad (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	printf("---------------------------------------PEDIDOS PENDIENTES CON LOCALIDAD------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%10s | %30s | %30s | %8s | %8s | %8s | %8s | %12s |\n","ID PEDIDO","NOMBRE EMPRESA", "LOCALIDAD", "KILOS", "HDPE", "LDPE", "PP", "ESTADO");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < tamPedido; i++)
	{
      if (listaPedidos[i].isEmpty == FALSE)
      {
    	  MostrarPedidoPendientesConLocalidad (listaPedidos[i], listaClientes, tamCliente);
	  }
    }
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
}

void MostrarPedidoProcesados (Pedido pedido, Cliente listaClientes[], int tamCliente)
{
	for (int i=0; i<tamCliente; i++)
    {
        if (listaClientes[i].id == pedido.idCliente)
        {
            printf ("%10d | %15s | %30s | %8.2f | %8.2f | %8.2f |\n",   pedido.id,
            															listaClientes[i].cuit,
																		listaClientes[i].direccion,
																		pedido.kHDPE,
																		pedido.kLDPE,
																		pedido.kPP);
            break;
        }
    }

}
void MostrarListaPedidosProcesados (Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	printf("------------------------------------PEDIDOS PROCESADOS------------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%10s | %15s | %30s | %8s | %8s | %8s |\n","ID PEDIDO", "CUIT", "DIRECCION", "HDPE", "LDPE", "PP");
	printf("------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < tamPedido; i++)
	{
      if (listaPedidos[i].isEmpty == FALSE && strcmp(listaPedidos[i].estado,"Procesado")==0)
      {
	    MostrarPedidoProcesados (listaPedidos[i], listaClientes, tamCliente);
	  }
    }
	printf("------------------------------------------------------------------------------------------------\n");
}

void MostrarListaClientesConCantPedidosPendientes(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	AuxiliarPedidos contador[tamCliente];
    //int maximo;
    int flag = -1;

    for(int i = 0; i < tamCliente; i++)
    {
       contador[i].contador = 0;
       contador[i].id = listaClientes[i].id;
    }

    for(int  i=0; i < tamCliente; i++)
    {
        for(int j=0; j < tamPedido; j++)
        {
            if(listaPedidos[j].idCliente == contador[i].id && strcmp(listaPedidos[j].estado,"Pendiente")==0)
            {
                contador[i].contador++;
            }
        }

    }

    printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%4s | %30s | %15s | %30s | %30s | %13s |\n","ID","NOMBRE EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD", "CANT PEDIDOS");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i<tamCliente; i++)
    {
       if(listaClientes[i].isEmpty == FALSE)
        {
            printf("%4d | %30s | %15s | %30s | %30s | %13d |\n",    listaClientes[i].id,
            														listaClientes[i].nombre,
																	listaClientes[i].cuit,
																	listaClientes[i].direccion,
																	listaClientes[i].localidad,
																	contador[i].contador);
            flag = 0;
        }
    }
    if(flag==0)
    {
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    else if(flag == -1)
    {
        printf("No se han cargado clientes\n\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}


void MostrarLocalidadesConCantPedidosPendientes(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	AuxiliarPedidos contador[tamCliente];
    //int maximo;
    int flag = -1;

    char localidad[51];
    MostrarListaPedidosPendientesConLocalidad(listaPedidos, tamPedido, listaClientes, tamCliente);
    PedirString("Ingrese una localidad: ", localidad);

    for(int i = 0; i < tamCliente; i++)
    {
       contador[i].contador = 0;
       contador[i].id = listaClientes[i].id;
    }

    for(int  i=0; i < tamCliente; i++)
    {
        for(int j=0; j < tamPedido; j++)
        {
            if(listaPedidos[j].idCliente == contador[i].id && strcmp(listaClientes[i].localidad,localidad)==0)
            {
                contador[i].contador++;
            }
        }

    }

    printf("-------------------------------------------------------\n");
    printf("%4s | %30s | %13s |\n","ID", "LOCALIDAD", "CANT PEDIDOS");
    printf("-------------------------------------------------------\n");

    for(int i=0; i<tamCliente; i++)
    {
       if(listaClientes[i].isEmpty == FALSE && strcmp(listaClientes[i].localidad,localidad)==0)
        {
            printf("%4d | %30s | %13d |\n",    listaClientes[i].id,
            								   listaClientes[i].localidad,
											   contador[i].contador);
            flag = 0;
        }
    }
    if(flag==0)
    {
    	printf("-------------------------------------------------------\n");
    }
    else if(flag == -1)
    {
        printf("No se han cargado clientes\n\n");
        printf("-------------------------------------------------------\n");
    }
}


void PromedioKilosPropilenoPorCliente(Pedido listaPedidos[], int tamPedido, Cliente listaClientes[], int tamCliente)
{
	AuxiliarPedidos contador[tamCliente];
	AucumuladorPedidos acumulador[tamCliente];
	AucumuladorPedidos promedio[tamCliente];
	//int maximo;
    int flag = -1;

    for(int i = 0; i < tamCliente; i++)
    {
       contador[i].contador = 0;
       contador[i].id = listaClientes[i].id;
       acumulador[i].id=listaClientes[i].id;
       acumulador[i].suma=0;
       promedio[i].id=listaClientes[i].id;
	   promedio[i].suma=0;
    }

    for(int  i=0; i < tamCliente; i++)
    {
        for(int j=0; j < tamPedido; j++)
        {
            if(listaPedidos[j].idCliente == contador[i].id)
            {
            	acumulador[i].suma+=listaPedidos[j].kPP;
            	contador[i].contador++;
            }
        }

    }
    for(int  i=0; i < tamCliente; i++)
    {
    	if(contador[i].contador!=0)
    	{
			promedio[i].suma = acumulador[i].suma / (float) contador[i].contador;
    	}
    }


    printf("----------------------------------------------------------------------------------\n");
    printf("%4s | %30s | %8s | %13s | %13s |\n","ID", "NOMBRE EMPRESA", "KILOS PP", "CANT PEDIDOS", "PROMEDIO PP");
    printf("----------------------------------------------------------------------------------\n");

    for(int i=0; i<tamCliente; i++)
    {
       if(listaClientes[i].isEmpty == FALSE)
        {
            printf("%4d | %30s | %8.2f | %13d | %13.2f |\n",    listaClientes[i].id,
            													listaClientes[i].nombre,
																acumulador[i].suma,
																contador[i].contador,
																promedio[i].suma);
            flag = 0;
        }
    }
    if(flag==0)
    {
    	printf("----------------------------------------------------------------------------------\n");
    }
    else if(flag == -1)
    {
        printf("No se han cargado clientes\n\n");
        printf("----------------------------------------------------------------------------------\n");
    }
}


/****************************************************************
int contarCantidadProductoTipo (Pedido listaPedidos[], int tamPedido, Cliente idCliente, int *contTipo)
 {
   int retorno = -1;
   int cont = 0;

   if (listaPedidos != NULL && tamPedido > 0)
   {
       for (int i=0; i < tamPedido; i++)
 	   {
     	  retorno = 1;
     	  if (listaPedidos[i].idCliente == idCliente && listaPedidos[i].isEmpty != FALSE && strcmp(listaPedidos[i].estado,"Pendiente")==0)
     	  {
     	      cont++;
     	      retorno = 0;
     	  }
 	   }
       *contTipo = cont;
   }

   return retorno;
 }

void BajadeProducto (Pedido listaPedidos[], int tam, Cliente tipoProducto[], int sizeTipoProducto)
{
  int Idproducto;

  MostrarListaProductos (listaPedidos, tam, tipoProducto, sizeTipoProducto);

  Idproducto = PedirEntero ("Ingrese el ID del producto");


  for (int i = 0; i < tam; i++)
    {

      if (listaPedidos[i].estado != TRUE
	  && listaPedidos[i].idProducto == Idproducto)
	{
	  listaPedidos[i].estado = TRUE;
	  break;
	}

    }
}


void ModificarProducto (Pedido listaPedidos[], int tam, Cliente tipoProducto[], int sizeTipoProducto)
{
  int Idproducto;


  MostrarListaProductos (listaPedidos, tam, tipoProducto, sizeTipoProducto);

  Idproducto = PedirEntero ("Ingrese el ID del producto a modificar");


  for (int i = 0; i < tam; i++)
    {

      if (listaPedidos[i].estado != TRUE
	  && listaPedidos[i].idProducto == Idproducto)
	{
	  PedirString ("ingrese la descripcion",
		       listaPedidos[i].descripcion);


	  break;
	}

    }
}

int MostrarProductoPorPrecio (Pedido listaPedidos[], int tam,
			  float precioABuscar, Cliente tipoProducto[], int sizeTipoProducto)
{

  int existeUno;
  existeUno = 0;

  for (int i = 0; i < tam; i++)
    {
      if (listaPedidos[i].precio == precioABuscar
	  && listaPedidos[i].estado == FALSE)
	{
	  existeUno = 1;
	  MostrarProducto (listaPedidos[i], tipoProducto, sizeTipoProducto);
	}
    }

  return existeUno;
}





int promedioTipoProducto(Pedido listaPedidos[], int tamProductos, Cliente listaClientes[], int tamTipo)
{
    int rtn = 1;
    int contTipo = 0;
    float acTipo = 0;
    float promedio;


    if(listaPedidos != NULL && tamProductos > 0 && listaClientes != NULL && tamTipo > 0)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            for(int j = 0; j < tamProductos; j++)
            {

                if(listaPedidos[j].idTipo == listaClientes[i].idTipo && listaPedidos[j].estado != TRUE)
                {
                    acTipo += listaPedidos[j].precio;
                    contTipo++;
                    rtn = 0;



                }

            }

            if(contTipo != 0)
            {

                promedio = acTipo / contTipo;

                printf("Promedio de %s: %.2f \n", listaClientes[i].descripcion, promedio);
            }
            else
            {
                printf("No se ingresaron productos de %s \n", listaClientes[i].descripcion);
            }
            contTipo = 0;
            acTipo = 0;

        }

    }

    return rtn;
}




void MostrarNacionalidadTipoProducto(eNacionalidad listaNacionalidades[], int tamNacionalidad,
Cliente listaClientes[],int tamTipoProducto, Pedido listaPedidos[], int tamProducto)
{
    int bandera= 0;

    for(int i= 0; i< tamNacionalidad; i++)// recorro nacionalidad
    {
        //for(int j= 0; j< tamTipoProducto; j++)// recorro tipo de producto
        //{
            for(int k= 0; k< tamProducto; k++)// recorro lista productos
            {
                if((listaPedidos[k].nacionalidad == listaNacionalidades[i].idNacionalidad) && listaPedidos[k].idTipo != 1000)
                {

                    bandera = 1;
                    break;
                }
            }
            if(bandera== 0)
            {
                printf("%s\n",listaNacionalidades[i].nacionalidad);

            }
            bandera= 0;
        //}
    }
}




*****************************************/








































