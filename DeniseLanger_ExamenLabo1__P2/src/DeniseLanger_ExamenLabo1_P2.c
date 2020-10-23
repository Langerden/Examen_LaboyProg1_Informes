/*
 ============================================================================
 Name        : DeniseLanger_ExamenLabo1_P2.c
 Author      : Denise Langer
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_getDato.h"
#include "Electro.h"
#include "Reparacion.h"
#include "Informes.h"
#include "dataWarehouse.h"


#define LARGO_MARCA 5
#define LARGO_SERVICIO 4
#define HARCOARRAY 10

int main(void)
{
	setbuf(stdout, NULL);
	int IDElectro;
	int IDReparacion;
	int datoUser;
	int flagMenu = 0;
	char salir = 'N';


	Marca arrayMarca [LARGO_MARCA] = {{1000,"Gafa"},{1001,"Liliana"},{1002,"Philips"},{1003,"Sony"},{1004,"Whirpool"}};
	Servicio arrayServicio [LARGO_SERVICIO] = {{20000,"Garantia",250},{20001,"Mantenimiento",500},{20002,"Repuestos",400},{20003,"Refaccion",600}};
	Electro arrayElectro [HARCOARRAY];
	Reparacion arrayReparacion [HARCOARRAY];
	Cliente arrayCliente [HARCOARRAY] = {{50,"Claudia","Lopez"},{51,"Ricardo","Gonzalez"},{52,"Ana","Perez"}, {53,"Juan","Alvarez"},{54,"Pedro","Juarez"},{55,"Facundo","Oliva"},{56,"Carolina", "Aguilera"},{57,"Julieta", "Aranda"},{58,"Marcelo","Escobar"},{59,"Alejandro","Nuniez"}};

	//NO HARDCODEO
	IDElectro = 1;
	IDReparacion = 1;


	//SI HARDCODEO
	//IDElectro = 11;
	//IDReparacion = 11;

	// inicializar las listas
	initElectro(arrayElectro, HARCOARRAY);
	initReparacion(arrayReparacion, HARCOARRAY);

	// SI HARD
	//hardcodearDatos(arrayElectro, HARCOARRAY, arrayReparacion, HARCOARRAY, arrayCliente, HARCOARRAY, &flagMenu);
	do{
		switch(menu())
		{
			case 'A': 	//Alta Electro
				if(cargarElectro(arrayElectro, HARCOARRAY, &IDElectro, arrayMarca, LARGO_MARCA))
				{
					flagMenu++;
				}
				break;
			case 'B': //Modificar Electro - Ingresar ID y modificar Serie y Modelo
				if(flagMenu)
				{
					modificarElectro(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA);
				} else {
					printf("Se debe dar de alta una Electro primero\n");
				}
				break;
			case 'C': //Bajar Electro - Ingresar ID y se hace una baja logica
				if(flagMenu)
				{
					listarElectros(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA);
					utn_getInt(&datoUser, "Ingrese el ID a eliminar: \n", "ERROR. ID INVALIDO\n", 1, 10, 7);
					if(eliminarIDElectro(arrayElectro, HARCOARRAY, datoUser, arrayMarca, LARGO_MARCA) != -1)
					{
						flagMenu--;
					}
				} else {
					printf("Se debe dar de alta una Electro primero\n");
				}
				break;
			case 'D': //Listar Electros - Mostrar ordenando por Modelo y Serie
				if(flagMenu)
				{
					ordenarElectro(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA);
				} else {
					printf("Se debe dar de alta una Electro primero\n");
				}
				break;
			case 'E': //Listar Marcas
				listarMarcas(arrayMarca, LARGO_MARCA);
				break;
			case 'F': //Listar Servicios
				listarServicios(arrayServicio, LARGO_SERVICIO);
				break;
			case 'G': //Alta Reparacion - se da de alta cada Reparacion pidiendo elegir una Electro y un servicio
				if(flagMenu)
				{
					altaReparacion(arrayReparacion, HARCOARRAY, &IDReparacion, arrayElectro, HARCOARRAY, arrayServicio, LARGO_SERVICIO, arrayMarca, LARGO_MARCA,arrayCliente,HARCOARRAY);
				} else {
					printf("Se debe dar de alta una Electro primero\n");
				}
				break;
			case 'H': //Listar Reparaciones
				if(IDReparacion == 1)
				{
					printf("Se debe registrar una reparacion primero\n");
				} else {
					listarReparaciones(arrayReparacion, HARCOARRAY, arrayServicio, LARGO_SERVICIO, arrayCliente,HARCOARRAY);
				}
				break;
			case 'I': //Informes
				if (flagMenu)
				{
				switch(menuInformes())
				{
					case 1:
						mostrarElectroSegunModelo2020(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA);
						break;
					case 2:
						mostrarElectroSegunMarca(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA);
						break;
					case 3:
						mostrarReparacionSegunElectro(arrayElectro, HARCOARRAY, arrayReparacion, HARCOARRAY,arrayMarca, LARGO_MARCA, arrayServicio, LARGO_SERVICIO, arrayCliente, HARCOARRAY);
						break;
					case 4:
						mostrarElectrosSinReparacion(arrayElectro, HARCOARRAY, arrayReparacion, HARCOARRAY, arrayMarca, LARGO_MARCA, arrayServicio, LARGO_SERVICIO, arrayCliente, HARCOARRAY);
						break;
					case 5:
						sumarServiciosxElectro(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA, arrayReparacion, HARCOARRAY, arrayCliente, HARCOARRAY, arrayServicio, LARGO_SERVICIO);
						break;
					case 6:
						mostrarServicioMasElegido(arrayServicio, LARGO_SERVICIO, arrayReparacion, HARCOARRAY);
						break;
					case 7:
						mostrarTotalServiciosxFecha(arrayServicio, LARGO_SERVICIO, arrayReparacion, HARCOARRAY, arrayCliente, HARCOARRAY);
						break;
					case 8:
						mostrarElectrosGarantiayFecha(arrayElectro, HARCOARRAY, arrayReparacion, HARCOARRAY, arrayMarca, LARGO_MARCA);
						break;
					case 9:
						mostrarReparacionesModelo2018(arrayElectro, HARCOARRAY, arrayReparacion, HARCOARRAY, arrayServicio, LARGO_SERVICIO, arrayCliente, HARCOARRAY);
						break;
					case 10:
						mostrarTotalMantenimientos(arrayReparacion, HARCOARRAY, arrayServicio, LARGO_SERVICIO);
						break;
					case 11:
						mostrarMarcaMasRefacciones(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA, arrayReparacion, HARCOARRAY);
						break;
					case 12:
						mostrarElectrosxFechaReparacion(arrayElectro, HARCOARRAY, arrayMarca, LARGO_MARCA, arrayReparacion, HARCOARRAY);
						break;
				}
				} else {
					printf("Se debe registrar un Electro como minimo para mostrar Informes\n");
				}
				break;
			case 'J': //Exit
				utn_getChar(&salir, "¿Desea salir? (Y / N): \n", "ERROR. Opcion invalida\n", 'N', 'Y', 7);
				if(salir == 'Y')
				{
					return EXIT_SUCCESS;
				}
		}
		system("pause");
		system("cls");
	}while (salir == 'N');
	return EXIT_SUCCESS;
}
