/*
 * Exercício para nota 03
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 21/10/2023
 */

#include <iostream>

using namespace std;

typedef struct Cliente {
    int senha;
    int idade;
    string nome;
    int quantidade_itens;
    float valor;
} CLIENTE;

struct Node {
    CLIENTE cliente;
    Node *next;
};

struct Fila {
    Node *inicio;
    Node *final;
    int tamanho;
    int proxima_senha;
};

void inicializar(Fila *);
void entrada_cliente(Fila *, string,int,int,float);
CLIENTE saida_cliente(Fila *);
void mostraFila(Fila *);
void dados_primeiro_fila(Fila *);
void dados_ultimo_fila(Fila *);
void encerrar(Fila *);

void buscar_clientes_senha(Fila *, int);
void buscar_clientes_menores_idade(Fila *);
void buscar_clientes_melhor_idade(Fila *);
void buscar_clientes_valores_quantidades(Fila *, int);
void buscar_clientes_valores_compras(Fila *, float);

int main() {
    Fila fila_caixa;
    CLIENTE atendido;
    inicializar(&fila_caixa);
    entrada_cliente(&fila_caixa, "Cliente Teste 1", 20, 1, 15.5);
    entrada_cliente(&fila_caixa, "Cliente Teste 2", 40, 2, 27.25);
    entrada_cliente(&fila_caixa, "Cliente Teste 3", 18, 6, 141.39);
    entrada_cliente(&fila_caixa, "Cliente Teste 4", 65, 8, 151.39);

    mostraFila(&fila_caixa);
    dados_primeiro_fila(&fila_caixa);
    dados_ultimo_fila(&fila_caixa);

    atendido = saida_cliente(&fila_caixa);
    atendido = saida_cliente(&fila_caixa);
    atendido = saida_cliente(&fila_caixa);

    dados_primeiro_fila(&fila_caixa);
    dados_ultimo_fila(&fila_caixa);
    mostraFila(&fila_caixa);
    atendido = saida_cliente(&fila_caixa);
    dados_primeiro_fila(&fila_caixa);
    dados_ultimo_fila(&fila_caixa);
    mostraFila(&fila_caixa);
    atendido = saida_cliente(&fila_caixa);

    /* Descomentar este trecho
    entrada_cliente(&fila_caixa, "Jose da Silva", 16, 1, 95.98);
    entrada_cliente(&fila_caixa, "Gabriel Nunes", 40, 2, 50.38);
    entrada_cliente(&fila_caixa, "Enrico Barros", 17, 6, 78.30);
    entrada_cliente(&fila_caixa, "Luiz Felipe Peixoto", 28, 12, 184.95);
    entrada_cliente(&fila_caixa, "Gustavo Henrique Novaes", 68, 3, 141.39);
    entrada_cliente(&fila_caixa, "Ana Luiza Rezende", 65, 5, 180.86);
    entrada_cliente(&fila_caixa, "Maria Julia da Paz", 12, 10, 23.22);
    entrada_cliente(&fila_caixa, "João Felipe Caldeira", 35, 2, 141.39);
    entrada_cliente(&fila_caixa, "Ana Campos", 27, 12, 22.38);
    entrada_cliente(&fila_caixa, "Luiz Felipe da Mota", 33, 1, 55.78);
    entrada_cliente(&fila_caixa, "Danilo Campos", 75, 2, 82.17);
    entrada_cliente(&fila_caixa, "Ana Júlia da Cunha", 72, 15, 186.69);
    entrada_cliente(&fila_caixa, "Brenda Moura", 17, 5, 64.89);
    mostraFila(&fila_caixa);

    // Busca por idades
    cout << "\t Busca por Idades " << endl;
    cout << "\t ================" << endl;
    buscar_clientes_menores_idade(&fila_caixa);
    buscar_clientes_melhor_idade(&fila_caixa);

    //  Busca por valores mínimos gasto
    cout << "\t Busca por Gastos Mínimos " << endl;
    cout << "\t ========================" << endl;
    buscar_clientes_valores_compras(&fila_caixa, 90);
    buscar_clientes_valores_compras(&fila_caixa, 150);

    //  Busca por quantidades
    cout << "\t Busca por quantidades " << endl;
    cout << "\t =====================" << endl;
    buscar_clientes_valores_quantidades(&fila_caixa, 5);
    buscar_clientes_valores_quantidades(&fila_caixa, 10);

    //  Busca por senha
    cout << "\t Busca por senha " << endl;
    cout << "\t ===============" << endl;
    buscar_clientes_senha(&fila_caixa, 3);
    buscar_clientes_senha(&fila_caixa, 10);
*/
    encerrar(&fila_caixa);
    mostraFila(&fila_caixa);

    return 0;
}

void inicializar(Fila *fila) {
    fila->tamanho = 0;
    fila->proxima_senha = 1;
    fila->inicio = NULL;
    fila->final = NULL;
}

CLIENTE saida_cliente(Fila *fila) {
    CLIENTE retorno;
    Node* aux;
    if (fila->final != NULL) {
        if ( fila->inicio != fila->final) {
            aux = fila->inicio;
            fila->inicio = fila->inicio->next;
            retorno = aux->cliente;
            aux->next = NULL;
            delete aux;
            fila->tamanho = fila->tamanho - 1;
        } else {
            retorno = fila->final->cliente;
            aux = fila->final;
            delete aux;
            fila->inicio = NULL;
            fila->final = NULL;
            fila->tamanho = fila->tamanho - 1;
        }
    } else {
        retorno.senha = -1;
        retorno.nome = "";
        retorno.idade = -1;
        retorno.valor = -1;
    }
    return retorno;
}

void entrada_cliente(Fila *fila, string nome, int idade, int quantidade_itens, float valor){
    Node *new_node = new Node;
    if (new_node == NULL) {
        cerr << "Acabou a memória. " << endl;
        exit(1);
    }
    new_node->cliente.senha = fila->proxima_senha;
    new_node->cliente.nome = nome;
    new_node->cliente.idade = idade;
    new_node->cliente.quantidade_itens = quantidade_itens;
    new_node->cliente.valor = valor;
    new_node->next = NULL;
    fila->proxima_senha = fila->proxima_senha + 1;
    if (fila->inicio == NULL) {
        fila->inicio = new_node;
        fila->final = new_node;
    } else {
        Node* aux = fila->inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_node;
        fila->final = new_node;
    }
    fila->tamanho = fila->tamanho + 1;
}

void mostraFila(Fila *fila){
    if (fila->inicio != NULL) {
        cout << "Tamanho da fila: " << fila->tamanho << endl;
        Node* cliente_local = fila->inicio;
        while(cliente_local->next != NULL){
            cout <<"[" << cliente_local->cliente.senha << "-";
            cout << cliente_local->cliente.nome << "] -> ";
            cliente_local = cliente_local->next;
        }
        cout <<"[" << cliente_local->cliente.senha << "-";
        cout << cliente_local->cliente.nome << "]";
        cout << endl << endl;
    } else {
        cout << "Tamanho da fila: " << fila->tamanho << endl;
        cout << "[]" << endl;
    }
}

void dados_primeiro_fila(Fila *fila){
    if (fila->inicio != NULL) {
        cout << "Próximo será: \t \t" << fila->inicio->cliente.senha << "  -  ";
        cout << fila->inicio->cliente.nome << "  -  ";
        cout << fila->inicio->cliente.idade << " anos  -  ";
        cout << fila->inicio->cliente.quantidade_itens << "  -  ";
        cout << "R$ " << fila->inicio->cliente.valor;
        cout << endl << endl;
    }
}

void dados_ultimo_fila(Fila *fila){
    if (fila->inicio != NULL) {
        cout << "Último da fila:  \t" << fila->final->cliente.senha << "  -  ";
        cout << fila->final->cliente.nome << "  -  ";
        cout << fila->final->cliente.idade << " anos  -  ";
        cout << fila->inicio->cliente.quantidade_itens << "  -  ";
        cout << "R$ " << fila->final->cliente.valor;
        cout << endl << endl;
    }
}

void encerrar(Fila *fila){
    if (fila->inicio != NULL) {
        while(fila->inicio->next != NULL){
            saida_cliente(fila);
        }
        saida_cliente(fila);
    }
}

/* Desenvolver suas funções a partir deste ponto. */