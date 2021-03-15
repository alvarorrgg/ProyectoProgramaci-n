#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "set.h"

/**
 * @brief Estructura space
 *
 * contiene las variables del espacio
 */
struct _Space {
  Id id;		/*!< coordenadas */
  char name[WORD_SIZE + 1];	/*!< nombre del espacio */
  Id north;		/*!< coordenada norte */
  Id south;		/*!< coordenada sur */
  Id east;		/*!< coordenada este */
  Id west;		/*!< coordenada oeste */
  Set* objects;	/*!< array de objetos */
  char **gdesc;	/*!< Descripción grafica */
};

Space* space_create(Id id) {

  Space *new_space = NULL;

  if (id == NO_ID) return NULL;

  new_space = (Space *) malloc(sizeof (Space));

  if (new_space == NULL) return NULL;
  new_space->objects=set_create();
  new_space->id = id;
  new_space->name[0] = '\0';
  new_space->north = NO_ID;
  new_space->south = NO_ID;
  new_space->east = NO_ID;
  new_space->west = NO_ID;  
  new_space->gdesc = (char **)malloc(3*sizeof(char *));
  new_space->gdesc[0] = (char *)malloc(9*sizeof(char));
  new_space->gdesc[1] = (char *)malloc(9*sizeof(char));
  new_space->gdesc[2] = (char *)malloc(9*sizeof(char));
  return new_space;
}

STATUS space_destroy(Space* space) {
  if (!space) return ERROR;
  set_destroy(space->objects);
  free(space->gdesc[0]);
  free(space->gdesc[1]);
  free(space->gdesc[2]);
  free(space->gdesc);
  free(space);
  return OK;
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) return ERROR;
  
  if (!strcpy(space->name, name))  return ERROR;
 
  return OK;
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) return ERROR;
  
  space->north = id;
  
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) return ERROR;
  
  space->south = id;
  
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) return ERROR;
  
  space->east = id;
  
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) return ERROR;
  
  space->west = id;
  
  return OK;
}

STATUS space_set_objects(Space* space, Id id) {
  if (!space || set_id_add(space->objects,id)==ERROR) return ERROR;
  return OK;
}

STATUS space_set_gdesc(Space *space, char **desc){
  if (!space) return ERROR;
  strcpy(space->gdesc[0], desc[0]);
  strcpy(space->gdesc[1], desc[1]);
  strcpy(space->gdesc[2], desc[2]);

  return OK;
}

char** space_get_gdesc(Space *space){
  if (!space)  return NULL;
  return space->gdesc;

}

STATUS space_remove_object(Space* space, Id id) {
   
  return set_id_delete(space->objects,id);
}

const char * space_get_name(Space* space) {
  if (!space) return NULL;
  
  return space->name;
}

Id space_get_id(Space* space) {
  if (!space) return NO_ID;
  
  return space->id;
}

Id space_get_north(Space* space) {
  if (!space) return NO_ID;
  
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) return NO_ID;
  
  return space->south;
}


Id space_get_east(Space* space) {
  if (!space) return NO_ID;
  
  return space->east;
}


Id space_get_west(Space* space) {
  if (!space) return NO_ID;
  
  return space->west;
}


Id* space_get_objects(Space* space) {
  if (!space) return NULL;
  return set_get_ids(space->objects);
}

int space_get_number_of_objects(Space* space) {
  return set_get_total_ids(space->objects);
}

BOOL space_has_object_id(Space* space, Id id){
  if (!space)  return FALSE;

  return set_has_id(space->objects, id);
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  if (!space) return ERROR;
  
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
  idaux = space_get_north(space);
  if (NO_ID != idaux) fprintf(stdout, "---> North link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No north link.\n");
  

  idaux = space_get_south(space);
  if (NO_ID != idaux) fprintf(stdout, "---> South link: %ld.\n", idaux);
  
  else fprintf(stdout, "---> No south link.\n");
  

  idaux = space_get_east(space);
  if (NO_ID != idaux) fprintf(stdout, "---> East link: %ld.\n", idaux);
   else fprintf(stdout, "---> No east link.\n");
  

  idaux = space_get_west(space);
  if (NO_ID != idaux) fprintf(stdout, "---> West link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No west link.\n");

  if ( space_get_objects(space)== NULL) fprintf(stdout, "---> No hay objetos en este espacio\n");
    else {
    fprintf(stdout, "---> Los objetos del espacio son:\n");
    set_print(stdout, space->objects);
  }

  return OK;
}

