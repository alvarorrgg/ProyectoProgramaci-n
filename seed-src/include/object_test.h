/** 
 * @brief It declares the tests for the object module
 * 
 * @file object_test.h
 * @author Gonzalo MArtin
 * @version 2.0 
 * @date 13-04-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Test function for object_create
 * @pre given correct inputs and looking if return diferent than NULL
 * @post Output != NULL
 */
    void test1_object_create();  

/**
 * @test Test function for object_create
 * @pre given correct inputs and looking if the object id is the correct
 * @post Output == id
 */
    void test2_object_create();  

/**
 * @test Test function for object_destroy
 * @pre given NULL object
 * @post Output == ERRROR
 */
    void test1_object_destroy();  

/**
 * @test Test function for object_destroy
 * @pre given a correct input
 * @post Output == OK
 */
    void test2_object_destroy();  

/**
 * @test Test function for object_get_id
 * @pre given NULL object
 * @post Output == NO_ID
 */
    void test1_object_get_id();  

/**
 * @test Test function for object_get_id
 * @pre given correct input
 * @post Output == 05
 */
    void test2_object_get_id(); 

/**
 * @test Test function for object_set_name
 * @pre given a NULL object
 * @post Output == ERROR
 */
    void test1_object_set_name();   

/**
 * @test Test function for object_set_name
 * @pre given a NULL name
 * @post Output == ERROR
 */
    void test2_object_set_name();   

/**
 * @test Test function for object_set_name
 * @pre given correct inputs
 * @post Output == OK
 */
    void test3_object_set_name();   

/**
 * @test Test function for object_set_id
 * @pre given a NULL object
 * @post Output == ERROR
 */
    void test1_object_set_id();   

/**
 * @test Test function for object_set_id
 * @pre given correct inputs
 * @post Output == OK
 */
    void test2_object_set_id();  

/**
 * @test Test function for object_get_name
 * @pre given a NULL object
 * @post Output == NULL
 */
    void test1_object_get_name();  

/**
 * @test Test function for object_get_name
 * @pre given a correct input
 * @post Output == Nombre
 */
    void test2_object_get_name();  

/**
 * @test Test function for object_get_descripcion
 * @pre given a NULL object
 * @post Output == NULL
 */
    void test1_object_get_descripcion();  

/**
 * @test Test function for object_get_descripcion
 * @pre given a correct input
 * @post Output == Ejemplo descripcion
 */
    void test2_object_get_descripcion();  

/**
 * @test Test function for object_set_descripcion
 * @pre given NULL object
 * @post Output == EERROR;
 */
    void test1_object_set_descripcion();  

/**
 * @test Test function for object_set_descripcion
 * @pre given a NULL descr
 * @post Output == EERROR;
 */
    void test2_object_set_descripcion();  

/**
 * @test Test function for object_set_descripcion
 * @pre given corrects inputs
 * @post Output == OK;
 */
    void test3_object_set_descripcion();

/**
 * @test Test function for object_get_id_by_name
 * @pre given a NULL object
 * @post Output == -1
 */
    void test1_object_get_id_by_name();   

/**
 * @test Test function for object_get_id_by_name
 * @pre given a NULL name
 * @post Output == -1
 */
    void test2_object_get_id_by_name();   

/**
 * @test Test function for object_get_id_by_name
 * @pre given correct inputs
 * @post Output == 05
 */
    void test3_object_get_id_by_name();

/**
 * @test Test function for object_print
 * @pre given a NULL object
 * @post Output == ERROR
 */
    void test1_object_print();

/**
 * @test Test function for object_print
 * @pre given a correct input
 * @post Output == OK
 */
    void test2_object_print();

#endif