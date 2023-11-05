#include <iostream>
#define CAPACIDADE_DO_ESTACIONAMENTO 10
using namespace std;

struct carro {
    string placa;
    int ano;
};
struct pilha {
    carro vaga[CAPACIDADE_DO_ESTACIONAMENTO];
    int contador;
};

void inicializar(pilha*);
void estacionar(pilha*, string, int);
void estacionar(pilha*, carro);
carro sair(pilha*);
void mostrar_pilha(pilha*);
void mostrar_tudo(pilha*);
int qtde_vagas(pilha);

int main() {
    pilha estacionamento;
    inicializar(&estacionamento);

    estacionar(&estacionamento, "ABC1234", 1999);
    carro carro_comum = {"DOW5782", 2004};
    estacionar(&estacionamento, carro_comum);
    cout << "Quantidade de vagas " << qtde_vagas(estacionamento) << "\n";
    mostrar_pilha(&estacionamento);

    estacionar(&estacionamento, "XYZ3215", 2022);
    estacionar(&estacionamento, "WQT2245", 2020);
    estacionar(&estacionamento, "GIN3285", 2017);
    estacionar(&estacionamento, "HIX5215", 2008);
    mostrar_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << "Saiu o carro: " << carro_comum.placa << "\n";
    mostrar_pilha(&estacionamento);

    cout << "Quantidade de vagas " << qtde_vagas(estacionamento) << "\n";
    mostrar_tudo(&estacionamento);
}

void inicializar(pilha* e) {
    e->contador = 0;
    for(int i = CAPACIDADE_DO_ESTACIONAMENTO-1; i >= 0; i--) {
        e->vaga[i] = {"AAA0000", 0};
    }
}

void estacionar(pilha* e, string placa, int ano) {
    e->vaga[e->contador++] = {placa, ano};
}

void estacionar(pilha* e, carro carro_que_chegou) {
    e->vaga[e->contador++] = carro_que_chegou;
}

carro sair(pilha* e) {
    carro carro_que_saiu = e->vaga[--e->contador];
    e->vaga[e->contador] = {"XXX0000", 0};
    return carro_que_saiu;
}

void mostrar_pilha(pilha* e) {
    cout << "PILHA DE CARROS\n";
    cout << "================\n";
    for(int i = e->contador-1; i >= 0; i--) {
        cout << e->vaga[i].placa << "\t" << e->vaga[i].ano << "\n";
    }
    cout << "\n";
}

void mostrar_tudo(pilha* e) {
    cout << "TODA A PILHA\n";
    cout << "================\n";
    for(int i = CAPACIDADE_DO_ESTACIONAMENTO-1; i >= 0; i--) {
        cout << e->vaga[i].placa << "\t" << e->vaga[i].ano << "\n";
    }
}

int qtde_vagas(pilha e) {
    return CAPACIDADE_DO_ESTACIONAMENTO - e.contador;
}