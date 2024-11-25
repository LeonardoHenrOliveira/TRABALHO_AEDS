#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

void EsvaziaListaE(L_entrada *lista_e) {
    if (lista_e == NULL) {
        printf("A lista não foi inicializada.\n");
        return;
    }

    lista_e->ultimoe = 0; // Redefine o índice do último elemento para 0, esvaziando a lista
    printf("ListaE esvaziada com sucesso.\n");
}


int main() {
    
    int quntdsondas, quntdoperacoes, i,peso, contador=0,j=0,k,escolha;
    char entrada[255], operacao;
    const char s[2]= " ";
    char * token;
    char categoria[20];
    float longitude, latitude, lat_i, long_i, velocidade_i, combustivel_i, capacidade_i;
    

    L_Minerais lista_m;
    Minerais minerais;
    
    Lista_s lista_sonda;
    Trocha lrocha;
    TLista comp;
    L_entrada lista_e;
    


    printf("Escolha se o codigo será rodado pela entrada do terminal ou de um arquivo txt:\n(1)=arquivo\n(2)=terminal\n");
    scanf("%d",&escolha);




if (escolha == 1) {
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Sai do programa se o arquivo não for encontrado
    }

    int quntdsondas, quntdoperacoes;
    if (fscanf(arquivo, "%d", &quntdsondas) != 1) {
        printf("Erro ao ler a quantidade de sondas.\n");
        fclose(arquivo);
        return 1;
    }
    fgetc(arquivo); // Consome a quebra de linha após o número

    FLVazia_s(&lista_sonda);

    // Leitura das sondas
    for (int k = 0; k < quntdsondas; k++) {
        float lat, lon, capacidade, velocidade, combustivel;
        if (fscanf(arquivo, "%f %f %f %f %f", &lat, &lon, &capacidade, &velocidade, &combustivel) != 5) {
            printf("Erro ao ler os dados da sonda %d.\n", k + 1);
            fclose(arquivo);
            return 1;
        }
        fgetc(arquivo); // Consome a quebra de linha
        TSonda Nsonda;
        Inicializar_sonda(&Nsonda, lat, lon, capacidade);
        LInsere_s(&lista_sonda, &Nsonda);
    }

    // Leitura da quantidade de operações
    if (fscanf(arquivo, "%d", &quntdoperacoes) != 1) {
        printf("Erro ao ler a quantidade de operações.\n");
        fclose(arquivo);
        return 1;
    }
    fgetc(arquivo); // Consome a quebra de linha após o número

    char operacao;
    int l = 0; // Contador de minerais diferentes

    // Processamento das operações
    for (int i = 0; i < quntdoperacoes; i++) {
        printf("OPERACAO %d de %d\n", i + 1, quntdoperacoes);

        // Lê a operação
        if (fscanf(arquivo, " %c", &operacao) != 1) {
            printf("Erro ao ler a operação.\n");
            break;
        }
        fgetc(arquivo); // Consome a quebra de linha após a operação

        if (operacao == 'R') {
            float latitude, longitude;
            int peso;

            if (fscanf(arquivo, "%f %f %d", &latitude, &longitude, &peso) != 3) {
                printf("Erro ao ler dados da rocha (latitude, longitude, peso).\n");
                break;
            }
            fgetc(arquivo); // Consome a quebra de linha

            char minerais_entrada[255];
            if (fgets(minerais_entrada, sizeof(minerais_entrada), arquivo) == NULL) {
                printf("Erro ao ler os minerais da rocha.\n");
                break;
            }
            minerais_entrada[strcspn(minerais_entrada, "\r\n")] = '\0'; // Remove \r ou \n

            // Processa minerais e classifica rocha
            char *token = strtok(minerais_entrada, " ");
            Trocha rnova;
            Trocha rocha;
            while (token != NULL) {
                if (strlen(token) > 0) {
                    entradaminerais entradam;
                    entradaminerais m1 = InicializarMinerale(&entradam, token);
                    LInsere_e(&lista_e, m1); // Adiciona mineral na lista de entrada

                    classifica_categoria(&lista_e, &rnova, l); // Classifica os minerais
                    printf("\neeee%s\n", lista_m.item[i].Nome);
                    // Limpa lista de minerais
                    Lretira_e(&lista_e);

                    // Atualiza a rocha com minerais classificados
                    rocha = InicializaRocha(&rnova, 1, peso, latitude, longitude);


                    l++; // Incrementa contador de minerais diferentes
                }


                token = strtok(NULL, " "); // Avança para o próximo mineral
            }
            printf("\n%s\n", lista_m.item[i].Nome);
            TSonda *sonda = Calculo_sonda_prox(&lista_sonda, &rocha); // Calcula sonda mais próxima
            LInsere(&sonda->compartimento, &rocha); // Insere a rocha na sonda
            printf("Rocha inserida na sonda.\n");

        } else if (operacao == 'I') {
            Operacao_i(&lista_sonda); // Processa operação de inserção
        } else if (operacao == 'E') {
            OperacaoE(&lista_sonda); // Processa operação de exibição
        } else {
            printf("Operação inválida no arquivo.\n");
        }
    }

    fclose(arquivo);
}
    
    
    else if (escolha==2){
        PreencheMinerais(&lista_m, &minerais);
        printquntdsondas();
        scanf("%d",&quntdsondas);

        FLVazia_s(&lista_sonda);
    
        for (k = 0; k < quntdsondas; k++){
            TSonda Nsonda;
            printsonda(quntdsondas);
            scanf("%f %f %f %f %f", &Nsonda.Latitude, &Nsonda.Longitude,&Nsonda.capacidade,&velocidade_i,&combustivel_i);
            Inicializar_sonda(&Nsonda,Nsonda.Latitude,Nsonda.Longitude,Nsonda.capacidade);
            LInsere_s(&lista_sonda, &Nsonda);
        }
    
    
        printquntdoperacoes();
        scanf("%d",&quntdoperacoes);
        FLvazia_e(&lista_e);
        
        for (i = 0; i < quntdoperacoes; i++){
            printmenu();
            scanf(" %c",&operacao);
            
            if(operacao=='R'){
                j = 0;
                printRochanova();
                getchar();
                fgets(entrada, 255, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';

                token = strtok(entrada,s);
                latitude = atof(token);
                token = strtok(NULL,s);
                longitude = atof(token);
                token = strtok(NULL, s);
                peso = atoi(token);
            
                while( token!= NULL ) {
                    token = strtok(NULL,s);
                    if (token!=NULL){
                        entradaminerais entradam;
                        entradaminerais m1 = InicializarMinerale(&entradam,token);
                        LInsere_e(&lista_e, m1);
                        j++;
                    }       
                }
            
                Trocha rnova;
                classifica_categoria(&lista_e,&rnova,j);
                Lretira_e(&lista_e);
                Trocha r1 = InicializaRocha(&rnova,1, peso, latitude, longitude);
                TSonda *sondamaisprox = Calculo_sonda_prox(&lista_sonda, &rnova);
                LInsere(&sondamaisprox->compartimento,&rnova);

                
            }
            else if (operacao== 'I'){
                Operacao_i(&lista_sonda);
            }
            else if (operacao== 'E'){
                OperacaoE(&lista_sonda);
            }
            else{
                printf ("operacao invalido");
            }
            
        }

    }

}