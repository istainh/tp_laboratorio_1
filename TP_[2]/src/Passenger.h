/*
 * Passenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */

#include "Flight.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define ELEMENTS 2000

typedef struct
{
	int codigoTipo;
	char descripcion[CANT];
}TypePassenger;

typedef struct
{
	int id;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int codigoTipo;
	char codigoVuelo[CANT2];
	int isEmpty;
}Passenger;

/// \fn int initPassenger(Passenger*, int)
/// \brief Indica que todas las posiciones de las variables se encuentran vacias.
/// Esta funcion asigna el valor 1 (verdadero) la variable isEmpty en todas las posiciones del Passenger.
/// \param estructura Passenger* puntero del array de passengers
/// \param tamanio Tamaño del array de passenger.
/// \return Retorna un 0 si el puntero es nulo o el TAMANIO es inválido y 1 si es ok.
int initPassenger(Passenger* estructura, int tamanio);

/// \fn int buscarIsEmpty(Passenger[], int, int*)
/// \brief Itera el array de Passenger buscando el primer campo isEmpty que sea igual a 1 (verdadero para "es vacio").
/// \param estructura Array de tipo Passenger que se va a recorrer.
/// \param tamanio Tamanio del array Passenger.
/// \param posicion Valor de la posicion del array donde isEmpty es igual a 1.
/// \return Retorna 0 si el array o el puntero es nulo y 1 si la funcion terminó ok.
int buscarIsEmpty(Passenger estructura[], int tamanio, int* posicion);

/// \fn int cargarPassenger(Passenger[], int, Flight[], int, TypePassenger, int, int*)
/// \brief Recibe un array de tipo Passanger y llama a distintas funciones para pedir los campos necesarios para cargar el primer elemento vacío
/// que tenga dicho array. Tambien calcula el id para el elemento autoincrementado de 1 en 1.
/// \param estrucPassenger Array de tipo Passenger que se va a recorrer.
/// \param tamPassenger Tamanio del array Passenger.
/// \param estrucFlight Array de tipo Flight que se va a recorrer.
/// \param tamFlight Tamanio del array Flight.
/// \param estrucTipo Array de tipo Passenger que se va a recorrer.
/// \param tamTipo Tamanio del array TypePassenger.
/// \param ultimoId Puntero con el valor del último id asignado.
/// \return Retorna 0 si alguno de los arrays son nulos, uno de los tamanios son menores a 0, no hay elementos vacíos en  el array Passenger
/// o alguna de las funciones para obtener datos no finalizó correctamente, y 1 si termina bien la función.
int cargarPassenger(Passenger estrucPassenger[], int tamPassenger, Flight estrucFlight[], int tamFlight, TypePassenger estrucTipo[], int tamTipo, int* ultimoId);

/// \fn void listarTipo(TypePassenger[], int)
/// \brief Imprime por consola el código y la descripción del tipo de pasajero de un elemento del array TypePassenger segun su posicion.
/// \param estructura Array de tipo TypePassenger.
/// \param posicion Valor de posicion del array TypePassenger que se va a imprimir en consola.
void listarTipo(TypePassenger estructura[], int posicion);

/// \fn int listarTipos(TypePassenger[], int)
/// \brief Imprime por consola el código y la descripción del tipo de pasajero de todos los elementos del array TypePassenger.
/// \param estructura Array de tipo TypePassenger.
/// \param tamanio Longitud del array TypePassenger.
/// \return Retorna 0 si el array es nulo o la longitud es inválida, y 1 si la función termina ok.
int listarTipos(TypePassenger estructura[], int tamanio);

/// \fn int buscarTipo(int, TypePassenger[], int)
/// \brief Valida que un código recibido por parámetro se encuentre dentro del array de tipo TypePassenger.
/// \param codigo Valor de tipo int recibido por parámetro para validar.
/// \param estructura Array de tipo TypePassenger.
/// \param tamanio Longitud del array TypePassenger.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int buscarTipo(int codigo, TypePassenger estructura[], int tamanio);

/// \fn int buscarPosicionTipo(int, TypePassenger[], int, int*)
/// \brief Valida que un código recibido por parámetro se encuentre dentro del array de tipo TypePassenger y devuelve por parámetro la posición.
/// \param codigo Valor de tipo int recibido por parámetro para validar.
/// \param estructura Array de tipo TypePassenger.
/// \param tamanio Longitud del array TypePassenger.
/// \param posicion Puntero para devolver la posición del código en el array.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int buscarPosicionTipo(int codigo, TypePassenger estructura[], int tamanio, int* posicion);

/// \fn int seleccionarTipo(int*, TypePassenger[], int)
/// \brief Lista todos los tipos de pasajeros, obtiene por teclado el código seleccionado por el usuario y valida si el mismo existe en
/// el array de TypePassenger.
/// \param codigo Valor ingresado por el usuario para seleccionar el tipo de pasajero que se regresará por parámetro.
/// \param estructura Array de tipo TypePassenger.
/// \param tamanio Longitud del array TypePassenger.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int seleccionarTipo(int* codigo, TypePassenger estructura[], int tamanio);

/// \fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
/// \brief Agrega a un array de tipo Passenger los valores recibidos por parámetros según la posición recibida tambien por parámetro.
/// \param estructura Array de tipo Passenger.
/// \param posicion Primera posicion vacia del array de tipo Passenger.
/// \param id Valor de tipo int que se le asignará como id al elemento del array Passenger.
/// \param nombre Valor de tipo char que se le asignará como nombre al elemento del array Passenger.
/// \param apellido Valor de tipo char que se le asignará como apellido al elemento del array Passenger.
/// \param precio Valor de tipo float que se le asignará como precio al elemento del array Passenger.
/// \param codigoTipo Valor de tipo int que se le asignará como código de tipo de pasajero al elemento del array Passenger.
/// \param codigoVuelo Valor de tipo char que se le asignará como código de vuelo al elemento del array Passenger.
/// \return Retorna un 0 si el puntero es nulo, y 1 si la funcion termina ok.
int addPassenger(Passenger* estructura, int posicion, int id, char nombre[], char apellido[], float precio, int codigoTipo, char codigoVuelo[]);

/// \fn int buscarPasajero(Passenger[], int, int)
/// \brief Recibe un array de tipo Passenger y una variable de tipo int con el valor del id a buscar en el array.
/// Recorre el array y si lo encuentra rompe la iteración y retorna un 1.
/// \param estructura Array de tipo Passenger.
/// \param tamanio Longitud del array de tipo Passenger.
/// \param id Valor a buscar en el array Passenger.
/// \return Retorna un 0 si el array es nulo o si no encuentra el valor id en el array, y 1 si la función termina ok.
int buscarPasajero(Passenger estructura[], int tamanio, int id);

/// \fn void listarPasajero(Passenger[], int)
/// \brief Imprime por consola los valores de los campos de un elemento del array Passenger según su posicion.
/// \param estructura Array de tipo Passenger.
/// \param posicion Valor de posicion del array Passenger que se va a imprimir en consola.
void listarPasajero(Passenger estructura[], int posicion);

/// \fn int listarPasajeros(Passenger[], int)
/// \brief Imprime por consola el valor de todos los campos de todos los elementos de array Passenger que nos estén vacíos.
/// \param estructura Array de tipo Passenger.
/// \param tamanio Longitud del array Passenger.
/// \return Retorna 0 si el array es nulo o la longitud es inválida, y 1 si la función termina ok.
int listarPasajeros(Passenger estructura[], int tamanio);

/// \fn int seleccionarPasajero(Passenger[], int, int*)
/// \brief Lista todos los pasajeros, obtiene por teclado el id seleccionado por el usuario y valida si el mismo existe en
/// el array de Passenger.
/// \param estructura Array de tipo Passenger.
/// \param tamanio Longitud del array Passenger.
/// \param id Valor ingresado por el usuario para seleccionar el tipo de pasajero que se regresará por parámetro.
/// \return Retorna 0 si el array es nulo, y 1 si la funcion termina ok.
int seleccionarPasajero(Passenger estructura[], int tamanio, int* id);

/// \fn int removerPasajero(Passenger[], int, int)
/// \brief Remueve un pasajero del array Passenger mediante el número de id. Pone el campo isEmpty en 1 (true).
/// \param estructura Array de tipo Passenger.
/// \param tamanio Longitud del array Passenger.
/// \param id Valor a buscar en el array Passenger para poder dar de baja al elemento.
/// \return Retorna 0 si el array es nulo o el tamanio es menor a 0, o 1 si la funcion termina ok.
int removerPasajero(Passenger estructura[], int tamanio, int id);

/// \fn int eliminarPasajero(Passenger[], int)
/// \brief Da de baja un elemento del array Passenger. Solicita al usuario un id, verifica que el mismo existe y realiza una baja
/// lógica al poner isEmpty en 1;
/// \param estructura Array de tipo Passenger.
/// \param tamanio Longitud de tipo Passenger.
/// \return Retorna 0 si el array es nulo, el tamaño es inválido,
int eliminarPasajero(Passenger estructura[], int tamanio);

/// \fn int menuModificadorPassenger(Passenger[], int, TypePassenger[], int, Flight[], int)
/// \brief Muestra un submenu en consola que permite al usuario seleccionar por medio de id a un pasajero y
/// modificar algún campo del mismo si existe.
/// \param estrucPasajero Array de tipo Passenger.
/// \param tamPasajero Longitud del array de tipo.
/// \param estrucTipo Array de tipo TypePassenger.
/// \param tamTipo Longitud del array TypePassenger.
/// \param estrucVuelo Array de tipo Flight.
/// \param tamVuelo Longitud del array Flight.
/// \return Retorna 0 si el puntero los arrays es nulo, el tamaño de los arrays son inválidos o si no se consigue el codigo ingresado por el usuario,
/// y 1 si la funcion termina ok.
int menuModificadorPassenger(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);

/// \fn void ordenarPasajerosAscendente(Passenger[], int, TypePassenger[], int)
/// \brief Ordena alfabeticamente de manera ascendente el apellido de un array de pasajeros y si dos pasajeros poseen el mismo apellido
/// ordena alfabeticamente de manera ascendente el tipo de pasajero.
/// \param estrucPasajero Array de tipo Passenger.
/// \param tamPasajero Longitud del array Passenger.
/// \param estrucTipo Array de tipo TypePassenger.
/// \param tamTipo Longitud del array TypePassenger.
void ordenarPasajerosAscendente(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo);

/// \fn void ordenarPasajerosDescendete(Passenger[], int, TypePassenger[], int)
/// \brief Ordena alfabeticamente de manera descendete el apellido de un array de pasajeros y si dos pasajeros poseen el mismo apellido
/// ordena alfabeticamente de manera descendete el tipo de pasajero.
/// \param estrucPasajero Array de tipo Passenger.
/// \param tamPasajero Longitud del array Passenger.
/// \param estrucTipo Array de tipo TypePassenger.
/// \param tamTipo Longitud del array TypePassenger.
void ordenarPasajerosDescendete(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo);

/// \fn void ordenarPasajeros(Passenger[], int, TypePassenger[], int, int)
/// \brief Llama a funciones que orden alfabeticamente de manera ascendente o descendente el apellido o el tipo de pasajero de un
/// elemmento del array Passenger según la opción recibida por parámetro, si es 1 llama a la funcion que ordena ascendentemente,
/// y si 0 llama a la funcion que ordena descendentemente.
/// \param estrucPasajero Array de tipo Passenger.
/// \param tamPasajero Longitud del array Passenger.
/// \param estrucTipo Array de tipo TypePassenger.
/// \param tamTipo Longitud del array TypePassenger.
/// \param orden Opción recibida por parámetro para ordenar.
void ordenarPasajeros(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, int orden);

int listarPasajerosCompletos(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);

void listarPasajeroCompleto(Passenger estructura[], int posicion, char* tipoPasajero, char* estatusVuelo);

void listarPasajerosOrdenados(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);
int calcularTotalPromedio(Passenger estructura[], int tamanio, float* importeTotal, float* promedio);
void listarPreciosPasajes(Passenger estructura[], int tamanio);
void ordenarVueloAscendente(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo);
void ordenarVueloDescendente(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo);
void ordenarPasajerosPorCodigo(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo, int orden);
void listarPasajerosVuelo(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);
int menuListar(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);

int cargaForzadaPasajeros(Passenger estructura[], int tamanio, int* ultimoId, int* contaAltaBajas);
int buscarPosicionPasajero(int id, Passenger estructura[], int tamanio, int* posicion);








#endif /* PASSENGER_H_ */
