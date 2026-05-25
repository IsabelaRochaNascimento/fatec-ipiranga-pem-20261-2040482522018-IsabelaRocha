#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void minMax(int *v, int n, int *min, int *max) {
    *min = *v;
    *max = *v;
    for(int i = 1; i < n; i++) {
        if(*(v + i) < *min) *min = *(v + i);
        if(*(v + i) > *max) *max = *(v + i);
    }
}

void normalizaVetor(float *v, int n) {
    float max = *v;
    for(int i = 1; i < n; i++) {
        if(*(v + i) > max) max = *(v + i);
    }
    for(int i = 0; i < n; i++) {
        *(v + i) /= max;
    }
}

int main() {
    int x = 10, y = 20;
    printf("Antes troca: x=%d, y=%d\n", x, y);
    troca(&x, &y);
    printf("Depois troca: x=%d, y=%d\n\n", x, y);

    int v[5] = {12, 5, 23, 8, 1};
    int min, max;
    minMax(v, 5, &min, &max);
    printf("Vetor: Min=%d, Max=%d\n\n", min, max);

    float vf[3] = {2.0f, 5.0f, 10.0f};
    printf("Antes normalizacao: %.1f, %.1f, %.1f\n", vf[0], vf[1], vf[2]);
    normalizaVetor(vf, 3);
    printf("Depois normalizacao: %.1f, %.1f, %.1f\n", vf[0], vf[1], vf[2]);

    return 0;
}