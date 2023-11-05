# Exercício Aula 02

1. Escreva um programa com uma função chamada soma. Este programa deve somar todos os valores entre 0 e n, onde n é o parâmetro passado para a função.

    Exemplo: n = 5, o retorno da função será 15 (5+4+3+2+1).

    **Utilize laço de repetição.**

    ```c++
    #include <iostream>
    int soma(int n) {
        int soma = 0;
        while(n > 0) {
            soma += n;
            n--;
        }
        return soma;
    }
    int main(int n) {
        std::cout << soma(n) << endl;
        return 0;
    }
    ```

2. Escreva um programa com uma função chamada soma. Este programa deve somar todos os valores entre 0 e n, onde n é o parâmetro passado para a função.

    Exemplo: n = 5, o retorno da função será 15 (5+4+3+2+1).

    **Utilize recursividade.**

    ```c++
    #include <iostream>
    int soma(int n) {
        if(n > 0) return n + soma(n-1);
        else return 0;
    }
    int main(int n) {
        std::cout << soma(n) << endl;
        return 0;
    }
    ```