#include <stdio.h>

#define N 8

int main() {
    int v1[N], v2[N];
    int maior, idx_maior = 0, menor, idx_menor = 0;
    int pares = 0, impares = 0;
    int busca, achou = -1;

    for (int i = 0; i < N; i++) {
        printf("v1[%d]: ", i);
        scanf("%d", &v1[i]);

        if (i == 0) {
            maior = v1[i];
            menor = v1[i];
        } else {
            if (v1[i] > maior) { maior = v1[i]; idx_maior = i; }
            if (v1[i] < menor) { menor = v1[i]; idx_menor = i; }
        }

        if (v1[i] % 2 == 0) pares++; else impares++;
    }

    //vetor inverso
    for (int i = 0; i < N; i++) {
        v2[i] = v1[N - 1 - i];
    }

    printf("\nMaior: %d no indice %d\n", maior, idx_maior);
    printf("Menor: %d no indice %d\n", menor, idx_menor);
    printf("Pares: %d | Impares: %d\n", pares, impares);

    printf("Vetor Inverso: ");
    for (int i = 0; i < N; i++) printf("%d ", v2[i]);

    printf("\n\nDigite um valor para busca linear: ");
    scanf("%d", &busca);

    for (int i = 0; i < N; i++) {
        if (v1[i] == busca) {
            achou = i;
            break;
        }
    }

    if (achou != -1) 
    printf("Valor encontrado no indice: %d\n", achou);
    else 
    printf("Valor nao existe no vetor.\n");

    return 0;
}