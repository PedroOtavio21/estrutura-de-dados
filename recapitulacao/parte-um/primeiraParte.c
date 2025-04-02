/*
Arquivo resposável para recapitular o básico de C, após 2 anos sem praticar as principais 
funcionalidades da linguagem
*/

#include <stdio.h>

int main(){

    /*
    char nome[50];

    printf("Digite o seu nome: ");
    scanf("%s", nome);

    printf("Olá, %s! Bem-vindo ao mundo da programação em C!", nome);
    */
    
    /*
    int num1;
    int num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("\nDigite o segundo número: ");
    scanf("%d", &num2);

    printf("A soma de %d e %d é %d", num1, num2, (num1 + num2));
    */

    /*
    float largura;
    float altura;

    printf("Digite a largura: ");
    scanf("%f", &largura);
    printf("\nDigite a altura: ");
    scanf("%f", &altura);

    float areaRetangulo = altura * largura;

    printf("A ára do retângulo é %.2f", areaRetangulo);
    */

    char caractere;

    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    printf("O código ASCII do caractere '%c' é %d.", caractere, caractere);

    return 0;
}