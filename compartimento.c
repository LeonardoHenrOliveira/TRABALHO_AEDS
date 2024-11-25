#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compartimento.h"

void FLVazia(TLista* pLista){
    pLista->pPrimeiro = (Apontador)malloc(sizeof(Tcelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
} 
int LEHVazia(TLista* pLista){
    return (pLista->pPrimeiro == pLista->pUltimo);
}
int LInsere(TLista* pLista, Trocha* pRocha ){
    Apontador novarocha= (Apontador)malloc(sizeof(Tcelula));
    strcpy(novarocha->rocha.categoria,pRocha->categoria);
    novarocha->rocha.peso=pRocha->peso;
    novarocha->rocha.latitude=pRocha->latitude;
    novarocha->rocha.longitude= pRocha->longitude;
    pLista->pUltimo->pProx = novarocha;
    novarocha->pProx=NULL;
    pLista->pUltimo=novarocha;
}
int LRetira(TLista* pLista, Trocha* pRocha){
    Tcelula* pAux;
    if (LEHVazia(pLista)){
        return 0;
    }
    *pRocha = pLista->pPrimeiro->pProx->rocha;
    pAux = pLista -> pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    return 1;
}
void LImprime(TLista* pLista){
    Apontador pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux!=NULL){
        printf("%s %.2f\n", pAux->rocha.categoria, pAux->rocha.peso);
        pAux= pAux->pProx;
    }
}
