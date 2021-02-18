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
