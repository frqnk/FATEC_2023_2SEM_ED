/*
 * Exercício para nota 01.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 23/09/2023
 */

#include <iostream>

#define TAMANHO_PILHA 10

using namespace std;

struct Carro {
    string  placa;
    int     ano;
};

struct Pilha {
    Carro   data[TAMANHO_PILHA];
    int     contador;
};
/* Protótipos das funções. Desenvolver a partir da linha 59 */
void inicializar(Pilha *);
void estacionar(Pilha *, string, int);
void estacionar(Pilha *, Carro);
Carro sair(Pilha *);
void imprime_pilha(Pilha *);
void imprime_tudo(Pilha *);
int quantidade_vagas(Pilha);


int main() {
    Pilha estacionamento;
    inicializar(&estacionamento);
    Carro carro_comum;
/*
    estacionar(&estacionamento,"ABC1234", 1999);
    carro_comum.placa = "DOW5782";
    carro_comum.ano = 2004;
    estacionar(&estacionamento, carro_comum);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_pilha(&estacionamento);
    estacionar(&estacionamento,"XYZ3215", 2022);
    estacionar(&estacionamento,"WQT2245", 2020);
    estacionar(&estacionamento,"GIN3285", 2017);
    estacionar(&estacionamento,"HIX5215", 2008);
    imprime_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << "Saiu o carro: " << carro_comum.placa << endl;
    imprime_pilha(&estacionamento);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_tudo(&estacionamento);
*/
}

/* Desenvolver as funções propostas a partir daqui */
void inicializar(Pilha *estacionamento) {
    estacionamento->contador = 0;
    int x;
	for (x = TAMANHO_PILHA-1; x >= 0 ; x--){
		estacionamento->data[x].placa = "AAA0000" ;
        estacionamento->data[x].ano = 0 ;
    }
}
