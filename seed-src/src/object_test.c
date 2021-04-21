/** 
 * @brief It tests object module
 * 
 * @file object_test.c
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 13-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 23 /*!<Numero maximo de tests*/


int/** 
 * @brief Función main para la unidad de pruebas de OBJECT. 
 * 
 * Se puede ejecutar con ALL o SINGLE test
 *   1.- Sin parámetros -> ALL todas las pruebas son ejecutadas 
 *   2.- Un numero simboliza un número particular de una prueba (la que se identifica con dicho número) que
 *       se ejecuta
 *  
 */ main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Ejecutando todas las pruebas para el modulo Object:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  
  if (all || test == 3) test1_object_destroy();
  if (all || test == 4) test2_object_destroy();
  
  if (all || test == 5) test1_object_get_id();
  if (all || test == 6) test2_object_get_id();

  if (all || test == 7) test1_object_set_name();
  if (all || test == 8) test2_object_set_name();  
  if (all || test == 9) test3_object_set_name();

  if (all || test == 10) test1_object_set_id();
  if (all || test == 111) test2_object_set_id();
  
  
  if (all || test == 12) test1_object_get_name();
  if (all || test == 13) test2_object_get_name();

  if (all || test == 14) test1_object_get_descripcion();
  if (all || test == 15) test2_object_get_descripcion();

  if (all || test == 16) test1_object_set_descripcion();
  if (all || test == 17) test2_object_set_descripcion();   
  if (all || test == 18) test3_object_set_descripcion();

  if (all || test == 19) test1_object_get_id_by_name();
  if (all || test == 20) test2_object_get_id_by_name();
  if (all || test == 21) test3_object_get_id_by_name();

  if (all || test == 22) test1_object_print();
  if (all || test == 23) test2_object_print();

  if (all || test == 24) test1_object_get_movement();
  if (all || test == 25) test2_object_get_movement();
  if (all || test == 26) test1_object_set_movement();
  if (all || test == 27) test2_object_set_movement();

  if (all || test == 28) test1_object_get_iluminate();
  if (all || test == 29) test2_object_get_iluminate();
  if (all || test == 30) test1_object_set_iluminate();
  if (all || test == 31) test2_object_set_iluminate();

  if (all || test == 32) test1_object_get_turnedon();
  if (all || test == 33) test2_object_get_turnedon();
  if (all || test == 34) test1_object_set_turnedon();
  if (all || test == 35) test2_object_set_turnedon();

  if (all || test == 36) test1_object_get_dependency();
  if (all || test == 37) test2_object_get_dependency();
  if (all || test == 38) test1_object_set_dependency();
  if (all || test == 39) test2_object_set_dependency();

  if (all || test == 40) test1_object_get_link_open();
  if (all || test == 41) test2_object_get_link_open();
  if (all || test == 42) test1_object_set_link_open();
  if (all || test == 43) test2_object_set_link_open();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_object_create(){
    Object *object = NULL;
    Id id = 05;

    object = object_create (id);

    PRINT_TEST_RESULT(object != NULL);
    object_destroy(object);
} 

void test2_object_create(){
    Object *object = NULL;
    Id id = 05;

    object = object_create (id);
    object_set_id (object, id);

    PRINT_TEST_RESULT(object_get_id (object) == id);
    object_destroy(object);
} 


void test1_object_destroy(){
    Object *object = NULL;

    PRINT_TEST_RESULT(object_destroy (object) == ERROR);
}


void test2_object_destroy(){
    Object *object = object_create (05);

    PRINT_TEST_RESULT(object_destroy (object) == OK);
}


void test1_object_get_id(){
    Object *object = NULL;

    PRINT_TEST_RESULT(object_get_id (object) == NO_ID);
}


void test2_object_get_id(){
    Object *object = object_create(05);

    PRINT_TEST_RESULT(object_get_id(object) == 05);
    object_destroy(object);
}    


void test1_object_set_name(){
    Object *object = NULL;

    PRINT_TEST_RESULT(object_set_name (object , "Ejemplo") == ERROR);
}


void test2_object_set_name(){
    Object *object = object_create (05);

    char *name = NULL;

    PRINT_TEST_RESULT(object_set_name (object , name) == ERROR);
    object_destroy (object);
}   


void test3_object_set_name(){
    Object *object = object_create (05);

    PRINT_TEST_RESULT(object_set_name (object , "Ejemplo") == OK);
    object_destroy (object);
}  


void test1_object_set_id(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_id (object , 05) == ERROR);
} 


void test2_object_set_id(){
    Object *object = object_create (05);

    PRINT_TEST_RESULT(object_set_id (object , 05) == OK);
    object_destroy (object);
}  


void test1_object_get_name(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_name (object) == NULL);
}


void test2_object_get_name(){
    Object *object = object_create (05);

    object_set_name (object , "Nombre");

    PRINT_TEST_RESULT(strcmp(object_get_name (object) , "Nombre") == 0);
    object_destroy (object);
} 


void test1_object_get_descripcion(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_description (object) == NULL);
}


void test2_object_get_descripcion(){
    Object *object = object_create (05);
    object_set_description (object , "Ejemplo de descripcion");
    
    PRINT_TEST_RESULT(strcmp (object_get_description (object) , "Ejemplo de descripcion") == 0);
    object_destroy (object);
}

void test1_object_set_descripcion(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_description (object , "Ejemplo descripcion") == ERROR);
}


void test2_object_set_descripcion(){
    Object *object = object_create(05);
    char *descr = NULL;

    PRINT_TEST_RESULT(object_set_description (object , descr) == ERROR);
    object_destroy(object);
}


void test3_object_set_descripcion(){
    Object *object = object_create(05);

    PRINT_TEST_RESULT(object_set_description (object , "Ejemplo descripcion") == OK);
    object_destroy(object);
}


void test1_object_get_id_by_name(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_id_by_name (object , "Nombre") == -1);
}


void test2_object_get_id_by_name(){
    Object *object = object_create (05);
    char* name = NULL;
    
    PRINT_TEST_RESULT(object_get_id_by_name (object , name) == -1);
    object_destroy(object);
}  


void test3_object_get_id_by_name(){
    Object *object = object_create (05);

    object_set_name (object , "Nombre");
    
    PRINT_TEST_RESULT(object_get_id_by_name (object , "Nombre") == 05);
    object_destroy(object);
}


void test1_object_print(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_print(object) == ERROR);
}


void test2_object_print(){
    Object *object = object_create(05);
    object_set_name (object , "Nombre");

    PRINT_TEST_RESULT(object_print(object) == OK);
    object_destroy(object);
}


void test1_object_get_movement(){
    Object *object = object_create (05);
    object_set_movement(object,TRUE) ;
    
    PRINT_TEST_RESULT(object_get_movement(object)==TRUE);
    object_destroy (object);
}
void test2_object_get_movement(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_movement(object)==FALSE);
    object_destroy (object);
}

void test1_object_set_movement(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_movement(object,TRUE)==ERROR);
}

void test2_object_set_movement(){
   Object *object = object_create (05);
    
    PRINT_TEST_RESULT(object_set_movement(object,TRUE)==OK);
    object_destroy (object);
}

void test1_object_get_iluminate(){
    Object *object = object_create (05);
    object_set_iluminate(object,TRUE) ;
    
    PRINT_TEST_RESULT(object_get_iluminate(object)==TRUE);
    object_destroy (object);
}

void test2_object_get_iluminate(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_iluminate(object)==FALSE);
    object_destroy (object);
}

void test1_object_set_iluminate(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_iluminate(object,TRUE)==ERROR);
}

void test2_object_set_iluminate(){
   Object *object = object_create (05);
    
    PRINT_TEST_RESULT(object_set_iluminate(object,TRUE)==OK);
    object_destroy (object);
}



void test1_object_get_turnedon(){
    Object *object = object_create (05);
    object_set_turnedon(object,TRUE) ;
    
    PRINT_TEST_RESULT(object_get_turnedon(object)==TRUE);
    object_destroy (object);
}

void test2_object_get_turnedon(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_turnedon(object)==FALSE);
    object_destroy (object);
}

void test1_object_set_turnedon(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_turnedon(object,TRUE)==ERROR);
}

void test2_object_set_turnedon(){
   Object *object = object_create (05);
    
    PRINT_TEST_RESULT(object_set_turnedon(object,TRUE)==OK);
    object_destroy (object);
}



void test1_object_set_dependency(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_dependency (object , 05) == ERROR);
} 
void test2_object_set_dependency(){
    Object *object = object_create (05);

    PRINT_TEST_RESULT(object_set_dependency (object , 5) == OK);
    object_destroy (object);
}  

void test1_object_get_dependency(){
    Object *object = object_create (05);
    object_set_dependency(object,5) ;
    
    PRINT_TEST_RESULT(object_get_dependency(object)==5);
    object_destroy (object);
}

void test2_object_get_dependency(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_dependency(object)==-1);
    object_destroy (object);
}



void test1_object_set_link_open(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_set_link_open (object , 05) == ERROR);
} 

void test2_object_set_link_open(){
    Object *object = object_create (05);

    PRINT_TEST_RESULT(object_set_link_open (object , 5) == OK);
    object_destroy (object);
}  

void test1_object_get_link_open(){
    Object *object = object_create (05);
    object_set_link_open(object,5) ;
    
    PRINT_TEST_RESULT(object_get_link_open(object)==5);
    object_destroy (object);
}

void test2_object_get_link_open(){
    Object *object = NULL;
    
    PRINT_TEST_RESULT(object_get_link_open(object)==-1);
    object_destroy (object);
}