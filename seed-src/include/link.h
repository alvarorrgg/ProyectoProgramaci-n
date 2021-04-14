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
#define MAX_LINKS 100 /*!<Numero maximo de links*/
typedef struct _Link Link;

Link* link_create (Id id);

STATUS link_destroy(Link *l);

Id link_get_id(Link *l);

char *link_get_name(Link *l);

Id link_get_id_from(Link *l);

Id link_get_id_to(Link *l);

TYPES link_get_type(Link *l);

STATUS link_set_id(Link *l, Id id);

STATUS link_set_name(Link *l, char *name);

STATUS link_set_id_from(Link *l, Id from);

STATUS link_set_id_to(Link *l, Id to);

STATUS link_set_type(Link *l, TYPES type);

STATUS link_print(FILE *pf, Link *l);

#endif