/**
 * @brief Implementa el intérprete de comandos
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 5

/**
 * @brief Tipos de comandos
 *
 * Se declaran dos variables referentes al tipo de comando
 */
typedef enum enum_CmdType {
  CMDS,		/*!< Comando ... */
  CMDL} T_CmdType;	/*!< Comando ... */

/**
 * @brief Comandos
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum enum_Command {
  NO_CMD = -1,		/*!< NO_CMD = -1*/
  UNKNOWN,		/*!< UNKNOWN = 0*/
  EXIT,		/*!< EXIT = 1*/
  NEXT,		/*!< NEXT = 2*/
  BACK} T_Command;	/*!< BACK = 3*/
/**
 * @brief obtiene la entrada del usuario
 *
 * get_user_imput sirve para saber que comando a introducido el usuario
 *
 * @date 13-01-2020
 * @author Profesores PPROG
 *
 * @return cmd el comando introducido por el jugador
 */
T_Command get_user_input();

#endif
