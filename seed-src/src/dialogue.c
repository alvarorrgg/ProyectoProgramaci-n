/** 
 * @brief Ejecuta una interacción entre el usuario y el juego
 * 
 * @file dialogue.c
 * @author Álvaro Rodríguez
 * @version 2.0 
 * @date 22-04-2021
 * @copyright GNU Public License
 */
#include "dialogue.h"

/**
 * @brief Define la estructura del Dialogo
 * 
 * Estructura de Dialogo
 */

struct _Dialogue
{
    int num_tries; /*!< Numero de intentos */
    char interaction[MAX_INTERACTION][MAX_CHARS_DIALOGUE]; /*!< Interacciones del dialogo */
    int num_dialogues; /*!< Numero de dialogos */
    int choose_dialogue; /*!< Numero de elecciones del dialogo */
    T_Command last_command; /*!< Tipo de dato command */
};

Dialogue* dialogue_new(){
  Dialogue * new_dialogue =NULL;
  int i = 0;
  new_dialogue=(Dialogue *) malloc(sizeof(Dialogue));
  if(!new_dialogue) return NULL;
  new_dialogue->num_tries=-2;
  for(i=0;i<MAX_INTERACTION;i++){
    new_dialogue->interaction[i][0]='\0';
  }
  new_dialogue->num_dialogues=0;
  new_dialogue->last_command=NO_CMD;
  new_dialogue->choose_dialogue=0;
  return new_dialogue;
}

STATUS dialogue_destroy(Dialogue* d){
    if(!d) return ERROR;
    free(d);
    return OK;
}

STATUS dialogue_set_num_tries(Dialogue *d,int new_tries){
    if(!d || new_tries<0) return ERROR;
    d->num_tries=new_tries;
    return OK;
}

int dialogue_get_num_tries(Dialogue *d){
    if(!d) return -1;
    return d->num_tries;
}

STATUS dialogue_set_num_dialogues(Dialogue *d,int new_dialogues){
    if(!d || new_dialogues<0) return ERROR;
    d->num_dialogues=new_dialogues;
    return OK;
}

int dialogue_get_num_dialogues(Dialogue *d){
    if(!d) return -1;
    return d->num_dialogues;
}

STATUS dialogue_set_choose_dialogue(Dialogue *d,int choose_dialogue){
    if(!d || choose_dialogue<0) return ERROR;
    d->choose_dialogue=choose_dialogue;
    return OK;
}

int dialogue_get_choose_dialogue(Dialogue *d){
    if(!d) return -1;
    return d->choose_dialogue;
}

STATUS dialogue_set_interaction(Dialogue *d,char *new_interaction){
    if(!d || !new_interaction) return ERROR;
    strcpy(d->interaction[d->num_dialogues],new_interaction);
    d->interaction[d->num_dialogues][strlen(new_interaction)]='\0';
    d->num_dialogues++;
    return OK;
}

char* dialogue_get_interaction(Dialogue *d,int index){
    if(!d) return NULL;
    return d->interaction[index];
}

T_Command dialogue_get_last_command(Dialogue *d){
    if(!d) return NO_CMD;
    return d->last_command;
}

STATUS dialogue_set_last_command(Dialogue *d, T_Command cmd){
    if( d==NULL || cmd == NO_CMD) return ERROR;
     d->last_command=cmd;
    return OK;
}
/*Funcionamiento de esta funcion: 
Esta es la funcion principal del modulo dialogue, en esta funcion es donde se lee el ultimo comando utilizado y se decide que mostrar en funcion de este comando.
Para empezar se hace unas pequeñas condiciones para estipular si en caso de error, si el jugador ha usado el comado varias veces,
Una vez se tiene esto en cuenta simplemente se busca el ultimo comando utilizado y se adapta la respuesta en funcion de este comando.
Se pueden ver varios numeros "que parecen" aleatorios por toda la funcion, estos son los numeros que ocupa cada comando en la estructura de datos.*/
STATUS dialogue_change_interaction(Dialogue *d, Command *c, Player *p){
    if(!d || !c) return ERROR;
    if(command_get_cmd(c)==UNKNOWN){
        if(d->num_tries==-1) d->num_tries=0;
        dialogue_set_interaction(d,"Ey Ese comando no exite prueba otro");
        return OK;
    }
    if(command_get_cmd(c)==d->last_command && command_get_status(c)==ERROR){
        if(d->num_tries==2){ 
        }
        else{
        d->num_tries++;
        }
    }
    else if(command_get_status(c)==ERROR){
        d->num_tries=0;
    }
    else{
        d->num_tries=0;
    }
    if(command_get_cmd(c)==TAKE){
        if(command_get_status(c)==OK){
            dialogue_set_choose_dialogue(d,0);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        else{
            dialogue_set_choose_dialogue(d,1+dialogue_get_num_tries(d));
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
     }
    if(command_get_cmd(c)==DROP){
        if(command_get_status(c)==OK){
            dialogue_set_choose_dialogue(d,4);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        else{
            dialogue_set_choose_dialogue(d,5+dialogue_get_num_tries(d));
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;

        }
    }
    if(command_get_cmd(c)==MOVE){
     if(command_get_status(c)==OK){
         if(strcmp(command_get_arg(c),"south")==0 || strcmp(command_get_arg(c),"s")==0){
             dialogue_set_choose_dialogue(d,8);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
         }
         else if(strcmp(command_get_arg(c),"north")==0 || strcmp(command_get_arg(c),"n")==0){
             dialogue_set_choose_dialogue(d,9);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
         }
         else if (strcmp(command_get_arg(c),"east")==0 || strcmp(command_get_arg(c),"e")==0){
             if(player_get_location(p)==27){
                 dialogue_set_choose_dialogue(d,45);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
             }
             else{
             dialogue_set_choose_dialogue(d,10);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
             }
         }
         else if(strcmp(command_get_arg(c),"west")==0 || strcmp(command_get_arg(c),"w")==0){
             dialogue_set_choose_dialogue(d,11);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
         }
         else if(strcmp(command_get_arg(c),"up")==0 || strcmp(command_get_arg(c),"u")==0){
             dialogue_set_choose_dialogue(d,12);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
         }
         else if(strcmp(command_get_arg(c),"down")==0 || strcmp(command_get_arg(c),"d")==0){
             dialogue_set_choose_dialogue(d,13);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
         }
     }
     else{
         dialogue_set_choose_dialogue(d,14+dialogue_get_num_tries(d));
        dialogue_set_last_command(d,command_get_cmd(c));
        return OK;
     }
    }
    if(command_get_cmd(c)==INSPECT){
        if(command_get_status(c)==OK){
            dialogue_set_choose_dialogue(d,17);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        else{
            dialogue_set_choose_dialogue(d,18+dialogue_get_num_tries(d));
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
    }

    if(command_get_cmd(c)==TURNON){
        if(command_get_status(c)==OK){
            dialogue_set_choose_dialogue(d,21);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        else{
            dialogue_set_choose_dialogue(d,22+dialogue_get_num_tries(d));
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
    }
    if(command_get_cmd(c)==TURNOFF){
        if(command_get_status(c)==OK){
            dialogue_set_choose_dialogue(d,25);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        else{
            dialogue_set_choose_dialogue(d,26+dialogue_get_num_tries(d));
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
    }
        if(command_get_cmd(c)==OPEN_LINK){
            if(command_get_status(c)==OK){
                dialogue_set_choose_dialogue(d,29);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
            else{
                dialogue_set_choose_dialogue(d,30+dialogue_get_num_tries(d));
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
        }
        if(command_get_cmd(c)==SAVE){
            if(command_get_status(c)==OK){
                dialogue_set_choose_dialogue(d,33);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
            else{
                dialogue_set_choose_dialogue(d,34);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
        }
        if(command_get_cmd(c)==LOAD){
            if(command_get_status(c)==OK){
                dialogue_set_choose_dialogue(d,35);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
            else{
                dialogue_set_choose_dialogue(d,36);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
        }
        if(command_get_cmd(c)==BUILD){
            if(command_get_status(c)==OK){
                dialogue_set_choose_dialogue(d,37);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
            else{
                dialogue_set_choose_dialogue(d,38+dialogue_get_num_tries(d));
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
        }
        if(command_get_cmd(c)==USE){
            if(command_get_status(c)==OK){
                dialogue_set_choose_dialogue(d,41);
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
            else{
                dialogue_set_choose_dialogue(d,42+dialogue_get_num_tries(d));
                dialogue_set_last_command(d,command_get_cmd(c));
                return OK;
            }
        }
    return OK;

}