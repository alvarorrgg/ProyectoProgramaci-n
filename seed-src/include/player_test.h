/** 
 * @brief It declares the tests for the player module
 * 
 * @file player_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 31-03-2021
 * @copyright GNU Public License
 */
#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H
 /**
 * @test Test function for player_create
 * @pre created player and checked if it is diferent from NULL
 * @post Output!=NULL
 */
void test1_player_create();
 /**
 * @test Test function for player_create
 * @pre created player and checked if it's id was the given when created
 * @post Output==5
 */
void test2_player_create();


 /**
 * @test Test function for player_destroy
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_destroy();
 /**
 * @test Test function for player_destroy
 * @pre given correct player and checked if output is OK
 * @post Output==OK
 */
void test2_player_destroy();

 /**
 * @test Test function for player_set_name
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_set_name();
 /**
 * @test Test function for player_set_name
 * @pre given NULL name and checked if output was ERROR
 * @post Output==ERROR
 */
void test2_player_set_name();
 /**
 * @test Test function for player_set_name
 * @pre given correct name and player and checked if output when calling player_get_name was the name given with player_set_name
 * @post Output=="Alvaro"
 */
void test3_player_set_name();


 /**
 * @test Test function for player_get_name
 * @pre given NULL player and checked if output was NULL
 * @post Output==NULL
 */
void test1_player_get_name();
 /**
 * @test Test function for player_get_name
 * @pre created a player and checked if name was different from NULL
 * @post Output!=NULL
 */
void test2_player_get_name();
 /**
 * @test Test function for player_get_name
 * @pre given correct name and player and checked if output when calling player_get_name was the name given with player_set_name
 * @post Output=="Alvaro"
 */
void test3_player_get_name();


 /**
 * @test Test function for player_get_id
 * @pre given NULL player and checked if output was NO_ID
 * @post Output==NO_ID
 */
void test1_player_get_id();
 /**
 * @test Test function for player_get_id
 * @pre created player and checked if output was the correct id
 * @post Output==5
 */
void test2_player_get_id();


 /**
 * @test Test function for player_get_objects
 * @pre given NULL player and checked if output was NULL
 * @post Output==NULL
 */
void test1_player_get_objects();
 /**
 * @test Test function for player_get_objects
 * @pre creating player and adding an object, then checking if output is different from NULL
 * @post Output!=NULL
 */
void test2_player_get_objects();


 /**
 * @test Test function for player_add_object
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_add_object();
 /**
 * @test Test function for player_add_object
 * @pre creating a player, adding an object, then trying to add the same object once again.
 * @post Output==ERROR
 */
void test2_player_add_object();
 /**
 * @test Test function for player_add_object
 * @pre created a player and trying to add a object
 * @post Output==OK
 */
void test3_player_add_object();

 /**
 * @test Test function for player_remove_object
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_remove_object();
 /**
 * @test Test function for player_remove_object
 * @pre creating a player, adding an object, then trying to remove a different object
 * @post Output==ERROR
 */
void test2_player_remove_object();
 /**
 * @test Test function for player_remove_object
 * @pre created a player adding an object then removing the same object
 * @post Output==OK
 */
void test3_player_remove_object();


 /**
 * @test Test function for player_set_location
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_set_location();
 /**
 * @test Test function for player_set_location
 * @pre created a player and tried to set its position to NO_ID
 * @post Output==ERROR
 */
void test2_player_set_location();
 /**
 * @test Test function for player_set_location
 * @pre created a player and tried to gave a normal position
 * @post Output==OK
 */
void test3_player_set_location();


 /**
 * @test Test function for player_get_location
 * @pre given NULL player and checked if output was NO_ID
 * @post Output==NO_ID
 */
void test1_player_get_location();
 /**
 * @test Test function for player_get_location
 * @pre created a player changed its location with player_set_location then calling player_get_location
 * @post Output==10
 */
void test2_player_get_location();

 /**
 * @test Test function for player_has_object
 * @pre given NULL player and checked if output was FALSE
 * @post Output==FALSE
 */
void test1_player_has_object();
 /**
 * @test Test function for player_has_object
 * @pre created a player and checked if it has a non added object
 * @post Output==FALSE
 */
void test2_player_has_object();
 /**
 * @test Test function for player_has_object
 * @pre created a player added a object and checked if it had the object.
 * @post Output==TRUE
 */
void test3_player_has_object();


 /**
 * @test Test function for player_get_inventory
 * @pre given NULL player and checked if output=NULL
 * @post Output==NULL
 */
void test1_player_get_inventory();
 /**
 * @test Test function for player_get_inventory
 * @pre given correct player and added an object then checking if ouput is different from NULL
 * @post Output!=NULL
 */
void test2_player_get_inventory();


 /**
 * @test Test function for player_set_inventory_max_capacity
 * @pre given NULL player and checking if output is ERROR
 * @post Output==ERROR
 */
void test1_player_set_inventory_max_capacity();
 /**
 * @test Test function for player_set_inventory_max_capacity
 * @pre Trying to change the capacity to a negative level
 * @post Output==ERROR
 */
void test2_player_set_inventory_max_capacity();
 /**
 * @test Test function for player_set_inventory_max_capacity
 * @pre given correct player and trying to change capacity to correct number
 * @post Output==OK
 */
void test3_player_set_inventory_max_capacity();


 /**
 * @test Test function for player_has_object
 * @pre given NULL player and checked if output was ERROR
 * @post Output==ERROR
 */
void test1_player_print();
 /**
 * @test Test function for player_has_object
 * @pre given NULL file and checked if output was ERROR
 * @post Output==ERROR
 */
void test2_player_print();
 /**
 * @test Test function for player_has_object
 * @pre given correct input and checked if output was OK
 * @post Output==OK
 */
void test3_player_print();

#endif