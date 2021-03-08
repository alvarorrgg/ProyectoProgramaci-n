/** 
 * @brief Archivo cabecera del modulo set.h, en el se define la estructura de datos Object y sus funciones.
 * 
 * @file die.h
 * @author R2
 * @version 1.0 
 * @date 02-03-2021 
 * @copyright GNU Public License
 */
 
#ifndef DIE_H
#define DIE_H
#include "types.h"
#include "time.h"
#define MAX_IDS 100

typedef struct _Die Die;


/**
 * @brief crea un dado 
 * 
 * die_create crea un dado inicializando sus variables
 *
 * @author R2
 * @date 02-03-2021
 *
 * @return el dado creado
 */
Die * die_create();

/**
 * @brief destruye un dado 
 * 
 * die_destroy destruye un dado y vacia la memoria reservada
 *
 * @author R2
 * @date 02-03-2021
 *
 * @param die el dado que se destruye
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_destroy(Die * die);

/**
 * @brief tira el dado
 * 
 * die_roll simula el tiro de un dado generando un número aleatoria entre 1 y 6
 *
 * @author R2
 * @date 07-03-2021
 *
 * @param die el dado que se tira
 * @return el valor aleatorio generado
 */
int die_roll(Die * die);

/**
 * @brief establece el id
 * 
 * die_set_Id estable el id al dado
 *
 * @author R2
 * @date 07-03-2021
 *
 * @param el id que se fija
 * @param die el dado al que se le establece el id
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_set_Id(Die * die, Id id);

/**
 * @brief recoge la ultima tirada
 * 
 * die_get_last_roll recoge la ultima tirada del dado
 *
 * @author R2
 * @date 07-03-2021
 *
 * @param die el dado del que se recoge la última tirada
 * @return la última tirada del dado
 */
int die_get_last_roll(Die * die);

/**
 * @brief encuentra el id
 * 
 * die_get_id encuentra el id del dado
 *
 * @author R2
 * @date 07-03-2021
 *
 * @param die el dado del que se busca el id
 * @return el id del dado
 */
Id die_get_id(Die * die);

/**
 * @brief imprime el dado
 * 
 * die_get_id imprime los valores útiles del dado
 *
 * @author R2
 * @date 07-03-2021
 *
 * @param pf el fichero donde se imprime
 * @param die el dado que se imprime
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_print(FILE *pf, const Die *die);
#endif
