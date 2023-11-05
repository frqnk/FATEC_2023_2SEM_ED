/*
Desenvolva uma aplicação para cadastrar cliente que fará um crédito em até 12 vezes. Insira na estrutura informações pertinentes ao cliente.
*/
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

struct cadastro_em_loja {
    string nome, cpf;
    int crédito, n_vezes;
};

void cadastrar(cadastro_em_loja* cliente);
void mostrar(cadastro_em_loja cliente);

int main() {
    cadastro_em_loja cliente;

    cadastrar(&cliente);
    mostrar(cliente);

    return 0;
}

void cadastrar(cadastro_em_loja* cliente) {
    cout << "Nome: ";
    cin >> cliente->nome;
    cout << "CPF: ";
    cin >> cliente->cpf;
    cout << "Crédito: ";
    cin >> cliente->crédito;
    cout << "Nº de vezes: ";
    cin >> cliente->n_vezes;
}

void mostrar(cadastro_em_loja cliente) {
    cout << "Cliente cadastrado:\n";
    cout << "Nome: " << cliente.nome << "\n";
    cout << "CPF: " << cliente.cpf << "\n";
    cout << "Crédito: " << cliente.crédito << "\n";
    cout << "Nº de vezes: " << cliente.n_vezes << endl;
}