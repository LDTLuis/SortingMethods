#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 50000

void preencherArray(int vec[]) {

    for(int i = 0; i < TAM; i++) {
        vec[i] = rand() % 200000 + 1;
    }

}

void imprimirArray (int vec[]) {

    printf("\n");

    for(int i = 0; i < 100 && i < TAM; i++) {
        printf("%5d ", vec[i]);
    }

    printf("...\n");

    for (int i = TAM - 100; i < TAM; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");

}

int partition(int *vec, int low, int high) {
    int pivo = vec[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (vec[j] < pivo) {
            i++;
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    int temp = vec[i + 1];
    vec[i + 1] = vec[high];
    vec[high] = temp;
    return i + 1;
}

void quickSort(int *vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


int main (void) {

    int vec[TAM];

    srand(time(NULL));

    preencherArray(vec);

    clock_t comeco = clock();
    imprimirArray(vec);
    clock_t fim = clock();

    double tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo gasto na impressão do array: %f segundos\n", tempoGasto);

    comeco = clock();
    quickSort(vec, 0, TAM - 1);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordenação (Ordenação por Partição): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;

}
