#include <iostream>

using namespace std;

struct pessoa {
    string nome, sobrenome;
};

struct node {
    pessoa pessoa;
    node *proximo;
};

struct fila {
    node *inicio;
    node *fim;
    int tamanho;
};

void inicializa_fila(fila *);
void entra_na_fila(fila *, string, string);
void sai_da_fila(fila *);
void sai_da_fila(fila *, int);
void mostra_fila(fila);

int main() {
    fila fila_qualquer;
    inicializa_fila(&fila_qualquer);

    entra_na_fila(&fila_qualquer, "Neil", "Richard MacKinnon Gaiman");
    entra_na_fila(&fila_qualquer, "Ronald", "Belford Scott");
    entra_na_fila(&fila_qualquer, "Blaise", "Pascal");

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer);

    entra_na_fila(&fila_qualquer, "Rogério", "Tolomei Teixeira");
    entra_na_fila(&fila_qualquer, "Pavel", "Valerievitch Durov");
    entra_na_fila(&fila_qualquer, "Ole", "Kirk Christiansen");

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer, 2);

    entra_na_fila(&fila_qualquer, "Bror", "Jan Alfredo Marcolin");
    entra_na_fila(&fila_qualquer, "Robert", "Norman Ross");
    entra_na_fila(&fila_qualquer, "Douglas", "Noël Adams");

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer, 6);
}

void inicializa_fila(fila *f) {
    (*f) = {
        .inicio = NULL,
        .fim = NULL,
        .tamanho = 0
    };
}

void entra_na_fila(fila *f, string n, string sn) {
    node *novo = new node;
    if(!novo) {
        cerr << "\nmemória esgotada\n";
        exit(1);
    }
    novo->pessoa = {n, sn};
    novo->proximo = NULL;
    if (!f->tamanho++) {
        f->inicio = f->fim = novo;
    }
    else {
        f->fim = f->fim->proximo = novo;
    }
    cout << f->tamanho << "\n";
}

void mostra_fila(fila f) {
    node *posicao = f.inicio;
    cout << "fila:\n";
    for (int i = 1; posicao; i++) {
        cout << i << "/" << f.tamanho << " " << posicao->pessoa.nome << '\n';
        posicao = posicao->proximo;
    }
}

void sai_da_fila(fila *f) {
    sai_da_fila(f, 1);
}

void sai_da_fila(fila *f, int n) {
    for (int i = 0; i < n; i++) {
        node *velho = f->inicio;
        f->inicio = f->inicio->proximo;
        delete(velho);
        f->tamanho--;
    }
}
