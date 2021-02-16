/**
 * @brief Define un motor gráfico textual
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Licencia Pública
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
 * @brief Define un motor gráfico
 * 
 * Estructura de motor gráfico
 */
typedef struct _Graphic_engine Graphic_engine;

Graphic_engine* graphic_engine_create();
void graphic_engine_destroy(Graphic_engine *ge);
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
