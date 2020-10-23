#ifndef Reparacion_H_
#define Reparacion_H_
#include "Fecha.h"
#include "Servicio.h"
#include "Cliente.h"

typedef struct
{	int id;
	int serie;
	int idServicio;
	int idCliente;
	Fecha fechaReparacion;
} Reparacion;

/**
 * @brief: Inicializa el Array de Reparacion en 0
 *
 * @param list: Array de estructuras de Reparacion
 * @param largoArray: largo de array Reparacion
 * @return: -1 en caso de error o 0 en caso de ok
 */
int initReparacion(Reparacion *list, int largoArray);

/**
 * @brief: Muestra los datos de una sola reparacion
 *
 * @param list: Array de estructuras de Reparacion
 * @param listaServicio: Array de estructuras de Servicio
 * @param largoServicio: largo de array Servicio
 * @param listaCliente:Array de estructuras de Cliente
 * @param largoCliente: largo de array Cliente
 */
void listarReparacion (Reparacion list, Servicio *listaServicio, int largoServicio, Cliente *listaCliente, int largoCliente);

/**
 * @brief: Muestra todos los electros registrados en el Array
 *
 * @param list: Array de estructuras de Reparacion
 * @param largoArray: largo de array Reparacion
 * @param listaServicio: Array de estructuras de Servicio
 * @param largoServicio: largo de array Servicio
 * @param listaCliente:Array de estructuras de Cliente
 * @param largoCliente: largo de array Cliente
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarReparaciones (Reparacion *list, int largoArray, Servicio *listaServicio, int largoServicio, Cliente *listaCliente, int largoCliente);

/**
 *@brief: Busca un indice sin datos registrados
 *
 *@param list: Array de estructuras de Reparacion
 *@param largoArray: largo de array Reparacion
 *@return: -1 en caso de error o el indice del array vacio
 */
int buscarReparacionLibre(Reparacion *list, int largoArray);

/**
 * @brief : Registrar un trabajo realizado relacionado con el ID de Electro
 *
 * @param list: Array de estructuras de Reparacion
 * @param largoArray: largo de array Reparacion
 * @param IDReparacion: puntero a un int para registrar con un ID el trabajo realizado
 * @param listElectro: Array de estructuras de Electro
 * @param largoElectro: largo de array Electro
 * @param listServ: Array de estructuras de Servicio
 * @param largoServicio: largo de array Servicio
 * @param listaMarca:  Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @param listaCliente:Array de estructuras de Cliente
 * @param largoCliente: largo de array Cliente
 * @return -1 en caso de error o 1 en caso de ok
 */
int altaReparacion (Reparacion *list, int largoArray, int *IDReparacion, Electro *listElectro, int largoElectro, Servicio *listServ, int largoServicio, Marca *listaMarca, int largoMarca, Cliente *listaCliente, int largoCliente);

#endif /* Reparacion_H_ */
