/** 
 * @brief Archivo cabecera de set.c en el se encuentra definidas los datos y funciones de set.c
 * 
 * @file set.h
 * @author Álvaro Rodríguez
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */
 #ifndef SET_H
#define SET_H
#include "types.h"
#define MAX_IDS 100 /*!<Numero maximo de ids*/

/**
 * @brief Estructura set
 *
 * contiene las variables del conjunto de objetos
 */
typedef struct _Set Set;
/**
 * @brief Crea un set
 *
 * set_create inicializa el set y sus parametros
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
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
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set.
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_destroy(Set* set);
/**
 * @brief añade al set un id
 *
 * set_id_add añade un id nuevo al array de ids
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set y el id que se va a añadir.
 * @param id recibe el id a añadir
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_id_add(Set* set,Id id);
/**
 * @brief elimina un id del set
 *
 * set_id_delete elimina un id almacenado en el array de ids
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set y un id para encontrar el objeto a eliminar.
 * @param id recibe el id a borrar
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_id_delete(Set* set,Id id);
/**
 * @brief cambia el numero total de ids
 *
 * set_set_total_ids modifica el numero de ids totales de la estructura
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set y un entero que será el numero de ids.
 * @param n nuevo numero de ids
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_set_total_ids(Set* set,int n);
/**
 * @brief obtiene el numero total de ids
 *
 * set_get_total_ids sirve para conseguir los ids de la estructura
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set.
 * @return devuelve un entero con el numero total de ids.
 */
int set_get_total_ids(Set* set);
/**
 * @brief verifica si la estructura tiene al id.
 *
 * set_has_id sirve para ver si la estructura de datos tiene el objeto.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set y un id.
 * @param id para verificar si lo tienen
 * @return devuelve TRUE si lo tiene y FALSE si no lo tiene o hay algun error
 */
BOOL set_has_id(Set* set, Id id);
/**
 * @brief ubica un objeto en un array
 *
 * set_find_object_by_id encuentra la posición de un objeto en el array
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set y el id del objeto a encontrar.
 * @param id para encontrar un objeto
 * @return devuelve un entero con la posición del entero en el array.
 */
int set_find_object_by_id(Set* set, Id id);
/**
 * @brief verifica si un set esta vacio
 *
 * set_is_empty sirve para ver si el set esta vacio
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set.
 * @return devuelve TRUE si esta vacio o FALSE si no lo está o hay algun error.
 */
BOOL set_is_empty(Set* set);
/**
 * @brief verifica si un set esta lleno
 *
 * set_is_empty sirve para ver si el set esta lleno
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set.
 * @return devuelve TRUE si esta lleno o FALSE si no lo está o hay algun error.
 */
BOOL set_is_full(Set* set);
/**
 * @brief obtiene los ids del set
 *
 * set_get_ids sirve para ver que ids hay en el set
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param set recibe un puntero a set.
 * @return devuelve NULL en caso de error, sino devuelve los ids del set.
 */
Id* set_get_ids(Set *set);

/**
 * @brief Muestra por pantalla las caracteristicas del set
 *
 * set_print muestra los valores de los parametros del set
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param pf recive el fichero en el que se mostrarán los parametros yun puntero a set.
 * @param set recibe un puntero a set
 * @return devuelve ERROR o OK según si se encuentra o no algun fallo
 */
STATUS set_print(FILE *pf, const Set *set);
#endif
