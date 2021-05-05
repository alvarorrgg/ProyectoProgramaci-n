/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Profesores Pprog, Álvaro Rodríguez, Gonzalo Martín, Alberto Vicente
 * @version 2.0 
 * @date 16-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "space_test.h"


#define MAX_TESTS 48 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de SPACE. 
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
    printf("Ejecutando todas las pruebas para el modulo Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
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
  if (all || test == 39) test1_space_set_description();
  if (all || test == 40) test2_space_set_description();
  if (all || test == 41) test3_space_set_description();
  if (all || test == 42) test1_space_get_description();
  if (all || test == 43) test2_space_get_description();
  if (all || test == 44) test1_space_set_ilumination();
  if (all || test == 45) test2_space_set_ilumination();
  if (all || test == 46) test3_space_set_ilumination();
  if (all || test == 47) test1_space_get_ilumination();
  if (all || test == 48) test2_space_get_ilumination();
  if (all || test == 49) test1_space_set_detailed_description();
  if (all || test == 50) test2_space_set_detailed_description();
  if (all || test == 51) test3_space_set_detailed_description();
  if (all || test == 52) test1_space_get_detailed_description();
  if (all || test == 53) test2_space_get_detailed_description();



  

  PRINT_PASSED_PERCENTAGE;
  return 1;
}

void test1_space_create() {
  Space *s ;
  s=space_create(2);
  PRINT_TEST_RESULT(s!=NULL);
  space_destroy(s);
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
  Link *l=NULL;
  l=link_create(5);
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north(s, l) == OK);
  space_destroy(s);
}

void test2_space_set_north() {
  Space *s = NULL;
  Link *l=NULL;
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_north(s, l) == ERROR);
  link_destroy(l);
}

void test1_space_set_south() {
  Space *s;
  Link *l=NULL;
  s = space_create(5);
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_south(s, l) == OK);
  space_destroy(s);
  
}

void test2_space_set_south() {
  Space *s = NULL;
  Link *l=NULL;
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_south(s, l) == ERROR);
  link_destroy(l);
}

void test1_space_set_east() {
  Space *s;
  Link *l=NULL;
  s = space_create(5);
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_east(s, l) == OK);
  space_destroy(s);
  
}

void test2_space_set_east() {
  Space *s = NULL;
  Link *l=NULL;
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_east(s, l) == ERROR);
  link_destroy(l);
}

void test1_space_set_west() {
  Space *s;
  Link *l=NULL;
  s = space_create(5);
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_west(s, l) == OK);
  space_destroy(s);
  
}

void test2_space_set_west() {
  Space *s = NULL;
  Link *l=NULL;
  l=link_create(5);
  PRINT_TEST_RESULT(space_set_west(s, l) == ERROR);
  link_destroy(l);
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
  Link *l=NULL;
  l=link_create(5);
  link_set_id_from(l,400);
  s = space_create(5);
  space_set_north(s, l);
  PRINT_TEST_RESULT(link_get_id_from(space_get_north(s)) == 400);
  space_destroy(s);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NULL);
}

void test1_space_get_south() {
  Space *s;
  Link *l=NULL;
  l=link_create(5);
  link_set_id_from(l,400);
  s = space_create(5);
  space_set_south(s, l);
  PRINT_TEST_RESULT(link_get_id_from(space_get_south(s)) == 400);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NULL);
}

void test1_space_get_east() {
  Space *s;
  Link *l=NULL;
  l=link_create(5);
  link_set_id_from(l,400);
  s = space_create(5);
  space_set_east(s, l);
  PRINT_TEST_RESULT(link_get_id_from(space_get_east(s)) == 400);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NULL);
}

void test1_space_get_west() {
  Space *s;
  Link *l=NULL;
  l=link_create(5);
  link_set_id_from(l,400);
  s = space_create(5);
  space_set_west(s, l);
  PRINT_TEST_RESULT(link_get_id_from(space_get_west(s)) == 400);
  space_destroy(s);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NULL);
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
  
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == ERROR);
  free(gdesc[0]);
  free(gdesc[1]);
  free(gdesc[2]);
  free(gdesc);
}

void test2_space_set_gdesc() {
  char **gdesc=NULL;
  Space *s=space_create(25);
  gdesc = (char **)malloc(3*sizeof(char *));
  gdesc[0] = (char *)malloc(9*sizeof(char));
  gdesc[1] = (char *)malloc(9*sizeof(char));
  gdesc[2] = (char *)malloc(9*sizeof(char));
  strcpy(gdesc[0], "ej1");
  strcpy(gdesc[1], "ej2");
  strcpy(gdesc[2], "ej3");

  
  PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == OK);
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
  strcpy(gdesc[0], "Hola");
  strcpy(gdesc[1], "Adios");
  strcpy(gdesc[2], "Hola");

  s = space_create(25);
  space_set_gdesc(s,gdesc);
  strcpy(gdesc2[0], space_get_gdesc(s)[0]);
  strcpy(gdesc2[1], space_get_gdesc(s)[1]);
  strcpy(gdesc2[2], space_get_gdesc(s)[2]);
  PRINT_TEST_RESULT(strcmp(gdesc[0],gdesc2[0])==0);
  free(gdesc[0]);
  free(gdesc[1]);
  free(gdesc[2]);
  free(gdesc);
  free(gdesc2[0]);
  free(gdesc2[1]);
  free(gdesc2[2]);
  free(gdesc2);
  
  space_destroy(s);
  
}

void test1_space_set_description(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_set_description (space , "Ejemplo descripcion") == ERROR);

}


void test2_space_set_description(){
  Space *space = space_create(05);

  char *descr = NULL;

  PRINT_TEST_RESULT(space_set_description (space , descr) == ERROR);
  space_destroy (space);
}


void test3_space_set_description(){
  Space *space = space_create(05);

  PRINT_TEST_RESULT(space_set_description (space , "Ejemplo descripcion") == OK);
  space_destroy (space);
}

void test1_space_get_description(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_get_description (space) == NULL);
}


void test2_space_get_description(){
  Space *space = space_create (05);
  space_set_description (space , "Ejemplo de descripcion");

  PRINT_TEST_RESULT(strcmp ( space_get_description (space) ,"Ejemplo de descripcion")  == 0);
  space_destroy (space);
}

void test1_space_set_ilumination(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_set_ilumination (space , 1) == ERROR);

}


void test2_space_set_ilumination(){
  Space *space = space_create(05);

  BOOL bool = -1;

  PRINT_TEST_RESULT(space_set_ilumination (space , bool) == ERROR);
  space_destroy (space);
}


void test3_space_set_ilumination(){
  Space *space = space_create(05);

  PRINT_TEST_RESULT(space_set_ilumination (space , 1) == OK);
  space_destroy (space);
}

void test1_space_get_ilumination(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_get_ilumination (space) == FALSE);
}


void test2_space_get_ilumination(){
  Space *space = space_create (05);
  space_set_ilumination (space , 1);

  PRINT_TEST_RESULT(space_get_ilumination (space)== 1);
  space_destroy (space);
}

void test1_space_set_detailed_description(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_set_detailed_description (space , "Ejemplo descripcion") == ERROR);

}


void test2_space_set_detailed_description(){
  Space *space = space_create(05);

  char *descr = NULL;

  PRINT_TEST_RESULT(space_set_detailed_description (space , descr) == ERROR);
  space_destroy (space);
}


void test3_space_set_detailed_description(){
  Space *space = space_create(05);

  PRINT_TEST_RESULT(space_set_detailed_description (space , "Ejemplo descripcion detallada") == OK);
  space_destroy (space);
}

void test1_space_get_detailed_description(){
  Space *space = NULL;

  PRINT_TEST_RESULT(space_get_detailed_description (space) == NULL);
}


void test2_space_get_detailed_description(){
  Space *space = space_create (05);
  space_set_detailed_description (space , "Ejemplo de descripcion");

  PRINT_TEST_RESULT(strcmp ( space_get_detailed_description (space) ,"Ejemplo de descripcion")  == 0);
  space_destroy (space);
}

