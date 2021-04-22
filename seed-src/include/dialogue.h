/** 
 * @brief Archivo cabecera de dialogue.c
 * 
 * @file dialogue.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 22-04-2021
 * @copyright GNU Public License
 */
#ifndef DIALOGUE_H
#define DIALOGUE_H

#define MAX_INTERACTION 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "command.h"
#include "player.h"


typedef struct _Dialogue Dialogue;
Dialogue* dialogue_new();
STATUS dialogue_destroy(Dialogue* d);

STATUS dialogue_set_num_tries(Dialogue *d,int new_tries);
int dialogue_get_num_tries(Dialogue *d);

STATUS dialogue_set_interaction(Dialogue *d,char *new_interaction);
char* dialogue_get_interaction(Dialogue *d);

STATUS dialogue_change_interaction(Dialogue *d, Command *c, Player *p);







#endif