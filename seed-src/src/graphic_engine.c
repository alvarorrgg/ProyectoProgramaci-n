/**
 * @brief Define un motor gráfico textual
 *
 * @file graphic_engine.c
 * @author Profesores PPROG , Gonzalo Martin, Alexandru Marius
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"
#include "command.h"
#include "link.h"
#include "dialogue.h"

#define MAX_CHARS1 44 /*!<Numero maximo de caracteres que se pueden escribir en cada linea del espacio*/
#define MAX_CHARS2 3  /*!<Numero maximo de caracteres que van a tener los links*/
#define MAX_CHARS3 7  /*!<Numero maximo de caracteres que van a tener los links + las flechas*/

/**
 * @brief carácteristicas del motor gráfico
 *
 * Contiene la información necesaria del motor gráfico
 */
struct _Graphic_engine
{
  Area *map;      /*!< Donde se representa el mapa de la oca */
  Area *descript; /*!< Descripción de los objetos y información importante */
  Area *banner;   /*!< The game of the Goose */
  Area *help;     /*!< Donde se muestran los posibles comandos */
  Area *feedback; /*!< Donde se muestra los ultimos comandos utilizados */
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (!ge)
    return NULL;

  ge->map = screen_area_init(1, 1, 118, 35);       /*mapa de la oca*/
  ge->descript = screen_area_init(120, 1, 29, 35); /*parte donde se pintan las jugadas y tal*/
  ge->banner = screen_area_init(28, 37, 23, 1);   /*"The game of the Goose"*/
  ge->help = screen_area_init(1, 38, 78, 2);      /*The----left or l*/
  ge->feedback = screen_area_init(1, 41, 78, 3);  /*comandos*/

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}
/*Hemos implementado el graphic enginge de manera que los objetos puedan tener el nombre que se quiera(dentro de unos requisitos) y el programa no se vea afectado por estos cambios*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  int i = 0;
  int sum = 0;
  int num_objects = 0;
  Id id_act = NO_ID, obj_loc = NO_ID;
  Id *id_objetos;
  Space *space_act = NULL;
  char **gdesc;
  char obj[MAX_OBJECTS][MAX_CHARS1];
  char str[MAX_CHARS];
  char espacios_back[MAX_CHARS1], espacios_act[MAX_CHARS1], espacios_next[MAX_CHARS1]; /*Servira para llevar recuento de los objetos en un espacio*/
  T_Command last_cmd = UNKNOWN;
  Link *link1 = NULL;
  Link *link2 = NULL;
  char id1[MAX_CHARS2], id2[MAX_CHARS2], id_to1[MAX_CHARS3], id_to2[MAX_CHARS3];
  extern char *cmd_to_str[N_CMD][N_CMDT]; /*Variable traida del modulo command para el tratado de comandos*/
  memset(espacios_back, 0, MAX_CHARS1);
  memset(espacios_act, 0, MAX_CHARS1);
  memset(espacios_next, 0, MAX_CHARS1);
  num_objects = game_get_total_objects(game);
  /* Pintar en el área del mapa */
  screen_area_clear(ge->map);
  sprintf(str, "#####################################################################################################################");
  screen_area_puts(ge->map, str);
  sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
  sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
  sprintf(str, " ");
  screen_area_puts(ge->map, str);
  sprintf(str, " ");
  screen_area_puts(ge->map, str);

  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
       /*   if (strcmp(id_to1, " -1") == 0 || link_get_type(game_get_link(game,link_get_id(link1)))==CLOSE)
        strcpy(id_to1, "      ");
      else
        strcat(id_to1, " <--");
      sprintf(id1, "%ld", link_get_id(link1));
      if (strcmp(id1, "-1") == 0 || link_get_type(game_get_link(game,link_get_id(link1)))==CLOSE)
        strcpy(id1, "  ");

      link2 = space_get_east(space_back);

      sprintf(id_to2, "%ld", link_get_id_to(link2));
      if (strcmp(id_to2, "-1") == 0 || link_get_type(game_get_link(game,link_get_id(link2)))==CLOSE)
        strcpy(id_to2, "      ");

      else
      {
        sprintf(id_to1, "%ld", link_get_id_to(link2));
        strcpy(id_to2, "--> ");
        strcat(id_to2, id_to1);
        strcpy(id_to1, "      ");
      }
      sprintf(id2, "%ld", link_get_id(link2));*/
    sum = 0;
    printf("%i",num_objects);
    for (i = 1; i <= num_objects + 1; i++)
    {
      if (space_has_object_id(space_act, i)){
        printf("cont\n%i\n",i);
       if(player_has_object(game_get_player(game),object_get_dependency(game_get_object_by_id(game,i))) || object_get_dependency(game_get_object_by_id(game,i))==-1) {
         printf("dep\n%li\n",object_get_dependency(game_get_object_by_id(game,i)));
        strcpy(obj[i], object_get_name(game_get_object(game, i-1)));
       }
       else{
         strcpy(obj[i], "");
       }
    }
      else
        strcpy(obj[i], "");
    }
    for (i = 1; i <= num_objects + 1; i++)
    {
      sum = sum + strlen(obj[i]);
      if (strlen(obj[i]) != 0)
        sum = sum + 1;
    }
    if (sum > MAX_CHARS1)
    {
      for (i = 1; i <= num_objects + 1; i++)
      {
        strcpy(espacios_act, obj[i]);
        if (strlen(espacios_act) != 0)
          break;
      }

      strcat(espacios_act, "...");
      while (strlen(espacios_act) < MAX_CHARS1)
        strcat(espacios_act, " ");
    }
    else
    {
      for (i = 1; i <= num_objects + 1; i++)
      {
        strcat(espacios_act, obj[i]);
        if (strlen(obj[i]) != 0)
          strcat(espacios_act, " ");
      }
    }
    while (strlen(espacios_act) < MAX_CHARS1)
      strcat(espacios_act, " ");

    if (id_act != NO_ID)
    {
      gdesc = space_get_gdesc(space_act);
      link1 = space_get_west(space_act);
      strcpy(id_to1, " <----");
      if (strcmp(id_to1, " -1") == 0 || link_get_type(game_get_link(game,link_get_id(link1)))==CLOSE)
        strcpy(id_to1, "      ");
      else
        
      sprintf(id1, "%ld", link_get_id(link1));
      if (strcmp(id1, "-1") == 0 || link_get_type(game_get_link(game,link_get_id(link1)))==CLOSE)
        strcpy(id1, "  ");

      link2 = space_get_east(space_act);

      sprintf(id_to2, "%ld", link_get_id_to(link2));
      if (strcmp(id_to2, "-1") == 0 || link_get_type(game_get_link(game,link_get_id(link2)))==CLOSE)
        strcpy(id_to2, "      ");

      else
      {
        sprintf(id_to1, "%ld", link_get_id_to(link2));
        strcpy(id_to2, "----> ");

        strcpy(id_to1, "      ");
      }
      sprintf(id2, "%ld", link_get_id(link2));
      if(space_get_ilumination(space_act)==TRUE || game_player_hasIluminated_object(game)==TRUE){
        if (strcmp(id2, "-1") == 0 || link_get_type(game_get_link(game,link_get_id(link2)))==CLOSE)
        strcpy(id2, "  ");
      sprintf(str, "###########################       +-------------------------------------------+         ##############################");
      screen_area_puts(ge->map, str);

        sprintf(str, "###########################       |                   UwU                      |        ##############################");
      screen_area_puts(ge->map, str);
       sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################"); 
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str,"########################### %s|                                            |%s  ##############################", id_to1, id_to2);
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                  %s                   |        ##############################", gdesc[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                  %s                   |        ##############################", gdesc[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                  %s                   |        ##############################", gdesc[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      
      sprintf(str, "###########################       |%s|        ##############################", espacios_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       +--------------------------------------------+        ##############################");
      screen_area_puts(ge->map, str);


      }
      
     else if(space_get_ilumination(space_act)==FALSE && game_player_hasIluminated_object(game)==FALSE){
      sprintf(str, "###########################        +-------------------------------------------+        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
       sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################"); 
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str,"###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      
      sprintf(str, "###########################       |                                            |        ##############################");
      screen_area_puts(ge->map, str);
      sprintf(str, "###########################       +--------------------------------------------+        ##############################");
      screen_area_puts(ge->map, str);

      }
  sprintf(str, " ");
  screen_area_puts(ge->map, str);
  sprintf(str, " ");
  screen_area_puts(ge->map, str);
  sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
  sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
  sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
   sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
   sprintf(str, "######################################################################################################################");
  screen_area_puts(ge->map, str);
      
    }
  }

  /* Pinta en el área de la despcripción */
  screen_area_clear(ge->descript);
  sprintf(str, "  Object locations: ");
  /*Comprobamos que el objeto no esta en el player y en caso de no estarlo mostramos donde se encuentra*/
  for (i = 0; i < MAX_OBJECTS - 1; i++)
  {
    if ((obj_loc = game_get_object_location(game, i)) != NO_ID)
    {
      sprintf(str, "  %s: %d", object_get_name(game_get_object(game, i - 1)), (int)obj_loc);
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /*Mostramos el ultimo roll del dado 0 en el primer caso*/
  if ((int)die_get_last_roll(game_get_die(game)) == -1)
    sprintf(str, "Last roll of dice: 0");
  else
    sprintf(str, "Last roll of dice: %d", (int)die_get_last_roll(game_get_die(game)));
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  if (inventory_get_number_of_objects(player_get_inventory(game_get_player(game))) == 0)
  {
    sprintf(str, "Player %s has no objects", player_get_name(game_get_player(game)));
    screen_area_puts(ge->descript, str);
  }
  else
  {
    sprintf(str, "This is the inventory of the player %s: ", player_get_name(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    id_objetos = inventory_get_inventory(player_get_inventory(game_get_player(game)));
    for (i = 0; i < inventory_get_number_of_objects(player_get_inventory(game_get_player(game))); i++)
    {
      sprintf(str, "                                   %i:%s", i + 1, object_get_name(game_get_object(game, id_objetos[i] - 1)));
      screen_area_puts(ge->descript, str);
    }
  }

  
  if (strlen(game_get_last_descripcion(game)) != 0)
  {
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "%s", game_get_last_descripcion(game));
    screen_area_puts(ge->descript, str);
  }
  if(dialogue_get_num_tries(game_get_dialogue(game))!=-1){
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    sprintf(str, "%s", dialogue_get_interaction(game_get_dialogue(game)));
    screen_area_puts(ge->descript, str);
  }
  /* Pinta en el área del banner */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Pinta en el área de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "next or n, back or b, exit or e, take or t, drop or d,roll or rl,left or l,right or r,move or m, inspect or i, turnon or ton, turnoff or toff"); /*Se escriben los comandos posibles*/
  screen_area_puts(ge->help, str);

  /* Pinta en el área de comentarios */
  /*Almacenamos el comando, comprobamos que no es NoCommand, obtenemos el estatus y llamamos a la función cmd_to_str para pintar el comando con su estatus*/
  last_cmd = command_get_cmd(game_get_command(game));
  if (last_cmd != -1)
  {
     if (command_get_status(game_get_command(game)) != 1)
    {
      if(strlen(command_get_arg(game_get_command(game)))==1){
      sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    }
      else{
        sprintf(str, " %s (%s) %s: ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], command_get_arg(game_get_command(game)));

      }
    }
    else{
      if(strlen(command_get_arg(game_get_command(game)))==1){
      sprintf(str, " %s (%s): OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);

    }
      else{
        sprintf(str, " %s (%s) %s: OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], command_get_arg(game_get_command(game)));

      }
      
    
    }
    screen_area_puts(ge->feedback, str);
  }
  /* Volcarlo en la terminal */
  screen_paint();
  printf("prompt:> ");
}
