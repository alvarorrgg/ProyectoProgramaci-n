/** 
 * @brief Archivo cabecera del modulo set.h, en el se define la estructura de datos Object y sus funciones.
 * 
 * @file set.h
 * @author R1
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */
 #ifndef SET_H
#define SET_H


typedef struct _Set Set;
/**
 * @brief Crea un set
 *
 * set_create inicializa el set y sus parametros
 *
 * @date 18-02-2021
 * @author R1
 *
 * @return devuelve un puntero a set, NULL en el caso de detectar algún error.
 */
Set* set_create();
/**
 * @brief Borra el set
 *
 * set_destroy destruye el set y libera la memoria utilizada por este
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a set.
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_destroy(Set* set);
/**
 * @brief añade al set un id
 *
 * set_id_add añade un id nuevo al array de ids
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a set y el id que se va a añadir.
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_id_add(Set* set,Id id);
/**
 * @brief elimina un id del set
 *
 * set_id_delete elimina un id almacenado en el array de ids
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a set.
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_id_delete(Set* set);
/**
 * @brief Muestra por pantalla las caracteristicas del set
 *
 * set_destroy muestra los valores de los parametros del set
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recive el fichero en el que se mostrarán los parametros yun puntero a set.
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_print(FILE *pf, const Set *set);
#endif
