/**
 * @brief Archivo cabecera de screen.c en el se encuentra definidas los datos y funciones de screen.c
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80 /*!<Numero maximo de STR*/

/**
 * @brief Define un área
 * 
 * Estructura de área
 */
typedef struct _Area Area;
/**
 * @brief Inicia la pantalla
 *
 * screen_init muestra por la terminal la pantalla de juego
 *
 * @date 18-02-2021
 * @author Profesores PProg
 */
void  screen_init();
/**
 * @brief Desecha la pantalla
 *
 * screen_destroy desecha la terminal que haya en pantalla
 *
 * @date 18-02-2021
 * @author Profesores PProg
 */
void  screen_destroy();
/**
 * @brief Inicia la pantalla
 *
 * screen_paint muestra por la terminal la pantalla de juego
 *
 * @date 18-02-2021
 * @author Profesores PProg
 */
void  screen_paint();
/**
 * @brief Área de pantalla inicializada
 *
 * screen_area_init muestra por pantalla la pantalla del comienzo
 * 
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param x x del cursor
 * @param y y del cursor
 * @param width la anchura de la pantalla
 * @param height la altura de la pantalla
 */
Area* screen_area_init(int x, int y, int width, int height);
/**
 * @brief Área de pantalla destruida
 *
 * screen_area_destroy destruye la pantalla mostrada por la terminal
 * 
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param area de la pantalla que se va a destruir
 */
void  screen_area_destroy(Area* area);

/**
 * @brief Área que se limpia
 *
 * screen_area_clear despeja la pantalla que hay en la terminal
 * 
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param area de la pantalla que se va a despejar
 */
void  screen_area_clear(Area* area);

/**
 * @brief Se resetea el cursor
 *
 * screen_area_reset_cursor resetea el cursor en pantalla
 * 
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param area donde se resetea el cursor
 */
void  screen_area_reset_cursor(Area* area);

/**
 * @brief Se resetea el cursor
 *
 * screen_area_puts representa el area de la pantalla en la que te encuentras.
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param area donde se resetea el cursor
 * @param str string donde se almacena la información
 */
void  screen_area_puts(Area* area, char *str);

#endif
