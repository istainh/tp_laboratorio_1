#include "Passenger.h"
#ifndef PARSER_H_
#define PARSER_H_
/// \fn int parser_PassengerFromText(FILE*, LinkedList*, TypePassenger*, int)
/// \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
/// \param pFile Archivo a parsear.
/// \param pArrayListPassenger LinkedLits de pasajeros.
/// \param tipoPasajero Array de tipos de pasajeros.
/// \param tamTipo Tamaño del array de tipoPasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo);

/// \fn int parser_PassengerFromBinary(FILE*, LinkedList*)
/// \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
/// \param pFile Archivo a parsear.
/// \param pArrayListPassenger LinkedLits de pasajeros.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
#endif /* PARSER_H_ */
