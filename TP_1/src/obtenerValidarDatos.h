/*
 * obtenerValidarDatos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef OBTENERVALIDARDATOS_H_
#define OBTENERVALIDARDATOS_H_

/// \fn int obtenerCaracter(char*, char*, char*, char, char, int)
/// \brief Obtiene por teclado un caracter y valida si es alguna de las opciones esperadas.
/// \param pCaracter Variable por donde se devuelve el caracter ingresado.
/// \param mensaje Se imprime este mensaje solicitando el ingreso de caracter al usuario.
/// \param mensajeError Se imprime este mensaje si el valor ingresado por teclado no es el esperado.
/// \param opcionUno Caracter esperado.
/// \param opcionDos Caracter esperado.
/// \param reintentos Número de reintentos si no se ingresa el caracter esperado.
/// \return Retorna 1 si algo salió mal y 0 si pudo obtener el caracter.
int obtenerCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos);

/// \fn int obtenerNumero(int*, char*, char*, int, int, int)
/// \brief Pide un número entero al usuario y lo valida.
/// \param pNumero es un puntero que modifica la dirección de memoria de una variable que se encuentra en otro scope.
/// \param mensaje es un puntero con el mensaje que se desea imprimir al usuario.
/// \param mensajeError imprime un mensaje al usuario notificando un error en el datto ingresado después de validarlo.
/// \param minimo es el numero menor permitido ingresar por el usuario.
/// \param maximo es el numero mayor permitido ingresar por el usuario.
/// \param reintentos es la cantidad de veces permitidas que el usuario podra ingresar un numero si anteriormente el numero ingresado es invalido.
/// \return Retorna 1 si hubo un error y 0 si salio ok.
int obtenerNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// \fn int obtenerFloat(float*, char*, char*, float, float, int)
/// \brief Pide un número float al usuario y lo valida.
/// \param pNumero es un puntero que modifica la dirección de memoria de una variable que se encuentra en otro scope.
/// \param mensaje es un puntero con el mensaje que se desea imprimir al usuario.
/// \param mensajeError imprime un mensaje al usuario notificando un error en el datto ingresado después de validarlo.
/// \param minimo es el numero menor permitido ingresar por el usuario.
/// \param maximo es el numero mayor permitido ingresar por el usuario.
/// \param reintentos es la cantidad de veces permitidas que el usuario podra ingresar un numero si anteriormente el numero ingresado es invalido.
/// \return Retorna 1 si hubo un error y 0 si salio ok.
int obtenerFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* OBTENERVALIDARDATOS_H_ */
