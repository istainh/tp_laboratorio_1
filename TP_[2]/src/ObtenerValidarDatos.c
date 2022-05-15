#include "ObtenerValidarDatos.h"

int obtenerInt(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=0;
	int numero;
	int aux;
	if(pNumero!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			aux=getInt(&numero);
			if((aux==1)&&(numero>=minimo)&&(numero<=maximo))
			{
				*pNumero=numero;
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno=0;
	char buffer[CANT];
	if(pResultado!=NULL)
	{
		gets(buffer);
		if(validarInt(buffer)&&quitarEspacio(buffer,sizeof(buffer)))
		{
			*pResultado = atoi(buffer);
			retorno=1;
		}
	}
	return retorno;
}

int validarInt(char* cadena)
{
	int retorno=1;
	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if(isdigit(cadena[i])==0)
			{
				if(i!=0||cadena[0]!='-'||isspace(cadena[i]))
				{
					retorno=0;
					break;
				}
			}
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}

int obtenerCaracter(char* pCaracter, char* mensaje, char* mensajeError, char opcionUno, char opcionDos, int reintentos)
{
	int retorno=0;
	char caracter;
	char aux;
	if(pCaracter!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &caracter);
			aux=tolower(caracter);
			if(aux==opcionUno||aux==opcionDos)
			{
				*pCaracter=aux;
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}
	return retorno;
}

int obtenerFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=0;
	float numero;
	int aux;
	if (pNumero!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			aux=getFloat(&numero);
			if(aux&&numero>=minimo&&numero<=maximo)
			{
				*pNumero=numero;
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	char buffer[CANT];
	int retorno=0;
	if(pResultado!=NULL)
	{
		scanf("%s", buffer);
		if(validarFloat(buffer)&&quitarEspacio(buffer,sizeof(buffer)))
		{
			*pResultado=atof(buffer);
			retorno=1;
		}
	}
	return retorno;
}

int validarFloat(char* cadena)
{
	int retorno=1;
	int contaSigno=0;
	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if(cadena[i]=='.')
			{
				contaSigno++;
			}
			else if(contaSigno>1)
			{
				retorno=0;
			}
			else
			{
				if(isdigit(cadena[i])==0)
				{
					if(i!=0||cadena[0]!='-'||isspace(cadena[i]))
					{
						retorno=0;
						break;
					}
				}
			}
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}

int quitarEspacio(char* cadena, int longitud)
{
	int retorno=0;
	if(cadena!=NULL&&longitud>0)
	{
		if (cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=1;
	}
	return retorno;
}

int obtenerString(char* mensaje, char* mensajeError, char arrayString[], int reintentos)
{
	int retorno=0;
	if(mensaje!=NULL&&arrayString!=NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(arrayString);

			if(validarString(arrayString))
			{
				retorno=1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int validarString(char *pString)
{
	int retorno=1;
	if (pString!=NULL)
	{
		for(int i=0;i<strlen(pString);i++)
		{
			if(isspace(pString[i])==0)
			{
				retorno=0;
				break;
			}
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
