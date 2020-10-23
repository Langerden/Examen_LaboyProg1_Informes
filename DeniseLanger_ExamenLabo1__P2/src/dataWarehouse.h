#include "Electro.h"
#include "Reparacion.h"

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_


/**
 * @brief : Hardcodea los datos de los campos de Electro y Reparacion
 *
 * @param electro: Array de estructuras de Electro
 * @param largoElectro: largo del array electro
 * @param reparacion: Array de estructuras de Reparacion
 * @param largoReparacion: largo de array reparacion
 * @param flag: puntero a un flag
 * @return retorna 0 en caso de error y 1 en caso de salir ok
 */


int hardcodearDatos(Electro *electro, int largoElectro, Reparacion *reparacion, int largoReparacion, Cliente *cliente, int largoCliente, int *flag);

#endif /* DATAWAREHOUSE_H_ */
