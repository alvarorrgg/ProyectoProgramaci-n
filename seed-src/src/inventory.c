#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "set.h"
#include "types.h"

struct _Inventory{
    Set *objects;
    int Max_Objets;
};


Inventory* inventory_create(){
    Inventory *new_invetory = (Inventory*) malloc(sizeof(Inventory));    

    new_invetory->objects = set_create();
    new_invetory->Max_Objets = MAX_OBJECTS;

    return new_invetory;
}


STATUS inventory_destroy(Inventory* inventory){
    if (!inventory) return ERROR;
    STATUS st;

    st = set_destroy (inventory->objects);
    free (inventory);

    return st;
}


STATUS inventory_setObject (Inventory *inventory , Id id){
    if (!inventory  || id<0 || !id || set_get_total_ids(inventory->objects) >= inventory->Max_Objets) return ERROR;
    STATUS st;

    st = set_id_add (inventory->objects , id);

    return st;
}


Id* inventory_getInventory (Inventory *inventory){
    if(!inventory) return NULL;

    return set_get_ids (inventory->objects);
}


STATUS inventory_print (Inventory *inventory , FILE *pf){
    if(! inventory || pf == NULL) return ERROR;
    STATUS st;

    st = set_print( pf , inventory->objects);

    return st;
}


STATUS inventory_deleteObject (Inventory* inventory , Id id){
    if(!inventory || !id || id<0 || inventory_isEmpty(inventory) == TRUE || set_has_id(inventory->objects , id) == FALSE) return ERROR;
    STATUS st;

    st = set_id_delete (inventory->objects , id);

    return st;
}

BOOL inventory_isEmpty (Inventory * inventory){
    if(!inventory) return ERROR;

    if(set_is_empty (inventory->objects) == TRUE) return TRUE;

    return FALSE;   
}