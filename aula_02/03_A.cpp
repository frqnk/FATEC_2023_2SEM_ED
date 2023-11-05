/*
Terceiro programa em C++
Cadastro de aluno

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>

using namespace std;

string recebe_nome_aluno();
string recebe_disciplina_aluno();
float recebe_nota_1();
float recebe_nota_2();

int main(int argc, char *argv[]) {
    struct cadastro {
        string nome;
        string disciplina;
        float nota_1;
        float nota_2;
        float media_simples;
    };

    cadastro aluno1;
    aluno1.nome = recebe_nome_aluno();
    aluno1.disciplina = recebe_disciplina_aluno();
    aluno1.nota_1 = recebe_nota_1();
    aluno1.nota_2 = recebe_nota_2();
    aluno1.media_simples = (aluno1.nota_1 + aluno1.nota_2) / 2;

    cadastro aluno2;
    aluno2.nome = "Jose";
    aluno2.disciplina = "ED";
    aluno2.nota_1 = 7;
    aluno2.nota_2 = 9;
    aluno2.media_simples = (aluno2.nota_1 + aluno2.nota_2) / 2;

    cout << "Nome = " << aluno1.nome << endl;
    cout << "Disciplina = " << aluno1.disciplina << endl;
    cout << "Nota 1 = " << aluno1.nota_1 << endl;
    cout << "Nota 2 = " << aluno1.nota_2 << endl;
    cout << "Média Simples = " << aluno1.media_simples << endl;
    cout << "=========================" << endl;
    cout << "Nome = " << aluno2.nome << endl;
    cout << "Média simples = " << aluno2.media_simples << endl;

    return 0;
}

string recebe_nome_aluno() {
    string nome_recebido;
    cout << "Digite o nome do aluno: ";
    cin >> nome_recebido;
    return nome_recebido;
}

string recebe_disciplina_aluno() {
    string disciplina;
    cout << "Digite a disciplina cursada: ";
    cin >> disciplina;
    return disciplina;
}

float recebe_nota_1() {
    string nota;
    float nota_1;
    cout << "Digite a nota do aluno: ";
    cin >> nota_1;
    return nota_1;
}

float recebe_nota_2() {
    string nota;
    float nota_2;
    cout << "Digite a nota do aluno: ";
    cin >> nota_2;
    return nota_2;
}
