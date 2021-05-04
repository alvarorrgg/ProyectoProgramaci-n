/** 
 * @brief Implementa el intérprete de comandos, leer comandos, conversión y almacenamiento de estos.
 * 
 * @file command.c
 * @author Álvaro Rodríguez, Profesores PPRog, Alberto Vicente
 * @version 2.0 
 * @date 01-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"
#include "game.h"



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
    {"op", "Open"}, /** !< op <=> open*/
    {"sv" , "Save"},	/** !< sv <=> save*/
    {"ld" , "Load"},	/** !< ld <=> load*/
    {"bd" , "Build"},	/** !< bd <=> build*/
    {"u" , "Use"},	/** !< u <=> use*/
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
  char obj[CMD_LENGHT];     /*!< Necesario para el comando open*/
};


Command* command_init(){
  Command * new_command =NULL;
	  
  new_command=(Command *) malloc(sizeof(Command));	  
  if (!new_command) return NULL;
	  
  new_command->cmd = NO_CMD;
  new_command->st = ERROR;
  new_command->arg[0] = (char)0;
  new_command->obj[0] = (char)0;

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

STATUS command_set_obj(Command *command,char *obj){
  if(!command || !obj) return ERROR;
  strcpy(command->obj, obj);
  return OK;
}

char* command_get_obj(Command *command){
  if(!command) return NULL;
  return command->obj;
}

T_Command command_get_user_command()
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

char** command_get_user_info(){
  char **info=NULL;
  char aux[WORD_SIZE];
  char *tok=NULL;
  int j=0;
  info=(char**) malloc( N_INFOS*sizeof(char*));
  info[0]=(char*) malloc( WORD_SIZE*sizeof(char));
  info[1]=(char*) malloc( WORD_SIZE*sizeof(char));
  
  if(fgets(aux, WORD_SIZE, stdin)!=NULL){
  for (j = 0; aux[j + 1] != (char)0; j++) aux[j] = aux[j + 1]; 
  j--;
  aux[j] =(char)0;
  tok=strtok(aux," ");
  strcpy(info[0],tok);
  tok=strtok(NULL," ");
  tok=strtok(NULL," ");
  if(tok!=NULL){
  strcpy(info[1],tok);
  return info;
  }
  else{
    info[1][0]='\0';
    return info;
  }
  }
  info[0][0]='\0';
  info[1][0]='\0';
  return info;
}


