#include "busca.h"

int busca_binaria(int array[], int inicio, int fim, int elemento, int *comparacoes) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2; // Determina o meio do array
        int chute = array[meio]; // declaração de variável para verificação
        
        (*comparacoes)++;  // Comparação com o elemento central

        if (chute == elemento) {
            return 1;
        } else if (chute < elemento) {
            inicio = meio + 1; // determina novo início
        } else {
            fim = meio - 1; // determina novo fim
        }
    }

    return 0;
}
