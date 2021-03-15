/** 
 * @brief Implementa la estructura de datos abstractos Set y sus funciones que se encargan del manejo de conjuntos.
 * 
 * @file set.c
 * @author Álvaro Rodríguez
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

struct _Set {
  Id id[MAX_IDS];	/** !< array de ids */		
  int total_ids;	/** !< total de ids */	
};

Set* set_create() {
 int i;
  Set *new_set= NULL;
  new_set = (Set *) malloc(sizeof (Set));

  if (new_set == NULL) return NULL;
  
  for(i =0;i<MAX_IDS;i++){
  	new_set->id[i]=NO_ID;
  }
  new_set->total_ids=0;
  
  return new_set;
}

STATUS set_destroy(Set* set){
	if(set==NULL) return ERROR;
	free(set);
	return OK;
}

STATUS set_id_add(Set* set,Id id){
	if(set==NULL || id<0 || set_is_full(set)||set_has_id(set,id) ) return ERROR;
		set->id[set->total_ids]=id;
		(set->total_ids)++;	
		return OK;
	}
	
STATUS set_id_delete(Set* set,Id id){
	int j;
	if(set==NULL || set_is_empty(set) || !set_has_id(set,id)){

		return ERROR;
	} 
	j=set_find_object_by_id(set,id);
	set->id[j]=set->id[set->total_ids-1];
	set->id[set->total_ids-1]=NO_ID;
	set->total_ids--;
	return OK;
}

STATUS set_set_total_ids(Set* set,int n){
	if (set==NULL || n<0) return ERROR;
	if(n>100) n=100;
	set->total_ids=n;
	return OK;
	}
	
int set_get_total_ids(Set* set){
	if(set==NULL) return -1;
	return set->total_ids;
	}
	
BOOL set_has_id(Set* set, Id id){
 	int i;
	if(set==NULL || id<0) return FALSE;
	for(i=0; i<set->total_ids;i++){
		if(set->id[i]==id){
			return TRUE;
			}
		}
	return FALSE;
	}
	
int set_find_object_by_id(Set* set, Id id){
	int i;
	if(set==NULL || id<0) return NO_ID;
	
	for(i=0; i<set->total_ids;i++){
		
		if(set->id[i]==id){		
			return i;
		}
	}
	return NO_ID;
	}
BOOL set_is_empty(Set* set){
	if(set==NULL) return FALSE;
	if(set->total_ids==0) return TRUE;
	return FALSE;
	}
	
BOOL set_is_full(Set* set){
	if(set==NULL) return FALSE;
	if(set->total_ids==MAX_IDS) return TRUE;
	return FALSE;
	}
	
Id* set_get_ids(Set *set){
	if(set==NULL || set->total_ids==0) return NULL;
	return set->id;
	}
	
	
STATUS set_print(FILE *pf, const Set *set){
 	int i;
	if(set==NULL || pf==NULL) return ERROR;
	
	
    fprintf (pf, "El set tiene %d elementos: \n", set->total_ids);

    for (i=0 ;i<set->total_ids; i++){
        fprintf(pf,"Id: %ld. \n", set->id[i]);
        i++;
   	}
   	fprintf (pf, "\n");
   	return OK;
   }


	
	
	
	
	
	
	
	
