#include <iostream>

using namespace std;

int soma_com_laco_de_repeticao(int n) {
    int soma = 0;
    for(int i = n; i > 0; i--) {
        soma += i;
    }
    return soma;
}

int soma_com_recursividade(int n) {
    if(n > 0) {
        return n + soma_com_recursividade(n-1);
    }
    else return 0;
}

int main() {
    int n;
    cin >> n;

    cout << soma_com_laco_de_repeticao(n) << endl;
    cout << soma_com_recursividade(n) << endl;

    return 0;
}