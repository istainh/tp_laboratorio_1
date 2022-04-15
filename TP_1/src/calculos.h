/*
 * calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Ainhoa
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// \fn int restarPorcentaje(float, float, float*)
/// \brief Recibe dos float, calcula la cantidad a restar a partir del porcentaje,
/// resta la cantidad al numero y devuelve el resultado por parámetro.
/// \param numero Valor al que se tiene que restar el porcentaje.
/// \param porcentaje Valor del porcentaje.
/// \param resultado Obtiene el valor final con la resta del porcentaje.
/// \return Retorna 1 si hubo error y 0 si no lo hubo.
int restarPorcentaje(float numero, float porcentaje, float* resultado);

/// \fn int sumarPorcentaje(float, float, float*)
/// \brief Recibe dos float, calcula la cantidad a sumar a partir del porcentaje,
/// suma la cantidad al numero y devuelve el resultado por parámetro.
/// \param numero Valor al que se tiene que sumar el porcentaje.
/// \param porcentaje Valor del porcentaje.
/// \param resultado Obtiene el valor final con la suma del porcentaje.
/// \return Retorna 1 si hubo error y 0 si no lo hubo.
int sumarPorcentaje(float numero, float porcentaje, float* resultado);

/// \fn int dividir(float, float, float*)
/// \brief Recibe dos float, los divide y devuelve el resultado por parámetro.
/// \param numUno Numero float que actua como dividendo.
/// \param numDos Numero float que actua como divisor.
/// \param resultado Resultado de la división entre los dos float.
/// \return Retorna 1 si hubo error y 0 si no lo hubo.
int dividir(float numUno, float numDos, float* resultado);

/// \fn int restar(float, float, float*)
/// \brief Recibe dos float, los resta y devuelve el resultado por parámetro.
/// \param numUno Numero float para restar.
/// \param numDos Numero float para restar.
/// \param resultado Resultado de la resta de los dos float.
/// \return Retorna 1 si hubo error y 0 si no lo hubo.
int restar(float numUno, float numDos, float* resultado);



#endif /* CALCULOS_H_ */
