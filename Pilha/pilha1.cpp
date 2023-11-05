/*
Exemplo do uso de pilha com uso de vetor.

Prof. Me. Orlando Saraiva Jr
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;

#define STACK_MAX 6

struct pilha {
    int data[STACK_MAX];
    int size;
};

void inicializar(pilha* ponteiro_pilha) {
    ponteiro_pilha->size = 0;
}

void push(pilha* ponteiro_pilha, int d) {
    if(ponteiro_pilha->size < STACK_MAX) {
        ponteiro_pilha->data[ponteiro_pilha->size++] = d;
    }
    else {
        fprintf(stderr, "Erro: pilha cheia\n");
    }
}

int pop(pilha* ponteiro_pilha) {
    int retorno;
    if (ponteiro_pilha->size == 0) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(-1);
    }
    else {
        retorno = ponteiro_pilha->data[--ponteiro_pilha->size];
        ponteiro_pilha->data[ponteiro_pilha->size] = 0;
        return(retorno);
    }
}

void imprime_pilha(pilha* ponteiro_pilha) {
    int x;
    for(x = ponteiro_pilha->size; x > 0 ; x--)
        cout << ponteiro_pilha->data[x-1];
    printf("\n");
}

int main() {
    pilha minhaPilha;
    int valor;

    inicializar(&minhaPilha);

    push(&minhaPilha, 3);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 1);
    imprime_pilha(&minhaPilha);

    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);

}
