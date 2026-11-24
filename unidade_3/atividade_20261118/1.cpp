//
// Created by segundo on 18/11/2026.
//
#include <iostream>
using namespace std;

struct No {
    No* direita = nullptr;
    No* esquerda = nullptr;
    int valor;
};

No* busca(No* &raiz, int valor) {
    if (raiz == nullptr) {
        cout << "m=busca Valor nao encontrado" << endl;
        return nullptr;
    }
    if (raiz -> valor == valor) {
        cout << "m=busca Valor encontrado" << endl;
        return raiz;
    }
    if (raiz -> valor < valor) {
        return busca(raiz -> direita, valor);
    }
    return busca(raiz -> direita, valor);
}

No* inserir(No* &raiz, int valor) {
    if (busca(raiz, valor) != nullptr) {
        cout << "m=inserir Esse valor ja existe dentro da arvore" << endl;
        return nullptr;
    }
    if (raiz == nullptr) {
        raiz = new No;
        raiz -> valor = valor;
        return raiz;
    }
    if (raiz -> valor < valor) {
        return inserir(raiz -> direita, valor);
    }
    return inserir(raiz -> esquerda, valor);
}

No* remover(No* &raiz, No* &noParaRemover) {
    if (busca(raiz, noParaRemover -> valor) == nullptr) {
        cout << "m=remover O elemento a remover nao existe" << endl;
        return nullptr;
    }
    if (noParaRemover -> esquerda == nullptr && noParaRemover -> direita == nullptr) {
        noParaRemover = nullptr;
    }
    return nullptr;
}

int main() {
    No* raiz = nullptr;
    inserir(raiz, 10);
    inserir(raiz, 20);
    inserir(raiz, 30);
    inserir(raiz, 40);
    inserir(raiz, 50);
    inserir(raiz, 60);
    inserir(raiz, 70);

    inserir(raiz, 7);
    inserir(raiz, 6);
    inserir(raiz, 5);
    inserir(raiz, 4);
    inserir(raiz, 3);
    inserir(raiz, 2);
    inserir(raiz, 1);

    cout << "Printando todos a direita" << endl;
    for (No* maior = raiz; maior != nullptr; maior = maior -> direita) {
        cout << maior -> valor << endl;
    }

    cout << "Printando todos a esquerda" << endl;
    for (No* maior = raiz; maior != nullptr; maior = maior -> esquerda) {
        cout << maior -> valor << endl;
    }
}