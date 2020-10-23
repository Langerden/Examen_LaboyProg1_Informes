#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include "utn_getDato.h"
# include "Fecha.h"


void listarFecha (Fecha list)
{
	printf("Año:%d  Mes:%d  Dia:%d\n",list.anio,list.mes,list.dia);
}

int listarFechas (Fecha *list, int largoArray)
{
	int retorno = -1;

	for (int i = 0; i < largoArray; i++)
	{
		listarFecha(list[i]);
			retorno = 0;
	}
	return retorno;
}
