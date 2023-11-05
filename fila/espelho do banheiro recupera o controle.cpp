#include <iostream>

using namespace std;

struct pessoa {
    string nome, sobrenome;
};

struct node {
    node *proximo;
    pessoa pessoa;
};

struct fila {
    node *primeiro_lugar;
    node *ultimo_lugar;
    int tamanho;
};

void inicializa_fila(fila *);
void entra_na_fila(fila *, pessoa);
void sai_da_fila(fila *);
void sai_da_fila(fila *, int);
void mostra_fila(fila);

int main() {
    fila fila_qualquer;
    inicializa_fila(&fila_qualquer);

    entra_na_fila(&fila_qualquer, {"Neil", "Richard MacKinnon Gaiman"});
    entra_na_fila(&fila_qualquer, {"Ronald", "Belford Scott"});
    entra_na_fila(&fila_qualquer, {"Blaise", "Pascal"});

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer, 1);

    entra_na_fila(&fila_qualquer, {"Rogério", "Tolomei Teixeira"});
    entra_na_fila(&fila_qualquer, {"Pavel", "Valerievitch Durov"});
    entra_na_fila(&fila_qualquer, {"Ole", "Kirk Christiansen"});

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer, 2);

    entra_na_fila(&fila_qualquer, {"Bror", "Jan Alfredo Marcolin"});
    entra_na_fila(&fila_qualquer, {"Robert", "Norman Ross"});
    entra_na_fila(&fila_qualquer, {"Douglas", "Noël Adams"});

    mostra_fila(fila_qualquer);

    sai_da_fila(&fila_qualquer, 6);
}

void inicializa_fila(fila *f) {
    *f = {NULL, NULL, 0};
}

void entra_na_fila(fila *f, pessoa p) {
    node *novo = new node;
    novo->pessoa = p;
    f->ultimo_lugar = novo;
    f->tamanho++;
}

void mostra_fila(fila f) {
    node *posicao = f.primeiro_lugar;
    cout << "fila:\n";
    for (int i = 0; i < f.tamanho; i++) {
        cout << i+1 << ". " << posicao->pessoa.nome << '\n';
        posicao = posicao->proximo;
    }
}

void sai_da_fila(fila *f) {
    sai_da_fila(f, 1);
}

void sai_da_fila(fila *f, int n) {
    for (int i = 0; i < n; i++) {
        node *velho = f->primeiro_lugar;
        f->primeiro_lugar = f->primeiro_lugar->proximo;
        delete(velho);
    }
}
