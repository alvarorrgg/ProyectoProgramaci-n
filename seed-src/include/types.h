/**
 * @brief Definde tipos comunes
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1


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
  N, S, E, W	/* !< N = 0 , S = 1 , E = 2 , W = 3*/
} DIRECTION;

#endif
