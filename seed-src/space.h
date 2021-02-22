/** 
 * @brief Define un espacio
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

/**
 * @brief Define un espacio
 * 
 * Estructura de espacio
 */
typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/**
 * @brief crea un nuevo espacio
 *
 * space_create crea un nuevo espacio inicializando las coordenadas a -1
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param id marca una localización.
 * @return newspace le espacio que se crea
 */
Space* space_create(Id id);

/**
 * @brief destruye un espacio
 *
 * space_destroy destruye un espacio creado previamente
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se destruye
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_destroy(Space* space);

/**
 * @brief obtiene la id del espacio
 *
 * space_get_id consigue la id del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->id la id del espacio
 */
Id space_get_id(Space* space);

/**
 * @brief da nombre a un espacio
 *
 * space_set_name da nombre a un espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio al que se le pone el nombre
 * @param name el nombre que se le da
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_name(Space* space, char* name);
/**
 * @brief obtiene el nombre del espacio
 *
 * space_get_name consigue el nombre del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->name el nombre del espacio
 */
const char* space_get_name(Space* space);

/**
 * @brief establece la coordenada norte
 *
 * space_set_north fija la coordenada norte
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_north(Space* space, Id id);

/**
 * @brief obtiene la coordenada norte del espacio
 *
 * space_get_north consigue la coordenada norte del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->north la coordenada norte del espacio
 */
Id space_get_north(Space* space);

/**
 * @brief establece la coordenada sur
 *
 * space_set_south fija la coordenada sur
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_south(Space* space, Id id);

/**
 * @brief obtiene la coordenada sur del espacio
 *
 * space_get_south consigue la coordenada sur del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->south la coordenada sur del espacio
 */
Id space_get_south(Space* space);

/**
 * @brief establece la coordenada este
 *
 * space_set_east fija la coordenada este
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_east(Space* space, Id id);
/**
 * @brief obtiene la coordenada este del espacio
 *
 * space_get_east consigue la coordenada este del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->east la coordenada este del espacio
 */
Id space_get_east(Space* space);

/**
 * @brief establece la coordenada oeste
 *
 * space_set_west fija la coordenada oeste
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id marca una localización.
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_west(Space* space, Id id);
/**
 * @brief obtiene la coordenada oeste del espacio
 *
 * space_get_west consigue la coordenada oeste del espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->west la coordenada oeste del espacio
 */
Id space_get_west(Space* space);

/**
 * @brief establece el objeto a TRUE o FALSE
 *
 * space_set_object establece el valor de object a TRUE o a FALSE
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param value el valor que se le otorga
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_object(Space* space, BOOL value);
/**
 * @brief obtiene el objeto "TRUE o FALSE"
 *
 * space_get_object obtiene el valor de object a TRUE o a FALSE
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->object el valor del objeto
 */
BOOL space_get_object(Space* space);
/**
 * @brief muestra por pantalla el espacio creado
 *
 * space_print imprime por la terminal el espacio creado
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_print(Space* space);

#endif
