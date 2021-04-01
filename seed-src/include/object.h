/** 
 * @brief Archivo cabecera del modulo object.h, en el se define la estructura de datos Object y sus funciones.
 * 
 * @file object.h
 * @author Álvaro Rodríguez
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
/**
 * @brief La estructura Object
 *
 * Almacena información del objeto.
 */
typedef struct _Object Object;

#define MAX_OBJECTS 100 /*Numero maximo de objetos*/
#define FIRST_OBJECT 1  /*Posición del primer objeto*/
/**
 * @brief Crea un objeto
 *
 * object_create crea un objeto y le da atributos sin valor, es la inicialización del objeto.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param id recibe un tipo id que es equivalente a recibir un long
 * @return object devuelve un puntero a objeto, NULL en caso de detectar algun error.
 */
Object* object_create(Id id);
/**
 * @brief Destruye un objeto
 *
 * object_destroy destruye un objeto y todo lo relacionado con este, tanto su id como su nombre.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error.
 */

STATUS object_destroy(Object* object);
/**
 * @brief Obtiene el id de un objeto
 *
 * object_get_id sirve para obtener el id de un objeto.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object un puntero a la estructura de datos objeto
 * @return Id devuelve el id del objeto
 */
Id object_get_id(Object* object);
/**
 * @brief Nombrar a un objeto
 *
 * object_set_name sirve para cambiar el nombre del objeto
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @param name recibe el nombre que se le va a poner al objeto.
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
STATUS object_set_name(Object* object, char* name);
/**
 * @brief cambiar la posición de un objeto
 *
 * object_set_id sirve para cambiar la posición de un objeto
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @param id recibe el nuevo lugar del objeto
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
 STATUS object_set_id(Object* object, Id id);
/**
 * @brief Escribe los atributos del objeto
 *
 * object_print sirve para escribir los atributos de el objeto como su id o su nombre.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */

 STATUS object_print(Object* object);


/**
 * @brief Obtiene el nombre del objeto
 *
 * object_get_name sirve para obtener el nombre de un objeto.
 *
 * @date 18-02-2021
 * @author Álvaro Rodríguez
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @return const char devuelve el nombre del objeto
 */
 const char* object_get_name(Object* object);


#endif