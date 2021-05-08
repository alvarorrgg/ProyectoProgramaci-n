/** 
 * @brief Archivo cabecera de space_test.c en el se encuentra definidas los datos y funciones de space_test.c
 * 
 * 
 * @file space_test.h
 * @author Profesores Pprog, Álvaro Rodríguez, Gonzalo Martín
 * @version 2.0 
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H
#include "test.h"
#include "set.h"
#include "space.h"
#include "link.h"
/**
 * @test Función de prueba para space_creation
 * @pre Space ID 
 * @post Non NULL Puntero a space 
 */
void test1_space_create();

/**
 * @test Función de prueba para space_creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Función de prueba para space_name setting
 * @pre String con nombre del space
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Función de prueba para space_name setting
 * @pre Puntero a space = NULL 
 * @post Output==NULL
 */
void test2_space_set_name();

/**
 * @test Función de prueba para space_name setting
 * @pre Puntero a space_name = NULL 
 * @post Output==NULL
 */
void test3_space_set_name();
/**
 * @test Función de prueba para space_north 
 * @pre Inputs correctos
 * @post Output==OK
 */
void test1_space_set_north();
/**
 * @test Función de prueba para space_north 
 * @pre Puntero a space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_north();

/**
 * @test Función de prueba para space_south 
 * @pre Inputs correctos
 * @post Output==OK
 */
void test1_space_set_south();
/**
 * @test Función de prueba para space_south
 * @pre Puntero a space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_south();
/**
 * @test Función de prueba para space_east 
 * @pre Inputs correctos
 * @post Output==OK
 */
void test1_space_set_east();
/**
 * @test Función de prueba para space_east
 * @pre Puntero a space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_east();
/**
 * @test Función de prueba para space_west 
 * @pre Inputs correctos
 * @post Output==OK
 */
void test1_space_set_west();
/**
 * @test Función de prueba para space_west
 * @pre Puntero a space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_west();
/**
 * @test Función de prueba para space_west
 * @pre Id=25
 * @post Output==25
 */
void test1_space_get_id();
/**
 * @test Función de prueba para space_west
 * @pre Puntero a space=NULL
 * @post Output==NO_ID
 */
void test2_space_get_id();
/**
 * @test Función de prueba para space_set_objects
 * @pre Se añade un objeto valido
 * @post Output==OK
 */
void test1_space_set_objects();
/**
 * @test Función de prueba para space_set_objects
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_set_objects();
/**
 * @test Función de prueba para space_get_name
 * @pre Dados inputs correctos compara los strings.
 * @post Output compare function with a string.
 */
void test1_space_get_name();
/**
 * @test Función de prueba para space_get_name
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_get_name();
/**
 * @test Función de prueba para space_get_north
 * @pre Dados inputs correctos esatblece una id valida
 * @post Output should be equal to north coordinate value.
 */
void test1_space_get_north();
/**
 * @test Función de prueba para space_get_north
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_get_north();
/**
 * @test Función de prueba para space_get_south
 * @pre Dados inputs correctos esatblece una id valida
 * @post Output should be equal to south coordinate value.
 */
void test1_space_get_south();
/**
 * @test Función de prueba para space_get_south
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_get_south();
/**
 * @test Función de prueba para space_get_east
 * @pre Dados inputs correctos esatblece una id valida
 * @post Output should be equal to east coordinate value.
 */
void test1_space_get_east();
/**
 * @test Función de prueba para space_get_east
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_get_east();
/**
 * @test Función de prueba para space_get_west
 * @pre Dados inputs correctos esatblece una id valida
 * @post Output should be equal to west coordinate value.
 */
void test1_space_get_west();
/**
 * @test Función de prueba para space_get_west
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test2_space_get_west();
/**
 * @test Función de prueba para space_get_object
 * @pre Inputs correctos pero objeto sin crear
 * @post Output==NULL
 */
void test1_space_get_object();
/**
 * @test Función de prueba para space_get_object
 * @pre Puntero a space=NULL
 * @post Output==NULL
 */
void test2_space_get_object();
/**
 * @test Función de prueba para space_remove_object
 * @pre Inputs correctos.
 * @post Output==OK
 */
void test1_space_remove_object(); 
/**
 * @test Función de prueba para space_remove_object
 * @pre Intenta eliminar un objeto con una id no valida
 * @post Output==ERROR
 */
void test2_space_remove_object();
/**
 * @test Función de prueba para space_has_object_id
 * @pre Puntero a space=NULL
 * @post Output==FALSE
 */
void test1_space_has_object_id();
/**
 * @test Función de prueba para space_has_object_id
 * @pre Inputs correctos.
 * @post Output==TRUE
 */
void test2_space_has_object_id();
/**
 * @test Función de prueba para space_has_object_id
 * @pre Dados inputs correctos pero con id desconocida.
 * @post Output==FALSE
 */
void test3_space_has_object_id();
/**
 * @test Función de prueba para space_set_gdesc
 * @pre Puntero a space=NULL
 * @post Output==ERROR
 */
void test1_space_set_gdesc();
/**
 * @test Función de prueba para space_set_gdesc
 * @pre Inputs correctos.
 * @post Output==OK
 */
void test2_space_set_gdesc();
/**
 * @test Función de prueba para space_get_gdesc
 * @pre Puntero a space=NULL
 * @post Output==NULL
 */
void test1_space_get_gdesc();
/**
 * @test Función de prueba para space_get_gdesc
 * @pre Inputs correctos.
 * @post Output=="Hola"
 */
void test2_space_get_gdesc();

/**
 * @test Función de prueba para space_set_descripcion
 * @pre Un space nulo .
 * @post Output==ERROR
 */
void test1_space_set_description();

/**
 * @test Función de prueba para space_set_descripcion
 * @pre Una descripción nula.
 * @post Output==ERROR
 */
void test2_space_set_description();

/**
 * @test Función de prueba para space_set_descripcion
 * @pre Inputs correctos.
 * @post Output==OK
 */
void test3_space_set_description();

/**
 * @test Función de prueba para space_get_descripcion
 * @pre Espacio nulo
 * @post Output==ERROR
 */
void test1_space_get_description();

/**
 * @test Función de prueba para space_get_descripcion
 * @pre Inputs corerctos
 * @post Output=="Ejemplo descripcion"
 */
void test2_space_get_description();

/**
 * @test Función de prueba para space_set_ilumination
 * @pre Space==NULL
 * @post Output==ERROR
 */
void test1_space_set_ilumination();
/**
 * @test Función de prueba para space_set_ilumination
 * @pre BOOL==-1
 * @post Output==ERROR
 */
void test2_space_set_ilumination();
/**
 * @test Función de prueba para space_set_ilumination
 * @pre Inputs correctos
 * @post Output==OK
 */
void test3_space_set_ilumination();
/**
 * @test Función de prueba para space_get_ilumination
 * @pre Space==NULL
 * @post Output==FALSE
 */
void test1_space_get_ilumination();

/**
 * @test Función de prueba para space_get_ilumination
 * @pre Inputs correctos
 * @post Output==1
 */
void test2_space_get_ilumination();

/**
 * @test Función de prueba para space_set_detailed_descripcion
 * @pre Un space nulo .
 * @post Output==ERROR
 */
void test1_space_set_detailed_description();

/**
 * @test Función de prueba para space_set_detailed_descripcion
 * @pre Una descripción nula.
 * @post Output==ERROR
 */
void test2_space_set_detailed_description();

/**
 * @test Función de prueba para space_set_detailed_descripcion
 * @pre Inputs correctos.
 * @post Output==OK
 */
void test3_space_set_detailed_description();

/**
 * @test Función de prueba para space_get_detailed_descripcion
 * @pre Espacio nulo
 * @post Output==ERROR
 */
void test1_space_get_detailed_description();

/**
 * @test Función de prueba para space_get_detailed_descripcion
 * @pre Inputs corerctos
 * @post Output=="Ejemplo descripcion detallada"
 */
void test2_space_get_detailed_description();
#endif
