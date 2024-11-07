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

void heapify(int *array, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        heapify(array, size, largest);
    }
}

void heapSort(int *array, int size) {

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {

        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
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
    heapSort(vec, TAM);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordenação (Ordenação por HeapSort): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;

}
