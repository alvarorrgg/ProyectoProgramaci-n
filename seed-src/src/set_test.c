/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 16-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 35 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de SET. 
 * 
 * Se puede ejecutar con ALL o SINGLE test
 *   1.- Sin parámetros -> ALL todas las pruebas son ejecutadas 
 *   2.- Un numero simboliza un número particular de una prueba (la que se identifica con dicho número) que
 *       se ejecuta
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Ejecutando todas las pruebas para el modulo Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  
  if (all || test == 3) test1_set_id_add();
  if (all || test == 4) test2_set_id_add();
  if (all || test == 5) test3_set_id_add();
  if (all || test == 6) test4_set_id_add();
  
  if (all || test == 7) test1_set_id_delete();
  if (all || test == 8) test2_set_id_delete();
  if (all || test == 9) test3_set_id_delete();
  if (all || test == 10) test4_set_id_delete();
  
  if (all || test == 11) test1_set_set_total_ids();
  if (all || test == 12) test2_set_set_total_ids();
  if (all || test == 13) test3_set_set_total_ids();
  
  
  if (all || test == 14) test1_set_get_total_ids();
  if (all || test == 15) test2_set_get_total_ids();

  if (all || test == 16) test1_set_has_id();
  if (all || test == 17) test2_set_has_id();
  if (all || test == 18) test3_set_has_id();
  if (all || test == 19) test4_set_has_id();
   
  if (all || test == 20) test1_set_find_object_by_id();
  if (all || test == 21) test2_set_find_object_by_id();
  if (all || test == 22) test3_set_find_object_by_id();
  if (all || test == 23) test4_set_find_object_by_id();
  
  if (all || test == 24) test1_set_is_empty();
  if (all || test == 25) test2_set_is_empty();
  if (all || test == 26) test3_set_is_empty();
  
  if (all || test == 27) test1_set_is_full();
  if (all || test == 28) test2_set_is_full();
  if (all || test == 29) test3_set_is_full();
  if (all || test == 30) test4_set_is_full();
  
  if (all || test == 31) test1_set_print();
  if (all || test == 32) test2_set_print();
  if (all || test == 33) test3_set_print();
  
  if (all || test == 34) test1_set_get_ids();
  if (all || test == 35) test2_set_get_ids();

  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


 void test1_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_total_ids(s) == 0);
  set_destroy(s);
 }

 void test2_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
  set_destroy(s);
}

  void test1_set_id_add(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_id_add(s,5) == ERROR);
  	}
  void test2_set_id_add(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_id_add(s,5) == OK);
	set_destroy(s);
  	}
  void test3_set_id_add(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_id_add(s,-3) == ERROR);
	set_destroy(s);
  	}
  void test4_set_id_add(){
  	Set *s;
  	s=set_create();
  	set_set_total_ids(s,1000);
  	PRINT_TEST_RESULT(set_id_add(s,5) == ERROR);
	set_destroy(s);
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
	set_destroy(s);
  	}
  void test3_set_id_delete(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,3);
  	PRINT_TEST_RESULT(set_id_delete(s,5) == ERROR);
	set_destroy(s);
  	}
  void test4_set_id_delete(){
  	Set *s;
  	s=set_create();
  	set_set_total_ids(s,0);
  	PRINT_TEST_RESULT(set_id_delete(s,5) == ERROR);
	set_destroy(s);
  	}
  	
  	
  void test1_set_set_total_ids(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_set_total_ids(s,5) == ERROR);
  	}
  void test2_set_set_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_set_total_ids(s,-5) == ERROR);
	  set_destroy(s);
  	}
  void test3_set_set_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_set_total_ids(s,3) == OK);
	set_destroy(s);
  	}
  	
  	
  void test1_set_get_total_ids(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_get_total_ids(s) == -1);
  	}
  void test2_set_get_total_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_get_total_ids(s) != -1);
	set_destroy(s);
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
	set_destroy(s);
  	}
  void test3_set_has_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_has_id(s,3) == FALSE);
	set_destroy(s);
  	}
  void test4_set_has_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_has_id(s,-4) == FALSE);
	set_destroy(s);
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
	set_destroy(s);
  	}
  void test3_set_find_object_by_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_find_object_by_id(s,-4) == NO_ID);
	set_destroy(s);
  	}
  void test4_set_find_object_by_id(){
  	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_find_object_by_id(s,2) == NO_ID);
	set_destroy(s);
  	}
  	
  	
  void test1_set_is_empty(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
  	}
  void test2_set_is_empty(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
	set_destroy(s);
  	}
  	
  void test3_set_is_empty(){
    	Set *s;
  	s=set_create();
  	set_id_add(s,5);
  	PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
	set_destroy(s);
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
	set_destroy(s);
  	}
  	
  void test3_set_is_full(){
    	Set *s;
  	s=set_create();
  	set_set_total_ids(s,100);
  	PRINT_TEST_RESULT(set_is_full(s) == TRUE);
	set_destroy(s);
  	}
 void test4_set_is_full(){
    	Set *s;
  	s=set_create();
  	set_set_total_ids(s,50);
  	PRINT_TEST_RESULT(set_is_full(s) == FALSE);
	set_destroy(s);
  	}
 
  void test1_set_print(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_print(stdout,s) == ERROR);
  	}
  void test2_set_print(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_print(NULL,s) == ERROR);
	set_destroy(s);
  	}
  void test3_set_print(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_print(stdout,s) == OK);
	set_destroy(s);
  	}
  	
  void test1_set_get_ids(){
  	Set *s=NULL;
  	PRINT_TEST_RESULT(set_get_ids(s) == NULL);
  	}
  void test2_set_get_ids(){
  	Set *s;
  	s=set_create();
  	PRINT_TEST_RESULT(set_get_ids(s) == NULL);
	set_destroy(s);
  	}





