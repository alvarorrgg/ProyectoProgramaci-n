/** 
 * @brief Archivo cabecera de inventory_test.c en el se encuentra definidas los datos y funciones de inventory_test.c
 * 
 * @file inventory_test.h
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */
#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H
 /**
 * @test Función de prueba para inventory_create
 * @pre Crea un inventario y comprueba si es diferente a NULL
 * @post Output!=NULL
 */
void test1_inventory_create();

 /**
 * @test Función de prueba para inventory_create
 * @pre Crea un inventario y comprueba si está vacio
 * @post Output==TRUE
 */
void test2_inventory_create();

 /**
 * @test Función de prueba para inventory_destroy
 * @pre Intenta destruir un inventario no inicializado
 * @post Output==ERROR
 */
void test1_inventory_destroy();

 /**
 * @test Función de prueba para inventory_set_object
 * @pre Intenta añadir un objeto a inventario no inicializado
 * @post Output==ERROR
 */
void test1_inventory_set_object();

 /**
 * @test Función de prueba para inventory_set_object
 * @pre Intenta añadir un objeto que ya existe
 * @post Output==ERROR
 */
void test2_inventory_set_object();

 /**
 * @test Función de prueba para inventory_set_object
 * @pre Intenta añadir un objeto con Id negativa
 * @post Output==ERROR
 */
void test3_inventory_set_object();

/**
 * @test Función de prueba para inventory_set_object
 * @pre Intenta añadir un objeto con id=NULL
 * @post Output==ERROR
 */
void test4_inventory_set_object();

/**
 * @test Función de prueba para inventory_set_object
 * @pre Establece el numero de objetos a 15 e intenta añadir uno mas
 * @post Output==ERROR
 */
void test5_inventory_set_object();
/**
 * @test Función de prueba para inventory_get_number_of_objects
 * @pre Dado un inventario no inicializado intenta ver cuantos objetos hay
 * @post Output==-1
 */
void test1_inventory_get_number_of_objects();
/**
 * @test Función de prueba para inventory_get_number_of_objects
 * @pre Añade un objeto y comprueba el número de objetos que hay
 * @post Output==1
 */
void test2_inventory_get_number_of_objects();
/**
 * @test Función de prueba para inventory_get_inventory
 * @pre Intenta obtener los objetos de un inventario no inicializado
 * @post Output==NULL
 */
void test1_inventory_get_inventory();

/**
 * @test Función de prueba para inventory_get_inventory
 * @pre Intenta obtener los objetos de un inventario con 0 objetos
 * @post Output==NULL
 */
void test2_inventory_get_inventory();

/**
 * @test Función de prueba para inventory_print
 * @pre Intenta imprimir un NULL
 * @post Output==ERROR
 */
void test1_inventory_print();

/**
 * @test Función de prueba para inventory_print
 * @pre Intenta printear con un fichero=NULL
 * @post Output==ERROR
 */
void test2_inventory_print();

/**
 * @test Función de prueba para inventory_print
 * @pre Intenta printear con inputs correctos
 * @post Output==OK
 */
void test3_inventory_print();

/**
 * @test Función de prueba para inventory_delete_object
 * @pre Intenta borrar un objeto de un inventario no inicializado
 * @post Output==ERROR
 */
void test1_inventory_delete_object();

/**
 * @test Función de prueba para inventory_delete_object
 * @pre Intenta borrar un objeto con id=NULL
 * @post Output==ERROR
 */
void test2_inventory_delete_object();

/**
 * @test Función de prueba para inventory_delete_object
 * @pre Intenta borrar un objeto con id negativa
 * @post Output==ERROR
 */
void test3_inventory_delete_object();

/**
 * @test Función de prueba para inventory_delete_object
 * @pre Intenta borrar un objeto de un inventario vacio
 * @post Output==ERROR
 */
void test4_inventory_delete_object();

/**
 * @test Función de prueba para inventory_delete_object
 * @pre Intenta borrar un objeto que no está en el inventario
 * @post Output==ERROR
 */
void test5_inventory_delete_object();

/**
 * @test Función de prueba para inventory_is_empty
 * @pre Inventario no inicializado
 * @post Output==ERROR
 */
void test1_inventory_is_empty();

/**
 * @test Función de prueba para inventory_is_empty
 * @pre Un inventario no vacio
 * @post Output==FALSE
 */
void test2_inventory_is_empty();

/**
 * @test Función de prueba para inventory_is_empty
 * @pre Un inventario vacio
 * @post Output==TRUE
 */
void test3_inventory_is_empty();

/**
 * @test Función de prueba para inventory_is_full
 * @pre Un inventario no inicializado
 * @post Output==FALSE
 */
void test1_inventory_is_full();

/**
 * @test Función de prueba para inventory_is_full
 * @pre Un inventario no lleno
 * @post Output==FALSE
 */
void test2_inventory_is_full();

/**
 * @test Función de prueba para inventory_is_full
 * @pre Un inventario lleno
 * @post Output==TRUE
 */
void test3_inventory_is_full();

/**
 * @test Función de prueba para inventory_serach_object
 * @pre Un inventario no inicializado
 * @post Output==FALSE
 */
void test1_inventory_search_object();

/**
 * @test Función de prueba para inventory_search_object
 * @pre Una id=NO_ID
 * @post Output==FALSE
 */
void test2_inventory_search_object();

/**
 * @test Función de prueba para inventory_search_object
 * @pre Un inventario negativo
 * @post Output==FALSE
 */
void test3_inventory_search_object();

/**
 * @test Función de prueba para inventory_search_object
 * @pre Intenta buscar un objeto que no está en el inventario
 * @post Output==FALSE
 */
void test4_inventory_search_object();

/**
 * @test Función de prueba para inventory_search_object
 * @pre Intenta un objeto que no está en el inventario 
 * @post Output==TRUE
 */
void test5_inventory_search_object();

/**
 * @test Función de prueba para inventory_set_max_objects
 * @pre Un inventario no inicializado
 * @post Output==ERROR
 */
void test1_inventory_set_max_objects();

/**
 * @test Función de prueba para inventory_set_max_objects
 * @pre Un numero negativo
 * @post Output==ERROR
 */
void test2_inventory_set_max_objects();

/**
 * @test Función de prueba para inventory_set_max_objects
 * @pre Inputs correctos
 * @post Output==numero anterior del set
 */
void test3_inventory_set_max_objects();

/**
 * @test Función de prueba para inventory_get_max_objects
 * @pre Un inventario no inicializado
 * @post Output==-1
 */
void test1_inventory_get_max_objects();

/**
 * @test Función de prueba para inventory_get_max_objects
 * @pre Un inventario correcto
 * @post Output == 15 
 */
void test2_inventory_get_max_objects();



#endif