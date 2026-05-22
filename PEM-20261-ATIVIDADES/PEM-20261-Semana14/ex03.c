#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso em (kg) e a altura em (m): ");
    scanf("%f %f", &peso, &altura);

    // para entradas invalidas, da erro
    if (peso <= 0 || altura <= 0) {
        printf("Erro: Peso e altura devem ser maiores que zero.\n");
    } else {
        imc = peso / (altura * altura);
        printf("IMC: %.2f - ", imc);

        // If  para classificacao
        if (imc < 18.5) {
            printf("Abaixo do peso\n");
        } else if (imc < 25.0) {
            printf("Peso normal\n");
        } else if (imc < 30.0) {
            printf("Sobrepeso\n");
        } else {
            printf("Obesidade\n");
        }
    }

    return 0;
}