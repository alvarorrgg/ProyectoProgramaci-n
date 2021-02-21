#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

/**
 * @brief Estructura space
 *
 * contiene las variables del espacio
 */
struct _Space {
  Id id;		/*!< coordenadas */
  char name[WORD_SIZE + 1];	/*!< nombre del espacio */
  Id north;		/*!< coordenada norte */
  Id south;		/*!< coordenada sur */
  Id east;		/*!< coordenada este */
  Id west;		/*!< coordenada oeste */
  BOOL object;		/*!< objeto (TRUE o FALSE) */
};

/**
 * @brief crea un nuevo espacio
 *
 * space_create crea un nuevo espacio inicializando las coordenadas a -1
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param id ...
 * @return newspace le espacio que se crea
 */
Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->object = FALSE;

  return newSpace;
}

/**
 * @brief destruye un espacio
 *
 * space_destroy destruye un espacio creado previamente
 * 
 * @date
 * @author
 *
 * @param space el espacio que se destruye
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  free(space);
  space = NULL;

  return OK;
}

/**
 * @brief da nombre a un espacio
 *
 * space_set_name da nombre a un espacio
 * 
 * @date
 * @author
 *
 * @param space el espacio al que se le pone el nombre
 * @param name el nombre que se le da
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

/**
 * @brief establece la coordenada norte
 *
 * space_set_north fija la coordenada norte
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id ...
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/**
 * @brief establece la coordenada sur
 *
 * space_set_south fija la coordenada sur
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id ...
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

/**
 * @brief establece la coordenada este
 *
 * space_set_east fija la coordenada este
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id ...
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

/**
 * @brief establece la coordenada oeste
 *
 * space_set_west fija la coordenada oeste
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param id ...
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

/**
 * @brief establece el objeto a TRUE o FALSE
 *
 * space_set_object establece el valor de object a TRUE o a FALSE
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @param value el valor que se le otorga
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_set_object(Space* space, BOOL value) {
  if (!space) {
    return ERROR;
  }
  space->object = value;
  return OK;
}

/**
 * @brief obtiene el nombre del espacio
 *
 * space_get_name consigue el nombre del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->name el nombre del espacio
 */
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

/**
 * @brief obtiene la id del espacio
 *
 * space_get_id consigue la id del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->id la id del espacio
 */
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/**
 * @brief obtiene la coordenada norte del espacio
 *
 * space_get_north consigue la coordenada norte del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->north la coordenada norte del espacio
 */
Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

/**
 * @brief obtiene la coordenada sur del espacio
 *
 * space_get_south consigue la coordenada sur del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->south la coordenada sur del espacio
 */
Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

/**
 * @brief obtiene la coordenada este del espacio
 *
 * space_get_east consigue la coordenada este del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->east la coordenada este del espacio
 */
Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

/**
 * @brief obtiene la coordenada oeste del espacio
 *
 * space_get_west consigue la coordenada oeste del espacio
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->west la coordenada oeste del espacio
 */
Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

/**
 * @brief obtiene el objeto "TRUE o FALSE"
 *
 * space_get_object obtiene el valor de object a TRUE o a FALSE
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return space->object el valor del objeto
 */
BOOL space_get_object(Space* space) {
  if (!space) {
    return FALSE;
  }
  return space->object;
}

/**
 * @brief muestra por pantalla el espacio creado
 *
 * space_print imprime por la terminal el espacio creado
 * 
 * @date
 * @author Profesores PPROG
 *
 * @param space el espacio que se trabaja
 * @return OK para saber que se ha ejecutado la función correctamente
 */
STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_get_object(space)) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}

