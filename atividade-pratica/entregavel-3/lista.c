#include "lista.h"

int tamanho_lista(TipoLista *lista) {
    return lista->tamanho;
}
void fazlistavazia(TipoLista *lista) {
    lista->tamanho = 0;
}
int insere_lista(TipoLista *lista, TipoChave chave){
    if (lista->tamanho >= MAX) {
        return 0; // Lista cheia
    }
    lista->elementos[lista->tamanho] = chave;
    lista->tamanho++;
    return 1;
}
int busca_e_remove_da_lista(TipoLista *lista, TipoChave chave) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == chave) {
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->elementos[j] = lista->elementos[j + 1];
            }
            lista->tamanho--;
            return 1;
        }
    }
    return 0; // Elemento não encontrado
}
int remove_primeiro_da_lista(TipoLista *lista, TipoChave *chave) {
    if (lista->tamanho == 0) {
        return 0; // Lista vazia
    }
    *chave = lista->elementos[0];
    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1;
}
