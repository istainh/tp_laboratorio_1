/*
 * FuncionesGenerales.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */
#include "FuncionesGenerales.h"

void encabezadoMenu()
{
	printf("MENÚ ADMINISTRADOR DE PASAJEROS\n\n"
			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
			"3. Alta de pasajero.\n"
			"4. Modificar datos de pasajero.\n"
			"5. Baja de pasajero.\n"
			"6. Listar pasajeros.\n"
			"7. Ordenar pasajeros.\n"
			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n"
			"10. Salir.\n");
}

int opcionMenu(int* opcion)
{
	int aux;
	int seleccion;
	int retorno=0;
	aux=obtenerInt(&seleccion, "Ingrese una opción:\n", "No ingresó una opción válidad. Por favor vuelva a intentarlo.\n", 1, 10, 10);
	if(aux)
	{
		*opcion=seleccion;
		retorno=1;
	}
	else
	{
		printf("Error al seleccionar en el menu. Intente más tarde.\n");
	}
	return retorno;
}

void consultarSalir(char* salir)
{
	int aux;
	char seleccion;
	if(salir!=NULL)
	{
		aux=obtenerCaracter(&seleccion, "¿Desea salir? [s]-si o [n]-no:\n", "Error. Ingrese una opción válida: [s]-si o [n]-no:\n", 's', 'n', 10);
		if(aux)
		{
			*salir=seleccion;
			printf("¡Hasta la próxima!\n");
		}
	}
}

