#include <stdio.h>
#include "conjunto.c"

int main() {
    ConjuntodeInteiros conjunto;
    int max, min;

    fazConjuntoVazio(&conjunto);

    insereuNoConjunto(10, &conjunto);
    insereuNoConjunto(25, &conjunto);
    insereuNoConjunto(5, &conjunto);
    insereuNoConjunto(30, &conjunto);
    insereuNoConjunto(15, &conjunto);
    insereuNoConjunto(10, &conjunto);

    printf("Conjunto atual: ");
    imprimeConjunto(&conjunto);

    printf("Pertence ao conjunto (25)? %d\n", pertenceAoConjunto(25, &conjunto));
    printf("Pertence ao conjunto (100)? %d\n", pertenceAoConjunto(100, &conjunto));

    printf("Removendo 25 do conjunto... Resultado: %d\n", retiraDoConjunto(25, &conjunto));
    printf("Removendo 100 do conjunto... Resultado: %d\n", retiraDoConjunto(100, &conjunto));

    printf("Conjunto após remoções: ");
    imprimeConjunto(&conjunto);

    if (maxDoConjunto(&max, &conjunto))
        printf("Maior elemento: %d\n", max);
    else
        printf("Conjunto vazio. Não foi possível obter o maior elemento.\n");

    if (maxMinDoConjunto(&max, &min, &conjunto))
        printf("MaxMin (v1): Max = %d | Min = %d\n", max, min);
    else
        printf("Conjunto vazio. Não foi possível obter max/min.\n");

    if (maxMinDoConjunto2(&max, &min, &conjunto))
        printf("MaxMin (v2): Max = %d | Min = %d\n", max, min);
    else
        printf("Conjunto vazio. Não foi possível obter max/min.\n");

    return 0;
}
