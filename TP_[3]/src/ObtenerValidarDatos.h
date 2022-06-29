
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#ifndef OBTENERVALIDARDATOS_H_
#define OBTENERVALIDARDATOS_H_

#define CANT 51
#define CANT2 10

/// \fn int obtenerInt(int*, char*, char*, int, int, int)
/// \brief Llama a distintas funciones que obtiene una cadena de caracteres por teclado, validan que el mismo tenga las
/// caracteristicas de un dato tipo int, transforma dicha cadena en un dato numérico y lo devuelve por un puntero de tipo int.
/// \param pNumero Puntero tipo int por donde se devolverá el dato obtenido por teclado.
/// \param mensaje Puntero de un mensaje que se muestra para pedir el dato al usuario.
/// \param mensajeError Puntero de un mensaje que se muestra si el dato ingresado tiene un caracter especial.
/// \param minimo Valor minimo que es permitido que se ingrese por teclado.
/// \param maximo Valor máximo que es permitido que se ingrese por teclado.
/// \param reintentos Número de reintentos que tendrá el usuario si ingresa un dato no válido.
/// \return Retorna 0 si alguno de los punteros son nulos o si se acabaron los reintentos y 1 si terminó ok la función.
int obtenerInt(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// \fn int getInt(int*)
/// \brief Obtiene por teclado una cadena de caracteres. Valida si el mismo es un dato de tipo int,
///  quita el espacio del final de la cadena y transforma la cadena en un dato numérico.
/// \param pResultado Puntero de tipo int por donde se va a devolver el dato obtenido.
/// \return Retorna 0 si el puntero es nulo o si no es un dato tipo int y 1 si terminó ok la función.
int getInt(int* pResultado);

/// \fn int validarInt(char*)
/// \brief Valida cada uno de los caracteres de una cadena y verifica si el mismo cumple con las caracteristicas
/// de un dato tipo int.
/// \param cadena Puntero a una cadena de caracteres.
/// \return Retorna 0 si la cadena no tiene más de una posicion o si hay un caracter especial o un espacio, y 1 si terminó ok la función.
int validarInt(char* cadena);

/// \fn int obtenerCaracter(char*, char*, char*, char, char, int)
/// \brief Obtiene por teclado un caracter, valida que sea uno de los valores permitos y lo devuelve por parámetro.
/// \param pCaracter Puntero a una variable de tipo caracter.
/// \param mensaje Puntero de un mensaje que se muestra para pedir el dato al usuario.
/// \param mensajeError Puntero de un mensaje que se muestra si el dato ingresado tiene un caracter especial.
/// \param opcionUno Puntero con el valor permitido que se puede ingresar.
/// \param opcionDos Puntero con el valor permitido que se puede ingresar
/// \param reintentos Número de reintentos que tendrá el usuario si ingresa un dato no válido.
/// \return Retorna 0 si alguno de los punteros son nulos o si se acabaron los reintentos y 1 si terminó ok la función.
int obtenerCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos);

/// \fn int obtenerFloat(float*, char*, char*, float, float, int)
/// \brief Llama a distintas funciones que obtiene una cadena de caracteres por teclado, validan que el mismo tenga las
/// caracteristicas de un dato tipo float, transforma dicha cadena en un dato numérico y lo devuelve por un puntero de tipo float.
/// \param pNumero Puntero tipo float por donde se devolverá el dato obtenido por teclado.
/// \param mensaje Puntero de un mensaje que se muestra para pedir el dato al usuario.
/// \param mensajeError Puntero de un mensaje que se muestra si el dato ingresado tiene un caracter especial.
/// \param minimo Valor minimo que es permitido que se ingrese por teclado.
/// \param maximo Valor máximo que es permitido que se ingrese por teclado.
/// \param reintentos Número de reintentos que tendrá el usuario si ingresa un dato no válido.
/// \return Retorna 0 si alguno de los punteros son nulos o si se acabaron los reintentos y 1 si terminó ok la función.
int obtenerFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// \fn int getFloat(float*)
/// \brief Obtiene por teclado una cadena de caracteres. Valida si el mismo es un dato de tipo float,
///  quita el espacio del final de la cadena y transforma la cadena en un dato numérico.
/// \param pResultado Puntero de tipo float por donde se va a devolver el dato obtenido.
/// \return Retorna 0 si el puntero es nulo o si no es un dato tipo float y 1 si terminó ok la función.
int getFloat(float* pResultado);

/// \fn int quitarEspacio(char*, int)
/// \brief Quita en la última posición de una cadena de caracteres el espacio (\n) y lo reemplaza por un
/// final de cadena (\0).
/// \param cadena Puntero a una cadena de caracteres.
/// \param longitud El sizeOf de la cadena de caracteres.
/// \return Retorna 0 si el puntero es nulo o si la longitud es menor a 1, y retorna 1 si terminó ok la función.
int quitarEspacio(char* cadena, int longitud);

/// \fn int validarFloat(char*)
/// \brief Valida cada uno de los caracteres de una cadena y verifica si el mismo cumple con las caracteristicas
/// de un dato tipo float.
/// \param pNumero Puntero a una cadena de caracteres.
/// \return Retorna 0 si la cadena no tiene más de una posicion o si hay más de un caracter especial o
/// si en la primera posicion hay un caracter distinto al signo menos (-), o si hay un espacio, y 1 si terminó ok la función.
int validarFloat(char* pNumero);

/// \fn int obtenerString(char*, char*, char[], int)
/// \brief Obtiene por teclado una cadena de caracteres y valida si es alfabetico y no sea un espacio.
/// \param mensaje Puntero de un mensaje que se muestra para pedir el dato al usuario.
/// \param mensajeError Puntero de un mensaje que se muestra si el dato ingresado no es válido.
/// \param arrayString Array donde se almacenará el dato obtenido por teclado.
/// \param reintentos Número de reintentos que tendrá el usuario si ingresa un dato no válido.
/// \return Retorna 0 si alguno de los punteros son nulos o si se acabaron los reintentos y 1 si terminó ok la función.
int obtenerString(char* mensaje, char* mensajeError, char arrayString[], int reintentos);

/// \fn int validarString(char*)
/// \brief Valida si los caracteres de una cadena son alfabeticos. Permite que hayan espacios en la cadena.
/// \param pString Puntero que contiene la cadena a recorrer.
/// \return Retorna 0 si encuentra un caracter que no es alfabético o 1 si terminó ok la función.
int validarString(char *pString);

/// \fn int obtenerAlphanumeric(char*, char*, char[], int)
/// \brief Obtiene por teclado una cadena de caracteres valida que no sea nulo o un espacio. Puede contener numeros (alfanumerico).
/// \param mensaje Puntero de un mensaje que se muestra para pedir el dato al usuario.
/// \param mensajeError Puntero de un mensaje que se muestra si el dato ingresado no es válido.
/// \param arrayString Array donde se almacenará el dato obtenido por teclado.
/// \param reintentos Número de reintentos que tendrá el usuario si ingresa un dato no válido.
/// \return Retorna 0 si alguno de los punteros son nulos o si se acabaron los reintentos y 1 si terminó ok la función.
int obtenerAlphanumeric(char* mensaje, char* mensajeError, char arrayString[], int reintentos);

#endif /* OBTENERVALIDARDATOS_H_ */
