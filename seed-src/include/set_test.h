/** 
 * @brief Archivo cabecera de set_test.c en el se encuentra definidas los datos y funciones de set_test.c
 * 
 * @file set_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H
/**
 * @test Función de prueba para set_create
 * @pre Dados inputs correctos comprueba si total ids=0
 * @post Output==0
 */
  void test1_set_create();  
 /**
 * @test Función de prueba para set_create
 * @pre Dados inputs correctos comprueba si el set está vacío
 * @post Output==TRUE
 */
  void test2_set_create();
   /**
 * @test Función de prueba para set_id_add
 * @pre Puntero a set=NULL
 * @post Output==ERROR
 */
  void test1_set_id_add();
   /**
 * @test Función de prueba para set_id_add
 * @pre Dados inputs validos comprueba que se puede añadir una id
 * @post Output==OK
 */
  void test2_set_id_add();
   /**
 * @test Función de prueba para set_id_add
 * @pre Dados inputs validos comprueba que no se puede añadir una id negativa
 * @post Output==ERROR
 */
  void test3_set_id_add();
   /**
 * @test Función de prueba para set_id_add
 * @pre Establece el numero de ids a 1000 y comprueba que no se puede añadir otra id
 * @post Output==ERROR
 */
  void test4_set_id_add(); 
  
   /**
 * @test Función de prueba para set_id_delete
 * @pre Puntero a set=NULL
 * @post Output==ERROR
 */ 
  void test1_set_id_delete();
   /**
 * @test Función de prueba para set_id_delete
 * @pre Dados inputs validos añade una id y borra a la misma
 * @post Output==OK
 */
  void test2_set_id_delete();
   /**
 * @test Función de prueba para set_id_delete
 * @pre Dados inputs validos añade una id y borra otra
 * @post Output==ERROR
 */
  void test3_set_id_delete();
   /**
 * @test Función de prueba para set_id_delete
 * @pre Esatblece el número de ids a 0 e intenta borrar una id
 * @post Output==ERROR
 */
  void test4_set_id_delete();
  
     /**
 * @test Función de prueba para set_set_total_ids
 * @pre Puntero a set=NULL
 * @post Output==ERROR
 */  
  void test1_set_set_total_ids();
     /**
 * @test Función de prueba para set_set_total_ids
 * @pre Dados inputs validos intenta establecer un total ids negativo
 * @post Output==ERROR
 */
  void test2_set_set_total_ids();
     /**
 * @test Función de prueba para set_set_total_ids
 * @pre Dados inputs validos intenta establecer un total ids valido
 * @post Output==OK
 */
  void test3_set_set_total_ids(); 
  /**
 * @test Función de prueba para set_get_total_ids
 * @pre Puntero a set=NULL
 * @post Output==ERROR
 */
  void test1_set_get_total_ids();
  /**
 * @test Función de prueba para set_get_total_ids
 * @pre Dados inputs validos sin establecer el total ids
 * @post Output==OK
 */
  void test2_set_get_total_ids();
  
   /**
 * @test Función de prueba para set_has_id
 * @pre Puntero a set=NULL
 * @post Output==FALSE
 */
  void test1_set_has_id();
   /**
 * @test Función de prueba para set_has_id
 * @pre Dados inputs validos establece un id correcta y llama a la función
 * @post Output==TRUE
 */
  void test2_set_has_id();
   /**
 * @test Función de prueba para set_has_id
 * @pre Dados inputs validos establece un id correcta y llama a la función con otra id
 * @post Output==FALSE
 */
  void test3_set_has_id();
   /**
 * @test Función de prueba para set_has_id
 * @pre Llama a la función para buscar una id negativa
 * @post Output==FALSE
 */
  void test4_set_has_id(); 
  
  /**
 * @test Función de prueba para set_find_object_by_id
 * @pre Puntero a set=NULL
 * @post Output==NO_ID
 */
  void test1_set_find_object_by_id();
  /**
 * @test Función de prueba para set_find_object_by_id
 * @pre Dados inputs validos crea una id correcta y encuentra su indice
 * @post Output!=NO_ID
 */
  void test2_set_find_object_by_id();
  /**
 * @test Función de prueba para set_find_object_by_id
 * @pre Dados inputs validos crea una id correcta y busca un indice negativo
 * @post Output==NO_ID
 */
  void test3_set_find_object_by_id();
  /**
 * @test Función de prueba para set_find_object_by_id
 * @pre Dados inputs validos crea una id correcta y busca una id completamente diferente
 * @post Output==FALSE
 */
  void test4_set_find_object_by_id(); 
   /**
 * @test Función de prueba para set_is_empty
 * @pre Puntero a set=NULL
 * @post Output==FALSE
 */
  void test1_set_is_empty();
   /**
 * @test Función de prueba para set_is_empty
 * @pre Dados inputs validos no se añade una id
 * @post Output==TRUE
 */
  void test2_set_is_empty();
   /**
 * @test Función de prueba para set_is_empty
 * @pre Dados inputs validos añade una id
 * @post Output==FALSE
 */
  void test3_set_is_empty();  
  /**
 * @test Función de prueba para set_is_full
 * @pre Puntero a set=NULL
 * @post Output==FALSE
 */
  void test1_set_is_full();
  /**
 * @test Función de prueba para set_is_full
 * @pre Establece total ids a 1000 y llama a la función
 * @post Output==TRUE
 */
  void test2_set_is_full();
  /**
 * @test Función de prueba para set_is_full
 * @pre Establece total ids a 100 y llama a la función
 * @post Output==TRUE
 */
  void test3_set_is_full();
  /**
 * @test Función de prueba para set_is_full
 * @pre Establece total ids a 50 y llama a la función
 * @post Output==FALSE
 */
  void test4_set_is_full();  
   /**
 * @test Función de prueba para set_print
 * @pre Puntero a set=NULL
 * @post Output==ERROR
 */
  void test1_set_print();
   /**
 * @test Función de prueba para set_print
 * @pre Fichero NULL
 * @post Output==ERROR
 */
  void test2_set_print();
   /**
 * @test Función de prueba para set_print
 * @pre Dados inputs validos llama a la función
 * @post Output==OK
 */
  void test3_set_print();
   /**
 * @test Función de prueba para set_get_ids
 * @pre Puntero a set=NULL
 * @post Output==NULL
 */
  void test1_set_get_ids();
   /**
 * @test Función de prueba para set_get_ids
 * @pre No añade una id y llama a la función
 * @post Output==NULL
 */
  void test2_set_get_ids();

#endif
