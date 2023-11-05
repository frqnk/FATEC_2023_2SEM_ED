/*
Desenvolva uma aplicação para cadastrar carro. Insira na estrutura informações pertinentes ao carro.
*/
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

struct cadastro_de_veículo {
    string marca, modelo, cor;
    int ano;
};

void cadastrar(cadastro_de_veículo* carro);
void mostrar(cadastro_de_veículo carro);

int main() {
    cadastro_de_veículo carro;

    cadastrar(&carro);
    mostrar(carro);

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
}

void mostrar(cadastro_de_veículo carro) {
    cout << "Carro cadastrado: " << carro.marca << " " << carro.modelo << " " << carro.ano << " " << carro.cor << endl;
}