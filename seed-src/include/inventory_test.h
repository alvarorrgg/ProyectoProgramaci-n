/** 
 * @brief It declares the tests for the inventory module
 * 
 * @file inventory_test.h
 * @author Gonzalo Martín
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */
#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H
 /**
 * @test Test function for inventory_create
 * @pre created inventory and checked if it is diferent from NULL
 * @post Output==NULL
 */
void test1_inventory_create();

 /**
 * @test Test function for inventory_create
 * @pre created inventory and checked if the  inventory is empty
 * @post Output==TRUE
 */
void test2_inventory_create();

 /**
 * @test Test function for inventory_destroy
 * @pre try to destroy a NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_destroy();

 /**
 * @test Test function for inventory_set_object
 * @pre try add an object in a NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_set_object();

 /**
 * @test Test function for inventory_set_object
 * @pre try add an existing object
 * @post Output==ERROR
 */
void test2_inventory_set_object();

 /**
 * @test Test function for inventory_set_object
 * @pre try add an  object with a negative id
 * @post Output==ERROR
 */
void test3_inventory_set_object();

/**
 * @test Test function for inventory_set_object
 * @pre try add an  object with a NULL id
 * @post Output==ERROR
 */
void test4_inventory_set_object();

/**
 * @test Test function for inventory_set_object
 * @pre set the number of objects to 1000 and trying to add one more object
 * @post Output==ERROR
 */
void test5_inventory_set_object();

/**
 * @test Test function for inventory_get_inventory
 * @pre try to get the objects of a NULL inventory
 * @post Output==NULL
 */
void test1_inventory_get_inventory();

/**
 * @test Test function for inventory_get_inventory
 * @pre try to get the objects of a inventory with 0 objects
 * @post Output==NULL
 */
void test2_inventory_get_inventory();

/**
 * @test Test function for inventory_print
 * @pre try to print a NULL
 * @post Output==ERROR
 */
void test1_inventory_print();

/**
 * @test Test function for inventory_print
 * @pre try to print with a NULL file
 * @post Output==ERROR
 */
void test2_inventory_print();

/**
 * @test Test function for inventory_print
 * @pre try to print with a corrects inputs
 * @post Output==OK
 */
void test3_inventory_print();

/**
 * @test Test function for inventory_delete_object
 * @pre try to delete an object in a NULL Inventory
 * @post Output==ERROR
 */
void test1_inventory_delete_object();

/**
 * @test Test function for inventory_delete_object
 * @pre try to delete an object with NULL id
 * @post Output==ERROR
 */
void test2_inventory_delete_object();

/**
 * @test Test function for inventory_delete_object
 * @pre try to delete an object with negative id
 * @post Output==ERROR
 */
void test3_inventory_delete_object();

/**
 * @test Test function for inventory_delete_object
 * @pre try to delete an object in a empty inventory
 * @post Output==ERROR
 */
void test4_inventory_delete_object();

/**
 * @test Test function for inventory_delete_object
 * @pre try to delete an object that is not in the Inventory
 * @post Output==ERROR
 */
void test5_inventory_delete_object();

/**
 * @test Test function for inventory_is_empty
 * @pre NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_is_empty();

/**
 * @test Test function for inventory_is_empty
 * @pre a non empty inventory
 * @post Output==FALSE
 */
void test2_inventory_is_empty();

/**
 * @test Test function for inventory_is_empty
 * @pre an empty inventory
 * @post Output==TRUE
 */
void test3_inventory_is_empty();

/**
 * @test Test function for inventory_is_full
 * @pre an NULL inventory
 * @post Output==FALSE
 */
void test1_inventory_is_full();

/**
 * @test Test function for inventory_is_full
 * @pre a non full inventory
 * @post Output==FALSE
 */
void test2_inventory_is_full();

/**
 * @test Test function for inventory_is_full
 * @pre a full inventory
 * @post Output==TRUE
 */
void test3_inventory_is_full();

/**
 * @test Test function for inventory_serach_object
 * @pre a NULL inventory
 * @post Output==FALSE
 */
void test1_inventory_search_object();

/**
 * @test Test function for inventory_search_object
 * @pre a NO_ID id
 * @post Output==FALSE
 */
void test2_inventory_search_object();

/**
 * @test Test function for inventory_search_object
 * @pre a negative inventory
 * @post Output==FALSE
 */
void test3_inventory_search_object();

/**
 * @test Test function for inventory_search_object
 * @pre try to search a object that is not in the inventory
 * @post Output==FALSE
 */
void test4_inventory_search_object();

/**
 * @test Test function for inventory_search_object
 * @pre try to search a object that is  in the inventory
 * @post Output==TRUE
 */
void test5_inventory_search_object();

/**
 * @test Test function for inventory_set_max_objects
 * @pre a NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_set_max_objects();

/**
 * @test Test function for inventory_set_max_objects
 * @pre a negative number
 * @post Output==ERROR
 */
void test2_inventory_set_max_objects();

/**
 * @test Test function for inventory_set_max_objects
 * @pre corrects inputs
 * @post Output==previous set number
 */
void test3_inventory_set_max_objects();

/**
 * @test Test function for inventory_get_max_objects
 * @pre a NULL inventory
 * @post Output==-1
 */
void test1_inventory_get_max_objects();

/**
 * @test Test function for inventory_get_max_objects
 * @pre a correct inventory
 * @post Output == 15 
 */
void test2_inventory_get_max_objects();



#endif