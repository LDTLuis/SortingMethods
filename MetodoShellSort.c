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

void shellSort(int *vec, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
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
    printf("Tempo gasto na impress�o do array: %f segundos\n", tempoGasto);

    comeco = clock();
    shellSort(vec, TAM);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordena��o (Ordena��o por ShellSort): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;

}
