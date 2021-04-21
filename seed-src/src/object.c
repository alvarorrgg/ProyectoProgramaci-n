/** 
 * @brief Sirve para el manejo de objetos.
 * 
 * @file object.c
 * @author Álvaro Rodríguez, Gonzalo Martín
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
 * @brief Define la estructura Object
 *
 * Almacena información del objeto.
 */
struct _Object {

  Id id;			/*!< id del objeto*/
  char name[WORD_SIZE + 1];	/*!< nombre del objeto*/
  char description[LEN_DES]; /*!< descripción de cada objecto*/
  BOOL movement;  /*!<Movimiento del objeto*/
  Id dependency; /*!<Dependencia del objeto*/
  Id open_link; /*!<Puede abrir o no un link*/
  BOOL illuminate; /*!< Ver si un objeto puede o no iluminar un espacio*/
  BOOL turnedon; /*!<Ver si un objeto que puede iluminar esta iluminado*/
  
};

Object* object_create(Id id) {  
  Object *new_object = NULL;

  if(id == NO_ID) return NULL;

  new_object = (Object *) malloc(sizeof (Object));
  if (!new_object) return NULL;
  
  new_object->id = id;
  new_object->name[0] = (char)0;
  new_object->movement=FALSE;
  new_object->dependency=NO_ID;
  new_object->open_link=NO_ID;
  new_object->illuminate=FALSE;
  new_object->turnedon=FALSE;
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
 BOOL object_get_movement(Object *object){
   if(!object) return FALSE;
     return object->movement;
   
 }

 STATUS object_set_movement(Object *object,BOOL bol){
   if(!object) return ERROR;
   object->movement=bol;
   return OK;
 }

Id object_get_dependency(Object *object){
   if(!object) return -1;
     return object->dependency;
   
 }

 STATUS object_set_dependency(Object *object,Id id){
   if(!object) return ERROR;
   object->dependency=id;
   return OK;
 }

 Id object_get_link_open(Object *object){
   if(!object) return -1;
     return object->open_link;
   
 }

 STATUS object_set_link_open(Object *object,Id id){
   if(!object) return ERROR;
   object->open_link=id;
   return OK;
 }

 BOOL object_get_iluminate(Object *object){
   if(!object) return FALSE;
     return object->illuminate;
   
 }

 STATUS object_set_iluminate(Object *object,BOOL bol){
   if(!object) return ERROR;
   object->illuminate=bol;
   return OK;
 }


 BOOL object_get_turnedon(Object *object){
   if(!object) return FALSE;
     return object->turnedon;
   
 }

 STATUS object_set_turnedon(Object *object,BOOL bol){
   if(!object) return ERROR;
   object->turnedon=bol;
   return OK;
 }

STATUS object_print(Object* object) {
  if (!object) return ERROR;
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
  
    if (object->id != NO_ID) fprintf(stdout, "---> Exite el objeto\n");
     else fprintf(stdout, "---> No hay objeto\n");
  
  return OK;
}

