/** 
 * @brief Se encarga de los espacios del juego
 * 
 * @file space.c
 * @author Profesores Pprog,Álvaro Rodríguez, Gonzalo Martín, Alberto Vicente
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "space.h"
#include "set.h"

#define NUMBEROFCHARS 3 /*!< Numero de chars */
#define MAX_CHARS 46 /*!< Maximo de chars */

/**
 * @brief Define un espacio
 * 
 * Estructura de espacio
 */
struct _Space {
  Id id;		/*!< Id del espacio */
  char name[WORD_SIZE + 1];	/*!< nombre del espacio */
  Link *north;		/*!< coordenada norte */
  Link *south;		/*!< coordenada sur */
  Link *east;		/*!< coordenada este */
  Link *west;		/*!< coordenada oeste */
  Link *up; /*!< coordenada hacia arriba */
  Link *down; /*!< coordenada hacia abajo */
  Set* objects;	/*!< array de objetos */
  char **gdesc;	/*!< Descripción grafica */
  char description[LEN_DES]; /*!< Descripción del espacio */
  char detailed_description[LEN_DETAIL_DESCR]; /*!< Descripción mas detallada del espacio*/
  BOOL ilumination; /*!< Tipo de iluminación del espacio */
};

Space* space_create(Id id) {

  Space *new_space = NULL;

  if (id == NO_ID) return NULL;

  new_space = (Space *) malloc(sizeof (Space));
  if (!new_space ) return NULL;

  new_space->objects = set_create();
  new_space->id = id;
  new_space->name[0] = '\0';
  new_space->north = NULL;
  new_space->south = NULL;
  new_space->east = NULL;
  new_space->west = NULL; 
  new_space->up = NULL; 
  new_space->down = NULL; 
  new_space->gdesc = (char **)malloc(NUMBEROFCHARS*sizeof(char *)); 
  new_space->gdesc[0] = (char *)malloc(MAX_CHARS*sizeof(char)); 
  new_space->gdesc[1] = (char *)malloc(MAX_CHARS*sizeof(char));
  new_space->gdesc[2] = (char *)malloc(MAX_CHARS*sizeof(char));
  new_space->ilumination = FALSE;
  if(!new_space->gdesc || !new_space->gdesc[0] || !new_space->gdesc[1] || !new_space->gdesc[2]) return NULL;

  return new_space; /*Se devuelve el nuevo espacio creado*/
}

STATUS space_destroy(Space* space) {
  if (!space) return ERROR; 

  set_destroy(space->objects); 

  if(space_get_north(space)!=NULL) link_destroy(space->north);
  if(space_get_south(space)!=NULL) link_destroy(space->south);
  if(space_get_west(space)!=NULL) link_destroy(space->west);
  if(space_get_east(space)!=NULL) link_destroy(space->east);
  if(space_get_up(space)!=NULL) link_destroy(space->up);
  if(space_get_down(space)!=NULL) link_destroy(space->down);

  
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

STATUS space_set_north(Space* space, Link *link) {
  if (!space || !link) return ERROR;
  
  space->north = link;
  
  return OK;
}

STATUS space_set_south(Space* space, Link *link) {
  if (!space || !link  ) return ERROR;
  
  space->south = link;
  
  return OK;
}

STATUS space_set_east(Space* space, Link *link) {
  if (!space || !link  ) return ERROR;
  
  space->east = link;
  
  return OK;
}

STATUS space_set_west(Space* space, Link *link) {
  if (!space || !link  ) return ERROR;
  
  space->west = link;
  
  return OK;
}
STATUS space_set_up(Space* space, Link *link) {
  if (!space || !link  ) return ERROR;
  
  space->up = link;
  
  return OK;
}
STATUS space_set_down(Space* space, Link *link) {
  if (!space || !link  ) return ERROR;
  
  space->down = link;
  
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

Link *space_get_north(Space* space) {
  if (!space) return NULL;
  
  return space->north;
}

Link *space_get_south(Space* space) {
  if (!space) return NULL;
  
  return space->south;
}


Link *space_get_east(Space* space) {
  if (!space) return NULL;
  
  return space->east;
}


Link *space_get_west(Space* space) {
  if (!space) return NULL;
  
  return space->west;
}
Link *space_get_up(Space* space) {
  if (!space) return NULL;
  
  return space->up;
}
Link *space_get_down(Space* space) {
  if (!space) return NULL;
  
  return space->down;
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


STATUS space_set_description(Space* space , char* descr){
  if(!space || !descr  ) return ERROR;

  if (!strcpy(space->description, descr)) return ERROR;

  return OK;
}

const char* space_get_description(Space* space){
    if (!space) return NULL;

    return space->description;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  if (!space) return ERROR;
  
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
  idaux = link_get_id_to(space_get_north(space));
  if (NO_ID != idaux) fprintf(stdout, "---> North link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No north link.\n");
  

  idaux = link_get_id_to(space_get_south(space));
  if (NO_ID != idaux) fprintf(stdout, "---> South link: %ld.\n", idaux);
  
  else fprintf(stdout, "---> No south link.\n");
  

  idaux = link_get_id_to(space_get_east(space));
  if (NO_ID != idaux) fprintf(stdout, "---> East link: %ld.\n", idaux);
   else fprintf(stdout, "---> No east link.\n");
  

  idaux = link_get_id_to(space_get_west(space));
  if (NO_ID != idaux) fprintf(stdout, "---> West link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No west link.\n");

  if ( !space_get_objects(space) ) fprintf(stdout, "---> No hay objetos en este espacio\n");
    else {
    fprintf(stdout, "---> Los objetos del espacio son:\n");
    set_print(stdout, space->objects);
  }

  if(space_get_ilumination(space)==TRUE)
    fprintf(stdout,"El espacio está iluminado\n");
  else
    fprintf(stdout,"El espacio no está iluminado\n");

  return OK;
}

STATUS space_set_detailed_description(Space* space , char* descr){
  if(!space || !descr) return ERROR;

  if (!strcpy(space->detailed_description, descr)) return ERROR;

  return OK;
}


 const char* space_get_detailed_description(Space* space){
  if (!space) return NULL;

  return space->detailed_description;
 }

BOOL space_get_ilumination(Space *s){
  if(!s) return FALSE;

  return s->ilumination;
}

STATUS space_set_ilumination(Space *s, BOOL boole){
  if(!s || (boole!=0 && boole!=1)) return ERROR;

  s->ilumination=boole;

  return OK;
}
