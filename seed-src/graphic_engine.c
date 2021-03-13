#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "graphic_engine.h"
#include "command.h"

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

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  char **gdesc;
  char **obj = NULL;
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  obj = (char **)malloc(4 * sizeof(char *));
  obj[0] = (char *)malloc(3 * sizeof(char));
  obj[1] = (char *)malloc(3 * sizeof(char));
  obj[2] = (char *)malloc(3 * sizeof(char));
  obj[3] = (char *)malloc(3 * sizeof(char));


  /* Pintar en el área del mapa */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    space_back = game_get_space(game, id_back);
    id_next = space_get_south(space_act);
    space_next = game_get_space(game, id_next);

    if (game_get_object_location(game, 1) == id_back) obj[0] = "O1";
    else obj[0] = "  ";
    if (game_get_object_location(game, 2) == id_back)obj[1] = "O2";
    else obj[1] = "  " ;
    if (game_get_object_location(game, 3) == id_back) obj[2] = "O3";
    else obj[2] = "  ";
    if (game_get_object_location(game, 4) == id_back) obj[3] = "O4";
    else obj[3] = "  ";

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
      sprintf(str, "  |%s %s %s %s|", obj[0],obj[1],obj[2],obj[3]);
       screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game, 1) == id_act) obj[0] = "O1";
    else obj[0] = "  ";
    if (game_get_object_location(game, 2) == id_act)obj[1] = "O2";
    else obj[1] = "  " ;
    if (game_get_object_location(game, 3) == id_act) obj[2] = "O3";
    else obj[2] = "  ";
    if (game_get_object_location(game, 4) == id_act) obj[3] = "O4";
    else obj[3] = "  ";

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
      sprintf(str, "  |%s %s %s %s|", obj[0],obj[1],obj[2],obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game, 1) == id_next) obj[0] = "O1";
    else obj[0] = "  ";
    if (game_get_object_location(game, 2) == id_next)obj[1] = "O2";
    else obj[1] = "  " ;
    if (game_get_object_location(game, 3) == id_next) obj[2] = "O3";
    else obj[2] = "  ";
    if (game_get_object_location(game, 4) == id_next) obj[3] = "O4";
    else obj[3] = "  ";

    if (id_next != NO_ID)
    {
      gdesc = space_get_gdesc(space_next);
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
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
      sprintf(str, "  |%s %s %s %s|", obj[0],obj[1],obj[2],obj[3]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
  }
  free(obj);
  /* Pinta en el área de la despcripción */
  screen_area_clear(ge->descript);
  sprintf(str, "  Object locations: ");
  if ((obj_loc = game_get_object_location(game, 1)) != NO_ID)
  {
    sprintf(str, "  Object 1: %d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
if ((obj_loc = game_get_object_location(game, 2)) != NO_ID)
  {
    sprintf(str, "  Object 2: %d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  if ((obj_loc = game_get_object_location(game, 3)) != NO_ID)
  {
    sprintf(str, "  Object 3: %d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  if ((obj_loc = game_get_object_location(game, 4)) != NO_ID)
  {
    sprintf(str, "  Object 4: %d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);


    if((int)die_get_last_roll(game_get_die(game))==-1) sprintf(str, "Last roll of dice: 0");
    else sprintf(str, "Last roll of dice: %d",(int)die_get_last_roll(game_get_die(game)));
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    if((int)player_get_object(game_get_player(game))!=-1) sprintf(str, "Player has object: %d",(int)player_get_object(game_get_player(game)));

   screen_area_puts(ge->descript, str);
  /* Pinta en el área del banner */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Pinta en el área de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, exit or e, take or t, drop or d");
  screen_area_puts(ge->help, str);

  /* Pinta en el área de comentarios */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Volcarlo en la terminal */
  screen_paint();
  printf("prompt:> ");
  
}
