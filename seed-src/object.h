/** 
 * @brief Archivo cabecera de la función object.h, en el se define la estructura de datos Object y sus funciones.
 * 
 * @file object.h
 * @author R1
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

#define MAX_OBJECTS 100
#define FIRST_OBJECT 1

Object* object_create(Id id);
STATUS object_destroy(Object* object);
Id object_get_id(Object* object);
STATUS object_set_name(Object* object, char* name);
const char* object_get_name(Object* object);
STATUS object_print(Object* object);

#endif
