#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct Pasta {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    struct Pasta* subpastas[10];
    int qtd_sub;
    int nivel;
} Pasta;

// variável global para contagem de ciclos 
long ciclos = 0;

// recursiva- refatorado com ponteiros
float processarRecursivo(Pasta* p, int limite) {
    ciclos++; //conta a entrada na função
    p->tamanho_total = p->tamanho_proprio;

    if (p->nivel <= limite) {
        for (int i = 0; i < p->qtd_sub; i++) {
            p->subpastas[i]->nivel = p->nivel + 1;
            p->tamanho_total += processarRecursivo(p->subpastas[i], limite);
        }
    }
    return p->tamanho_total;
}

// parte interativa 
typedef struct { Pasta* p; int idx; } Pilha;

void processarIterativo(Pasta* raiz, int limite) {
    Pilha stack[MAX_PASTAS];
    int topo = 0;
    stack[0] = (Pilha){raiz, 0};

    while (topo >= 0) {
        //conta cada interaçao
        ciclos++; 
        Pasta* atual = stack[topo].p;
        int i = stack[topo].idx;

        if (i == 0) atual->tamanho_total = atual->tamanho_proprio;

        if (i < atual->qtd_sub && atual->nivel < limite) {
            stack[topo].idx++;
            Pasta* filho = atual->subpastas[i];
            filho->nivel = atual->nivel + 1;
            stack[++topo] = (Pilha){filho, 0};
        } else {
            if (topo > 0) stack[topo - 1].p->tamanho_total += atual->tamanho_total;
            topo--;
        }
    }
}

// função utilitária , resetar tamanhos antes de cada teste
void resetarDados(Pasta* drive) {
    for(int i=0; i<4; i++) drive[i].tamanho_total = 0;
}

int main() {
    Pasta drive[4];
    strcpy(drive[0].nome, "RAIZ"); drive[0].tamanho_proprio = 10.0;
    strcpy(drive[1].nome, "Projetos_TI"); drive[1].tamanho_proprio = 50.0;
    strcpy(drive[2].nome, "Backups_Antigos"); drive[2].tamanho_proprio = 350.0;
    strcpy(drive[3].nome, "Videos_Aulas"); drive[3].tamanho_proprio = 280.0;

    drive[0].subpastas[0] = &drive[1]; drive[0].subpastas[1] = &drive[2]; drive[0].qtd_sub = 2;
    drive[1].subpastas[0] = &drive[3]; drive[1].qtd_sub = 1;
    drive[2].qtd_sub = 0; drive[3].qtd_sub = 0;

    int limite = 2;
    clock_t t;

    // teste recursivo 
    resetarDados(drive);
    ciclos = 0;
    drive[0].nivel = 0;
    t = clock();
    processarRecursivo(&drive[0], limite);
    t = clock() - t;
    printf("RECURSIVO: Ciclos: %ld | Tempo: %f s\n", ciclos, ((double)t)/CLOCKS_PER_SEC);

    // teste iterativp
    resetarDados(drive);
    ciclos = 0;
    drive[0].nivel = 0;
    t = clock();
    processarIterativo(&drive[0], limite);
    t = clock() - t;
    printf("ITERATIVO: Ciclos: %ld | Tempo: %f s\n", ciclos, ((double)t)/CLOCKS_PER_SEC);

    return 0;
}