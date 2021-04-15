/** 
 * @brief Sirve para el manejo de objetos.
 * 
 * @file object.c
 * @author Álvaro Rodríguez
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

  Id id;			/*!< id del objeto*/
  char name[WORD_SIZE + 1];	/*!< nombre del objeto*/
  char description[LEN_DES]; /*!< descripción de cada objecto*/
};

Object* object_create(Id id) {

  Object *new_object = NULL;


  new_object = (Object *) malloc(sizeof (Object));

  if (!new_object) return NULL;
  
  new_object->id = id;
  new_object->name[0] = (char)0;
  
  return new_object;
}

STATUS object_destroy(Object* object) {
  if (!object) return ERROR;
  
  free(object);

  return OK;
}

Id object_get_id(Object* object) {
  if (!object) return NO_ID;
  
  return object->id;
}

STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) return ERROR;
  if (!strcpy(object->name, name)) return ERROR;
  
  return OK;
}

STATUS object_set_id(Object* object, Id id) {
  if (!object) {
    return ERROR;
  }

  object->id=id;
  return OK;
}

const char * object_get_name(Object* object) {
  if (!object) return NULL;
  
  return object->name;
}

const char* object_get_description(Object* object){
  if (!object) return NULL;

  return object->description;
}

STATUS object_set_description(Object* object , char* descr){
  if(!object || !descr ) return ERROR;

  if (!strcpy(object->description, descr)) return ERROR;

  return OK;
}


 Id object_get_id_by_name (Object *object , char *name){
  if (!object || !name) return -1;

  if (strcmp (name , object_get_name (object)) == 0) return object->id;

  return -1;

 }

STATUS object_print(Object* object) {
  if (!object) return ERROR;
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  
    if (object->id != NO_ID) fprintf(stdout, "---> Exite el objeto\n");
     else fprintf(stdout, "---> No hay objeto\n");
  
  return OK;
}

