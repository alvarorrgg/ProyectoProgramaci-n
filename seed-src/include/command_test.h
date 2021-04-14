/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test_en.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test funtion for command_init
 * @pre Creates command and checks that is not NULL
 * @post Output!=NULL 
 */
void test1_command_init();

/**
 * @test Test funtion for command_init
 * @pre Creates command and checks that the cmd has been initialized to NO_CMD
 * @post Output==NO_CMD
 */
void test2_command_init();

/**
 * @test Test funtion for command_init
 * @pre Creates command and checks that the status has been initialized to ERROR
 * @post Ouput==ERROR
 */
void test3_command_init();

/**
 * @test Test funtion for command_destroy
 * @pre Checks that it can't destroy an unitialized command 
 * @post Output==ERROR
 */
void test1_command_destroy();

/**
 * @test Test funtion for command_destroy
 * @pre Checks if it destroyed the command 
 * @post Output==OK
 */
void test2_command_destroy();
/**
 * @test Test function for command_set_status
 * @pre Checks if the status has been set properly
 * @post Output==OK
 */
void test1_command_set_status();
/**
 * @test Test function for command_set_status
 * @pre Checks that the state can't be set to a NULL command
 * @post Output==ERROR
 */
void test2_command_set_status();

/**
 * @test Test function for command_get_status
 * @pre Checks that the status is obtained properly
 * @post Output==ERROR
 */
void test1_command_get_status();
/**
 * @test Test function for command_get_status
 * @pre Checks the status from an initialized command
 * @post Output==NEXT
 */
void test2_command_get_status();
/**
 * @test Test function for command_set_cmd
 * @pre Checks if the cmd has been set properly
 * @post Output==OK
 */
void test1_command_set_cmd();
/**
 * @test Test function for command_set_cmd
 * @pre Checks that the cmd can't be set to a NULL command
 * @post Output==ERROR
 */
void test2_command_set_cmd();
/**
 * @test Test function for command_set_cmd
 * @pre Checks if the cmd has been set properly
 * @post Output==OK
 */
void test3_command_set_cmd();
/**
 * @test Test function for command_get_cmd
 * @pre Checks that the cmd has been obtained properly
 * @post Output==TAKE
 */
void test1_command_get_cmd();
/**
 * @test Test function for command_get_cmd
 * @pre Checks that the cmd from an initialized command is NO_CMD
 * @post Output==NO_CMD
 */
void test2_command_get_cmd();
/**
 * @test Test function for command_get_cmd
 * @pre Checks that the cmd from an uninitialized command is NO_CMD
 * @post Output==NO_CMD
 */
void test3_command_get_cmd();
/**
 * @test Test function for command_set_arg
 * @pre Checks that the arg is set properly
 * @post Output==0
 */
void test1_command_set_arg();
/**
 * @test Test function for command_set_arg
 * @pre Checks that the arg is set properly
 * @post Output==0
 */
void test2_command_set_arg();
/**
 * @test Test function for command_set_arg
 * @pre Checks that the arg can't be set to a NULL command
 * @post Output==ERROR
 */
void test3_command_set_arg();
/**
 * @test Test function for command_get_arg
 * @pre Checks that the lenght of an arg of an uninitialized command is 0
 * @post Output==0
 */
void test1_command_get_arg();
/**
 * @test Test function for space_get_arg
 * @pre Checks that thearg from an uninitialized command is NULL
 * @post Output==NULL
 */
void test2_command_get_arg();

/**
 * @test Test function for command_get_user_input
 * @pre Checks that command_get_user_input obtains the user input properly
 * @post Output==aux
 */
void test1_command_get_user_input();

#endif
