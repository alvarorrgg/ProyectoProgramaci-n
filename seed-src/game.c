/** 
 * @brief Implementa la interfaz del juego y todas las devoluciones de
 * llamada asociadas para cada comando
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"
#define N_CALLBACK 6

/**
 * Define el tipo de funciones para las devoluciones de llamada
 */
typedef void (*callback_fn)(Game* game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_unknown cuando se teclea un caracter no reconocido.
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_unknown(Game* game);
/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_exit si se introduce e o exit sale del juego.
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_exit(Game* game);
/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_next si se introduce n o next, avanza a la siguiente casilla.
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_next(Game* game);
/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_back si se introduce b o back se retrocede a la casilla anterior.
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_back(Game* game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_take si se introduce b o back se retrocede a la casilla anterior.
 *
 * @date 28-02-2021
 * @author R2
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_take(Game* game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_drop si se introduce b o back se retrocede a la casilla anterior.
 *
 * @date 28-02-2021
 * @author R2
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
 */
void game_callback_drop(Game* game);



/**
 * Array que guarda los comandos
 */
static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  };

/**
   Funciones privadas
*/


/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space_id_at Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego del que se va a identificar el espacio
 * @param position la posición del espacio
 * @return la función space_get_id con la posición position del juego
 */
Id game_get_space_id_at(Game* game, int position);

/**
 * @brief Establece la posición del jugador
 *
 * game_set_player_location Comienza comprobando si el segundo parametro es -1
 *

 *
 * @param game el juego donde se establece el jugador
 * @param position la posición donde se establece el jugador
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_player_location(Game* game, Id id);

/**
 * @brief Establece la posición del objeto
 *
 * game_set_objet_location Comprueba si el segundo parametro es -1
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego donde se establece el objeto
 * @param position la posición donde se establece el objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_object_location(Game* game, Id id);

/*Implementación de las funciones de Game*/ 

STATUS game_create(Game* game) {
  int i;  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  game->player = player_create(1);
  game->object = object_create(1);
  game->last_cmd = NO_CMD;
  
  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR) return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR) return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }
      
  player_destroy(game->player);
  object_destroy(game->object);
    
  return OK;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;
  if (space == NULL) return ERROR; 
   
  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)) i++; 
  
  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) return NO_ID;  
  
  return space_get_id(game->spaces[position]);
}


Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) return NULL;
  
    
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) return game->spaces[i];
    
  }
    
  return NULL;
}

STATUS game_set_player_location(Game* game, Id id) {   
  if (id == NO_ID || game==NULL) return ERROR; 
  return player_set_location(game->player, id);
}

STATUS game_set_object_location(Game* game, Id id) {  
  if(id == NO_ID || game==NULL) return ERROR;
 
  for (int i=0; game->spaces[i] != NULL; i++){
    if (space_get_id(game->spaces[i]) == id) return space_set_object(game->spaces[i], object_get_id(game->object));
  }
  return ERROR;
}


Id game_get_player_location(Game* game) {
if(game==NULL) return NO_ID;
  return player_get_location(game->player);
}


Id game_get_object_location(Game* game) {
  if(game==NULL) return NO_ID;
  for (int i=0; game->spaces[i] != NULL || i<MAX_SPACES; i++){
    if (space_get_object(game->spaces[i] ) == object_get_id(game->object))return space_get_id(game->spaces[i]); 	
  }
  return NO_ID;
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

void game_print_data(Game* game) {
  int i = 0;
  printf("\n\n-------------\n\n"); 
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  } 
  printf("=> Object location: %d\n", (int) game_get_object_location(game));    
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}


BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}

void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;  
  space_id = game_get_player_location(game);
  
  if (space_id == NO_ID) return;
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  space_id = game_get_player_location(game); 
  if (NO_ID == space_id) return;
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_take(Game* game) {
  int i;
  Id ob_lc;
  Id pl_lc;
  
  pl_lc = game_get_player_location(game);
  
  for (i=0; game->spaces[i]!=NULL; i++){
    if (space_get_id(game->spaces[i])==pl_lc){
      ob_lc = space_get_object(game->spaces[i]);
      
      if (ob_lc == NO_ID) return;
      
      player_set_object(game->player, ob_lc);
      space_set_object(game->spaces[i], NO_ID);
      break;
    }
  }
}

void game_callback_drop(Game* game) {
  int i;
  Id pl_lc;
  
  if (player_get_object(game->player)==NO_ID) return;
  
  pl_lc=game_get_player_location(game);
  
  for (i=0; game->spaces[i] != NULL; i++){
    if (space_get_id(game->spaces[i]) == pl_lc){
      space_set_object(game->spaces[i], object_get_id(game->object));
      player_set_object(game->player,NO_ID);
      break;
    }
  }
}



