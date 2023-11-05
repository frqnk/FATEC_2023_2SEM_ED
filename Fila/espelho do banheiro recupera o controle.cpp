#include <iostream>

using namespace std;

struct pessoa {
    string nome, sobrenome;
};

struct node {
    pessoa pessoa;
    node *a_frente;
    node *atras;
};

struct fila {
    int tamanho;
    node *primeiro_lugar;
    node *ultimo_lugar;
};

void inicializar_fila(fila *);
void entra_na_fila(fila *, pessoa);
void sai_da_fila(fila *);
void sai_da_fila(fila *, int);
void mostra_fila(fila);

int main() {
    fila fila_qualquer;
    inicializar_fila(&fila_qualquer);

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

void inicializar_fila(fila *f) {
    *f = {0, NULL, NULL};
}

void entra_na_fila(fila *f, pessoa p) {
    node *novo = new node;
    novo->pessoa = p;
    if(f->tamanho == 0) {
        *f = {1, novo, novo};
    }
    else {
        f->tamanho++;
        novo->a_frente = f->ultimo_lugar;
        f->ultimo_lugar = novo;
        novo->a_frente->atras = novo;
    }
}

void mostra_fila(fila f) {
    node *lugar = f.primeiro_lugar;
    cout << "fila:\n";
    for (int i = 0; i < f.tamanho; i++) {
        cout << i+1 << ". " << lugar->pessoa.nome << '\n';
        lugar = lugar->atras;
    }
}

void sai_da_fila(fila *f) {
    sai_da_fila(f, 1);
}

void sai_da_fila(fila *f, int n) {
    for (int i = 0; i < n; i++) {
        if(f->primeiro_lugar->atras != NULL) {
            f->primeiro_lugar = f->primeiro_lugar->atras;
            delete(f->primeiro_lugar->a_frente);
        }
        else {
            delete(f->primeiro_lugar);
        }
    }
}