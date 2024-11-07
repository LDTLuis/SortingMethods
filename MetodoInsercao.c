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

void ordenacaoInsercao(int *vec, int size) {
    for (int i = 1; i < size; i++) {
        int chave = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > chave) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = chave;
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
    ordenacaoInsercao(vec, TAM);
    fim = clock();

    tempoGasto = (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("\nTempo gasto na ordena��o (Ordena��o por Inser��o): %f segundos\n", tempoGasto);

    imprimirArray(vec);

    return 0;

}
