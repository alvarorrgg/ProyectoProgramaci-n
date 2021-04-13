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
#include "link.h"

#define MAX_CHARS1 19 /*Numero maximo de caracteres que se pueden escribir en cada linea del espacio*/
#define MAX_CHARS2 3  /*Numero maximo de caracteres que van a tener los links*/
#define MAX_CHARS3 7  /*Numero maximo de caracteres que van a tener los links + las flechas*/

/**
 * @brief carácteristicas del motor gráfico
 *
 * Contiene la información necesaria del motor gráfico
 */
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

  ge->map = screen_area_init(1, 1, 48, 35);       /*mapa de la oca*/
  ge->descript = screen_area_init(50, 1, 29, 35); /*parte donde se pintan las jugadas y tal*/
  ge->banner = screen_area_init(28, 37, 23, 1);   /*"The game of the Goose"*/
  ge->help = screen_area_init(1, 38, 78, 2);      /*The----left or l*/
  ge->feedback = screen_area_init(1, 41, 78, 3);  /*comandos*/

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
  int i = 0;
  int sum = 0;
  int num_objects = 0;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Id *id_objetos;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  char **gdesc;
  char obj[MAX_OBJECTS][MAX_CHARS1];
  char str[MAX_CHARS];
  char espacios_back[MAX_CHARS1], espacios_act[MAX_CHARS1], espacios_next[MAX_CHARS1]; /*Servira para llevar recuento de los objetos en un espacio*/
  T_Command last_cmd = UNKNOWN;
  Link *link1 = NULL;
  Link *link2 = NULL;
  char id1[MAX_CHARS2], id2[MAX_CHARS2], id_to1[MAX_CHARS3], id_to2[MAX_CHARS3];
  extern char *cmd_to_str[N_CMD][N_CMDT]; /*Variable traida del modulo command para el tratado de comandos*/
  memset(espacios_back, 0, MAX_CHARS1);
  memset(espacios_act, 0, MAX_CHARS1);
  memset(espacios_next, 0, MAX_CHARS1);
  num_objects = game_get_total_objects(game);
  /* Pintar en el área del mapa */
  screen_area_clear(ge->map);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);
  sprintf(str, "      ");
  screen_area_puts(ge->map, str);

  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = link_get_to(space_get_north(space_act));
    space_back = game_get_space(game, id_back);
    id_next = link_get_to(space_get_south(space_act));
    space_next = game_get_space(game, id_next);
    for (i = 0; i < num_objects + 1; i++)
    {
      if (space_has_object_id(space_back, i))
        strcpy(obj[i], object_get_name(game_get_object(game, i - 1)));
      else
        strcpy(obj[i], "");
    }
    for (i = 0; i < num_objects + 1; i++)
    {
      sum = sum + strlen(obj[i]);
      if (strlen(obj[i]) != 0)
        sum = sum + 1;
    }
    if (sum > MAX_CHARS1)
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcpy(espacios_back, obj[i]);
        if (strlen(espacios_back) != 0)
          break;
      }

      strcat(espacios_back, "...");
      while (strlen(espacios_back) < MAX_CHARS1)
        strcat(espacios_back, " ");
    }
    else
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcat(espacios_back, obj[i]);
        if (strlen(obj[i]) != 0)
          strcat(espacios_back, " ");
      }
    }
    while (strlen(espacios_back) < MAX_CHARS1)
      strcat(espacios_back, " ");
    if (id_back != NO_ID)
    {

      gdesc = space_get_gdesc(space_back);
      link1 = space_get_west(space_back);
      sprintf(id_to1, " %ld", link_get_to(link1));
      if (strcmp(id_to1, " -1") == 0)
        strcpy(id_to1, "      ");
      else
        strcat(id_to1, " <--");
      sprintf(id1, "%ld", link_get_id(link1));
      if (strcmp(id1, "-1") == 0)
        strcpy(id1, "  ");

      link2 = space_get_east(space_back);

      sprintf(id_to2, "%ld", link_get_to(link2));
      if (strcmp(id_to2, "-1") == 0)
        strcpy(id_to2, "      ");

      else
      {
        sprintf(id_to1, "%ld", link_get_to(link2));
        strcpy(id_to2, "--> ");
        strcat(id_to2, id_to1);
        strcpy(id_to1, "      ");
      }
      sprintf(id2, "%ld", link_get_id(link2));
      if (strcmp(id2, "-1") == 0)
        strcpy(id2, "  ");

      sprintf(str, "           %s|                 %2d|%s", id1, (int)id_back, id2);
      screen_area_puts(ge->map, str);
      sprintf(str, "       %s|    %s        |%s", id_to1, gdesc[0], id_to2);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |%s|", espacios_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "             +-------------------+");
      screen_area_puts(ge->map, str);
      link2 = space_get_north(space_act);
      sprintf(id2, "%ld", link_get_id(link2));
      sprintf(str, "                      ^ %s", id2);
      screen_area_puts(ge->map, str);
    }
    sum = 0;
    for (i = 0; i < num_objects + 1; i++)
    {
      if (space_has_object_id(space_act, i))
        strcpy(obj[i], object_get_name(game_get_object(game, i - 1)));
      else
        strcpy(obj[i], "");
    }
    for (i = 0; i < num_objects + 1; i++)
    {
      sum = sum + strlen(obj[i]);
      if (strlen(obj[i]) != 0)
        sum = sum + 1;
    }
    if (sum > MAX_CHARS1)
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcpy(espacios_act, obj[i]);
        if (strlen(espacios_act) != 0)
          break;
      }

      strcat(espacios_act, "...");
      while (strlen(espacios_act) < MAX_CHARS1)
        strcat(espacios_act, " ");
    }
    else
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcat(espacios_act, obj[i]);
        if (strlen(obj[i]) != 0)
          strcat(espacios_act, " ");
      }
    }
    while (strlen(espacios_act) < MAX_CHARS1)
      strcat(espacios_act, " ");

    if (id_act != NO_ID)
    {
      gdesc = space_get_gdesc(space_act);
      link1 = space_get_west(space_act);
      sprintf(id_to1, " %ld", link_get_to(link1));
      if (strcmp(id_to1, " -1") == 0)
        strcpy(id_to1, "      ");
      else
        strcat(id_to1, " <--");
      sprintf(id1, "%ld", link_get_id(link1));
      if (strcmp(id1, "-1") == 0)
        strcpy(id1, "  ");

      link2 = space_get_east(space_act);

      sprintf(id_to2, "%ld", link_get_to(link2));
      if (strcmp(id_to2, "-1") == 0)
        strcpy(id_to2, "      ");

      else
      {
        sprintf(id_to1, "%ld", link_get_to(link2));
        strcpy(id_to2, "--> ");
        strcat(id_to2, id_to1);
        strcpy(id_to1, "      ");
      }
      sprintf(id2, "%ld", link_get_id(link2));
      if (strcmp(id2, "-1") == 0)
        strcpy(id2, "  ");
      sprintf(str, "           %s+-------------------+%s", id1, id2);
      screen_area_puts(ge->map, str);
      sprintf(str, "       %s|          UwU    %2d|%s", id_to1, (int)id_act, id_to2);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |%s|", espacios_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "             +-------------------+");
      screen_area_puts(ge->map, str);
    }
    sum = 0;
    for (i = 0; i < num_objects + 1; i++)
    {
      if (space_has_object_id(space_next, i))
        strcpy(obj[i], object_get_name(game_get_object(game, i - 1)));
      else
        strcpy(obj[i], "");
    }
    for (i = 0; i < num_objects + 1; i++)
    {
      sum = sum + strlen(obj[i]);
      if (strlen(obj[i]) != 0)
        sum = sum + 1;
    }
    if (sum > MAX_CHARS1)
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcpy(espacios_next, obj[i]);
        if (strlen(espacios_next) != 0)
          break;
      }

      strcat(espacios_next, "...");
      while (strlen(espacios_next) < MAX_CHARS1)
        strcat(espacios_next, " ");
    }
    else
    {
      for (i = 0; i < num_objects + 1; i++)
      {
        strcat(espacios_next, obj[i]);
        if (strlen(obj[i]) != 0)
          strcat(espacios_next, " ");
      }
    }
    while (strlen(espacios_next) < MAX_CHARS1)
      strcat(espacios_next, " ");
    if (id_next != NO_ID)
    {
      gdesc = space_get_gdesc(space_next);
      link1 = space_get_west(space_next);
      sprintf(id_to1, " %ld", link_get_to(link1));
      if (strcmp(id_to1, " -1") == 0)
        strcpy(id_to1, "      ");
      else
        strcat(id_to1, " <--");
      sprintf(id1, "%ld", link_get_id(link1));
      if (strcmp(id1, "-1") == 0)
        strcpy(id1, "  ");

      link2 = space_get_east(space_next);

      sprintf(id_to2, "%ld", link_get_to(link2));
      if (strcmp(id_to2, "-1") == 0)
        strcpy(id_to2, "      ");

      else
      {
        sprintf(id_to1, "%ld", link_get_to(link2));
        strcpy(id_to2, "--> ");
        strcat(id_to2, id_to1);
        strcpy(id_to1, "      ");
      }
      link2 = space_get_south(space_act);
      sprintf(id2, "%ld", link_get_id(link2));

      sprintf(str, "                      v %s", id2);
      screen_area_puts(ge->map, str);

      link2 = space_get_east(space_next);
      sprintf(id2, "%ld", link_get_id(link2));
      if (strcmp(id2, "-1") == 0)
        strcpy(id2, "  ");
      sprintf(str, "           %s+-------------------+%s", id1, id2);
      screen_area_puts(ge->map, str);
      sprintf(str, "       %s|                 %2d|%s", id_to1, (int)id_next, id_to2);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |    %s        |", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "             |%s|", espacios_next);
      screen_area_puts(ge->map, str);
    }
  }

  /* Pinta en el área de la despcripción */
  screen_area_clear(ge->descript);
  sprintf(str, "  Object locations: ");
  /*Comprobamos que el objeto no esta en el player y en caso de no estarlo mostramos donde se encuentra*/
  for (i = 0; i < MAX_OBJECTS - 1; i++)
  {
    if ((obj_loc = game_get_object_location(game, i)) != NO_ID)
    {
      sprintf(str, "  %s: %d", object_get_name(game_get_object(game, i - 1)), (int)obj_loc);
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /*Mostramos el ultimo roll del dado 0 en el primer caso*/
  if ((int)die_get_last_roll(game_get_die(game)) == -1)
    sprintf(str, "Last roll of dice: 0");
  else
    sprintf(str, "Last roll of dice: %d", (int)die_get_last_roll(game_get_die(game)));
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  if (inventory_get_number_of_objects(player_get_inventory(game_get_player(game))) == 0)
  {
    sprintf(str, "Player has no objects");
    screen_area_puts(ge->descript, str);
  }
  else
  {
    sprintf(str, "This is the inventory of the player: ");
    screen_area_puts(ge->descript, str);
    id_objetos = inventory_get_inventory(player_get_inventory(game_get_player(game)));
    for (i = 0; i < inventory_get_number_of_objects(player_get_inventory(game_get_player(game))); i++)
    {
      sprintf(str, "                                   %i:%s", i + 1, object_get_name(game_get_object(game, id_objetos[i] - 1)));
      screen_area_puts(ge->descript, str);
    }
  }

  if (strlen(game_get_last_descripcion(game)) != 0)
  {
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "%s", game_get_last_descripcion(game));
    screen_area_puts(ge->descript, str);
  }

  /* Pinta en el área del banner */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Pinta en el área de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "next or n, back or b, exit or e, take or t, drop or d,roll or rl,left or l,right or r,move or m, inspect or i"); /*Se escriben los comandos posibles*/
  screen_area_puts(ge->help, str);

  /* Pinta en el área de comentarios */
  /*Almacenamos el comando, comprobamos que no es NoCommand, obtenemos el estatus y llamamos a la función cmd_to_str para pintar el comando con su estatus*/
  last_cmd = command_get_cmd(game_get_command(game));
  if (last_cmd != -1)
  {
     if (command_get_status(game_get_command(game)) != 1)
    {
      if(strlen(command_get_arg(game_get_command(game)))==1){
      sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    }
      else{
        sprintf(str, " %s (%s) %s: ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], command_get_arg(game_get_command(game)));

      }
    }
    else{
      if(strlen(command_get_arg(game_get_command(game)))==1){
      sprintf(str, " %s (%s): OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);

    }
      else{
        sprintf(str, " %s (%s) %s: OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], command_get_arg(game_get_command(game)));

      }
      
    
    }
    screen_area_puts(ge->feedback, str);
  }
  /* Volcarlo en la terminal */
  screen_paint();
  printf("prompt:> ");
}
