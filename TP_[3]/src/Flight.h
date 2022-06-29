/*
 * Flight.h
 *
 *  Created on: 29 abr. 2022
 *      Author: Ainhoa
 */
#include "ObtenerValidarDatos.h"
#ifndef FLIGHT_H_
#define FLIGHT_H_

typedef struct
{
	char codigoVuelo[CANT];
	char estatusVuelo[CANT];
}Flight;

/// \fn void listarVuelo(Flight[], int)
/// \brief Imprime por consola el c�digo de vuelo y descripcion del estado del mismo de un elemento del array Flight segun su posicion.
/// \param estructura Array de tipo Flight.
/// \param posicion Valor de posicion del array Flight que se va a imprimir en consola.
void listarVuelo(Flight estructura[], int posicion);

/// \fn int listarVuelos(Flight[], int)
/// \brief Imprime por consola el c�digo de vuelo y descripcion del estado del mismo de todos los elementos de array Flight.
/// \param estructura Array de tipo Flight.
/// \param tamanio Longitud del array Flight.
/// \return Retorna 0 si el array es nulo o la longitud es inv�lida, y 1 si la funci�n termina ok.
int listarVuelos(Flight estructura[], int tamanio);

/// \fn int buscarVuelo(char*, Flight[], int)
/// \brief Valida que un codigo recibido por par�metro se encuentre dentro del array de tipo Flight.
/// \param codigo Valor de tipo char recibido por par�metro para validar.
/// \param estructura Array de tipo Flight.
/// \param tamanio Longitud del array Flight.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int buscarVuelo(char* codigo, char* estado, Flight estructura[], int tamanio);

/// \fn int seleccionarVuelo(char*, Flight[], int)
/// \brief Lista todos los tipos de pasajeros, obtiene por teclado el c�digo seleccionado por el usuario y valida si el mismo existe en
/// el array de TypePassenger.
/// \param codigo Valor ingresado por el usuario para seleccionar el tipo de pasajero que se regresar� por par�metro.
/// \param estructura Array de tipo TypePassenger.
/// \param tamanio Longitud del array TypePassenger.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int seleccionarVuelo(char* codigo, char* estado, Flight estructura[], int tamanio);

/// \fn int buscarPosicionVuelo(int, Flight[], int, int*)
/// \brief Valida que un c�digo recibido por par�metro se encuentre dentro del array de tipo Flight y devuelve por par�metro la posici�n.
/// \param codigo Valor de tipo int recibido por par�metro para validar.
/// \param estructura Array de tipo Flight.
/// \param tamanio Longitud del array Flight.
/// \param posicion Puntero para devolver la posici�n del c�digo en el array.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int buscarPosicionVuelo(char* codigo, Flight estructura[], int tamanio, int* posicion);

#endif /* FLIGHT_H_ */
