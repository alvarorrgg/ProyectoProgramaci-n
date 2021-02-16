/** 
 * @brief Define un espacio
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Licencia Pública
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

/**
 * @brief Define un espacio
 * 
 * Estructura de espacio
 */
typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

Space* space_create(Id id);
STATUS space_destroy(Space* space);
Id space_get_id(Space* space);
STATUS space_set_name(Space* space, char* name);
const char* space_get_name(Space* space);
STATUS space_set_north(Space* space, Id id);
Id space_get_north(Space* space);
STATUS space_set_south(Space* space, Id id);
Id space_get_south(Space* space);
STATUS space_set_east(Space* space, Id id);
Id space_get_east(Space* space);
STATUS space_set_west(Space* space, Id id);
Id space_get_west(Space* space);
STATUS space_set_object(Space* space, BOOL value);
BOOL space_get_object(Space* space);
STATUS space_print(Space* space);

#endif
