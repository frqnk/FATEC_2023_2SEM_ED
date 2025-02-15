/*
Ponteiro - exemplo em C++

Orlando Saraiva Jr
*/
#include <iostream>
#include <string>

using namespace std;

static int contador = 0;

int main(int argc, char* argv[]) {
    int x;

    struct CadastroAluno {
        string nome;
        float nota_1;
        float nota_2;
    };

    CadastroAluno aluno;
    CadastroAluno *vetor_alunos;

    cout << "Digite o número de elementos: ";
    cin >> contador;

    vetor_alunos = new CadastroAluno[contador];

    // Entrada de dados
    for(x = 0; x < contador; x++) {
        cout << "\nDigite o nome do aluno " << x+1 << ": ";
        cin >> vetor_alunos[x].nome;
        cout << "\nDigite a nota 1 do aluno " << x+1 << ": ";
        cin >> vetor_alunos[x].nota_1;
        cout << "\nDigite a nota 2 do aluno " << x+1 << ": ";
        cin >> vetor_alunos[x].nota_2;
    }

    cout << "\n**********************\n";
    // Imprimir resultados
    for(x = 0; x < contador; x++) {
        cout << "O nome do aluno:\t " << vetor_alunos[x].nome << "\n";
        cout << "Média:\t" << (vetor_alunos[x].nota_1 + vetor_alunos[x].nota_2) / 2;
        cout << endl;
    }
    cout << "\n**********************\n";

    delete[] vetor_alunos;

    return 0;
}
