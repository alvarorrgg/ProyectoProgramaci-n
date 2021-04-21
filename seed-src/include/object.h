/** 
 * @brief Archivo cabecera de object.c en el se encuentra definidas los datos y funciones de object.c
 * 
 * @file object.h
 * @author Álvaro Rodríguez, Gonzalo Martín
 * @version 1.0 
 * @date 18-02-2021 
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#define LEN_DES 100 /*!<Numero maximo de caracteres en la descrpicion del objeto*/

#include "types.h"
/**
 * @brief La estructura Object
 *
 * Almacena información del objeto.
 */
typedef struct _Object Object;

#define FIRST_OBJECT 1  /*!<Posición del primer objeto*/
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


 /**
 * @brief Obtiene la descrpicion del objeto
 *
 * object_get_description sirve para obtener la descrpicion del objeto
 *
 * @date 10-04-2021
 * @author Gonzalo Martín
 *
 * @param object recibe un puntero a la estructura de datos objeto
 * @return const char devuelve la descrpicion del objeto
 */
 const char* object_get_description(Object* object);

 /**
 * @brief Determina la descrpicion del objeto
 *
 * object_set_description sirve para determinar la descrpicion del objeto
 *
 * @date 10-04-2021
 * @author Gonzalo Martín
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param descr descripción del objeto
 * @return STATUS devuelve un tipo de dato STATUS que es OK si se ejecuta la función sin errores y ERROR si detecta algun error. 
 */
 STATUS object_set_description(Object* object , char* descr);


/**
 * @brief Devuelve el Id de un objeto
 *
 * object_get_id_by_name devuelve el Id de un objeto dependiendo del nombre
 *
 * @date 10-04-2021
 * @author Gonzalo Martín
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param name nombre del objeto
 * @return el Id del objeto con el nobre pasado por argumento 
 */
 Id object_get_id_by_name (Object *object , char *name);
 /**
 * @brief Devuelve si el objeto se puede o no mover
 *
 * object_get_movement devuelve si el objeto puede alterar su movimiento
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @return TRUE O FALSE segun si se puede o no mover.
 */
 BOOL object_get_movement(Object *object);
  /**
 * @brief Cambia el movimiento del objeto
 *
 * object_set_movement cambia el movimiento del objeto
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param bol nuevo valor del movimiento
 * @return OK o ERROR segun si se ha realizado de manera correcta.
 */
STATUS object_set_movement(Object *object,BOOL bol);
 /**
 * @brief Devuelve si la dependencia del objeto
 *
 * object_get_movement devuelve la dependencia del objeto
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @return id, el id de la dependencia
 */
Id object_get_dependency(Object *object);
  /**
 * @brief Cambia la dependencia de un objeto
 *
 * object_set_movement cambia la dependencia de un objeto
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param id nueva id del objeto del que depende
 * @return OK o ERROR segun si se ha realizado de manera correcta.
 */
STATUS object_set_dependency(Object *object,Id id);
  /**
 * @brief Devuelve si el objeto abre algun link
 *
 * object_get_link_open devuelve que link abre el objeto
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @return id, el id del link que abre
 */
Id object_get_link_open(Object *object);
  /**
 * @brief Cambia el link que abre un objeto
 *
 * object_set_link_open cambia el id que abre un objeto
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param id id del link que abre
 * @return OK o ERROR segun si se ha realizado de manera correcta.
 */
STATUS object_set_link_open(Object *object,Id id);

 /**
 * @brief Devuelve si el objeto puede iluminar o no
 *
 * object_get_iluminate devuelve si el objeto puede iluminar
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @return TRUE O FALSE segun si se puede o no mover.
 */
 BOOL object_get_iluminate(Object *object);
  /**
 * @brief Cambia la caracteristica de iluminar
 *
 * object_set_iluminate modfica la iluminación
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param bol nuevo valor del movimiento
 * @return OK o ERROR segun si se ha realizado de manera correcta.
 */
STATUS object_set_iluminate(Object *object,BOOL bol);

 /**
 * @brief Devuelve si el objeto puede iluminar o no
 *
 * object_get_turnedon devuelve si el objeto que puede iluminar esta iluminado
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @return TRUE O FALSE segun si se puede o no mover.
 */
 BOOL object_get_turnedon(Object *object);
  /**
 * @brief Cambia la caracteristica de si un objeto esta o no iluminado
 *
 * object_set_turnedon modfica si el objeto que puede iluminarse esta iluminado
 *
 * @date 20-04-20
 * @author Álvaro Rodríguez Rodrigo
 *
 * @param object recibe un puntero a la estructura de datos objeto 
 * @param bol nuevo valor del movimiento
 * @return OK o ERROR segun si se ha realizado de manera correcta.
 */
STATUS object_set_turnedon(Object *object,BOOL bol);


#endif
