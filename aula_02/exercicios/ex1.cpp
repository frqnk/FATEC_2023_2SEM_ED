#include <iostream>
#include <string>

int main() {
    struct cadastro {
        std::string descricao;
    };
    cadastro carro;
    carro.descricao = "nao tenho";
    return 0;
}