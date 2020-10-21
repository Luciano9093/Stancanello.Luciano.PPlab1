

/*
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[])
{
    int error=-1;
    if(servicios!=NULL && tam>0 && id>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

int altaTrabajo(eBicicleta bicicleta[], int tam; eServicio servicios[],int tamS, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int error=-1;
    int id;
    int indice;
    int servicio;

    if(bicicleta!=NULL && tam>0 && servicios!=NULL && tamS>0 && tipos!=NULL && tamT>0 && colores!=NULL && tamC>0)
    {
        mostrarBicicletas(bicicleta,tam, tipos, tamT, colores, tamC);
        printf("\n\nSeleccione una bicicleta por su ID: ");
        scanf("%d", &id);

        indice=buscarBicicleta(bicicleta,tam,id);

        if(indice!=-1)
        {
            printf("***    LISTA DE SERVICIOS      ***.\n\n ");
            printf("1.Parche.\n");
            printf("2.Centrado.\n");
            printf("3.Cadena.\n");
            printf("Seleccione una opcion.");
            scanf("%d",&servicio);

            if(cargarDescripcionServicio(servicios,tamS,eTrabajo.idServicio,servicio)==0)
            {
                    printf()
            }


        }
    }


    return error;
}
*/
