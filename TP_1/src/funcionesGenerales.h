/*
 * funcionesGenerales.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */
#include "calculos.h"
#include "obtenerValidarDatos.h"
#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_

/// \fn void encabezadoMenu(float, float, float, float)
/// \brief Imprime en consola el encabezado del menú.
/// \param km Valor de los km ingresados a mostrar. Si es menor a 0 se imprime x.
/// \param precioUno Valor del precio de la primera aerolinea. Si es menor a 0 se imprime y.
/// \param precioDos Valor del precio de la segunda aerolinea. Si es menor a 0 se imprime z.
/// \param precioBitcoin Valor del precio del Bitcoin.
void encabezadoMenu(float km, float precioUno, float precioDos, float precioBitcoin);

/// \fn int opcionMenu(int*)
/// \brief Usa la funcion obtenerNumero para obtener la opción del menu y valida si se obtiene el dato.
/// \param opcion Puntero donde se va a devolver el número de la opción seleccionada.
/// \return Retorna el valor de 0 si salió bien o 1 si no.
int opcionMenu(int* opcion);

/// \fn void consultarSalir(char*)
/// \brief Imprime un mensaje en consola consultando al usuario si desea salir del programa.
/// \param salir Puntero que envía un char s si deasea salir y n si no desea salir.
void consultarSalir(char* salir);

/// \fn void procesarPrecios(float, float, float, float*, float*, float*, float*)
/// \brief Recibe un precio total y procesa los distintos precios de los medios de pagos
/// de la agencia. Llama a las funciones sumarPorcentaje, restarPorcentaje y dividir para calcular.
/// Devuelve los resultados por parámetro.
/// \param precio Valor total para calcular los otros precios.
/// \param km Cantidad de kilómetros para poder obtener el precio unitario.
/// \param bitcoin Tasa del Bitcoin.
/// \param precioDebito Variable que obtendra el resultado de la función restarPorcentaje.
/// \param precioCredito Variable que obtendrá el resultado de la función sumarPorcentaje.
/// \param precioBitcoin Variable que obtendrá el resultado de la función dividir.
/// \param precioUnitario Variable que obtendrá el resultado de la función dividir.
void procesarPrecios(float precio, float km, float bitcoin, float* precioDebito, float* precioCredito,
		            float* precioBitcoin, float* precioUnitario);

/// \fn void informarResultados(float, float, float, float, float, float, float, float, float, float, float)
/// \brief Muestra por consola el resultado de cada precio calculado para ambas aerolineas.
/// \param precio Valor del precio total de una aerolineas.
/// \param precioDos Valor del precio total de una aerolineas.
/// \param precioDebito Valor del precio con tarjeta de debido para la primera aerolinea.
/// \param precioCredito Valor del precio con tarjeta de credito para la primera aerolinea.
/// \param precioBitcoin Valor del precio en Bitcoins para la primera aerolinea.
/// \param precioUnitario Valor del precio entre los kilómetros para la primera aerolinea.
/// \param precioDebitoDos Valor del precio con tarjeta de debido para la segunda aerolinea.
/// \param precioCreditoDos Valor del precio con tarjeta de credito para la segunda aerolinea.
/// \param precioBitcoinDos Valor del precio con Bitcoin para la segunda aerolinea.
/// \param precioUnitarioDos Valor del precio entre los kilómetros para la segunda aerolinea.
/// \param precioDiferencia Valor de la diferencia de precio entre las dos aerolineas.
void informarResultados(float precio, float precioDos, float precioDebito, float precioCredito,
		               float precioBitcoin, float precioUnitario, float precioDebitoDos,
					   float precioCreditoDos, float precioBitcoinDos, float precioUnitarioDos, float precioDiferencia);

/// \fn void cargaCalculoForzado(float*, float*, float*, float)
/// \brief Realiza una carga forzada de los km, precioLatam y precioAero. Llama a la función procesarPrecios
/// y muestra los resultados.
/// \param km Valor de los kilómetros.
/// \param precioLatam Valor total de Latam.
/// \param precioAero Valor total de Aero.
/// \param precioBitcoin Valor del Bitcoin.
void cargaCalculoForzado(float km, float precioLatam, float precioAero, float precioBitcoin);

#endif /* FUNCIONESGENERALES_H_ */
