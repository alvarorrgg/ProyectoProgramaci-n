/**
 * @brief Archivo cabecera de graphic_engine.c en el se encuentra definidas los datos y funciones de graphic_engine.c
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

#define MAX_CHARS 255 /*!<Numero maximo de caracteres*/

/**
 * @brief carácteristicas del motor gráfico
 *
 * Contiene la información necesaria del motor gráfico
 */
typedef struct _Graphic_engine Graphic_engine;
/**
 * @brief crea el motor gráfico
 *
 * graphic_engine_create crea un motor gráfico de 0
 *
 * @date 18-02-2021
 * @author Profesores PPROG 
 *
 * @return ge el motor gráfico
 */
Graphic_engine* graphic_engine_create();
/**
 * @brief destruye el motor gráfico
 *
 * graphic_engine_destroy destruye un motor gráfico
 *
 * @date 18-02-2021
 * @author Profesores PPROG 
 *
 * @param ge el motor gráfico que se va a destruir
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief imprime por pantalla el juego a partir del motor gráfico
 *
 * graphic_engine_paint_game muestra por pantalla el juego creado
 *
 * @date 18-02-2021
 * @author Profesores PPROG 
 *
 * @param ge el motor gráfico que se utiliza
 * @param game el juego que se muestra por pantalla
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);
/**
 * @brief Recibe el comando escrito en la consola
 *
 * graphic_engine_write_command obtiene el comando utilizado
 *
 * @date 18-02-2021
 * @author Profesores PPROG 
 *
 * @param ge el motor gráfico que se utiliza
 * @param str es la cadena de texto donde va el comando.
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
