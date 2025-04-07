#include <stdio.h>

// Declaração antecipada de funções auxiliares
void showData(int var, int *ptr);
void modify(int *ptr);

int main(){
    // Declaração de variável principal
    int var = 15;

    // Declaração e atribuição de valor por referência ao ponteiro
    int *ptr;
    ptr = &var;

    // Informa os valores atuais das duas variáveis
    showData(var, ptr);

    // Altera o valor presente dentro do ponteiro (modificando tbm a variável!)
    modify(ptr);

    // Informa novamente as duas variáveis atualizadas!
    showData(var, ptr);

    return 0;
}

// Função responsável por informar o conteúdo atualizado das variáveis
void showData(int var, int *ptr){
    printf("\n\n");
    printf("Conteúdo da variável: %d\n", var);
    printf("Conteúdo do endereço da variável: %p\n", &var);
    printf("Conteúdo apontado pelo ponteiro: %d\n", *ptr);
    printf("Endereço do conteúdo apontado pelo ponteiro: %p\n", ptr);
    printf("Conteúdo do endereço do ponteiro: %p\n", &ptr);
}

// Altera o valor que se encontra no endereço, armazenado pelo ponteiro (passado por referência)
void modify(int *ptr){
    *ptr += 1;
}