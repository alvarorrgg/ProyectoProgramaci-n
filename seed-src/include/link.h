/** 
 * @brief Define los enlaces entre espacios
 * 
 * @file link.h
 * @author Alberto Vicente
 * @version 1.0 
 * @date 11-04-2021
 * @copyright GNU Public License
 */


#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link;

Link* link_create (Id id);

STATUS link_destroy(Link *l);

Id link_getId(Link *l);

char *link_getName(Link *l);

Id link_getIdFrom(Link *l);

Id link_getTo(Link *l);

TYPES link_getType(Link *l);

STATUS link_setId(Link *l, Id id);

STATUS link_setName(Link *l, char *name);

STATUS link_setIdFrom(Link *l, Id from);

STATUS link_setId(Link *l, Id to);

STATUS link_setType(Link *l, TYPES type);

STATUS link_print(Link *l);

#endif