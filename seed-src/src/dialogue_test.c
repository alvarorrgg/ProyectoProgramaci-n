/** 
 * @brief It tests dialogue module
 * 
 * @file dialogue_test.c
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 09-05-21
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "dialogue_test.h"

#define MAX_TESTS 24 /*!<Numero maximo de tests*/


int/** 
 * @brief Función main para la unidad de pruebas de DIALOGUE. 
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
    printf("Ejecutando todas las pruebas para el modulo Dialogue:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_dialogue_create();
  if (all || test == 2) test2_dialogue_create();
  
  if (all || test == 3) test1_dialogue_destroy();
  if (all || test == 4) test2_dialogue_destroy();
  
  if (all || test == 5) test1_dialogue_set_num_tries();
  if (all || test == 6) test2_dialogue_set_num_tries();
  if (all || test == 7) test3_dialogue_set_num_tries();

  if (all || test == 8) test1_dialogue_get_num_tries();
  if (all || test == 9) test2_dialogue_get_num_tries();

  if (all || test == 10) test1_dialogue_set_num_dialogues();
  if (all || test == 11) test2_dialogue_set_num_dialogues();  
  if (all || test == 12) test3_dialogue_set_num_dialogues();

  if (all || test == 13) test1_dialogue_get_num_dialogues();
  if (all || test == 14) test2_dialogue_get_num_dialogues();

  if (all || test == 15) test1_dialogue_set_choose_dialogue();
  if (all || test == 16) test2_dialogue_set_choose_dialogue();
  if (all || test == 17) test3_dialogue_set_choose_dialogue();

  if (all || test == 18) test1_dialogue_get_choose_dialogue();
  if (all || test == 19) test2_dialogue_get_choose_dialogue();

  if (all || test == 20) test1_dialogue_set_interaction();
  if (all || test == 21) test2_dialogue_set_interaction();
  if (all || test == 22) test3_dialogue_set_interaction();

  if (all || test == 23) test1_dialogue_get_interaction();
  if (all || test == 24) test2_dialogue_get_interaction();


  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_dialogue_create(){
   Dialogue *d = dialogue_new();
   dialogue_set_num_tries (d , 5);

    PRINT_TEST_RESULT(d != NULL);
    dialogue_destroy (d);
   
} 

void test2_dialogue_create(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_get_num_tries (d) == -2);
    dialogue_destroy (d);
   
} 

void test1_dialogue_destroy(){
   Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_destroy (d) == ERROR);
     
} 

void test2_dialogue_destroy(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_destroy (d) == OK);
     
} 

void test1_dialogue_set_num_tries(){
   Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_num_tries (d , 5) == ERROR);
     
}

void test2_dialogue_set_num_tries(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_num_tries (d , -5) == ERROR);
     dialogue_destroy (d);
} 

void test3_dialogue_set_num_tries(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_num_tries (d , 5) == OK);
     dialogue_destroy (d);
} 

void test1_dialogue_get_num_tries(){
   Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_num_tries (d) == -1);
}

void test2_dialogue_get_num_tries(){
   Dialogue *d = dialogue_new();
   dialogue_set_num_tries (d , 5);

    PRINT_TEST_RESULT(dialogue_get_num_tries (d) == 5);
    dialogue_destroy(d);
}


void test1_dialogue_set_num_dialogues(){
   Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_num_dialogues (d , 5) == ERROR);
     
}

void test2_dialogue_set_num_dialogues(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_num_dialogues (d , -5) == ERROR);
     dialogue_destroy (d);
} 

void test3_dialogue_set_num_dialogues(){
   Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_num_dialogues (d , 5) == OK);
     dialogue_destroy (d);
} 

void test1_dialogue_get_num_dialogues(){
   Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_num_dialogues (d) == -1);
}

void test2_dialogue_get_num_dialogues(){
   Dialogue *d = dialogue_new();
   dialogue_set_num_dialogues (d , 5);

    PRINT_TEST_RESULT(dialogue_get_num_dialogues (d) == 5);
    dialogue_destroy(d);
}


void test1_dialogue_set_choose_dialogue(){
    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_choose_dialogue (d , 5) == ERROR);

}

void test2_dialogue_set_choose_dialogue(){
    Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_choose_dialogue (d , -5) == ERROR);
    dialogue_destroy (d);
}

void test3_dialogue_set_choose_dialogue(){
    Dialogue *d = dialogue_new();

    PRINT_TEST_RESULT(dialogue_set_choose_dialogue (d , 5) == OK);
    dialogue_destroy (d);
}

void test1_dialogue_get_choose_dialogue(){
    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_choose_dialogue (d) == -1);

}

void test2_dialogue_get_choose_dialogue(){
    Dialogue *d = dialogue_new();
    dialogue_set_choose_dialogue (d , 5);

    PRINT_TEST_RESULT(dialogue_get_choose_dialogue (d) == 5);
    dialogue_destroy (d);

}

void test1_dialogue_set_interaction(){
    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_interaction (d , "Ejemplo interaccio") == ERROR);

}

void test2_dialogue_set_interaction(){
    Dialogue *d = dialogue_new();
    char *ejemplo = NULL;

    PRINT_TEST_RESULT(dialogue_set_interaction (d , ejemplo) == ERROR);
    dialogue_destroy (d);
}

void test3_dialogue_set_interaction(){
    Dialogue *d = dialogue_new();
    char ejemplo[30] = "";
    strcpy (ejemplo , "Ejemplo de interaccion");
    PRINT_TEST_RESULT(dialogue_set_interaction (d , ejemplo) == OK);
    dialogue_destroy (d);
}

void test1_dialogue_get_interaction(){
    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_interaction (d , 0 ) == NULL);
}

void test2_dialogue_get_interaction(){
    Dialogue *d = dialogue_new();
    dialogue_set_interaction (d , "Ejemplo interacion");

    PRINT_TEST_RESULT(dialogue_get_interaction (d , 0) != NULL);
    dialogue_destroy(d);
}





