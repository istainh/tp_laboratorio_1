/*
 * FuncionesGenerales.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */
#include "FuncionesGenerales.h"

void encabezadoMenu()
{
	printf("MEN� ADMINISTRADOR DE PASAJEROS\n\n"
			"1. Dar de alta a un pasajero.\n"
			"2. Modificar los datos de un pasajero.\n"
			"3. Dar de baja a un pasajero.\n"
			"4. Informar listados.\n"
			"5. Carga forzada pasajeros.\n"
			"6. Salir del administrador.\n");
}

int opcionMenu(int* opcion)
{
	int aux;
	int seleccion;
	int retorno=0;
	aux=obtenerInt(&seleccion, "Ingrese una opci�n:\n", "No ingres� una opci�n v�lidad. Por favor vuelva a intentarlo.\n", 1, 6, 10);
	if(aux)
	{
		*opcion=seleccion;
		retorno=1;
	}
	else
	{
		printf("Error al seleccionar en el menu. Intente m�s tarde.\n");
	}
	return retorno;
}

void consultarSalir(char* salir)
{
	int aux;
	char seleccion;
	if(salir!=NULL)
	{
		aux=obtenerCaracter(&seleccion, "�Desea salir? [s]-si o [n]-no:\n", "Error. Ingrese una opci�n v�lida: [s]-si o [n]-no:\n", 's', 'n', 10);
		if(aux)
		{
			*salir=seleccion;
			printf("�Hasta la pr�xima!\n");
		}
	}
}

