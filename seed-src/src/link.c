/** 
 * @brief Define los enlaces entre espacios
 * 
 * @file link.c
 * @author Alberto Vicente
 * @version 1.0 
 * @date 11-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"
#include "types.h"

/**
 * @brief Define la estructura de los enlaces
 * 
 * Estructura del link
 */
struct _Link{

    Id id;     /*!< Id del link */
    char name [WORD_SIZE +1]; /*!< Nombre del link */
    Id from; /*!< Id donde empieza */
    Id to; /*!< Id donde acaba */
    TYPES type; /*!< Tipo de link */
};

Link* link_create(Id id){
    Link *l=NULL;
    
    if(!id) return NULL;

    l= (Link*) malloc (sizeof(Link));
    if(!l) return NULL;

    l->id=id;
    l->name[0]='\0';
    l->from=NO_ID;
    l->to=NO_ID;
    l->type=CLOSE;

    return  l;
}

STATUS link_destroy(Link *l){
    
    if(!l)return ERROR;
    
    free(l);

    return OK;
}

Id link_get_id(Link *l){
    if(!l)return NO_ID;

    return l->id;
}

char *link_get_name(Link *l){
    if(!l)return NULL;

    return l->name;
}

Id link_get_id_from(Link *l){
    if(!l)return NO_ID;

    return l->from;
}

Id link_get_id_to(Link *l){
    if(!l)return NO_ID;

    return l->to;
}

TYPES link_get_type(Link *l){
    if(!l)return CLOSE;
    return l->type;
}

STATUS link_set_id(Link *l, Id id){
    if(!l || !id)return ERROR;
    if(id == NO_ID) return ERROR;

    l->id=id;

    return OK;
}

STATUS link_set_name(Link *l, char *name){
    if(!l || !name)return ERROR;

    strcpy(l->name,name);
    if(!l->name)return ERROR;

    return OK;
}

STATUS link_set_id_from(Link *l, Id from){
    if(!l || !from)return ERROR;
    if(from == NO_ID) return ERROR;

    l->from=from;

    return OK;
}

STATUS link_set_id_to(Link *l, Id to){
    if(!l || !to)return ERROR;
    if(to == NO_ID) return ERROR;

    l->to=to;

    return OK;
}

STATUS link_set_type(Link *l, TYPES type){
    if(!l)return ERROR;

    l->type=type;

    return OK;
}


STATUS link_print(FILE *pf, Link *l){
    if(!l || !pf)return ERROR;

    fprintf(pf, "--> Link (Id: %ld; Name: %s; From: %ld; To: %ld; Type: %d)\n", l->id, l->name, l->from, l->to, l->type);

    return OK;
}
