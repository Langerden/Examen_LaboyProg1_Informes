#ifndef INFORMES_H_
#define INFORMES_H_
#include "Electro.h"
#include "Reparacion.h"
#include "Cliente.h"


/**
 * @brief Muestra los electros con Modelo 2020
 *
 * @param list: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaMarca: Array de Estructuras de Marca
 * @param largoMarca: largo de array Marca
 */
void mostrarElectroSegunModelo2020 (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca);

/**
 * @brief Muestra los Electros segun la marca elegida
 *
 * @param list: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaMarca: Array de Estructuras de Marca
 * @param largoMarca: largo de array Marca
 */
void mostrarElectroSegunMarca (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca);
/**
 * @brief Muestra todos las reparaciones efectuadas al Electrodoméstico seleccionado
 *
 * @param listElectro: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de array Reparacion
 * @param listMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 * @param listServicio: Array de Estructuras Servicio
 * @param largoServicio: largo de array Servicio
 * @param listCliente: Array de Estructuras Cliente
 * @param largoCliente: largo de array Cliente
 */
void mostrarReparacionSegunElectro (Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Marca *listMarca, int largoMarca, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente);
/**
 * @brief Muestra los Electrodomésticos que no tuvieron reparaciones
 *
 *
 * @param listElectro: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 * @param listServicio: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 * @param listCliente: Array de Estructuras Cliente
 * @param largoCliente: largo de array Cliente
 */
void mostrarElectrosSinReparacion(Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Marca *listMarca, int largoMarca, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente);
/**
 * @brief Informa importe total de las reparaciones realizadas a un Electrodoméstico seleccionado
 *
 * @param listaElectro: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 * @param listReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listServicio: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 * @param listCliente: Array de Estructuras Cliente
 * @param largoCliente: largo de array Cliente
 */
void sumarServiciosxElectro (Electro *listaElectro, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion, Cliente *listaCliente, int largoCliente, Servicio *listaServicio, int largoServicio);

/**
 * @brief Muestra el servicio más pedido
 *
 * @param lista: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 * @param listReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 */
void mostrarServicioMasElegido (Servicio *lista, int largoServicio, Reparacion *listaReparacion, int largoReparacion);
/**
 * @brief Muestra la recaudación en una fecha en particular
 *
 * @param listaServicio: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listCliente: Array de Estructuras Cliente
 * @param largoCliente: largo de array Cliente
 */
void mostrarTotalServiciosxFecha (Servicio *listaServicio, int largoServicio, Reparacion *listaReparacion, int largoReparacion, Cliente *listaCliente, int largoCliente);
/**
 * @brief  Muestra todos los Electrodomésticos que realizaron una garantía y la fecha
 *
 * @param listaElectro: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listaMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 */
void mostrarElectrosGarantiayFecha (Electro *listaElectro, int largoElectro, Reparacion *listaReparacion, int largoReparacion, Marca *listaMarca, int largoMarca);
/**
 * @brief Muestra los Trabajos realizados a Electrodomésticos del año(modelo) 2018
 *
 * @param listaElectro: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listaServicio: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 * @param listCliente: Array de Estructuras Cliente
 * @param largoCliente: largo de array Cliente
 */
void mostrarReparacionesModelo2018 (Electro *listElectro, int largoElectro, Reparacion *listReparacion, int largoReparacion, Servicio *listServicio, int largoServicio, Cliente *listCliente, int largoCliente);
/**
 * @brief Muestra la facturación total por los mantenimientos
 *
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 * @param listaServicio: Array de Estructura Servicio
 * @param largoServicio: largo de array Servicio
 */
void mostrarTotalMantenimientos(Reparacion *listaReparacion, int largoReparacion, Servicio *listaServicio, int largoServicio);

/**
 * @brief Informa la marca de Electrodomésticos que efectuaron más refacciones
 *
 * @param list: Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 */
void mostrarMarcaMasRefacciones (Electro *list, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion);

/**
 * @brief Lista los Electrodomésticos que recibieron reparación en un fecha determinada
 *
 * @param listaElectro:Array de Estructuras Electro
 * @param largoElectro: largo de array Electro
 * @param listaMarca: Array de Estructuras Marca
 * @param largoMarca: largo de array Marca
 * @param listaReparacion: Array de Estructuras Reparacion
 * @param largoReparacion: largo de arrayReparacion
 */
void mostrarElectrosxFechaReparacion (Electro *listaElectro, int largoElectro, Marca *listaMarca, int largoMarca, Reparacion *listaReparacion, int largoReparacion);

/**
 * @brief Muestra el SubMenu de Informes
 *
 * @return la opcion que ingresa el usuario
 */
int menuInformes();








#endif /* INFORMES_H_ */
