/** 
 * @brief Archivo cabecera de player.c en el se encuentra definidas los datos y funciones de player.c
 * 
 * @file player.h
 * @author Álvaro Rodríguez, Alberto Vicente
 * @version 1.0 
 * @date 22-02-2021 
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"
/**
 * @brief La estructura Player
 *
 * Almacena información del jugador.
 */
typedef struct _Player Player;

#define MAX_PLAYERS 100 /*!<Numero maximo de jugadores*/
#define FIRST_PLAYER 1 /*!<Primer jugador*/
/**
 * @brief Crea un jugador
 *
 * player_create crea un jugador y le da atributos sin valor, es la inicialización del objeto.
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param id recibe un tipo id que es equivalente a recibir un long
 * @return Player devuelve un puntero a objeto, NULL en caso de detectar algun error.
 */
Player* player_create(Id id);
/**
 * @brief Destruye un jugador
 *
 * player_destroy destruye un jugador y todo lo relacionado con este, tanto su id como su nombre.
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player recibe un puntero a la estructura de datos jugador
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error.
 */

STATUS player_destroy(Player* player);
/**
 * @brief Obtiene el id de un jugador
 *
 * player_get_id sirve para obtener el id de un jugador.
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player recibe un puntero a la estructura de datos jugador
 * @return Id devuelve el id del jugador
 */
Id player_get_id(Player* player);
/**
 * @brief Nombrar a un jugador
 *
 * player_set_name sirve para cambiar el nombre del jugador
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player recibe un puntero a la estructura de datos jugador
 * @param name recibe el nombre que se le va a poner al jugador.
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
STATUS player_set_name(Player* player, char* name);
/**
 * @brief Escribe los atributos del jugador
 *
 * player_print sirve para escribir los atributos de el objeto como su id o su nombre.
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player recibe un puntero a la estructura de datos jugador
 * @param pf donde escribe el print
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
 STATUS player_print(FILE *pf,Player* player);

/**
 * @brief Obtiene el nombre del jugador
 *
 * player_get_name sirve para obtener el nombre de un jugador.
 *
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player recibe un puntero a la estructura de datos jugador
 * @return const char devuelve el nombre del jugador
 */
 const char* player_get_name(Player* player);

/**
 * @brief añade un objeto al player
 *
 * player_add_object añade un objeto a player
 * 
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @param value el valor que se le otorga
 * @return STATUS OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_add_object(Player* player, Id value);

/**
 * @brief borra un objeto de player
 *
 * player_remove_object borra un objeto
 * 
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @param value el valor que se le otorga
 * @return STATUS OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_remove_object(Player* player, Id value);
/**
 * @brief establece la posición del jugador
 *
 * player_set_location establece la posición del jugador al id
 * 
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @param id nueva localizacion del jugador
 * @return STATUS OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_location(Player* player, Id id);

/**
 * @brief obtiene la maxima capacidad del inventario
 *
 * player_get_inventory_max_capacity consigue la capacidad del inventario
 * 
 * @date 02-05-2021
 * @author Alberto Vicente
 *
 * @param player el jugador del juego
 * @return la capacidad si todo funciona correctamente, -1 si hubo algun error
 */
int player_get_inventory_max_capacity (Player *player);

/**
 * @brief establece la nueva capacidad del inventario
 *
 * player_set_inventory_max_capacity cambia la capacidad del inventario
 * 
 * @date 02-04-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @param max_objects nueva capacidad del inventario
 * @return STATUS OK para saber que se ha ejecutado la función correctamente
 */
STATUS player_set_inventory_max_capacity(Player *player, int max_objects);
/**
 * @brief obtiene la localización del jugador
 *
 * player_get_location consigue la localización del jugador
 * 
 * @date 23-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @return Id la localización del jugador
 */
Id player_get_location(Player* player);

/**
 * @brief Obtiene todos los ids de los objetos que tiene player
 *
 * player_get_object obtiene los objetos de player
 * 
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @return Id del objeto
 */
Id *player_get_objects(Player* player);

/**
 * @brief Obtiene el inventario del objeto
 *
 * player_get_inventory obtiene el inventario del objeto
 * 
 * @date 2-04-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @return Inventory el inventario del player
 */
Inventory *player_get_inventory(Player* player);
/**
 * @brief verifica si el jugador tiene un objeto
 *
 * player_has_object verifica si el player tiene un objeto TRUE si lo tiene FALSE si no
 * 
 * @date 22-02-2021
 * @author Álvaro Rodríguez
 *
 * @param player el jugador del juego
 * @param id el identificador del objeto a verificar
 * @return TRUE o FALSE segun si tiene el objeto o no
 */
BOOL player_has_object(Player* player,Id id);
#endif
