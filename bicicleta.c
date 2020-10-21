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


char subMenu()
{
    char opcion;

    system("cls");
    printf("LISTA DE INFORMES.\n\n");
    printf("A.LISTAR BICICLETAS X COLOR\n");
    printf("B.LISTAR BICICLETAS X TIPO\n");
    printf("C.LISTAR BICICLETAS X MENOR RODADO\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

char menu()
{
    char opcion;
    //int opcion1;
    system("cls");

    printf("*** ABM Bicicletas ***\n\n");
    printf("A. ALTA BICICLETA\n");
    printf("B. MODIFICAR BICICLETA\n");
    printf("C. BAJA BICICLETA\n");
    printf("D. INFORMES\n");
    printf("E. SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    if(opcion=='d')
    {
        subMenu();
    }



    return opcion;

}

int inicializarBicicletas(eBicicleta bicicleta[], int tam)
{
    int error = -1;
    if(bicicleta!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            bicicleta[i].isEmpty=0;
        }
        error=0;
    }
    return error;
}
int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[])
{
    int error=-1;
    if(colores!=NULL && tam>0 && id>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id==id)
            {
                strcpy(descripcion, colores[i].nombreColor);
                error=0;
                break;
            }
        }
    }
    return error;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int error=-1;
    if( tipos!=NULL && tam>0 && id>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(descripcion, tipos[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

void mostrarBicicleta(eBicicleta x, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    char desColor[20];
    char desTipo[20];
    if(cargarDescripcionColor(colores,tamC,x.idColor,desColor)==0 && cargarDescripcionTipo(tipos, tamT, x.idTipo, desTipo)==0)
    {
        printf("%5d      %10s         %10s         %10s         %5.1f\n", x.id, x.marca, desTipo, desColor,x.rodado);
    }
}
int mostrarBicicletas(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int error = -1;
    int flag = 0;

    if(bicicleta!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("         *** LISTADO DE BICICLETAS *** \n\n");
        printf("    ID        MARCA                TIPO                COLOR          RODADO\n");
        printf("-----------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(bicicleta[i].isEmpty==0)
            {
                mostrarBicicleta(bicicleta[i], tipos, tamT, colores, tamC);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay bicicletas en la lista");
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

int ordenarTipoRodado(eBicicleta bicicleta[], int tam, int criterioA, int criterioB)
{
    int error=-1;
    eBicicleta auxiliar;
    if(bicicleta!=NULL && tam>0 && criterioA>=0 && criterioA<=1 && criterioB>=0 && criterioB<=1)
    {
        error=0;
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(criterioA==0 && bicicleta[i].idTipo>bicicleta[j].idTipo)
                {
                    auxiliar=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxiliar;
                }
                else if(criterioA==1 && bicicleta[i].idTipo<bicicleta[j].idTipo)
                {
                    auxiliar=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxiliar;
                }
                else if(bicicleta[i].idTipo==bicicleta[j].idTipo && bicicleta[i].idColor>bicicleta[j].idColor && criterioB==0)
                {
                    auxiliar=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxiliar;
                }
                else if(bicicleta[i].idTipo==bicicleta[j].idTipo && bicicleta[i].idColor<bicicleta[j].idColor && criterioB==1)
                {
                    auxiliar=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxiliar;
                }

            }

        }
    }
    return error;
}
int buscarBicicleta(eBicicleta bicicleta[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(bicicleta[i].id==id && bicicleta[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int modificarBicicleta(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int error=-1;
    int id;
    int indice;
    char confirma;
    char opcion;

    if(bicicleta!=NULL && tam>0 && tipos!=NULL && tamT>0)
    {
        system("cls");
        printf("    **** MODIFICAR DATOS DE BICICLETA ****\n\n");
        mostrarBicicletas(bicicleta,tam, tipos, tamT, colores, tamC);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice= buscarBicicleta(bicicleta,tam,id);

        if(indice==-1)
        {
            printf("No existe una bicicleta con ese id\n");
        }
        else
        {
            error=0;
            mostrarBicicleta(bicicleta[indice],tipos,tamT,colores,tamC);
            printf("Confirma modificacion: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                system("cls");
                printf("MENU DE DATOS MODIFICABLES.");
                printf("\n\nA. TIPO.\n");
                printf("B. RODADO.\n\n");
                printf("Seleccione opcion a modificar: ");
                fflush(stdin);
                opcion = tolower(getchar());

                switch(opcion)
                {
                case 'a':
                    system("cls");
                    printf("Ingrese tipo, solo por su ID.\n\n");
                    printf("A. Rutera: 1000\n");
                    printf("B. Carrera: 1001\n");
                    printf("C. Mountain: 1002\n");
                    printf("D. BMX: 1003\n\n");
                    printf("Ingrese ID de TIPO: ");
                    scanf("%d",&bicicleta[indice].idTipo);
                    while(bicicleta[indice].idTipo<1000 || bicicleta[indice].idTipo>1003)
                    {

                        printf("Ingreso no valido. Seleccione ID de tipo nuevamente: ");
                        scanf("%d",&bicicleta[indice].idTipo);
                    }
                    break;
                case 'b':
                    printf("Ingrese rodado. '20 - 26 - 27.5 - 29': ");
                    scanf("%f",&bicicleta[indice].rodado);
                    while(bicicleta[indice].rodado!=20 && bicicleta[indice].rodado!=26 && bicicleta[indice].rodado!=27.5 && bicicleta[indice].rodado!=29)
                    {
                        fflush(stdin);
                        printf("Ingreso no valido. Ingrese el rodado nuevamente. Valido solo para rodados 20, 26, 27.5 y 29: ");
                        scanf("%f",&bicicleta[indice].rodado);
                    }
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente: ");
                    break;
                }

            }
            else
            {
                printf("Modificacion cancelada.\n\n");
                error=2;
            }

        }

    }
    return error;
}

int bajaBicicleta(eBicicleta bicicleta[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int error=-1;
    int id;
    int indice;
    char confirma;
    int salida=0;

    if(bicicleta!=NULL && tam>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        while(salida==0)
        {
            system("cls");
            printf("    **** BAJA DE PERSONA ****\n\n");
            mostrarBicicletas(bicicleta,tam, tipos, tamT, colores, tamC);
            printf("Ingrese el id o ingrese 0 'cero' para salir: ");
            scanf("%d", &id);

            if(id!=0)
            {
                indice= buscarBicicleta(bicicleta,tam,id);

                if(indice==-1)
                {
                    printf("No existe una bicicleta con ese id.\n");
                }
                else
                {
                    mostrarBicicleta(bicicleta[indice], tipos, tamT, colores, tamC);
                    printf("Confirma borrado: ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma=tolower(confirma);
                    if(confirma == 's')
                    {
                        bicicleta[indice].isEmpty=1;
                        error=0;
                    }
                    else
                    {
                        error=2;
                    }
                }
            }
            else
            {
                salida=1;
            }
        }

    }
    return error;
}

