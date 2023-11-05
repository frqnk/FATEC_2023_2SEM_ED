/*
Escreva um programa com uma função chamada soma. Este programa deve somar todos os valores entre 0 e n, onde n é o parâmetro passado para a função.

Exemplo: n = 5, o retorno da função será 15 (5+4+3+2+1).

Utilize recursividade
*/
#include <stdio.h>

int soma(int valor) {
    return valor > 0 ? valor + soma(valor-1) : 0;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%i", &n);
    printf("A soma dos valores entre 0 e n é %i", soma(n));
    return 0;
}