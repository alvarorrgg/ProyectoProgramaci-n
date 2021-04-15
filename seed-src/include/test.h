/**
 * @brief Archivo de cabecera test.h en el se definen utiles para el funcionamiento de los modulos tests.
 *
 * @file test.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR
#define KRED  "\x1B[31m" /*!<Color rojo*/
#define KGRN  "\x1B[32m" /*!<Color verde*/
#define KYEL  "\x1B[33m" /*!<Color amarillo*/
#define KCYN  "\x1B[36m" /*!<Color cian*/
#define RESET "\033[0m" /*!<Reset*/
#else
#define KRED
#define KGRN
#define KYEL
#define KCYN
#define RESET
#endif

 /**
 * @test Print test result
 * @pre resultado
 * @post Output==OK or FAIL
 */
#define PRINT_TEST_RESULT(x) do{					\
    __test_counter++;							\
    __pass = (x);							\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;	\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n",	\
	   __FILE__, __LINE__ , __FUNCTION__,				\
	   ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET));	\
  } while (0) 

/**
 * @test Print passed percemtage
 * @pre resultado
 * @post Output==%
 */
#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))
      
static int __test_counter = 0;
static int __test_passed  = 0;
static int __pass = 0;

#endif
