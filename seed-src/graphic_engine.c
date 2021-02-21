#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "graphic_engine.h"
#include "command.h"

/**
 * @brief carácteristicas del motor gráfico
 *
 * Contiene la información necesaria del motor gráfico
 */
struct _Graphic_engine{
  Area *map,		/*!< el mapa */
  Area *descript,	/*!< la descripción */
  Area *banner,	/*!< el banner */
  Area *help,		/*!< la ayuda */
  Area *feedback;	/*!< los comentarios */
};

/**
 * @brief crea el motor gráfico
 *
 * graphic_engine_create crea un motor gráfico de 0
 *
 * @date
 * @author Profesores PPROG 
 *
 * @return ge el motor gráfico
 */
Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map      = screen_area_init( 1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner   = screen_area_init(28,15, 23,  1);
  ge->help     = screen_area_init( 1,16, 78,  2);
  ge->feedback = screen_area_init( 1,19, 78,  3);

  return ge;
}

/**
 * @brief destruye el motor gráfico
 *
 * graphic_engine_destroy destruye un motor gráfico
 *
 * @date
 * @author Profesores PPROG 
 *
 * @param ge el motor gráfico que se va a destruir
 */
void graphic_engine_destroy(Graphic_engine *ge){
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

/**
 * @brief imprime por pantalla el juego a partir del motor gráfico
 *
 * graphic_engine_paint_game muestra por pantalla el juego creado
 *
 * @date
 * @author Profesores PPROG 
 *
 * @param ge el motor gráfico que se utiliza
 * @param game el juego que se muestra por pantalla
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space* space_act = NULL;
  char obj='\0';
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];


  /* Pintar en el área del mapa */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    if (game_get_object_location(game) == id_back)
      obj='*';
    else
      obj=' ';

    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |",obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game) == id_act)
      obj='*';
    else
      obj=' ';

    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | 8D      %2d|",(int) id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |",obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (game_get_object_location(game) == id_next)
      obj='*';
    else
      obj=' ';

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|",(int) id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |",obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Pinta en el área de la despcripción */
  screen_area_clear(ge->descript);
  if ((obj_loc = game_get_object_location(game)) != NO_ID){
    sprintf(str, "  Object location:%d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }

  /* Pinta en el área del banner */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Pinta en el área de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, exit or e");
  screen_area_puts(ge->help, str);

  /* Pinta en el área de comentarios */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Volcarlo en la terminal */
  screen_paint();
  printf("prompt:> ");
}
