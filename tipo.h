#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

int validarIdtipo(eTipo tipos[], int tam, int id);



#endif // TIPO_H_INCLUDED
