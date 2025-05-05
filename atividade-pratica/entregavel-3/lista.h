#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 100

typedef int TipoChave;

typedef struct tipolista {
    TipoChave elementos[MAX];
    int tamanho;
} TipoLista;

// Funções do TAD Lista
void fazlistavazia(TipoLista *lista);
int insere_lista(TipoLista *lista, TipoChave chave);
int busca_e_remove_da_lista(TipoLista *lista, TipoChave chave);
int tamanho_lista(TipoLista *lista);
int remove_primeiro_da_lista(TipoLista *lista, TipoChave *chave);

#endif // LISTA_H_INCLUDED
