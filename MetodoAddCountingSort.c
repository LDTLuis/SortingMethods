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

void countingSort(int *vec, int size) {
    int count[MAX_VAL + 1] = {0};

    for (int i = 0; i < size; i++) {
        count[vec[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= MAX_VAL; i++) {
        while (count[i] > 0) {
            vec[index++] = i;
            count[i]--;
        }
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
    countingSort(vec, TAM);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordenação (Ordenação por CountingSort): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;
}

