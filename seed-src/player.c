#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"

/**
 * @brief Estructura player
 *
 * contiene las variables del jugador
 */
struct _Player {
  Id id;		/*!< coordenadas */
  char name[WORD_SIZE + 1];	/*!< nombre del jugador */
  Id location;		/*!< localización del jugador */
  BOOL object;		/*!< objeto (TRUE o FALSE) */
};

Player* player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID) return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) return NULL;
  
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = FALSE;

  return newPlayer;
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


STATUS player_set_object(Player* player, BOOL value) {
  if (!player) return ERROR;
  
  player->object = value;
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


BOOL player_get_object(Player* player) {
  if (!player) return FALSE;
  
  return player->object;
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
  Id idaux = NO_ID;

  if (!player) return ERROR;
  
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  
  if (player_get_localitation(player)) fprintf(stdout, "---> Player location. \n");
  else  fprintf(stdout, "---> No player location.\n");

  if (player_get_object(player)) fprintf(stdout, "---> Object in player.\n");
  else  fprintf(stdout, "---> No object in player.\n");

  return OK;
}

