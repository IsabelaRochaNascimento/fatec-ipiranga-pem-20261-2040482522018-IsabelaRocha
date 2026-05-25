#include <stdio.h>

long long movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        movimentos++;
        return;
    }
    
    hanoi(n - 1, origem, auxiliar, destino);
    
    printf("Mova disco %d de %c para %c\n", n, origem, destino);
    movimentos++;
    
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    printf("Digite o numero de discos (1 a 70): ");
    scanf("%d", &n);

    if(n < 1 || n > 70) {
        printf("Valor invalido.\n");
        return 1;
    }

    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal de movimentos: %lld\n", movimentos);
    return 0;
}