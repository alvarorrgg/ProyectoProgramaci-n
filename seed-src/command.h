/**
 * @brief Implementa el intérprete de comandos
 *
 * @file command.h
 * @author Álvaro Rodríguez
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H
#define N_CMDT 2
#define N_CMD 10
#include "types.h"

typedef struct _Command Command;

/**
 * @brief Tipos de comandos
 *
 * Se declaran dos variables referentes al tipo de comando
 */
typedef enum enum_CmdType {
  CMDS,		/*!< Comando ... */
  CMDL
  } T_CmdType;	/*!< Comando ... */

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
  BACK,		/*!< BACK = 3*/
  TAKE,		/*!< TAKE = 4*/
  DROP,		/*!< DROP = 5*/
  ROLL,		/*!< ROLL = 6*/
  RIGHT,		/*!< RIGHT = 7*/
  LEFT			/*!< LEFT = 8*/
  } T_Command;	
/**
 * @brief obtiene la entrada del usuario
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
 * @brief inicializa la estructura de datos command
 *
 * command_init sirve para inicializar la estructura de datos
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @return el comando inicializado.
 */
Command* command_init();

/**
 * @brief destruye command
 *
 * command_destroy destruye la estructura
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @return STATUS segun si se ha hecho todo de manera correcta o no
 */
STATUS command_destroy(Command *command);
/**
 * @brief cambia el estado del comando
 *
 * command_set_status sirve para cambiar el estado
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @param la estructura de datos command
 * @param el nuevo estado
 * @return STATUS segun si se ha hecho todo de manera correcta o no
 */
STATUS command_set_status(Command *command,STATUS st);
/**
 * @brief obtiene el estado
 *
 * command_get_status sirve para obtener el estado
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @param la estructura de datos command
 * @return STATUS del ultimo comando.
 */
STATUS command_get_status(Command *command);
/**
 * @brief cambia el ultimo comando
 *
 * command_set_cmd sirve para cambiar el comando
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @param  la estructura de datos command y T_command el comando introducido por el usuario.
 * @return Status según si se ha cambiado correctamente.
 */
STATUS command_set_cmd(Command *command,T_Command cmd);
/**
 * @brief obtiene el ultimo comando
 *
 * command_get_cmd sirve para saber que comando a introducido el usuario
 *
 * @date 13-01-2020
 * @author Álvaro Rodríguez
 * @param  la estructura de datos command 
 * @param T_command el comando introducido por el usuario.
 * @return T_Command, el ultimo comando.
 */
T_Command command_get_cmd(Command *command);
#endif
