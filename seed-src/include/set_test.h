/** 
 * @brief Archivo cabecera de set_test.c en el se encuentra definidas los datos y funciones de set_test.c
 * 
 * @file set_test.h
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 18-02-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H
/**
 * @test Test function for set_create
 * @pre given correct inputs and looking if total ids are 0
 * @post Output==0
 */
  void test1_set_create();  
 /**
 * @test Test function for set_create
 * @pre given correct inputs and looking if the set is empty
 * @post Output==TRUE
 */
  void test2_set_create();
   /**
 * @test Test function for set_id_add
 * @pre pointer to set=NULL
 * @post Output==ERROR
 */
  void test1_set_id_add();
   /**
 * @test Test function for set_id_add
 * @pre given correct inputs and trying to add a normal id
 * @post Output==OK
 */
  void test2_set_id_add();
   /**
 * @test Test function for set_id_add
 * @pre given correct inputs and trying to add negative id
 * @post Output==ERROR
 */
  void test3_set_id_add();
   /**
 * @test Test function for set_id_add
 * @pre set the number of ids to 1000 and trying to add one more id
 * @post Output==ERROR
 */
  void test4_set_id_add(); 
  
   /**
 * @test Test function for set_id_delete
 * @pre pointer to set=NULL
 * @post Output==ERROR
 */ 
  void test1_set_id_delete();
   /**
 * @test Test function for set_id_delete
 * @pre given correct inputs and adding a correct id then trying to delete the same id
 * @post Output==OK
 */
  void test2_set_id_delete();
   /**
 * @test Test function for set_id_delete
 * @pre given correct inputs and adding a correct id then trying to delete a different id
 * @post Output==ERROR
 */
  void test3_set_id_delete();
   /**
 * @test Test function for set_id_delete
 * @pre set the number of ids to 0 and trying to delete one id
 * @post Output==ERROR
 */
  void test4_set_id_delete();
  
     /**
 * @test Test function for set_set_total_ids
 * @pre pointer to set=NULL
 * @post Output==ERROR
 */  
  void test1_set_set_total_ids();
     /**
 * @test Test function for set_set_total_ids
 * @pre given correct inputs but trying to set the total ids to negative number
 * @post Output==ERROR
 */
  void test2_set_set_total_ids();
     /**
 * @test Test function for set_set_total_ids
 * @pre given correct inputs and trying to set total ids to propper number
 * @post Output==OK
 */
  void test3_set_set_total_ids(); 
  /**
 * @test Test function for set_get_total_ids
 * @pre pointer to set=NULL
 * @post Output==ERROR
 */
  void test1_set_get_total_ids();
  /**
 * @test Test function for set_get_total_ids
 * @pre given correct inputs without setting the total ids to any number
 * @post Output==OK
 */
  void test2_set_get_total_ids();
  
   /**
 * @test Test function for set_has_id
 * @pre pointer to set=NULL
 * @post Output==FALSE
 */
  void test1_set_has_id();
   /**
 * @test Test function for set_has_id
 * @pre given correct inputs adding a correct id and calling function
 * @post Output==TRUE
 */
  void test2_set_has_id();
   /**
 * @test Test function for set_has_id
 * @pre given correct inputs adding a correct id and calling function but with another number
 * @post Output==FALSE
 */
  void test3_set_has_id();
   /**
 * @test Test function for set_has_id
 * @pre calling function to search for a negative number
 * @post Output==FALSE
 */
  void test4_set_has_id(); 
  
  /**
 * @test Test function for set_find_object_by_id
 * @pre pointer to set=NULL
 * @post Output==NO_ID
 */
  void test1_set_find_object_by_id();
  /**
 * @test Test function for set_find_object_by_id
 * @pre given correct inputs and creating a correct id then finding id index
 * @post Output!=NO_ID
 */
  void test2_set_find_object_by_id();
  /**
 * @test Test function for set_find_object_by_id
 * @pre given correct inputs and creating a correct id then finding a negative id index
 * @post Output==NO_ID
 */
  void test3_set_find_object_by_id();
  /**
 * @test Test function for set_find_object_by_id
 * @pre given correct inputs and creating a correct id then finding a completly different id
 * @post Output==FALSE
 */
  void test4_set_find_object_by_id(); 
   /**
 * @test Test function for set_is_empty
 * @pre pointer to set=NULL
 * @post Output==FALSE
 */
  void test1_set_is_empty();
   /**
 * @test Test function for set_is_empty
 * @pre given correct inputs and not adding any id
 * @post Output==TRUE
 */
  void test2_set_is_empty();
   /**
 * @test Test function for set_is_empty
 * @pre given correct inputs and adding an id
 * @post Output==FALSE
 */
  void test3_set_is_empty();  
  /**
 * @test Test function for set_is_full
 * @pre pointer to set=NULL
 * @post Output==FALSE
 */
  void test1_set_is_full();
  /**
 * @test Test function for set_is_full
 * @pre setting total ids to 1000 and calling function
 * @post Output==TRUE
 */
  void test2_set_is_full();
  /**
 * @test Test function for set_is_full
 * @pre setting total ids to 100 and calling function
 * @post Output==TRUE
 */
  void test3_set_is_full();
  /**
 * @test Test function for set_is_full
 * @pre setting total ids to 50 and calling function
 * @post Output==FALSE
 */
  void test4_set_is_full();  
   /**
 * @test Test function for set_print
 * @pre pointer to set=NULL
 * @post Output==ERROR
 */
  void test1_set_print();
   /**
 * @test Test function for set_print
 * @pre given NULL file
 * @post Output==ERROR
 */
  void test2_set_print();
   /**
 * @test Test function for set_print
 * @pre given correct inputs and calling function
 * @post Output==OK
 */
  void test3_set_print();
   /**
 * @test Test function for set_get_ids
 * @pre pointer to set=NULL
 * @post Output==NULL
 */
  void test1_set_get_ids();
   /**
 * @test Test function for set_get_ids
 * @pre not adding any id and calling function
 * @post Output==NULL
 */
  void test2_set_get_ids();

#endif
