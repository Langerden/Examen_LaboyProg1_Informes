#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn_getDato.h"
#include "Electro.h"
#include "Reparacion.h"
#include "Informes.h"


//1 Mostrar Electros segun Modelo (2020)
void mostrarElectroSegunModelo2020 (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca)
{
	int flag = 0;

	for(int e = 0; e < largoElectro; e++)
	{
		if(list[e].id > 0 && list[e].idModelo == 2020)
			{
				listarElectro(list[e], listaMarca, largoMarca);
				flag = 1;
			}
	}
	if(flag == 0)
	{
		printf("No hay ningun Electro registrado con el Modelo 2020\n");
	}
}


//2 Mostrar Electrodomésticos de una marca seleccionada
void mostrarElectroSegunMarca (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca)
{
	int auxMarca;
	int flagMarca = 0;
	char descMarca [20];

	listarMarcas(listaMarca, largoMarca);
	utn_getInt(&auxMarca,"Ingrese el ID de la Marca a mostrar: \n","ERROR. NO EXISTE ESE ID", 1000, 1004, 7);
	cargarDescripcionMarca(listaMarca, largoMarca, auxMarca, descMarca);

	for(int i = 0; i < largoElectro; i++)
	{
		if(list[i].id > 0 && auxMarca == list[i].idMarca)
		{
			listarElectro(list[i], listaMarca, largoMarca);
			flagMarca = 1;
		}
	}
	if (flagMarca == 0)
	{
		printf("No hay ningun Electro registrado con la Marca %s\n",descMarca);
	}
}

//3-Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado
void mostrarReparacionSegunElectro (Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Marca *listMarca, int largoMarca, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente)
{

	int flagReparacion = 0;
	int auxIDElectro;
	int index;

		listarElectros(listElectro, largoElectro, listMarca, largoMarca);
		utn_getInt(&auxIDElectro, "Ingrese el Numero de ID del Electro\n", "ERROR. Numero de ID Incorrecto\n", 1, 100, 7);
		index = buscarIDElectro(listElectro, largoElectro, auxIDElectro);

		if (index != -1)
		{
			for (int i = 0; i < largoReparacion; i++)
			{
				if(listReparacion[i].id > 0 && listReparacion[i].serie == listElectro[index].serie)
				{
					listarReparacion(listReparacion[i], listServicio, largoServicio, listCliente,largoCliente);
					flagReparacion = 1;
				}
			}
		}

		if (flagReparacion == 0)
		{
			printf("No se registro una reparacion para ese Electro\n");
		}
}

//4- Listar los Electrodomésticos que no tuvieron reparaciones
void mostrarElectrosSinReparacion(Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Marca *listMarca, int largoMarca, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente)
{

	int flagReparacion = 0;

		for(int r = 0; r < largoReparacion; r++)
		{
			if(listReparacion[r].id == 0 && listElectro[r].id != 0 && listReparacion[r].serie != listElectro[r].serie)
			{
				listarElectro(listElectro[r], listMarca, largoMarca);
				flagReparacion = 1;

			}
		}

		if (flagReparacion == 0)
		{
			printf("Todos los Electros poseen una reparacion registrada\n");
		}
}
// 5 - Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado
void sumarServiciosxElectro (Electro *listaElectro, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion, Cliente *listaCliente, int largoCliente, Servicio *listaServicio, int largoServicio)
{
	int auxIDElectro;
	int indexElectro;
	int indexService;
	float acumuladorServicios = 0;

	listarElectros(listaElectro, largoElectro, listaMarca, largoMarca);
	utn_getInt(&auxIDElectro, "Ingrese el numero de ID: \n",	"ERROR. ID INVALIDO\n", 1, 100, 7);

	indexElectro = buscarIDElectro(listaElectro, largoElectro, auxIDElectro);
	if(indexElectro != -1)
	{
		for(int s = 0; s < largoServicio; s++)
		{
			for(int r = 0; r < largoReparacion;r++)
			{
				if(listaElectro[indexElectro].serie == listaReparacion[r].serie)
				{
					indexService = listaReparacion[r].idServicio;
					if(listaServicio[s].id == indexService)
					{
						acumuladorServicios+= listaServicio[s].precio;
					}
				}
			}
		}
	}
	if(acumuladorServicios > 0)
	{
		printf("El costo total de los servicios para el Electro con ID %d es de %.2f\n", auxIDElectro,acumuladorServicios);
	} else {
		printf("No se registro ningun servicio para el Electro con ID %d\n", auxIDElectro);
	}
}

// 6- Mostrar el servicio más pedido
void mostrarServicioMasElegido (Servicio *lista, int largoServicio, Reparacion *listaReparacion, int largoReparacion)
{
	int contador;
	int arrayContadores [largoServicio];
	int arrayID [largoServicio];
	int flag = 0;
	int auxIDServicio = 0;
	int maxServicio;
	char descServicio [20];

		for(int s = 0; s < largoServicio; s++)
		{
			contador = 0;
			for(int r = 0; r < largoReparacion; r++)
			{
				if(listaReparacion[r].id > 0 && lista[s].id == listaReparacion[r].idServicio)
				{
					contador++;
				}
			}
			arrayContadores[s] = contador;
			arrayID[s] = lista[s].id;
		}

		for(int m = 0; m < largoServicio; m++)
		{
			if(flag == 0)
			{
				auxIDServicio = arrayID[m];
				maxServicio = arrayContadores[m];
				flag = 1;
			} else if (maxServicio < arrayContadores[m] && flag != 0)
			{
				auxIDServicio = arrayID[m];
				maxServicio = arrayContadores[m];
			}
		}
		cargarDescripcionServicio(lista, largoServicio, auxIDServicio, descServicio);
		printf("El Servicio mas elegido es: %s\n", descServicio);
}

//7- Mostrar la recaudación en una fecha en particular
void mostrarTotalServiciosxFecha (Servicio *listaServicio, int largoServicio, Reparacion *listaReparacion, int largoReparacion, Cliente *listaCliente, int largoCliente)
{
	Reparacion auxReparacion;
	float acumulador = 0;

	utn_getInt(&auxReparacion.fechaReparacion.anio, "Ingrese el anio (2000 al 2020): \n","ERROR. ANIO INVALIDO\n",2000, 2020, 7);
	utn_getInt(&auxReparacion.fechaReparacion.mes, "Ingrese el numero del Mes (1 al 12): \n", "ERROR. MES INVALIDO\n", 1, 12, 7);
	utn_getInt(&auxReparacion.fechaReparacion.dia, "Ingrese el dia (1 al 31): \n", "ERROR. DIA INVALIDO\n", 1, 31, 7);

	for (int r = 0; r < largoReparacion; r++)
	{
		for(int s = 0; s < largoServicio; s++)
		{
			if(listaReparacion[r].id > 0 && auxReparacion.fechaReparacion.anio == listaReparacion[r].fechaReparacion.anio && auxReparacion.fechaReparacion.mes == listaReparacion[r].fechaReparacion.mes && auxReparacion.fechaReparacion.dia == listaReparacion[r].fechaReparacion.dia
					&& listaReparacion[r].idServicio == listaServicio[s].id)
			{
				acumulador += listaServicio[s].precio;
			}
		}
	}
	if(acumulador == 0)
	{
		printf("No hay un Servicio registrado con la Fecha %d/%d/%d\n",auxReparacion.fechaReparacion.dia, auxReparacion.fechaReparacion.mes, auxReparacion.fechaReparacion.anio);
	} else {
		printf("El total de recaudaciones para la Fecha %d/%d/%d es de %.2f\n",auxReparacion.fechaReparacion.dia, auxReparacion.fechaReparacion.mes, auxReparacion.fechaReparacion.anio,acumulador);
	}
}

//8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha

void mostrarElectrosGarantiayFecha (Electro *listaElectro, int largoElectro, Reparacion *listaReparacion, int largoReparacion, Marca *listaMarca, int largoMarca)
{
	int flag = 0;

	for (int r = 0; r < largoReparacion; r++)
	{
		if(listaReparacion[r].id > 0)
		{
			for(int e = 0; e < largoElectro; e++)
		{
			if(listaElectro[e].id > 0 && listaReparacion[r].idServicio == 20000 && listaReparacion[r].serie == listaElectro[e].serie)
				{
					listarElectro(listaElectro[e], listaMarca, largoMarca);
					listarFecha(listaReparacion[r].fechaReparacion);
					flag = 1;
				}
			}
		}
	}
	if(flag == 0)
	{
		printf("No hay un Electro registrado con una Garantia\n");
	}
}

//9- Trabajos realizados a Electrodomésticos del año(modelo) 2018
void mostrarReparacionesModelo2018 (Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente)
{
	int flagReparacion = 0;

	for(int r = 0; r < largoReparacion; r++)
	{
		if(listReparacion[r].id > 0)
		{
			for(int e = 0; e < largoElectro; e++)
				{
					if(listElectro[e].id > 0 && listElectro[e].idModelo == 2018 && listReparacion[r].serie == listElectro[e].serie)
						{
							listarReparacion(listReparacion[r], listServicio, largoServicio, listCliente, largoCliente);
							flagReparacion = 1;
						}
				}
		}
	}
	if (flagReparacion == 0)
	{
		printf("No se registro ningun trabajo para un Electro con Modelo 2018\n");
	}
}

//10- Facturación total por los mantenimientos
void mostrarTotalMantenimientos(Reparacion *listaReparacion, int largoReparacion, Servicio *listaServicio, int largoServicio)
{
	float acumulador = 0;

	for(int r = 0; r < largoReparacion; r++)
	{
		if(listaReparacion[r].id > 0 && listaReparacion[r].idServicio == 20001)
		{
				acumulador += listaServicio[r].precio;
		}
	}

	if (acumulador > 0)
	{
		printf("La Facturacion total de los Mantenimientos es de %.2f:\n",acumulador);
	} else {
		printf("No se registro ningun Mantenimiento\n");
	}
}

//11- Informar la marca de Electrodomésticos que efectuaron más refacciones
void mostrarMarcaMasRefacciones (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion)
{
	int contador = 0;
	int arrayContadores [largoReparacion];
	int arrayID [largoReparacion];
	int flag = 0;
	int auxIDMarca = 0;
	int maxMarca;
	char descMarca [20];


	for(int e = 0; e < largoElectro; e++)
	{
		if(list[e].id > 0)
		{
			for(int r = 0; r < largoReparacion; r++)
			{
				if(listaReparacion[r].id > 0 && listaReparacion[r].idServicio == 20003)
				{
					contador ++;
				}
			}
		}
		arrayContadores[e] = contador;
		arrayID[e] = list[e].idMarca;
	}

	for(int m = 0; m < largoElectro; m++)
	{
		if(flag == 0)
		{
			auxIDMarca = arrayID[m];
			maxMarca = arrayContadores[m];
			flag = 1;
		} else if (maxMarca < arrayContadores[m] && flag != 0)
		{
			auxIDMarca = arrayID[m];
			maxMarca = arrayContadores[m];
			}
		}
	     cargarDescripcionMarca(listaMarca, largoMarca, auxIDMarca, descMarca);
	     printf("La Marca con mayor refacciones es %s\n", descMarca);
}

//12- Listar los Electrodomésticos que recibieron reparación en un fecha determinada
void mostrarElectrosxFechaReparacion (Electro *listaElectro, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion)
{
	Reparacion auxReparacion;
	int flag = 0;

	utn_getInt(&auxReparacion.fechaReparacion.anio, "Ingrese el anio (2000 al 2020): \n","ERROR. ANIO INVALIDO\n",2000, 2020, 7);
	utn_getInt(&auxReparacion.fechaReparacion.mes, "Ingrese el numero del Mes (1 al 12): \n", "ERROR. MES INVALIDO\n", 1, 12, 7);
	utn_getInt(&auxReparacion.fechaReparacion.dia, "Ingrese el dia (1 al 31): \n", "ERROR. DIA INVALIDO\n", 1, 31, 7);

	for (int r = 0; r < largoReparacion; r++)
	{
		if(listaReparacion[r].id > 0 && auxReparacion.fechaReparacion.anio == listaReparacion[r].fechaReparacion.anio && auxReparacion.fechaReparacion.mes == listaReparacion[r].fechaReparacion.mes && auxReparacion.fechaReparacion.dia == listaReparacion[r].fechaReparacion.dia)
		{
			for(int e = 0; e < largoElectro; e++)
			{
				if(listaReparacion[r].serie == listaElectro[e].serie)
				{
				 listarElectro(listaElectro[e], listaMarca, largoMarca);
				 flag = 1;
				}
			}
		}
	}
	if(flag == 0)
	{
		printf("No se registro una reparacion con la Fecha %d/%d/%d\n",auxReparacion.fechaReparacion.dia, auxReparacion.fechaReparacion.mes, auxReparacion.fechaReparacion.anio);
	}
}

int menuInformes()
{
	int opcion;

	printf("1 - Mostrar Electros segun Modelo (2020)\n");
	printf("2 - Mostrar Electros segun una Marca\n");
	printf("3 - Mostrar Reparaciones segun Electro\n");
	printf("4 - Mostrar Electros sin Reparaciones\n");
	printf("5 - Mostrar Suma de Importes de Reparaciones Segun Electro\n");
	printf("6 - Mostrar Servicio mas elegido\n");
	printf("7 - Mostrar Recaudacion Segun Fecha\n");
	printf("8 - Mostrar Electros con Garantia y Fecha\n");
	printf("9 - Mostrar Reparaciones de Electros con Modelo 2018\n");
	printf("10- Mostrar Suma Total de Mantenimiento\n");
	printf("11- Mostrar Marcas con mas refacciones\n");
	printf("12- Mostrar Electros segun Fecha de Reparacion\n");
	fflush(stdin);
	utn_getInt(&opcion,"Elija una opcion: \n", "ERROR. OPCION INVALIDA\n", 1, 12, 7);
	return opcion;
}
