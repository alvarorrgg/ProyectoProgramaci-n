/** 
 * @brief It tests inventory module
 * 
 * @file inventory_test.c
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 31-03-2021
 * @updated 31-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"

#define MAX_TESTS 35 /*Numero maximo de tests*/

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


  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  
  if (all || test == 3) test1_inventory_destroy();

  if (all || test == 4) test1_inventory_setObject();
  if (all || test == 5) test2_inventory_setObject();
  if (all || test == 6) test3_inventory_setObject();  
  if (all || test == 7) test4_inventory_setObject();
  if (all || test == 8) test5_inventory_setObject();

  if (all || test == 9) test1_inventory_getInventory();
  if (all || test == 10) test2_inventory_getInventory();
  
  if (all || test == 11) test1_inventory_print();
  if (all || test == 12) test2_inventory_print();
  if (all || test == 13) test3_inventory_print();
  
  
  if (all || test == 14) test1_inventory_deleteObject();
  if (all || test == 15) test2_inventory_deleteObject();
  if (all || test == 16) test3_inventory_deleteObject();
  if (all || test == 17) test4_inventory_deleteObject();
  if (all || test == 18) test5_inventory_deleteObject();

  if (all || test == 19) test1_inventory_isEmpty();   
  if (all || test == 20) test2_inventory_isEmpty();
  if (all || test == 21) test3_inventory_isEmpty();
  
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

    PRINT_TEST_RESULT( inventory_isEmpty (new_invetory) == TRUE );
    inventory_destroy (new_invetory);
}

void test1_inventory_destroy(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_destroy (inventory) == ERROR );
}

void test1_inventory_setObject(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_setObject (inventory , 5) == ERROR );
}

void test2_inventory_setObject(){
    Inventory *inventory = inventory_create();
    inventory_setObject (inventory , 5);
    PRINT_TEST_RESULT( inventory_setObject (inventory , 5) == ERROR );
    inventory_destroy (inventory);
}

void test3_inventory_setObject(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_setObject (inventory , -5) == ERROR );
    inventory_destroy (inventory);
}

void test4_inventory_setObject(){
    Inventory *inventory = inventory_create();
    Id id = NO_ID;
    PRINT_TEST_RESULT( inventory_setObject (inventory , id) == ERROR );
    inventory_destroy (inventory);
}

void test5_inventory_setObject(){
    Inventory *inventory = inventory_create();

    inventory_setObject (inventory , 01);
    inventory_setObject (inventory , 02);
    inventory_setObject (inventory , 03);
    inventory_setObject (inventory , 04);
    inventory_setObject (inventory , 05);
    inventory_setObject (inventory , 06);
    inventory_setObject (inventory , 07);
    inventory_setObject (inventory , 16);
    inventory_setObject (inventory , 17);
    inventory_setObject (inventory , 10);
    inventory_setObject (inventory , 11);
    inventory_setObject (inventory , 12);
    inventory_setObject (inventory , 13);
    inventory_setObject (inventory , 14);
    inventory_setObject (inventory , 15);
        
    PRINT_TEST_RESULT( inventory_setObject (inventory , 18) == ERROR );
    
    inventory_destroy (inventory);
}

void test1_inventory_getInventory(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_getInventory (inventory) == NULL );
}

void test2_inventory_getInventory(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_getInventory (inventory) == NULL );
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


void test1_inventory_deleteObject(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_deleteObject (inventory , 5) == ERROR);  
}

void test2_inventory_deleteObject(){
    Inventory *inventory = inventory_create();
    Id id=-1;
    PRINT_TEST_RESULT( inventory_deleteObject (inventory , id) == ERROR);  
    inventory_destroy (inventory);
}

void test3_inventory_deleteObject(){
    Inventory *inventory = inventory_create();
    inventory_setObject (inventory , 5);
    PRINT_TEST_RESULT( inventory_deleteObject (inventory , -6) == ERROR);  
    inventory_destroy(inventory);
}

void test4_inventory_deleteObject(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_deleteObject (inventory , 5) == ERROR);  
    inventory_destroy(inventory);
}

void test5_inventory_deleteObject(){
    Inventory *inventory = inventory_create();
    inventory_setObject (inventory , 5);
    PRINT_TEST_RESULT( inventory_deleteObject (inventory , 6) == ERROR);  
    inventory_destroy(inventory);
}

void test1_inventory_isEmpty(){
    Inventory *inventory = NULL;
    PRINT_TEST_RESULT( inventory_isEmpty(inventory) == FALSE);
}

void test2_inventory_isEmpty(){
    Inventory *inventory = inventory_create();
    inventory_setObject (inventory , 5);
    PRINT_TEST_RESULT( inventory_isEmpty(inventory) == FALSE);
    inventory_destroy(inventory);
}

void test3_inventory_isEmpty(){
    Inventory *inventory = inventory_create();
    PRINT_TEST_RESULT( inventory_isEmpty(inventory) == TRUE);
    inventory_destroy(inventory);
}

