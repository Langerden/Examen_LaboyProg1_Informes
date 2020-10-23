#ifndef Electro_H_
#define Electro_H_
#include "Marca.h"

typedef struct
{	int id;
	int serie;
	int idMarca;
	int idModelo;
} Electro;

/**
 * @brief: Muestra los datos de un solo Electro
 *
 * @param list: Array de estructuras de Electro
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 */
void listarElectro (Electro list, Marca *listaMarca, int largoMarca);

/**
 * @brief: Muestra todos los electros registrados en el Array
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarElectros (Electro *list, int largoArray, Marca *listaMarca, int largoMarca);

/**
 * @brief: Inicializa el Array de Electro en 0
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @return: -1 en caso de error o 0 en caso de ok
 */
int initElectro(Electro *list, int largoArray);

/**
 *@brief: Busca un indice sin datos registrados
 *
 *@param list: Array de estructuras de Electro
 *@param largoArray: largo de array Electro
 *@return: -1 en caso de error o el indice del array vacio
 */
int buscarIndiceLibre(Electro *list, int largoArray);
/**
 * @brief: Busca la posicion dentro del array donde se encuentra el ID buscado
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param ID: numero de ID que se quiere encontrar
 * @return: -1 en caso de error o el indice del array donde esta el ID cargado
 */
int buscarIDElectro(Electro *list, int largoArray, int ID);

/**
 * @brief : Registrar los datos de un Electro
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param nextID: ID de electro
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @return: 0 en caso de error o 1 en caso de ok
 */
int cargarElectro (Electro *list,int largoArray, int *nextID, Marca *listaMarca,int largoMarca);

/**
 * @brief: Editar algun campo de la estrucutra Electro
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @return: -1 en caso de error o 1 en caso de ok
' */
int modificarElectro(Electro *list, int largoArray, Marca *listaMarcas, int largoMarca);

/**
 * @brief: Elimina de forma logica un ID de electro
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param ID: ID que se quiere eliminar
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @return: -1 en caso de error o 1 en caso de ok
 */
int eliminarIDElectro(Electro *list, int largoArray,int ID, Marca *listaMarca, int largoMarca);

/**
 * @brief Burbujeo de Electro de manera DESC segun modelo y serie
 *
 * @param list: Array de estructuras de Electro
 * @param largoArray: largo de array Electro
 * @param listaMarca: Array de estructuras de Marca
 * @param largoMarca: largo de array Marca
 * @return: -1 en caso de error o 1 en caso de ok
 */
int ordenarElectro(Electro *list, int largoArray, Marca *listaMarca, int largoMarca);


#endif /* Electro_H_ */
