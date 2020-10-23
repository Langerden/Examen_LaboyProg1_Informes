#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getDato.h"
#include "Servicio.h"

void listarServicio (Servicio list)
{
	printf("ID:%d  Descripcion:%s Precio: %.2f\n",list.id,list.descripcion,list.precio);
}

int listarServicios (Servicio *list, int largoArray)
{
	int retorno = -1;

	for (int i = 0; i < largoArray; i++)
	{
		listarServicio(list[i]);
			retorno = 0;
	}
	return retorno;
}

int cargarDescripcionServicio(Servicio *list, int largoArray, int idServicio, char descripcion[])
{
	int retorno = -1;
	for(int i=0; i < largoArray; i++)
	{
		if(list[i].id == idServicio)
		{
			strcpy(descripcion, list[i].descripcion);
			retorno = 0;
			break;
		}
	}
	return retorno;
}

