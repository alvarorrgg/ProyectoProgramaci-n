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
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==NULL
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==NULL
 */
void test3_space_set_name();
/**
 * @test Test function for space_north 
 * @pre space_created correctly and given a correct input
 * @post Output==OK
 */
void test1_space_set_north();
/**
 * @test Test function for space_north 
 * @pre pointer to space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_north();

/**
 * @test Test function for space_south 
 * @pre space_created correctly and given a correct input
 * @post Output==OK
 */
void test1_space_set_south();
/**
 * @test Test function for space_south
 * @pre pointer to space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_south();
/**
 * @test Test function for space_east 
 * @pre space_created correctly and given a correct input
 * @post Output==OK
 */
void test1_space_set_east();
/**
 * @test Test function for space_east
 * @pre pointer to space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_east();
/**
 * @test Test function for space_west 
 * @pre space_created correctly and given a correct input
 * @post Output==OK
 */
void test1_space_set_west();
/**
 * @test Test function for space_west
 * @pre pointer to space=NULL
 * @post Output==NO_ID
 */
void test2_space_set_west();
/**
 * @test Test function for space_west
 * @pre space_created correctly and given Id=25
 * @post Output==25
 */
void test1_space_get_id();
/**
 * @test Test function for space_west
 * @pre pointer to space=NULL
 * @post Output==NO_ID
 */
void test2_space_get_id();
/**
 * @test Test function for space_set_objects
 * @pre space_created correctly and an object added in space
 * @post Output==OK
 */
void test1_space_set_objects();
/**
 * @test Test function for space_set_objects
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_set_objects();
/**
 * @test Test function for space_get_name
 * @pre space created correctly and set his name to a correct string then compared strings.
 * @post Output compare function with a string.
 */
void test1_space_get_name();
/**
 * @test Test function for space_get_name
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_get_name();
/**
 * @test Test function for space_get_north
 * @pre space created correctly and set his north cordinate to a correct id 
 * @post Output should be equal to north coordinate value.
 */
void test1_space_get_north();
/**
 * @test Test function for space_get_north
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_get_north();
/**
 * @test Test function for space_get_south
 * @pre space created correctly and set his south cordinate to a correct id 
 * @post Output should be equal to south coordinate value.
 */
void test1_space_get_south();
/**
 * @test Test function for space_get_south
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_get_south();
/**
 * @test Test function for space_get_east
 * @pre space created correctly and set his east cordinate to a correct id 
 * @post Output should be equal to east coordinate value.
 */
void test1_space_get_east();
/**
 * @test Test function for space_get_east
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_get_east();
/**
 * @test Test function for space_get_west
 * @pre space created correctly and set his west cordinate to a correct id 
 * @post Output should be equal to west coordinate value.
 */
void test1_space_get_west();
/**
 * @test Test function for space_get_west
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test2_space_get_west();
/**
 * @test Test function for space_get_object
 * @pre given a correct space input without an object creation
 * @post Output==NULL
 */
void test1_space_get_object();
/**
 * @test Test function for space_get_object
 * @pre pointer to space=NULL
 * @post Output==NULL
 */
void test2_space_get_object();
/**
 * @test Test function for space_remove_object
 * @pre everything created correctly with the correct inputs.
 * @post Output==OK
 */
void test1_space_remove_object(); 
/**
 * @test Test function for space_remove_object
 * @pre Trying to remove an object which id does exists
 * @post Output==ERROR
 */
void test2_space_remove_object();
/**
 * @test Test function for space_has_object_id
 * @pre pointer to space=NULL
 * @post Output==FALSE
 */
void test1_space_has_object_id();
/**
 * @test Test function for space_has_object_id
 * @pre everything created correctly with the correct inputs.
 * @post Output==TRUE
 */
void test2_space_has_object_id();
/**
 * @test Test function for space_has_object_id
 * @pre everything created correctly with the correct inputs but searchs for unknown id.
 * @post Output==FALSE
 */
void test3_space_has_object_id();
/**
 * @test Test function for space_set_gdesc
 * @pre pointer to space=NULL
 * @post Output==ERROR
 */
void test1_space_set_gdesc();
/**
 * @test Test function for space_set_gdesc
 * @pre everything created correctly with the correct inputs and the correct mallocs.
 * @post Output==OK
 */
void test2_space_set_gdesc();
/**
 * @test Test function for space_get_gdesc
 * @pre pointer to space=NULL
 * @post Output==NULL
 */
void test1_space_get_gdesc();
/**
 * @test Test function for space_get_gdesc
 * @pre everything created correctly with the correct inputs and the correct mallocs.
 * @post Output=="Hola"
 */
void test2_space_get_gdesc();

/**
 * @test Test function for space_set_descripcion
 * @pre a NULL space
 * @post Output==ERROR
 */
void test1_space_set_description();

/**
 * @test Test function for space_set_descripcion
 * @pre a NULL descripcion
 * @post Output==ERROR
 */
void test2_space_set_description();

/**
 * @test Test function for space_set_descripcion
 * @pre corrrect inputs
 * @post Output==OK
 */
void test3_space_set_description();

/**
 * @test Test function for space_get_descripcion
 * @pre a NULL space
 * @post Output==ERROR
 */
void test1_space_get_description();

/**
 * @test Test function for space_get_descripcion
 * @pre a correct input
 * @post Output=="Ejemplo descripcion"
 */
void test2_space_get_description();
#endif
