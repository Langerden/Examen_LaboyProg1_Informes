#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Marca.h"
#include "utn_getDato.h"

void listarMarca (Marca list)
{
	printf("ID:%d  Marca:%s \n",list.id,list.descripcion);
}

int listarMarcas (Marca *list, int largoArray)
{
	int retorno = -1;

	for (int i = 0; i < largoArray; i++)
	{
		listarMarca(list[i]);
		retorno = 0;
	}
	return retorno;
}

// Funcion descripcion
int cargarDescripcionMarca(Marca *list, int largoArray, int idMarca, char descripcion[])
{
	int retorno = -1;
	for(int i=0; i < largoArray; i++)
	{
		if(list[i].id == idMarca)
		{
			strcpy(descripcion, list[i].descripcion);
			retorno = 0;
			break;
		}
	}
	return retorno;
}
