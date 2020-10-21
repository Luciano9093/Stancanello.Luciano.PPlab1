#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"


typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
}eBicicleta;


char subMenu();

/** \brief inicializa menu de opciones;
 *
 * \param ninguno;
 * \param ninguno;
 * \return opcion levantada mediante buffer de teclado;
 *
 */
char menu();
//int altaBicicleta(eBicicleta bicicleta[], int tam, int id);


/** \brief inicializa los espacios de memoria para la bicicletas
 *
 * \param estructura bicicleta
 * \param cantidad de bicicletas
 * \return un entero para validar si se pudo o no hacer la operacion
 *
 */
int inicializarBicicletas(eBicicleta bicicleta[], int tam);


/** \brief carga nombre de los colores (descripcion)
 *
 * \param estructura color
 * \param cantidad de color
 * \param ID que se compara en el Idcolor de la estructura Bicicletas
 * \param descripcion: variable en donde se guarda el nombre del color
 * \return
 *
 */
int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[]);


/** \brief carga nombre de los colores (descripcion)
 *
 * \param estructura tipos
 * \param cantidad de tipos
 * \param ID que se compara en el Idtipo de la estructura Bicicletas
 * \param descripcion: variable en donde se guarda el nombre de la descripcion tipo
 * \return un entero para validar si se pudo o no hacer la operacion
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);


/** \brief muestra los datos ingresados de una bicicleta
 *
 * \param estructura bicicleta
 * \param tamaño de la estructura bicicleta
 * \param estructura tipo
 * \param tamaño de la estructura tipo
 * \param estructura color
 * \param tamaño de la estructura color
 * \return un entero para validar si se pudo o no hacer la operacion
 *
 */
void mostrarBicicleta(eBicicleta x, eTipo tipos[], int tamT, eColor colores[], int tamC);


/** \brief muestra los datos ingresados de todas las bicicletas
 *
 * \param estructura bicicleta
 * \param tamaño de la estructura bicicleta
 * \param estructura tipo
 * \param tamaño de la estructura tipo
 * \param estructura color
 * \param tamaño de la estructura color
 * \return no retorna nada (VOID)
 *
 */
int mostrarBicicletas(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);


/** \brief ordena los datos ingresados bajo dos criterios= tipo y rodado
 *
 * \param estructura bicicleta
 * \param tamaño de estructura bicicleta
 * \param estructura tipo
 * \param tamaño de estructura tipo
 * \param estructura color
 * \param tamaño de estructura color
 * \return un entero para validar si se pudo o no hacer la operacion
 *
 */
int ordenarTipoRodado(eBicicleta bicicleta[], int tam, int criterioA, int criterioB);


/** \brief busca una bicicleta mediante su ID
 *
 * \param estructura bicicleta
 * \param tamaño estructura bicicleta
 * \param ID ingresado.
 * \return un entero con el valor del indice
 *
 */

int buscarBicicleta(eBicicleta bicicleta[], int tam, int id);

/** \brief modificar los datos ingresados por tipo y rodados
 *
 * \param estructura bicicleta
 * \param tamaño de estructura bicicleta
 * \param estructura tipo
 * \param tamaño de estructura tipo
 * \param estructura color
 * \param tamaño de estructura color
 * \return un entero para validar si se pudo o no hacer la operacion
 */

int modificarBicicleta(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/** \brief dar de baja una bicicleta cargada
 *
 * \param tamaño de estructura bicicleta
 * \param estructura tipo
 * \param tamaño de estructura tipo
 * \param estructura color
 * \param tamaño de estructura color
 * \return un entero para validar si se pudo o no hacer la operacion
 *
 */

int bajaBicicleta(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarPorColor(eBicicleta bicicleta[],int tam, eColor colores[],int tamC, eTipo tipos[], int tamT);
int mostrarPorTipos(eBicicleta bicicleta[],int tam, eColor colores[],int tamC, eTipo tipos[], int tamT);



#endif // BICICLETA_H_INCLUDED
