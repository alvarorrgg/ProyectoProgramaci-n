#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

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
  Id object;		/*!< id del objeto */
};

Space* space_create(Id id) {

  Space *new_space = NULL;

  if (id == NO_ID) return NULL;

  new_space = (Space *) malloc(sizeof (Space));

  if (new_space == NULL) return NULL;
  
  new_space->id = id;
  new_space->name[0] = '\0';
  new_space->north = NO_ID;
  new_space->south = NO_ID;
  new_space->east = NO_ID;
  new_space->west = NO_ID;
  new_space->object = NO_ID;

  return new_space;
}

STATUS space_destroy(Space* space) {
  if (!space) return ERROR;
  
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

STATUS space_set_object(Space* space, Id value) {
  if (!space) return ERROR;
  
  space->object = value;
  return OK;
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


BOOL space_get_object(Space* space) {
  if (!space) return FALSE;
  
  return space->object;
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

  if (space_get_object(space)) fprintf(stdout, "---> Object in the space.\n");
  else  fprintf(stdout, "---> No object in the space.\n");

  return OK;
}

