#include <stdio.h>
#include "recursao.h"

// converte decimal para binario usando recursividade
void decToBin(int n)
{
    if (n > 1)
    {
        decToBin(n / 2);
    }

    printf("%d", n % 2);
}

// calcula potencia usando recursividade
int potencia(int base, int exp)
{
    // caso base
    if (exp == 0)
    {
        return 1;
    }

    // chamada recursiva
    return base * potencia(base, exp - 1);
}

// soma os digitos usando recursividade
int somaDigitos(int n)
{
    // caso base
    if (n == 0)
    {
        return 0;
    }

    // soma ultimo digito + chamada recursiva
    return (n % 10) + somaDigitos(n / 10);
}
