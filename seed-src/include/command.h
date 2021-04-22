/**
 * @brief Archivo cabecera de command.c en el se encuentra definidas los datos y funciones de command.c
 *
 * @file command.h
 * @author Álvaro Rodríguez, Profesores PPRog
 * @version 2.0
 * @date 15-04-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2 /*!<Tipos de representación de los comandos*/
#define N_CMD 8 /*!<Numero de comandos*/

#include "types.h"
/**
 * @brief Estructura command
 *
 * contiene las partes de un comando
 */
typedef struct _Command Command;

/**
 * @brief Tipos de comandos
 *
 * Se declaran dos variables referentes al tipo de comando
 */
typedef enum enum_CmdType {
  CMDS,		/*!< CMDS=0 Cuerpo del comando de forma abreviada */
  CMDL			/*!< CMDL=1 Cuerpo del comando en su forma original */
  } T_CmdType;	

/**
 * @brief Comandos
 *
 * Da valores numéricos siguiendo un orden a las variables de la estructura
 */
typedef enum enum_Command {
  NO_CMD = -1,		/*!< NO_CMD = -1*/
  UNKNOWN,		/*!< UNKNOWN = 0*/
  EXIT,		/*!< EXIT = 1*/
  TAKE,		/*!< TAKE = 2*/
  DROP,		/*!< DROP = 3*/
  ROLL,		/*!< ROLL = 4*/
  INSPECT  /*!< INSPECT = 5*/
  } T_Command;	
/**
 * @brief obtiene la entrada del usuario.
 *
 * command_get_user_input sirve para saber que comando a introducido el usuario
 *
 * @date 13-01-2020
 * @author Profesores PPROG
 *
 * @return T_Command, el comando introducido por el usuario.
 */
T_Command command_get_user_input();

/**
 * @brief inicializa la estructura de datos command.
 *
 * command_init sirve para inicializar la estructura de datos
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @return Command, el comando inicializado.
 */
Command* command_init();

/**
 * @brief destruye command.
 *
 * command_destroy destruye la estructura
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param command el comando a destruir
 *
 * @return STATUS OK o ERROR segun si se ha hecho todo correctamente.
 */
STATUS command_destroy(Command *command);
/**
 * @brief cambia el estado del comando.
 *
 * command_set_status sirve para cambiar el estado.
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param command la estructura de datos command
 * @param st el nuevo estado
 *
 * @return STATUS OK o ERROR segun si se ha hecho todo correctamente.
 */
STATUS command_set_status(Command *command,STATUS st);
/**
 * @brief obtiene el estado.
 *
 * command_get_status sirve para obtener el estado
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param command estructura de datos command
 *
 * @return STATUS del ultimo comando.
 */
STATUS command_get_status(Command *command);
/**
 * @brief cambia el ultimo comando.
 *
 * command_set_cmd sirve para cambiar el comando.
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command
 * @param  cmd enumeración con valores de cada comando
 *
 * @return STATUS OK o ERROR segun si se ha hecho todo correctamente.
 */
STATUS command_set_cmd(Command *command,T_Command cmd);
/**
 * @brief obtiene el ultimo comando
 *
 * command_get_cmd sirve para saber que comando a introducido el usuario
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command 
 *
 * @return T_Command, el ultimo comando.
 */
T_Command command_get_cmd(Command *command);
/**
 * @brief cambia el cuerpo del comando
 *
 * command_set_arg sirve para cambiar la parte de final del comando
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command
 * @param  arg donde se almacena el comando
 *
 * @return STATUS OK o ERROR segun si se ha hecho todo correctamente.
 */
STATUS command_set_arg(Command *command,char *arg);
/**
 * @brief obtiene el cuerpo del comando
 *
 * command_get_arg sirve para saber que instruccion sigue al comando
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command 
 *
 * @return T_Command, la instrucción que sigue al comando
 */
char* command_get_arg(Command *command);
#endif
