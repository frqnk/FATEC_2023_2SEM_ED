/*
Desenvolva uma aplicação para cadastrar carro. Insira na estrutura informações pertinentes ao carro.
*/
#include <iostream>
#include <string>

using std::string, std::cout, std::cin;

struct cadastro_de_veículo {
    string marca, modelo, cor;
    int ano;
};

void cadastrar(cadastro_de_veículo* carro);
void mostrar(cadastro_de_veículo carro);

int main() {
    int n;
    cout << "Qtde. de carros: ";
    cin >> n;
    cout << "---\n";

    cadastro_de_veículo carro[n];

    for(int i = 0; i < n; i++) {
        cadastrar(&carro[i]);
    }
    cout << "Carro(s) cadastrado(s):\n";
    cout << "---\n";
    for(int i = 0; i < n; i++) {
        mostrar(carro[i]);
    }

    return 0;
}

void cadastrar(cadastro_de_veículo* carro) {
    cout << "Marca: ";
    cin >> carro->marca;
    cout << "Modelo: ";
    cin >> carro->modelo;
    cout << "Ano: ";
    cin >> carro->ano;
    cout << "Cor: ";
    cin >> carro->cor;
    cout << "---\n";
}

void mostrar(cadastro_de_veículo carro) {
    cout << carro.marca << " " << carro.modelo << " " << carro.ano << " " << carro.cor << "\n";
    cout << "---\n";
}