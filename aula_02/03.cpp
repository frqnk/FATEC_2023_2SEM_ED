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
<<<<<<< HEAD
        float media_simples;
    };

<<<<<<< HEAD:aula_02/03.cpp
=======
    };

>>>>>>> 4cd1ff0 ()
    int total_alunos = 35;
    cadastro vetor_aluno[total_alunos];

    for(int x = 0; x < total_alunos; x++) {
        vetor_aluno[x].nome = recebe_nome_aluno();
        vetor_aluno[x].disciplina = recebe_disciplina_aluno();
        vetor_aluno[x].nota_1 = recebe_nota_1();
        vetor_aluno[x].nota_2 = recebe_nota_2();
    }

    for(int x = 0; x < total_alunos; x++) {
        cout << "Nome = " << vetor_aluno[x].nome << endl;
        cout << "Disciplina = " << vetor_aluno[x].disciplina << endl;
        cout << "Nota 1 = " << vetor_aluno[x].nota_1 << endl;
        cout << "Nota 2 = " << vetor_aluno[x].nota_2 << endl;
        cout << "Média Simples = " << (vetor_aluno[x].nota_1 + vetor_aluno[x].nota_2) / 2 << endl;
    }

<<<<<<< HEAD
=======
    struct cadastro aluno1;

    aluno1.nome = recebe_nome_aluno();
    aluno1.disciplina = recebe_disciplina_aluno();
    aluno1.nota_1 = recebe_nota_1();
    aluno1.nota_2 = recebe_nota_2();

    cout << "Nome = " << aluno1.nome << endl;
    cout << "Disciplina = " << aluno1.disciplina << endl;
    cout << "Nota 1 = " << aluno1.nota_1 << endl;
    cout << "Nota 2 = " << aluno1.nota_2 << endl;
    aluno1.media_simples = (aluno1.nota_1 + aluno1.nota_2) / 2;
    cout << "Média Simples = " << aluno1.media_simples  << endl;
>>>>>>> 6562a28 (Update 3A):Aula02/03_A.c
=======
>>>>>>> 4cd1ff0 ()
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
