#include <stdio.h>

int main() {
    int n, passos = 0;

    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    // entrada
    if (n <= 0) {
        printf("Erro: O valor deve ser estritamente positivo.\n");
        return 1;
    }

    printf("Sequencia: %d", n);
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        printf(" -> %d", n);
        passos++;
    }

    printf("\nPassos necessarios: %d\n", passos);
    return 0;
}