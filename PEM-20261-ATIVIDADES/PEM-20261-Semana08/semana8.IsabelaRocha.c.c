#include <stdio.h>


void processarCarga(float *ptr_vetor, int n) {
    float soma = 0.0, media = 0.0;
    
    // calcular a média aritmética dos pesos
    for (int i = 0; i < n; i++) {
        soma += *(ptr_vetor + i); // aritmética de ponteiros
    }
    media = soma / n;
    
    printf("\n--- Relatorio de Processamento ---");
    printf("\nMedia do lote: %.2f kg", media);
    printf("\nLimite (Media + 10%%): %.2f kg\n", media * 1.10);

    // localizar pesos que excedam a média em mais de 10%
    for (int i = 0; i < n; i++) {
        float *enderecoAtual = (ptr_vetor + i);
        
        if (*enderecoAtual > (media * 1.10)) {
            // aplicar correção de -5% diretamente no endereço de memória
            *enderecoAtual = (*enderecoAtual) * 0.95;
            printf("Peso na posicao [%d] corrigido para: %.2f kg\n", i, *enderecoAtual);
        }
    }
}

//função principal com inicialização do vetor.
int main() {
    // vetor de 10 pacotes inicializado 
    float pesos[10] = {120.5, 150.0, 80.2, 200.5, 110.0, 95.4, 300.0, 105.0, 115.8, 140.0};
    int tamanho = 10;

    //exibir estado antes do processamento
    printf("ESTADO ANTERIOR DO VETOR:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", pesos[i]);
    }
    printf("\n");

    // chamada da função passando o ponteiro do vetor 
    processarCarga(pesos, tamanho);

    // exibir estado após o processamento
    printf("\nESTADO ATUALIZADO DO VETOR:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", pesos[i]);
    }
    printf("\n");

    return 0;
}