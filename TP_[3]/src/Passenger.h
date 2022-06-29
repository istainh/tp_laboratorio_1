/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Flight.h"
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
	int tipoPasajero;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
}Passenger;

/// \fn Passenger Passenger_new*()
/// \brief Crea en memoria dinámica un pasajero.
/// \return Retorna el pasajero creado en memoria dinámica.
Passenger* Passenger_new();

/// \fn Passenger Passenger_newParametrosArchivo*(char*, char*, char*, char*, char*, char*, char*, TypePassenger*, int)
/// \brief Setea los valores recibidos por parámetros a un pasajero. También recibe el array de TypePassenger para buscar por la descripcion
/// leida del archivo el id del tipo de pasajero y asignar el id en vez de la descripcion del tipo.
/// \param id Entero que se seteara como id en el pasajero.
/// \param nombre String que se seteara como nombre en el pasajero.
/// \param apellido String que se seteara como apellido en el pasajero.
/// \param precio Float que se seteara como precio en el pasajero.
/// \param codigoVuelo String que se seteara como código de vuelo en el pasajero.
/// \param tipoPasajero Entero que se seteara como tipo de pasajero.
/// \param estadoVuelo String que se seteara como estado del vuelo.
/// \param estrucTipo Array de tipo de pasajero.
/// \param tamTipo Tamaño del array de estrucTipo.
/// \return Retorna el pasajero con sus campos cargados.
Passenger* Passenger_newParametrosArchivo(char* id, char* nombre, char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo, TypePassenger* estrucTipo, int tamTipo);

/// \fn Passenger Passenger_newParametros*(int, char*, char*, float, char*, int, char*)
/// \brief Setea los valores recibidos por parámetros a un pasajero.
/// \param id Entero que se seteara como id en el pasajero.
/// \param nombre String que se seteara como nombre en el pasajero.
/// \param apellido String que se seteara como apellido en el pasajero.
/// \param precio Float que se seteara como precio en el pasajero.
/// \param codigoVuelo String que se seteara como código de vuelo en el pasajero.
/// \param tipoPasajero Entero que se seteara como tipo de pasajero.
/// \param estadoVuelo String que se seteara como estado del vuelo.
/// \return Retorna el pasajero con sus campos cargados.
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, char* estadoVuelo);

/// \fn void Passenger_delete(Passenger*)
/// \brief Elimina de manera física (memoria) un psajero.
/// \param this Pasajero a eliminar.
void Passenger_delete();

/// \fn int Passenger_setId(Passenger*, int)
/// \brief Setea el id en el pasajero.
/// \param this Pasajero a setear dato.
/// \param id Entero que se seteara como id en el pasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int Passenger_setId(Passenger* this, int id);

/// \fn int Passenger_getId(Passenger*, int*)
/// \brief Obtiene el valor del campo id del pasajero.
/// \param this Pasajero a obtener valor.
/// \param id Entero que se devolverá como parámetro.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int Passenger_getId(Passenger* this, int* id);

/// \fn int Passenger_setNombre(Passenger*, char*)
/// \brief Setea el nombre en el pasajero.
/// \param this Pasajero a setear dato.
/// \param nombre String que se seteara como nombre en el pasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int Passenger_setNombre(Passenger* this, char* nombre);

/// \fn int Passenger_getNombre(Passenger*, char*)
/// \brief Obtiene el valor del campo nombre del pasajero.
/// \param this Pasajero a obtener valor.
/// \param nombre String que se devolverá como parámetro.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int Passenger_getNombre(Passenger* this, char* nombre);

/// \fn int Passenger_setApellido(Passenger*, char*)
/// \brief
/// \param this
/// \param apellido
/// \return
int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

int seleccionarTipoPasajeroArchivo(char* tipoPasajero, int* idTipoPasajero, TypePassenger* estrucTipo, int tamTipo);
int buscarTipo(int codigo, TypePassenger* tipoPasajero, int tamTipo);
int buscarPosicionTipo(int codigo, TypePassenger* tipoPasajero, int tamTipo, int* posicion);
void listarTipo(TypePassenger* tipoPasajero, int posicion);
int listarTipos(TypePassenger* tipoPasajero, int tamTipo);
int seleccionarTipoPasajero(int* codigo, TypePassenger* tipoPasajero, int tamTipo);

int seleccionarPasajero(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo, int* id);
int buscarPasajero(LinkedList* pArrayListPassenger, int id);
int buscarPosicionPasajero(LinkedList* pArrayListPassenger, int id, int* posicion);
void listarPasajero(int id, char* nombre, char* apellido, float precio, char* descripTipo, char* codigoVuelo, char* estadoVuelo);
int listarPasajeros(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo);
int listarPasajeroId(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo, int id);
int Passenger_sortId(void* thisOne, void* thisTwo);
int Passenger_sortNombre(void* thisOne, void* thisTwo);
int Passenger_sortApellido(void* thisOne, void* thisTwo);
int Passenger_sortPrecio(void* thisOne, void* thisTwo);
int Passenger_sortTipo(void* thisOne, void* thisTwo);
int Passenger_sortVuelo(void* thisOne, void* thisTwo);
void obtenerUltimoIdLinkedList(LinkedList* pArrayListPassenger, int* id);


#endif /* PASSENGER_H_ */
