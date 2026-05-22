#include <stdio.h>

int main() {
    char opcao;

    do {
        // laço com o for 
        for (int i = 1; i <= 10; i++) {
            printf("Tabuada do %d:\n", i);
            int j = 1;
            // laço com while
            while (j <= 10) {
                printf("%d x %2d = %2d\n", i, j, i * j);
                j++;
            }
            printf("\n");
        }

        // continuaçao com do while
        do {
            printf("Deseja continuar? (S/N): ");
            scanf(" %c", &opcao);
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

    } while (opcao == 'S' || opcao == 's');

    return 0;
}