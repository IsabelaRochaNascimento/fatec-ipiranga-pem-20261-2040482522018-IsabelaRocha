#include <stdio.h>

void exibirTabuleiro(int t[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) printf("%d ", t[i][j]);
        printf("\n");
    }
}

int verificarSimetria(int t[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if (t[i][j] != t[j][i]) return 0; // nao simetrico
        }
    }
    return 1;
}

void exibirDiagonais(int t[4][4]) {
    printf("Diagonal Principal: ");
    for(int i=0; i<4; i++) printf("%d ", t[i][i]);
    printf("\nDiagonal Secundaria: ");
    for(int i=0; i<4; i++) printf("%d ", t[i][3 - i]);
    printf("\n");
}

int main() {
    int tabuleiro[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 1},
        {4, 7, 1, 5}
    };

    printf("Grade do Tabuleiro:\n");
    exibirTabuleiro(tabuleiro);
    
    printf("\n");
    exibirDiagonais(tabuleiro);

    if (verificarSimetria(tabuleiro)) {
        printf("\nTodos os pares estao em posicoes simetricas!\n");
    } else {
        printf("\nOs pares NAO estao em posicoes simetricas.\n");
    }

    return 0;
}