/** 
 * @brief Archivo cabecera de inventory.c en el se encuentra definidas los datos y funciones de inventory.c
 * 
 * @file inventory.h
 * @author Gonzalo Martín
 * @version 1.0 
 * @date 30-03-2021
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

/**
 * @brief Define el inventario del jugador
 * 
 * Estructura de espacio
 */
typedef struct _Inventory Inventory;

#define MAX_OBJECTS 40 /*!<Numero maximo de objetos que puede llevar el jugador*/

/**
 * @brief crea el inventario del jugador
 *
 * inventory_create crea el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @return el inventario creado
 */
Inventory* inventory_create();

/**
 * @brief destruye el inventario
 *
 * inventory_destroy destruye el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario a destruir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_destroy(Inventory* inventory);

/**
 * @brief añade al inventario del jugador un elemento
 *
 * inventory_set_object añade al inventario del jugador un elemento
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario y el Id del elemento
 * @param id id del objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_set_object (Inventory *inventory , Id id);


/**
 * @brief devuelve el inventario
 *
 * inventory_get_inventory delvuelve el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario 
 * @return los ids de los objetos
 */
Id* inventory_get_inventory (Inventory *inventory);
/**
 * @brief devuelve el numero de objetos en el inventario
 *
 * inventory_get_number_of_objects devuelve el numero de objetos dentro del inventario
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario 
 * @return int el numero de objetos
 */
int inventory_get_number_of_objects(Inventory *inventory);
/**
 * @brief printea el inventario
 *
 * inventory_print printea el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario y un puntero a un FILE
 * @param pf puntero al archivo
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_print (Inventory *inventory , FILE *pf);


/**
 * @brief elimina un objeto
 *
 * inventory_delete_object elmina un objecto del inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario y el id del elemento
 * @param id id del objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_delete_object (Inventory* inventory , Id id);


/**
 * @brief chequea si la mochila esta vacia
 *
 * inventory_is_empty chequea si la mochila del jugador esta vacia
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario
 * @return TRUE si esta vacia, FALSE si no lo esta
 */
BOOL inventory_is_empty (Inventory * inventory);

/**
 * @brief chequea si la mochila esta llena
 *
 * inventory_is_full chequea si la mochila del jugador esta llena
 * 
 * @date 01-04-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario
 * @return TRUE si esta llena, FALSE si no lo esta
 */
BOOL inventory_is_full(Inventory* inventory);

/**
 * @brief chequea hay hay un cierto objecto en la mochila 
 *
 * inventory_serach_object chequea si hay un determinado objecto en la mochila del jugador
 * 
 * @date 01-04-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario y el Id del objeto a buscar
 * @param id del objeto
 * @return TRUE si esta el objeto en la mochila, FALSE si no lo esta
 */
BOOL inventory_search_object (Inventory *inventory , Id id);

/**
 * @brief establece el numero maximo de objectos 
 *
 * inventory_set_max_objects establece el numero maximo de objectos de la mochila
 * 
 * @date 01-04-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario y el nuevo numero maximo de objetos
 * @param max numero maximo de objetos
 * @return Ok si se ha establecido bien, ERROR si no fue asi
 */
STATUS inventory_set_max_objects (Inventory *inventory , int max);

/**
 * @brief devuelve el numero maximo de objectos 
 *
 * inventory_get_max_objects devuelve el numero maximo de objectos de la mochila
 * 
 * @date 01-04-2021
 * @author Gonzalo Martín
 *
 * @param inventory el inventario
 * @return el numero maximo de objectos que caben en la mochila, -1 si ha avido un error
 */
int inventory_get_max_objects (Inventory *inventory);



#endif
