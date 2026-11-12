#include <iostream>
using namespace std;

int somaDosNumero(int numeroBase) {
    int contador = 0;
    for (int i = 0; i < numeroBase; i++) {
        contador += i;
    }
    return contador;
}

int recursivaSomaDosNumeros(int numeroParada) {
    --numeroParada;
    if (numeroParada == 0) {
        return 0;
    }
    return numeroParada + recursivaSomaDosNumeros(numeroParada);
}

int main() {
    cout << recursivaSomaDosNumeros(2048) << endl;
    cout << somaDosNumero(2048) << endl;
}