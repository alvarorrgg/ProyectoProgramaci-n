/** 
 * @brief Archivo cabecera de die.c en el se encuentra definidas los datos y funciones de die.c
 * 
 * @file die.h
 * @author Alberto Vicente
 * @version 1.0 
 * @date 02-03-2021 
 * @copyright GNU Public License
 */
 
#ifndef DIE_H
#define DIE_H

#define MAX_IDS 100 /*!<Numero maximo de ids*/

#include "types.h"
#include "time.h"
/**
 * @brief Estructura die
 *
 * contiene las variables del dado
 */
typedef struct _Die Die;


/**
 * @brief crea un dado 
 * 
 * die_create crea un dado inicializando sus variables
 *
 * @author Alberto Vicente
 * @date 02-03-2021
 *
 * @param id el id del dado
 * @return el dado creado
 */
Die * die_create(Id id);

/**
 * @brief destruye un dado 
 * 
 * die_destroy destruye un dado y vacia la memoria reservada
 *
 * @author Alberto Vicente
 * @date 02-03-2021
 *
 * @param die el dado que se destruye
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_destroy(Die * die);

/**
 * @brief tira el dado
 * 
 * die_roll simula el tiro de un dado generando un número aleatorio entre 1 y 6
 *
 * @author Alberto Vicente
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
 * @author Alberto Vicente
 * @date 07-03-2021
 *
 * @param id el id que se fija
 * @param die el dado al que se le establece el id
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_set_Id(Die * die, Id id);

/**
 * @brief recoge la ultima tirada
 * 
 * die_get_last_roll recoge la ultima tirada del dado
 *
 * @author Alberto Vicente
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
 * @author Alberto Vicente
 * @date 07-03-2021
 *
 * @param die el dado del que se busca el id
 * @return el id del dado
 */
Id die_get_id(Die * die);

/**
 * @brief imprime el dado
 * 
 * die_print imprime los valores útiles del dado
 *
 * @author Alberto Vicente
 * @date 07-03-2021
 *
 * @param pf el fichero donde se imprime
 * @param die el dado que se imprime
 * @return ERROR o OK según si se encuentra o no algun fallo
 */
STATUS die_print(FILE *pf,Die *die);
#endif
