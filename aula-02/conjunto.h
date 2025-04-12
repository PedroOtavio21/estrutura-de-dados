#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} ConjuntodeInteiros;

void fazConjuntoVazio(ConjuntodeInteiros *conjunto);
void imprimeConjunto(ConjuntodeInteiros *conjunto);
int insereuNoConjunto(int elem, ConjuntodeInteiros *conjunto);
int pertenceAoConjunto(int elem, ConjuntodeInteiros *conjunto);
int retiraDoConjunto(int elem, ConjuntodeInteiros *conjunto);
int maxDoConjunto(int *elem, ConjuntodeInteiros *conjunto);
int maxMinDoConjunto(int *maiorElem, int *menorElem, ConjuntodeInteiros *conjunto);
int maxMinDoConjunto2(int *maiorElem, int *menorElem, ConjuntodeInteiros *conjunto);

#endif
