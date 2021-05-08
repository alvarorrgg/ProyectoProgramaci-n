/** 
 * @brief Archivo cabecera de game.c en el se encuentra definidas los datos y funciones de game.c. Además también se definen otros datos útiles para otros módulos.
 * 
 * @file game.h
 * @author Profesores PPROG, Álvaro Rodríguez, Gonzalo Martín, Alberto Vicente, Alexandru Marius Platon.
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
#include "inventory.h"
#include "link.h"
#include "dialogue.h"

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
 * @author Álvaro Rodríguez
 *
 * @return Puntero a la estructura Game si todo ha ido bien, NULL si ha ocurrido un error
 */
Game *game_init();
/**
 * @brief Crea el juego en un fichero
 *
 * game_create_from_file Primero se comprueba si se crea o no el juego y si se ejecuta correctamente la funcion game_management_load_spaces y establece la posición del jugador y del objeto a 0
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
 * @param arg argumento del comando
 * @param obj nombre del objeto
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_update(Game* game, T_Command cmd, char *arg, char *obj);
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
BOOL game_is_over(Game* game);

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
void game_print_data(Game* game);
/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date  18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego del que se va a identificar el espacio
 * @param id la posición del espacio
 * @return la función space_get_space con la posición position del juego
 */
Space* game_get_space(Game* game, Id id);
/**
 * @brief Identifica un espacio del juego
 *
 * game_get_space_id_at Comprueba si el segundo parametro es menor a 0 o mayor o igual al espacio máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date 18-02-2021
 * @author Profesores PProg
 *
 * @param game el juego del que se va a identificar el espacio
 * @param position la posición del espacio
 * @return la función space_get_id con la posición position del juego
 */
Id game_get_space_id_at(Game *game, int position);
/**
 * @brief Obtiene el total de espacios dentro del juego
 *
 * game_get_total_spaces obtiene cuantos espacios hay en el juego
 *
 * @date  02-05-2021
 * @author Alberto Vicente
 *
 * @param game el juego del que se va a sacar el numero de espacios
 * @return el numero de espacios
 */
int game_get_total_spaces(Game *game);
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
 * @param id id del objeto a buscar
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
 * @brief Controla la estructura dialogue dentro de game
 *
 * game_get_dialogue Controla la estructura dialogue dentro de game
 *
 * @date  23-04-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a sacar command
 * @return el último dialogo 
 */
Dialogue *game_get_dialogue(Game *game);
/**
 * @brief Obtiene el objeto a traves de su nombre
 *
 * game_get_object_from name Obtiene el objeto a traves de su nombre
 *
 * @date  05-04-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a sacar el objeto
 * @param name el nombre del objeto
 * @return el objeto 
 */
Object* game_get_object_from_name(Game *game, char *name);
/**
 * @brief Obtiene el total de objetos dentro del juego
 *
 * game_get_total_objects obtiene cuantos objetos hay en el juego
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a sacar el numero de objetos
 * @return el numero de objetos
 */
int game_get_total_objects(Game *game);

/**
 * @brief devuelve un objeto dado su indice
 *
 * game_get_object devuelve un objeto dado su indice
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a obtener el objeto
 * @param index indice del objeto
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
 * @param game el juego al que se va a añadir un objeto
 * @param object el objeto que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_object(Game* game, Object* object);
/**
 * @brief Añade un nuevo jugador al juego
 *
 * game_add_player Añade un player al juego
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un jugador
 * @param player el jugador
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_player(Game* game, Player* player);

/**
 * @brief Añade un nuevo link al juego
 *
 * game_add_link Añade un link a la lista de links.
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un link
 * @param link el link que se va a añadir
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_add_link(Game *game, Link *link);
/**
 * @brief Obtiene el link del id determinado
 *
 * game_get_link busca el link de id determinado
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego al que se va a añadir un link
 * @param id el id del link que se va a devolver
 * @return Se devuelve el link encontrado NULL si no se encuentra nada.
 */
Link *game_get_link(Game *game, Id id);
/**
 * @brief Obtiene el total de links dentro del juego
 *
 * game_get_total_links obtiene cuantos links hay en el juego
 *
 * @date  02-05-2021
 * @author Alberto Vicente
 *
 * @param game el juego del que se va a sacar el numero de links
 * @return el numero de links
 */
int game_get_total_links(Game *game);
/**
 * @brief Identifica un enlace del juego
 *
 * game_get_link_id_at Comprueba si el segundo parametro es menor a 0 o mayor o igual al enlace máximo, en el caso de que se cumpla una de estas dos cosas la función retorna -1
 *
 * @date 02-05-2021
 * @author Alberto Vicente
 *
 * @param game el juego del que se va a identificar el enlace
 * @param position la posición del enlace
 * @return la función link_get_id con la posición position del juego
 */
Id game_get_link_id_at(Game *game, int position);
/**
 * @brief devuelve un objeto dado su id
 *
 * game_get_object_by_id devuelve un objeto dado su id
 *
 * @date  22-04-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a obtener el objeto
 * @param id id del objeto
 * @return Object, el objeto a obtener.
 */
Object *game_get_object_by_id(Game *game, Id id);

/**
 * @brief devuelve las dependencias del ObjId
 *
 * game_get_dependency devuelve un objeto dado su id y quita el anterior objeto del inventario
 *
 * @date  22-04-2021
 * @author Álvaro Rodríguez 
 *
 * @param game el juego del que se va a obtener el objeto
 * @param ObjId id del objeto cuyas dependencias se buscan
 * @param id donde se guardan las dependencias
 * @param space donde se dropean los objetos
 * @return Id* de las dependencias
 */
Id* game_get_dependency(Game *game, Id ObjId, Id *id,int space);
/**
 * @brief Establece la posición del jugador
 *
 * game_set_player_location Comienza comprobando si el segundo parametro es -1
 *
 * @date  18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego donde se establece el jugador
 * @param id la posición donde se establece el jugador
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS game_set_player_location(Game* game, Id id);

/**
 * @brief Establece la posición del objeto
 *
 * game_set_objet_location Comprueba si el segundo parametro es -1
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param game el juego donde se establece el objeto
 * @param pos_obj la posición donde se establece el objeto
 * @param id id del objeto
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
 * @param id la posición donde se establece el objeto
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
 * @param game el juego donde se establece el objeto
 * @param descr descripcion del objeto
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
 * @param game el juego donde se establece el objeto
 * @return lo que guarda la el campo last_descripcion
 */
const char* game_get_last_descripcion(Game* game);

/**
 * @brief Busca si el jugador tiene un objeto iluminado
 *
 * game_get_descripcion devuelve la descripcion del ultimo objeto pedido
 *
 * @date 02-05-2021
 * @author Alexandru Marius Platon
 *
 * @param g el juego donde se establece el objeto
 * @return TRUE si el jugador tiene un objeto iluminado, FALSE en caso contrario
 */
BOOL game_player_hasIluminated_object(Game *g);

#endif
