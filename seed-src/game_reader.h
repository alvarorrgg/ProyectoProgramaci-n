/** 
 * @brief Archivo de cabecera de game_reader.c con las definiciones de funciones publicas.
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */
#ifndef GAME_READER_H
#define GAME_READER_H


/**
	Definición de funciones publicas
		Inicialización de la función game_reader_load_spaces que sirve para cargar los espacios iniciales del archivo data.dat.
*/
STATUS game_reader_load_spaces(Game* game, char* filename);
#endif
