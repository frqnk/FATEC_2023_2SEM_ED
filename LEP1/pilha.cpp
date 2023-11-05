#include <iostream>

#define TAMANHO_DA_PILHA 10

using namespace std;

struct carro {
    string placa;
    int ano;
};
struct pilha {
    carro data[TAMANHO_DA_PILHA];
    int contador;
};

void inicializar(pilha* pilha);
void estacionar(pilha* local, string placa, int ano);
void estacionar(pilha* local, carro veículo);
carro sair(pilha* local);
void imprime_pilha(pilha* pilha);
void imprime_tudo(pilha* pilha);
int qtde_vagas(pilha local);

int main() {
    pilha estacionamento;
    inicializar(&estacionamento);

    estacionar(&estacionamento, 'ABC1234', 1999);

    carro carro_comum = {'DOW5782', 2004};
    estacionar(&estacionamento, carro_comum);

    cout << 'Qtde. de vagas: ' << qtde_vagas(estacionamento) << endl;

    imprime_pilha(&estacionamento);

    estacionar(&estacionamento, 'XYZ3215', 2022);
    estacionar(&estacionamento, 'WQT2245', 2020);
    estacionar(&estacionamento, 'GIN3285', 2017);
    estacionar(&estacionamento, 'HIX5215', 2008);

    imprime_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << 'Saiu o carro: ' << carro_comum.placa << endl;

    imprime_pilha(&estacionamento);

    cout << 'qtde de vagas ' << qtde_vagas(estacionamento) << endl;

    imprime_tudo(&estacionamento);
}

void inicializar(pilha* estacionamento) {
    estacionamento->contador = 0;
    int x;
    for(x = TAMANHO_DA_PILHA-1; x >= 0 ; x--) {
        estacionamento->data[x].placa = 'AAA0000';
        estacionamento->data[x].ano = 0;
    }
}
