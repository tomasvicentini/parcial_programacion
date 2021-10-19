#include "imput.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define FALSE 1
#define TRUE 0


int PedirEntero (char mensaje[])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}
int PedirEnteroValidar(char mensaje[],char mensajeError[], int minimo, int maximo)
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s %s",mensajeError,mensaje);
		scanf("%d", &numeroIngresado);
	}
	return numeroIngresado;
}

float PedirFloat (char mensaje[])
{
    float numeroIngresado;

    printf("%s \n", mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}
float PedirFloatValidar(char mensaje[], int minimo, int maximo)
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("Error. %s", mensaje);
		scanf("%f", &numeroIngresado);
	}
	return numeroIngresado;
}

float PedirFloatValidarConFloat(char mensaje[], float minimo, float maximo)
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	while (numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("Error. %s", mensaje);
		scanf("%f", &numeroIngresado);
	}
	return numeroIngresado;
}

void PedirString (char mensaje[], char stringIngresado[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}
