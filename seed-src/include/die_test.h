/** 
 * @brief Archivo cabecera de die_test.c en el se encuentra definidas los datos y funciones de die_test.c
 * 
 * @file die_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */
#ifndef DIE_TEST_H
#define DIE_TEST_H
 /**
 * @test Función de prueba para die_create
 * @pre Crea un dado con id=5 y comprueba que el ultimo tiro fue correcto
 * @post Output==NO_ID
 */
void test1_die_create();
 /**
 * @test Función de prueba para die_create
 * @pre Crea un dado con una id determinada y comprueba que esa id sea valida
 * @post Output==5
 */
void test2_die_create();


 /**
 * @test Función de prueba paradie_roll
 * @pre Puntero a die=NULL
 * @post Output==-1
 */
void test1_die_roll();
 /**
 * @test Función de prueba para die_roll
 * @pre Crea un dado, lo tira y comprueba que el resultado esta en el intervalo asignado.
 * @post Output>0 && <7
 */
void test2_die_roll();


 /**
 * @test Función de prueba para die_set_Id
 * @pre Puntero a die=NULL
 * @post Output==ERROR
 */
void test1_die_set_Id();
 /**
 * @test Función de prueba para die_set_Id
 * @pre Inputs correctos con Id valida para ser establecida
 * @post Output==OK
 */
void test2_die_set_Id();
 /**
 * @test Función de prueba para die_set_Id
 * @pre Given correct inputs with a negative Id value to set.
 * @post Output==ERROR
 */
void test3_die_set_Id();


 /**
 * @test Función de prueba para die_get_last_roll
 * @pre Puntero a die==NULL
 * @post Output==-1
 */
void test1_die_get_last_roll();
 /**
 * @test Función de prueba para die_get_last_roll
 * @pre Crea un dado, lo tira y comprueba que el valor esta en el intervalo asignado.
 * @post Output>0 && <7
 */
void test2_die_get_last_roll();


 /**
 * @test Función de prueba para die_get_id
 * @pre Puntero a die==NULL
 * @post Output==NO_ID
 */
void test1_die_get_id();
 /**
 * @test Función de prueba paradie_get_id
 * @pre Crea un dado con Id=5 y comprueba que la id se almacenó correctamente
 * @post Output==5
 */
void test2_die_get_id();


 /**
 * @test Función de prueba para die_print
 * @pre Puntero a die==NULL
 * @post Output==ERROR
 */
void test1_die_print();
 /**
 * @test Función de prueba paradie_print
 * @pre Puntero correcto pero fichero incorrecto
 * @post Output==ERROR
 */
void test2_die_print();
 /**
 * @test Función de prueba para die_print
 * @pre Tanto el fichero como el puntero son correctos
 * @post Output==OK
 */
void test3_die_print();

#endif
