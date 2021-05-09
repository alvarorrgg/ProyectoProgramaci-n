/** 
 * @brief Archivo cabecera de dialogue_test.c en el se encuentra definidas los datos y funciones de dialogue_test.c
 * 
 * 
 * @file dialogue_test.h
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 09-05-21
 * @copyright GNU Public License
 */

#ifndef DIALOGUE_TEST_H
#define DIALOGUE_TEST_H
#include "test.h"
#include "dialogue.h"
#include "types.h"


/**
 * @test Función de prueba para dialogue_new
 * @pre  
 * @post output Non NULL Puntero a dialogue 
 */
void test1_dialogue_create();

/**
 * @test Función de prueba para dialogue_new
 * @pre  
 * @post output Non NULL Puntero a dialogue con num_tries = -1
 */
void test2_dialogue_create();

/**
 * @test Función de prueba para dialogue_destroy
 * @pre  input NULL dialogue
 * @post output == ERROR
 */
void test1_dialogue_destroy();

/**
 * @test Función de prueba para dialogue_destroy
 * @pre  input  correcto
 * @post output == OK
 */
void test2_dialogue_destroy();

/**
 * @test Función de prueba para dialogue_set_num_tries
 * @pre  input  NULL dialogue
 * @post output == ERROR;
 */
void test1_dialogue_set_num_tries();

/**
 * @test Función de prueba para dialogue_set_num_tries
 * @pre  input  num_tries < 0
 * @post output == ERROR;
 */
void test2_dialogue_set_num_tries();

/**
 * @test Función de prueba para dialogue_set_num_tries
 * @pre  inputs correctos
 * @post output == OK;
 */
void test3_dialogue_set_num_tries();

/**
 * @test Función de prueba para dialogue_get_num_tries
 * @pre  input  NULL dialogue
 * @post output == -1;
 */
void test1_dialogue_get_num_tries();

/**
 * @test Función de prueba para dialogue_get_num_tries
 * @pre  input  correct dialogue
 * @post output == 3;
 */
void test2_dialogue_get_num_tries();

/**
 * @test Función de prueba para dialogue_set_num_dialogues
 * @pre  input  NULL dialogue
 * @post output == ERROR;
 */
void test1_dialogue_set_num_dialogues();

/**
 * @test Función de prueba para dialogue_set_num_dialogues
 * @pre  input  num_dialogues < 0
 * @post output == ERROR;
 */
void test2_dialogue_set_num_dialogues();

/**
 * @test Función de prueba para dialogue_set_num_dialogues
 * @pre  input  correctos
 * @post output == OK;
 */
void test3_dialogue_set_num_dialogues();


/**
 * @test Función de prueba para dialogue_get_num_dialogues
 * @pre  input  NULL dialogue
 * @post output == -1;
 */
void test1_dialogue_get_num_dialogues();

/**
 * @test Función de prueba para dialogue_get_num_dialogues
 * @pre  input  correcto
 * @post output == 5;
 */
void test2_dialogue_get_num_dialogues();

/**
 * @test Función de prueba para dialogue_set_choose_dialogue
 * @pre  input  NULL dialogue
 * @post output == ERROR;
 */
void test1_dialogue_set_choose_dialogue();

/**
 * @test Función de prueba para dialogue_set_choose_dialogue
 * @pre  input  choose_dialogue < 0
 * @post output == ERROR;
 */
void test2_dialogue_set_choose_dialogue();

/**
 * @test Función de prueba para dialogue_set_choose_dialogue
 * @pre  input  correctos
 * @post output == OK;
 */
void test3_dialogue_set_choose_dialogue();


/**
 * @test Función de prueba para dialogue_get_choose_dialogue
 * @pre  input  NULL dialogue
 * @post output == -1;
 */
void test1_dialogue_get_choose_dialogue();

/**
 * @test Función de prueba para dialogue_get_choose_dialogue
 * @pre  input  correcto
 * @post output == 5;
 */
void test2_dialogue_get_choose_dialogue();


/**
 * @test Función de prueba para dialogue_set_interaction
 * @pre  input  NULLL dialogue
 * @post output == ERROR;
 */
void test1_dialogue_set_interaction();

/**
 * @test Función de prueba para dialogue_set_interaction
 * @pre  input  NULLL new_interaction
 * @post output == ERROR;
 */
void test2_dialogue_set_interaction();

/**
 * @test Función de prueba para dialogue_set_interaction
 * @pre  inputs correctos
 * @post output == OK;
 */
void test3_dialogue_set_interaction();

/**
 * @test Función de prueba para dialogue_get_interaction
 * @pre  input NULL dialogue
 * @post output == NULL;
 */
void test1_dialogue_get_interaction();

/**
 * @test Función de prueba para dialogue_get_interaction
 * @pre  inputs correctos
 * @post output == "Ejemplo interaccion";
 */
void test2_dialogue_get_interaction();


#endif