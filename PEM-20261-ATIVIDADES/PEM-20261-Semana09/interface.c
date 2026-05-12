#include <stdio.h>
#include "interface.h"
#include "recursao.h"

// mostra menu principal
void mostrarMenu()
{
    printf("\nsistema cucc\n");
    printf("1 - decimal para binario\n");
    printf("2 - potencia\n");
    printf("3 - soma de digitos\n");
    printf("0 - sair\n");
    printf("escolha: ");
}

// menu da conversao binaria
void menuBinario()
{
    int numero;

    printf("digite um numero decimal: ");
    scanf("%d", &numero);

    printf("binario: ");
    decToBin(numero);
    printf("\n");
}

// menu da potencia
void menuPotencia()
{
    int base;
    int expoente;
    int resultado;

    printf("digite a base: ");
    scanf("%d", &base);

    printf("digite o expoente: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("resultado: %d\n", resultado);
}

// menu soma de digitos
void menuSomaDigitos()
{
    int numero;
    int resultado;

    printf("digite um numero: ");
    scanf("%d", &numero);

    resultado = somaDigitos(numero);

    printf("soma dos digitos: %d\n", resultado);
}
