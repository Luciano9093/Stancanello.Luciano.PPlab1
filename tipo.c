#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "fecha.h"
#include "bicicleta.h"
#include "trabajo.h"

#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define ASC 0
#define DESC 1

int validarIdtipo(eTipo tipos[], int tam, int id)
{
    int esValido=0;
    for(int i=0; i<tam; i++)
    {
        if(tipos[i].id==id)
        {
           esValido=1;
           break;
        }
    }
    return esValido;
}

int mostrarPorTipos(eBicicleta bicicleta[],int tam, eColor colores[],int tamC, eTipo tipos[], int tamT)
{
    int error=-1;
    int id;
    char nombreTipo[20];

    if(bicicleta!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        error=0;
        system("cls");
        printf("SELECCION ID DEL TIPO DESEADO.\n\n");
        printf("RUTERA: ID nro. 1000.\n");
        printf("CARRERA: ID nro. 1001\n");
        printf("MOUNTAIN: ID nro. 1002\n");
        printf("BMX: ID nro. 1003\n\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        while(validarIdtipo(tipos, tamT, id)==0)
        {
            printf("id invalido. Intente nuevamente");
            scanf("%d", &id);
        }
        cargarDescripcionTipo(tipos,tamT,id,nombreTipo);

        printf("LISTADO DE BICICLETAS POR TIPO %s\n\n", nombreTipo);
        printf("    ID        MARCA                TIPO                COLOR          RODADO\n");
        printf("-----------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(bicicleta[i].isEmpty==0 && bicicleta[i].idTipo==id)
            {
                mostrarBicicleta(bicicleta[i],tipos,tamT,colores,tamC);
            }
        }

    }
    return error;
}
