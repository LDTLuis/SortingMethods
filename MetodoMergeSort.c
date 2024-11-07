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

void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
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
    mergeSort(vec, 0, TAM - 1);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordenação (Ordenação por MergeSort): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;

}
