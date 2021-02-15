/** 
 * @brief Archivo cabecera de game.c contiene la estructura de datos game en la que se almacenan algunas caracteristicas del juego y algunas de las funciones publicas del programa.
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"

/**
 * @brief La estructura game
 *
 * Almacena información del juego a tiempo real
 */

typedef struct _Game{
  Id player_location;		/*!< Localización del jugador*/
  Id object_location;		/*!< Localización del objeto*/
  Space* spaces[MAX_SPACES + 1];		/*!< */
  T_Command last_cmd;		/*!< comando que se recibe del jugador*/
} Game;

STATUS game_create(Game* game);
STATUS game_create_from_file(Game* game, char* filename);
STATUS game_update(Game* game, T_Command cmd);
STATUS game_destroy(Game* game);
BOOL   game_is_over(Game* game);
void   game_print_data(Game* game);
Space* game_get_space(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game);
T_Command game_get_last_command(Game* game);
#endif
