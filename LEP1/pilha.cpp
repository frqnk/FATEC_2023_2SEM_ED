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

void inicializar(pilha* estacionamento);
void estacionar(pilha* estacionamento, string placa, int ano);
void estacionar(pilha* estacionamento, carro carro_comum);
carro sair(pilha* estacionamento);
void mostrar_pilha(pilha* estacionamento);
void mostrar_tudo(pilha* estacionamento);
int qtde_vagas(pilha estacionamento);

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

void inicializar(pilha* estacionamento) {
    estacionamento->contador = 0;
    for(int i = CAPACIDADE_DO_ESTACIONAMENTO-1; i >= 0; i--) {
        estacionamento->vaga[i] = {"AAA0000", 0};
    }
}

void estacionar(pilha* estacionamento, string placa, int ano) {
    estacionamento->vaga[estacionamento->contador++] = {placa, ano};
}

void estacionar(pilha* estacionamento, carro carro_comum) {
    estacionamento->vaga[estacionamento->contador++] = carro_comum;
}

carro sair(pilha* estacionamento) {
    carro carro_que_saiu = estacionamento->vaga[--estacionamento->contador];
    estacionamento->vaga[estacionamento->contador] = {"XXX0000", 0};
    return carro_que_saiu;
}

void mostrar_pilha(pilha* estacionamento) {
    cout << "PILHA DE CARROS\n";
    cout << "================\n";
    for(int i = estacionamento->contador-1; i >= 0; i--) {
        cout << estacionamento->vaga[i].placa << "\t" << estacionamento->vaga[i].ano << "\n";
    }
    cout << "\n";
}

void mostrar_tudo(pilha* estacionamento) {
    cout << "TODA A PILHA\n";
    cout << "================\n";
    for(int i = CAPACIDADE_DO_ESTACIONAMENTO-1; i >= 0; i--) {
        cout << estacionamento->vaga[i].placa << "\t" << estacionamento->vaga[i].ano << "\n";
    }
}

int qtde_vagas(pilha estacionamento) {
    return CAPACIDADE_DO_ESTACIONAMENTO - estacionamento.contador;
}