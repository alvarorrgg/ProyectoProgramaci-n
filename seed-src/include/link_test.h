/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author Alberto Vicente
 * @version 2.0 
 * @date 14-04-2021
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

 /**
 * @test Test function for link_create
 * @pre created link and checked if it is diferent from NULL
 * @post Output!=NULL
 */
void test1_link_create();

/**
 * @test Test function for link_create
 * @pre created link with id and checked if it had correct Id
 * @post Output==5
 */
void test2_link_create();

/**
 * @test Test function for link_get_id
 * @pre created link with id and checked if it had correct Id
 * @post Output==5
 */
void test1_link_get_id();

/**
 * @test Test function for link_get_id
 * @pre pointer to link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id();

/**
 * @test Test function for link_set_id
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OK
 */
void test1_link_set_id();

/**
 * @test Test function for link_set_id
 * @pre given wrong inputs with a wrong Id value to set.
 * @post Output==ERROR
 */
void test2_link_set_id();

/**
 * @test Test function for link_set_id
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id();

/**
 * @test Test function for link_get_name
 * @pre set a name to the link and check if it gets the same name
 * @post Output==OK
 */
void test1_link_get_name();

/**
 * @test Test function for link_get_name
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test2_link_get_name();

/**
 * @test Test function for link_set_name
 * @pre given correct inputs with a correct char value to set.
 * @post Output==OK
 */
void test1_link_set_name();

/**
 * @test Test function for link_set_name
 * @pre given wrong inputs with a wrong char value to set.
 * @post Output==ERROR
 */
void test2_link_set_name();

/**
 * @test Test function for link_set_name
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test3_link_set_name();

/**
 * @test Test function for link_get_id_from
 * @pre created link with id and checked if it had correct Id
 * @post Output==6
 */
void test1_link_get_id_from();

/**
 * @test Test function for link_get_id_from
 * @pre pointer to link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id_from();

/**
 * @test Test function for link_set_id_from
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OK
 */
void test1_link_set_id_from();

/**
 * @test Test function for link_set_id_from
 * @pre given wrong inputs with a wrong Id value to set.
 * @post Output==ERROR
 */
void test2_link_set_id_from();

/**
 * @test Test function for link_set_id_from
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id_from();

/**
 * @test Test function for link_get_id_to
 * @pre created link with id and checked if it had correct Id
 * @post Output==6
 */
void test1_link_get_id_to();

/**
 * @test Test function for link_get_id_to
 * @pre pointer to link=NULL
 * @post Output==NO_ID
 */
void test2_link_get_id_to();

/**
 * @test Test function for link_set_id_to
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OK
 */
void test1_link_set_id_to();

/**
 * @test Test function for link_set_id_to
 * @pre given wrong inputs with a wrong Id value to set.
 * @post Output==ERROR
 */
void test2_link_set_id_to();

/**
 * @test Test function for link_set_id_to
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test3_link_set_id_to();

/**
 * @test Test function for link_get_type
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OPEN
 */
void test1_link_get_type();

/**
 * @test Test function for link_get_type
 * @pre pointer to link=NULL
 * @post Output==CLOSE
 */
void test2_link_get_type();

/**
 * @test Test function for link_get_type
 * @pre given correct inputs with a correct Id value to set.
 * @post Output==OK
 */
void test1_link_set_type();

/**
 * @test Test function for link_get_type
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test2_link_set_type();

/**
 * @test Test function for link_print
 * @pre pointer to link=NULL
 * @post Output==ERROR
 */
void test1_link_print();

/**
 * @test Test function for link_print
 * @pre correct pointer to link but incorrect file.
 * @post Output==ERROR
 */
void test2_link_print();

/**
 * @test Test function for link_print
 * @pre Both file and pointer correctly given
 * @post Output==OK
 */
void test3_link_print();


#endif