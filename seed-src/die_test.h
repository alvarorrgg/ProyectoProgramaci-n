/** 
 * @brief It declares the tests for the die module
 * 
 * @file die_test.h
 * @author R1
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */
 #ifndef DIE_TEST_H
#define DIE_TEST_H

void test1_die_create();
void test2_die_create();
 /**
 * @test Test function for die_roll
 * @pre pointer to die=NULL
 * @post Output==-1
 */
void test1_die_roll();
void test2_die_roll();
 /**
 * @test Test function for die_set_Id
 * @pre pointer to die=NULL
 * @post Output==ERROR
 */
void test1_die_set_Id();
void test2_die_set_Id();
void test3_die_set_Id();
 /**
 * @test Test function for die_get_last_roll
 * @pre pointer to die=NULL
 * @post Output==-1
 */
void test1_die_get_last_roll();
void test2_die_get_last_roll();

 /**
 * @test Test function for die_get_id
 * @pre pointer to die=NULL
 * @post Output==NO_ID
 */
void test1_die_get_id();
void test2_die_get_id();

 /**
 * @test Test function for die_print
 * @pre pointer to die=NULL
 * @post Output==ERROR
 */
void test1_die_print();
void test2_die_print();
void test3_die_print();







#endif
