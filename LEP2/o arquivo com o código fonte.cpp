#include <iostream>
#include <ctime>
using namespace std;

struct registro_de_acesso {
    string url;
    int dia, mês, ano;
};
struct nó {
    registro_de_acesso site_visitado;
    nó* próximo_nó;
};
struct pilha {
    nó* topo;
    int tamanho;
};

void inicializar(pilha*);
void navegar(pilha*, string);
void navegar(pilha*, string, int, int, int);
registro_de_acesso voltar(pilha*);
void mostrar_histórico(pilha*);
void mostrar_url(registro_de_acesso);
void destruir_histórico(pilha*);

int main() {
    registro_de_acesso site;
    pilha histórico_de_navegação;
    inicializar(&histórico_de_navegação);

    navegar(&histórico_de_navegação, "http://www.google.com");
    navegar(&histórico_de_navegação, "http://www.facebook.com");
    navegar(&histórico_de_navegação, "http://www.globo.com", 15, 1, 2023);
    navegar(&histórico_de_navegação, "http://www.fatecararas.sp.gov.br");
    navegar(&histórico_de_navegação, "http://www.google.com");
    navegar(&histórico_de_navegação, "http://www.facebook.com");
    navegar(&histórico_de_navegação, "http://www.fatecararas.sp.gov.br");
    navegar(&histórico_de_navegação, "http://www.gmail.com");
    mostrar_histórico(&histórico_de_navegação);
    site = voltar(&histórico_de_navegação);
    mostrar_url(site);
    site = voltar(&histórico_de_navegação);
    mostrar_url(site);
    mostrar_url(voltar(&histórico_de_navegação));
    cout << "\n\n";

    mostrar_histórico(&histórico_de_navegação);
    destruir_histórico(&histórico_de_navegação);

    return 0;
}

void inicializar(pilha* h) {
    h->tamanho = 0;
    h->topo = NULL;
}

void navegar(pilha* h, string u) {
    nó* novo_nó = new nó;
    if(novo_nó == NULL) {
        cerr << "Acabou a memória.\n";
        exit(1);
    }

    novo_nó->site_visitado.url = u;

    time_t momento_salvo = time(NULL);
    tm* data_atual = localtime(&momento_salvo);
    novo_nó->site_visitado.dia = data_atual->tm_mday;
    novo_nó->site_visitado.mês = data_atual->tm_mon + 1;
    novo_nó->site_visitado.ano = data_atual->tm_year + 1900;

    novo_nó->próximo_nó = h->topo;
    h->topo = novo_nó;
    h->tamanho++;
}

void navegar(pilha* h, string u, int d, int m, int a) {
    navegar(h, u);
}

registro_de_acesso voltar(pilha* h) {
    nó* nó_anterior = h->topo;
    h->topo = h->topo->próximo_nó;

    registro_de_acesso site_anterior = nó_anterior->site_visitado;

    delete(nó_anterior);
    h->tamanho--;

    return site_anterior;
}

void mostrar_histórico(pilha* h) {
    cout << "Quantidade de URLs: " << h->tamanho << " no histórico.\n";
    cout << "==================================\n";
    nó* nó_mostrado = h->topo;
    while(nó_mostrado != NULL) {
        cout << nó_mostrado->site_visitado.url << "\n";
        nó_mostrado = nó_mostrado->próximo_nó;
    }
    cout << "-----------------------------------\n";
}

void mostrar_url(registro_de_acesso s) {
    cout << "\t" << s.dia << "/" << s.mês << "/" << s.ano << "\t" << s.url << "\n";
}

void destruir_histórico(pilha* h) {
    while(h->topo != NULL) {
        cout << "Desempilhando a URL: " << h->topo->site_visitado.url << "\n";
        voltar(h);
    }
}