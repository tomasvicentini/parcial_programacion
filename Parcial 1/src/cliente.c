#include "cliente.h"


int initClientes(Cliente* list, int len)
{
	int flag = -1;

	for(int i=0;i<len;i++)
	{
		list[i].isEmpty = TRUE;
		flag = 0;
	}

	return flag;
}

int ValidarCargaRegistros(Cliente list[], int len)
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

int CargaDeCliente(Cliente* list, int tam)
{
  int id;
  char nombre[51];
  char cuit [15];
  char direccion[51];
  char localidad[51];
  int retorno = -1;

  for(int i=0; i < tam; i++)
  {
	  if(list[i].isEmpty == TRUE)
	  {
		  id = i+1;
		  printf("\nALTA DE CLIENTE ID=%i",id);
		  PedirString ("\n\nNombre de la Empresa: ",nombre);
		  PedirString ("CUIT: ",cuit);
		  PedirString ("Direccion: ",direccion);
		  PedirString ("Localidad: ",localidad);

		  retorno = agregarCliente(list, tam, id, nombre, cuit, direccion, localidad);
		  break;
	   }
  }

  return retorno; // -1 -> error | id si el alta es correcta
}

int agregarCliente(Cliente* list, int len, int id, char name[],char cuit[],char direccion[],char localidad[])
{
	//int flag = -1;
	int i = id-1;

	if(list[i].isEmpty==TRUE && id<=(len+1))
	{
		list[i].id=id;
		strcpy(list[i].nombre,name);
		strcpy(list[i].cuit,cuit);
		strcpy(list[i].direccion,direccion);
		strcpy(list[i].localidad,localidad);
		list[i].isEmpty=FALSE;

		//flag = 0;
	}

	return id; //devuelvo el id para informarlo si la carga es realizada correctamente
}

int findClienteById(Cliente* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].id == id)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

void mostrarListadoDeClientes(Cliente listado[], int tam)
{
    int i;
    int flag = -1;

	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("%4s | %30s | %15s | %30s | %30s |\n","ID","NOMBRE EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0; i<tam; i++)
    {
       if(listado[i].isEmpty == FALSE)
        {
            printf("%4d | %30s | %15s | %30s | %30s |\n",   listado[i].id,
                                                            listado[i].nombre,
															listado[i].cuit,
                                                            listado[i].direccion,
                                                            listado[i].localidad);
            flag = 0;
        }
    }
    if(flag==0)
    {
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
    }
    else if(flag == -1)
    {
        printf("No se han cargado clientes\n\n");
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
    }
}

void modificarCliente(Cliente listado[], int tam)
{
    int id, retorno, opcion;
    mostrarListadoDeClientes(listado, tam);

	id = PedirEnteroValidar("Ingrese ID del cliente a modificar: ","ID INVALIDO!!",1,tam);

	retorno = findClienteById(listado,tam,id);

	if(retorno!=-1 && listado[retorno].isEmpty == FALSE)
	{
		do
		{
			printf("------MODIFICAR CLIENTE------\n");
			printf("\t1- NOMBRE DE LA EMPRESA\n");
			printf("\t2- CUIT/S\n");
			printf("\t3- DIRECCION\n");
			printf("\t4- LOCALIDAD\n");
			printf("\t5- VOLVER\n");
			printf("----------------------------\n");
			opcion = PedirEnteroValidar("Ingrese la opcion: ", "Opcion incorrecta!!!", 1, 5);

			switch(opcion)
			{
				case 1:
					PedirString ("\nNombre de la empresa: ",listado[retorno].nombre);
					printf("\nNombre modificado!\n\n");
					system("pause");
					break;
				case 2:
					PedirString ("CUIT: ",listado[retorno].cuit);
					printf("\nCUIT modificado!\n\n");
					system("pause");
					break;
				case 3:
					PedirString ("Direccion: ",listado[retorno].direccion);
					printf("\nDireccion modificado!\n\n");
					system("pause");
					break;
				case 4:
					PedirString ("Localidad: ",listado[retorno].localidad);
					printf("\nLocalidad modificado!\n\n");
					system("pause");
					break;
				case 5:
					printf("Modificacion cancelada!\n\n");
					break;
			}
		}while(opcion!=5);
	}
	else
	{
		printf("ERROR! El cliente no existe!!\n\n");
		system("pause");
	}

}

int removeCliente(Cliente* list, int len, int id)
{
    int retorno = -1;

    for(int i=0;i<len; i++)
	{
    	if(list[i].isEmpty == FALSE && id == list[i].id)
    	{
    		printf("Esta seguro que desea eliminar el cliente ID:%d-%s?\n",list[i].id,list[i].nombre);
    		retorno = PedirEnteroValidar("1- Si\n2- No\nOpcion: ", "Error! Respuesta invalida (1 o 2)", 1, 2);
			if(retorno==1)
			{
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}

    return retorno;
}

void eliminarCliente(Cliente listado[], int tam)
{
    int retorno;
    int id;
    int eliminar;

    mostrarListadoDeClientes(listado, tam);
    id = PedirEnteroValidar("Ingrese ID del cliente a eliminar: ","ID INVALIDO!!",1,tam);

    retorno = findClienteById(listado,tam,id);

    if(retorno!=-1)
    {
    	eliminar = removeCliente(listado, tam, id);
    }

    if(eliminar==0)
    {
    	printf("\nCliente eliminado con exito!\n\n");
    }
    else if(eliminar==-1)
    {
    	printf("\nError! Cliente no encontrado.\n\n");
    }
    else
    {
    	printf("\nBaja abortada por el usuario.\n\n");
    }
}

int contarClientesCargados(Cliente listado[], int tam)
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
