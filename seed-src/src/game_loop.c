/**
 * @brief Define el ciclo del juego
 *
 * @file game_loop.c
 * @author Profesores PPROG,Álvaro Rodriguez
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"
#include "command.h"
#include "game.h"



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
 * @param f puntero al fichero que se va a usar
 */
void game_loop_run(Game *game, Graphic_engine *gengine, FILE *f);
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
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 *
 * @brief función principal
 *
 * main es la función con la que comienza el programa
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param argc cantidad de argumentos necesarios para que el programa funcione
 * @param argv array donde se guarda cada uno de los argumentos
 * @return 0 si la función se realiza correctamente
 */
int main(int argc, char *argv[])
{
  Game *game;
  Graphic_engine *gengine;
  FILE *f = NULL;
  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
  if (argc > 2 && argc == 4)
  {
    if (strcmp(argv[2], "-l") == 0)
    { /*Verifica que el tercer argumento es -l*/
      f = fopen(argv[3], "w");
    }
    else
    {
      fprintf(stderr, "Los parametros se deben introducir de la forma ./ocaBAS data.dat -l log.txt");
      return 0;
    }
  }
  else
  {
    if (argc == 3)
    { /*Verifica que despues de haber puesto -l, se ha introducido el nombre de un archivo*/
      fprintf(stderr, "Tienes que poner o bien 2 argumento so bien 4");
      return 0;
    }
  }
  game = game_init();
  if (!game_loop_init(game, &gengine, argv[1])) /*Inicio del juego*/
  {                                 
    game_loop_run(game, gengine, f); /*Bucle donde se desarrolla el juego*/
    game_loop_cleanup(game, gengine);
    if (argc > 2) fclose(f); /*Necesaria esta comprobación para no cerrar el archivo en caso de que no se hubiera abierto*/
  }

  return 0;
}

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  if (game_create_from_file(game, file_name) == ERROR)
  { /*Se crea el juego*/
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  { /*Se crea el motor grafico*/
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, FILE *f)
{ /*Aqui es donde se desarrolla todo el juego*/
  T_Command command = NO_CMD;
  char **info=NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT]; /*Incluyo esta variable desde command para poder incluir los comandos en el file*/

  while ((command != EXIT) && !game_is_over(game))
  { /*Mientras que el comando sea distinto de EXIT o no se cumpla game_is_over, se pintará la pantalla cada vez que se ejecute game_update*/

    graphic_engine_paint_game(gengine, game);
    command = command_get_user_command();
    info = command_get_user_info();
    game_update(game, command, info[0], info[1]);
    free(info[0]);
    free(info[1]);
    free(info);
    if (f != NULL)
    { /*Necesario para no escribir en un fichero vacio*/
      if (command_get_cmd(game_get_command(game)) != -1)
      {
        if (command_get_status(game_get_command(game)) != 1)
        {
          if (strlen(command_get_arg(game_get_command(game))) == 1){
            fprintf(f, " %s (%s): ERROR\n", cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDS]); /*Se usa esta linea cuando el status es ERROR*/
        }
        else
        {
          fprintf(f, " %s (%s) %s: ERROR\n", cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDS], command_get_arg(game_get_command(game)));
        }
      }
      else
      {
        if (strlen(command_get_arg(game_get_command(game))) == 1){
            fprintf(f, " %s (%s): OK\n", cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDS]); /*Se usa esta linea cuando el status es ERROR*/
        }
        else
        {
          fprintf(f, " %s (%s) %s: OK\n", cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(game_get_command(game)) - NO_CMD][CMDS], command_get_arg(game_get_command(game)));
        }
      }
    }
  }
}
graphic_engine_paint_game(gengine, game);
}

void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
