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

#define MAX_INTERACTION 100 /*!<Numero maximo de interacciones*/
#define MAX_CHARS_DIALOGUE 100 /*!<Numero maximo de letras del dialogo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "command.h"
#include "player.h"

/**
 * @brief Estructura dialogue
 *
 * contiene las variables del dialogo
 */
typedef struct _Dialogue Dialogue;
/**
 * @brief crea un dialogo
 * 
 * diaolgue_create crea un dialogo
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @return El dialogo nuevo
 */
Dialogue* dialogue_new();
/**
 * @brief destruye un dialogo
 * 
 * diaolgue_destroy destruye un dialogo
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_destroy(Dialogue* d);
/**
 * @brief establece el numero de intentos
 * 
 * diaolgue_set_num_tries establece el numero de intentos
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @param new_tries numero de intentos
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_set_num_tries(Dialogue *d,int new_tries);
/**
 * @brief consigue el numero de intentos
 * 
 * diaolgue_set_num_tries consigue el numero de intentos
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @return El numero de intentos si todo ha ido bien, -1 si algo ha fallado
 */
int dialogue_get_num_tries(Dialogue *d);

/**
 * @brief establece el numero de dialogos
 * 
 * dialogue_set_num_dialogues establece el numero de dialogos
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @param new_dialogues numero de dialogos
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_set_num_dialogues(Dialogue *d,int new_dialogues);
/**
 * @brief consigue el numero de dialogos
 * 
 * dialogue_get_num_dialogues consigue el numero de dialogos
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @return El numero de dialogos si todo ha ido bien, -1 si algo ha fallado
 */
int dialogue_get_num_dialogues(Dialogue *d);

/**
 * @brief establece el dialogo elegido
 * 
 * dialogue_set_choose_dialogue establece el dialogo elegido
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @param choose_dialogue numero de dialogo elegido
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_set_choose_dialogue(Dialogue *d,int choose_dialogue);
/**
 * @brief consigue el dialogo elegido
 * 
 * ialogue_get_choose_dialogue consigue el dialogo elegido
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 *
 * @param d Puntero a estructura Dialogue
 * @return El numero del dialogo si todo ha ido bien, -1 si algo ha fallado
 */
int dialogue_get_choose_dialogue(Dialogue *d);
/**
 * @brief establece una nueva interaccion
 * 
 * diaolgue_set_interaction establece una nueva interaccion
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 * @param d Puntero a estructura Dialogue
 * @param new_interaction nueva interaccion
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_set_interaction(Dialogue *d,char *new_interaction);
/**
 * @brief consigue la interaccion buscada
 * 
 * diaolgue_get_interaction consigue la interaccion buscada
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 * @param d Puntero a estructura Dialogue
 * @param index indice del dialogo
 * @return la interaccion buscada si todo ha ido bien, NULL si algo ha fallado
 */
char* dialogue_get_interaction(Dialogue *d,int index);
/**
 * @brief establece el ultimo comando para el dialogo
 *
 * dialogue_set_last_command establece el ultimo comando para el dialogo
 * 
 * @date 02-05-2021
 * @author ÃƒÂlvaro RodrÃƒÂ­guez
 *
 * @param d Puntero a estructura Dialogue
 * @param cmd comando recibido
 * @return OK si todo ha salido bien, ERROR si ha habido algun ERROR
 */
STATUS dialogue_set_last_command(Dialogue *d, T_Command cmd);
/**
 * @brief obtiene el ultimo comando para el dialogo
 *
 * dialogue_get_last_command obtiene el ultimo comando para el dialogo
 * 
 * @date 02-05-2021
 * @author Ãlvaro Rodri­guez
 *
 * @param d Puntero a estructura Dialogue

 * @return el comando si todo ha salido bien. NO_CMD en caso contrario
 */
T_Command dialogue_get_last_command(Dialogue *d);
/**
 * @brief cambia una interaccion
 * 
 * diaolgue_change_interaction cambiua una interaccion
 *
 * @author Alvaro Rodriguez
 * @date 02-05-2021
 * @param d Puntero a estructura Dialogue
 * @param c Puntero a estructura Command
 * @param p Puntero a estructura Player
 * @return OK si todo ha ido bien, ERROR si algo ha fallado
 */
STATUS dialogue_change_interaction(Dialogue *d, Command *c, Player *p);







#endif