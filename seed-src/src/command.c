/** 
 * @brief Implementa el intérprete de comandos, leer comandos, conversión y almacenamiento de estos.
 * 
 * @file command.c
 * @author Álvaro Rodríguez, Profesores PPRog
 * @version 2.0 
 * @date 01-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"

#define CMD_LENGHT 30 /*!<Numero maximo de letras de cada cmando*/

/**
 @brief tipo de comandos
 */
char *cmd_to_str[N_CMD][N_CMDT] = {
    {"", "No command"}, /** !< NO COMMAND*/
    {"", "Unknown"},	/** !< UNKNOWN*/
    {"e", "Exit"},	/** !< e <=> exit*/
    {"t", "Take"},	/** !< t <=> take*/
    {"d", "Drop"},	/** !< d <=> drop*/
    {"rl", "Roll"},	/** !< rl <=> roll*/
    {"m", "Move"}, /** !< m <=> move*/
    {"i" , "Inspect"},	/** !< i <=> inspect*/
    {"ton" , "Turnon"},	/** !< ton <=> turnon*/
    {"toff" , "Turnoff"},	/** !< toff<=> turnoff*/
    
    };

/**
 * @brief Define las partes del comando
 * 
 * Define todas las partes que tiene un comando
 */
struct _Command {

  T_Command cmd;             /*!< Parte principal del comando*/
  char arg[CMD_LENGHT];     /*!<Segunda parte del comando*/
  STATUS st;                /*!< Status del comando ERROR o OK segun si el comando se ha ejecutado bien o no*/
};


Command* command_init(){
  Command * new_command =NULL;
	  
  new_command=(Command *) malloc(sizeof(Command));	  
  if (!new_command) return NULL;
	  
  new_command->cmd = NO_CMD;
  new_command->st = ERROR;
  new_command->arg[0] = (char)0;

  return new_command;
}

STATUS command_destroy(Command *command){
  if(!command) return ERROR;
	
  free(command);
  return OK;
}

STATUS command_set_status(Command *command,STATUS st){

  if(!command || (st!=0 && st!=1))return ERROR;

  command->st = st;
  return OK;
}

STATUS command_get_status(Command *command){
  if(!command) return ERROR;
  return command->st;
}

STATUS command_set_cmd(Command *command,T_Command cmd){
  if(!command ) return ERROR;
  command->cmd = cmd;
  return OK;
}

T_Command command_get_cmd(Command *command){
  if(!command) return NO_CMD;
  return command->cmd;
}

STATUS command_set_arg(Command *command,char *arg){
  if(!command || !arg) return ERROR;
  strcpy(command->arg, arg);
  return OK;
}

char* command_get_arg(Command *command){
  if(!command) return NULL;
  return command->arg;
}

T_Command command_get_user_input()
{
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;
  if (scanf("%s", input) > 0){
  cmd = UNKNOWN;
   while (cmd == UNKNOWN && i < N_CMD)
   {
     if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))  cmd = i + NO_CMD; /*compara el input convirtiendolo con la función cmd_to_str con los comandos posibles e iguala cmd al comando detectado*/
     
     else i++; /*Busca el siguiente comando*/
     
    }
  }
  return cmd; /*Devuelve el comando, NO_COMMAND si no encuentra ningun comando*/
}
