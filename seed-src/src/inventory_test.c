/** 
 * @brief It tests inventory module
 * 
 * @file inventory_test.c
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"

#define MAX_TESTS 36 /*!<Numero maximo de tests*/

/** 
 * @brief Main function for INVENTOTY unit tests. 
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
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  
  if (all || test == 3) test1_inventory_destroy();

  if (all || test == 4) test1_inventory_set_object();
  if (all || test == 5) test2_inventory_set_object();
  if (all || test == 6) test3_inventory_set_object();  
  if (all || test == 7) test4_inventory_set_object();
  if (all || test == 8) test5_inventory_set_object();

  if (all || test == 9) test1_inventory_get_inventory();
  if (all || test == 10) test2_inventory_get_inventory();
  
  if (all || test == 11) test1_inventory_print();
  if (all || test == 12) test2_inventory_print();
  if (all || test == 13) test3_inventory_print();
  
  
  if (all || test == 14) test1_inventory_delete_object();
  if (all || test == 15) test2_inventory_delete_object();
  if (all || test == 16) test3_inventory_delete_object();
  if (all || test == 17) test4_inventory_delete_object();
  if (all || test == 18) test5_inventory_delete_object();

  if (all || test == 19) test1_inventory_is_empty();   
  if (all || test == 20) test2_inventory_is_empty();
  if (all || test == 21) test3_inventory_is_empty();

  if (all || test == 22) test1_inventory_is_full();   
  if (all || test == 23) test2_inventory_is_full();
  if (all || test == 24) test3_inventory_is_full();

  if (all || test == 25) test1_inventory_search_object();
  if (all || test == 26) test2_inventory_search_object();
  if (all || test == 27) test3_inventory_search_object();
  if (all || test == 28) test4_inventory_search_object();
  if (all || test == 29) test5_inventory_search_object();

  if (all || test == 30) test1_inventory_set_max_objects();
  if (all || test == 31) test2_inventory_set_max_objects();
  if (all || test == 32) test3_inventory_set_max_objects();

  if (all || test == 33) test1_inventory_get_max_objects();
  if (all || test == 34) test2_inventory_get_max_objects();

  if (all || test == 35) test1_inventory_get_number_of_objects();
  if (all || test == 36) test2_inventory_get_number_of_objects();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_inventory_create(){
    Inventory *new_invetory  = inventory_create();

    PRINT_TEST_RESULT( new_invetory != NULL);
    inventory_destroy (new_invetory);
}

void test2_inventory_create(){
    Inventory *new_invetory  = inventory_create();

    PRINT_TEST_RESULT( inventory_is_empty (new_invetory) == TRUE );
    inventory_destroy (new_invetory);
}

void test1_inventory_destroy(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_destroy (inventory) == ERROR );
}

void test1_inventory_set_object(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_set_object (inventory , 5) == ERROR );
}

void test2_inventory_set_object(){
    Inventory *inventory = inventory_create();
    inventory_set_object (inventory , 5);
    PRINT_TEST_RESULT( inventory_set_object (inventory , 5) == ERROR );
    inventory_destroy (inventory);
}

void test3_inventory_set_object(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_set_object (inventory , -5) == ERROR );
    inventory_destroy (inventory);
}

void test4_inventory_set_object(){
    Inventory *inventory = inventory_create();
    Id id = NO_ID;
    PRINT_TEST_RESULT( inventory_set_object (inventory , id) == ERROR );
    inventory_destroy (inventory);
}

void test5_inventory_set_object(){
    Inventory *inventory = inventory_create();

    inventory_set_object (inventory , 01);
    inventory_set_object (inventory , 02);
    inventory_set_object (inventory , 03);
    inventory_set_object (inventory , 04);
    inventory_set_object (inventory , 05);
    inventory_set_object (inventory , 06);
    inventory_set_object (inventory , 07);
    inventory_set_object (inventory , 16);
    inventory_set_object (inventory , 17);
    inventory_set_object (inventory , 10);
    inventory_set_object (inventory , 11);
    inventory_set_object (inventory , 12);
    inventory_set_object (inventory , 13);
    inventory_set_object (inventory , 14);
    inventory_set_object (inventory , 15);
        
    PRINT_TEST_RESULT( inventory_set_object (inventory , 18) == ERROR);
    
    inventory_destroy (inventory);
}
void test1_inventory_get_number_of_objects(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_get_number_of_objects (inventory) == -1 );
}

void test2_inventory_get_number_of_objects(){
    Inventory *inventory = inventory_create();
    inventory_set_object (inventory , 15);
    PRINT_TEST_RESULT( inventory_get_number_of_objects (inventory) == 1 );
    inventory_destroy (inventory);
}
void test1_inventory_get_inventory(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_get_inventory (inventory) == NULL );
}

void test2_inventory_get_inventory(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_get_inventory (inventory) == NULL );
    inventory_destroy(inventory);
}

void test1_inventory_print(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_print (inventory , stdout) == ERROR );
}

void test2_inventory_print(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_print (inventory , NULL) == ERROR );
    inventory_destroy(inventory);
}

void test3_inventory_print(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_print (inventory , stdout) == OK );
    inventory_destroy(inventory);
}


void test1_inventory_delete_object(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_delete_object (inventory , 5) == ERROR);  
}

void test2_inventory_delete_object(){
    Inventory *inventory = inventory_create();
    Id id=-1;
    PRINT_TEST_RESULT( inventory_delete_object (inventory , id) == ERROR);  
    inventory_destroy (inventory);
}

void test3_inventory_delete_object(){
    Inventory *inventory = inventory_create();
    inventory_set_object (inventory , 5);
    PRINT_TEST_RESULT( inventory_delete_object (inventory , -6) == ERROR);  
    inventory_destroy(inventory);
}

void test4_inventory_delete_object(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_delete_object (inventory , 5) == ERROR);  
    inventory_destroy(inventory);
}

void test5_inventory_delete_object(){
    Inventory *inventory = inventory_create();
    inventory_set_object (inventory , 5);
    PRINT_TEST_RESULT( inventory_delete_object (inventory , 6) == ERROR);  
    inventory_destroy(inventory);
}

void test1_inventory_is_empty(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_is_empty(inventory) == FALSE);
}

void test2_inventory_is_empty(){
    Inventory *inventory = inventory_create();
    inventory_set_object (inventory , 5);
    PRINT_TEST_RESULT( inventory_is_empty(inventory) == FALSE);
    inventory_destroy(inventory);
}

void test3_inventory_is_empty(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_is_empty(inventory) == TRUE);
    inventory_destroy(inventory);
}


void test1_inventory_is_full(){
    Inventory *inventory = NULL;

    PRINT_TEST_RESULT( inventory_is_full(inventory) == FALSE);
}

void test2_inventory_is_full(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_is_full (inventory) == FALSE);
    inventory_destroy(inventory);
}

void test3_inventory_is_full(){
    Inventory *inventory = inventory_create();

    inventory_set_max_objects (inventory , 5);

    inventory_set_object (inventory , 01);
    inventory_set_object (inventory , 02);
    inventory_set_object (inventory , 03);
    inventory_set_object (inventory , 04);
    inventory_set_object (inventory , 05);
    

    PRINT_TEST_RESULT( inventory_is_full (inventory) == TRUE);
    inventory_destroy(inventory);
}

void test1_inventory_search_object(){
    Inventory *inventory = NULL;

    PRINT_TEST_RESULT( inventory_search_object (inventory , 5) == FALSE);
}

void test2_inventory_search_object(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_search_object (inventory , NO_ID) == FALSE);
    inventory_destroy(inventory);
}

void test3_inventory_search_object(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_search_object (inventory , -5) == FALSE);
    inventory_destroy(inventory);
}

void test4_inventory_search_object(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_search_object (inventory , 5) == FALSE);
    inventory_destroy(inventory);
}

void test5_inventory_search_object(){
    Inventory *inventory = inventory_create();

    inventory_search_object (inventory , 5);

    PRINT_TEST_RESULT( inventory_search_object (inventory , 5) == FALSE);
    inventory_destroy(inventory);
}

void test1_inventory_set_max_objects(){
    Inventory *inventory = NULL;

    PRINT_TEST_RESULT( inventory_set_max_objects (inventory , 5) == ERROR);
}

void test2_inventory_set_max_objects(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_set_max_objects (inventory , -5) == ERROR);
    inventory_destroy(inventory);
}

void test3_inventory_set_max_objects(){
    Inventory *inventory = inventory_create();
    inventory_set_max_objects (inventory , 5);

    PRINT_TEST_RESULT( inventory_get_max_objects (inventory) == 5);
    inventory_destroy(inventory);
}

void test1_inventory_get_max_objects(){
    Inventory *inventory = NULL ;

    PRINT_TEST_RESULT( inventory_get_max_objects (inventory) == -1);
 
}

void test2_inventory_get_max_objects(){
    Inventory *inventory = inventory_create();

    PRINT_TEST_RESULT( inventory_get_max_objects (inventory) == 15);
    inventory_destroy (inventory);
 
}




