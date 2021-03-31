/** 
 * @brief Define el inventario del jugador
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

#define MAX_OBJECTS 15 /*Numero maximo de objetos que puede llevar el jugador*/

/**
 * @brief crea el inventario del jugador
 *
 * inventory_create crea el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param id 
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
 * @param inventary el inventario a destruir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_destroy(Inventory* inventory);

/**
 * @brief añade al inventario del jugador un elemento
 *
 * inventory_setObject añade al inventario del jugador un elemento
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventary el inventario y el Id del elemento
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_setObject (Inventory *inventory , Id id);


/**
 * @brief devuelve el inventario
 *
 * inventory_getInventory delvuelve el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventary el inventario 
 * @return los ids de los objetos
 */
Id* inventory_getInventory (Inventory *inventory);

/**
 * @brief printea el inventario
 *
 * inventory_print printea el inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventary el inventario y un puntero a un FILE
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_print (Inventory *inventory , FILE *pf);


/**
 * @brief elimina un objeto
 *
 * inventory_deleteObject elmina un objecto del inventario del jugador
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventary el inventario y el id del elemento
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS inventory_deleteObject (Inventory* inventory , Id id);


/**
 * @brief chequea si la mochila esta vacia
 *
 * inventory_isEmpty chequea si la mochila del jugador esta vacia
 * 
 * @date 30-03-2021
 * @author Gonzalo Martín
 *
 * @param inventary el inventario
 * @return TRUE si esta vacia, FALSE si no lo esta
 */
BOOL inventory_isEmpty (Inventory * inventory);

#endif
