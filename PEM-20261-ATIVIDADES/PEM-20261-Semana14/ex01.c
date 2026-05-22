#include <stdio.h>

int main() {
    double n1, n2, n3;
    int p1, p2, p3;
    double media;

    printf("Digite a nota 1 e seu peso: ");
    scanf("%lf %d", &n1, &p1);
    printf("Digite a nota 2 e seu peso: ");
    scanf("%lf %d", &n2, &p2);
    printf("Digite a nota 3 e seu peso: ");
    scanf("%lf %d", &n3, &p3);

    media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);

    printf("\nMedia Ponderada: %.2f\n", media);
    printf("Tamanho em bytes - double: %zu bytes, int: %zu bytes\n", sizeof(double), sizeof(int));

    return 0;
}