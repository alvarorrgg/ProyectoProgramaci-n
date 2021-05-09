/** 
 * @brief Implementa el inicio del juego y obtiene los valores iniciales de data.dat
 * 
 * @file game_management.c
 * @author Álvaro Rodríguez, Alberto Vicente, Gonzalo Martin
 * @version 1.0 
 * @date 18-02-2021  
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_management.h"
#include "inventory.h"
#include "object.h"

STATUS game_management_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char descr[LEN_DES] = "";
  char detail_descr[LEN_DES] = "";
  char **gdesc = NULL;
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  BOOL ilumination;

  gdesc = (char **)malloc(3 * sizeof(char *));
  if (!gdesc)
    return ERROR;

  gdesc[0] = (char *)malloc(46 * sizeof(char));
  if (!gdesc[0])
    return ERROR;

  gdesc[1] = (char *)malloc(46 * sizeof(char));
  if (!gdesc[1])
    return ERROR;

  gdesc[2] = (char *)malloc(46* sizeof(char));
  if (!gdesc[2])
    return ERROR;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");
  if (!file)
    return ERROR;

  while (fgets(line, WORD_SIZE, file)) /*Mientras haya información del espacio para leer, se leerá*/
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");
      ilumination = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[0], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[1], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[2], toks);
      toks = strtok(NULL, "|");
      strcpy(descr, toks);
      toks = strtok(NULL, "|");
      strcpy(detail_descr, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west, up, down);
#endif
      space = space_create(id);
      if (space != NULL) /*Si el space es válido implementa al espacio del juego todo lo leido y añade un espacio*/
      {
        space_set_name(space, name);
        space_set_north(space, NULL);
        space_set_east(space, NULL);
        space_set_south(space, NULL);
        space_set_west(space, NULL);
        space_set_up(space, NULL);
        space_set_down(space, NULL);
        space_set_ilumination(space,ilumination);
        space_set_gdesc(space, gdesc);
        game_add_space(game, space);
        space_set_description(space, descr);
        space_set_detailed_description(space, detail_descr);
      }
    }
  }
  if (ferror(file))
    status = ERROR;
  free(gdesc[0]);
  free(gdesc[1]);
  free(gdesc[2]);
  free(gdesc);
  fclose(file);

  return status;
}

STATUS game_management_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  int i = 0, j = 0;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char aux[WORD_SIZE] = "";
  char descr[LEN_DES] = "";
  BOOL move = FALSE;
  BOOL ilum = FALSE;
  BOOL turnOn = FALSE;
  Id dependency = -1;
  Id link_open = -1;
  char *toks = NULL;
  Id id = NO_ID, pos_obj = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");
  if (!file)
    return ERROR;

  while (fgets(line, WORD_SIZE, file)) /*Mientras haya información del objeto para leer, se leerá*/
  {
    strcpy(aux,line);
    if (strncmp("#o:", line, 3) == 0 || strncmp("#i:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      if (strcmp(name, "space") == 0 || strcmp(name, "Space") == 0 || strcmp(name, "s") == 0)
      { /*comprobar que no sea un nombre de objeto incorrecto*/
        printf("No puede haber un objeto llamado 'space' , 'Space' o 's'\n");
        return ERROR;
      }
      toks = strtok(NULL, "|");
      pos_obj = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(descr, toks);
      toks = strtok(NULL, "|");
      move = atol(toks);
      toks = strtok(NULL, "|");
      dependency = atol(toks);
      toks = strtok(NULL, "|");
      link_open = atol(toks);
      toks = strtok(NULL, "|");
      ilum = atol(toks);
      toks = strtok(NULL, "|");
      turnOn = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%i|%li\n", id, name, pos_obj, move, dependency);
#endif
      object = object_create(id);
      if (!object)
        return ERROR;
      if (pos_obj != NO_ID) /*Si la posición del object es válida implementa al objeto todo lo leido*/
      {
        object_set_description(object, descr);
        object_set_name(object, name);
        object_set_movement(object, move);
        object_set_dependency(object, dependency);
        object_set_link_open(object, link_open);
        object_set_iluminate(object, ilum);
        object_set_turnedon(object, turnOn);
        while ((i < MAX_OBJECTS) && (game_get_object(game, i) != NULL))
          i++;
        for (j = 0; j < i; j++)
        {
          if (strcmp(name, object_get_name(game_get_object(game, j))) == 0)
          { /*Comprueba si hay dos objetos con el mismo nombre*/
            printf("Has creado dos objetos con el mismo nombre: Cambia el nombre de los objetos");
            return ERROR;
          }
        } /*Se implementa el objeto al juego*/
        game_add_object(game, object);

        if (strncmp("#i:", aux, 3) == 0)
          player_add_object(game_get_player(game),object_get_id(object));

        else
          game_set_object_location(game, id, pos_obj);
      }
    }
  }
  if (ferror(file))
    status = ERROR;
  fclose(file);

  return status;
}

STATUS game_management_load_players(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, player_pos = NO_ID;
  Player *player = NULL;
  int max_objects = 0;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file)) /*Mientras haya información del jugador para leer, se leerá*/
  {
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      player_pos = atol(toks);
      toks = strtok(NULL, "|");
      max_objects = atoi(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%i|\n", id, name, player_pos, max_objects);
#endif
      player = player_create(id);
      if (!player)
        return ERROR;
      if (player_pos != NO_ID) /*Si la posición del player es válida implementa al jugador todo lo leido*/
      {
        player_set_name(player, name);
        if (strlen(name) > 10)
        { /*Comprueba si el nombre del player se pasa del límite*/
          printf("El nombre del jugador no puede tener mas de 10 caracteres");
          return ERROR;
        }
        if (player_pos == 0)
          player_pos = 1;

        player_set_location(player, player_pos);
        player_set_inventory_max_capacity(player, max_objects);
        game_add_player(game, player); /*Se implementa el jugador al juego*/
      }
    }
  }
  if (ferror(file))
    status = ERROR;

  fclose(file);

  return status;
}

STATUS game_management_load_links(Game *game, char *filename)
{
  FILE *file = NULL;
  char name[WORD_SIZE] = "";
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, id_space1 = 0, id_space2 = 0;
  Space *space1, *space2;
  int flag = -1;
  TYPES gate = CLOSE;
  Link *link1 = NULL;
  Link *link2 = NULL;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");

  if (!file)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  { /*Mientras haya información del enlacé para leer, se leerá*/
    if (strncmp("#l:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      id_space1 = atol(toks);
      toks = strtok(NULL, "|");
      id_space2 = atol(toks);
      toks = strtok(NULL, "|");
      gate = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%d\n", id, name, id_space1, id_space2, gate);
#endif
      /*Estas lineas sirven para comprobar de que tipo de enlace estamos hablando, normal, oca, puente o muerte 
      Primero comprobaremos que tipo de enlace es, y mediante un flag lo guardamos, luego segun el tipo de enlace creamos 1 link o 2 links
      Y asi se hacen las uniones.*/
  space1 = game_get_space(game, id_space1);
        space2 = game_get_space(game, id_space2);
      if (id != NO_ID)
      {
        if (id_space1 + 1 == id_space2)
        {
          flag = 1;
        }

        else if (id_space1 + 8 == id_space2)
        {
          flag = 2;
        }

        else if (id_space1+10 == id_space2)
        {
          flag = 4;
        }

        else
        {
          flag = 3;
        }
      }
      else
      {
        return ERROR;
      }
      if (flag == 1 || flag == 2 || flag == 4)
      { /*en el caso de que se cumpla lo anterior, se implementa la información leida*/
        space1 = game_get_space(game, id_space1);
        space2 = game_get_space(game, id_space2);
        link1 = link_create(id);
        link2 = link_create(id);
        link_set_name(link1, name);
        link_set_name(link2, name);
        link_set_id_to(link1, id_space2);
        link_set_id_from(link1, id_space1);
        link_set_id_to(link2, id_space1);
        link_set_id_from(link2, id_space2);
        link_set_type(link1, gate);
        link_set_type(link2, gate);
        game_add_link(game, link1);

        if (flag == 1)
        {
          space_set_south(space1, link1);
          space_set_north(space2, link2);
        }
        else if (flag == 2)
        {
          space_set_east(space1, link1);
          space_set_west(space2, link2);
        }
        else if (flag == 4)
        {

          space_set_up(space1, link1);
          space_set_down(space2, link2);
        }
      }
      else
      {
        space1 = game_get_space(game, id_space1);
        link1 = link_create(id);
        link_set_name(link1, name);
        link_set_id_from(link1, id_space1);
        link_set_id_to(link1, id_space2);
        link_set_type(link1, gate);
        game_add_link(game, link1);
        space_set_east(space1, link1);
      }
    }
  }

  fclose(file);

  return OK;
}

STATUS game_management_load_dialogue(Game * game){

  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  


  if (!game)
    return ERROR;

  file = fopen("dialogue.dat", "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  {
    line[strcspn(line, "\n")] = 0;
    dialogue_set_interaction(game_get_dialogue(game),line);

  }
    fclose(file);

  return OK;
}

STATUS game_management_save(Game * game, char * filename){

  FILE *f;
  Object *o;
  Player *p;
  Link *l;
  int i;
  Id id, loc;

  if (!game || filename==NULL) return ERROR;

  f=fopen(filename,"w");
  if(f==NULL) return ERROR;

  p=game_get_player(game);
  fprintf(f,"#p:%ld|%ld|\n",player_get_id(p),player_get_location(p));

  for (i=0;i<game_get_total_objects(game);i++){
    o=game_get_object(game,i);
    if(player_has_object(game_get_player(game),object_get_id(o))){
      loc=game_get_object_location(game,object_get_id(o));/*
      if (loc<1){
        loc=player_get_location(p);
      }*/
      fprintf(f,"#i:%ld|%s|%ld|%s|%ld|%d|%d|\n",object_get_id(o),object_get_name(o),loc,object_get_description(o),object_get_link_open(o),object_get_iluminate(o),object_get_turnedon(o));
    }
    else
      fprintf(f,"#o:%ld|%s|%ld|%s|%ld|%d|%d|\n",object_get_id(o),object_get_name(o),game_get_object_location(game,object_get_id(o)),object_get_description(o),object_get_link_open(o),object_get_iluminate(o),object_get_turnedon(o));
  }

  for(i=0;i<game_get_total_links(game);i++){
    id=game_get_link_id_at(game,i);
    l=game_get_link(game,id);
    fprintf(f,"#l:%ld|%d|\n",link_get_id(l),link_get_type(l));
  }

  fclose(f);

  return OK;
}

STATUS game_management_load(Game * game, char * filename){

  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char descr[LEN_DES] = "";
  char aux[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, player_pos = NO_ID, pos_obj = NO_ID, link_open = NO_ID, pos_objAUX=NO_ID;
  BOOL ilum = FALSE;
  BOOL turnOn = FALSE;
  Object *object;
  TYPES gate = CLOSE;
  


  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  {
    strcpy(aux,line);
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      player_pos = atol(toks);

      if (player_pos != NO_ID)
      {
        if (player_pos == 0)
          player_pos = 1;

        player_set_location(game_get_player(game), player_pos);
      }
    }

    if (strncmp("#o:", line, 3) == 0 || strncmp("#i:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      pos_obj = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(descr, toks);
      toks = strtok(NULL, "|");
      link_open = atol(toks);
      toks = strtok(NULL, "|");
      ilum = atol(toks);
      toks = strtok(NULL, "|");
      turnOn = atol(toks);

      object=game_get_object_by_id(game,id);
      object_set_description(object, descr);
      object_set_name(object, name);
      object_set_link_open(object, link_open);
      object_set_iluminate(object, ilum);
      object_set_turnedon(object, turnOn);
      pos_objAUX=game_get_object_location(game,id);
      
        if (strncmp("#i:", aux, 3) == 0){
          printf("%s",object_get_name(object));
          if(pos_objAUX!=-1){
          space_remove_object(game_get_space(game,pos_objAUX),id);
          }
          player_add_object(game_get_player(game),object_get_id(object));

      }

        else{
          space_remove_object(game_get_space(game,pos_objAUX),id);
          space_set_objects(game_get_space(game,pos_obj),id);
        }
      }

      if (strncmp("#l:", line, 3) == 0)
      {
        toks = strtok(line + 3, "|");
        id = atol(toks);
        toks = strtok(NULL, "|");
        gate = atol(toks);
      
        link_set_type(game_get_link(game,id), gate);
      }
    }
    fclose(file);

  return OK;
}