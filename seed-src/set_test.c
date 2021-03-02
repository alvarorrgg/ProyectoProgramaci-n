/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author R1
 * @version 2.0 
 * @date 16-01-2015
 * @updated 18-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 32

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
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_set_create();
  
  if (all || test == 2) test1_set_id_add();
  if (all || test == 3) test2_set_id_add();
  if (all || test == 4) test3_set_id_add();
  if (all || test == 5) test4_set_id_add();
  
  if (all || test == 6) test1_set_id_delete();
  if (all || test == 7) test2_set_id_delete();
  if (all || test == 8) test3_set_id_delete();
  if (all || test == 9) test4_set_id_delete();
  
  if (all || test == 10) test1_set_set_total_ids();
  if (all || test == 11) test2_set_set_total_ids();
  if (all || test == 12) test3_set_set_total_ids();
  
  
  if (all || test == 13) test1_set_get_total_ids();
  if (all || test == 14) test2_set_get_total_ids();

  if (all || test == 15) test1_set_has_id();
  if (all || test == 16) test2_set_has_id();
  if (all || test == 17) test3_set_has_id();
  if (all || test == 18) test4_set_has_id();
   
  if (all || test == 19) test1_set_find_object_by_id();
  if (all || test == 20) test2_set_find_object_by_id();
  if (all || test == 21) test3_set_find_object_by_id();
  if (all || test == 22) test4_set_find_object_by_id();
  
  if (all || test == 23) test1set_is_empty();
  if (all || test == 24) test2_set_is_empty();
  if (all || test == 25) test3_set_is_empty();
  
  if (all || test == 26) test1_set_is_full();
  if (all || test == 27) test2_set_is_full();
  if (all || test == 28) test3_set_is_full();
  if (all || test == 29) test4_set_is_full();
  
  if (all || test == 30) test1_set_print();
  if (all || test == 31) test2_set_print();
  if (all || test == 32) test3_set_print();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}


 void test1_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_total_ids(s) == 0);
}

  void test1_set_id_add(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_id_add(s,5) == ERROR);
  	}
  void test2_set_id_add(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_id_add(s,5) == OK);
  	}
  void test3_set_id_add(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_id_add(s,-3) == ERROR);
  	}
  void test4_set_id_add(){
  	Set *s;
  	s=set_create();
  	set_set_total_ids(s,1000);
  	PRINT_TEST_RESULT(set_id_add(s,5) == ERROR);
  	}
  	
  	
  void test1_set_id_delete(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_id_delete(s,5) == ERROR);
  	}
  void test2_set_id_delete(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_id_delete(s,5) == OK);
  	}
  void test3_set_id_delete(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_id_delete(s,5) == ERROR);
  	}
  void test4_set_id_delete(){
  	Set *s;
  	s=set_create();
  	set_set_total_ids(s,0);
  	PRINT_TEST_RESULT(set_id_delete(s,5) == ERROR);
  	}
  	
  	
  void test1_set_set_total_ids(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_set_total_ids(s,5) == ERROR);
  	}
  void test2_set_set_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_set_total_ids(s,-5) == ERROR);
  	}
  void test3_set_set_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_set_total_ids(s,3) == OK);
  	}
  	
  	
  void test1_set_get_total_ids(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_get_total_ids(s) == -1);
  	}
  void test2_set_get_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_get_total_ids(s) != -1);
  	}
  	
  	
  void test1_set_has_id(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_has_id(s,5) == FALSE);
  	}
  void test2_set_has_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_has_id(s,5) == TRUE);
  	}
  void test3_set_has_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_has_id(s,3) == FALSE);
  	}
  void test4_set_has_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_has_id(s,-4) == FALSE);
  	}
  	
  	
  void test1_set_find_object_by_id(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_find_object_by_id(s,5) == NO_ID);
  	}
  void test2_set_find_object_by_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_find_object_by_id(s,5) != NO_ID);
  	}
  void test3_set_find_object_by_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_find_object_by_id(s,-4) == NO_ID);
  	}
  void test4_set_find_object_by_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_find_object_by_id(s,2) == NO_ID);
  	}
  	
  	
  void test1set_is_empty(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
  	}
  void test2_set_is_empty(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
  	}
  	
  void test3_set_is_empty(){
    	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
  	}
  
  
   void test1_set_is_full(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_is_full(s) == FALSE);
  	}
  void test2_set_is_full(){
  	Set *s;
  	s=set_create();
  	set_set_total_ids(s,1000);
  	PRINT_TEST_RESULT(set_is_full(s) == TRUE);
  	}
  	
  void test3_set_is_full(){
    	Set *s;
  	s=set_create();
  	set_set_total_ids(s,100);
  	PRINT_TEST_RESULT(set_is_full(s) == TRUE);
  	}
 void test4_set_is_full(){
    	Set *s;
  	s=set_create();
  	set_set_total_ids(s,50);
  	PRINT_TEST_RESULT(set_is_full(s) == FALSE);
  	}
 
  void test1_set_print(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_print(stdout,s) == ERROR);
  	}
  void test2_set_print(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_print(NULL,s) == ERROR);
  	}
  void test3_set_print(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_print(stdout,s) == OK);
  	}





