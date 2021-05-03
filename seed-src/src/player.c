/** 
 * @brief Se encarga de todo lo relacionado con el jugador.
 * 
 * @file player.c
 * @author Álvaro Rodriguez
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"
#include "object.h"

/**
 * @brief Define la estructura Player
 *
 * Almacena información del jugador.
 */
struct _Player {
  
  Id id;		                /*!< Id del jugador */
  char name[WORD_SIZE + 1];	/*!< nombre del jugador */
  Id location;	          	/*!< localización del jugador */
  Inventory *inventory;	    /*!< Inventario con los objetos del jugador */
};

Player* player_create(Id id) {

  Player *new_player = NULL;

  if (id == NO_ID) return NULL;

  new_player = (Player *) malloc(sizeof (Player));

  if (!new_player ) return NULL;
  
  new_player->id = id;
  new_player->name[0] = '\0';
  new_player->location = NO_ID;
  new_player->inventory=inventory_create();
  if(!new_player->inventory) return NULL;

  return new_player;
}

STATUS player_destroy(Player* player) {
  if (!player) return ERROR;
  
  inventory_destroy(player->inventory);
  free(player);
  return OK;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || strlen(name)==0) return ERROR;
  
  if (!strcpy(player->name, name))  return ERROR;
 
  return OK;
}

const char * player_get_name(Player* player) {
  if (!player) return NULL;
  
  return player->name;
}

Id player_get_id(Player* player) {
  if (!player) return NO_ID;
  
  return player->id;
}

int player_get_inventory_max_capacity (Player *player){
    if (!player) return -1;

    return inventory_get_max_objects(player->inventory);
}

STATUS player_set_inventory_max_capacity(Player *player, int max_objects){
  if(!player || max_objects<0) return ERROR;
  return inventory_set_max_objects(player->inventory,max_objects);
}

Id *player_get_objects(Player* player) {
  if (!player) return NULL;
  
  return inventory_get_inventory(player->inventory);
}

STATUS player_add_object(Player* player, Id value) {
  if (!player) {
    return ERROR;
  }
  
  return inventory_set_object(player->inventory,value);
}

STATUS player_remove_object(Player* player, Id value) {
  if (!player) {
    return ERROR;
  }
  
  return inventory_delete_object(player->inventory,value);
}

STATUS player_set_location(Player* player, Id id) {
  if (!player || id == NO_ID) return ERROR;
  
  player->location = id;
  
  return OK;
}

Id player_get_location(Player* player) {
  if (!player) return NO_ID;
  
  return player->location;
}

BOOL player_has_object(Player* player, Id id){
  if(!player || !inventory_search_object(player->inventory,id)) return FALSE;
  
  return TRUE;

}

Inventory *player_get_inventory(Player* player){
  if(!player) return NULL;
  return player->inventory ;
}

STATUS player_print(FILE *pf,Player* player) {

  if (!player || !pf) return ERROR;
  
  fprintf(pf, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  
  if (player_get_location(player)!=-1) fprintf(pf, "---> Player location: %li \n",player_get_location(player));
  else  fprintf(pf, "---> No player location.\n");

   if (player_get_id(player) != NO_ID) fprintf(pf, "---> Existe un jugador.\n");
   else fprintf(pf, "---> No existe jugador.\n");
  

  return OK;
}

