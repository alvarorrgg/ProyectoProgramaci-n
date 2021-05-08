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
#define N_CMD 15 /*!<Numero de comandos*/
#define CMD_LENGHT 30 /*!<Numero maximo de letras de cada cmando*/
#define N_INFOS 2 /*!<Numero de informacion*/
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
  MOVE,   /*!< MOVE = 5*/
  INSPECT,  /*!< INSPECT = 6*/
  TURNON, /*!< TURNON = 7*/
  TURNOFF, /*!< TURNOFF = 8*/
  OPEN_LINK, /*!< OPEN = 9 */
  SAVE, /*!< SAVE = 10 */
  LOAD, /*!< LOAD = 11 */
  BUILD, /*!< BUILD = 12 */
  USE /*!< USE = 13 */
  } T_Command;	
/**
 * @brief obtiene la entrada del usuario.
 *
 * command_get_user_command sirve para saber que comando a introducido el usuario
 *
 * @date 13-01-2020
 * @author Profesores PPROG
 *
 * @return T_Command, el comando introducido por el usuario.
 */
T_Command command_get_user_command();
/**
 * @brief obtiene la entrada del usuario.
 *
 * command_get_user_info sirve para saber la parte del medio del comando
 *
 * @date 03-05-2021
 * @author Profesores PPROG
 *
 * @return char, el comando introducido por el usuario.
 */
char** command_get_user_info();

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
 * @return char, la instrucción que sigue al comando
 */
char* command_get_arg(Command *command);
/**
 * @brief cambia la parte del objeto del comando
 *
 * command_set_obj sirve para cambiar la parte del objeto del comando
 *
 * @date 03-05-2021
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command
 * @param  obj donde se almacena el comando
 *
 * @return STATUS OK o ERROR segun si se ha hecho todo correctamente.
 */
STATUS command_set_obj(Command *command,char *obj);
/**
 * @brief obtiene el objeto del comando
 *
 * command_get_obj sirve para saber que instruccion sigue al comando
 *
 * @date 03-05-2021
 * @author Álvaro Rodríguez
 *
 * @param  command estructura de datos command 
 *
 * @return char, la instrucción que sigue al comando
 */
char* command_get_obj(Command *command);
#endif
