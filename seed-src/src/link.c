/** 
 * @brief Define los enlaces entre espacios
 * 
 * @file link.h
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

struct _Link{
    Id id;
    char name [WORD_SIZE +1];
    Id from;
    Id to;
    TYPES type;
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

Id link_getId(Link *l){
    if(!l)return NO_ID;

    return l->id;
}

char *link_getName(Link *l){
    if(!l)return NULL;

    return l->name;
}

Id link_getIdFrom(Link *l){
    if(!l)return NO_ID;

    return l->to;
}

Id link_getTo(Link *l){
    if(!l)return NO_ID;

    return l->to;
}

TYPES link_getType(Link *l){
    if(!l)return CLOSE;

    return l->type;
}

STATUS link_setId(Link *l, Id id){
    if(!l || !id)return ERROR;

    l->id=id;

    return OK;
}

STATUS link_setName(Link *l, char *name){
    if(!l || !name)return ERROR;

    strcpy(l->name,name);
    if(!l->name)return ERROR;

    return OK;
}

STATUS link_setIdFrom(Link *l, Id from){
    if(!l || !from)return ERROR;

    l->from=from;

    return OK;
}

STATUS link_setIdTo(Link *l, Id to){
    if(!l || !to)return ERROR;

    l->to=to;

    return OK;
}

STATUS link_setType(Link *l, TYPES type){
    if(!l || !type)return ERROR;

    l->type=type;

    return OK;
}

STATUS link_print(Link *l){
    if(!l)return ERROR;

    fprintf(stdout, "--> Link (Id: %ld; Name: %s; From: %ld; To: %ld; Type: %d)\n", l->id, l->name, l->from, l->to, l->type);

    return OK;
}