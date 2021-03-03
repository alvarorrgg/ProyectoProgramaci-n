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
  Id id[MAX_IDS];
  int min, max;
  int last_roll;
};

Die *die(Die *die){

  int i;
  Die * new_die =NULL;
  
  new_die=(Die *) malloc(sizeof(Die));
  
  if (new_die==NULL) return NULL;

  for(i=0;i<MAX_IDS;i++){
    new_die->id[i]=NO_ID;
  }
  
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



















