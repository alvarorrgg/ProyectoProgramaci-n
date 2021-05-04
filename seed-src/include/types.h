/**
 * @brief Archivo cabecera types.h, en el se definen tipos de datos utiles para el juego.
 *
 * @file types.h
 * @author Profesores PPROG, Álexandru Marius
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000 /*!<Numero maximo letras por palabra*/
#define NO_ID -1 /*!<Definicion de NO_ID */


/**
 * @brief Tipo de Id
 *
 * Define una estructura de tipo long con nombre Id, con esta estructura Id es equivalente a long
 */
typedef long Id;

/**
 * @brief Opciones para BOOL
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum {
  FALSE, TRUE	/* !< FALSE = 0 , TRUE = 1*/
} BOOL;

/**
 * @brief Opciones para STATUS
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum {
  ERROR, OK	/* !< ERROR = 0 , OK = 1*/
} STATUS;

/**
 * @brief Opciones para DIRECTION
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum {
  X, N, S, E, W, U, D	/* !< X = 0 , N = 1 , S = 2 , E = 3, W = 4, U = 5 D = 6*/
} DIRECTION;

/**
 * @brief Opciones para TYPES
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum {
  OPEN=0,CLOSE /* !< OPEN=0,CLOSE=1*/
} TYPES;

#endif
