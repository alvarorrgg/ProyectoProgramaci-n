/** 
 * @brief It tests object module
 * 
 * @file object_test.c
 * @author Gonzalo Martin
 * @version 2.0 
 * @date 13-04-2021
 * @updated 13-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 23 /*Numero maximo de tests*/

/** 
 * @brief Main function for SET unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
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