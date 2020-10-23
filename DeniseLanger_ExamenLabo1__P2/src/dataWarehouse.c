
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "Electro.h"
#include "Reparacion.h"


// 10 Electros

int idElectros[] = {1,2,3,4,5,6,7,8,9,10};
int serie[] = {150,150,155,154,152,150,150,155,152,152};
int idMarca[] = {1000,1000,1002,1003,1003,1003,1001,1000,1002,1003};
int idModelo[] = {2000,2002,2004,2006,2008,2010,2012,2014,2016,2020};

// 10 Reparacion

int idReparacion[] = {1,2,3,4,5,6,7,8,9,10};
int idServicio[] = {20001,20001,20002,20003,20003,20002,20001,20001,20001,20002};
Fecha fecha[] = {{10,10,2020},{10,10,2020},{12,10,2020},{12,10,2020},{9,10,2020},{8,10,2020},{30,9,2020},{25,9,2020},{25,8,2020},{25,7,2020}};

// Clientes
int idCliente [] = {50,51,52,53,54,55,56,57,58,59,};
char nombre [][20] = {{"Claudia"},{"Ricardo"},{"Ana"},{"Juan"},{"Pedro"},{"Facundo"},{"Carolina"},{"Julieta"},{"Marcelo"},{"Alejandro"}};
char apellido [][20] = {{"Lopez"},{"Gonzalez"},{"Perez"},{"Alvarez"},{"Juarez"},{"Oliva"},{"Aguilera"},{"Aranda"},{"Escobar"},{"Nuniez"}};

int hardcodearDatos(Electro *electro, int largoElectro, Reparacion *reparacion, int largoReparacion, Cliente *cliente, int largoCliente, int *flag)
{
	int okElectro = 0;
	int okReparacion = 0;
	int okCliente = 0;
	int retorno = 0;
	Electro auxElectro;
	Reparacion auxReparacion;
	Cliente auxCliente;

	for(int i = 0;i<largoElectro;i++)
	{
		auxElectro.id = idElectros[i];
		auxElectro.idMarca = idMarca[i];
		auxElectro.idModelo = idModelo[i];
		auxElectro.serie =  serie[i];
		electro[i] = auxElectro;
		okElectro = 1;
	}

	for(int i = 0;i<largoReparacion;i++)
	{
		auxReparacion.id = idReparacion[i];
		auxReparacion.serie = serie[i];
		auxReparacion.idServicio = idServicio[i];
		auxReparacion.fechaReparacion.dia = fecha[i].dia;
		auxReparacion.fechaReparacion.mes = fecha[i].mes;
		auxReparacion.fechaReparacion.anio = fecha[i].anio;
		auxReparacion.idCliente = idCliente[i];
		reparacion[i] = auxReparacion;
		okReparacion = 1;
	}

	for(int i = 0;i<largoCliente;i++)
		{
			auxCliente.id = idCliente[i];
			strcpy(auxCliente.nombre,nombre[i]);
			strcpy(auxCliente.apellido,apellido[i]);
			cliente[i] = auxCliente;
			okCliente = 1;
		}

	if(okElectro && okReparacion && okCliente)
	{
		retorno = 1;
		*flag = 10;
	}
	return retorno;
}

