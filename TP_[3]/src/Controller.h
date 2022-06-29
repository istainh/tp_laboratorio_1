#include "parser.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/// \fn int controller_loadFromText(char*, LinkedList*, TypePassenger*, int, int*)
/// \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
/// \param path Archivo a cargar.
/// \param pArrayListPassenger LinkedList de pasajeros para añadir pasajeros del archivo.
/// \param tipoPasajero Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \param ultimoId Puntero donde se enviará por parámetro el valor del último id del archivo.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo, int* ultimoId);

/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
/// \param path Archivo a cargar.
/// \param pArrayListPassenger LinkedList de pasajeros para añadir pasajeros a la LinkedList desde el archivo.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// \fn int controller_addPassenger(LinkedList*, TypePassenger[], Flight[], int, int, int*)
/// \brief Realiza el alta de psajeros. Pide los datos, los valida y por último añade al pasajero en la LinkedList.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param tipoPasajero Array de tipo de pasajeros.
/// \param statusVuelo Array de vuelos.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \param tamVuelo Entero con el tamaño del array statusVuelo.
/// \param ultimoId Puntero donde se enviará por parámetro el valor del último id cargado en la linkedlist.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_addPassenger(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], Flight statusVuelo[], int tamTipo, int tamVuelo, int* ultimoId);

/// \fn int controller_editPassenger(LinkedList*, TypePassenger[], int, Flight[], int)
/// \brief Muestra en pantalla un submenu para seleccionar el campo de un pasajero se quiere modificar, pide el nuevo dato, lo valida y lo setea en el pasajero.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param estrucTipo Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \param estrucVuelo Array de vuelos.
/// \param tamVuelo Entero con el tamaño del array estrucVuelo.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_editPassenger(LinkedList* pArrayListPassenger, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo);

/// \fn int controller_removePassenger(LinkedList*, TypePassenger[], int)
/// \brief Muestra la lista completa de pasajeros, pide el ingreso por teclado del id del pasajero que se desea eliminar, verifica que exista y lo elimina de la linkedlist.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param estrucTipo Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_removePassenger(LinkedList* pArrayListPassenger, TypePassenger estrucTipo[], int tamTipo);

/// \fn int controller_ListPassenger(LinkedList*, TypePassenger[], int)
/// \brief Lista todos los pasajeros de la linkedlist.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param tipoPasajero Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_ListPassenger(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo);

/// \fn int controller_sortPassenger(LinkedList*)
/// \brief Muestra en pantalla un submenu para seleccionar cual campo de los pasajeros cargados en la linkedlist desea ordenar y pregunta si desea que sea de manera
/// ascendente (inegresar 1) o descendente (ingresar 0)
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// \fn int controller_saveAsText(char*, LinkedList*, TypePassenger[], int)
/// \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
/// \param path Archivo a guardar.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param tipoPasajero Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo);

/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
/// \param path Archivo a guardar.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \return Retorna 0 si algo salió mal o 1 si terminó ok.
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// \fn void abrirArchivoTexto(char*, char*, LinkedList*, TypePassenger*, int)
/// \brief Realiza el fopen del archivo en modo texto.
/// \param path Archivo a abrir.
/// \param modoApertura String con el modo de apertura que recibirá como parámetro la función fopen.
/// \param pArrayListPassenger LinkedList de pasajeros.
/// \param tipoPasajero Array de tipo de pasajeros.
/// \param tamTipo Entero con el tamaño del array tipoPasajero.
void abrirArchivoTexto(char* path, char* modoApertura, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo);

/// \fn void abrirArchivoBinario(char*, char*, LinkedList*)
/// \brief Realiza el fopen del archivo en modo binario.
/// \param path Archivo a abrir.
/// \param modoApertura String con el modo de apertura que recibirá como parámetro la función fopen.
/// \param pArrayListPassengerLinkedList de pasajeros.
void abrirArchivoBinario(char* path, char* modoApertura, LinkedList* pArrayListPassenger);
#endif /* CONTROLLER_H_ */
