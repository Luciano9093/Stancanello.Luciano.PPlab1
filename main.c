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
#define TAM_BICICLETA 10
#define ASC 0
#define DESC 1

int main()
{

    eTipo tipos[TAM_TIPO]=
    {
        {1000,"Rutera"},
        {1001,"Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"}
    };

    eColor colores[TAM_COLOR]=
    {
        {5000,"Gris"},
        {5001,"Negro"},
        {5002,"Blanco"},
        {5003,"Azul"},
        {5004,"Rojo"}
    };

    /*    eServicio servicios[TAM_SERVICIO]=
        {
            {20000,"Limpieza",250},
            {20001,"Parche",300},
            {20002,"Centrado",400},
            {20003,"Cadena",350}
        };*/

    eBicicleta bicicletas[TAM_BICICLETA]=
    {
        {1,"Zanella",1000,5000,20},
        {2,"Fiorella",1001,5001,26},
        {3,"Sunella",1002,5002,27.5},
        {4,"Catella",1003,5003,29},
        {5,"Catello",1003,5004,20},
        {6,"Zane",1000,5000,20},
        {7,"Fior",1001,5001,26},
        {8,"Sune",1002,5002,27.5},
        {9,"Cate",1003,5003,29},
        {10,"Cella",1003,5004,20}
    };

    int flag=1;
    char confirma='n';

    inicializarBicicletas(bicicletas,TAM_BICICLETA);

    do
    {

        system("cls");
        switch(menu())
        {
        case 'a':
            /*if(altaBicicleta(bicicletas, TAM_BICICLETA, proximoId)==0)
            {
                proximoId++;
                printf("Alta existosa!!!\n\n");
                flag=1;
            }
            else
            {
                printf("Problemas para realizar alta\n\n");
            }*/
            break;
        case 'b':
            if(flag==1)
            {
                if(modificarBicicleta(bicicletas,TAM_BICICLETA, tipos, TAM_TIPO, colores, TAM_COLOR)==0)
                {
                    printf("Las modificaciones fueron realizadas.\n\n");
                }
                else
                {
                    if(modificarBicicleta(bicicletas,TAM_BICICLETA, tipos, TAM_TIPO, colores, TAM_COLOR)==2)
                    {
                        printf("Las modificaciones han sido canceladas.\n\n");
                    }
                    else
                    {
                        printf("Ingreso invalido. Verifique que haya seleccionado el legajo correcto.\n\n");
                    }
                }
            }
            else
            {
                printf("No hay personas igresadas en el sistema");
            }

            break;
        case 'c':
            if(flag==1)
            {
                if(bajaBicicleta(bicicletas,TAM_BICICLETA,tipos,TAM_TIPO,colores,TAM_COLOR)==0)
                {
                    printf("La baja ha sido generada.\n\n");
                }
                else
                {
                    if(bajaBicicleta(bicicletas,TAM_BICICLETA,tipos,TAM_TIPO,colores,TAM_COLOR)==2)
                    {
                        printf("La baja ha sido cancelada.\n\n");
                    }
                    else
                    {
                        printf("No se ha podido dar de baja a la persona deseada. Verifique que haya seleccionado el legajo correcto.\n\n");
                    }
                }
            }
            else
            {
                printf("No hay personas ingresadas en el sistema.\n\n");
            }

            break;
            break;
        case 'd':
           switch(subMenu())
           {
                case 'a':
                    mostrarPorColor(bicicletas,TAM_BICICLETA,colores,TAM_COLOR,tipos,TAM_TIPO);
                    break;
                case 'b':
                    mostrarPorTipos(bicicletas,TAM_BICICLETA,colores,TAM_COLOR,tipos,TAM_TIPO);
                    break;

           }




           /* ordenarTipoRodado(bicicletas,TAM_BICICLETA,DESC,DESC);
            mostrarBicicletas(bicicletas,TAM_BICICLETA, tipos, TAM_TIPO, colores, TAM_COLOR);*/


            break;
            case 'e':
            break;
            case 'f':
            break;
            case 'g':
            break;
            case 'h':
            break;
            case 'i':
            break;
            case 'j':
            printf("Confirma salida?: 'S' para salir 'N' para continuar: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            while(!(confirma=='s' || confirma=='n'))
            {
                printf("Ingreso no valido. Intente nuevamente. 'S' para salir, 'N' para continuar:  ");
                fflush(stdin);
                confirma=tolower(getchar());
            }
            break;
            }
            system("pause");
            }
            while(confirma=='n');
            }
