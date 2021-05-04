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


struct _Dialogue
{
    int num_tries;
    char interaction[MAX_INTERACTION];
    T_Command last_command;
};

Dialogue* dialogue_new(){
  Dialogue * new_dialogue =NULL;
  
  new_dialogue=(Dialogue *) malloc(sizeof(Dialogue));
  if(!new_dialogue) return NULL;
  new_dialogue->num_tries=-1;
  new_dialogue->interaction[0]='\0';
  new_dialogue->last_command=NO_CMD;
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

STATUS dialogue_set_interaction(Dialogue *d,char *new_interaction){
    if(!d || !new_interaction) return ERROR;
    strcpy(d->interaction,new_interaction);
    return OK;
}

char* dialogue_get_interaction(Dialogue *d){
    if(!d) return NULL;
    return d->interaction;
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

STATUS dialogue_change_interaction(Dialogue *d, Command *c, Player *p){
    char str[MAX_INTERACTION];
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
    else{
        d->num_tries=0;
    }
    if(command_get_cmd(c)==TAKE){
        if(command_get_status(c)==OK){
            sprintf(str,"Genial, ahora tienes en tu inventario el objeto: %s",command_get_arg(c));
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==0){
            sprintf(str,"Estas seguro de que ese objeto esta en la casilla en la que estas?");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==1){
            sprintf(str,"Deja de intentarlo, no estas cerca del objeto");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==2){
            sprintf(str,"take take y tanto take...QUE NO FUNCIONA PESADO!!");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
     }
    if(command_get_cmd(c)==DROP){
        if(command_get_status(c)==OK){
            sprintf(str,"uhuhuhu, muy bien, soltastes el objeto %s y todos los que dependían de el",command_get_arg(c));
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==0){
            sprintf(str,"Creo que el objeto que buscas no esta en tu inventario");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==1){
            sprintf(str,"Si miras a la derecha veras que ahi esta tu inventario y que no tienes ese objeto en el");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==2){
            sprintf(str,"En vez de hacer drop pq no pruebas otro comando que si funcione");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }

    }
    if(command_get_cmd(c)==ROLL){
        if(command_get_status(c)==OK){
            dialogue_set_interaction(d,"Muy bien, avanza las casillas que te marque el dado");
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }

    }
    if(command_get_cmd(c)==MOVE){
     if(command_get_status(c)==OK){
            sprintf(str,"Te has movido a la casilla: %li", player_get_location(p));
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==0){
            sprintf(str,"En esa direccion no exite un camino");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==1){
            sprintf(str,"Deja de insistir, no queremos que te caigas por un precipicio");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==2){
            sprintf(str,"Moverte no es la unica cosa que puedes hacer sabes?");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }

    }
    if(command_get_cmd(c)==INSPECT){
    if(command_get_status(c)==OK){
            sprintf(str,"Jejeje, estas hecho todo un inspector");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==0){
            sprintf(str,"Lo que inspeccionas no se encuentra ni en el espacio ni en tu inventario");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==1){
            sprintf(str,"Que te parece probar con inspect Space");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }
        if(d->num_tries==2){
            sprintf(str,"Tanto inspeccionar, te confundirán con el inspector gadchet");
            dialogue_set_interaction(d,str);
            dialogue_set_last_command(d,command_get_cmd(c));
            return OK;
        }

    }
    return OK;

}