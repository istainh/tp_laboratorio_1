/*
 * funcionesGenerales.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */

#include "funcionesGenerales.h"

void encabezadoMenu(float km, float precioUno, float precioDos, float precioBitcoin)
{
	printf("MENÚ CALCULAR PRECIOS DE VUELOS\n"
			"Ingrese una opción:\n\n");
	if(km>0)
	{
		printf("1. Ingresar kilómetros: (km= %.2f)\n\n", km);
	}
	else
	{
		printf("1. Ingresar kilómetros: (km= x)\n\n");
	}
	if(precioUno>0&&precioDos>0)
	{
		printf("2. Ingresar precio de vuelos: (Aerolíneas= %.2f, Latam= %.2f)\n\n", precioUno, precioDos);
	}
	else
	{
		printf("2. Ingresar precio de vuelos: (Aerolíneas= y, Latam= z)\n\n");
	}
	printf("3. Calcular todos los costos:\n"
			"a) Tarjeta de débito (descuento 10%%)\n"
			"b) Tarjeta de crédito (interés 25%%)\n"
			"c) Bitcoin (1BTC -> %.2f)\n"
			"d) Precio por kilómetro (precio unitario)\n"
			"e) Diferencia de precios aerolineas\n\n"
			"4. Informar resultados\n\n"
			"5. Carga forzada de datos\n\n"
			"6. Salir\n", precioBitcoin);
}

int opcionMenu(int* opcion)
{
	int aux;
	int seleccion;
	int retorno = 1;

	aux=obtenerNumero(&seleccion, "", "No ingresó una opción válidad. Por favor vuelva a intentarlo.\n", 1, 6, 10);
	if(aux==0)
	{
		*opcion=seleccion;
		retorno = 0;
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
		aux=obtenerCaracter(&seleccion, "¿Desea salir? [s]-si o [n]-no:\n", "Error. Ingrese una opción válida: [s]-si o [n]-no:\n", 's', 'n', 1000);
		if(aux==0)
		{
			*salir=seleccion;
			printf("¡Hasta la próxima!\n");
		}
	}
}

void procesarPrecios(float precio, float km, float bitcoin, float* precioDebito, float* precioCredito,
		            float* precioBitcoin, float* precioUnitario)
{
	float auxDebito;
	float auxCredito;
	float auxBitcoin;
	float auxUnitario;

	restarPorcentaje(precio, 10, &auxDebito);
	sumarPorcentaje(precio, 25, &auxCredito);
	dividir(precio, bitcoin, &auxBitcoin);
	dividir(precio, km, &auxUnitario);

	*precioDebito=auxDebito;
	*precioCredito=auxCredito;
	*precioBitcoin=auxBitcoin;
	*precioUnitario=auxUnitario;

}

void informarResultados(float precio, float precioDos, float precioDebito, float precioCredito,
		               float precioBitcoin, float precioUnitario, float precioDebitoDos,
					   float precioCreditoDos, float precioBitcoinDos, float precioUnitarioDos, float precioDiferencia)
{
	printf("Latam:\n"
			"a) Precio con tarjeta de débito: $ %.2f\n"
			"b) Precio con tarjeta de crédito: $ %.2f\n"
			"c) Precio pagado con Bitcoin: %.2f BTC\n"
			"d) Precio unitario: $ %.2f\n"
			"Aerolíneas:\n"
			"a) Precio con tarjeta de débito: $ %.2f\n"
			"b) Precio con tarjeta de crédito: $ %.2f\n"
			"c) Precio pagado con Bitcoin: %.2f BTC\n"
			"d) Precio unitario: $ %.2f\n"
			"Diferencia de precio: $ %.2f\n\n", precioDebito, precioCredito, precioBitcoin, precioUnitario,
			precioDebitoDos, precioCreditoDos, precioBitcoinDos, precioUnitarioDos, precioDiferencia);
}

void cargaCalculoForzado(float km, float precioLatam, float precioAero, float precioBitcoin)
{
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioDebitoAero;
	float precioCreditoAero;
	float precioBitcoinAero;
	float precioUnitarioAero;
	float precioDiferencia;
	procesarPrecios(precioLatam, km, precioBitcoin, &precioDebitoLatam, &precioCreditoLatam,
			       &precioBitcoinLatam, &precioUnitarioLatam);
	procesarPrecios(precioAero, km, precioBitcoin, &precioDebitoAero, &precioCreditoAero,
			       &precioBitcoinAero, &precioUnitarioAero);
	restar(precioAero, precioLatam, &precioDiferencia);

	printf("KMs Ingresados: %.2f\n\n"
			"Precio Aerolineas: $%.2f\n"
			"a) Precio con tarjeta de debido: $ %.2f\n"
			"b) Precio con tarjeta de credito: $ %.2f\n"
			"c) Precio pagando con Bitcoin: %.2f BTC\n"
			"d) Mostrar precio unitario: $ %.2f\n\n"
			"Precio Latam: $%.2f\n"
			"a) Precio con tarjeta de debido: $ %.2f\n"
			"b) Precio con tarjeta de credito: $ %.2f\n"
			"c) Precio pagando con Bitcoin: %.2f BTC\n"
			"d) Mostrar precio unitario: $ %.2f\n\n"
			"La diferencia de precio es: $ %.2f\n\n", km, precioAero, precioDebitoAero, precioCreditoAero,
			precioBitcoinAero, precioUnitarioAero, precioLatam, precioDebitoLatam, precioCreditoLatam,
			precioBitcoinLatam, precioUnitarioLatam, precioDiferencia);
}
