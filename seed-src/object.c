/** 
 * @brief Implementa la estructura de datos abstractos Object, y las funciones que estan relacionadas con esta.
 * 
 * @file object.c
 * @author R1
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "object.h"
/**
 * @brief La estructura Object
 *
 * Almacena información del objeto.
 */
struct _Object {
  Id id;
  char name[WORD_SIZE + 1];
};
/**
 * @brief Crea un objeto
 *
 * object_create crea un objeto y le da atributos sin valor, es la inicialización del objeto.
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un tipo id que es equivalente a recibir un long
 * @return devuelve un puntero a objeto, NULL en caso de detectar algun error.
 */
Object* object_create(Id id) {

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}
/**
 * @brief Destruye un objeto
 *
 * object_destroy destruye un objeto y todo lo relacionado con este, tanto su id como su nombre.
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a la estructura de datos objeto
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error.
 */

STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}
/**
 * @brief Obtiene el id de un objeto
 *
 * object_get_id sirve para obtener el id de un objeto.
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a la estructura de datos objeto
 * @return devuelve el id del objeto
 */
Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}
/**
 * @brief Nombrar a un objeto
 *
 * object_set_name sirve para cambiar el nombre del objeto
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a la estructura de datos objeto
 * @param recibe el nombre que se le va a poner al objeto.
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}
/**
 * @brief Obtiene el nombre del objeto
 *
 * object_get_name sirve para obtener el nombre de un objeto.
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a la estructura de datos objeto
 * @return devuelve el nombre del objeto
 */
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}
/**
 * @brief Escribe los atributos del objeto
 *
 * object_print sirve para escribir los atributos de el objeto como su id o su nombre.
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param recibe un puntero a la estructura de datos objeto
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
STATUS object_print(Object* object) {
  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  return OK;
}

