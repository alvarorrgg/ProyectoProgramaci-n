/** 
 * @brief Archivo cabecera de game.c contiene la estructura de datos game en la que se almacenan algunas caracteristicas del juego y algunas de las funciones publicas del programa.
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "object.h"
#include "command.h"
#include "space.h"
#include "die.h"

/**
 * @brief La estructura game
 *
 * Almacena información del juego a tiempo real
 */

typedef struct _Game Game;
/**
 * @brief Crea el juego
 *
 * game_create Crea el juego declarando todos los espacios del tablero a NULL e inicializa la posición del jugador y del objeto a -1, al igual que el comando introducido por el jugador
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que se va a crear
 * @return OK para saber que se ha ejecutado la función correctamente
 */

STATUS game_create(Game* game);

/**
 * @brief Inicializa el juego
 *
 * game_init Inicializa el juego 
 *
 * @date 18-02-2021
 * @author R1
 *
 * @param 
 * @return Puntero a la estructura Game si todo ha ido bien, NULL si ha ocurrido un error
 */
Game *game_init();
/**
 * @brief Crea el juego en un fichero
 *
 * game_create_from_file Primero se comprueba si se crea o no el juego y si se ejecuta correctamente la funcion game_reader_load_spaces y establece la posición del jugador y del objeto a 0
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que se ha a creado
 * @param filename el nombre del fichero
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_create_from_file(Game* game, char* filename);

/**
 * @brief Destruye el fichero
 *
 * game_destroy comienza con un bucle para establecer a NULL todas las casillas del juego que no lo estén
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que se va a "vaciar"
 * @return OK para saber que se ha ejecutado la función correctamente
 */
 STATUS game_destroy(Game* game);
 
/**
 * @brief Actualiza el juego
 *
 * game_update el juego se actualiza en dependencia del comando introducido
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que se actualiza
 * @param cmd comando introducido
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_update(Game* game, T_Command cmd);
/**
 * @brief Termina el juego
 *
 * game_is_over se encarga de poner fin al juego
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego que finaliza
 * @return FALSE para saber que se ha ejecutado la función correctamente 
 */
BOOL   game_is_over(Game* game);

/**
 * @brief Escribe por pantalla los datos de la partida
 *
 * game_print_data se encarga de poner pon pantalla los datos de la partida
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego del cual se escriben los datos
 */
void   game_print_data(Game* game);
/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego del que se va a identificar el espacio
 * @param position la posición del espacio
 * @return la función space_get_space con la posición position del juego
 */
Space* game_get_space(Game* game, Id id);
/**
 * @brief Identifica el dado
 *
 * game_get_die Sirve para obtener el dado del juego
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego del que se va a identificar el espacio
 * @return el dado del juego
 */
Die* game_get_die(Game* game);
/**
 * @brief Identifica el jugador
 *
 * game_get_player Sirve para obtener el jugador del juego
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a identificar el espacio
 * @return el jugador del juego
 */
Player *game_get_player(Game *game);
/**
 * @brief Determina la posición del jugador
 *
 * game_get_player_location averigua la posición del jugador
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego donde se determian la posición del jugador
 * @return la posición del jugador
 */
Id game_get_player_location(Game* game);

/**
 * @brief Determina la posición del objeto
 *
 * game_get_objet_location averigua la posición del objeto
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego donde se determian la posición del objeto
 * @return la posición del objeto
 */
Id game_get_object_location(Game* game,Id id);

/**
 * @brief Controla la estructura command dentro de game
 *
 * game_get_command Controla la estructura command dentro de game
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a sacar command
 * @return el último comando introducido
 */
Command* game_get_command(Game* game);
/**
 * @brief devuelve un objeto dado su indice
 *
 * game_get_object devuelve un objeto dado su indice
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a obtener el objeto
 * @return Object, el objeto a obtener.
 */
Object *game_get_object(Game *game, int index);
/**
 * @brief Añade un nuevo espacio al juego
 *
 * game_add_space Comprueba si el segundo parametro es NULL, luego mediante un bucle determina cual es la primera casilla con valor NULL para añadir un espacio en ella. También comprueba que no se haya sobrepasado el limite de casillas
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego al que se va a añadir un espacio
 * @param space el espacio que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_space(Game* game, Space* space);
/**
 * @brief Añade un nuevo objeto al juego
 *
 * game_add_object Añade un objeto a la lista de objetos.
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un espacio
 * @param object el espacio que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_object(Game* game, Object* object);
/**
 * @brief Añade un nuevo jugador al juego
 *
 * game_add_player Añade un objeto a la lista de objetos.
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un espacio
 * @param player el espacio que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_player(Game* game, Player* player);
/**
 * @brief Cambia la localización del objeto
 *
 * game_object_set_location Cambia la localizacion del objeto
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un espacio
 * @param id identificador del objeto.
 * @param nueva posición del objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */

/**
 * @brief Establece la posición del jugador
 *
 * game_set_player_location Comienza comprobando si el segundo parametro es -1
 *

 *
 * @param game el juego donde se establece el jugador
 * @param position la posición donde se establece el jugador
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_player_location(Game* game, Id id);

/**
 * @brief Establece la posición del objeto
 *
 * game_set_objet_location Comprueba si el segundo parametro es -1
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego donde se establece el objeto
 * @param position la posición donde se establece el objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_object_location(Game* game, Id id,Id pos_obj);

/**
 * @brief Establece la posición del objeto
 *
 * game_set_objet_location Comprueba si el segundo parametro es -1
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego donde se establece el objeto
 * @param position la posición donde se establece el objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
BOOL game_id_object_exists(Game* game, Id id);

/**
 * @brief Determina la ultima descripcion pedida
 *
 * game_set_descripcion determina la descripcion del ultimo objeto pedido
 *
 * @date 11-04-2021
 * @author Gonzalo Martín
 *
 * @param game 
 * @return lo que guarda la el campo last_descripcion
 */
STATUS game_set_last_description(Game* game , char* descr);

/**
 * @brief Devueve la ultima descripcion pedida
 *
 * game_get_descripcion devuelve la descripcion del ultimo objeto pedido
 *
 * @date 11-04-2021
 * @author Gonzalo Martín
 *
 * @param game 
 * @return lo que guarda la el campo last_descripcion
 */
const char* game_get_last_descripcion(Game* game);

#endif
