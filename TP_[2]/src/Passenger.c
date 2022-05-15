/*
 * Passenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Ainhoa Osorio
 */
#include "Passenger.h"

int initPassenger(Passenger* estructura, int tamanio)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0;i<tamanio;i++)
		{
			estructura[i].isEmpty=1;
			retorno=1;
		}
	}
	else
	{
		printf("El puntero es nulo o el tamanio no es válido en la funcion initAlbum.\n");
	}
	return retorno;
}

int cargarPassenger(Passenger estrucPassenger[], int tamPassenger, Flight estrucFlight[], int tamFlight, TypePassenger estrucTipo[], int tamTipo, int* ultimoId)
{
	int retorno=0;
	int posicion;
	int id;
	char nombre[CANT];
	char apellido[CANT];
	float precio;
	int codigoTipo;
	char codigoVuelo[CANT2];

	if(estrucPassenger!=NULL&&estrucFlight!=NULL&&estrucTipo!=NULL&&tamPassenger>0&&tamFlight>0&&tamTipo>0)
	{
		if(buscarIsEmpty(estrucPassenger, tamPassenger, &posicion))
		{
			if(obtenerString("Ingrese el nombre del pasajero:\n\n", "Error al ingresar el nombre del pasajero. Vuelva a intentarlo.\n\n", nombre, 10)&&
			   obtenerString("Ingrese el apellido del pasajero:\n\n", "Error al ingresar el apellido del pasajero. Vuelva a intentarlo.\n\n", apellido, 10)&&
			   obtenerFloat(&precio, "Ingrese el precio del ticket:\n\n", "Error al ingresar el precio del ticket. Vuelva a intentarlo.\n\n", 1, 1000000, 10)&&
			   seleccionarTipo(&codigoTipo, estrucTipo, tamTipo)&&
			   seleccionarVuelo(codigoVuelo, estrucFlight, tamFlight))
			{
				id=*ultimoId+1;
				if(addPassenger(estrucPassenger, posicion, id, nombre, apellido, precio, codigoTipo, codigoVuelo))
				{
					printf("Se cargó exitosamente el pasajero #%d \n\n", id);
					*ultimoId=id;
					retorno=1;
				}
			}
			else
			{
				printf("Se agotaron los intentos para cargar algun dato. Vuelva a intentarlo luego.\n\n");
			}
		}
		else
		{
			printf("No hay espacio para agregar más pasajeros.\n\n");
		}
	}
	else
	{
		printf("Uno de los punteros es nulo o el tamaño de las estructuras en inválida en la funcion buscarIsEmpty.\n");
	}
	return retorno;
}

int buscarIsEmpty(Passenger estructura[], int tamanio, int* posicion)
{
	int retorno=0;
	if(estructura!=NULL&&posicion!=NULL&&tamanio>0)
	{
		for(int i=0;i<tamanio;i++)
		{
			if(estructura[i].isEmpty==1)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Algun puntero es nulo o el tamanio es inválido para la función buscarIsEmpty.\n");
	}
	return retorno;
}

void listarTipo(TypePassenger estructura[], int posicion)
{
	if(estructura!=NULL)
	{
		printf("%d\t\t%s\n", estructura[posicion].codigoTipo, estructura[posicion].descripcion);

	}
	else
	{
		printf("Puntero nulo o posicion inválida en la funcion listarTipo.\n");
	}
}

int listarTipos(TypePassenger estructura[], int tamanio)
{
	int retorno=0;
	int flagCabecera=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(flagCabecera==0)
			{
				printf("Id:\tTipo de pasajero:\n");
				flagCabecera=1;
			}
			listarTipo(estructura, i);
		}
		retorno=1;
	}
	return retorno;
}

int buscarTipo(int codigo, TypePassenger estructura[], int tamanio)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].codigoTipo==codigo)
			{
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarTipo.\n");
	}
	return retorno;
}

int buscarPosicionTipo(int codigo, TypePassenger estructura[], int tamanio, int* posicion)
{
	int retorno=0;
	if(estructura!=NULL&&posicion!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].codigoTipo==codigo)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarPosicionTipo.\n");
	}
	return retorno;
}

int buscarPosicionPasajero(int id, Passenger estructura[], int tamanio, int* posicion)
{
	int retorno=0;
	if(estructura!=NULL&&posicion!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].id==id)
			{
				*posicion=i;
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarPosicionPasajero.\n");
	}
	return retorno;
}

int seleccionarTipo(int* codigo, TypePassenger estructura[], int tamanio)
{
	int retorno=0;
	int aux;
	if(codigo!=NULL&&estructura!=NULL&&tamanio>0)
	{
		if(listarTipos(estructura, tamanio))
		{
			if(obtenerInt(&aux, "Ingrese el código del tipo de pasajero:\n\n", "Error al seleccionar el código del tipo de pasajero. Intentelo de nuevo.\n\n", 1, tamanio, 10))
			{
				if(buscarTipo(aux, estructura, tamanio))
				{
					*codigo=aux;
					retorno=1;
				}
				else
				{
					printf("El código ingresado no existe. Vuelva a intentarlo luego.\n");
				}
			}
		}
	}
	else
	{
		printf("Punteros nulos o tamaño inválido en la funcion seleccionarTipo.\n");
	}
	return retorno;
}

int addPassenger(Passenger* estructura, int posicion, int id, char nombre[], char apellido[], float precio, int codigoTipo, char codigoVuelo[])
{
	int retorno=0;
	if(estructura!=NULL)
	{
		estructura[posicion].id=id;
		strcpy(estructura[posicion].nombre,nombre);
		strcpy(estructura[posicion].apellido,apellido);
		estructura[posicion].precio=precio;
		estructura[posicion].codigoTipo=codigoTipo;
		strcpy(estructura[posicion].codigoVuelo,codigoVuelo);
		estructura[posicion].isEmpty=0;
		retorno=1;
	}
	else
	{
		printf("Un puntero o array es nulo en la función addPassenger.\n");
	}
	return retorno;
}

int eliminarPasajero(Passenger estructura[], int tamanio)
{
	int retorno=0;
	int id;
	char darBaja;
	if(estructura!=NULL&&tamanio>0)
	{
		if(seleccionarPasajero(estructura, tamanio, &id))
		{
			if(obtenerCaracter(&darBaja, "¿Desea dar de baja al id #%d? [s]-si [n]-no\n", "Opción ingresado inválido. Intente de nuevo.\n", 's', 'n', 10))
			{
				if(darBaja=='s')
				{
					if(removerPasajero(estructura, tamanio, id))
					{
						printf("Se dio de baja al pasajero #%d.\n", id);

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
			else
			{
				printf("Error al ingresar una opcion en eliminarPasajero\n");
			}
		}
	}

	return retorno;
}

void listarPasajero(Passenger estructura[], int posicion)
{
	if(estructura!=NULL)
	{
		printf("t%d\t\t%s\t\t%s\t\t%.2f\t\t%d\t\t%s\n", estructura[posicion].id, estructura[posicion].nombre, estructura[posicion].apellido,
				                                        estructura[posicion].precio, estructura[posicion].codigoTipo, estructura[posicion].codigoVuelo);

	}
	else
	{
		printf("Puntero nulo o posicion inválida en la funcion listarPasajero.\n");
	}
}

int listarPasajeros(Passenger estructura[], int tamanio)
{
	int retorno=0;
	int flagCabecera=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].isEmpty==0)
			{
				if(flagCabecera==0)
				{
					printf("Id:\tNombre:\tApellido:\tPrecio;\tTipo pasajero:\tVuelo:\n");
					flagCabecera=1;
				}
				listarPasajero(estructura, i);
			}
		}
		retorno=1;
	}
	return retorno;
}

int listarPasajerosCompletos(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int retorno=0;
	int flagCabecera=0;
	int posicionTipo;
	int posicionVuelo;
	if(estrucPasajero!=NULL&&estrucTipo!=NULL&&estrucVuelo!=NULL&&tamPasajero>0&&tamTipo>0&&tamVuelo>0)
	{
		for(int i=0; i<tamPasajero; i++)
		{
			if(estrucPasajero[i].isEmpty==0)
			{
				if(buscarPosicionTipo(estrucPasajero[i].codigoTipo, estrucTipo, tamTipo, &posicionTipo)&&
				   buscarPosicionVuelo(estrucPasajero[i].codigoVuelo, estrucVuelo, tamVuelo, &posicionVuelo))
				{
					if(flagCabecera==0)
					{
						printf("Id:       Nombre:       Apellido:       Precio:       Tipo de Pasejero:       Código de vuelo:       Estatus del vuelo:\n");
						flagCabecera=1;
					}
					listarPasajeroCompleto(estrucPasajero, i, estrucTipo[posicionTipo].descripcion, estrucVuelo[posicionVuelo].descripcionEstado);

				}
			}
		}
		retorno=1;
	}
	return retorno;
}

void listarPasajeroCompleto(Passenger estructura[], int posicion, char* tipoPasajero, char* estatusVuelo)
{
	if(estructura!=NULL&&tipoPasajero!=NULL&&estatusVuelo!=NULL)
	{
		printf("%-10d%-14s%-16s%-14.2f%-24s%-23s%-25s\n", estructura[posicion].id, estructura[posicion].nombre, estructura[posicion].apellido,
														  estructura[posicion].precio, tipoPasajero, estructura[posicion].codigoVuelo, estatusVuelo);
	}
	else
	{
		printf("Punteros nulos o posicion inválida en la funcion listarPasajeroCompleto.\n");
	}
}

int buscarPasajero(Passenger estructura[], int tamanio, int id)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].id==id)
			{
				retorno=1;
				break;
			}
		}
	}
	else
	{
		printf("Puntero nulo en la funcion buscarPasajero.\n");
	}
	return retorno;
}

int seleccionarPasajero(Passenger estructura[], int tamanio, int* id)
{
	int retorno=0;
	int aux;
	if(id!=NULL&&estructura!=NULL&&tamanio>0)
	{
		if(listarPasajeros(estructura, tamanio))
		{
			if(obtenerInt(&aux, "Ingrese el id del pasajero:\n\n", "Error al seleccionar el id del pasajero. Intentelo de nuevo.\n\n", 1, tamanio, 10))
			{
				if(buscarPasajero(estructura, tamanio, aux))
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
	else
	{
		printf("Punteros nulos o tamaño inválido en la funcion seleccionarPasajero.\n");
	}
	return retorno;
}

int removerPasajero(Passenger estructura[], int tamanio, int id)
{
	int retorno=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].id==id)
			{
				estructura[i].isEmpty=1;
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int menuModificadorPassenger(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int retorno=0;
	int opcion;
	int posicion;
	int id;

	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		if(seleccionarPasajero(estrucPasajero, tamPasajero, &id))
		{
			if(buscarPosicionPasajero(id, estrucPasajero, tamPasajero, &posicion))
			{
				listarPasajero(estrucPasajero, posicion);
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
							if(obtenerString("Ingrese el nombre:\n", "Nombre inválido. Vuelva a intentar ingresarlo.\n",
							   estrucPasajero[posicion].nombre, 10))
							{
								printf("Nombre modificado con exito. Nombre: %s\n", estrucPasajero[posicion].nombre);
							}
							else
							{
								printf("Hubo un error al intentar modificar el nombre.\n");
							}
							break;
						case 2:
							if(obtenerString("Ingrese el apellido:\n", "apellido inválido. Vuelva a intentar ingresarlo.\n",
							   estrucPasajero[posicion].apellido, 10))
							{
								printf("Apellido modificado con exito. Apellido: %s\n", estrucPasajero[posicion].apellido);
							}
							else
							{
								printf("Hubo un error al intentar modificar el apellido.\n");
							}
							break;
						case 3:
							if(obtenerFloat(&estrucPasajero[posicion].precio, "Ingrese el precio:\n", "Precio inválido. Vuelva a intentar ingresarlo.\n",
							   1, 1000000, 10))
							{
								printf("Precio modificado con exito. Precio: %.2f\n", estrucPasajero[posicion].precio);
							}
							else
							{
								printf("Hubo un error al intentar modificar el precio.\n");
							}
							break;
						case 4:
							if(seleccionarTipo(&estrucPasajero[posicion].codigoTipo, estrucTipo, tamTipo))
							{
								printf("El tipo de pasajero fue modificado con exito.\n");
							}
							else
							{
								printf("Hubo un error al intentar modificar el tipo de pasajero.\n");
							}
							break;
						case 5:
							if(seleccionarVuelo(estrucPasajero[posicion].codigoVuelo, estrucVuelo, tamVuelo))
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

int menuListar(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int retorno=0;
	int opcion;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		if(obtenerInt(&opcion, "Indique qué desea listar:\n"
							   "[1] Listado de pasajeros ordenados alafabeticamente por apellido y tipo de pasajero.\n"
							   "[2] Todos los tipos de artistas musicales.\n"
							   "[3] Listar a los pasajeros por código de vuelo y estado de vuelo ACTIVO.\n\n",
							   "Opción ingresada inválida. Vuelva a ingresar la opción.\n", 1, 3, 10))
		{
			switch (opcion)
			{
				case 1:
					listarPasajerosOrdenados(estrucPasajero, tamPasajero, estrucTipo, tamTipo, estrucVuelo, tamVuelo);
					break;
				case 2:
					listarPreciosPasajes(estrucPasajero, tamPasajero);
					break;
				case 3:
					listarPasajerosVuelo(estrucPasajero, tamPasajero, estrucTipo, tamTipo, estrucVuelo, tamVuelo);
					break;
			}
			retorno=1;
		}
	}
	return retorno;
}

void listarPasajerosOrdenados(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int orden;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		if(obtenerInt(&orden, "Ingrese la opción para ordenar el listado alfabeticamente: [1]- Ascendente [0]-Descendente\n",
					  "Error al ingresar la opción. Ingrese de nuevo una opción válida.\n", 0, 1, 10))
		{
			ordenarPasajeros(estrucPasajero, tamPasajero, estrucTipo, tamTipo, orden);
		}
		listarPasajerosCompletos(estrucPasajero, tamPasajero, estrucTipo, tamTipo, estrucVuelo, tamVuelo);
	}
}

void ordenarPasajeros(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, int orden)
{
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0)
	{
		if(orden)
		{
			ordenarPasajerosAscendente(estrucPasajero, tamPasajero, estrucTipo, tamTipo);
		}
		else
		{
			ordenarPasajerosDescendete(estrucPasajero, tamPasajero, estrucTipo, tamTipo);
		}
	}
}

void ordenarPasajerosAscendente(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo)
{
	Passenger aux;
	int posicionTipo;
	int posicionTipoDos;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamPasajero-1; i++)
		{
			for(int j=i+1; j<tamPasajero; j++)
			{
				if(estrucPasajero[i].isEmpty==0&&estrucPasajero[j].isEmpty==0)
				{
					if((strcmp(estrucPasajero[i].apellido,estrucPasajero[j].apellido))<0)
					{
						aux=estrucPasajero[i];
						estrucPasajero[i]=estrucPasajero[j];
						estrucPasajero[j]=aux;
					}
					if((strcmp(estrucPasajero[i].apellido,estrucPasajero[j].apellido))==0)
					{
						buscarPosicionTipo(estrucPasajero[i].codigoTipo, estrucTipo, tamTipo, &posicionTipo);
						buscarPosicionTipo(estrucPasajero[j].codigoTipo, estrucTipo, tamTipo, &posicionTipoDos);
						if((strcmp(estrucTipo[i].descripcion,estrucTipo[j].descripcion))<0)
						{
							aux=estrucPasajero[i];
							estrucPasajero[i]=estrucPasajero[j];
							estrucPasajero[j]=aux;
						}
					}
				}
			}
		}
	}
}

void ordenarPasajerosDescendete(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo)
{
	Passenger aux;
	int posicion;
	int posicionDos;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0)
	{
		for(int i=0; i<tamPasajero-1; i++)
		{
			for(int j=i+1; j<tamPasajero; j++)
			{
				if(estrucPasajero[i].isEmpty==0&&estrucPasajero[j].isEmpty==0)
				{
					if((strcmp(estrucPasajero[i].apellido,estrucPasajero[j].apellido))>0)
					{
						aux=estrucPasajero[i];
						estrucPasajero[i]=estrucPasajero[j];
						estrucPasajero[j]=aux;
					}
					if((strcmp(estrucPasajero[i].apellido,estrucPasajero[j].apellido))==0)
					{
						buscarPosicionTipo(estrucPasajero[i].codigoTipo, estrucTipo, tamTipo, &posicion);
						buscarPosicionTipo(estrucPasajero[j].codigoTipo, estrucTipo, tamTipo, &posicionDos);
						if((strcmp(estrucTipo[posicion].descripcion,estrucTipo[posicionDos].descripcion))>0)
						{
							aux=estrucPasajero[i];
							estrucPasajero[i]=estrucPasajero[j];
							estrucPasajero[j]=aux;
						}
					}
				}
			}
		}
	}
}

void listarPreciosPasajes(Passenger estructura[], int tamanio)
{
	float totalImporte=0;
	float promedio;
	int contadorPromedio=0;
	if(estructura!=NULL&&tamanio>0)
	{
		if(calcularTotalPromedio(estructura, tamanio, &totalImporte, &promedio))
		{
			for(int i=0; i<tamanio; i++)
			{
				if(estructura[i].isEmpty==0)
				{
					if(estructura[i].precio>promedio)
					{
						contadorPromedio++;
					}
				}
			}
			printf("Total de los precios de los pasajes: %.2f\n\n"
				   "Promedio de los precios de los pasajes: %.2f\n\n"
				   "Cantidad de pasajeros que superan el promedio del precio de los pasajes: %d\n\n", totalImporte, promedio, contadorPromedio);
		}
	}
}

int calcularTotalPromedio(Passenger estructura[], int tamanio, float* importeTotal, float* promedio)
{
	int retorno=0;
	int auxConta=0;
	float auxImporte=0;
	float auxPromedio=0;
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<tamanio; i++)
		{
			if(estructura[i].isEmpty==0)
			{
				auxImporte=auxImporte+estructura[i].precio;
				auxConta++;
			}
		}
		auxPromedio=(float)auxImporte/auxConta;
		*promedio=auxPromedio;
		*importeTotal=auxImporte;
		retorno=1;
	}
	return retorno;
}

void listarPasajerosVuelo(Passenger estrucPasajero[], int tamPasajero, TypePassenger estrucTipo[], int tamTipo, Flight estrucVuelo[], int tamVuelo)
{
	int orden;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucTipo!=NULL&&tamTipo>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		if(obtenerInt(&orden, "Ingrese la opción para ordenar el listado alfabeticamente: [1]- Ascendente [0]-Descendente\n",
					  "Error al ingresar la opción. Ingrese de nuevo una opción válida.\n", 0, 1, 10))
		{
			ordenarPasajerosPorCodigo(estrucPasajero, tamPasajero, estrucVuelo, tamVuelo, orden);
		}
		listarPasajerosCompletos(estrucPasajero, tamPasajero, estrucTipo, tamTipo, estrucVuelo, tamVuelo);
	}
}

void ordenarPasajerosPorCodigo(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo, int orden)
{
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		if(orden)
		{
			ordenarVueloAscendente(estrucPasajero, tamPasajero, estrucVuelo, tamVuelo);
		}
		else
		{
			ordenarVueloDescendente(estrucPasajero, tamPasajero, estrucVuelo, tamVuelo);
		}
	}
}

void ordenarVueloAscendente(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo)
{
	Passenger aux;
	int posicion;
	int posicionDos;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		for(int i=0; i<tamPasajero-1; i++)
		{
			for(int j=i+1; j<tamPasajero; j++)
			{
				if(estrucPasajero[i].isEmpty==0&&estrucPasajero[j].isEmpty==0)
				{
					if((strcmp(estrucPasajero[i].codigoVuelo,estrucPasajero[j].codigoVuelo))<0)
					{
						aux=estrucPasajero[i];
						estrucPasajero[i]=estrucPasajero[j];
						estrucPasajero[j]=aux;
					}
					if((strcmp(estrucPasajero[i].codigoVuelo,estrucPasajero[j].codigoVuelo))==0)
					{
						buscarPosicionVuelo(estrucPasajero[i].codigoVuelo, estrucVuelo, tamVuelo, &posicion);
						buscarPosicionVuelo(estrucPasajero[j].codigoVuelo, estrucVuelo, tamVuelo, &posicionDos);
						if((strcmp(estrucVuelo[posicion].descripcionEstado,estrucVuelo[posicionDos].descripcionEstado))<0)
						{
							aux=estrucPasajero[i];
							estrucPasajero[i]=estrucPasajero[j];
							estrucPasajero[j]=aux;
						}
					}
				}
			}
		}
	}
}

void ordenarVueloDescendente(Passenger estrucPasajero[], int tamPasajero, Flight estrucVuelo[], int tamVuelo)
{
	Passenger aux;
	int posicion;
	int posicionDos;
	if(estrucPasajero!=NULL&&tamPasajero>0&&estrucVuelo!=NULL&&tamVuelo>0)
	{
		for(int i=0; i<tamPasajero-1; i++)
		{
			for(int j=i+1; j<tamPasajero; j++)
			{
				if(estrucPasajero[i].isEmpty==0&&estrucPasajero[j].isEmpty==0)
				{
					if((strcmp(estrucPasajero[i].codigoVuelo,estrucPasajero[j].codigoVuelo))>0)
					{
						aux=estrucPasajero[i];
						estrucPasajero[i]=estrucPasajero[j];
						estrucPasajero[j]=aux;
					}
					if((strcmp(estrucPasajero[i].codigoVuelo,estrucPasajero[j].codigoVuelo))==0)
					{
						buscarPosicionVuelo(estrucPasajero[i].codigoVuelo, estrucVuelo, tamVuelo, &posicion);
						buscarPosicionVuelo(estrucPasajero[j].codigoVuelo, estrucVuelo, tamVuelo, &posicionDos);
						if((strcmp(estrucVuelo[posicion].descripcionEstado,estrucVuelo[posicionDos].descripcionEstado))>0)
						{
							aux=estrucPasajero[i];
							estrucPasajero[i]=estrucPasajero[j];
							estrucPasajero[j]=aux;
						}
					}
				}
			}
		}
	}
}

int cargaForzadaPasajeros(Passenger estructura[], int tamanio, int* ultimoId, int* contaAltaBajas)
{
	int retorno=0;
	int id=*ultimoId;
	int contador=*contaAltaBajas;
	char nombre[5][CANT]={"Camila", "Pedro", "Lucia", "Carlos", "Ainhoa"};
	char apellido[5][CANT]={"Ramirez", "Matos", "Lee", "Peres", "Osorio"};
	float precio[5]={1500, 1800, 15000, 24567.56, 123553.13};
	int codigoTipo[5]={1, 2, 3, 2, 1};
	char codigoVuelo[5][CANT2]={"BDB16C", "TPD22P", "ZPT88A", "BDB16C", "TPD22P"};
	if(estructura!=NULL&&tamanio>0)
	{
		for(int i=0; i<5; i++)
		{
			id++;
			contador++;
			if(estructura[i].isEmpty==1)
			{
				estructura[i].id=id;
				strcpy(estructura[i].nombre,nombre[i]);
				strcpy(estructura[i].apellido,apellido[i]);
				estructura[i].precio=precio[i];
				estructura[i].codigoTipo=codigoTipo[i];
				strcpy(estructura[i].codigoVuelo,codigoVuelo[i]);
				estructura[i].isEmpty=0;
			}
		}
		*contaAltaBajas=contador;
		*ultimoId=id;
	}
	return retorno;
}
