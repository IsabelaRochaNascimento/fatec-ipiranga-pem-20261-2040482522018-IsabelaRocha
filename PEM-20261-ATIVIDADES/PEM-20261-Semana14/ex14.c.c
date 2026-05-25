#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b);
int potencia(int base, int exp);
int ehPrimo(int n);
void decimalParaBinario(int n, char *res);

int main() {
    int opcao, val1, val2;
    char binStr[33];

    do {
        printf("\n--- MENU ---\n");
        printf("1. MDC (Euclides)\n");
        printf("2. Potencia Inteira\n");
        printf("3. Verificador de Primo\n");
        printf("4. Conversao Decimal-Binario\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao >= 1 && opcao <= 4) {
            printf("Digite o valor/valores: ");
        }

        switch(opcao) {
            case 1:
                scanf("%d %d", &val1, &val2);
                printf("MDC: %d\n", mdc(val1, val2));
                break;
            case 2:
                scanf("%d %d", &val1, &val2);
                printf("Resultado: %d\n", potencia(val1, val2));
                break;
            case 3:
                scanf("%d", &val1);
                printf("Primo? %s\n", ehPrimo(val1) ? "Sim" : "Nao");
                break;
            case 4:
                scanf("%d", &val1);
                decimalParaBinario(val1, binStr);
                printf("Binario: %s\n", binStr);
                break;
        }
    } while(opcao != 5);

    return 0;
}

int mdc(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int potencia(int base, int exp) {
    int res = 1;
    for(int i = 0; i < exp; i++) res *= base;
    return res;
}

int ehPrimo(int n) {
    if (n <= 1) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void decimalParaBinario(int n, char *res) {
    int i = 0;
    if(n == 0) { res[0] = '0'; res[1] = '\0'; return; }
    char aux[33];
    while(n > 0) {
        aux[i++] = (n % 2) + '0';
        n /= 2;
    }
    int j;
    for(j = 0; j < i; j++) {
        res[j] = aux[i - 1 - j];
    }
    res[j] = '\0';
}