#include <stdio.h>

int main() {
    // tipos:
    // int: suporta ate 2.147.483.647, ideal para a distancia maxima exigida
    // float: precisao suficiente para metros
    // double: maior precisao para quilometros e milhas para evitar perdas em divisoes
    int cm;
    float metros;
    double km, milhas;

    printf("Digite a distancia em centimetros: ");
    scanf("%d", &cm);

    // veerificacao se o valor é positivo
    if (cm < 0) {
        printf("Erro: A distancia deve ser um valor positivo.\n");
    } else {
        metros = cm / 100.0f;
        km = cm / 100000.0;
        milhas = km / 1.60934;

        printf("\nResultados:\n");
        printf("Metros: %.2fm\n", metros);
        printf("Quilometros: %.5f km\n", km);
        printf("Milhas: %.5f mi\n", milhas);
    }

    return 0;
}