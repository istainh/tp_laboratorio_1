#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo, int* ultimoId)
{
	int retorno=0;
	int aux;
	char seleccion;
	int auxId=*ultimoId;
	if(path!=NULL&&pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&ultimoId!=NULL&&tamTipo>0)
	{
		if(ll_isEmpty(pArrayListPassenger)==1)
		{
			abrirArchivoTexto(path, "r", pArrayListPassenger, tipoPasajero, tamTipo);
			obtenerUltimoIdLinkedList(pArrayListPassenger, &auxId);
			*ultimoId=auxId;
			retorno=1;
		}
		else
		{
			aux=obtenerCaracter(&seleccion, "¡ATENCION: Se detectaron datos en su LinkedList!\n"
					   "Si continua con la apertura del archivo se borraran los datos actuales cargados en memoria.\n\n"
					   "Si desea continuar y borrar los archivos guardados en memoria selecione [s]-si.\n"
					   "Si desea continuar usando la LinkedList actual selecione [n]-no.", "Error. Ingrese una opción válida: [s]-si o [n]-no:\n", 's', 'n', 10);
			if(aux)
			{
				if(seleccion=='s'&&ll_clear(pArrayListPassenger)==0)
				{
					abrirArchivoTexto(path, "r", pArrayListPassenger, tipoPasajero, tamTipo);
					retorno=1;
				}
			}
			else
			{
				printf("Por un error al seleccionar [s]-si o [n]-no, no se podrá abrir el archivo. Intente más tarde.\n");
			}
		}
	}
	return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int aux;
	char seleccion;
	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)==1)
		{
			abrirArchivoBinario(path, "rb", pArrayListPassenger);
			retorno=1;
		}
		else
		{
			aux=obtenerCaracter(&seleccion, "¡ATENCION: Se detectaron datos en su LinkedList!\n"
					   "Si continua con la apertura del archivo se borraran los datos actuales cargados en memoria.\n\n"
					   "Si desea continuar y borrar los archivos guardados en memoria selecione [s]-si.\n"
					   "Si desea continuar usando la LinkedList actual elecione [n]-no.", "Error. Ingrese una opción válida: [s]-si o [n]-no:\n", 's', 'n', 10);
			if(aux)
			{
				if(seleccion=='s'&&ll_clear(pArrayListPassenger)==0)
				{
					abrirArchivoBinario(path, "rb", pArrayListPassenger);
					retorno=1;
				}
			}
			else
			{
				printf("Por un error al seleccionar [s]-si o [n]-no, no se podrá abrir el archivo. Intente más tarde.\n");
			}
		}
	}
	return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], Flight statusVuelo[], int tamTipo, int tamVuelo, int* ultimoId)
{
	int retorno=0;
	int id;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int codigoTipo;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
	int posicionTipo;
	int flagCabecera=0;
	Passenger* auxPasajero=NULL;

	if(pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&statusVuelo!=NULL&&ultimoId!=NULL&&tamTipo>0&&tamVuelo>0)
	{
		if(obtenerString("Ingrese el nombre del pasajero:\n\n", "Error al ingresar el nombre del pasajero. Vuelva a intentarlo.\n\n", nombre, 10)&&
		   obtenerString("Ingrese el apellido del pasajero:\n\n", "Error al ingresar el apellido del pasajero. Vuelva a intentarlo.\n\n", apellido, 10)&&
		   obtenerFloat(&precio, "Ingrese el precio del ticket:\n\n", "Error al ingresar el precio del ticket. Vuelva a intentarlo.\n\n", 1, 10000000, 10)&&
		   seleccionarVuelo(codigoVuelo, estadoVuelo, statusVuelo, tamVuelo)&&
		   seleccionarTipoPasajero(&codigoTipo, tipoPasajero, tamTipo))
		{
			id=*ultimoId+1;
			auxPasajero=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, codigoTipo, estadoVuelo);
			if(auxPasajero!=NULL)
			{
				ll_add(pArrayListPassenger,auxPasajero);
				if(flagCabecera==0)
				{
					printf("Id:       Nombre:       Apellido:       Precio:       Tipo de Pasejero:       Código de vuelo:       Estado del vuelo:\n");
					flagCabecera=1;
				}
				buscarPosicionTipo(codigoTipo, tipoPasajero, tamTipo, &posicionTipo);
				listarPasajero(id, nombre, apellido, precio, tipoPasajero[posicionTipo].descripcion, codigoVuelo, estadoVuelo);
				printf("¡Se cargó exitosamente el pasajero!\n\n");
				*ultimoId=id;
				retorno=1;
			}
		}
		else
		{
			printf("Se agotaron los intentos para cargar algun dato. Vuelva a intentarlo luego.\n\n");
			free(auxPasajero);
		}
	}
	else
	{
		printf("Uno de los punteros es nulo o el tamaño de las estructuras en inválida en la funcion buscarIsEmpty.\n");
	}
	return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int retorno=0;
	int opcion;
	int id;
	int posicion;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int tipo;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
	Passenger* auxPasajero=NULL;

	if(pArrayListPassenger!=NULL&&estrucTipo!=NULL&&tamTipo>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		printf("Lista de todos los pasajeros. Ingrese el ID del que desea modificar alguno de sus campos.\n\n");
		if(seleccionarPasajero(pArrayListPassenger, estrucTipo, tamTipo, &id))
		{
			if(buscarPosicionPasajero(pArrayListPassenger, id, &posicion))
			{
				auxPasajero=(Passenger*)ll_get(pArrayListPassenger, posicion);
				listarPasajeroId(pArrayListPassenger, estrucTipo, tamTipo, id);
				if(obtenerInt(&opcion, "\nIngrese una opción:\n"
									   "[1] Modificar nombre.\n"
									   "[2] Modificar apellido.\n"
									   "[3] Modificar precio.\n"
									   "[4] Modificar tipo de pasajero.\n"
									   "[5] Modificar código de vuelo.\n",
									   "Opción ingresada inválida. Vuelva a ingresar la opción.\n", 1, 5, 10))
				{
					switch (opcion)
					{
						case 1:
							if((obtenerString("Ingrese el nombre:\n", "Nombre inválido. Vuelva a intentar ingresarlo.\n", nombre, 10))&&
								Passenger_setNombre(auxPasajero, nombre))
							{
								printf("Nombre modificado con exito. Nombre: %s\n", nombre);
							}
							else
							{
								printf("Hubo un error al intentar modificar el nombre.\n");
							}
							break;
						case 2:
							if((obtenerString("Ingrese el apellido:\n", "apellido inválido. Vuelva a intentar ingresarlo.\n", apellido, 10))&&
							    Passenger_setApellido(auxPasajero, apellido))
							{
								printf("Apellido modificado con exito. Apellido: %s\n", apellido);
							}
							else
							{
								printf("Hubo un error al intentar modificar el apellido.\n");
							}
							break;
						case 3:
							if((obtenerFloat(&precio, "Ingrese el precio:\n", "Precio inválido. Vuelva a intentar ingresarlo.\n", 1, 1000000, 10))&&
								Passenger_setPrecio(auxPasajero, precio))
							{
								printf("Precio modificado con exito. Precio: %.2f\n", precio);
							}
							else
							{
								printf("Hubo un error al intentar modificar el precio.\n");
							}
							break;
						case 4:
							if((seleccionarTipoPasajero(&tipo, estrucTipo, tamTipo))&&Passenger_setTipoPasajero(auxPasajero, tipo))
							{
								printf("El tipo de pasajero fue modificado con exito.\n");
							}
							else
							{
								printf("Hubo un error al intentar modificar el tipo de pasajero.\n");
							}
							break;
						case 5:
							if((seleccionarVuelo(codigoVuelo, estadoVuelo, estrucVuelo, tamVuelo))&&Passenger_setCodigoVuelo(auxPasajero, codigoVuelo)&&
								Passenger_setEstadoVuelo(auxPasajero, estadoVuelo))
							{
								printf("El código de vuelo fue modificado con exito.\n");
							}
							else
							{
								printf("Hubo un error al intentar modificar el código de vuelo.\n");
							}
							break;
					}
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger, TypePassenger estrucTipo[], int tamTipo)
{
    int retorno=0;
	int id;
	int posicion;
	char darBaja;

	if(pArrayListPassenger!=NULL&&estrucTipo!=NULL&&tamTipo>0)
	{
		printf("Lista de todos los pasajeros. Ingrese el ID del pasajero que desea eliminar.\n\n");
		if(seleccionarPasajero(pArrayListPassenger, estrucTipo, tamTipo, &id))
		{
			if(buscarPosicionPasajero(pArrayListPassenger, id, &posicion))
			{
				listarPasajeroId(pArrayListPassenger, estrucTipo, tamTipo, id);
				if(obtenerCaracter(&darBaja, "¿Desea dar de baja al pasajero? Seleccione: [s]-si o [n]-no\n\n", "La opción ingresada no es válida. Intente de nuevo.\n\n", 's', 'n', 10))
				{
					if(darBaja=='s')
					{
						if(ll_remove(pArrayListPassenger, posicion)==0)
						{
							printf("Se dio de baja al pasajero #%d.\n", id);
							retorno=1;
						}
						else
						{
							printf("Error en la función removerPasajero.\n");
						}
					}
					else
					{
						printf("No se dio de baja al pasajero #%d \n", id);
					}
				}
			}
		}
	}
	return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo)
{
    int retorno=0;
    if(pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
    {
    	if(listarPasajeros(pArrayListPassenger, tipoPasajero, tamTipo))
    	{
    		retorno=1;
    	}
    }
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int opcion;
	int(*ordenar)(void*,void*);

	if(pArrayListPassenger!=NULL)
	{
		if(obtenerInt(&opcion, "\nIngrese una opción numérica del campo que desea ordenar:\n"
							   "[1] Ordenar Id.\n"
							   "[2] Ordenar nombre.\n"
							   "[3] Ordenar apellido.\n"
							   "[4] Ordenar precio.\n"
							   "[5] Ordenar tipo de pasajero.\n"
							   "[6] Ordenar código de vuelo.\n",
							   "Opción ingresada inválida. Vuelva a ingresar la opción.\n", 1, 6, 10))
		{
			switch(opcion)
			{
				case 1:
					ordenar=Passenger_sortId;
					break;
				case 2:
					ordenar=Passenger_sortNombre;
					break;
				case 3:
					ordenar=Passenger_sortApellido;
					break;
				case 4:
					ordenar=Passenger_sortPrecio;
					break;
				case 5:
					ordenar=Passenger_sortTipo;
					break;
				case 6:
					ordenar=Passenger_sortVuelo;
					break;
			}
			if(obtenerInt(&opcion, "Ingrese una opción numérica para seleccionar el criterio de ordenamiento. "
								   "Seleccione: [1] Ascendente o [0] Descendente.\n\n", "Opción ingresada inválida. Vuelva a ingresar la opción.\n", 0, 1, 10))
			{
				ll_sort(pArrayListPassenger, ordenar, opcion);
				printf("Se ordenó correctamente la lista.\n\n");
				retorno=1;
			}
		}
	}
	return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo)
{

	int retorno=0;
	int posicion;
	int id;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int tipo;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
	Passenger* auxPasajero=NULL;
	FILE* pFile=NULL;

	if(path!=NULL&&pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		if((pFile=fopen(path,"w"))!=NULL)
		{
			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(Passenger_getId(auxPasajero, &id)&&
				   Passenger_getNombre(auxPasajero, nombre)&&
				   Passenger_getApellido(auxPasajero, apellido)&&
				   Passenger_getPrecio(auxPasajero, &precio)&&
				   Passenger_getTipoPasajero(auxPasajero, &tipo)&&
				   Passenger_getCodigoVuelo(auxPasajero, codigoVuelo)&&
				   Passenger_getEstadoVuelo(auxPasajero, estadoVuelo))
				{
					buscarPosicionTipo(tipo, tipoPasajero, tamTipo, &posicion);
					fprintf(pFile,"%d,%s,%s,%0.f,%s,%s,%s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero[posicion].descripcion, estadoVuelo);
					retorno=1;
				}
			}
			if(retorno)
			{
				printf("Los pasajeros cargados fueron guardados en el archivo correctamente.\n");
			}
			fclose(pFile);
		}
	}
	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int auxLeido;
	FILE* pFile=NULL;
	Passenger* auxPasajero=NULL;

	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		if((pFile=fopen(path,"wb"))!=NULL)
		{
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				auxLeido=fwrite(auxPasajero, sizeof(Passenger), 1, pFile);
				if(auxLeido!=1)
				{
					Passenger_delete(auxPasajero);
					break;
				}
				else
				{
					retorno=1;
				}
			}
			if(retorno)
			{
				printf("Los pasajeros cargados fueron guardados en el archivo correctamente.\n");
			}
		}
	}
    return retorno;
}

void abrirArchivoTexto(char* path, char* modoApertura, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo)
{
	if(path!=NULL&&modoApertura!=NULL&&pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		FILE *pFile=fopen(path,modoApertura);
		if(pFile!=NULL)
		{
			if(parser_PassengerFromText(pFile, pArrayListPassenger, tipoPasajero, tamTipo))
			{
				fclose(pFile);
				printf("Se pudo leer el archivo correctamente.\n\n");
			}
			else
			{
				printf("No se pudo leer el archivo.\n\n");
			}
		}
		else
		{
			printf("El archivo no existe.\n\n");
		}
	}
}

void abrirArchivoBinario(char* path, char* modoApertura, LinkedList* pArrayListPassenger)
{
	if(path!=NULL&&modoApertura!=NULL&&pArrayListPassenger!=NULL)
	{
		FILE *pFile=fopen(path, modoApertura);
		if(pFile!=NULL)
		{
			if(parser_PassengerFromBinary(pFile,pArrayListPassenger)!=1)
			{
				printf("No se pudo leer el archivo.\n");
			}
			else
			{
				fclose(pFile);
				printf("Se pudo leer el archivo correctamente.\n\n");
			}
		}
	}
}


