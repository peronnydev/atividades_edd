//
// Created by segundo on 16/11/2026.
//
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* direita;
    No* esquerda;
};

No* busca(No* &raiz, int alvo) {
    if (raiz == nullptr) {
        cout << "Valor nao encontrado" << endl;
        return nullptr;
    } else if (raiz -> valor == alvo) {
        cout << "Valor encontrado" << endl;
        return raiz;
    } else if (alvo > raiz -> valor) {
        return busca(raiz -> direita, alvo);
    }
    return busca(raiz -> esquerda, alvo);
}

int main() {
    No* raiz = new No{10, nullptr, nullptr};
    No* esquerda = new No{0, nullptr, nullptr};
    No* direita = new No{20, nullptr, nullptr};

    raiz -> direita = direita;
    raiz -> esquerda = esquerda;

    busca(raiz, 20);
}