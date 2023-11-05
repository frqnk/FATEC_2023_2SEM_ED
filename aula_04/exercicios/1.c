/*
Desenvolva uma aplicação para cadastrar carro. Insira na estrutura informações pertinentes ao carro.
*/
#include <stdio.h>

struct cadastro_de_veículo {
    char marca[20], modelo[20], cor[20];
    int ano;
};

void cadastrar(struct cadastro_de_veículo* carro);
void mostrar(struct cadastro_de_veículo carro);

int main() {
    struct cadastro_de_veículo carro;

    cadastrar(&carro);
    mostrar(carro);

    return 0;
}

void cadastrar(struct cadastro_de_veículo* carro) {
    printf("Marca: ");
    scanf("%s", &carro->marca);
    printf("Modelo: ");
    scanf("%s", &carro->modelo);
    printf("Ano: ");
    scanf("%i", &carro->ano);
    printf("Cor: ");
    scanf("%s", &carro->cor);
}

void mostrar(struct cadastro_de_veículo carro) {
    printf("Carro cadastrado: %s %s %i %s\n", carro.marca, carro.modelo, carro.ano, carro.cor);
}