/** 
 * @brief Implementa la estructura de datos abstractos Set y sus funciones que se encargan del manejo de conjuntos.
 * 
 * @file set.c
 * @author R1
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"

struct _Set {
  Id id[MAX_IDS];	/** !< array de ids */		
  int total_ids;	/** !< total de ids */	
};

Set* set_create() {

  Set *new_set= NULL;
  new_set = (Set *) malloc(sizeof (Set));

  if (new_set == NULL) return NULL;
  
  for(int i =0;i<MAX_IDS;i++){
  	new_set[i]=NO_ID;
  }
  new_set->total=0;
  
  return new_set;
}

STATUS set_destroy(Set* set){
	if(set==NULL) return ERROR;
	free(set);
	return OK;
}

STATUS set_id_add(Set* set,Id id){
	if(set==NULL || id<0) return ERROR;
	set->id[set->total_ids]=id;
	set->total_ids++;
	return OK;
	}
	
STATUS set_id_delete(Set* set){
	if(set==NULL) return ERROR;
	set->id[set->total_ids]=NULL;
	set->total_ids--;
	return OK;
}
STATUS set_print(FILE *pf, const Set *set){
	if(set==NULL || pf==NULL) return ERROR;
	
	
    fprintf (pf, "El set tiene %d elementos: \n", set->total_ids);

    for (int i=0, i<set->total_ids; i++){
        fprintf(pf,"Id: %ld. \n", set->items[i]);
        i++;
   	}
   	fprintf (pf, "\n");
   	return OK
   }


	
	
	
	
	
	
	
	
