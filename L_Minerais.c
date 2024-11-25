#include <stdio.h>
#include "L_Minerais.h"


void FLvazia_e(L_entrada* lista_e){
    lista_e->primeiroe = INICIO;
    lista_e->ultimoe= lista_e->primeiroe;
}
int LInsere_e(L_entrada* lista_e, entradaminerais y){
    if(lista_e->ultimoe==maxentrada){
        return 0;
    }
    lista_e->item_e[lista_e->ultimoe++] = y;
    return 1;
}

void LImprime_e(L_entrada* lista_e){
    int i;
    for (i = lista_e->primeiroe; i < lista_e->ultimoe; i++){
        printf("\n%s\n", lista_e->item_e[i].nome);
    }
}

void FLvazia_m(L_Minerais* lista_m){
    lista_m->primeiro = INICIO;
    lista_m->ultimo = lista_m->primeiro;
};

int LEhVazia_m(L_Minerais* lista_m){
    return(lista_m->primeiro == lista_m->ultimo);
};

int LEhVazia_e(L_entrada* lista_m){
    return(lista_m->primeiroe == lista_m->primeiroe);
};

int LInsere_m(L_Minerais* lista_m, Minerais x){
    if(lista_m->ultimo == MAXTAM)
        return 0;
    lista_m->item[lista_m->ultimo++] = x;
    return 1;
};


int Lretira_e(L_entrada* lista_e) {
    lista_e->ultimoe=0;
    return 0; 
}


int Lretira_m(L_Minerais* lista_m, int p, Minerais *px){
    int cont;
    if(LEhVazia_m(lista_m) || p >= lista_m->ultimo || p < 0)
        return 0;
    
    *px = lista_m->item[p];
    for(cont = p+1; cont <= lista_m->ultimo; cont++){
        lista_m->item[cont - 1] = lista_m->item[cont];
    }
    return 1;
};

void LImprime_m(L_Minerais* lista_m){
    int i;
    for (i = lista_m->primeiro; i < lista_m->ultimo; i++){
        printf("\n%s\n", lista_m->item[i].Nome);
        printf("%.2f\n", lista_m->item[i].Dureza);
        printf("%.2f\n", lista_m->item[i].Reatividade);
        printf("%s\n", lista_m->item[i].Cor);
    }
};

void PreencheMinerais(L_Minerais* lista_m, Minerais* mineral){
    FLvazia_m(lista_m);

    Minerais Ferrolita = InicializarMineral(mineral, "Ferrolita", 0.5, 0.7, "Cinza");
    Minerais Solarium = InicializarMineral(mineral, "Solarium", 0.9, 0.2, "Amarelo");
    Minerais Aquavitae = InicializarMineral(mineral, "Aquavitae", 0.5, 0.8, "Azul");
    Minerais Terranita = InicializarMineral(mineral, "Terranita", 0.5, 0.8, "Marrom");
    Minerais Calaris = InicializarMineral(mineral, "Calaris", 0.6, 0.5, "Vermelho");
    LInsere_m(lista_m, Ferrolita);
    LInsere_m(lista_m, Solarium);
    LInsere_m(lista_m, Aquavitae);
    LInsere_m(lista_m, Terranita);
    LInsere_m(lista_m, Calaris);
}