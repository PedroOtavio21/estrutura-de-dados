#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.c"

#define TAMANHO_ARRAY 10000
#define NUM_TESTES 50

// Algoritmo questão 2. a)
int algoritmo(int A[], int n) {
    int i, j, k, x;
    int comparacoes = 0;

    for (i = 0; i <= n - 2; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (A[j] < A[k]) {
                k = j;
            }
        }
        // Troca os elementos entre A[k] e A[i]
        x = A[k];
        A[k] = A[i];
        A[i] = x;
    }

    return comparacoes;
}

int main() {
    int array[TAMANHO_ARRAY];
    int comparacoes_total = 0;
    int i, elemento, comparacoes;

    // Preenche o array com valores de 1 a 10000
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        array[i] = i + 1;
    }

    // --- Parte da Questão 1: Busca Binária Média ---
    srand(time(NULL));
    for (i = 0; i < NUM_TESTES; i++) {
        elemento = rand() % TAMANHO_ARRAY + 1;
        comparacoes = 0;
        busca_binaria(array, 0, TAMANHO_ARRAY - 1, elemento, &comparacoes);
        comparacoes_total += comparacoes;
    }
    double media_comparacoes = (double)comparacoes_total / NUM_TESTES;
    printf("Media de comparacoes na busca binaria: %.2f\n", media_comparacoes);

    // --- Parte da Questão 2: Algoritmo de ordenação ---
    // Criar nova cópia do array (porque ele já está ordenado)
    int array2[TAMANHO_ARRAY];
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        array2[i] = i + 1;
    }

    int comparacoes_alg2 = algoritmo(array2, TAMANHO_ARRAY);
    printf("Numero de comparacoes no algoritmo da questao 2: %d\n", comparacoes_alg2);

    return 0;
}
