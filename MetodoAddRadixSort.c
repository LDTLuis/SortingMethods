#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 50000
#define MAX_VAL 200000

void preencherArray(int vec[]) {
    for(int i = 0; i < TAM; i++) {
        vec[i] = rand() % MAX_VAL + 1;
    }
}

void imprimirArray(int vec[]) {
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

void countingSortDigit(int *vec, int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        int digit = (vec[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = (vec[i] / exp) % 10;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        vec[i] = output[i];
    }
}

void radixSort(int *vec, int size) {
    int max = vec[0];
    for (int i = 1; i < size; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortDigit(vec, size, exp);
    }
}

int main(void) {
    int vec[TAM];
    srand(time(NULL));

    preencherArray(vec);

    clock_t comeco = clock();
    imprimirArray(vec);
    clock_t fim = clock();

    double tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo gasto na impressão do array: %f segundos\n", tempoGasto);

    comeco = clock();
    radixSort(vec, TAM);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordenação (Ordenação por RadixSort): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;
}

