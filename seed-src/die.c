/** 
 * @brief Módulo para aplicar funcionalidad al dado
 * 
 * @file die.c
 * @author R2
 * @version 2.0 
 * @date 02-03-2021
 * @updated 02-03-2021
 * @copyright GNU Public License
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "die.h"

struct _Die {
  Id id;
  int min, max;
  int last_roll;
};

Die *die(){

  if (!die) return NULL;
  
  int i;
  Die * new_die =NULL;
  
  new_die=(Die *) malloc(sizeof(Die));
  
  if (new_die==NULL) return NULL;

  new_die->id=NO_ID;
  new_die->min=1;
  new_die->max=6;
  new_die->last_roll=NO_ID;
  
  return * new_die;
}

STATUS die_destroy(Die * die){
  if (!die) return ERROR;
  free(die);
  return OK;
}

int die_roll(Die * die){
  if (!die) return -1;
  die->last_roll=rand () %(die->max) + die->min;
  return die->last_roll;
}

STATUS die_set_Id(Die * die, Id id){
  if (!die || !id) return ERROR;
  die->id=id;
  return OK;
}

int die_get_last_roll(Die * die){
  if (!die) return -1;
  return die->last_roll;
}

Id die_get_id(Die * die){
  if (!die) return NO_ID;
  return die->id;
}

STATUS die_print(FILE *pf, const Die *die){
  if (!pf || !die) return ERROR;
  
  fprintf(pf,"El dado %ld ha sacado un %d. \n", die->id,die->last_roll);
  
  return OK;
}

