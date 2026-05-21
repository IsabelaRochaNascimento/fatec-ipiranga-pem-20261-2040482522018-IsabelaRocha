#include <stdio.h>
#include <string.h>

// estruturas auxiliares
typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

typedef struct {
    char nome[40];
    float preco;
    int estoque;
} Produto;

void trocar(int *a, int *b);
void inverter(int *arr, int n);
void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor);
void selectionSort(int *arr, int n);

int main() {
    // EXERCÍCIO 01 e 02: Endereços e Tamanhos
    printf("--- Exercicio 01 & 02 ---\n");
    int iVal = 10; float fVal = 5.5; char cVal = 'A';
    int *pi = &iVal; float *pf = &fVal; char *pc = &cVal;

    printf("Int: Valor %d, End Var %p, End Ptr %p, Valor Ptr %d\n", iVal, (void*)&iVal, (void*)pi, *pi); [cite: 29, 30, 31, 32, 33]
    
    /* Explicação Exercício 02: 
       O tamanho de um ponteiro não varia com o tipo apontado.
       o tamanho desse endereço depende da arquitetura do processador  
    */ [cite: 36, 37]
    printf("Tamanhos de ponteiros: int:%zu, float:%zu, char:%zu\n\n", sizeof(pi), sizeof(pf), sizeof(pc)); [cite: 36]

    // EXERCÍCIO 03: troca de valores
    printf("--- Exercicio 03 ---\n");
    int x = 10, y = 20;
    printf("Antes: x=%d, y=%d\n", x, y); [cite: 54]
    trocar(&x, &y); [cite: 53]
    printf("Depois: x=%d, y=%d\n\n", x, y); [cite: 54]

    // EXERCÍCIO 04: mapa de endereços struct
    printf("--- Exercicio 04 ---\n");
    Aluno a1 = {"Joao", 123, 8.5};
    printf("End. Nome: %p\nEnd. Matrícula: %p\nEnd. Média: %p\n", (void*)&a1.nome, (void*)&a1.matricula, (void*)&a1.media); [cite: 58]
    /* endereços são consecutivos porque os campos de um struct 
       são alocados em sequência na memória, respeitando o alinhamento do hardware. 
    */ [cite: 58]

    // EXERCÍCIO 05: modificação indireta - vetor
    printf("--- Exercicio 05 ---\n");
    int vet5[5] = {1, 2, 3, 4, 5};
    int *pVet5 = vet5;
    printf("Antes: ");
    for(int i=0; i<5; i++) printf("%d ", vet5[i]);
    
    for(int i=0; i<5; i++) {
        *(pVet5 + i) *= 2; // multiplica sem usar []
    } [cite: 75]
    printf("\nDepois: ");
    for(int i=0; i<5; i++) printf("%d ", vet5[i]);
    printf("\n\n");

    // EXERCÍCIO 06: struct por ponteiro
    printf("--- Exercicio 06 ---\n");
    Produto prod;
    Produto *pProd = &prod;
    (*pProd).preco = 15.0; // (*p).campo [cite: 79]
    // Usando seta
    pProd->estoque = 100; // p : campo [cite: 80]
    printf("Preco: %.2f, Estoque: %d\n\n", prod.preco, prod.estoque);

    // EXERCÍCIO 07: percurso com incremento
    printf("--- Exercicio 07 ---\n");
    int vet8[8] = {5, 2, 9, 1, 7, 4, 6, 3};
    int *p8 = vet8, soma = 0, maior = *vet8, menor = *vet8;
    for(int i=0; i<8; i++) {
        int val = *(p8 + i);
        printf("End: %p | Valor: %d\n", (void*)(p8 + i), val); [cite: 97]
        soma += val;
        if(val > maior) maior = val;
        if(val < menor) menor = val;
    }
    printf("Soma: %d, Media: %.2f, Maior: %d, Menor: %d\n\n", soma, (float)soma/8, maior, menor); [cite: 97]

    // EXERCÍCIO 08: distância entre ponteiros
    printf("--- Exercicio 08 ---\n");
    double vDb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double *p3 = &vDb[2], *p8_2 = &vDb[7];
    /* compilador calcula a diferença subtraindo os endereços 
       físicos e dividindo pelo tamanho do tipo 
    */ [cite: 100]
    printf("Distancia: %ld elementos\n", p8_2 - p3); [cite: 100]

    // EXERCÍCIO 09: inversão das array
    printf("--- Exercicio 09 ---\n");
    int vInv[7] = {1, 2, 3, 4, 5, 6, 7};
    inverter(vInv, 7);
    printf("Invertido: ");
    for(int i=0; i<7; i++) printf("%d ", vInv[i]);
    printf("\n\n");

    // EXERCÍCIO 10: busca em matriz - ponteiro linear
    printf("--- Exercicio 10 ---\n");
    int mat[4][4] = {{1,2,3,4},{5,20,7,8},{9,10,11,12},{13,14,15,16}};
    int *pMat = &mat[0][0];
    int mVal = *pMat, mLin = 0, mCol = 0;
    for(int i=0; i<16; i++) {
        if(*(pMat + i) > mVal) {
            mVal = *(pMat + i);
            mLin = i / 4;
            mCol = i % 4;
        }
    } [cite: 121]
    printf("Maior: %d na Posicao (%d, %d)\n\n", mVal, mLin, mCol);

    return 0;
}
// funções
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} [cite: 53]

void inverter(int *arr, int n) {
    int *inicio = arr;
    int *fim = arr + n - 1;
    while(inicio < fim) {
        trocar(inicio, fim);
        inicio++;
        fim--;
    }
} [cite: 118]

void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    *soma = 0;
    *maior = *v;
    *menor = *v;
    for(int i=0; i<n; i++) {
        int atual = *(v + i);
        *soma += atual;
        if(atual > *maior) *maior = atual;
        if(atual < *menor) *menor = atual;
    }
    *media = (float)(*soma) / n;
} [cite: 140]

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int *min = (arr + i);
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) < *min) {
                min = (arr + j);
            }
        }
        if (min != (arr + i)) {
            trocar((arr + i), min);
            // Demonstração opcional do estado a cada troca
            printf("Troca realizada: ");
            for(int k=0; k<n; k++) printf("%d ", *(arr + k));
            printf("\n");
        }
    }
} [cite: 143]