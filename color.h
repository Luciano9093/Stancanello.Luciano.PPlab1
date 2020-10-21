#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;


int validarIdColor(eColor colores[], int tam, int id);

#endif // COLOR_H_INCLUDED

