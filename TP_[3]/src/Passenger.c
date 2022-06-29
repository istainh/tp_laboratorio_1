#include "Passenger.h"

void Passenger_delete(Passenger* this)
{
	free(this);
}

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametrosArchivo(char* id, char* nombre, char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo, TypePassenger* estrucTipo, int tamTipo)
{
	int auxTipoPasajero;
	Passenger* pAuxPasajero=Passenger_new();
	if(pAuxPasajero!=NULL&&id!=NULL&&nombre!=NULL&&apellido!=NULL&&precio!=NULL&&tipoPasajero!=NULL&&codigoVuelo!=NULL&&estrucTipo!=NULL&&estadoVuelo!=NULL&&tamTipo>0)
	{
		seleccionarTipoPasajeroArchivo(tipoPasajero, &auxTipoPasajero, estrucTipo, tamTipo);
		if((Passenger_setId(pAuxPasajero,atoi(id))==0)||
		  (Passenger_setNombre(pAuxPasajero,nombre)==0)||
		  (Passenger_setApellido(pAuxPasajero,apellido)==0)||
		  (Passenger_setPrecio(pAuxPasajero,atof(precio))==0)||
		  (Passenger_setTipoPasajero(pAuxPasajero, auxTipoPasajero)==0)||
		  (Passenger_setCodigoVuelo(pAuxPasajero, codigoVuelo)==0)||
		  (Passenger_setEstadoVuelo(pAuxPasajero, estadoVuelo))==0)
		{
			free(pAuxPasajero);
			pAuxPasajero=NULL;
		}
	}
	return pAuxPasajero;
}

Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, char* estadoVuelo)
{
	Passenger* pAuxPasajero=Passenger_new();
	if(pAuxPasajero!=NULL&&nombre!=NULL&&apellido!=NULL&&codigoVuelo!=NULL&&estadoVuelo!=NULL)
	{
		if((Passenger_setId(pAuxPasajero,id)==0)||
		  (Passenger_setNombre(pAuxPasajero,nombre)==0)||
		  (Passenger_setApellido(pAuxPasajero,apellido)==0)||
		  (Passenger_setPrecio(pAuxPasajero,precio)==0)||
		  (Passenger_setTipoPasajero(pAuxPasajero, tipoPasajero)==0)||
		  (Passenger_setCodigoVuelo(pAuxPasajero, codigoVuelo)==0)||
		  (Passenger_setEstadoVuelo(pAuxPasajero, estadoVuelo))==0)
		{
			free(pAuxPasajero);
			pAuxPasajero=NULL;
		}
	}
	return pAuxPasajero;
}

int Passenger_setId(Passenger* this, int id)
{
	int retorno=0;
	if(this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int Passenger_getId(Passenger* this, int* id)
{
	int retorno=0;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int retorno=0;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=1;
 	}
	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int retorno=0;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int retorno=0;
	if(this!=NULL&&apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		retorno=1;
 	}
	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno=0;
	if(this!=NULL&&apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		retorno=1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno=0;
	if(this!=NULL&&codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno=1;
 	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno=0;
	if(this!=NULL&&codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno=0;
	if(this!=NULL&&estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno=1;
 	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno=0;
	if(this!=NULL&&estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno=1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno=0;
	if(this!=NULL)
	{
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno=0;
	if(this!=NULL&&precio!=NULL)
	{
		*precio=this->precio;
		retorno=1;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno=0;
	if(this!=NULL&&tipoPasajero>0)
	{
		this->tipoPasajero=tipoPasajero;
		retorno=1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int retorno=0;
	if(this!=NULL&&tipoPasajero>0)
	{
		*tipoPasajero=this->tipoPasajero;
		retorno=1;
	}
	return retorno;
}

int seleccionarTipoPasajeroArchivo(char* tipoPasajero, int* idTipoPasajero, TypePassenger* estrucTipo, int tamTipo)
{
	int retorno=0;
	if(tipoPasajero!=NULL&&idTipoPasajero!=NULL&&estrucTipo!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamTipo; i++)
		{
			if((stricmp(estrucTipo[i].descripcion, tipoPasajero))==0)
			{
				*idTipoPasajero=estrucTipo[i].codigoTipo;
				retorno=1;
			}

		}
	}
	return retorno;
}

int buscarTipo(int codigo, TypePassenger* tipoPasajero, int tamTipo)
{
	int retorno=0;
	if(tipoPasajero!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamTipo; i++)
		{
			if(tipoPasajero[i].codigoTipo==codigo)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int buscarPosicionTipo(int codigo, TypePassenger* tipoPasajero, int tamTipo, int* posicion)
{
	int retorno=0;
	if(tipoPasajero!=NULL&&posicion!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamTipo; i++)
		{
			if(tipoPasajero[i].codigoTipo==codigo)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

void listarTipo(TypePassenger* tipoPasajero, int posicion)
{
	if(tipoPasajero!=NULL)
	{
		printf("%d\t\t%s\n", tipoPasajero[posicion].codigoTipo, tipoPasajero[posicion].descripcion);

	}
}

int listarTipos(TypePassenger* tipoPasajero, int tamTipo)
{
	int retorno=0;
	int flagCabecera=0;
	if(tipoPasajero!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamTipo; i++)
		{
			if(flagCabecera==0)
			{
				printf("Id:\tTipo de pasajero:\n");
				flagCabecera=1;
			}
			listarTipo(tipoPasajero, i);
		}
		retorno=1;
	}
	return retorno;
}

int seleccionarTipoPasajero(int* codigo, TypePassenger* tipoPasajero, int tamTipo)
{
	int retorno=0;
	int aux;
	if(codigo!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		if(listarTipos(tipoPasajero, tamTipo))
		{
			if(obtenerInt(&aux, "Ingrese el ID del tipo de pasajero:\n\n", "Error al seleccionar el código del tipo de pasajero. Intentelo de nuevo.\n\n", 1, tamTipo, 10))
			{
				if(buscarTipo(aux, tipoPasajero, tamTipo))
				{
					*codigo=aux;
					retorno=1;
				}
				else
				{
					printf("El ID ingresado no existe. Vuelva a intentarlo luego.\n");
				}
			}
		}
	}
	return retorno;
}

int listarPasajeros(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo)
{
	int retorno=0;
	int flagCabecera=0;
	int id;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int tipo;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
	int posicionTipo;
	Passenger* auxPasajero=NULL;
	if(pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		if(ll_isEmpty(pArrayListPassenger)==0)
		{
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if(Passenger_getId(auxPasajero, &id)&&Passenger_getNombre(auxPasajero, nombre)&&Passenger_getApellido(auxPasajero, apellido)&&
				   Passenger_getPrecio(auxPasajero, &precio)&&Passenger_getTipoPasajero(auxPasajero, &tipo)&&
				   Passenger_getCodigoVuelo(auxPasajero, codigoVuelo)&&Passenger_getEstadoVuelo(auxPasajero, estadoVuelo))
				{
					if(flagCabecera==0)
					{
						printf("Id:       Nombre:       Apellido:       Precio:       Tipo de Pasajero:       Código de vuelo:       Estado del vuelo:\n");
						flagCabecera=1;
					}
					buscarPosicionTipo(tipo, tipoPasajero, tamTipo, &posicionTipo);
					listarPasajero(id, nombre, apellido, precio, tipoPasajero[posicionTipo].descripcion, codigoVuelo, estadoVuelo);
					retorno=1;
				}
			}
		}
		else
		{
			printf("No hay pasajeros para listar.\n");
		}
	}
	return retorno;
}

int listarPasajeroId(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo, int id)
{
	int retorno=0;
	int flagCabecera=0;
	int auxId;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int tipo;
	char codigoVuelo[CANT];
	char estadoVuelo[CANT];
	int posicionTipo;
	Passenger* auxPasajero=NULL;
	if(pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		if(ll_isEmpty(pArrayListPassenger)==0)
		{
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				if((Passenger_getId(auxPasajero, &auxId))&&auxId==id)
				{
					if(Passenger_getId(auxPasajero, &auxId)&&Passenger_getNombre(auxPasajero, nombre)&&Passenger_getApellido(auxPasajero, apellido)&&
					   Passenger_getPrecio(auxPasajero, &precio)&&Passenger_getTipoPasajero(auxPasajero, &tipo)&&
					   Passenger_getCodigoVuelo(auxPasajero, codigoVuelo)&&Passenger_getEstadoVuelo(auxPasajero, estadoVuelo))
					{
						if(flagCabecera==0)
						{
							printf("Id:       Nombre:       Apellido:       Precio:       Tipo de Pasejero:       Código de vuelo:       Estado del vuelo:\n");
							flagCabecera=1;
						}
						buscarPosicionTipo(tipo, tipoPasajero, tamTipo, &posicionTipo);
						listarPasajero(auxId, nombre, apellido, precio, tipoPasajero[posicionTipo].descripcion, codigoVuelo, estadoVuelo);
						retorno=1;
						break;
					}
				}
			}
		}
		else
		{
			printf("No hay pasajeros para listar.\n");
		}
	}
	return retorno;
}

void listarPasajero(int id, char* nombre, char* apellido, float precio, char* descripTipo, char* codigoVuelo, char* estadoVuelo)
{
	printf("%-10d%-14s%-16s%-14.2f%-24s%-23s%s\n", id, nombre, apellido, precio, descripTipo, codigoVuelo, estadoVuelo);

}

int seleccionarPasajero(LinkedList* pArrayListPassenger, TypePassenger tipoPasajero[], int tamTipo, int* id)
{
	int retorno=0;
	int aux;
	if(id!=NULL&&pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		if(listarPasajeros(pArrayListPassenger, tipoPasajero, tamTipo))
		{
			if(obtenerInt(&aux, "Ingrese el id del pasajero:\n\n", "Error al seleccionar el id del pasajero. Intentelo de nuevo.\n\n", 1, ll_len(pArrayListPassenger), 10))
			{
				if(buscarPasajero(pArrayListPassenger, aux))
				{
					*id=aux;
					retorno=1;
				}
				else
				{
					printf("El id ingresado no existe. Vuelva a intentarlo luego.\n");
				}
			}
		}
	}
	return retorno;
}

int buscarPasajero(LinkedList* pArrayListPassenger, int id)
{
	int retorno=0;
	int auxId;
	Passenger* auxPasajero=NULL;
	if(pArrayListPassenger!=NULL)
	{
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			if((Passenger_getId(auxPasajero, &auxId))&&id==auxId)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int buscarPosicionPasajero(LinkedList* pArrayListPassenger, int id, int* posicion)
{
	int retorno=0;
	int auxId;
	Passenger* auxPasajero=NULL;
	if(pArrayListPassenger!=NULL&&posicion!=NULL)
	{
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			if((Passenger_getId(auxPasajero, &auxId))&&id==auxId)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_sortId(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int aux1;
	int aux2;

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getId((Passenger*)thisOne, &aux1)&&Passenger_getId((Passenger*)thisTwo, &aux2))
		{
			if(aux1>aux2)
			{
				retorno=1;
			}
			if(aux1<aux2)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortNombre(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char aux1[CANT];
	char aux2[CANT];

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getNombre((Passenger*)thisOne, aux1)&&Passenger_getNombre((Passenger*)thisTwo, aux2))
		{
			if(strcmp(aux1,aux2)>0)
			{
				retorno=1;
			}
			if(strcmp(aux1,aux2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortApellido(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char aux1[CANT];
	char aux2[CANT];

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getApellido((Passenger*)thisOne, aux1)&&Passenger_getApellido((Passenger*)thisTwo, aux2))
		{
			if(strcmp(aux1,aux2)>0)
			{
				retorno=1;
			}
			if(strcmp(aux1,aux2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortPrecio(void* thisOne, void* thisTwo)
{
	int retorno=0;
	float aux1;
	float aux2;

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getPrecio((Passenger*)thisOne, &aux1)&&Passenger_getPrecio((Passenger*)thisTwo, &aux2))
		{
			if(aux1>aux2)
			{
				retorno=1;
			}
			if(aux1<aux2)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortTipo(void* thisOne, void* thisTwo)
{
	int retorno=0;
	int aux1;
	int aux2;

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getTipoPasajero((Passenger*)thisOne, &aux1)&&Passenger_getTipoPasajero((Passenger*)thisTwo, &aux2))
		{
			if(aux1>aux2)
			{
				retorno=1;
			}
			if(aux1<aux2)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int Passenger_sortVuelo(void* thisOne, void* thisTwo)
{
	int retorno=0;
	char aux1[CANT];
	char aux2[CANT];

	if(thisOne!=NULL&&thisTwo!=NULL)
	{
		if(Passenger_getCodigoVuelo((Passenger*)thisOne, aux1)&&Passenger_getCodigoVuelo((Passenger*)thisTwo, aux2))
		{
			if(strcmp(aux1,aux2)>0)
			{
				retorno=1;
			}
			if(strcmp(aux1,aux2)<0)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

void obtenerUltimoIdLinkedList(LinkedList* pArrayListPassenger, int* id)
{
	int auxId;
	Passenger* auxPasajero=NULL;

	if(pArrayListPassenger!=NULL&&id!=NULL&&(ll_isEmpty(pArrayListPassenger)==0))
	{
		for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			auxPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(auxPasajero, &auxId);
			if(auxId>*id)
			{
				*id=auxId;
			}
		}
	}
}
