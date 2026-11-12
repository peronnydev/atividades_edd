//
// Created by segundo on 11/11/2026.
//
#include <iostream>
using namespace std;

string palindromo(string palavra, int inicio, int fim) {
    if (inicio >= fim) {
        return "True";
    }
    if (palavra[inicio] == palavra[fim]) {
        return palindromo(palavra, ++inicio, --fim);
    }
    return "False";
}

int main() {
    cout << palindromo("uva", 0, 2);
}