#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 23
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x))

/**
 * @brief Dimensiones del área
 *
 *  Almacena las dimensiones del área de juego
 */
struct _Area{
  int x, y, width, height;	/*!< x del cursor, y del cursor, anchura, altura */
  char *cursor;		/*!< Posición del cursor */
};

char *__data;

/*******************************/
/*      Funciones privadas     */
/*******************************/
int  screen_area_cursor_is_out_of_bounds(Area* area);
void screen_area_scroll_up(Area* area);
void screen_utils_replaces_special_chars(char* str);

/*******************************/
/* Implementación de funciones */
/*******************************/

/**
 * @brief Inicia la pantalla
 *
 * screen_init muestra por la terminal la pantalla de juego
 *
 * @date
 * @author
 */
void screen_init(){
  screen_destroy(); /* Desechar si se inicializó previamente */
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data){
    memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Llenar el fondo*/
    *(__data + TOTAL_DATA - 1) = '\0';         /*NULL-cadena terminada*/
  }
}

/**
 * @brief Desecha la pantalla
 *
 * screen_destroy desecha la terminal que haya en pantalla
 *
 * @date
 * @author
 */
void screen_destroy(){
  if (__data)
    free(__data);
}

/**
 * @brief Inicia la pantalla
 *
 * screen_paint muestra por la terminal la pantalla de juego
 *
 * @date
 * @author
 */
void screen_paint(){
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i=0;

  memset(dest, 0, COLUMNS + 1);

  if (__data){
    /* pone(__data); */ /*Vuelca datos directamente a la terminal*/
    /*Funciona bien si la ventana de la terminal tiene el tamaño correto*/

    puts("\033[2J"); /*Vacia la terminal*/
    for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS){
      memcpy(dest, src, COLUMNS);
      /* printf("%s\n", dest); */
      for (i=0; i<COLUMNS; i++){
	if (dest[i] == BG_CHAR){
	  printf("\033[0;34;44m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
	}else{
	  printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
	}
      }
      printf("\n");
    }
  }
}

/**
 * @brief Área de pantalla inicializada
 *
 * screen_area_init muestra por pantalla la pantalla del comienzo
 * 
 * @param x x del cursor
 * @param y y del cursor
 * @param width la anchura de la pantalla
 * @param height la altura de la pantalla
 */
Area* screen_area_init(int x, int y, int width, int height){
  int i = 0;
  Area* area = NULL;

  if ( (area  = (Area*) malloc (sizeof(struct _Area))) ){
    *area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }

  return area;
}

/**
 * @brief Área de pantalla destruida
 *
 * screen_area_destroy destruye la pantalla mostrada por la terminal
 * 
 * @param área de la pantalla que se va a destruir
 */
void screen_area_destroy(Area* area){
  if(area)
    free(area);
}

/**
 * @brief Área que se limpia
 *
 * screen_area_init despeja la pantalla que hay en la terminal
 * 
 * @param área de la pantalla que se va a despejar
 */
void screen_area_clear(Area* area){
  int i = 0;

  if (area){
    screen_area_reset_cursor(area);

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }
}

/**
 * @brief Se resetea el cursor
 *
 * screen_area_reset_cursor resetea el cursor en pantalla
 * 
 * @param área donde se resetea el cursor
 */
void screen_area_reset_cursor(Area* area){
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}

/**
 * @brief Se resetea el cursor
 *
 * screen_area_puts no la entiendo ;)
 * 
 * @param área donde se resetea el cursor
 */
void screen_area_puts(Area* area, char *str){
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width)? strlen(ptr) : area->width;
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS;
  }
}

/**
 * @brief El cursor está fuera de los límites
 *
 * screen_area_cursor_is_out_of_bounds comprueba si el cursor está fuera de los límites de la pantalla
 * 
 * @param área donde está el cursor
 * @return la posición del cursor
 */
int screen_area_cursor_is_out_of_bounds(Area* area){
  return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

/**
 * @brief a pantalla se desplaza hacia arriba
 *
 * screen_area_scroll_up desplaza la pantalla hacia arriba para que pueda salir la siguiente
 * 
 * @param área que se desplaza
 */
void screen_area_scroll_up(Area* area){
  for(area->cursor = ACCESS(__data, area->x, area->y);
      area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      area->cursor += COLUMNS){
    memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  }
}

/**
 * @brief reemplaza los caracteres especiales por otros
 *
 * screen_utils_replaces_special_chars sirve para reemplazar los caracteres no permitidos por otros
 * 
 * @param str carácter que se va a reemplazar
 */
void screen_utils_replaces_special_chars(char* str){
  char *pch = NULL;

  /* Reemplaza acentos y tildes con '??' */
  while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
