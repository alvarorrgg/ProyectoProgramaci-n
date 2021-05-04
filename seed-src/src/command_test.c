/** 
 * @brief It tests the command module
 * 
 * @file command_test.c
 * @author Alexandru Marius
 * @version 2.0 
 * @date 15-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "command_test.h"
#include "test.h"

#define MAX_TESTS 21 /*!<Numero maximo de tests*/

/** 
 * @brief Función main para la unidad de pruebas de COMMAND. 
 * 
 * Se puede ejecutar con ALL o SINGLE test
 *   1.- Sin parámetros -> ALL todas las pruebas son ejecutadas 
 *   2.- Un numero simboliza un número particular de una prueba (la que se identifica con dicho número) que
 *       se ejecuta
 *  
 */
int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)  printf("Ejecutando todas las pruebas para el modulo Command:\n");
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Ejecutando prueba %d:\t", test);
        if (test < 1 && test > MAX_TESTS)
        {
            printf("Error: prueba desconocida %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1)test1_command_init();
    if (all || test == 2)test2_command_init();
    if (all || test == 3)test3_command_init();

    if (all || test == 4)test1_command_destroy();
    if (all || test == 5)test2_command_destroy();
    
    if (all || test == 6)test1_command_set_status();
    if (all || test == 7)test2_command_set_status();

    if (all || test == 8)test1_command_get_status();
    if (all || test == 9)test2_command_get_status();
    
    if (all || test == 10)test1_command_set_cmd();
    if (all || test == 11)test2_command_set_cmd();
    if (all || test == 12)test3_command_set_cmd();
    
    if (all || test == 13)test1_command_get_cmd();
    if (all || test == 14)test2_command_get_cmd();
    if (all || test == 15)test3_command_get_cmd();

    if (all || test == 16)test1_command_set_arg();
    if (all || test == 17)test2_command_set_arg();
    if (all || test == 18)test3_command_set_arg();

    if (all || test == 19)test1_command_get_arg();
    if (all || test == 20)test2_command_get_arg();

    if (all || test == 21)test1_command_set_obj();
    if (all || test == 22)test2_command_set_obj();
    if (all || test == 23)test3_command_set_obj();

    if (all || test == 24)test1_command_get_obj();
    if (all || test == 25)test2_command_get_obj();
    if (all || test == 26)test1_command_get_user_input();
    

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_command_init()
{
    Command *new_command = NULL;
    new_command = command_init();
    PRINT_TEST_RESULT(new_command != NULL);
    command_destroy(new_command);
}

void test2_command_init()
{
    Command *new_command = NULL;
    new_command = command_init();
    PRINT_TEST_RESULT(command_get_cmd(new_command) == NO_CMD);
    command_destroy(new_command);
}
void test3_command_init()
{
    Command *new_command = NULL;
    new_command = command_init();
    PRINT_TEST_RESULT(command_get_status(new_command) == ERROR);
    command_destroy(new_command);
}
void test1_command_destroy()
{
    Command *new_command = NULL;

    PRINT_TEST_RESULT(command_destroy(new_command) == ERROR);
}
void test2_command_destroy()
{
    Command *new_command = NULL;
    new_command = command_init();

    PRINT_TEST_RESULT(command_destroy(new_command) == OK);
}
void test1_command_set_status()
{
    Command *new_command = NULL;
    new_command = command_init();

    command_set_status(new_command, OK);
    PRINT_TEST_RESULT(command_get_status(new_command) == OK);
    command_destroy(new_command);
}
void test2_command_set_status()
{
    Command *new_command = NULL;
    
    
    PRINT_TEST_RESULT(command_set_status(new_command, OK)==ERROR);
    
}

void test1_command_get_status()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_status(new_command, ERROR);
    PRINT_TEST_RESULT(command_get_status(new_command) == ERROR);
    command_destroy(new_command);
}
void test2_command_get_status()
{
    Command *new_command = NULL;
    new_command = command_init();

    PRINT_TEST_RESULT(command_get_status(new_command) == ERROR);
    command_destroy(new_command);
}
void test1_command_set_cmd()
{
    Command *new_command = NULL;
    new_command = command_init();

    command_set_cmd(new_command, EXIT);
    PRINT_TEST_RESULT(command_get_cmd(new_command) == EXIT);
    command_destroy(new_command);
}
void test2_command_set_cmd()
{
    Command *new_command = NULL;
    
    
    PRINT_TEST_RESULT(command_set_cmd(new_command, INSPECT)==ERROR);
    
}
void test3_command_set_cmd()
{
    Command *new_command = NULL;
    new_command = command_init();

    
    PRINT_TEST_RESULT(command_set_cmd(new_command, UNKNOWN) == OK);
    command_destroy(new_command);
}
void test1_command_get_cmd()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_cmd(new_command, TAKE);
    PRINT_TEST_RESULT(command_get_cmd(new_command) == TAKE);
    command_destroy(new_command);
}
void test2_command_get_cmd()
{
    Command *new_command = NULL;
    new_command = command_init();
    
    PRINT_TEST_RESULT(command_get_cmd(new_command) == NO_CMD);
    command_destroy(new_command);
}
void test3_command_get_cmd()
{
    Command *new_command = NULL;
    
    
    PRINT_TEST_RESULT(command_get_cmd(new_command) == NO_CMD);
    
}

void test1_command_set_arg()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_arg(new_command, "north");
    PRINT_TEST_RESULT(strcmp(command_get_arg(new_command), "north")==0);
    command_destroy(new_command);
}
void test2_command_set_arg()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_arg(new_command, "argumento_de_prueba");
    PRINT_TEST_RESULT(strcmp(command_get_arg(new_command), "argumento_de_prueba")==0);
    command_destroy(new_command);
}
void test3_command_set_arg()
{
    Command *new_command = NULL;
    PRINT_TEST_RESULT(command_set_arg(new_command, "argumento_de_prueba")==ERROR);
}
void test1_command_get_arg()
{
    Command *new_command = NULL;
    new_command = command_init();

    PRINT_TEST_RESULT(strlen(command_get_arg(new_command))==0);
    command_destroy(new_command);
}
void test2_command_get_arg()
{
    Command *new_command = NULL;
    PRINT_TEST_RESULT(command_get_arg(new_command) == NULL);
    
}


void test1_command_set_obj()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_obj(new_command, "north");
    PRINT_TEST_RESULT(strcmp(command_get_obj(new_command), "north")==0);
    command_destroy(new_command);
}
void test2_command_set_obj()
{
    Command *new_command = NULL;
    new_command = command_init();
    command_set_obj(new_command, "argumento_de_prueba");
    PRINT_TEST_RESULT(strcmp(command_get_obj(new_command), "argumento_de_prueba")==0);
    command_destroy(new_command);
}
void test3_command_set_obj()
{
    Command *new_command = NULL;
    PRINT_TEST_RESULT(command_set_obj(new_command, "argumento_de_prueba")==ERROR);
}
void test1_command_get_obj()
{
    Command *new_command = NULL;
    new_command = command_init();

    PRINT_TEST_RESULT(strlen(command_get_obj(new_command))==0);
    command_destroy(new_command);
}
void test2_command_get_obj()
{
    Command *new_command = NULL;
    PRINT_TEST_RESULT(command_get_obj(new_command) == NULL);
    
}



void test1_command_get_user_input()
{
    T_Command aux;
    Command *new_command = NULL;
    new_command = command_init();
    
    printf("Escribe un comando:\n");
    aux=command_get_user_command();
    command_set_cmd(new_command, aux);
    
    printf("Posicion de comando: %d\n", aux);
    PRINT_TEST_RESULT(command_get_cmd(new_command)==aux);
    command_destroy(new_command);
}

