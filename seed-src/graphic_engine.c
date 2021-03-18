/**
 * @brief Define un motor gráfico textual
 *
 * @file graphic_engine.c
 * @author Álvaro Rodríguez Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"
#include "command.h"

#define MAX_CHARS1 11 /*Numero maximo de caracteres que se pueden escribir en cada linea del espacio*/

struct _Graphic_engine
{
  Area *map;      /*!< el mapa */
  Area *descript; /*!< la descripción */
  Area *banner;   /*!< el banner */
  Area *help;     /*!< la ayuda */
  Area *feedback; /*!< los comentarios */
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 25);       /*mapa de la oca*/
  ge->descript = screen_area_init(50, 1, 29, 25); /*parte donde se pintan las jugadas y tal*/
  ge->banner = screen_area_init(28, 27, 23, 1);   /*"The game of the Goose"*/
  ge->help = screen_area_init(1, 28, 78, 2);      /*The----left or l*/
  ge->feedback = screen_area_init(1, 31, 78, 3);  /*comandos*/

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}
/*Hemos implementado el graphic enginge de manera que los objetos puedan tener el nombre que se quiera(dentro de unos requisitos) y el programa no se vea afectado por estos cambios*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  char **gdesc;
  char obj[MAX_CHARS1],obj1[MAX_CHARS1],obj2[MAX_CHARS1],obj3[MAX_CHARS1];/*Nombre de cada objeto*/
  char str[MAX_CHARS];
  char espacios_back[MAX_CHARS1],espacios_act[MAX_CHARS1],espacios_next[MAX_CHARS1];/*Servira para llevar recuento de los objetos en un espacio*/
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT]; /*Variable traida del modulo command para el tratado de comandos*/

  /* Pintar en el área del mapa */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    space_back = game_get_space(game, id_back);
    id_next = space_get_south(space_act);
    space_next = game_get_space(game, id_next);
/*Obtenemos el nombre de cada objeto o "" si no hay ningun objeto*/
    if (space_has_object_id(space_back,1)) strcpy(obj,object_get_name(game_get_object(game, 0)));
    else strcpy(obj,"");
    if (space_has_object_id(space_back,2)) strcpy(obj1,object_get_name(game_get_object(game, 1)));
    else strcpy(obj1,"");
    if (space_has_object_id(space_back,3))strcpy(obj2,object_get_name(game_get_object(game, 2)));
    else strcpy(obj2,"");
    if (space_has_object_id(space_back,4))strcpy(obj3,object_get_name(game_get_object(game, 3)));
    else strcpy(obj3,"");
 /*Vemos si la suma de todos los objetos es mayor que la cantidad de espacio que tenemos en caso afirmativo se escribe un objeto y ...*/
    if(strlen(obj1)+strlen(obj2)+strlen(obj)+strlen(obj3)+strlen("    ")>MAX_CHARS1){
      strcpy(espacios_back, obj);
      if(strlen(espacios_back)==0){
        strcpy(espacios_back, obj1);
        if(strlen(espacios_back)==0){
          strcpy(espacios_back, obj2);
          if(strlen(espacios_back)==0){
            strcpy(espacios_back, obj3);
          }
        }
      }
      strcat(espacios_back, "...");
      while (strlen(espacios_back)<MAX_CHARS1) strcat(espacios_back, " ");
       
    }
    else{ /*En caso negativo se pueden escribir todos los objetos sin ningun problema*/
      strcat(espacios_back, obj);
      strcat(espacios_back, " ");
      strcat(espacios_back, obj1);
      strcat(espacios_back, " ");
      strcat(espacios_back, obj2);
      strcat(espacios_back, " ");
      strcat(espacios_back, obj3);
    }
     while (strlen(espacios_back)<MAX_CHARS1) strcat(espacios_back, " ");
    if (id_back != NO_ID)
    {
      gdesc = space_get_gdesc(space_back);
      sprintf(str, "  |       C:%2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|",espacios_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
/*Obtenemos el nombre de cada objeto o "" si no hay ningun objeto*/
     if (space_has_object_id(space_act,1))strcpy(obj,object_get_name(game_get_object(game, 0)));
    else strcpy(obj,"");
    if (space_has_object_id(space_act,2))strcpy(obj1,object_get_name(game_get_object(game, 1)));
    else strcpy(obj1,"");
    if (space_has_object_id(space_act,3))strcpy(obj2,object_get_name(game_get_object(game, 2)));
    else strcpy(obj2,"");
    if (space_has_object_id(space_act,4))strcpy(obj3,object_get_name(game_get_object(game, 3)));
    else strcpy(obj3,"");
/*Vemos si la suma de todos los objetos es mayor que la cantidad de espacio que tenemos en caso afirmativo se escribe un objeto y ...*/
 if(strlen(obj1)+strlen(obj2)+strlen(obj)+strlen(obj3)+strlen("    ")>MAX_CHARS1){
      strcpy(espacios_act, obj);
      if(strlen(espacios_act)==0){
        strcpy(espacios_act, obj1);
        if(strlen(espacios_act)==0){
          strcpy(espacios_act, obj2);
          if(strlen(espacios_act)==0){
            strcpy(espacios_act, obj3);
          }
        }
      }
      strcat(espacios_act, "...");
      while (strlen(espacios_act)<MAX_CHARS1)strcat(espacios_act, " ");
         
    }
    else{/*En caso negativo se pueden escribir todos los objetos sin ningun problema*/
      strcat(espacios_act, obj);
      strcat(espacios_act, " ");
      strcat(espacios_act, obj1);
      strcat(espacios_act, " ");
      strcat(espacios_act, obj2);
      strcat(espacios_act, " ");
      strcat(espacios_act, obj3);
    }
     while (strlen(espacios_act)<MAX_CHARS1) strcat(espacios_act, " ");
      
    if (id_act != NO_ID)
    {
      gdesc = space_get_gdesc(space_act);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | ^_^   C:%2d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|",espacios_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
/*Obtenemos el nombre de cada objeto o "" si no hay ningun objeto*/
     if (space_has_object_id(space_next,1))strcpy(obj,object_get_name(game_get_object(game, 0)));
    else strcpy(obj,"");
    if (space_has_object_id(space_next,2))strcpy(obj1,object_get_name(game_get_object(game, 1)));
    else strcpy(obj1,"");
    if (space_has_object_id(space_next,3))strcpy(obj2,object_get_name(game_get_object(game, 2)));
    else strcpy(obj2,"");
    if (space_has_object_id(space_next,4))strcpy(obj3,object_get_name(game_get_object(game, 3)));
    else strcpy(obj3,"");
/*Vemos si la suma de todos los objetos es mayor que la cantidad de espacio que tenemos en caso afirmativo se escribe un objeto y ...*/
 if(strlen(obj1)+strlen(obj2)+strlen(obj)+strlen(obj3)+strlen("    ")>MAX_CHARS1){
      strcpy(espacios_next, obj);
      if(strlen(espacios_next)==0){
        strcpy(espacios_next, obj1);
        if(strlen(espacios_next)==0){
          strcpy(espacios_next, obj2);
          if(strlen(espacios_next)==0){
            strcpy(espacios_next, obj3);
          }
        }
      }
      strcat(espacios_next, "...");
      while (strlen(espacios_next)<MAX_CHARS1-1) strcat(espacios_next, " ");
      
    }
    else{/*En caso negativo se pueden escribir todos los objetos sin ningun problema*/
      strcat(espacios_next, obj);
      strcat(espacios_next, " ");
      strcat(espacios_next, obj1);
      strcat(espacios_next, " ");
      strcat(espacios_next, obj2);
      strcat(espacios_next, " ");
      strcat(espacios_next, obj3);
    }

     while (strlen(espacios_next)<MAX_CHARS1-1)
      {
        strcat(espacios_next, " ");
      }  
    if (id_next != NO_ID)
    {
      gdesc = space_get_gdesc(space_next);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |       C:%2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s |",espacios_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
  }

  /* Pinta en el área de la despcripción */
  screen_area_clear(ge->descript);
  sprintf(str, "  Object locations: ");
/*Comprobamos que el objeto no esta en el player y en caso de no estarlo mostramos donde se encuentra*/
  if ((obj_loc = game_get_object_location(game, 1)) != NO_ID)
  {
    sprintf(str, "  %s: %d", object_get_name(game_get_object(game, 0)),(int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
if ((obj_loc = game_get_object_location(game, 2)) != NO_ID)
  {
    sprintf(str, "  %s: %d", object_get_name(game_get_object(game, 1)),(int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  if ((obj_loc = game_get_object_location(game, 3)) != NO_ID)
  {
    sprintf(str, "  %s: %d", object_get_name(game_get_object(game, 2)),(int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  if ((obj_loc = game_get_object_location(game, 4)) != NO_ID)
  {
    sprintf(str, "  %s: %d", object_get_name(game_get_object(game, 3)),(int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

/*Mostramos el ultimo roll del dado 0 en el primer caso*/
    if((int)die_get_last_roll(game_get_die(game))==-1) sprintf(str, "Last roll of dice: 0");
    else sprintf(str, "Last roll of dice: %d",(int)die_get_last_roll(game_get_die(game)));
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
/*Verificamos que el player tiene algun objeto en caso de tenerlo se escribe*/
    if((int)player_get_object(game_get_player(game))!=-1) sprintf(str, "Player has object: %d",(int)player_get_object(game_get_player(game)));
   screen_area_puts(ge->descript, str);
   
  /* Pinta en el área del banner */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Pinta en el área de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "next or n, back or b, exit or e, take or t, drop or d,roll or rl,left or l,right or r"); /*Se escriben los comandos posibles*/
  screen_area_puts(ge->help, str);

  /* Pinta en el área de comentarios */
/*Almacenamos el comando, comprobamos que no es NoCommand, obtenemos el estatus y llamamos a la función cmd_to_str para pintar el comando con su estatus*/
  last_cmd = command_get_cmd(game_get_command(game));
  if(last_cmd!=-1){
  if(command_get_status(game_get_command(game))!=1){
  sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  }
  else sprintf(str, " %s (%s) OK ", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);
}
  /* Volcarlo en la terminal */
  screen_paint();
  printf("prompt:> ");
 
}
