/** 
 * @brief Implementa la interfaz del juego y todas las devoluciones de llamada asociadas para cada comando
 * 
 * 
 * @file game.c
 * @author Álvaro Rodríguez, Gonzalo Martín y ProfesoresPProg, Alberto Vicente, Alexandru Marius Platon
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_management.h"

#define N_CALLBACK 14 /*!<Numero maximo de llamadas a comandos*/

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
  Dialogue *dialogue;     /*!<Dialogo del juego*/
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
 * game_callback_inspect examina los objetos/espacio indicados obteniendo la descripción de los mismos
 * @date 10-04-2021
 * @author Gonzalo Martín
 *
 * @param game el parametro sobre el que opera el comando con su respectiva accion
 */
void game_callback_inspect(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_up saltos del jugador hacia las posiciones especificadas
 *
 * @date 08-04-2021
 * @author Alexandru Marius Platon	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_up(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_down saltos del jugador hacia las posiciones especificadas
 *
 * @date 08-04-2021
 * @author Alexandru Marius Platon	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_down(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_turnon enciende un objeto
 *
 * @date 02-05-2021
 * @author Alexandru Marius Platon	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_turnon(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_turnoff apaga un objeto
 *
 * @date 02-05-2021
 * @author Alexandru Marius Platon	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_turnoff(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_open abre un link
 *
 * @date 03-05-2021
 * @author Álvaro Rodríguez Rodrigo	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva accion
 */
void game_callback_open(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_save guarda la partida
 *
 * @date 03-05-2021
 * @author Alberto Vicente
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_save(Game *game);
/**
 * @brief Acción del jugador
 *
 * game_callback_load acarga una partida
 *
 * @date 03-05-2021
 * @author Alberto Vicente	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_load(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_build combina objetos para crear otros
 *
 * @date 03-05-2021
 * @author Álvaro Rodríguez	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_build(Game *game);

/**
 * @brief Acción del jugador
 *
 * game_callback_use sirve para hacer cosas
 *
 * @date 03-05-2021
 * @author Álvaro Rodríguez	
 *
 * @param game el parametro sobre el que opera el comando con su respectiva acciÃ³n
 */
void game_callback_use(Game *game);



/**
 * Array que guarda los comandos
 */
static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,     /*UNKNOWN=0*/
    game_callback_exit,        /*EXIT=1*/
    game_callback_take,	/*TAKE=2*/
    game_callback_drop,	/*DROP=3*/
    game_callback_roll,	/*ROLL=4*/
    game_callback_move, /*MOVE=5*/
    game_callback_inspect, /*INSPECT=6*/
    game_callback_turnon, /*TURNON=7*/
    game_callback_turnoff, /*TURNOFF=8*/
    game_callback_open, /*OPEN=9*/
    game_callback_save, /*SAVE=10*/
    game_callback_load, /*LOAD=11*/
    game_callback_build, /*Build=11*/
    game_callback_use, /*Use=12*/

};


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

  if(!game) return ERROR;

  for (i = 0; i < MAX_SPACES; i++) game->spaces[i] = NULL; /*Se inicializan todos los espacios con un valor NULL*/
  
  for (i = 0; i < MAX_OBJECTS; i++)  game->objects[i] = NULL;/*Se inicializan todos los objetos con un valor NULL*/
  
  for (i = 0; i < MAX_LINKS; i++) game->link[i] = NULL; /*Se inicializan todos los links con un valor NULL*/
  
  game->die = die_create(1);
  if(!game->die) return ERROR;
  game->command = command_init();
  if(!game->command) return ERROR;
  game->last_descripcion[0] = '\0';
  game->dialogue=dialogue_new();
  if(!game->dialogue) return ERROR;

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{
  if(!game || !filename) return ERROR;
 
  if (game_create(game) == ERROR) return ERROR;
  if (game_management_load_spaces(game, filename) == ERROR) return ERROR; /*Se leen los espacios del fichero data.dat*/
  if (game_management_load_players(game, filename) == ERROR) return ERROR;   /*Se leen los jugadores del fichero data.dat*/
  if (game_management_load_objects(game, filename) == ERROR) return ERROR;   /*Se leen los objetos del fichero data.dat*/
  if (game_management_load_links(game, filename) == ERROR) return ERROR;   /*Se leen los links del fichero data.dat*/
  if (game_management_load_dialogue(game) == ERROR) return ERROR;   /*Se leen los links del fichero data.dat*/


  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  if(!game) return ERROR;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)  space_destroy(game->spaces[i]); /*Se destruyen todos los espacios uno a uno*/
  
  for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) object_destroy(game->objects[i]); /*Se destruyen todos los objetos uno a uno*/
  
  player_destroy(game->player); /*Se destruye el jugador*/
  die_destroy(game->die);       /*Se destruye el dado*/
  command_destroy(game->command);
  dialogue_destroy(game->dialogue);
  free(game);

  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (!game || !space)return ERROR;

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) i++;

  game->spaces[i] = space;
  

  return OK;
}

STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;

  if (!game || !object) return ERROR;

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

  if (!game || !link) return ERROR;

  while ((i < MAX_LINKS) && (game->link[i] != NULL)) i++;

  game->link[i] = link;
  return OK;
}

Link *game_get_link(Game *game, Id id)
{
  int i = 0;

  if (!game || id == NO_ID) return NULL;

  for (i = 0; i < MAX_LINKS && game->link[i] != NULL; i++) {
    if (id == link_get_id(game->link[i])) {
      return game->link[i];
    }
  }
  

  return NULL;
}

int game_get_total_links(Game *game){
  int i = 0;

  if (!game) return -1;

  while ((i < MAX_LINKS) && (game->link[i] != NULL)) i++;

  return i;
}

Id game_get_link_id_at(Game *game, int position)
{

  if (!game || position < 0 || position >= MAX_LINKS) return NO_ID;

  return link_get_id(game->link[position]);
}

Id game_get_space_id_at(Game *game, int position)
{

  if (!game || position < 0 || position >= MAX_SPACES) return NO_ID;

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (!game  || id == NO_ID) return NULL;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i])) return game->spaces[i];
  }

  return NULL;
}
Object* game_get_object_from_name(Game *game, char *name){
  int i=0;
  if(!game || !name) return NULL;
  for(i=0;i<MAX_OBJECTS;i++){
    if(strcmp(object_get_name(game->objects[i]),name)==0) return game->objects[i];
  }
  return NULL;
}
int game_get_total_spaces(Game *game){
  int i = 0;

  if (!game) return -1;

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) i++;

  return i;
}

Die* game_get_die(Game* game){
  if(!game) return ERROR;
  return game->die;
}
Player* game_get_player(Game* game){
  if(!game) return NULL;
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
    if(!game || index<0 || index>MAX_OBJECTS) return NULL;
    
    return game->objects[index];
}

Object *game_get_object_by_id(Game *game, Id id){
  int i=0;
  if(!game || id<0) return NULL;
  while(game->objects[i]!=NULL){
    if(object_get_id(game->objects[i])==id){
      return game->objects[i];
    }
  i++;
  }
  return NULL;
}

Id* game_get_dependency(Game *game, Id ObjId, Id *id,int space){
  int i=0,j=0,total=inventory_get_number_of_objects(player_get_inventory(game->player));
  Id *id2;
  if(!game || ObjId<0 || !id || space<0) return NULL;
  while(id[i]!=NO_ID){
    id[i]=id[i+1];
    i++;
  }
  id2=inventory_get_inventory(player_get_inventory(game->player));
  for(j=0;j<total;j++){
    if(object_get_dependency(game_get_object_by_id(game,id2[j]))==ObjId){
      id[i]=id2[j];
      i++;
      space_set_objects(game->spaces[space], id2[j]);
      player_remove_object(game->player,id2[j]);
      j=-1;
      total=inventory_get_number_of_objects(player_get_inventory(game->player));
    }
  }
  return id;

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
  if (pos_obj == NO_ID || !game || !game_id_object_exists(game, id)) return ERROR;
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
  if (!game || !game_id_object_exists(game, id)) return NO_ID;
  while (game->spaces[k] != NULL)
  {
    if (space_has_object_id(game->spaces[k], id)) return space_get_id(game->spaces[k]); /*Se detecta la posición del objeto y se devuelve como return*/
    k++;
  }
  if(player_has_object(game->player,id)) return NO_ID;
  return NO_ID;
}

Command* game_get_command(Game* game){
  if (!game) return NULL;
  return game->command;
}

BOOL game_id_object_exists(Game *game, Id id)
{
  int i;

  if(!game || id == NO_ID) return FALSE;

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    if (object_get_id(game->objects[i]) == id) return TRUE;

  }
  return FALSE;
}

STATUS game_update(Game *game, T_Command cmd, char* arg, char *obj)
{

  if(!game) return ERROR;

  command_set_cmd(game->command,cmd);
  if(arg!=NULL && obj!=NULL){
  command_set_arg(game->command,arg);
  command_set_obj(game->command,obj);
  }
  else if(arg !=NULL && obj==NULL){
      obj[0]='\0';
      command_set_obj(game->command,obj);
  }
  else{
  arg[0]='\0';
  obj[0]='\0';
  command_set_obj(game->command,obj);
  command_set_arg(game->command,arg);

  }
 (*game_callback_fn_list[cmd])(game);
  if(dialogue_change_interaction(game->dialogue,game->command,game->player)==ERROR) return ERROR;
  return OK;
}



void game_print_data(Game *game)
{
  int i = 0;

  if(!game) return;

  printf("\n\n-------------\n\n");
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) space_print(game->spaces[i]); /*mientras haya espacios en el juego se imprimirán*/

  printf("=> Object location: %d\n", (int)game_get_object_location(game, 1));
  printf("=> Player location: %d\n", (int)game_get_player_location(game));
  printf("prompt:> ");
}

const char* game_get_last_descripcion(Game* game){
  if (!game) return  NULL;

  return game->last_descripcion;
}

STATUS game_set_last_description(Game* game , char* descr){
  if(!game || !descr) return ERROR;

  if (!strcpy(game->last_descripcion , descr)) return ERROR;

  return OK;
}

BOOL game_is_over(Game *game)
{
  return FALSE;
}
Dialogue *game_get_dialogue(Game *game){
  if(!game) return NULL;
  return game->dialogue;
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      
      if(link_get_id(space_get_south(game->spaces[i]))==-1){
        command_set_status(game->command, ERROR);
        return;
      }
      if(link_get_type(game->link[link_get_id(space_get_south(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_south(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      if(link_get_id(space_get_north(game->spaces[i]))==-1){
        command_set_status(game->command, ERROR);
        return;
      }
       if(link_get_type(game->link[link_get_id(space_get_north(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_north(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)  /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      if(link_get_id(space_get_west(game->spaces[i]))==-1){
        command_set_status(game->command, ERROR);
        return;
      }
      if(link_get_type(game->link[link_get_id(space_get_west(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_west(game->spaces[i]));  /*consigue el enlaze del espacio por la derecha*/
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);        
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)  /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      if(link_get_id(space_get_east(game->spaces[i]))==-1){
        command_set_status(game->command, ERROR);
        return;
      }
      if(link_get_type(game->link[link_get_id(space_get_east(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_east(game->spaces[i]));  /*consigue el enlaze del espacio por la izquierda*/


      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
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
    return;
  }
  while (game->objects[i] != NULL)
  {
    if (strcmp(object_get_name(game->objects[i]), objeto) == 0) /*Se buscan los objetos que tengan el mismo nombre que el señalado*/
    {
      id = object_get_id(game->objects[i]);/*Se consigue el id del objeto*/
      break;
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
      if(object_get_movement(game->objects[i])==TRUE){
        if(object_get_dependency(game->objects[i])==-1 || player_has_object(game->player,object_get_dependency(game->objects[i]))){
          player_add_object(game->player,id);
          space_remove_object(game->spaces[k], id);
          strcpy (game->last_descripcion , " ");
          command_set_status(game->command, OK);
            return;
          }
          else{
            command_set_status(game->command, ERROR);
            return;
          }
        }
        else{
          command_set_status(game->command, ERROR);
          return;
        }
      }
    }
    k++;
  }
  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  return ;

}

void game_callback_drop(Game *game)
{
   
   char objeto[WORD_SIZE];
  int k = 0, i = 0,j=0;
  Id id=NO_ID;
  Id dependency=NO_ID;
  Id *ids=(Id*)malloc(sizeof(Id)*MAX_OBJECTS);
  strcpy(objeto,command_get_arg(game->command));
  if(!game){
    command_set_status(game->command, ERROR);
    free(ids);
    return;
  }
  if (inventory_is_empty(player_get_inventory(game->player))){/*Se verifica que el player tiene algun objeto*/
    command_set_status(game->command, ERROR);
    free(ids);
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
    free(ids);
    return ;
  }

  if(!player_has_object(game->player,id)){
    command_set_status(game->command,ERROR);
    free(ids);
    return;
  }


  while (game->spaces[k] != NULL)/*Se busca el espacio*/
  {
    if (space_get_id(game->spaces[k]) == game_get_player_location(game))/*Se verifica que el jugador esta en el espacio*/
    {/*Se le quita el objeto al player y se pone en el objeto*/
      for(j=0;j<MAX_OBJECTS;j++){
        ids[j]=NO_ID;
      }
        space_set_objects(game->spaces[k], id);
        player_remove_object(game->player,id);
        ids=game_get_dependency(game,id,ids,k);
        while(ids[0]!=NO_ID){
           dependency=ids[0];
           ids=game_get_dependency(game,dependency,ids,k);
        }

      break;
    }
    k++;
  }
  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  free(ids);
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
  strcpy (game->last_descripcion , " ");
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
  if(strcmp(direction, "north")==0 || strcmp(direction, "n")==0){  /*se mueve el jugador al norte*/

    game_callback_back(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "south")==0 || strcmp(direction, "s")==0){  /*se mueve el jugador al sur*/

    game_callback_next(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "west")==0 || strcmp(direction, "w")==0){  /*se mueve el jugador al oeste*/

    game_callback_right(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "east")==0 || strcmp(direction, "e")==0){  /*se mueve el jugador al este*/
    game_callback_left(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "up")==0 || strcmp(direction, "u")==0){  /*se mueve el jugador al este*/
    game_callback_up(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  else if(strcmp(direction, "down")==0 || strcmp(direction, "dn")==0){  /*se mueve el jugador al este*/
    game_callback_down(game);
    command_set_status(game->command, command_get_status(game->command));

    return;
  }
  
  else {

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
  Id object_id;
  
  if(!game || current_id == NO_ID){
    command_set_status(game->command, ERROR);
    return;
  }
 
  strcpy(name ,command_get_arg(game->command));

  if (strcmp(name , "space") == 0 || strcmp (name , "s") ==0 ){ /*Comprobamos si se quiere inspeccionar un objeto o un espacio*/
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL ; i++){
      space_id = space_get_id (game->spaces[i]);
      if (current_id == space_id){
        if(space_get_ilumination(game->spaces[i]) == TRUE || game_player_hasIluminated_object(game) == TRUE){   
          strcpy (game->last_descripcion , space_get_detailed_description (game->spaces[i]));
          command_set_status(game->command, OK);
          return;
        }
        else {
          command_set_status(game->command, ERROR);
          return;
        }
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

  object_id = i;


  if(inventory_search_object (player_get_inventory(game->player) , id) == TRUE){
    game_set_last_description (game , (char *) object_get_description (game->objects[object_id])); /*Ponemos la ultima descripcion a la que tenga el objecto*/
    command_set_status(game->command, OK);
    return;
  }
  if(game_get_player_location (game) == game_get_object_location (game , id)){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL ; i++){
      space_id = space_get_id (game->spaces[i]);
      if(current_id == space_id){
        if(space_get_ilumination (game->spaces[i]) == TRUE){
          game_set_last_description (game , (char *) object_get_description (game->objects[object_id])); /*Ponemos la ultima descripcion a la que tenga el objecto*/
          command_set_status(game->command, OK);
          return;
        }
        else {
          command_set_status(game->command, ERROR);
          return;
        }
      }
    }
  }

  command_set_status(game->command, ERROR);
  return;
}
void game_callback_up(Game *game)
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      

      if(link_get_type(game->link[link_get_id(space_get_up(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_up(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  return;
}
void game_callback_down(Game *game)
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

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) /*comprueba que no se pase de los espacios que hay en el juego*/
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      

      if(link_get_type(game->link[link_get_id(space_get_down(game->spaces[i]))-1])==CLOSE){
        command_set_status(game->command, ERROR);
        return;
      }
      current_id = link_get_id_to(space_get_down(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
        if(space_get_ilumination (game_get_space(game,current_id)) == TRUE || game_player_hasIluminated_object(game) == TRUE){  
          strcpy (game->last_descripcion , space_get_description (game_get_space(game,current_id)));
        }
        command_set_status(game->command, OK);
        return ;
      }
      else{
        command_set_status(game->command, ERROR);
        return;
      }
    }
  }
  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  return;
}
void game_callback_turnon(Game *game){

  char objeto[WORD_SIZE];
  int ob_index;
  Id obid;
  
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  
  strcpy(objeto,command_get_arg(game->command));
  for(ob_index=0;ob_index<MAX_OBJECTS;ob_index++){
  obid=object_get_id_by_name(game->objects[ob_index], objeto);
  if(obid!=-1){
    break;

  }
  
  else if(ob_index==MAX_OBJECTS){
    command_set_status(game->command, ERROR);
    
    return;

  }
  }
  if(player_has_object(game->player, obid)==FALSE) { /*Se verifica que el jugador tenga el objeto*/
    command_set_status(game->command, ERROR);
    return;
  }
  if(object_get_iluminate(game_get_object(game, ob_index))==FALSE){ /*Se verifica que el objeto pueda ser iliminado*/
    command_set_status(game->command, ERROR);
    return;

  }
  if(object_get_turnedon(game_get_object(game, ob_index))==TRUE){

    command_set_status(game->command, ERROR);
    return;
  }
  object_set_turnedon(game_get_object(game, ob_index), TRUE);


  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  return ;

}
void game_callback_turnoff(Game *game){

  char objeto[WORD_SIZE];
  int  ob_index;
  Id obid;
  if(!game){
    command_set_status(game->command, ERROR);
    return;
  }
  
  strcpy(objeto,command_get_arg(game->command));
  for(ob_index=0;ob_index<MAX_OBJECTS;ob_index++){
  obid=object_get_id_by_name(game->objects[ob_index], objeto);
  if(obid!=-1){
    break;

  }
  
  
  else if(ob_index==MAX_OBJECTS){
    command_set_status(game->command, ERROR);
    
    return;

  }
  }
  if(player_has_object(game->player, obid)==FALSE) { /*Se verifica que el jugador tenga el objeto*/
    command_set_status(game->command, ERROR);
    return;
  }
  if(object_get_turnedon(game_get_object(game, ob_index))==FALSE){

    command_set_status(game->command, ERROR);
    return;
  }
  
  object_set_turnedon(game_get_object(game, ob_index), FALSE);
 
  strcpy (game->last_descripcion , " ");
  command_set_status(game->command, OK);
  return;

}

BOOL game_player_hasIluminated_object(Game *g){

  int i;
  if(!g)return FALSE;

  for(i=0;g->objects[i]!=NULL;i++){
  if(player_has_object(g->player, object_get_id(g->objects[i]))==TRUE){

    if(object_get_turnedon(game_get_object(g, i))==TRUE)return TRUE;


  }
  }
  return FALSE;
}

void game_callback_open(Game *game){


  int i=0,j=0;
  Id idObj=-1;
  char objeto[WORD_SIZE],link[WORD_SIZE];
    if(!game){
    command_set_status(game->command,ERROR);
    return;
  }
  strcpy(objeto,command_get_obj(game->command));
  strcpy(link,command_get_arg(game->command));
    while (game->objects[i] != NULL)
  {
    if (strcmp(object_get_name(game->objects[i]), objeto) == 0) /*Se buscan los objetos que tengan el mismo nombre que el señalado*/
    {
      idObj = object_get_id(game->objects[i]);/*Se consigue el id del objeto*/
      break;
    }
    i++;
    }

  if(idObj==-1 || player_has_object(game->player,idObj)==FALSE){
    command_set_status(game->command,ERROR);
    return;
  }


  while (game->link[j] != NULL)
  {
     
    if (strcmp(link_get_name(game->link[j]), link) == 0) /*Se buscan los links que tengan el mismo nombre que el señalado*/
    {
     
      break;
    }
    j++;
    }
  if(link_get_type(game->link[j])==OPEN){
    command_set_status(game->command,ERROR);
    return;
  }
  if(object_get_link_open(game->objects[i])==link_get_id(game->link[j])){
    link_set_type(game->link[j],OPEN);
    player_remove_object(game_get_player(game),object_get_id(game->objects[i]));
    game_set_object_location(game, object_get_id(game->objects[i]), 99);
    if(strcmp(object_get_name(game->objects[i]),"C4")==0){
      player_remove_object(game_get_player(game),object_get_id(game->objects[1]));
      game_set_object_location(game, object_get_id(game->objects[1]), 99);
    }
    strcpy (game->last_descripcion , " ");
    command_set_status(game->command,OK);
    return;
  }
  else{
    command_set_status(game->command,ERROR);
    return;
  }
}


void game_callback_save(Game *game){

  char filename[WORD_SIZE];

  if (!game){
    command_set_status(game->command,ERROR);
    return;
  }

  strcpy(filename,command_get_arg(game->command));
  if(strlen(filename)==0){
    command_set_status(game->command,ERROR);
    return;

  }
  if (game_management_save(game,filename)==ERROR){
    command_set_status(game->command,ERROR);
    return;
  }

  strcpy (game->last_descripcion , " ");
  command_set_status(game->command,OK);

  return;
}

void game_callback_load(Game *game){

  char filename[WORD_SIZE];

  if (!game){
    command_set_status(game->command,ERROR);
    return;
  }

  strcpy(filename,command_get_arg(game->command));

   if(strlen(filename)==0){
    command_set_status(game->command,ERROR);
    return;

  }
  if (game_management_load(game,filename)==ERROR){
    command_set_status(game->command,ERROR);
    return;
  }

  strcpy (game->last_descripcion , " ");
  command_set_status(game->command,OK);

  return;
}


void game_callback_build(Game *game){

  

  if (!game){
    command_set_status(game->command,ERROR);
    return;
  }
  if(strcmp(command_get_arg(game_get_command(game)),"Antorcha")==0 || strcmp(command_get_arg(game_get_command(game)),"antorcha")==0){
    if(player_has_object(game_get_player(game),object_get_id(game->objects[1])) && player_has_object(game_get_player(game),object_get_id(game->objects[2])) && player_has_object(game_get_player(game),object_get_id(game->objects[3]))){
        object_set_description(game->objects[1],"Ya puedo iluminar las salas");
        object_set_iluminate(game->objects[1],TRUE);
        object_set_name(game->objects[1],"Antorcha");
        player_remove_object(game_get_player(game),object_get_id(game->objects[2]));
        player_remove_object(game_get_player(game),object_get_id(game->objects[3]));
        game_set_object_location(game, object_get_id(game->objects[2]), 99);
        game_set_object_location(game, object_get_id(game->objects[3]), 99);
        strcpy (game->last_descripcion , " ");
        command_set_status(game_get_command(game),OK);
        return;
        
    }
  }
 else if(strcmp(command_get_arg(game_get_command(game)),"C4")==0){
      if(player_has_object(game_get_player(game),object_get_id(game->objects[8])) && player_has_object(game_get_player(game),object_get_id(game->objects[9])) && player_has_object(game_get_player(game),object_get_id(game->objects[10]))){
        object_set_description(game->objects[8],"Un explosivo C4");
        object_set_iluminate(game->objects[8],FALSE);
        object_set_name(game->objects[8],"C4");
        object_set_link_open(game->objects[8],6);
        player_remove_object(game_get_player(game),object_get_id(game->objects[9]));
        player_remove_object(game_get_player(game),object_get_id(game->objects[10]));
        game_set_object_location(game, object_get_id(game->objects[9]), 99);
        game_set_object_location(game, object_get_id(game->objects[10]), 99);
        strcpy (game->last_descripcion , " ");
        command_set_status(game_get_command(game),OK);
        return;
        
    }


  }
  else if(strcmp(command_get_arg(game_get_command(game)),"Pico")==0 || strcmp(command_get_arg(game_get_command(game)),"pico")==0){
    if(player_has_object(game_get_player(game),object_get_id(game->objects[13])) && player_has_object(game_get_player(game),object_get_id(game->objects[14])) && player_has_object(game_get_player(game),object_get_id(game->objects[15])) && player_has_object(game_get_player(game),object_get_id(game->objects[16]))){
        object_set_description(game->objects[13],"Pico para romper muros");
        object_set_iluminate(game->objects[13],TRUE);
        object_set_name(game->objects[13],"Pico");
        object_set_link_open(game->objects[13],9);
        player_remove_object(game_get_player(game),object_get_id(game->objects[14]));
        player_remove_object(game_get_player(game),object_get_id(game->objects[15]));
        player_remove_object(game_get_player(game),object_get_id(game->objects[16]));
        game_set_object_location(game, object_get_id(game->objects[14]), 55);
        game_set_object_location(game, object_get_id(game->objects[15]), 99);
        game_set_object_location(game, object_get_id(game->objects[16]), 99);
        strcpy (game->last_descripcion , " ");
        command_set_status(game_get_command(game),OK);
        return;
        
    }
  }
 else  if(strcmp(command_get_arg(game_get_command(game)),"Escalera")==0 || strcmp(command_get_arg(game_get_command(game)),"escalera")==0){
     if(player_has_object(game_get_player(game),object_get_id(game->objects[14])) && player_has_object(game_get_player(game),object_get_id(game->objects[17])) ){
        object_set_description(game->objects[14],"Escalera para subir a sitios");
        object_set_iluminate(game->objects[14],TRUE);
        object_set_name(game->objects[14],"Escalera");
        object_set_link_open(game->objects[14],11);
        player_remove_object(game_get_player(game),object_get_id(game->objects[17]));
        game_set_object_location(game, object_get_id(game->objects[17]), 99);
        strcpy (game->last_descripcion , " ");
        command_set_status(game_get_command(game),OK);
        return;
        
    }
  }
    command_set_status(game_get_command(game),ERROR);
    return;
}

void game_callback_use(Game *game){
  if (!game){
    command_set_status(game->command,ERROR);
    return;
  }
  if(player_get_location(game->player)==9 && player_has_object(game->player,object_get_id(game->objects[4]))){
    link_set_type(game->link[2],OPEN);
    strcpy (game->last_descripcion , " ");
    command_set_status(game_get_command(game),OK);
    return;
  }
  if(player_get_location(game->player)==18 && player_has_object(game->player,object_get_id(game->objects[6]))){
    link_set_type(game->link[6],OPEN);
    player_remove_object(game_get_player(game),object_get_id(game->objects[6]));
    game_set_object_location(game, object_get_id(game->objects[6]), 99);
    strcpy (game->last_descripcion , " ");
    command_set_status(game_get_command(game),OK);
    return;
  }
  if(player_get_location(game->player)==45 && strcmp(command_get_arg(game_get_command(game)),"345")==0){
    link_set_type(game->link[9],OPEN);
    strcpy (game->last_descripcion , " ");
    command_set_status(game_get_command(game),OK);
    return;
  }
if(player_get_location(game->player)==65 && strcmp(command_get_arg(game_get_command(game)),"12")==0){
    object_set_dependency(game->objects[19],-1);
    strcpy (game->last_descripcion , " ");
    command_set_status(game_get_command(game),OK);
    return;
  }
  command_set_status(game_get_command(game),ERROR);
    return;
}