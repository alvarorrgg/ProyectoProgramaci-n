/** 
 * @brief Implementa el intérprete de comandos
 * 
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 13-01-2020 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30
/*brief Convierte un comando introducido por el usuario a una cadena de caracteres*/
char *cmd_to_str[N_CMD][N_CMDT] = {
  {"", "No command"}, 
  {"", "Unknown"}, 
  {"e","Exit"}, 
  {"n", "Next"}, 
  {"b","Back"}};

T_Command get_user_input(){
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i= UNKNOWN - NO_CMD + 1;
	
  if (scanf("%s",  input) > 0){
    cmd = UNKNOWN;
    while(cmd == UNKNOWN && i < N_CMD){
      if (!strcasecmp( input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL])){
        cmd = i + NO_CMD;
      }
      else{
        i++;
      }
    }
  }
  return cmd;
}
