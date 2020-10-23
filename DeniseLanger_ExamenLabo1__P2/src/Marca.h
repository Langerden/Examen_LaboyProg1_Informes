#ifndef MARCA_H_
#define MARCA_H_
#define LONG_DESC 20

typedef struct
{	int id; //Comienza en 1000
	char descripcion [LONG_DESC];
} Marca;

/**
 * @brief : Muestra una sola Marca
 *
 * @param list: Array de estructuras de Marca
 */
void listarMarca (Marca list);
/**
 * @brief: Muestra todas las marcas registradas
 *
 * @param list: Array de estructuras de Marcas
 * @param largoArray: largo de array Marca
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarMarcas (Marca *list, int largoArray);

/**
 * @brief : Muestra el nombre de la marca al ingresar el ID
 *
 * @param list: Array de estructuras de Marcas
 * @param largoArray: largo de array Marca
 * @param idMarca: ID de la Marca
 * @param descripcion: Array de char para guardar el nombre de la marca
 * @return: -1 en caso de error o 0 en caso de ok
 */
int cargarDescripcionMarca(Marca *list, int largoArray, int idMarca, char descripcion[]);

#endif /* MARCA_H_ */


