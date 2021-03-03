/** 
 * @brief Archivo cabecera del modulo set.h, en el se define la estructura de datos Object y sus funciones.
 * 
 * @file die.h
 * @author R2
 * @version 1.0 
 * @date 02-03-2021 
 * @copyright GNU Public License
 */
 
#ifndef DIE_H
#define DIE_H
#include "types.h"
#include "time.h"
#define MAX_IDS 100

typedef struct _Die Die;

Die * die_create(Id id);
STATUS die_destroy(Die * die);
