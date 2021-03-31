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
 * @test Test function for inventory_setObject
 * @pre try add an object in a NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_setObject();

 /**
 * @test Test function for inventory_setObject
 * @pre try add an existing object
 * @post Output==ERROR
 */
void test2_inventory_setObject();

 /**
 * @test Test function for inventory_setObject
 * @pre try add an  object with a negative id
 * @post Output==ERROR
 */
void test3_inventory_setObject();

/**
 * @test Test function for inventory_setObject
 * @pre try add an  object with a NULL id
 * @post Output==ERROR
 */
void test4_inventory_setObject();

/**
 * @test Test function for inventory_setObject
 * @pre set the number of objects to 1000 and trying to add one more object
 * @post Output==ERROR
 */
void test5_inventory_setObject();

/**
 * @test Test function for inventory_getObject
 * @pre try to get the objects of a NULL inventory
 * @post Output==NULL
 */
void test1_inventory_getInventory();

/**
 * @test Test function for inventory_getObject
 * @pre try to get the objects of a inventory with 0 objects
 * @post Output==NULL
 */
void test2_inventory_getInventory();

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
 * @test Test function for inventory_deleteObject
 * @pre try to delete an object in a NULL Inventory
 * @post Output==ERROR
 */
void test1_inventory_deleteObject();

/**
 * @test Test function for inventory_deleteObject
 * @pre try to delete an object with NULL id
 * @post Output==ERROR
 */
void test2_inventory_deleteObject();

/**
 * @test Test function for inventory_deleteObject
 * @pre try to delete an object with negative id
 * @post Output==ERROR
 */
void test3_inventory_deleteObject();

/**
 * @test Test function for inventory_deleteObject
 * @pre try to delete an object in a empty inventory
 * @post Output==ERROR
 */
void test4_inventory_deleteObject();

/**
 * @test Test function for inventory_deleteObject
 * @pre try to delete an object that is not in the Inventory
 * @post Output==ERROR
 */
void test5_inventory_deleteObject();

/**
 * @test Test function for inventory_isEmpty
 * @pre NULL inventory
 * @post Output==ERROR
 */
void test1_inventory_isEmpty();

/**
 * @test Test function for inventory_isEmpty
 * @pre a non empty inventory
 * @post Output==FALSE
 */
void test2_inventory_isEmpty();

/**
 * @test Test function for inventory_isEmpty
 * @pre an empty inventory
 * @post Output==TRUE
 */
void test3_inventory_isEmpty();


#endif