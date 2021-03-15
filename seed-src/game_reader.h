/** 
 * @brief Archivo de cabecera de game_reader.c con las definiciones de funciones publicas.
 * 
 * @file game_reader.h
 * @author Álvaro Rodríguez	
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */
#ifndef GAME_READER_H
#define GAME_READER_H

/**
	Definición de funciones públicas.
*/
/**
 * @brief Cargar espacios
 *
 * game_reader_load_spaces carga los espacios del fichero leido según una estructura determinada.
 *
 * @date 18-02-2021 
 * @author Álvaro Rodríguez
 *
 * @param recibe un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param nombre del archivo de donde se van a obtener los valores en este caso data.dat.
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_reader_load_spaces(Game* game, char* filename);

/**
 * @brief Cargar objetos
 *
 * game_reader_load_objects carga los objetos del fichero leido según una estructura determinada.
 *
 * @date 18-02-2021 
 * @author Álvaro Rodríguez
 *
 * @param recibe un puntero de tipo Game que es una estructura definida en "game.h" 
 * @param nombre del archivo de donde se van a obtener los valores en este caso data.dat.
 * @return devuelve un tipo de dato STATUS que es o bien ERROR o bien OK segun si hay o no algun fallo en la ejecución. 
 */
STATUS game_reader_load_objects(Game* game, char* filename);
#endif
