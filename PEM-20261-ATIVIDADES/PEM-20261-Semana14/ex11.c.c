#include <stdio.h>

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int *p = vetor;
    int soma = 0;

    printf("Enderecos e valores:\n");
    for (int i = 0; i < 6; i++) {
        printf("Valor: %d | Endereco: %p\n", *(p + i), (void*)(p + i));
        soma += *(p + i);
    }

    printf("\nSoma dos elementos: %d\n", soma);

    printf("\nDobrando valores inplace:\n");
    for (int i = 0; i < 6; i++) {
        *(p + i) = *(p + i) * 2;
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}