/** 
 * @brief It tests die module
 * 
 * @file die_test.c
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 10-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "die.h"
#include "die_test.h"
#include "test.h"


#define MAX_TESTS 14 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de DIE. 
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

  if (argc < 2)  printf("Ejecutando todas las pruebas para el modulo Die:\n");
 else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_die_create();
  if (all || test == 2) test2_die_create();
  
  if (all || test == 3) test1_die_roll();
  if (all || test == 4) test2_die_roll();
  
  if (all || test == 5) test1_die_set_Id();
  if (all || test == 6) test2_die_set_Id();
  if (all || test == 7) test3_die_set_Id();
  
  if (all || test == 8) test1_die_get_last_roll();
  if (all || test == 9) test2_die_get_last_roll();
  
  if (all || test == 10) test1_die_get_id();
  if (all || test == 11) test2_die_get_id();
  
  if (all || test == 12) test1_die_print();
  if (all || test == 13) test2_die_print();  
  if (all || test == 14) test3_die_print();

  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}
 void test1_die_create() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_get_last_roll(d) == NO_ID);
  die_destroy(d);
 }
 void test2_die_create() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_get_id(d) == 5);
  die_destroy(d);
}


 void test1_die_roll() {
  Die *d=NULL;
  PRINT_TEST_RESULT(die_roll(d) == -1);
}
 void test2_die_roll() {
  Die *d;
  d = die_create(5);
  die_roll(d);
  PRINT_TEST_RESULT(die_get_last_roll(d)>0 && die_get_last_roll(d)<7);
  die_destroy(d);
}


 void test1_die_set_Id() {
  Die *d=NULL;
  PRINT_TEST_RESULT(die_set_Id(d,5) == ERROR);
}
 void test2_die_set_Id() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_set_Id(d,5) == OK);
  die_destroy(d);
}
 void test3_die_set_Id() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_set_Id(d,-5) == ERROR);
  die_destroy(d);
}


 void test1_die_get_last_roll() {
  Die *d=NULL;
  PRINT_TEST_RESULT(die_get_last_roll(d) == -1);
}
 void test2_die_get_last_roll() {
  Die *d;
  d = die_create(5);
  die_roll(d);
  PRINT_TEST_RESULT(die_get_last_roll(d)>0 && die_get_last_roll(d)<7);
  die_destroy(d);
}


 void test1_die_get_id() {
  Die *d=NULL;
  PRINT_TEST_RESULT(die_get_id(d) == NO_ID);
}
 void test2_die_get_id() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_get_id(d) == 5);
  die_destroy(d);
}


 void test1_die_print() {
  Die *d=NULL;
  PRINT_TEST_RESULT(die_print(stdout,d) == ERROR);
}
 void test2_die_print() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_print(NULL,d) == ERROR);
  die_destroy(d);
}
 void test3_die_print() {
  Die *d;
  d = die_create(5);
  PRINT_TEST_RESULT(die_print(stdout,d) == OK);
  die_destroy(d);
}
