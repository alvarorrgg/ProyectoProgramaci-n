/** 
 * @brief Archivo cabecera de object_test.c en el se encuentra definidas los datos y funciones de object_test.c
 * 
 * @file object_test.h
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 13-04-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Función de prueba para object_create
 * @pre Inputs correctos y comprueba si el return no es NULL
 * @post Output != NULL
 */
    void test1_object_create();  

/**
 * @test Función de prueba para object_create
 * @pre Inputs correctos y comprueba si el id del objeto es el correcto
 * @post Output == id
 */
    void test2_object_create();  

/**
 * @test Función de prueba para object_destroy
 * @pre Objeto=NULL
 * @post Output == ERRROR
 */
    void test1_object_destroy();  

/**
 * @test Función de prueba para object_destroy
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_destroy();  

/**
 * @test Función de prueba para object_get_id
 * @pre Objeto=NULL
 * @post Output == NO_ID
 */
    void test1_object_get_id();  

/**
 * @test Función de prueba para object_get_id
 * @pre given Inputs correctos
 * @post Output == 05
 */
    void test2_object_get_id(); 

/**
 * @test Función de prueba para object_set_name
 * @pre Objeto=NULL
 * @post Output == ERROR
 */
    void test1_object_set_name();   

/**
 * @test Función de prueba para object_set_name
 * @pre name=NULL
 * @post Output == ERROR
 */
    void test2_object_set_name();   

/**
 * @test Función de prueba para object_set_name
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test3_object_set_name();   

/**
 * @test Función de prueba para object_set_id
 * @pre Objeto=NULL
 * @post Output == ERROR
 */
    void test1_object_set_id();   

/**
 * @test Función de prueba para object_set_id
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_id();  

/**
 * @test Función de prueba para object_get_name
 * @pre Objeto=NULL
 * @post Output == NULL
 */
    void test1_object_get_name();  

/**
 * @test Función de prueba para object_get_name
 * @pre Inputs correctos
 * @post Output == Nombre
 */
    void test2_object_get_name();  

/**
 * @test Función de prueba para object_get_descripcion
 * @pre Objeto=NULL
 * @post Output == NULL
 */
    void test1_object_get_descripcion();  

/**
 * @test Función de prueba para object_get_descripcion
 * @pre Inputs correctos
 * @post Output == Ejemplo descripcion
 */
    void test2_object_get_descripcion();  

/**
 * @test Función de prueba para object_set_descripcion
 * @pre Objeto=NULL
 * @post Output == EERROR;
 */
    void test1_object_set_descripcion();  

/**
 * @test Función de prueba para object_set_descripcion
 * @pre given a NULL descr
 * @post Output == EERROR;
 */
    void test2_object_set_descripcion();  

/**
 * @test Función de prueba para object_set_descripcion
 * @pre Inputs correctos
 * @post Output == OK;
 */
    void test3_object_set_descripcion();

/**
 * @test Función de prueba para object_get_id_by_name
 * @pre Objeto=NULL
 * @post Output == -1
 */
    void test1_object_get_id_by_name();   

/**
 * @test Función de prueba para object_get_id_by_name
 * @pre name=NULL
 * @post Output == -1
 */
    void test2_object_get_id_by_name();   

/**
 * @test Función de prueba para object_get_id_by_name
 * @pre Inputs correctos
 * @post Output == 05
 */
    void test3_object_get_id_by_name();

/**
 * @test Función de prueba para object_print
 * @pre Objeto=NULL
 * @post Output == ERROR
 */
    void test1_object_print();

/**
 * @test Función de prueba para object_print
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_print();
 /**
 * @test Función de prueba para object_get_movement
 * @pre Inputs correctos
 * @post Output == TRUE
 */
    void test1_object_get_movement();
 /**
 * @test Función de prueba para object_get_movement
 * @pre object==NULL
 * @post Output == FALSE
 */
    void test2_object_get_movement();
/**
 * @test Función de prueba para object_set_movement
 * @pre object==NULL
 * @post Output == ERROR
 */
    void test1_object_set_movement();
/**
 * @test Función de prueba para object_set_movement
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_movement();

/**
 * @test Función de prueba para object_get_iluminate
 * @pre Inputs correctos
 * @post Output == TRUE
 */
    void test1_object_get_iluminate();
 /**
 * @test Función de prueba para object_get_iluminate
 * @pre object==NULL
 * @post Output == FALSE
 */
    void test2_object_get_iluminate();
/**
 * @test Función de prueba para object_set_iluminate
 * @pre object==NULL
 * @post Output == ERROR
 */
    void test1_object_set_iluminate();
/**
 * @test Función de prueba para object_set_iluminate
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_iluminate();

 /**
 * @test Función de prueba para object_get_turnedon
 * @pre Inputs correctos
 * @post Output == TRUE
 */
    void test1_object_get_turnedon();
 /**
 * @test Función de prueba para object_get_turnedon
 * @pre object==NULL
 * @post Output == FALSE
 */
    void test2_object_get_turnedon();
/**
 * @test Función de prueba para object_set_turnedon
 * @pre object==NULL
 * @post Output == ERROR
 */
    void test1_object_set_turnedon();
/**
 * @test Función de prueba para object_set_turnedon
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_turnedon();
/**
 * @test Función de prueba para object_set_dependency
 * @pre object==NULL
 * @post Output == ERROR
 */
    void test1_object_set_dependency();
/**
 * @test Función de prueba para object_set_dependency
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_dependency();
/**
 * @test Función de prueba para object_get_dependency
 * @pre Inputs correctos
 * @post Output == 5
 */
    void test1_object_get_dependency();
 /**
 * @test Función de prueba para object_get_dependency
 * @pre object==NULL
 * @post Output == -1
 */
    void test2_object_get_dependency();

/**
 * @test Función de prueba para object_set_link_open
 * @pre object==NULL
 * @post Output == ERROR
 */
    void test1_object_set_link_open();
/**
 * @test Función de prueba para object_set_link_open
 * @pre Inputs correctos
 * @post Output == OK
 */
    void test2_object_set_link_open();
/**
 * @test Función de prueba para object_get_link_open
 * @pre Inputs correctos
 * @post Output == 5
 */
    void test1_object_get_link_open();
 /**
 * @test Función de prueba para object_get_link_open
 * @pre object==NULL
 * @post Output == -1
 */
    void test2_object_get_link_open();


#endif