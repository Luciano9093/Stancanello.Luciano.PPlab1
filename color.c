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

int validarIdColor(eColor colores[], int tam, int id)
{
    int esValido=0;
    for(int i=0; i<tam; i++)
    {
        if(colores[i].id==id)
        {
           esValido=1;
           break;
        }
    }
    return esValido;
}

int mostrarPorColor(eBicicleta bicicleta[],int tam, eColor colores[],int tamC, eTipo tipos[], int tamT)
{
    int error=-1;
    int id;
    char nombreColor[20];

    if(bicicleta!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        error=0;
        system("cls");
        printf("SELECCION ID DEL COLOR DESEADO.\n\n");
        printf("GRIS: ID nro. 5000.\n");
        printf("NEGRO: ID nro. 5001\n");
        printf("BLANCO: ID nro. 5002\n");
        printf("AZUL: ID nro. 5003\n");
        printf("ROJO: ID nro. 5004\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &id);

        while(validarIdColor(colores, tamC, id)==0)
        {
            printf("id invalido. Intente nuevamente");
            scanf("%d", &id);
        }
        cargarDescripcionColor(colores,tamC,id,nombreColor);

        printf("LISTADO DE BICICLETAS POR COLOR %s\n\n", nombreColor);
        printf("    ID        MARCA                TIPO                COLOR          RODADO\n");
        printf("-----------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(bicicleta[i].isEmpty==0 && bicicleta[i].idColor==id)
            {
                mostrarBicicleta(bicicleta[i],tipos,tamT,colores,tamC);
            }
        }

    }
    return error;
}
