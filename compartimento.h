#ifndef L_ROCHAS_H
#define L_ROCHAS_H
#include <stdio.h>
#include "Rocha.h"

typedef struct celula* Apontador;
typedef struct celula{
    Trocha rocha;
    struct celula* pProx;
}Tcelula;


typedef struct  {
    Apontador pPrimeiro;
    Apontador pUltimo;   
}TLista;


void FLVazia(TLista* pLista);
int LEHVazia(TLista* pLista);
int LInsere(TLista* pLista, Trocha* pRocha );
int LRetira(TLista* pLista, Trocha* pRocha);
void LImprime(TLista* pLista);

#endif