/*
 ============================================================================
 Name        : main.c
 Author      : Ainhoa Osorio
 Version     : 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 float
double
%lf
%.3lf

 */

#include "funcionesGenerales.h"

int main(void) {
	setbuf(stdout, NULL);

	char salir;
	int opcion;
	int aux;
	int auxDos;
	float km=0;
	float precioLatam=0;
	float precioAero=0;
	float precioBitcoin=803107.75;
	int flagKm=0;
	int flagPrecios=0;
	float precioDebitoLatam;
	float precioDebitoAero;
	float precioCreditoLatam;
	float precioCreditoAero;
	float precioBitcoinLatam;
	float precioBitcoinAero;
	float precioUnitarioLatam;
	float precioUnitarioAero;
	float precioDiferencia;
	int flagCalculos=0;

	do
	{
		encabezadoMenu(km, precioAero, precioLatam, precioBitcoin);
		opcionMenu(&opcion);
		switch (opcion)
		{
			case 1:
				aux=obtenerFloat(&km, "Ingrese los kilómetros:\n\n", "Error. Cantidad de kilómetros ingresados inválido.\n\n",
								0, 1000000, 10);
				if(aux==0)
				{
					flagKm = 1;
					aux=1;
				}
				else
				{
					printf("Hubo un error al intentar obtener los kilómetros. Volviendo al menú...\n\n");
				}
				break;
			case 2:
				aux=obtenerFloat(&precioAero, "Ingrese el precio de Aerolíneas Argentinas:\n\n", "Error. Precio ingresado inválido.\n\n",
								1, 100000000, 10);
				auxDos=obtenerFloat(&precioLatam, "Ingrese el precio de Latam:\n\n", "Error. Precio ingresado inválido.\n\n",
								1, 100000000, 10);
				if(aux==0&&auxDos==0)
				{
					flagPrecios = 1;
					aux=1;
					auxDos=1;
				}
				else
				{
					printf("Hubo un error al intentar obtener los precios de las aerolineas. Volviendo al menú...\n\n");
				}
				break;
			case 3:
				if(flagKm==0)
				{
					printf("Por favor ingrese los kilómetros antes de calcular todo.\n\n");
				}
				else if(flagPrecios==0)
				{
					printf("Por favor ingrese los precios de los vuelos antes de calcular todo.\n\n");
				}
				else
				{
					procesarPrecios(precioLatam, km, precioBitcoin, &precioDebitoLatam, &precioCreditoLatam,
							       &precioBitcoinLatam, &precioUnitarioLatam);
					procesarPrecios(precioAero, km, precioBitcoin, &precioDebitoAero, &precioCreditoAero,
							       &precioBitcoinAero, &precioUnitarioAero);
					restar(precioAero, precioLatam, &precioDiferencia);
					flagCalculos=1;
				}
				break;
			case 4:
				if(flagCalculos==0)
				{
					printf("Todavía no hay resultados para mostrar.\n");
				}
				else
				{
					informarResultados(precioLatam, precioAero, precioDebitoLatam, precioCreditoLatam,
							          precioBitcoinLatam, precioUnitarioLatam, precioDebitoAero, precioCreditoAero,
									  precioBitcoinAero, precioUnitarioAero, precioDiferencia);
				}
				break;
			case 5:
				km=7090;
				precioLatam=159339;
				precioAero=162965;
				cargaCalculoForzado(km, precioLatam, precioAero, precioBitcoin);
				break;
			case 6:
				consultarSalir(&salir);
				break;
		}
	}while(salir=='n'||opcion!=6);
	return EXIT_SUCCESS;
}
