/**
 * @brief Define el ciclo del juego
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"

/**
 *
 * @brief función que inicializa el juego
 *
 * game_loop_init inicializa el juego llamando a las funciones que crean la parte principal del juego
 *
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param game juego que se crea
 * @param gengine motor que se crea
 * @param file_name nombre del fichero donde se cra el juego
 * @return 0 si la función se realiza correctamente
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 *
 * @brief función que hace que el juego corra
 *
 * game_loop_run continúa el juego una vez creado
 *
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param game juego que continúa
 * @param gengine motor que se utiliza en el juego
 */
void game_loop_run(Game game, Graphic_engine *gengine);
/**
 *
 * @brief función que finaliza el juego
 *
 * game_loop_cleanup finaliza el juego
 *
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param game juego que se destruye
 * @param gengine motor que se destruye
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/**
 *
 * @brief función principal
 *
 * main es la función con la que comienza el programa
 *
 * @date
 * @author
 *
 * @param argc cantidad de argumentos necesarios para que el programa funcione
 * @param argv 
 * @return 0 si la función se realiza correctamente
 */
int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if (!game_loop_init(&game, &gengine, argv[1])){
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name){
  if (game_create_from_file(game, file_name) == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game game, Graphic_engine *gengine){
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(&game)) {
    graphic_engine_paint_game(gengine, &game);
    command = get_user_input();
    game_update(&game, command);
  }
}


void game_loop_cleanup(Game game, Graphic_engine *gengine){
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
