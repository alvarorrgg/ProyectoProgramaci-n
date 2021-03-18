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
#include <string.h>
#include "graphic_engine.h"
#include "command.h"

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
void game_loop_run(Game game, Graphic_engine *gengine,FILE *f);
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
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param argc cantidad de argumentos necesarios para que el programa funcione
 * @param argv 
 * @return 0 si la función se realiza correctamente
 */
int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;
  FILE *f = NULL;
  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
  if(argc>2 && argc==4){
  	if(strcmp(argv[2],"-l")==0) {
      f = fopen(argv[3], "w");
    }
  	else{
  	fprintf(stderr,"Los parametros se deben introducir de la forma ./ocaBAS data.dat -l log.txt");
  	return 0;
  	}
  	}
  else { 
   	if(argc==3) {
   		fprintf(stderr,"Tienes que poner o bien 2 argumento so bien 4");
   		return 0;
   		}
   		}
  if (!game_loop_init(&game, &gengine, argv[1])){
    game_loop_run(game, gengine,f);
    game_loop_cleanup(game, gengine);
    if(argc>2)fclose(f); 
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

void game_loop_run(Game game, Graphic_engine *gengine,FILE *f){
  T_Command command = NO_CMD;
   extern char *cmd_to_str[N_CMD][N_CMDT];
  while ((command != EXIT) && !game_is_over(&game)) {/*Mientras que el comando sea distinto de EXIT o no se cumpla game_is_over, se pintará la pantalla cada vez que se ejecute game_update*/
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    game_update(&game, command);
if(f!=NULL){

if(command_get_cmd(game_get_command(&game))!=-1){
  if(command_get_status(game_get_command(&game))!=1){
  fprintf(f, " %s (%s): ERROR\n", cmd_to_str[command_get_cmd(game_get_command(&game)) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(&game))- NO_CMD][CMDS]);
  }
  else{
     fprintf(f, " %s (%s): OK\n", cmd_to_str[command_get_cmd(game_get_command(&game))- NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(&game))- NO_CMD][CMDS]);
}
  }
}
  }
}


void game_loop_cleanup(Game game, Graphic_engine *gengine){
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
