#include <stdio.h>
#include "conjunto.h"

void fazConjuntoVazio(ConjuntodeInteiros *conjunto) {
    conjunto->tamanho = 0;
}

void imprimeConjunto(ConjuntodeInteiros *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d", conjunto->elementos[i]);
        if (i < conjunto->tamanho - 1)
            printf(", ");
    }
    printf(" }\n");
}

int insereuNoConjunto(int elem, ConjuntodeInteiros *conjunto) {
    if (conjunto->tamanho >= MAX_SIZE)
        return 0;

    if (pertenceAoConjunto(elem, conjunto))
        return 0;

    conjunto->elementos[conjunto->tamanho] = elem;
    conjunto->tamanho++;
    return 1;
}

int pertenceAoConjunto(int elem, ConjuntodeInteiros *conjunto) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elem)
            return 1;
    }
    return 0;
}

int retiraDoConjunto(int elem, ConjuntodeInteiros *conjunto) {
    if (conjunto->tamanho == 0)
        return 0;

    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elem) {
            for (int j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            return 1;
        }
    }
    return 0;
}

int maxDoConjunto(int *elem, ConjuntodeInteiros *conjunto) {
    if (conjunto->tamanho == 0)
        return 0;

    *elem = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] > *elem)
            *elem = conjunto->elementos[i];
    }
    return 1;
}

int maxMinDoConjunto(int *maiorElem, int *menorElem, ConjuntodeInteiros *conjunto) {
    if (conjunto->tamanho == 0)
        return 0;

    *maiorElem = *menorElem = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] > *maiorElem)
            *maiorElem = conjunto->elementos[i];
        if (conjunto->elementos[i] < *menorElem)
            *menorElem = conjunto->elementos[i];
    }
    return 1;
}

int maxMinDoConjunto2(int *maiorElem, int *menorElem, ConjuntodeInteiros *conjunto) {
    if (conjunto->tamanho == 0)
        return 0;

    int i = 0;

    if (conjunto->tamanho % 2 == 0) {
        if (conjunto->elementos[0] > conjunto->elementos[1]) {
            *maiorElem = conjunto->elementos[0];
            *menorElem = conjunto->elementos[1];
        } else {
            *maiorElem = conjunto->elementos[1];
            *menorElem = conjunto->elementos[0];
        }
        i = 2;
    } else {
        *maiorElem = *menorElem = conjunto->elementos[0];
        i = 1;
    }

    while (i < conjunto->tamanho - 1) {
        int maior = (conjunto->elementos[i] > conjunto->elementos[i + 1]) ? conjunto->elementos[i] : conjunto->elementos[i + 1];
        int menor = (conjunto->elementos[i] < conjunto->elementos[i + 1]) ? conjunto->elementos[i] : conjunto->elementos[i + 1];

        if (maior > *maiorElem) *maiorElem = maior;
        if (menor < *menorElem) *menorElem = menor;

        i += 2;
    }

    return 1;
}
