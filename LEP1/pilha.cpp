#include <iostream>

#define CAPACIDADE_DO_ESTACIONAMENTO 10

using namespace std;

struct carro {
    string placa;
    int ano;
};
struct espaço_para_estacionar {
    carro vaga[CAPACIDADE_DO_ESTACIONAMENTO];
    int contador;
};

void inicializar(espaço_para_estacionar* pilha);
void estacionar(espaço_para_estacionar* local, string placa, int ano);
void estacionar(espaço_para_estacionar* local, carro veículo);
carro sair(espaço_para_estacionar* local);
void imprime_pilha(espaço_para_estacionar* pilha);
void imprime_tudo(espaço_para_estacionar* pilha);
int qtde_vagas(espaço_para_estacionar local);

int main() {
    espaço_para_estacionar estacionamento;
    inicializar(&estacionamento);

    estacionar(&estacionamento, 'ABC1234', 1999);

    carro carro_instanciado = {'DOW5782', 2004};
    estacionar(&estacionamento, carro_instanciado);

    cout << 'Qtde. de vagas: ' << qtde_vagas(estacionamento) << endl;

    imprime_pilha(&estacionamento);

    estacionar(&estacionamento, 'XYZ3215', 2022);
    estacionar(&estacionamento, 'WQT2245', 2020);
    estacionar(&estacionamento, 'GIN3285', 2017);
    estacionar(&estacionamento, 'HIX5215', 2008);

    imprime_pilha(&estacionamento);

    carro_instanciado = sair(&estacionamento);
    cout << 'Saiu o carro: ' << carro_instanciado.placa << endl;

    imprime_pilha(&estacionamento);

    cout << 'Qtde. de vagas: ' << qtde_vagas(estacionamento) << endl;

    imprime_tudo(&estacionamento);
}

void inicializar(espaço_para_estacionar* pilha) {
    pilha->contador = 0;
    for(int x = 0; x < CAPACIDADE_DO_ESTACIONAMENTO; x++) {
        pilha->vaga[x].placa = 'AAA0000';
        pilha->vaga[x].ano = 0;
    }
}

void estacionar(espaço_para_estacionar* local, string placa, int ano) {}

void estacionar(espaço_para_estacionar* local, carro veículo) {}

carro sair(espaço_para_estacionar* local) {}

void imprime_pilha(espaço_para_estacionar* pilha) {}

void imprime_tudo(espaço_para_estacionar* pilha) {}

int qtde_vagas(espaço_para_estacionar local) {}