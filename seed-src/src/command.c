/** 
 * @brief Implementa el intérprete de comandos
 * 
 * @file command.c
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 13-01-2020 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "command.h"


#define CMD_LENGHT 30
/* @brief Convierte un comando introducido por el usuario a una cadena de caracteres*/
char *cmd_to_str[N_CMD][N_CMDT] = {
    {"", "No command"}, /** !< NO COMMAND*/
    {"", "Unknown"},	/** !< UNKNOWN*/
    {"e", "Exit"},	/** !< e <=> exit*/
    {"n", "Next"},	/** !< n <=> next*/
    {"b", "Back"},	/** !< b <=> back*/
    {"t", "Take"},	/** !< t <=> take*/
    {"d", "Drop"},	/** !< d <=> drop*/
    {"rl", "Roll"},	/** !< rl <=> roll*/
    {"l", "Left"},	/** !< l <=> left*/
    {"r", "Right"}, /** !< r <=> right*/
    {"m", "Move"}};	/** !< m <=> move*/


struct _Command {
  T_Command cmd; /** !< comando*/
  STATUS st;    /**  !< status del comando*/
};
/*EJEMPLO*/
Command* command_init(){
  Command * new_command =NULL;
	  
  new_command=(Command *) malloc(sizeof(Command));
	  
  if (new_command==NULL) return NULL;
	  
  new_command->cmd = NO_CMD;
  new_command->st = ERROR;

  return new_command;
}

STATUS command_destroy(Command *command){
  if(!command) return ERROR;
	
  free(command);
  return OK;
}

STATUS command_set_status(Command *command,STATUS st){

  if(command==NULL || (st!=0 && st!=1))return ERROR;

  command->st = st;
  return OK;
}

STATUS command_get_status(Command *command){
  if(!command) return ERROR;
  return command->st;
}

STATUS command_set_cmd(Command *command,T_Command cmd){
  if(command==NULL ) return ERROR;
  command->cmd = cmd;
  return OK;
}

T_Command command_get_cmd(Command *command){
  if(command==NULL) return ERROR;
  return command->cmd;
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
     if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL])) /*compara el input convirtiendolo con la función cmd_to_str con los comandos posibles*/
     {
       cmd = i + NO_CMD; /*iguala cmd al comando detectado*/
     }
     else
     {
       i++;
     }
    }
  }
  return cmd;
}
