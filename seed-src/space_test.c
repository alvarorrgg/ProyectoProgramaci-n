/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Profesores Pprog, Álvaro Rodríguez
 * @version 2.0 
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "space_test.h"


#define MAX_TESTS 38

/** 
 * @brief Main function for SPACE unit tests. 
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


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_set_name();
  if (all || test == 4) test2_space_set_name();
  if (all || test == 5) test3_space_set_name();
  if (all || test == 6) test1_space_set_north();
  if (all || test == 7) test2_space_set_north();
  if (all || test == 8) test1_space_set_south();
  if (all || test == 9) test2_space_set_south();
  if (all || test == 10) test1_space_set_east();
  if (all || test == 11) test2_space_set_east();
  if (all || test == 12) test1_space_set_west();
  if (all || test == 13) test2_space_set_west();
  if (all || test == 14) test1_space_get_name();
  if (all || test == 15) test2_space_get_name();
  if (all || test == 16) test1_space_get_object();
  if (all || test == 17) test2_space_get_object();
  if (all || test == 18) test1_space_get_north();
  if (all || test == 19) test2_space_get_north();
  if (all || test == 20) test1_space_get_south();
  if (all || test == 21) test2_space_get_south();
  if (all || test == 22) test1_space_get_east();
  if (all || test == 23) test2_space_get_east();
  if (all || test == 24) test1_space_get_west();
  if (all || test == 25) test2_space_get_west();
  if (all || test == 26) test1_space_get_id();
  if (all || test == 27) test2_space_get_id();
  if (all || test == 28) test1_space_set_objects();
  if (all || test == 29) test2_space_set_objects();
  if (all || test == 30) test1_space_remove_object();
  if (all || test == 31) test2_space_remove_object();
  if (all || test == 32) test1_space_has_object_id();
  if (all || test == 33) test2_space_has_object_id();
  if (all || test == 34) test3_space_has_object_id();
  if (all || test == 35) test1_space_set_gdesc();
  if (all || test == 36) test2_space_set_gdesc();
  if (all || test == 37) test1_space_get_gdesc();
  if (all || test == 38) test2_space_get_gdesc();
  

  PRINT_PASSED_PERCENTAGE;
  return 1;
}

void test1_space_create() {
  int result = space_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

void test1_space_set_south() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

void test1_space_set_east() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

void test1_space_set_west() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

void test1_space_set_objects() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_objects(s,TRUE) == OK);
  space_destroy(s);
}

void test2_space_set_objects() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_objects(s,TRUE) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);

}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);

}

void test1_space_get_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
  space_destroy(s);
     
}

void test2_space_get_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
}

void test1_space_get_north() {
  Space *s;
  s = space_create(5);
  space_set_north(s, 4);
  PRINT_TEST_RESULT(space_get_north(s) == 4);
  space_destroy(s);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
  Space *s;
  s = space_create(5);
  space_set_south(s, 2);
  PRINT_TEST_RESULT(space_get_south(s) == 2);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
  Space *s;
  s = space_create(5);
  space_set_east(s, 1);
  PRINT_TEST_RESULT(space_get_east(s) == 1);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
  Space *s;
  s = space_create(5);
  space_set_west(s, 6);
  PRINT_TEST_RESULT(space_get_west(s) == 6);
  space_destroy(s);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}


void test1_space_remove_object() {
  Space *s;
  s = space_create(25);
  space_set_objects(s, 10);
  PRINT_TEST_RESULT(space_remove_object(s,10) == OK);
  space_destroy(s);
}

void test2_space_remove_object() {
  Space *s;
  s = space_create(25);
  space_set_objects(s, 10);
  PRINT_TEST_RESULT(space_remove_object(s,-10) == ERROR);
  space_destroy(s);
}

void test1_space_has_object_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_has_object_id(s,NO_ID) == FALSE);
}

void test2_space_has_object_id() {
  Space *s;
  s = space_create(25);
  space_set_objects(s, 10);
  PRINT_TEST_RESULT(space_has_object_id(s,10) == TRUE);
  space_destroy(s);
}

void test3_space_has_object_id() {
  Space *s;
  s = space_create(25);
  space_set_objects(s, 10);
  PRINT_TEST_RESULT(space_has_object_id(s,-10) == FALSE);
  space_destroy(s);
}

void test1_space_set_gdesc() {
  char **gdesc;
  Space *s=NULL;
  gdesc = (char **)malloc(3*sizeof(char *));
  gdesc[0] = (char *)malloc(9*sizeof(char));
  gdesc[1] = (char *)malloc(9*sizeof(char));
  gdesc[2] = (char *)malloc(9*sizeof(char));
  PRINT_TEST_RESULT(space_set_gdesc(s,gdesc) == ERROR);
  free(gdesc[0]);
  free(gdesc[1]);
  free(gdesc[2]);
  free(gdesc);
}

void test2_space_set_gdesc() {
  char **gdesc;
  Space *s;
  gdesc = (char **)malloc(3*sizeof(char *));
  gdesc[0] = (char *)malloc(9*sizeof(char));
  gdesc[1] = (char *)malloc(9*sizeof(char));
  gdesc[2] = (char *)malloc(9*sizeof(char));
  s = space_create(25);
  PRINT_TEST_RESULT(space_set_gdesc(s,gdesc) == OK);
  free(gdesc[0]);
  free(gdesc[1]);
  free(gdesc[2]);
  free(gdesc);
  space_destroy(s);
}

void test1_space_get_gdesc() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_gdesc(s) == NULL);
}

void test2_space_get_gdesc() {
  char **gdesc,**gdesc2;
  Space *s;
  gdesc2 = (char **)malloc(3*sizeof(char *));
  gdesc2[0] = (char *)malloc(9*sizeof(char));
  gdesc2[1] = (char *)malloc(9*sizeof(char));
  gdesc2[2] = (char *)malloc(9*sizeof(char));
  gdesc = (char **)malloc(3*sizeof(char *));
  gdesc[0] = (char *)malloc(9*sizeof(char));
  gdesc[1] = (char *)malloc(9*sizeof(char));
  gdesc[2] = (char *)malloc(9*sizeof(char));
  gdesc[0]="Hola";
  gdesc[1]="Hola";
  gdesc[2]="Hola";
  s = space_create(25);
  space_set_gdesc(s,gdesc);
  gdesc2=space_get_gdesc(s);
  PRINT_TEST_RESULT(strcmp(gdesc[0],gdesc2[0])==0);
  free(gdesc);
  free(gdesc2);
  space_destroy(s);
}


