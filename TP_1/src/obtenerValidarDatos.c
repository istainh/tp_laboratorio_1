/*
 * obtenerValidarDatos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */

#include "obtenerValidarDatos.h"

int obtenerCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos)
{
	int retorno=1;
	char caracter;

	if(pCaracter!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &caracter);

			if(caracter==opcionUno||caracter==opcionDos)
			{
				*pCaracter=caracter;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}
	return retorno;
}

int obtenerNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=1;
	int numero;

	if (pNumero!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &numero);
			if (numero>=minimo && numero<=maximo)
			{
				*pNumero=numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int obtenerFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=1;
	float numero;

	if (pNumero!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &numero);
			if (numero>=minimo && numero<=maximo)
			{
				*pNumero=numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}






