#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

typedef struct  Celula_s* Apontador_s;
typedef struct Celula_s{
    TSonda item;
    struct Celula_s* pProx;
}Celula_s;


typedef struct {
    Apontador_s pPrimeiro_s;
    Apontador_s pUltimo_s;
}Lista_s;

void FLVazia_s(Lista_s* lista_sonda);
int LEHVazia_s(Lista_s* lista_sonda);
int LInsere_s(Lista_s* lista_sonda, TSonda* sonda );
int LRetita_s(Lista_s* lista_sonda, TSonda* sonda);
void LImprime_s(Lista_s* lista_sonda);

float percorrer(TLista comp, char* cat);
void retiraRochas(TSonda* sonda, TLista* temp_lista, float media);
void voltarRocha(TSonda* sonda, TLista* temp_lista, float media);
int maisItem(TLista* comp);
void reduz_capacidade(TSonda* sonda, Trocha* rocha);

void Operacao_i(Lista_s* lista_sonda);
void OperacaoE(Lista_s* lista_sonda);
void RedistribuirSondas(Lista_s* lista_Sonda);
float MediaSondas(Lista_s* lista_sonda);
void PosicaoInicial(Lista_s* lista_sonda);
int ContemCategoria(TSonda *sonda, const char *categoria, float pesoMinimo);

TSonda* Calculo_sonda_prox(Lista_s *lista_sonda, Trocha *rocha);