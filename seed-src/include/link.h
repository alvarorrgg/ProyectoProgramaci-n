/** 
 * @brief Archivo cabecera de link.c en el se encuentra definidas los datos y funciones de link.c
 * 
 * @file link.h
 * @author Alberto Vicente
 * @version 1.0 
 * @date 11-04-2021
 * @copyright GNU Public License
 */


#ifndef LINK_H
#define LINK_H

#include "types.h"

#define MAX_LINKS 100 /*!<Numero maximo de links*/

/**
 * @brief La estructura Link
 *
 * Almacena información del link.
 */
typedef struct _Link Link;

/**
 * @brief crea los enlaces entre los espacios
 *
 * inventory_create crea las conexiones que hay entre los espacios
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param id la id del enlace que se va a crear
 * @return Puntero a la estructura Link si todo ha ido bien, NULL en caso contrario
 */
Link* link_create (Id id);

/**
 * @brief destruye un enlace entre esapcios
 *
 * inventory_destroy destruye el enlace especificado
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_destroy(Link *l);

/**
 * @brief obtiene la id de un enlace
 *
 * inventory_destroy obtiene la id de un enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return La id del enlace si todo ha ido bien, NO_ID en caso contrario
 */
Id link_get_id(Link *l);

/**
 * @brief obtiene el nombre de un enlace
 *
 * inventory_destroy obtiene el nombre de un enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return El nombre del enlace si todo ha ido bien, NULL en caso contrario
 */
char *link_get_name(Link *l);

/**
 * @brief obtiene la id del espacio del cual empieza el enlace
 *
 * inventory_destroy obtiene la id del espacio del cual empieza el enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return La id del espacio si todo ha ido bien, NO_ID en caso contrario
 */
Id link_get_id_from(Link *l);

/**
 * @brief obtiene la id del espacio en el cual termina el enlace 
 *
 * inventory_destroy obtiene la id del espacio en el cual termina el enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return La id del espacio si todo ha ido bien, NO_ID en caso contrario
 */
Id link_get_id_to(Link *l);

/**
 * @brief obtiene la clase del enlace 
 *
 * inventory_destroy obtiene la clase del enlace (abierto o cerrado)
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @return El tipo de enlace si todo ha ido bien, CLOSE en caso contrario
 */
TYPES link_get_type(Link *l);

/**
 * @brief esatblece la id de un enlace
 *
 * inventory_destroy esatblece la id de un enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param id id que va a ser establecida
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_set_id(Link *l, Id id);

/**
 * @brief esatblece el nombre de un enlace
 *
 * inventory_destroy esatblece el nombre de un enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param name nombre que va a ser estalecido
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_set_name(Link *l, char *name);
/**
 * @brief esatblece la id en la cual comienza el enlace
 *
 * inventory_destroy esatblece la id en la cual comienza el enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param from id en la cual será establecido el comienzao del enlace
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_set_id_from(Link *l, Id from);

/**
 * @brief esatblece la id en la cual termina el enlace
 *
 * inventory_destroy esatblece la id en la cual termina el enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param to id en la cual será establecido el fin del enlace
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_set_id_to(Link *l, Id to);

/**
 * @brief esatblece el tipo de un enlace
 *
 * link_set_type esatblece el tipo de un enlace
 * 
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param type tipo del enlace
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_set_type(Link *l, TYPES type);

/**
 * @brief imprime en un fichero la información sobre un enlace
 *
 * inventory_destroy imprime en un fichero la información sobre un enlace
 * @date 30-03-2021
 * @author Alberto Vicente García
 *
 * @param l puntero a la estructura Link
 * @param pf nombre del fichero en el que será impreso
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS link_print(FILE *pf, Link *l);

#endif