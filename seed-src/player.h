/** 
 * @brief Archivo cabecera de la función player.h, en el se define la estructura de datos Player y sus funciones.
 * 
 * @file player.h
 * @author R2
 * @version 1.0 
 * @date 22-02-2021 
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
/**
 * @brief La estructura Player
 *
 * Almacena información del jugador.
 */
typedef struct _Player Player;

#define MAX_PLAYERS 100
#define FIRST_PLAYER 1
/**
 * @brief Crea un jugador
 *
 * player_create crea un jugador y le da atributos sin valor, es la inicialización del objeto.
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un tipo id que es equivalente a recibir un long
 * @return devuelve un puntero a objeto, NULL en caso de detectar algun error.
 */
Player* player_create(Id id);
/**
 * @brief Destruye un jugador
 *
 * player_destroy destruye un jugador y todo lo relacionado con este, tanto su id como su nombre.
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un puntero a la estructura de datos jugador
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error.
 */

STATUS player_destroy(Player* player);
/**
 * @brief Obtiene el id de un jugador
 *
 * player_get_id sirve para obtener el id de un jugador.
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un puntero a la estructura de datos jugador
 * @return devuelve el id del jugador
 */
Id player_get_id(Player* player);
/**
 * @brief Nombrar a un jugador
 *
 * player_set_name sirve para cambiar el nombre del jugador
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un puntero a la estructura de datos jugador
 * @param recibe el nombre que se le va a poner al jugador.
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
STATUS player_set_name(Player* player, char* name);
/**
 * @brief Escribe los atributos del jugador
 *
 * player_print sirve para escribir los atributos de el objeto como su id o su nombre.
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un puntero a la estructura de datos jugador
 * @return devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
 STATUS player_print(Player* player);

/**
 * @brief Obtiene el nombre del jugador
 *
 * player_get_name sirve para obtener el nombre de un jugador.
 *
 * @date 22-02-2021
 * @author R2
 *
 * @param recibe un puntero a la estructura de datos jugador
 * @return devuelve el nombre del jugador
 */
 const char* player_get_name(Player* player);

/**
 * @brief establece la coordenada norte del jugador
 *
 * player_set_north fija la coordenada norte del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_north(Player* player, Id id);

/**
 * @brief obtiene la coordenada norte del jugador
 *
 * player_get_north consigue la coordenada norte del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @return player->north la coordenada norte del espacio
 */
Id player_get_north(Player* player);

/**
 * @brief establece la coordenada sur del jugador
 *
 * player_set_south fija la coordenada sur del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_south(Player* player, Id id);

/**
 * @brief obtiene la coordenada sur del jugador
 *
 * player_get_south consigue la coordenada sur del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @return player->south la coordenada sur del espacio
 */
Id player_get_south(Player* player);

/**
 * @brief establece la coordenada este del jugador
 *
 * player_set_east fija la coordenada este del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_east(Player* player, Id id);
/**
 * @brief obtiene la coordenada este del jugador
 *
 * player_get_east consigue la coordenada este del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @return player->east la coordenada este del espacio
 */
Id player_get_east(Player* player);

/**
 * @brief establece la coordenada oeste del jugador
 *
 * player_set_west fija la coordenada oeste del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_west(Player* player, Id id);
/**
 * @brief obtiene la coordenada oeste del jugador
 *
 * player_get_west consigue la coordenada oeste del jugador
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @return player->west la coordenada oeste del espacio
 */
Id player_get_west(Player* player);

/**
 * @brief establece el objeto a TRUE o FALSE
 *
 * player_set_object establece el valor de object a TRUE o a FALSE
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @param value el valor que se le otorga
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_object(Player* player, BOOL value);
/**
 * @brief obtiene el objeto "TRUE o FALSE"
 *
 * player_get_object obtiene el valor de object a TRUE o a FALSE
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param player el jugador que se trabaja
 * @return player->object el valor del objeto
 */
BOOL player_get_object(Player* player);
#endif
