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
  Id north;		/*!< coordenada norte */
  Id south;		/*!< coordenada sur */
  Id east;		/*!< coordenada este */
  Id west;		/*!< coordenada oeste */
  BOOL object;		/*!< objeto (TRUE o FALSE) */
};

Player* player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID) return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) return NULL;
  
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->north = NO_ID;
  newPlayer->south = NO_ID;
  newPlayer->east = NO_ID;
  newPlayer->west = NO_ID;
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

STATUS player_set_north(Player* player, Id id) {
  if (!player || id == NO_ID) return ERROR;
  
  player->north = id;
  
  return OK;
}

STATUS player_set_south(Player* player, Id id) {
  if (!player || id == NO_ID) return ERROR;
  
  player->south = id;
  
  return OK;
}

STATUS player_set_east(Player* player, Id id) {
  if (!player || id == NO_ID) return ERROR;
  
  player->east = id;
  
  return OK;
}

STATUS player_set_west(Player* player, Id id) {
  if (!player || id == NO_ID) return ERROR;
  
  player->west = id;
  
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

Id player_get_north(Player* player) {
  if (!player) return NO_ID;
  
  return player->north;
}

Id player_get_south(Player* player) {
  if (!player) return NO_ID;
  
  return player->south;
}


Id player_get_east(Player* player) {
  if (!player) return NO_ID;
  
  return player->east;
}


Id player_get_west(Player* player) {
  if (!player) return NO_ID;
  
  return player->west;
}


BOOL player_get_object(Player* player) {
  if (!player) return FALSE;
  
  return player->object;
}


STATUS player_print(Player* player) {
  Id idaux = NO_ID;

  if (!player) return ERROR;
  
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  idaux = player_get_north(player);
  if (NO_ID != idaux) fprintf(stdout, "---> North link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No north link.\n");
  

  idaux = player_get_south(player);
  if (NO_ID != idaux) fprintf(stdout, "---> South link: %ld.\n", idaux);
  
  else fprintf(stdout, "---> No south link.\n");
  

  idaux = player_get_east(player);
  if (NO_ID != idaux) fprintf(stdout, "---> East link: %ld.\n", idaux);
   else fprintf(stdout, "---> No east link.\n");
  

  idaux = player_get_west(player);
  if (NO_ID != idaux) fprintf(stdout, "---> West link: %ld.\n", idaux);
  
   else fprintf(stdout, "---> No west link.\n");

  if (player_get_object(player)) fprintf(stdout, "---> Object in player.\n");
  else  fprintf(stdout, "---> No object in player.\n");

  return OK;
}

