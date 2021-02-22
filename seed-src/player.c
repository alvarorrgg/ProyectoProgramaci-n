/** 
 * @brief Implementa la estructura de datos abstractos Player, y las funciones que estan relacionadas con esta.
 * 
 * @file player.c
 * @author R2
 * @version 1.0 
 * @date 22-02-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"

struct _Player {
  Id id;
  char name[WORD_SIZE + 1];
};

Player* player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID) return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) return NULL;
  
  newPlayer->id = id;
  newPlayer->name[0] = '\0';

  return newPlayer;
}

STATUS player_destroy(Player* player) {
  if (!player) return ERROR;
  
  free(player);
  player = NULL;

  return OK;
}

Id player_get_id(Player* player) {
  if (!player) return NO_ID;
  
  return player->id;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) return ERROR;
  

  if (!strcpy(player->name, name)) return ERROR;
  
  return OK;
}

const char * player_get_name(Player* player) {
  if (!player) return NULL;
  
  return player->name;
}

STATUS player_print(Player* player) {
  if (!player) return ERROR;
  

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  return OK;
}

