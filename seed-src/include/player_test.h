/** 
 * @brief Archivo cabecera de player_test.c en el se encuentra definidas los datos y funciones de player_test.c
 * 
 * @file player_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */
#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H
 /**
 * @test Función de prueba para player_Create
 * @pre Crea un player y comprueba si es diferente a NULL
 * @post Output!=NULL
 */
void test1_player_create();
 /**
 * @test Función de prueba para player_Create
 * @pre Crea un player con id y comprueba si tiene una id correcta
 * @post Output==5
 */
void test2_player_create();


 /**
 * @test Función de prueba para player_destroy
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_destroy();
 /**
 * @test Función de prueba para player_destroy
 * @pre Crea un player con id y comprueba si la salida es OK
 * @post Output==OK
 */
void test2_player_destroy();

 /**
 * @test Función de prueba para player_set_name
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_set_name();
 /**
 * @test Función de prueba para player_set_name
 * @pre Dado un char con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test2_player_set_name();
 /**
 * @test Función de prueba para player_set_name
 * @pre Crea un player y le da un nombre válido comprueba si la salida es el nombre llamando a la función player_get_name
 * @post Output=="Alvaro"
 */
void test3_player_set_name();


 /**
 * @test Función de prueba para player_get_name
 * @pre Dado un player con valor NULL comprueba si la salida es NULL
 * @post Output==NULL
 */
void test1_player_get_name();
 /**
 * @test Función de prueba para player_get_name
 * @pre Crea un player y comprueba si su nombre es diferente a NULL
 * @post Output!=NULL
 */
void test2_player_get_name();
 /**
 * @test Función de prueba para player_get_name
 * @pre Crea un player y le da un nombre válido comprueba si la salida es el nombre llamando a la función player_get_name
 * @post Output=="Alvaro"
 */
void test3_player_get_name();


 /**
 * @test Función de prueba para player_get_id
 * @pre Dado un player con valor NULL comprueba si la salida es NO_ID
 * @post Output==NO_ID
 */
void test1_player_get_id();
 /**
 * @test Función de prueba para player_get_id
 * @pre Crea un player y comprueba si la salida es el id Dado
 * @post Output==5
 */
void test2_player_get_id();


 /**
 * @test Función de prueba para player_get_objects
 * @pre Dado un player con valor NULL comprueba si la salida es NULL
 * @post Output==NULL
 */
void test1_player_get_objects();
 /**
 * @test Función de prueba para player_get_objects
 * @pre Crea un player y añade un objeto, luego comprueba si la salida es diferente de NULL
 * @post Output!=NULL
 */
void test2_player_get_objects();


 /**
 * @test Función de prueba para player_add_object
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_add_object();
 /**
 * @test Función de prueba para player_add_object
 * @pre Crea un player y añade un objeto, luego intenta añadir el mismo objeto otra vez
 * @post Output==ERROR
 */
void test2_player_add_object();
 /**
 * @test Función de prueba para player_add_object
 * @pre Crea un player e intenta añadir un objeto
 * @post Output==OK
 */
void test3_player_add_object();

 /**
 * @test Función de prueba para player_remove_object
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_remove_object();
 /**
 * @test Función de prueba para player_remove_object
 * @pre Crea un player y añade un objeto, luego intenta retirar otro objeto
 * @post Output==ERROR
 */
void test2_player_remove_object();
 /**
 * @test Función de prueba para player_remove_object
 * @pre Crea un player y añade un objeto, luego intenta retirar el mismo objeto
 * @post Output==OK
 */
void test3_player_remove_object();


 /**
 * @test Función de prueba para player_set_location
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_set_location();
 /**
 * @test Función de prueba para player_set_location
 * @pre Crea un player e intenta establecer su posición a NO_ID
 * @post Output==ERROR
 */
void test2_player_set_location();
 /**
 * @test Función de prueba para player_set_location
 * @pre Crea un player e intenta darle una posición válida
 * @post Output==OK
 */
void test3_player_set_location();


 /**
 * @test Función de prueba para player_get_location
 * @pre Dado un player con valor NULL comprueba si la salida es NO_ID
 * @post Output==NO_ID
 */
void test1_player_get_location();
 /**
 * @test Función de prueba para player_get_location
 * @pre Crea un player y cambia su posición con player_set_location, luego llama a player_get_location
 * @post Output==10
 */
void test2_player_get_location();

 /**
 * @test Función de prueba para player_has_object
 * @pre Dado un player con valor NULL comprueba si la salida es FALSE
 * @post Output==FALSE
 */
void test1_player_has_object();
 /**
 * @test Función de prueba para player_has_object
 * @pre Crea un player y comprueba si no tiene añadido ningún objeto
 * @post Output==FALSE
 */
void test2_player_has_object();
 /**
 * @test Función de prueba para player_has_object
 * @pre Crea un player, le añade un objeto y comprueba si tiene el miso objeto
 * @post Output==TRUE
 */
void test3_player_has_object();


 /**
 * @test Función de prueba para player_get_inventory
 * @pre Dado un player con valor NULL comprueba si la salida es NULL
 * @post Output==NULL
 */
void test1_player_get_inventory();
 /**
 * @test Función de prueba para player_get_inventory
 * @pre Crea un player y añade un objeto, luego comprueba si la salida es diferente de NULL
 * @post Output!=NULL
 */
void test2_player_get_inventory();


 /**
 * @test Función de prueba para player_set_inventory_max_capacity
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_set_inventory_max_capacity();
 /**
 * @test Función de prueba para player_set_inventory_max_capacity
 * @pre Crea a un player e intenta cambiar la capacidad máxima a una negativa
 * @post Output==ERROR
 */
void test2_player_set_inventory_max_capacity();
 /**
 * @test Función de prueba para player_set_inventory_max_capacity
 * @pre Crea un player e intenta cambiar la capacidad máxima a un número válido
 * @post Output==OK
 */
void test3_player_set_inventory_max_capacity();


 /**
 * @test Función de prueba para player_has_object
 * @pre Dado un player con valor NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test1_player_print();
 /**
 * @test Función de prueba para player_has_object
 * @pre Dado un fichero NULL comprueba si la salida es ERROR
 * @post Output==ERROR
 */
void test2_player_print();
 /**
 * @test Función de prueba para player_has_object
 * @pre dada una entrada válida comprueba si la salida es OK
 * @post Output==OK
 */
void test3_player_print();

#endif