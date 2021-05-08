/** 
 * @brief Archivo cabecera de game_management.c en el se encuentra definidas los datos y funciones de game_management_test.c
 * 
 * @file game_management.h
 * @author Álvaro Rodríguez, Alberto Vicente
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */
#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

/**
	Definición de funciones públicas.
*/
/**
 * @brief Cargar espacios
 *
 * game_management_load_spaces carga los espacios del fichero leido según una estructura determinada.
 *
 * @date 18-02-2021 
 * @author Álvaro Rodríguez
 *
 * @param game un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo de donde se van a obtener los valores.
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load_spaces(Game* game, char* filename);

/**
 * @brief Cargar objetos
 *
 * game_management_load_objects carga los objetos del fichero leido según una estructura determinada.
 *
 * @date 18-02-2021 
 * @author Alberto Vicente
 *
 * @param game  un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo de donde se van a obtener los valores..
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load_objects(Game* game, char* filename);

/**
 * @brief Cargar jugadores
 *
 * game_management_load_players carga los jugadores del fichero leido según una estructura determinada.
 *
 * @date 18-02-2021 
 * @author Álvaro Rodríguez
 *
 * @param game  un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo de donde se van a obtener los valores..
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load_players(Game* game, char* filename);

/**
 * @brief Cargar links
 *
 * game_management_load_links carga los links del fichero leido segun la estructura determinada
 *
 * @date 18-02-2021 
 * @author Álvaro Rodríguez
 *
 * @param game  un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo de donde se van a obtener los valores..
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load_links(Game* game, char* filename);

/**
 * @brief Carga el dialogo
 *
 * game_management_load_dialogue Carga el dialogo
 *
 * @date 02-05-2021 
 * @author Álvaro Rodríguez
 *
 * @param game  un puntero de tipo Game que es una estructura definida en "game.h" 
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load_dialogue(Game * game);

/**
 * @brief Guardar partida
 *
 * game_management_save guarda los datos de la partida en un fichero
 *
 * @date 29-04-2021 
 * @author Alberto Vicente
 *
 * @param game  un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo donde se van a guardar los datos de la partida
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_save(Game * game, char * filename);

/**
 * @brief Cargar partida
 *
 * game_management_load carga los datos de una partida a partir de un fichero
 *
 * @date 29-04-2021 
 * @author Alberto Vicente
 *
 * @param game un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param filename del archivo donde se van a cargar los datos de la partida
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_management_load(Game * game, char * filename);

#endif
