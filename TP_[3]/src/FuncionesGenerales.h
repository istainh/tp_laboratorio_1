/*
 * FuncionesGenerales.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */
#include "Controller.h"
#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_

/// \fn void encabezadoMenu()
/// \brief Imprime en consola el encabezado del men�.
void encabezadoMenu();

/// \fn int opcionMenu(int*)
/// \brief Usa la funcion obtenerInt para obtener la opci�n del menu y valida si se encuentra entre las opciones v�lidas
/// y obtiene el dato de tipo int.
/// \param opcion Puntero donde se va a devolver el n�mero de la opci�n seleccionada.
/// \return Retorna el valor de 0 si agot� los reintentos o 1 si termin� ok.
int opcionMenu(int* opcion);

/// \fn void consultarSalir(char*)
/// \brief Imprime un mensaje en consola consultando al usuario si desea salir del programa, llama a la funcion
/// obtenerCaracter que validar� la obtenci�n por teclado de los caracter 's' o 'n'.
/// \param salir Puntero que env�a un char 's' si deasea salir y 'n' si no desea salir.
void consultarSalir(char* salir);

#endif /* FUNCIONESGENERALES_H_ */
