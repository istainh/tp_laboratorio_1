
#include "FuncionesGenerales.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    char salir='n';
	int opcion;
	int ultimoId=0;
	int archivoAbierto=0;
	int porGuardar=0;
    LinkedList* listaPasajeros = ll_newLinkedList();
	TypePassenger tipoPasajero[3]={{1, "FirstClass"}, {2, "ExecutiveClass"}, {3, "EconomyClass"}};
	Flight vuelos[8]={{"BA2491A", "Aterrizado"}, {"BR3456J", "Demorado"}, {"FR5678G", "En Horario"}, {"GU2345F", "En Vuelo"},
			          {"HY4567D", "Demorado"}, {"IB0800A", "Aterrizado"}, {"MM0987B", "En Horario"}, {"TU6789B", "Aterrizado"}};

	do
	{
		encabezadoMenu();
		if(opcionMenu(&opcion))
		{
			switch (opcion)
			{
				case 1:
					if(archivoAbierto==0)
					{
						if(controller_loadFromText("data.csv", listaPasajeros, tipoPasajero, 3, &ultimoId))
						{
							archivoAbierto=1;
							porGuardar=1;
						}
						else
						{
							printf("Error al cargar el archivo.\n\n");
						}
					}
					else
					{
						printf("Ya tiene un archivo abierto.\n\n");
					}
					break;
				case 2:
					if(archivoAbierto==0)
					{
						if(controller_loadFromBinary("data.bin", listaPasajeros))
						{
							archivoAbierto=1;
							porGuardar=1;
						}
						else
						{
							printf("Error al cargar el archivo.\n\n");
						}
					}
					else
					{
						printf("Ya tiene un archivo abierto.\n\n");
					}
					break;
				case 3:
					if(controller_addPassenger(listaPasajeros, tipoPasajero, vuelos, 3, 8, &ultimoId))
					{
						porGuardar=1;
					}
					break;
				case 4:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_editPassenger(listaPasajeros, tipoPasajero, 3, vuelos, 8);
					}
					else
					{
						printf("No hay pasajeros para poder modificar.\n");
					}
					break;
				case 5:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_removePassenger(listaPasajeros, tipoPasajero, 3);
						if(ll_isEmpty(listaPasajeros))
						{
							porGuardar=0;
						}
					}
					else
					{
						printf("No hay pasajeros para eliminar.\n");
					}
					break;
				case 6:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_ListPassenger(listaPasajeros, tipoPasajero, 3);
					}
					else
					{
						printf("No hay pasajeros para listar.\n");
					}
					break;
				case 7:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_sortPassenger(listaPasajeros);
					}
					else
					{
						printf("No hay pasajeros para ordenar.\n");
					}
					break;
				case 8:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_saveAsText("data.csv", listaPasajeros, tipoPasajero, 3);
						porGuardar=0;
					}
					else
					{
						printf("No hay pasajeros para guardar en el archivo.\n");
					}
					break;
				case 9:
					if(ll_isEmpty(listaPasajeros)==0)
					{
						controller_saveAsBinary("data.bin", listaPasajeros);
						porGuardar=0;
					}
					else
					{
						printf("No hay pasajeros para guardar en el archivo.\n");
					}
					break;
				case 10:
					if(porGuardar==0)
					{
						consultarSalir(&salir);
					}
					else
					{
						printf("Debe guardar primero los pasajeros cargados o eliminar los mismos antes de salir.\n");
					}
					break;
			}
		}
	}while(salir=='n'||opcion!=10);

return EXIT_SUCCESS;
}


