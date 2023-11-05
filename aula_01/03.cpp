#include <iostream>

using namespace std;

int fatorial(int n) {
    if(n <= 1) {
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }
}

int main() {
    int n;
    cout << "Informe o número que deseja obter o fatorial: ";
    cin >> n;
    cout << "O fatorial de " << n << " é " << fatorial(n) << endl;
    return 0;
}
