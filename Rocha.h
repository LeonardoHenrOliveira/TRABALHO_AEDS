#ifndef ROCHA_H
#define ROCHA_H
#include <stdio.h>
#include "L_Minerais.h"

typedef int tiporocha;
typedef struct {
    int identificador;
    float peso;
    char categoria[20];
    tiporocha rocha;
    L_entrada lista_minerais;
    float latitude;
    float longitude;
    
}Trocha;

void setidentificador(Trocha *rocha, int identificador);
void setpeso(Trocha *rocha, float peso);
void setlatitude(Trocha *rocha, float latitude);
void setlongitude(Trocha *rocha, double longitude);


void classifica_categoria(L_entrada* lista_e, Trocha * rocha_m, int j);

Trocha InicializaRocha(Trocha *rocha, int identificador, float peso, float latitude, float longitude);

int getidentificador(Trocha* rocha);
float getpeso(Trocha* rocha);
char* getcategoria(Trocha* rocha);
float getlatitude(Trocha* rocha);
float getlongitude(Trocha* rocha);

#endif