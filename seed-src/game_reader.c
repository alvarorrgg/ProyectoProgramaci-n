/** 
 * @brief Implementa el inicio de juego y obtiene los valores iniciales de data.dat
 * 
 * @file game_reader.c
 * @author R1
 * @version 1.0 
 * @date 18-02-2021  
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char **gdesc = NULL;
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  gdesc = (char **)malloc(3 * sizeof(char *));
  if (gdesc == NULL)
    return ERROR;
  gdesc[0] = (char *)malloc(9 * sizeof(char));
  if (gdesc[0] == NULL)
    return ERROR;
  gdesc[1] = (char *)malloc(9 * sizeof(char));
  if (gdesc[1] == NULL)
    return ERROR;
  gdesc[2] = (char *)malloc(9 * sizeof(char));
  if (gdesc[2] == NULL)
    return ERROR;

  if (!filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
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
      strcpy(gdesc[0], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[1], toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc[2], toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_gdesc(space, gdesc);
        game_add_space(game, space);
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

STATUS game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, pos_obj = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename)
    return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      pos_obj = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, posobj);
#endif
      object = object_create(id);
      if (pos_obj != NO_ID)
      {
        object_set_name(object, name);
        game_add_object(game, object);
        game_set_object_location(game, id, pos_obj);
      }
    }
  }
  if (ferror(file))
    status = ERROR;
  fclose(file);

  return status;
}
