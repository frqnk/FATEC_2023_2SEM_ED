/*
Desenvolva uma aplicação para cadastrar carro. Insira na estrutura informações pertinentes ao carro.
*/
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main() {
    struct cadastro_de_veículo {
        string marca, modelo, cor;
        int ano;
    } carro;

    cout << "Marca: ";
    cin >> carro.marca;
    cout << "Modelo: ";
    cin >> carro.modelo;
    cout << "Ano: ";
    cin >> carro.ano;
    cout << "Cor: ";
    cin >> carro.cor;

    cout << "Carro cadastrado: " << carro.marca << " " << carro.modelo << " " << carro.ano << " " << carro.cor << endl;

    return 0;
}