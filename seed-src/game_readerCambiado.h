#ifndef GAME_READER_H
#define GAME_READER_H
#include "command.h"
#include "space.h"


typedef struct _Game{
  Id player_location;
  Id object_location;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;

STATUS game_load_spaces(Game* game, char* filename);
STATUS game_add_space(Game* game, Space* space);
Id     game_get_space_id_at(Game* game, int position);
Space* game_get_space(Game* game, Id id);

#endif
