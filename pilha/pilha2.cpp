/*
Exemplo do uso de pilha.

Prof. Me. Orlando Saraiva Jr
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *next;
};

struct pilha {
    node* top;
    int size;
};

pilha* inicializar() {
    // pilha* s = (pilha*) malloc(sizeof(pilha));
    pilha* s = new pilha;
    s->size = 0; // Setar o tamanho da pilha como zero.
    s->top = NULL; // o topo da pilha é NULL
    return s;
}

void push(pilha* s, int value) {
    node* ptr_node; // Criar um ponteiro de node (nó)

    // ptr_node = (node*) malloc(sizeof(node)); // Alocar node na memória
    ptr_node = new node;
    if(ptr_node == NULL) {
        exit(1);
    }

    ptr_node->item = value; // Setar o valor no node.
    ptr_node->next = s->top; // Copiar o último endereço que estará no topo da pilha
    s->top = ptr_node; // O topo está apontando para o novo node criado .

    s->size++; // Incrementar o tamanho do contador de pilha
}

int pop(pilha* s) {
    int temp;
    node* ptr_node;

    if(s->top == NULL) {
        exit(1);
    }

    ptr_node = s->top; // Um ponteiro de nó está apontando para o topo da pilha.
    temp = s->top->item; // armazenar em temp o valor corrente do topo da pilha.
    s->top = ptr_node->next; // fazer o topo da pilha apontar para o nó abaixo
    s->size--; // decrementar o tamanho da pilha
    //free(ptr_node); // desalocar o nó topo
    delete(ptr_node);
    return temp; // retornar o valor desempilhado
}

void destruir_pilha(pilha* s) {
    while(s->top != NULL) {
        pop(s);
    }
    pop(s);
    free(s);
}

void imprime_pilha(pilha* s) {
	node* temp;

    if(s->top == NULL) {
        return;
    }
	temp = s->top;
    printf("# %d \n", s->size);
	while(temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}

	printf("\n");
}

int main() {
    int valor;

    pilha* minha_pilha = inicializar();
    imprime_pilha(minha_pilha);
    push(minha_pilha, 7);
    imprime_pilha(minha_pilha);
    push(minha_pilha, 9);
    push(minha_pilha, 3);
    push(minha_pilha, 6);
    push(minha_pilha, 2);
    push(minha_pilha, 1);
    imprime_pilha(minha_pilha);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    imprime_pilha(minha_pilha);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    destruir_pilha(minha_pilha);
    return 0;
}
