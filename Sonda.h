#include <stdio.h>
#include <stdlib.h>
#include "Compartimento.h"


typedef struct {
    int Identificador;
    TLista compartimento;
    float capacidade;
    float peso;
    float Latitude, Longitude;
    int EstaLigada;
}TSonda;

void Inicializar_sonda(TSonda* sonda, float latitude, float longitude, float capacidade);
int Liga(TSonda* sonda);
int Desliga(TSonda* sonda);
void Move(TSonda* sonda, float latitude, float longitude);


void setLatitude(TSonda* sonda, float latitude);
void setLongitude(TSonda* sonda, float longitude);
void setCapacidade(TSonda* sonda, float capacidade);
int FazId (TSonda*sonda);

float setPesoSonda(TSonda* sonda, TLista* lista_r);
int getId(TSonda* sonda);
int getLatitude(TSonda* sonda);
int getLongitude(TSonda* sonda);

