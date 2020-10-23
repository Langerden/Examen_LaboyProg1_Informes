#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getDato.h"
#include "Cliente.h"

int cargarDescripcionCliente(Cliente *list, int largoArray, int idCliente, char nombre[], char apellido[])
{
	int retorno = -1;
	for(int i=0; i < largoArray; i++)
	{
		if(list[i].id == idCliente)
		{
			strcpy(nombre, list[i].nombre);
			strcpy(apellido, list[i].apellido);
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int buscarClientePorID(Cliente* list, int largoCliente,int idCliente)
{
		int retorno = -1;

		for(int i = 0; i < largoCliente; i++)
		{
			if(list[i].id == idCliente && list[i].id > 0)
			{
				retorno = i;
				break;
			}
		}
		return retorno;
}

void listarCliente(Cliente list)
{
	printf("ID:%d  Nombre:%s  Apellido:%s\n",list.id,list.nombre,list.apellido);
}

int listarClientes(Cliente* list, int largoArray)
{
		int retorno = -1;

		for (int i = 0; i < largoArray; i++)
		{
			listarCliente(list[i]);
			retorno = 0;
		}
		return retorno;
}



