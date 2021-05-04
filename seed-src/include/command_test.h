/** 
 * @brief Archivo cabecera de command_test.c en el se encuentra definidas los datos y funciones de command_test.c
 * 
 * @file command_test.h
 * @author Alexandru Marius
 * @version 2.0 
 * @date 15-04-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H

/**
 * @test Función de prueba para command_init
 * @pre Crea un comando y comprueba que no sea NULL
 * @post Output!=NULL 
 */
void test1_command_init();

/**
 * @test Función de prueba para command_init
 * @pre Crea un comando y comprueba que el cmd se haya inicializado en NO_CMD
 * @post Output==NO_CMD
 */
void test2_command_init();

/**
 * @test Función de prueba para command_init
 * @pre Crea un comando ycomprueba que el status se haya inicializado en ERROR
 * @post Ouput==ERROR
 */
void test3_command_init();

/**
 * @test Función de prueba para command_destroy
 * @pre Comprueba que no se pueda borrar un comando no inicializado
 * @post Output==ERROR
 */
void test1_command_destroy();

/**
 * @test Función de prueba para command_destroy
 * @pre Comprueba que el comando se haya destruido
 * @post Output==OK
 */
void test2_command_destroy();
/**
 * @test Función de prueba para command_set_status
 * @pre Comprueba que el status ha sido establecido correctamente
 * @post Output==OK
 */
void test1_command_set_status();
/**
 * @test Función de prueba para command_set_status
 * @pre Comprueba que no se puede establecer un estado a un comando no inicializado
 * @post Output==ERROR
 */
void test2_command_set_status();

/**
 * @test Función de prueba para command_get_status
 * @pre Comprueba que el status se ha obtenido correctamente
 * @post Output==ERROR
 */
void test1_command_get_status();
/**
 * @test Función de prueba para command_get_status
 * @pre Comprueba el status de un comando inicializado
 * @post Output==ERROR
 */
void test2_command_get_status();
/**
 * @test Función de prueba para command_set_cmd
 * @pre Comprueba que el comando ha sido establecido correctamente
 * @post Output==OK
 */
void test1_command_set_cmd();
/**
 * @test Función de prueba para command_set_cmd
 * @pre Comprueba que no se puede establecer un cmd a un comando no inicializado
 * @post Output==ERROR
 */
void test2_command_set_cmd();
/**
 * @test Función de prueba para command_set_cmd
 * @pre Comprueba que el cmd ha sido esatblecido correctamnte 
 * @post Output==OK
 */
void test3_command_set_cmd();
/**
 * @test Función de prueba para command_get_cmd
 * @pre Comprueba que el comando se ha obtenido correctamente
 * @post Output==TAKE
 */
void test1_command_get_cmd();
/**
 * @test Función de prueba para command_get_cmd
 * @pre Comprueba que el cmd de un comando inicializado es NO_CMD
 * @post Output==NO_CMD
 */
void test2_command_get_cmd();
/**
 * @test Función de prueba para command_get_cmd
 * @pre Comprueba que el cmd de un comando no inicializado es NO_CMD
 * @post Output==NO_CMD
 */
void test3_command_get_cmd();
/**
 * @test Función de prueba para command_set_arg
 * @pre Comprueba que el arg se ha esatblecido correctamente
 * @post Output==0
 */
void test1_command_set_arg();
/**
 * @test Función de prueba para command_set_arg
 * @pre Comprueba que el arg se ha esatblecido correctamente
 * @post Output==0
 */
void test2_command_set_arg();
/**
 * @test Función de prueba parar command_set_arg
 * @pre Comprueba que arg no puede ser esatblecido para un comando sin inicializar
 * @post Output==ERROR
 */
void test3_command_set_arg();
/**
 * @test Función de prueba para command_get_arg
 * @pre Comprueba que la longitud del arg de un comando inicializado es 0
 * @post Output==0
 */
void test1_command_get_arg();
/**
 * @test Función de prueba para command_get_arg
 * @pre Comprueba que el arg de un comando no inicializado es NULL
 * @post Output==NULL
 */
void test2_command_get_arg();

/**
 * @test Función de prueba para command_set_obj
 * @pre Comprueba que el obj se ha esatblecido correctamente
 * @post Output==0
 */
void test1_command_set_obj();
/**
 * @test Función de prueba para command_set_obj
 * @pre Comprueba que el obj se ha esatblecido correctamente
 * @post Output==0
 */
void test2_command_set_obj();
/**
 * @test Función de prueba parar command_set_obj
 * @pre Comprueba que obj no puede ser esatblecido para un comando sin inicializar
 * @post Output==ERROR
 */
void test3_command_set_obj();
/**
 * @test Función de prueba para command_get_obj
 * @pre Comprueba que la longitud del obj de un comando inicializado es 0
 * @post Output==0
 */
void test1_command_get_obj();
/**
 * @test Función de prueba para command_get_obj
 * @pre Comprueba que el obj de un comando no inicializado es NULL
 * @post Output==NULL
 */
void test2_command_get_obj();

/**
 * @test Función de prueba para command_get_user_input
 * @pre Comprueba que el input del usuario se ha obtenido correctamente
 * @post Output==aux
 */
void test1_command_get_user_input();

#endif
