/** 
 * @brief Se encarga de definir el modulo inventario que sirve para recoger varios objetos
 * 
 * @file inventory.c
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "set.h"
#include "types.h"

/**
 * @brief Define el inventario del jugador
 * 
 * Estructura de espacio
 */
struct _Inventory{
    Set *objects; /*!< Puntero a la estructura Set*/
    int Max_Objets; /*!< Numero maximo de objetos*/
};


Inventory* inventory_create(){
    Inventory *new_invetory = NULL;
    new_invetory = (Inventory*) malloc(sizeof(Inventory));    
    if(!new_invetory) return NULL;

    new_invetory->objects = set_create();
    if(!new_invetory->objects) return NULL;

    new_invetory->Max_Objets = MAX_OBJECTS;

    return new_invetory;
}


STATUS inventory_destroy(Inventory* inventory){
    STATUS st;
    if (!inventory) return ERROR;
 

    st = set_destroy (inventory->objects);
    free (inventory);

    return st;
}


STATUS inventory_set_object (Inventory *inventory , Id id){
     STATUS st;
    if (!inventory  || id<0 || !id || id == NO_ID||inventory_is_full (inventory) == TRUE) {
        return ERROR;
    }

    st = set_id_add (inventory->objects , id);

    return st;
}


Id* inventory_get_inventory (Inventory *inventory){
    if(!inventory) return NULL;

    return set_get_ids (inventory->objects);
}

int inventory_get_number_of_objects(Inventory *inventory){
    if(!inventory) return -1;
    return set_get_total_ids(inventory->objects);
}

STATUS inventory_print (Inventory *inventory , FILE *pf){
    STATUS st;
    if(! inventory || !pf ) return ERROR;
    

    st = set_print( pf , inventory->objects);

    return st;
}


STATUS inventory_delete_object (Inventory* inventory , Id id){
    STATUS st;
    if(!inventory || !id || id<0 || id == NO_ID||inventory_is_empty(inventory) == TRUE || set_has_id(inventory->objects , id) == FALSE) return ERROR;

    st = set_id_delete (inventory->objects , id);

    return st;
}

BOOL inventory_is_empty (Inventory * inventory){
    if(!inventory) return FALSE;

    if(set_is_empty (inventory->objects) == TRUE) return TRUE;

    return FALSE;   
}


BOOL inventory_is_full(Inventory* inventory){
    if(!inventory) return FALSE;

    if(set_get_total_ids (inventory->objects) == inventory->Max_Objets) return TRUE;

    return FALSE;
}

BOOL inventory_search_object (Inventory *inventory , Id id){
    if (!inventory || id == NO_ID || id < 0 || inventory_is_empty (inventory) == TRUE) return FALSE;

    if (set_has_id (inventory->objects , id) == TRUE) return TRUE;

    return FALSE;
}

STATUS inventory_set_max_objects (Inventory *inventory , int max){
    if(!inventory || max < 0 ) return ERROR;

    inventory->Max_Objets = max;

    return OK;
}


int inventory_get_max_objects (Inventory *inventory){
    if (!inventory) return -1;

    return inventory->Max_Objets;
}