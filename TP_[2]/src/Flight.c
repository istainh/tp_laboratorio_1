/*
 * Flight.c
 *
 *  Created on: 29 abr. 2022
 *      Author: Ainhoa
 */
#include "Flight.h"

void listarVuelo(Flight estructura[], int posicion)
{
	if(estructura!=NULL)
	{
		printf("t%s\t\t%s\n", estructura[posicion].codigoVuelo, estructura[posicion].descripcionEstado);

	}
	else
	{
		printf("Puntero nulo o posicion inválida en la funcion listarVuelo.\n");
	}
}

int listarVuelos(Flight estructura[], int tamanio)
{
	int retorno=0;
	int flagCabecera=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(flagCabecera==0)
			{
				printf("Códigos de vuelo:\tEstado del vuelo:\n");
				flagCabecera=1;
			}
			listarVuelo(estructura, i);
		}
		retorno=1;
	}
	return retorno;
}

int buscarVuelo(char* codigo, Flight estructura[], int tamanio)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(stricmp(estructura[i].codigoVuelo,codigo)==0)
			{
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarVuelo.\n");
	}
	return retorno;
}

int buscarPosicionVuelo(char* codigo, Flight estructura[], int tamanio, int* posicion)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(stricmp(estructura[i].codigoVuelo,codigo)==0)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarPosicionVuelo.\n");
	}
	return retorno;
}

int seleccionarVuelo(char codigo[], Flight estructura[], int tamanio)
{
	int retorno=0;
	char aux[CANT2];
	if(codigo!=NULL&&estructura!=NULL&&tamanio>0)
	{
		if(listarVuelos(estructura, tamanio))
		{
			if(obtenerString("Ingrese el código del vuelo:\n\n", "Error al seleccionar el código del vuelo. Intentelo de nuevo.\n\n", aux, 10))
			{
				if(buscarVuelo(aux, estructura, tamanio))
				{
					strcpy(codigo,aux);
					retorno=1;
				}
				else
				{
					printf("El código ingresado no existe. Vuelva a intentarlo luego.\n");
				}
			}
		}
	}
	else
	{
		printf("Punteros nulos o tamaño inválido en la funcion seleccionarVuelo.\n");
	}
	return retorno;
}

