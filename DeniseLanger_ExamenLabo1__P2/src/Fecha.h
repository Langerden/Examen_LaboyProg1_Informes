
#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{	int dia;
	int mes;
	int anio;
} Fecha;

/**
 * @brief : Muestra una sola Fecha
 *
 * @param list: Array de estructuras de Fecha
 */
void listarFecha (Fecha list);

/**
 * @brief: Muestra todas las fechas registradas
 *
 * @param list: Array de estructuras de Fecha
 * @param largoArray: largo de array Fecha
 * @return: -1 en caso de error o 0 en caso de ok
 */
int listarFechas (Fecha *list, int largoArray);








#endif /* FECHA_H_ */
