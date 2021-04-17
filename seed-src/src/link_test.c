/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author Alberto Vicente
 * @version 2.0 
 * @date 13-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "link.h"
#include "link_test.h"
#include "test.h"
#include "types.h"

#define MAX_TESTS 29 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de LINK. 
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
    printf("Ejecutando todas las pruebas para el modulo Link:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();

    if (all || test == 3) test1_link_get_id();
    if (all || test == 4) test2_link_get_id();

    if (all || test == 5) test1_link_set_id();
    if (all || test == 6) test2_link_set_id();
    if (all || test == 7) test3_link_set_id();

    if (all || test == 8) test1_link_get_name();
    if (all || test == 9) test2_link_get_name();

    if (all || test == 10) test1_link_set_name();
    if (all || test == 11) test2_link_set_name();
    if (all || test == 12) test3_link_set_name();

    if (all || test == 13) test1_link_get_id_from();
    if (all || test == 14) test2_link_get_id_from();
    
    if (all || test == 15) test1_link_set_id_from();
    if (all || test == 16) test2_link_set_id_from();
    if (all || test == 17) test3_link_set_id_from();
    
    if (all || test == 18) test1_link_get_id_to();
    if (all || test == 19) test2_link_get_id_to();

    if (all || test == 20) test1_link_set_id_to();
    if (all || test == 21) test2_link_set_id_to();
    if (all || test == 22) test3_link_set_id_to();

    if (all || test == 23) test1_link_get_type();
    if (all || test == 24) test2_link_get_type();

    if (all || test == 25) test1_link_set_type();
    if (all || test == 26) test2_link_set_type();

    if (all || test == 27) test1_link_print();
    if (all || test == 28) test2_link_print();
    if (all || test == 29) test3_link_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}


void test1_link_create() {
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(l != NULL);
  link_destroy(l);
}

void test2_link_create() {
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_id(l) == 5);
  link_destroy(l);
}

void test1_link_get_id() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_get_id(l) == 5);
  link_destroy(l);
}

void test2_link_get_id() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_set_id() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id(l, 5) == OK);
  link_destroy(l);
}

void test2_link_set_id() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id(l, NO_ID) == ERROR);
  link_destroy(l);
}

void test3_link_set_id() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_set_id(l, 5) == ERROR);
}

void test1_link_get_name() {
  Link* l;
  l = link_create(5);
  link_set_name(l, "name");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "name") == 0);
  link_destroy(l);
}

void test2_link_get_name() {
  Link* l = NULL;
  link_set_name(l, "name");
  PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_set_name() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, "name") == OK);
  link_destroy(l);
}

void test2_link_set_name() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
  link_destroy(l);
}

void test3_link_set_name() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_set_name(l, "name") == ERROR);
}

void test1_link_get_id_from() {
  Link* l;
  l = link_create(5);
  link_set_id_from(l, 6);
  PRINT_TEST_RESULT(link_get_id_from(l) == 6);
  link_destroy(l);
}

void test2_link_get_id_from() {
  Link* l = NULL;
  link_set_id_from(l, 5);
  PRINT_TEST_RESULT(link_get_id_from(l) == NO_ID);
}

void test1_link_set_id_from() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id_from(l, 5) == OK);
  link_destroy(l);
}

void test2_link_set_id_from() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id_from(l, NO_ID) == ERROR);
  link_destroy(l);
}

void test3_link_set_id_from() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_set_id_from(l, 5) == ERROR);
}

void test1_link_get_id_to() {
  Link* l;
  l = link_create(5);
  link_set_id_to(l, 6);
  PRINT_TEST_RESULT(link_get_id_to(l) == 6);
  link_destroy(l);
}

void test2_link_get_id_to() {
  Link* l = NULL;
    link_set_id_to(l, 6);
  PRINT_TEST_RESULT(link_get_id_to(l) == NO_ID);
}

void test1_link_set_id_to() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id_to(l, 5) == OK);
  link_destroy(l);
}

void test2_link_set_id_to() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_id_to(l, NO_ID) == ERROR);
  link_destroy(l);
}

void test3_link_set_id_to() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_set_id_to(l, 5) == ERROR);
}

void test1_link_get_type() {
  Link* l;
  l = link_create(5);
  link_set_type(l, OPEN);
  PRINT_TEST_RESULT(link_get_type(l) == OPEN);
  link_destroy(l);
}

void test2_link_get_type() {
  Link* l = NULL;
  link_set_type(l, OPEN);
  PRINT_TEST_RESULT(link_get_type(l) == CLOSE);
}

void test1_link_set_type() {
  Link* l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_set_type(l, OPEN) == OK);
  link_destroy(l);
}

void test2_link_set_type() {
  Link* l = NULL;
  PRINT_TEST_RESULT(link_set_type(l, OPEN) == ERROR);
}

void test1_link_print() {
  Link *l=NULL;
  PRINT_TEST_RESULT(link_print(stdout,l) == ERROR);
}

 void test2_link_print() {
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_print(NULL,l) == ERROR);
  link_destroy(l);
}

 void test3_link_print() {
  Link *l;
  l = link_create(5);
  PRINT_TEST_RESULT(link_print(stdout,l) == OK);
  link_destroy(l);
}