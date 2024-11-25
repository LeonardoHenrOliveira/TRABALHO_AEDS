#ifndef L_MINERAIS_H
#define L_MINERAIS_H

#include <stdio.h>
#include "Minerais.h"
#define MAXTAM 5
#define maxentrada 3
#define INICIO 0


typedef struct {
    Minerais item[MAXTAM];
    int primeiro;
    int ultimo;
}L_Minerais;

typedef struct {
    entradaminerais item_e[MAXTAM];
    int primeiroe;
    int ultimoe;
}L_entrada;


void FLvazia_m(L_Minerais* lista_m);
int LEhVazia_m(L_Minerais* lista_m);
int LInsere_m(L_Minerais* lista_m, Minerais x);
int Lretira_m(L_Minerais* lista_m, int p, Minerais *px);
void LImprime_m(L_Minerais* lista_m);

int LEhVazia_e(L_entrada* lista_m);
void FLvazia_e(L_entrada* lista_e);
int LInsere_e(L_entrada* lista_e, entradaminerais y);
void LImprime_e(L_entrada* lista_e);
int Lretira_e(L_entrada* lista_e);


void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral);



#endif