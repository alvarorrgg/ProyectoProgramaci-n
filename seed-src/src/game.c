/** 
 * @brief Implementa la interfaz del juego y todas las devoluciones de llamada asociadas para cada comando
 * 
 * 
 * @file game.c
 * @author Álvaro Rodríguez, Alberto Vicente, Alexandru Marius, Gonzalo Martín y ProfesoresPProg
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

#define N_CALLBACK 11 /*!<Numero maximo de llamadas a comandos*/



/**
 * @brief Define los elementos del juego
 * 
 * Estructura del juego
 */
struct _Game{
  Player *player;			/*!< Estructura de datos del jugador*/
  Object *objects[MAX_OBJECTS+1];	/*!< Donde se almacenan los objetos del juego*/
  Space* spaces[MAX_SPACES + 1];	/*!< Donde se almacenan los espacios del juego*/		
  Die *die;               /*!< Dado del juego*/
  Command *command;       /*!< comando que se recibe cada vez que se escribe por pantalla*/
  char last_descripcion[LEN_DES]; /*!< Ultima descripcion del comando inspect llamada */
  Link *link[MAX_LINKS+1]; /*!<Donde se almacenan los enlaces del juego*/
};
/**
 * Define el tipo de funciones para las devoluciones de llamada
 */
typedef void (*callback_fn)(Game *game);

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
void game_callback_unknown(Game *game);
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
void game_callback_exit(Game *game);
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
void game_callback_next(Game *game);
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
void game_callback_back(Game *game);

/**
 * Lista de devoluciones de llamada por cada comando en el juego 
 */

/**
 * @brief Acción del jugador
 *
 * game_callback_take si se esta encima de un objeto y se pulsa t o take se recoge el objeto
 *
 * @date 28-02-2021
 * @author Alberto Vicente
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_take(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_drop si se tiene un objeto, y se introduce d o drop, se deja caer el objeto.
 *
 * @date 28-02-2021
 * @author Alberto Vicente
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_drop(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_roll se tira el dado para avanzar
 *
 * @date 08-03-2021
 * @author Alberto Vicente
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_roll(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_right saltos del jugador en casillas especiales si se introduce right o r
 *
 * @date 08-03-2021
 * @author Álvaro Rodríguez	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_right(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_left saltos del jugador en casillas especiales si se introduce left o l
 *
 * @date 08-03-2021
 * @author Álvaro Rodríguez	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acción
 */
void game_callback_left(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_move saltos del jugador hacia las posiciones especificadas
 *
 * @date 08-03-2021
 * @author Alexandru Marius Platon	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_move(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_inspect examina los objetos indicados obteniendo la descripción de los mismos
 * @date 10-04-2021
 * @author Gonzalo Martín
 *
 * @param game el parametro sobre el que opera el comando con su respectiva accion
 */
void game_callback_inspect(Game *game);


/**
 * Array que guarda los comandos
 */
static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,     /*UNKNOWN=0*/
    game_callback_exit,        /*EXIT=1*/
    game_callback_next,	/*NEXT=2*/
    game_callback_back,	/*BACK=3*/
    game_callback_take,	/*TAKE=4*/
    game_callback_drop,	/*DROP=5*/
    game_callback_roll,	/*ROLL=6*/
    game_callback_right,	/*RIGHT=7*/
    game_callback_left,	/*LEFT=8*/
    game_callback_move, /*MOVE=9*/
    game_callback_inspect, /*INSPECT*/

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
Id game_get_space_id_at(Game *game, int position);

/*Implementación de las funciones de Game*/

Game *game_init(){

  Game *game=NULL;

  game=(Game*)malloc(sizeof(Game));

  if(!game)return NULL;

  return game;

}

STATUS game_create(Game *game)
{
  int i;
  for (i = 0; i < MAX_SPACES; i++) game->spaces[i] = NULL; /*Se inicializan todos los espacios con un valor NULL*/
  
  for (i = 0; i < MAX_OBJECTS; i++)  game->objects[i] = NULL; /*Se inicializan todos los objetos con un valor NULL*/
  
   for (i = 0; i < MAX_LINKS; i++) game->link[i] = NULL; /*Se inicializan todos los links con un valor NULL*/
  
  game->die = die_create(1);
  if(!game->die) return ERROR;
  game->command = command_init();
  game->last_descripcion[0] = '\0';

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{
 
  if (game_create(game) == ERROR) return ERROR;
  if (game_reader_load_spaces(game, filename) == ERROR) return ERROR; /*Se leen los espacios del fichero data.dat*/
  if (game_reader_load_objects(game, filename) == ERROR) return ERROR;   /*Se leen los objetos del fichero data.dat*/
  if (game_reader_load_players(game, filename) == ERROR) return ERROR;   /*Se leen los jugadores del fichero data.dat*/
  if (game_reader_load_links(game, filename) == ERROR) return ERROR;   /*Se leen los links del fichero data.dat*/


  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)  space_destroy(game->spaces[i]); /*Se destruyen todos los espacios uno a uno*/
  
  for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) object_destroy(game->objects[i]); /*Se destruyen todos los objetos uno a uno*/
  
  player_destroy(game->player); /*Se destruye el jugador*/
  die_destroy(game->die);       /*Se destruye el dado*/
  command_destroy(game->command);
  free(game);

  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;
  if (!space)return ERROR;

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) i++;

  game->spaces[i] = space;
  

  return OK;
}

STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;
  if (!object) return ERROR;

  while ((i < MAX_OBJECTS) && (game->objects[i] != NULL)) i++;

  game->objects[i] = object;
  return OK;
}

STATUS game_add_player(Game *game, Player *player)
{
  if(!game || !player) return ERROR;
  game->player=player;
  return OK;
}

STATUS game_add_link(Game *game, Link *link)
{
  int i = 0;
  if (!link  ) return ERROR;

  while ((i < MAX_LINKS) && (game->link[i] != NULL)) i++;

  game->link[i] = link;
  return OK;
}

Link *game_get_link(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID) return NULL;

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++) if (id == link_get_id(game->link[i])) return game->link[i];
  

  return NULL;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES) return NO_ID;

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID) return NULL;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i])) return game->spaces[i];
  }

  return NULL;
}
Die* game_get_die(Game* game){
  return game->die;
}
Player* game_get_player(Game* game){
  return game->player;
}

STATUS game_set_player_location(Game *game, Id id)
{
  if (id == NO_ID || !game )return ERROR;
  return player_set_location(game->player, id);
}
Id game_get_player_location(Game *game)
{
  if (!game)return NO_ID;
  return player_get_location(game->player);
}
Object *game_get_object(Game *game, int index){
    if(index<0 || index>MAX_OBJECTS) return NULL;
    
    return game->objects[index];
}
int game_get_total_objects(Game *game){
  int i = 0;
  if (!game) return -1;

  while ((i < MAX_OBJECTS) && (game->objects[i] != NULL)) i++;

  return i;
}
STATUS game_set_object_location(Game *game, Id id, Id pos_obj)
{ /*Explicación código: Primero verifica que el id dado es valido y mediante un bucle while recorre los espacios del juego hasta encontrar el que coincide con el id dado, una vez se encuentra, se devuelve la funcion space_set_object con la que se coloca el objeto en la posición correcta.*/
  int k = 0;
  if (pos_obj == NO_ID || !game   || !game_id_object_exists(game, id)) return ERROR;
  while (game->spaces[k] != NULL)
  {
    if (space_get_id(game->spaces[k]) == pos_obj) return space_set_objects(game->spaces[k], id); /*Se le atribuye al espacio determinado el objeto*/
    k++;
  }
  return ERROR;
}

Id game_get_object_location(Game *game, Id id)
{ /*Explicación código: muy parecida a game_set_object_location salvo por que el bucle recorre espacios hasta que encuentra uno en el que los valores dados por space_get_object y object_get_id sean iguales, es decir, hasta que se encuentra un objeto. Una vez se encuentra, se devuelve el id del objeto.*/
  int k = 0;
  if (!game   || !game_id_object_exists(game, id)) return NO_ID;
  while (game->spaces[k] != NULL)
  {
    if (space_has_object_id(game->spaces[k], id)) return space_get_id(game->spaces[k]); /*Se detecta la posición del objeto y se devuelve como return*/
    k++;
  }
  return NO_ID;
}

Command* game_get_command(Game* game){
  if (!game) return NULL;
  return game->command;
}

BOOL game_id_object_exists(Game *game, Id id)
{
  int i;
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (object_get_id(game->objects[i]) == id) return TRUE;

  }
  return FALSE;
}

STATUS game_update(Game *game, T_Command cmd)
{
  char arg[WORD_SIZE];
  int j=0;
  command_set_cmd(game->command,cmd);

  fgets(arg, WORD_SIZE, stdin);
  for (j = 0; arg[j + 1] != (char)0; j++) arg[j] = arg[j + 1]; 
  
  j--;
  arg[j] =(char)0;
  command_set_arg(game->command,arg);

 (*game_callback_fn_list[cmd])(game);
  return OK;
}



void game_print_data(Game *game)
{
  int i = 0;
  printf("\n\n-------------\n\n");
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) space_print(game->spaces[i]);

  printf("=> Object location: %d\n", (int)game_get_object_location(game, 1));
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
  printf("prompt:> ");
}

const char* game_get_last_descripcion(Game* game){
  if (!game) return  NULL;

  return game->last_descripcion;
}

STATUS game_set_last_description(Game* game , char* descr){
  if(!game || !descr  ) return ERROR;

  if (!strcpy(game->last_descripcion , descr)) return ERROR;

  return OK;
}

BOOL game_is_over(Game *game)
{
  return FALSE;
}



/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game *game)
{
  if(!game){
  command_set_status(game->command, ERROR);
  return;
  }
  command_set_status(game->command, ERROR);
  return;
}

void game_callback_exit(Game *game)
{
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  command_set_status(game->command, OK);
  return;
}

void game_callback_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  space_id = game_get_player_location(game);
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if (space_id == NO_ID){
    command_set_status(game->command, ERROR);
    return ;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      current_id = link_get_id_to(space_get_south(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  command_set_status(game->command, OK);
  return;
}

void game_callback_back(Game *game)
{
    int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  space_id = game_get_player_location(game);
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if (space_id == NO_ID){
    command_set_status(game->command, ERROR);
    return ;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      current_id = link_get_id_to(space_get_north(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  command_set_status(game->command, OK);
  return;
}
void game_callback_right(Game *game)
{ 
   int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  space_id = game_get_player_location(game);
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if (space_id == NO_ID){
    command_set_status(game->command, ERROR);
    return ;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      current_id = link_get_id_to(space_get_west(game->spaces[i]));
      printf("%li",current_id);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  command_set_status(game->command, OK);
  return;
}
void game_callback_left(Game *game)
{
    int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  space_id = game_get_player_location(game);
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if (space_id == NO_ID){
    command_set_status(game->command, ERROR);
    return ;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      current_id = link_get_id_to(space_get_east(game->spaces[i]));
      printf("%li",current_id);

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  command_set_status(game->command, OK);
  return;
}

void game_callback_take(Game *game)
{

  char objeto[WORD_SIZE];
  int k = 0, i = 0;
  Id id=NO_ID;
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  
  strcpy(objeto,command_get_arg(game->command));
  if(inventory_is_full(player_get_inventory(game->player))) { /*Se verifica que el inventario del player no este lleno*/
    command_set_status(game->command, ERROR);
    printf("pito\n");
    return;
  }
  while (game->objects[i] != NULL)
  {
    if (strcmp(object_get_name(game->objects[i]), objeto) == 0) /*Se buscan los objetos que tengan el mismo nombre que el señalado*/
    {
      id = object_get_id(game->objects[i]);/*Se consigue el id del objeto*/
    }
    i++;
    }
  if(id==NO_ID){
    command_set_status(game->command,ERROR);
    return ;
  }

    while (game->spaces[k] != NULL)/*Se busca el espacio*/
    {
        
      if (space_get_id(game->spaces[k]) == game_get_player_location(game))/*Se comprueba que el jugador este en el espacio*/
      {
      if (!space_has_object_id(game->spaces[k], id)){/*Se comprueba que el objeto este en el espacio*/
        command_set_status(game->command, ERROR);
        return;
      }
      else
      {/*Se hacen las instrucciones necesarias: ponerle el objeto al jugador, borrarlo del espacio etc.*/
        player_add_object(game->player,id);
        space_remove_object(game->spaces[k], id);
        command_set_status(game->command, OK);
        return;
      }
    }
    k++;
  }
  command_set_status(game->command, OK);
  return ;

}

void game_callback_drop(Game *game)
{
   char objeto[WORD_SIZE];
  int k = 0, i = 0;
  Id id=NO_ID;
  strcpy(objeto,command_get_arg(game->command));
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if (inventory_is_empty(player_get_inventory(game->player))){/*Se verifica que el player tiene algun objeto*/
    command_set_status(game->command, ERROR);
    return;
  }
    while (game->objects[i] != NULL)
  {
    if (strcmp(object_get_name(game->objects[i]), objeto) == 0) /*Se buscan los objetos que tengan el mismo nombre que el señalado*/
    {
      id = object_get_id(game->objects[i]);/*Se consigue el id del objeto*/
    }
    i++;
    }
  if(id==NO_ID){
    command_set_status(game->command,ERROR);
    return ;
  }

  if(!player_has_object(game->player,id)){
    command_set_status(game->command,ERROR);
    return;
  }

  while (game->spaces[k] != NULL)/*Se busca el espacio*/
  {
    if (space_get_id(game->spaces[k]) == game_get_player_location(game))/*Se verifica que el jugador esta en el espacio*/
    {/*Se le quita el objeto al player y se pone en el objeto*/
      space_set_objects(game->spaces[k], id);
      player_remove_object(game->player,id);
      break;
    }
    k++;
  }
  command_set_status(game->command, OK);
  return;
}

void game_callback_roll(Game *game)
{
  
  if (!game){
    command_set_status(game->command, ERROR);
    return;
  }  
  
    
  if (die_get_id(game->die) == NO_ID){
    command_set_status(game->command, ERROR);
    return;
  }
  
  die_roll(game->die);/*Se hace la tirada*/
  command_set_status(game->command, OK);
    return;
}
void game_callback_move(Game *game)

{
  char direction[WORD_SIZE];
  strcpy(direction,command_get_arg(game->command));

  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  if(strcmp(direction, "north")==0 || strcmp(direction, "n")==0){

    game_callback_back(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "south")==0 || strcmp(direction, "s")==0){

    game_callback_next(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "west")==0 || strcmp(direction, "w")==0){

    game_callback_right(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "east")==0 || strcmp(direction, "e")==0){
    game_callback_left(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  
  else {

    printf("La direccion no es valida.\n");
    command_set_status(game->command, ERROR);

    return;

  }


}

void game_callback_inspect(Game *game){
  char name[WORD_SIZE];
  int i = 0;
  Id id;
  Id current_id = game_get_player_location (game);
  Id space_id;

  if(!game || current_id == NO_ID){
    command_set_status(game->command, ERROR);
    return;
  }
 
  strcpy(name ,command_get_arg(game->command));

  if (strcmp(name , "space") == 0 || strcmp (name , "s") ==0 ){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL ; i++){
      space_id = space_get_id (game->spaces[i]);
      if (current_id == space_id){
        strcpy (game->last_descripcion , space_get_description (game->spaces[i]));
        command_set_status(game->command, OK);
        return;
      }
    }
    command_set_status(game->command, ERROR);
    return;
  }

  while (game->objects[i] != NULL){
    id = object_get_id_by_name(game->objects[i] , name);
    if (id != -1) break; 
    i++;
  }

  if (id == -1){
    command_set_status(game->command, ERROR);
    return;
  }

  if (game_get_player_location (game) == game_get_object_location (game , id) || inventory_search_object (player_get_inventory(game->player) , id) ==TRUE){
    game_set_last_description (game , (char *) object_get_description (game->objects[i]));
    command_set_status(game->command, OK);
    return;
  }
  else{
    command_set_status(game->command, ERROR);
    return;
  }
}
