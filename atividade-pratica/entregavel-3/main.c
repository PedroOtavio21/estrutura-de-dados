#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX_TAREFAS 100

int main() {
    int n, j, k;

    printf("Digite o número de tarefas: ");
    scanf("%d", &n);

    TipoLista entraem[MAX_TAREFAS], saide[MAX_TAREFAS];
    int foiprasaida[MAX_TAREFAS] = {0};
    int ordemdesaida[MAX_TAREFAS] = {0};

    for (int i = 1; i <= n; i++) {
        fazlistavazia(&entraem[i]);
        fazlistavazia(&saide[i]);
    }

    printf("Digite os pares (j,k) de pré-requisitos (0 0 para parar):\n");
    while (1) {
        scanf("%d %d", &j, &k);
        if (j == 0 && k == 0)
            break;
        insere_lista(&entraem[k], j);
        insere_lista(&saide[j], k);
    }

    for (int i = 1; i <= n; i++) {
        int w = -1;
        for (int t = 1; t <= n; t++) {
            if (tamanho_lista(&entraem[t]) == 0 && !foiprasaida[t]) {
                w = t;
                break;
            }
        }
        if (w == -1) {
            printf("Erro: Pré-requisitos são impossíveis!\n");
            return 1;
        }

        while (tamanho_lista(&saide[w]) > 0) {
            int t;
            remove_primeiro_da_lista(&saide[w], &t);
            busca_e_remove_da_lista(&entraem[t], w);
        }
        ordemdesaida[i] = w;
        foiprasaida[w] = 1;
    }

    printf("Ordem de saída das tarefas:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ordemdesaida[i]);
    }
    printf("\n");

    return 0;
}
