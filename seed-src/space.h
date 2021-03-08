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
 * space_set_objects establece el valor de object a TRUE o a FALSE
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param value el valor que se le otorga
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_objects(Space* space, Id value);
/**
 * @brief obtiene los ids de los objetos en el set
 *
 * space_get_objects obtiene los ids de los objetos en el espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return los ids de los objetos
 */
Id* space_get_objects(Space* space);
/**
 * @brief obtiene el numero total de objetos
 *
 * space_get_objects obtiene el numero total de objetos
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return el numero de objetos
 */
int space_get_number_of_objects(Space* space);
/**
 * @brief verifica si un espacio tiene un objeto
 *
 * space_get_objects comprueba que el objeto esta en el espacio
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja, Id del objeto
 * @return TRUE o FALSE segun si el objeto esta o no en el espacio
 */
BOOL space_has_object_id(Space* space, Id id);
/**
 * @brief elimina un objeto de un espacio
 *
 * space_get_objects elimina el objeto de id determinado
 * 
 * @date 18-02-2021
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja, Id del objeto
 * @return OK o ERROR segun si se ha eliminado correctamente el objeto o no.
 */
STATUS space_remove_object(Space* space, Id id);
/**
 * @brief cambias la descripción de un espacio
 *
 * space_set_gdesc cambias la descripción grafica de un objeto
 * 
 * @date 18-02-2021
 * @author R1
 *
 * @param space el espacio que se trabaja
 * @param descripción
 * @return OK o ERROR segun si se ha cambiado la descripción o no.
 */
STATUS space_set_gdesc(Space *space, char **desc);
/**
 * @brief cambias la descripción de un espacio
 *
 * space_get_gdesc obtienes la descripción grafica de un objeto
 * 
 * @date 18-02-2021
 * @author R1
 *
 * @param space el espacio que se trabaja
 * @return OK o ERROR segun si se ha obtenido la descripción o no.
 */
char** space_get_gdesc(Space *space);

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
