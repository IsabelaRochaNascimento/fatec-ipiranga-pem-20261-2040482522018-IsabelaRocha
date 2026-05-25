#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chamadasBusca = 0, profBusca = 0, profAtualBusca = 0;
int chamadasSoma = 0, profSoma = 0, profAtualSoma = 0;

int buscaRec(int *v, int n, int chave) {
    chamadasBusca++;
    profAtualBusca++;
    if (profAtualBusca > profBusca) profBusca = profAtualBusca;

   
    if (n <= 0) {
        profAtualBusca--;
        return -1;
    }
    if (v[n - 1] == chave) {
        int idx = n - 1;
        profAtualBusca--;
        return idx;
    }

    int res = buscaRec(v, n - 1, chave);
    profAtualBusca--;
    return res;
}

int somaRec(int *v, int ini, int fim) {
    chamadasSoma++;
    profAtualSoma++;
    if (profAtualSoma > profSoma) profSoma = profAtualSoma;

    if (ini == fim) {
        profAtualSoma--;
        return v[ini];
    }

    int meio = (ini + fim) / 2;
    int s1 = somaRec(v, ini, meio);
    int s2 = somaRec(v, meio + 1, fim);

    profAtualSoma--;
    return s1 + s2;
}

int main() {
    int vetor[12];
    srand(time(NULL));

    printf("Vetor Aleatorio: ");
    for(int i = 0; i < 12; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int soma = somaRec(vetor, 0, 11);
    printf("Soma Total (somaRec): %d\n", soma);
    printf("Soma -> Chamadas: %d | Profundidade Maxima: %d\n\n", chamadasSoma, profSoma);

    int busca;
    printf("Digite um valor para buscar: ");
    scanf("%d", &busca);

    int idx = buscaRec(vetor, 12, busca);
    if(idx != -1) printf("Chave encontrada no indice: %d\n", idx);
    else printf("Valor nao existe no vetor.\n");

    printf("Busca -> Chamadas: %d | Profundidade Maxima: %d\n", chamadasBusca, profBusca);

    return 0;
}