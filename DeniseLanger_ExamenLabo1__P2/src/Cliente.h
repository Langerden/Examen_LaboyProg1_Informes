/*
 * Cliente.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Lange
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define LONG_CHAR 20

typedef struct
{	int id;
	char nombre [LONG_CHAR];
	char apellido [LONG_CHAR];
} Cliente;


/**
 * @brief : Muestra el nombre y el apellido del cliente al ingresar el ID
 *
 * @param list: Array de estructuras de Clientes
 * @param largoArray: largo de array Clientes
 * @param idCliente: ID del cliente
 * @param nombre: Array de char para guardar el nombre del cliente
 * @param apellido: Array de char para guardar el apellido del cliente
 * @return: -1 en caso de error o 0 en caso de ok
 */
int cargarDescripcionCliente(Cliente *list, int largoArray, int idCliente, char nombre[], char apellido[]);

/**
 * @brief: Busca la posicion dentro del array donde se encuentra el ID buscado
 *
 * @param list: Array de estructuras de Cliente
 * @param largoCliente: largo de array Cliente
 * @param idCliente: numero de ID que se quiere encontrar
 * @return: -1 en caso de error o el indice del array donde esta el ID cargado
 */
int buscarClientePorID(Cliente* list, int largoCliente,int idCliente);

/**
 * @brief Imprime los campos de un solo cliente
 *
 * @param list: Array de estructuras de Cliente
 */
void listarCliente(Cliente list);

/**
 * @brief: Muestra todos los clientes
 *
 * @param list: Array de estructuras de Clientes
 * @param largoArray: largo de array Clientes
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarClientes(Cliente* list, int largoArray);

#endif /* CLIENTE_H_ */
