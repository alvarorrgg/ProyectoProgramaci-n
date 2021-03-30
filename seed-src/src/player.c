/** 
 * @brief Se encarga del jugador
 * 
 * @file player.c
 * @author Alberto Garcia.
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

struct _Player {
  Id id;		                /*!< Id del jugador */
  char name[WORD_SIZE + 1];	/*!< nombre del jugador */
  Id location;		/*!< localización del jugador */
  Id object;	/*!< Id del objeto del jugador */
};

Player* player_create(Id id) {

  Player *new_player = NULL;

  if (id == NO_ID) return NULL;

  new_player = (Player *) malloc(sizeof (Player));

  if (new_player == NULL) return NULL;
  
  new_player->id = id;
  new_player->name[0] = '\0';
  new_player->location = NO_ID;
  new_player->object = NO_ID;

  return new_player;
}

STATUS player_destroy(Player* player) {
  if (!player) return ERROR;
  
  free(player);
  return OK;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) return ERROR;
  
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


Id player_get_object(Player* player) {
  if (!player) return FALSE;
  
  return player->object;
}

STATUS player_set_object(Player* player, Id value) {
  if (!player) {
    return ERROR;
  }
  player->object = value;

  return OK;
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

STATUS player_print(Player* player) {

  if (!player) return ERROR;
  
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  
  if (player_get_location(player)!=-1) fprintf(stdout, "---> Player location: %li \n",player_get_location(player));
  else  fprintf(stdout, "---> No player location.\n");

   if (player_get_id(player) != NO_ID) fprintf(stdout, "---> Existe un jugador.\n");
   else fprintf(stdout, "---> No existe jugador.\n");
  

  return OK;
}

