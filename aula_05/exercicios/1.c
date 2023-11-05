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
    int n;
    printf("Qtde. de carros: ");
    scanf("%i", &n);
    printf("---\n");

    struct cadastro_de_veículo carro[n];

    for(int i = 0; i < n; i++) {
        cadastrar(&carro[i]);
    }
    printf("Carro(s) cadastrado(s):\n");
    printf("---\n");
    for(int i = 0; i < n; i++) {
        mostrar(carro[i]);
    }

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
    printf("---\n");
}

void mostrar(struct cadastro_de_veículo carro) {
    printf("%s %s %i %s\n", carro.marca, carro.modelo, carro.ano, carro.cor);
    printf("---\n");
}