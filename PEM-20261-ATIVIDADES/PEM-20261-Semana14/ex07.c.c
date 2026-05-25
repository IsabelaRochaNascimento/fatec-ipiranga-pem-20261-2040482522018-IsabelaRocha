#include <stdio.h>

int main() {
    float vet[10];
    float soma = 0, media, maior, menor, somaAcimaMedia = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vet[i]);
        
        soma += vet[i];
        if (i == 0) {
            maior = vet[i];
            menor = vet[i];
        } else {
            if (vet[i] > maior) maior = vet[i];
            if (vet[i] < menor) menor = vet[i];
        }
    }

    media = soma / 10.0f;
    
    for (int i = 0; i < 10; i++) {
        if (vet[i] > media) {
            somaAcimaMedia += vet[i];
        }
    }

    printf("\nMedia: %.2f\n", media);
    printf("Maior: %.2f | Menor: %.2f\n", maior, menor);
    printf("Soma dos valores acima da media: %.2f\n", somaAcimaMedia);

    return 0;
}