/*
Desenvolva uma aplicação para cadastrar cliente que fará um crédito em até 12 vezes. Insira na estrutura informações pertinentes ao cliente.
*/
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main() {
    struct cadastro_de_cliente {
        string nome, cpf;
        int crédito, n_vezes;
    } cliente;

    cout << "Nome: ";
    cin >> cliente.nome;
    cout << "CPF: ";
    cin >> cliente.cpf;
    cout << "Crédito: ";
    cin >> cliente.crédito;
    cout << "Nº de vezes: ";
    cin >> cliente.n_vezes;

    cout << "Cliente cadastrado:\n";
    cout << "Nome: " << cliente.nome << "\n";
    cout << "CPF: " << cliente.cpf << "\n";
    cout << "Crédito: " << cliente.crédito << "\n";
    cout << "Nº de vezes: " << cliente.n_vezes << endl;

    return 0;
}