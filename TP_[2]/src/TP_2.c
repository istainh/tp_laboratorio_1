/*
 ============================================================================
 Name        : TP_2.c
 Author      : Ainhoa Osorio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "FuncionesGenerales.h"

int main(void){
	setbuf(stdout, NULL);

	char salir='n';
	int opcion;
	int ultimoId=0;
	int contaAltasBajas=0;
	Flight vuelos[4]={{1, "ADV34C", ACTIVO, "Activo: Abordando."}, {2, "ZPT88A", ACTIVO, "Activo: Próximo a abordar."},
			          {3, "TPD22P", DEMORADO, "Demorado: Clima inadecuado."}, {4, "BDB16C", CANCELADO, "Cancelado: Deperfecto aeronave."}};
	TypePassenger tipoPasajeros[3]={{1, "Primera clase"}, {2, "Ejecutivo"}, {3, "Turista"}};
	Passenger pasajeros[ELEMENTS];

	if(initPassenger(pasajeros, ELEMENTS))
	{
		do
		{
			encabezadoMenu();
			if(opcionMenu(&opcion))
			{
				switch (opcion)
				{
					case 1:
						if(cargarPassenger(pasajeros, ELEMENTS, vuelos, 4, tipoPasajeros, 3, &ultimoId))
						{
							contaAltasBajas++;
						}
						else
						{
							printf("Hubo un Error al agregar el pasajero.\n");
						}
						break;
					case 2:
						if(contaAltasBajas>0)
						{
							menuModificadorPassenger(pasajeros, ELEMENTS, tipoPasajeros, 3, vuelos, 4);
						}
						else
						{
							printf("No hay pasajeros para poder modificar.\n");
						}
						break;
					case 3:
						if(contaAltasBajas>0)
						{
							if(eliminarPasajero(pasajeros, ELEMENTS))
							{
								contaAltasBajas--;
							}
						}
						else
						{
							printf("No hay pasajeros para dar de baja.\n");
						}
						break;
					case 4:
						if(contaAltasBajas>0)
						{
							if(!(menuListar(pasajeros, ELEMENTS, tipoPasajeros, 3, vuelos, 4)))
							{
								printf("Hubo un error al tratar de pedir un listado.\n");
							}
						}
						else
						{
							printf("No hay pasajeros cargados para poder generar listados.\n");
						}
						break;
					case 5:
						cargaForzadaPasajeros(pasajeros, ELEMENTS, &ultimoId, &contaAltasBajas);
						break;
					case 6:
						consultarSalir(&salir);
						break;
				}
			}
		}while(salir=='n'||opcion!=6);
	}
	return EXIT_SUCCESS;
}

