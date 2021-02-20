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
#define N_CALLBACK 4

/**
 * Define el tipo de funciones para las devoluciones de llamada
 */
typedef void (*callback_fn)(Game* game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);

/**
 * Array que guarda los comandos
 */
static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back};

/**
   Funciones privadas
*/


Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

/**
   Interfaz de game
*/

/**
 * @brief Crea el juego
 *
 * game_create Crea el juego declarando todos los espacios del tablero a NULL e inicializa la posición del jugador y del objeto a -1, al igual que el comando introducido por el jugador
 *
 * @date 
 * @author
 *
 * @param game el juego que se va a crear
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_create(Game* game) {
  int i;
  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  
  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;
  
  return OK;
}
/**
 * @brief Crea el juego en un fichero
 *
 * game_create_from_file Primero se comprueba si se crea o no el juego y si se ejecuta correctamente la funcion game_reader_load_spaces y establece la posición del jugador y del objeto a 0
 *
 * @date 
 * @author
 *
 * @param game el juego que se ha a creado
 * @param filename el nombre del fichero
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/**
 * @brief Crea el juego en un fichero
 *
 * game_destroy comienza con un bucle para establecer a NULL todas las casillas del juego que no lo estén
 *
 * @date 
 * @author
 *
 * @param game el juego que se va a "vaciar"
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }
        
  return OK;
}

/**
 * @brief Añade un nuevo espacio al juego
 *
 * game_add_space Comprueba si el segundo parametro es NULL, luego mediante un bucle determina cual es la primera casilla con valor NULL para añadir un espacio en ella. También comprueba que no se haya sobrepasado el limite de casillas
 *
 * @date 
 * @author
 *
 * @param game el juego al que se va a añadir un espacio
 * @param space el espacio que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space_id_at Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date 
 * @author
 *
 * @param game el juego del que se va a identificar el espacio
 * @param position la posición del espacio
 * @return la función space_get_id con la posición position del juego
 */
Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date 
 * @author
 *
 * @param game el juego del que se va a identificar el espacio
 * @param position la posición del espacio
 * @return la función space_get_id con la posición position del juego
 */
Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }
    
  return NULL;
}

/**
 * @brief Establece la posición del jugador
 *
 * game_set_player_location Comienza comprobando si el segundo parametro es -1
 *
 * @date 
 * @author
 *
 * @param game el juego donde se establece el jugador
 * @param position la posición donde se establece el jugador
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_player_location(Game* game, Id id) {
    
  if (id == NO_ID) {
    return ERROR;
  }

  game->player_location = id;

  return OK;
}

/**
 * @brief Establece la posición del objeto
 *
 * game_set_objet_location Comprueba si el segundo parametro es -1
 *
 * @date 
 * @author
 *
 * @param game el juego donde se establece el objeto
 * @param position la posición donde se establece el objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_object_location(Game* game, Id id) {
  

  if (id == NO_ID) {
    return ERROR;
  }

  game->object_location = id;

  return OK;
}

/**
 * @brief Determina la posición del jugador
 *
 * game_get_player_location averigua la posición del jugador
 *
 * @date 
 * @author
 *
 * @param game el juego donde se determian la posición del jugador
 * @return la posición del jugador
 */
Id game_get_player_location(Game* game) {
  return game->player_location;
}

/**
 * @brief Determina la posición del objeto
 *
 * game_get_objet_location averigua la posición del objeto
 *
 * @date 
 * @author
 *
 * @param game el juego donde se determian la posición del objeto
 * @return la posición del objeto
 */
Id game_get_object_location(Game* game) {
  return game->object_location;
}

/**
 * @brief Actualiza el juego
 *
 * game_update el juego se actualiza en dependencia del comando introducido
 *
 * @date 
 * @author
 *
 * @param game el juego que se actualiza
 * @param cmd comando introducido
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

/**
 * @brief Encuentra el último comando introducido
 *
 * game_get_last_command averigua el último comando introducido
 *
 * @date 
 * @author
 *
 * @param game el juego del que se quiere averiguar el último comando introducido
 * @param cmd 
 * @return el último comando introducido
 */
T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

/**
 * @brief Escribe por pantalla los datos de la partida
 *
 * game_print_data se encarga de poner pon pantalla los datos de la partida
 *
 * @date 
 * @author
 *
 * @param game el juego del cual se escriben los datos
 */
void game_print_data(Game* game) {
  int i = 0;
  
  printf("\n\n-------------\n\n");
  
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  
  printf("=> Object location: %d\n", (int) game->object_location);    
  printf("=> Player location: %d\n", (int) game->player_location);
  printf("prompt:> ");
}

/**
 * @brief Termina el juego
 *
 * game_is_over se encarga de poner fin al juego
 *
 * @date 
 * @author
 *
 * @param game el juego que finaliza
 * @return FALSE para saber que se ha ejecutado la función correctamente 
 */
BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

/**
 * @brief Acción del jugador
 *
 * game_callback_unknown, game_callback_exit, game_callback_next y game_callback_back son funciones que se encargan de avanzar, retroceder o salir del juego dependiendo de lo que el jugador introduzca
 *
 * @date 
 * @author
 *
 * @param game el juego que en el que se avanza, retrocede o se abandona
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
  if (space_id == NO_ID) {
    return;
  }
  
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
  
  if (NO_ID == space_id) {
    return;
  }
  
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


