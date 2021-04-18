/** 
 * @brief Archivo cabecera de link_test.c en el se encuentra definidas los datos y funciones de link_test.c
 * 
 * @file link_test.h
 * @author Alberto Vicente
 * @version 2.0 
 * @date 14-04-2021
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

 /**
 * @test Función de prueba para link_create
 * @pre Crea un link y comprueba si es diferente a NULL
 * @post Output!=NULL
 */
void test1_link_create();

/**
 * @test Función de prueba para link_create
 * @pre Crea un link with id y comprueba si tiene una id correcta
 * @post Output==5
 */
void test2_link_create();

/**
 * @test Función de prueba para link_get_id
 * @pre Crea un link con id y comprueba si la id es correcta
 * @post Output==5
 */
void test1_link_get_id();

/**
 * @test Función de prueba para link_get_id
 * @pre Puntero a link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id();

/**
 * @test Función de prueba para link_set_id
 * @pre Inputs correctos con id valida
 * @post Output==OK
 */
void test1_link_set_id();

/**
 * @test Función de prueba para link_set_id
 * @pre Inputs incorrectos con id no valida
 * @post Output==ERROR
 */
void test2_link_set_id();

/**
 * @test Función de prueba para link_set_id
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id();

/**
 * @test Función de prueba para link_get_name
 * @pre Comprueba que el nombre se establecio correctamente
 * @post Output==OK
 */
void test1_link_get_name();

/**
 * @test Función de prueba para link_get_name
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test2_link_get_name();

/**
 * @test Función de prueba para link_set_name
 * @pre Inputs correctos con char valido
 * @post Output==OK
 */
void test1_link_set_name();

/**
 * @test Función de prueba para link_set_name
 * @pre Inputs incorrecots con char no valido
 * @post Output==ERROR
 */
void test2_link_set_name();

/**
 * @test Función de prueba para link_set_name
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test3_link_set_name();

/**
 * @test Función de prueba para link_get_id_from
 * @pre Crea un link con id y comprueba si la id es correcta
 * @post Output==6
 */
void test1_link_get_id_from();

/**
 * @test Función de prueba para link_get_id_from
 * @pre Puntero a link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id_from();

/**
 * @test Función de prueba para link_set_id_from
 * @pre Inputs correctos con id valida
 * @post Output==OK
 */
void test1_link_set_id_from();

/**
 * @test Función de prueba para link_set_id_from
 * @pre Inputs incorrectos con id no valida
 * @post Output==ERROR
 */
void test2_link_set_id_from();

/**
 * @test Función de prueba para link_set_id_from
 * @pre puntero a link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id_from();

/**
 * @test Función de prueba para link_get_id_to
 * @pre crea un link with id y comprueba if it had correct Id
 * @post Output==6
 */
void test1_link_get_id_to();

/**
 * @test Función de prueba para link_get_id_to
 * @pre puntero a link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id_to();

/**
 * @test Función de prueba para link_set_id_to
 * @pre Inputs correctos con id valida
 * @post Output==OK
 */
void test1_link_set_id_to();

/**
 * @test Función de prueba para link_set_id_to
 * @pre Inputs incorrectos con id no valida
 * @post Output==ERROR
 */
void test2_link_set_id_to();

/**
 * @test Función de prueba para link_set_id_to
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id_to();

/**
 * @test Función de prueba para link_get_type
 * @pre Inputs correctos con id valida
 * @post Output==OPEN
 */
void test1_link_get_type();

/**
 * @test Función de prueba para link_get_type
 * @pre Puntero a link=NULL
 * @post Output==CLOSE
 */
void test2_link_get_type();

/**
 * @test Función de prueba para link_get_type
 * @pre Inputs correctos con id valida
 * @post Output==OK
 */
void test1_link_set_type();

/**
 * @test Función de prueba para link_get_type
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test2_link_set_type();

/**
 * @test Función de prueba para link_print
 * @pre Puntero a link=NULL
 * @post Output==ERROR
 */
void test1_link_print();

/**
 * @test Función de prueba para link_print
 * @pre  Puntero a link valido pero fichero no valido
 * @post Output==ERROR
 */
void test2_link_print();

/**
 * @test Función de prueba para link_print
 * @pre Fichero y puntero correctos
 * @post Output==OK
 */
void test3_link_print();


#endif