/** 
 * @brief It tests player module
 * 
 * @file player_test.c
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "player.h"
#include "player_test.h"
#include "test.h"

#define MAX_TESTS 36 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de PLAYER. 
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
    printf("Ejecutando todas las pruebas para el modulo Player:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Ejecutando prueba %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: prueba desconocida %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  
  if (all || test == 3) test1_player_destroy();
  if (all || test == 4) test2_player_destroy();

  if (all || test == 5) test1_player_set_name();
  if (all || test == 6) test2_player_set_name();
  if (all || test == 7) test3_player_set_name();  

  if (all || test == 8) test1_player_get_location();
  if (all || test == 9) test2_player_get_location();

  if (all || test == 10) test1_player_get_name();
  if (all || test == 11) test2_player_get_name();
  if (all || test == 12) test3_player_get_name();

  if (all || test == 13) test1_player_get_id();
  if (all || test == 14) test2_player_get_id();
  
  
  if (all || test == 15) test1_player_get_objects();
  if (all || test == 16) test2_player_get_objects();

  if (all || test == 17) test1_player_add_object();
  if (all || test == 18) test2_player_add_object();
  if (all || test == 19) test3_player_add_object();

  if (all || test == 20) test1_player_remove_object();
  if (all || test == 21) test2_player_remove_object();
  if (all || test == 22) test3_player_remove_object();

  if (all || test == 23) test1_player_set_location();   
  if (all || test == 24) test2_player_set_location();
  if (all || test == 25) test3_player_set_location();

  if (all || test == 26) test1_player_has_object();   
  if (all || test == 27) test2_player_has_object();
  if (all || test == 28) test3_player_has_object();

  if (all || test == 29) test1_player_get_inventory();
  if (all || test == 30) test2_player_get_inventory();

  if (all || test == 31) test1_player_set_inventory_max_capacity();
  if (all || test == 32) test2_player_set_inventory_max_capacity();
  if (all || test == 33) test3_player_set_inventory_max_capacity();

  if (all || test == 34) test1_player_print();   
  if (all || test == 35) test2_player_print();
  if (all || test == 36) test3_player_print();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_player_create(){
  Player *player  = player_create(5);

  PRINT_TEST_RESULT( player != NULL);
  player_destroy (player);
}
void test2_player_create(){
  Player *player= player_create(5);

  PRINT_TEST_RESULT( player_get_id(player) == 5);
  player_destroy (player);
}


void test1_player_destroy(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_destroy (player) == ERROR );
}

void test2_player_destroy(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_destroy (player) == OK);
}


void test1_player_set_name(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_destroy (player) == ERROR );

}
void test2_player_set_name(){
  Player *player = player_create(5);
  char nombre[6]="";
  PRINT_TEST_RESULT( player_set_name (player,nombre) == ERROR );
  player_destroy (player);

}
void test3_player_set_name(){
  Player *player = player_create(5);
  char nombre[6]="Alvaro";
  player_set_name (player,nombre);
  PRINT_TEST_RESULT( strcmp(player_get_name(player),nombre)==0);
  player_destroy (player);

}


void test1_player_get_location(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_get_location (player) == NO_ID );

}
void test2_player_get_location(){
  Player *player = player_create(5);
  player_set_location(player,10);
  PRINT_TEST_RESULT( player_get_location (player) == 10 );
  player_destroy (player);
}


void test1_player_get_name(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_get_name (player) == NULL );

}
void test2_player_get_name(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_get_name (player) != NULL);
  player_destroy (player);

}
void test3_player_get_name(){
  Player *player = player_create(5);
  char nombre[6]="Alvaro";
  player_set_name(player,nombre);
  PRINT_TEST_RESULT( strcmp(player_get_name(player),nombre)==0);
  player_destroy (player);

}


void test1_player_get_id(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_get_id (player) == NO_ID );

}
void test2_player_get_id(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_get_id (player) == 5 );
  player_destroy (player);
}


void test1_player_get_objects(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_get_objects (player) == NULL );

}
void test2_player_get_objects(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_get_objects(player)!= NULL);
  player_destroy (player);
}


void test1_player_add_object(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_add_object (player,10) == ERROR );

}
void test2_player_add_object(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_add_object(player,10)==ERROR);
  player_destroy (player);
}
void test3_player_add_object(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_add_object(player,10)==OK);
  player_destroy (player);
}


void test1_player_remove_object(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_remove_object (player,10) == ERROR );

}
void test2_player_remove_object(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_remove_object(player,5)==ERROR);
  player_destroy (player);
}
void test3_player_remove_object(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_remove_object(player,10)==OK);
  player_destroy (player);
}


void test1_player_set_location(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_set_location (player,10) == ERROR );

}
void test2_player_set_location(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_set_location(player,-1) == ERROR);
  player_destroy (player);
}
void test3_player_set_location(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_set_location(player,10) == OK);
  player_destroy (player);
}




void test1_player_has_object(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_has_object (player,10) == FALSE );

}
void test2_player_has_object(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_has_object(player,5)== FALSE);
  player_destroy (player);
}
void test3_player_has_object(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_has_object(player,10)==TRUE);
  player_destroy (player);
}

void test1_player_get_inventory(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_get_inventory (player) == NULL);

}
void test2_player_get_inventory(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_get_inventory(player)!=NULL);
  player_destroy (player);
}

void test1_player_set_inventory_max_capacity(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_set_inventory_max_capacity(player,10) == ERROR );

}
void test2_player_set_inventory_max_capacity(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_set_inventory_max_capacity(player,-1) == ERROR);
  player_destroy (player);
}
void test3_player_set_inventory_max_capacity(){
  Player *player = player_create(5);
  PRINT_TEST_RESULT( player_set_inventory_max_capacity(player,10) == OK);
  player_destroy (player);
}


void test1_player_print(){
  Player *player = NULL;
  PRINT_TEST_RESULT( player_print (stdout,player) == ERROR );

}
void test2_player_print(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_print(NULL,player)== ERROR);
  player_destroy (player);
}
void test3_player_print(){
  Player *player = player_create(5);
  player_add_object(player,10);
  PRINT_TEST_RESULT( player_print(stdout,player)==OK);
  player_destroy (player);
}