/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */

#include <stdio.h>
#include <stdlib.h>

int restarPorcentaje(float numero, float porcentaje, float* resultado)
{
	int retorno=1;
	float numeroResta;
	if(resultado!=NULL)
	{
		numeroResta=numero*(porcentaje/100);
		*resultado=numero-numeroResta;
		retorno=0;
	}
	return retorno;
}

int sumarPorcentaje(float numero, float porcentaje, float* resultado)
{
	int retorno=1;
	float numeroSuma;
	if(resultado!=NULL)
	{
		numeroSuma=numero*(porcentaje/100);
		*resultado=numero+numeroSuma;
		retorno=0;
	}
	return retorno;
}

int dividir(float numUno, float numDos, float* resultado)
{
	int retorno=1;
	if(resultado!=NULL)
	{
		*resultado=numUno/numDos;
		retorno=0;
	}
	return retorno;
}

int restar(float numUno, float numDos, float* resultado)
{
	int retorno=1;
	if (resultado!=NULL)
	{
		*resultado=numUno-numDos;
		retorno=0;
	}
	return retorno;
}
