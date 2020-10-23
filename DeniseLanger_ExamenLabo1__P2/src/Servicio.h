#ifndef SERVICIO_H_
#define SERVICIO_H_
#define LONG_DESCRIPTION 25

typedef struct
{	int id; //Arranca en 20k
	char descripcion [LONG_DESCRIPTION];
	float precio;
} Servicio;

/**
 * @brief : Muestra un solo Servicio
 *
 * @param list: Array de estructuras de Servicio
 */
void listarServicio (Servicio list);

/**
 * @brief: Muestra todos los servicios registrados
 *
 * @param list: Array de estructuras de Servicio
 * @param largoArray: largo de array Servicio
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarServicios (Servicio *list, int largoArray);

/**
 * @brief : Muestra el nombre del servicio al ingresar el ID
 *
 * @param list: Array de estructuras de Servicio
 * @param largoArray: largo de array Servicio
 * @param idMarca: ID del Servicio
 * @param descripcion: Array de char para guardar el nombre del servicio
 * @return: -1 en caso de error o 0 en caso de ok
 */
int cargarDescripcionServicio(Servicio *list, int largoArray, int idServicio, char descripcion[]);


#endif /* SERVICIO_H_ */
