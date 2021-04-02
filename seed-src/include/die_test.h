/** 
 * @brief It declares the tests for the die module
 * 
 * @file die_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */
#ifndef DIE_TEST_H
#define DIE_TEST_H
 /**
 * @test Test function for die_create
 * @pre created die with id=5 and checked if last roll was correct
 * @post Output==NO_ID
 */
void test1_die_create();
 /**
 * @test Test function for die_roll
 * @pre created die with id and checked if it had correct Id
 * @post Output==5
 */
void test2_die_create();


 /**
 * @test Test function for die_roll
 * @pre pointer to die=NULL
 * @post Output==-1
 */
void test1_die_roll();
 /**
 * @test Test function for die_roll
 * @pre created a die, rolled and checked if last roll was between correct value gaps.
 * @post Output>0 && <7
 */
void test2_die_roll();


 /**
 * @test Test function for die_set_Id
 * @pre pointer to die=NULL
 * @post Output==ERROR
 */
void test1_die_set_Id();
 /**
 * @test Test function for die_set_Id
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OK
 */
void test2_die_set_Id();
 /**
 * @test Test function for die_set_Id
 * @pre given correct inputs with a negative Id value to set.
 * @post Output==ERROR
 */
void test3_die_set_Id();


 /**
 * @test Test function for die_get_last_roll
 * @pre pointer to die=NULL
 * @post Output==-1
 */
void test1_die_get_last_roll();
 /**
 * @test Test function for die_get_last_roll
 * @pre created a die, rolled and checked if last roll was between correct value gaps.
 * @post Output>0 && <7
 */
void test2_die_get_last_roll();


 /**
 * @test Test function for die_get_id
 * @pre pointer to die=NULL
 * @post Output==NO_ID
 */
void test1_die_get_id();
 /**
 * @test Test function for die_get_id
 * @pre created die with Id=5 and checked if die Id was correctly storaged
 * @post Output==5
 */
void test2_die_get_id();


 /**
 * @test Test function for die_print
 * @pre pointer to die=NULL
 * @post Output==ERROR
 */
void test1_die_print();
 /**
 * @test Test function for die_print
 * @pre correct pointer to die but incorrect file.
 * @post Output==ERROR
 */
void test2_die_print();
 /**
 * @test Test function for die_print
 * @pre Both file and pointer correctly given
 * @post Output==OK
 */
void test3_die_print();

#endif
