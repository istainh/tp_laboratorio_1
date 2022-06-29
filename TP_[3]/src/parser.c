#include "parser.h"

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger, TypePassenger* tipoPasajero, int tamTipo)
{
	int retorno=0;
	int retornoLeido;
	char buffer[7][128];
	Passenger* pAuxPasajero=NULL;

	if(pFile!=NULL&&pArrayListPassenger!=NULL&&tipoPasajero!=NULL&&tamTipo>0)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
		do
		{
			retornoLeido=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			if(retornoLeido==7)
			{
				pAuxPasajero=Passenger_newParametrosArchivo(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6], tipoPasajero, tamTipo);
				if(pAuxPasajero!=NULL)
				{
					ll_add(pArrayListPassenger,pAuxPasajero);
					retorno=1;
				}
			}
			else
			{
				Passenger_delete(pAuxPasajero);
				break;
			}
		}while(!feof(pFile));
	}
return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int retornoLeido;
	Passenger* auxPasajero=NULL;
	if(pFile!=NULL&&pArrayListPassenger!=NULL)
	{
		do
		{
			auxPasajero=Passenger_new();
			if(auxPasajero!=NULL)
			{
				retornoLeido=fread(auxPasajero,sizeof(Passenger),1,pFile);
				if(retornoLeido!=1)
				{
					Passenger_delete(auxPasajero);
					break;
				}
				else
				{
					ll_add(pArrayListPassenger,auxPasajero);
					retorno=1;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
