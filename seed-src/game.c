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
 * @param game el parametro sobre el que opera el comando con su respectiva acción
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
 * @param game el parametro sobre el que opera el comando con su respectiva acción
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
 * @param game el parametro sobre el que opera el comando con su respectiva acción
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
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_back(Game* game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */
 
/**
 * @brief Acción del jugador
 *
 * game_callback_take si se esta encima de un objeto y se pulsa t o take se recoge el objeto
 *
 * @date 28-02-2021
 * @author R2
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_take(Game* game);

 
/**
 * @brief Acción del jugador
 *
 * game_callback_drop si se tiene un objeto, y se introduce d o drop, se deja caer el objeto.
 *
 * @date 28-02-2021
 * @author R2
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_drop(Game* game);

/**
 * @brief Acción del jugador
 *
 * game_callback_roll se tira el dado para avanzar
 *
 * @date 08-03-2021
 * @author R2
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_roll(Game* game);



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
  game_callback_roll,
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


/*Implementación de las funciones de Game*/ 

STATUS game_create(Game* game) {
  int i;  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL; /*Se inicializan todos los espacios con un valor NULL*/
  }
   for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL; /*Se inicializan todos los objetos con un valor NULL*/
  }
  game->player = player_create(1);
  game->last_cmd = NO_CMD;
  game->die = die_create(1);
  
  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR) return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR) return ERROR;/*Se leen los espacios del fichero data.dat*/
   if (game_reader_load_objects(game, filename) == ERROR) return ERROR;/*Se leen los objetos del fichero data.dat*/
  game_set_player_location(game, game_get_space_id_at(game, 0));/*Se inicializa el jugador en el primer espacio*/


  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);/*Se destruyen todos los espacios uno a uno*/
  }
       for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) {
    object_destroy(game->objects[i]);/*Se destruyen todos los objetos uno a uno*/
  } 
  player_destroy(game->player);/*Se destruye el jugador*/
  die_destroy(game->die);/*Se destruye el dado*/

    
  return OK;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;
  if (space == NULL) return ERROR; 
   
  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)) i++; 
  
  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game* game, Object* object) {
  int i = 0;
  if (object== NULL) return ERROR; 
   
  while ( (i < MAX_OBJECTS) && (game->objects[i] != NULL)) i++; 
  
  game->objects[i] = object;

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
Id game_get_player_location(Game* game) {
if(game==NULL) return NO_ID;
  return player_get_location(game->player);
}

STATUS game_set_object_location(Game* game, Id id,Id pos_obj) {/*Explicación código: Primero verifica que el id dado es valido y mediante un bucle while recorre los espacios del juego hasta encontrar el que coincide con el id dado, una vez se encuentra, se devuelve la funcion space_set_object con la que se coloca el objeto en la posición correcta.*/
  int k=0;
  if(pos_obj == NO_ID || game==NULL || !game_id_object_exists(game,id)) return ERROR;
  while(game->spaces[k] != NULL){
   if (space_get_id(game->spaces[k]) == pos_obj) return space_set_objects(game->spaces[k], id);/*Se le atribuye al espacio determinado el objeto*/
    k++;
  }  
  return ERROR;
}

Id game_get_object_location(Game* game,Id id) {/*Explicación código: muy parecida a game_set_object_location salvo por que el bucle recorre espacios hasta que encuentra uno en el que los valores dados por space_get_object y object_get_id sean iguales, es decir, hasta que se encuentra un objeto. Una vez se encuentra, se devuelve el id del objeto.*/
  int k=0;
  if(game==NULL || !game_id_object_exists(game,id)) return NO_ID;
  while(game->spaces[k] != NULL){
    if(space_has_object_id(game->spaces[k], id)) return space_get_id(game->spaces[k]);/*Se detecta la posición del objeto y se devuelve como return*/
  	k++;
  	} 
  return NO_ID;
}
BOOL game_id_object_exists(Game* game, Id id){
  int i;
  for(i=0;i<MAX_OBJECTS;i++){
    if(object_get_id(game->objects[i])==id){
      return TRUE;
    }
  }
  return FALSE;
}
	
STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

/*void game_print_data(Game* game) {
  int i = 0;
  printf("\n\n-------------\n\n"); 
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  } 
  printf("=> Object location: %d\n", (int) game_get_object_location(game,id));    
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}


BOOL game_is_over(Game* game) {
  return FALSE;
}*/

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
/*
void game_callback_take(Game* game) {
  int k=0;
  while(game->spaces[k]!=NULL){
      if (space_get_id(game->spaces[k])==game_get_player_location(game) ){
        if (space_get_objects(game->spaces[k]) == NO_ID) return;
      else{
        player_set_object(game->player, space_get_objects(game->spaces[k]));
        space_set_objects(game->spaces[k], NO_ID);
        }
    }
    k++;
  }
}

void game_callback_drop(Game* game){
  int k=0;
  if(player_get_object(game->player) == NO_ID) return;
  while (game->spaces[k] != NULL){
    if (space_get_id(game->spaces[k]) ==  game_get_player_location(game)){
        space_set_objects(game->spaces[k], object_get_id(game->object));
        player_set_object(game->player, NO_ID);
        break;
    }
          k++;
      }

}
  */

void game_callback_roll(Game* game){
  if(!game)return;
  if(die_get_id(game->die)==NO_ID)return;
  if(die_get_last_roll(game->die)==-1 || die_get_last_roll(game->die)==0)return;
  
  die_roll(game->die);
}



