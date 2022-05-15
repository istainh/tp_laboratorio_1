/*
 * FuncionesGenerales.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */

#include "Passenger.h"
#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_

/// \fn void encabezadoMenu()
/// \brief Imprime en consola el encabezado del menú.
void encabezadoMenu();

/// \fn int opcionMenu(int*)
/// \brief Usa la funcion obtenerInt para obtener la opción del menu y valida si se encuentra entre las opciones válidas
/// y obtiene el dato de tipo int.
/// \param opcion Puntero donde se va a devolver el número de la opción seleccionada.
/// \return Retorna el valor de 0 si agotó los reintentos o 1 si terminó ok.
int opcionMenu(int* opcion);

/// \fn void consultarSalir(char*)
/// \brief Imprime un mensaje en consola consultando al usuario si desea salir del programa, llama a la funcion
/// obtenerCaracter que validará la obtención por teclado de los caracter 's' o 'n'.
/// \param salir Puntero que envía un char 's' si deasea salir y 'n' si no desea salir.
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

/// \fn void manejarErrores(char*)
/// \brief Se muestra un mensaje de que una función (nombre obtenida por parámetro) no cumplió con su proposito y se setea el
/// puntero Salir con el caracter 's' para que se cierre el programa.
/// \param funcion Es un puntero que indica el nombre de la funcion que falló.
/// \param salir Puntero por donde se devolverá el valor de 's' para terminar el programa.
void manejarErrores(char* funcion, char* salir);


#endif /* FUNCIONESGENERALES_H_ */
