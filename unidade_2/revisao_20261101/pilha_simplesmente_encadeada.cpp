//
// Created by segundo on 02/11/2026.
//
#include <iostream>
using namespace std;

struct No{
    int valor;
    No* sucessor;
};

void push(No* &top, int valor) {
    No* fakeTop = new No;
    if (top == nullptr) {
        top = new No;
        top -> valor = valor;
        top -> sucessor = nullptr;
        return;
    }
    fakeTop -> valor = top -> valor;
    fakeTop -> sucessor = top -> sucessor;
    top -> valor = valor;
    top -> sucessor = fakeTop;
}

void pop(No* &top) {
    if (top == nullptr) return;
    No* aux = top -> sucessor;
    top -> valor = aux -> valor;
    top -> sucessor = aux -> sucessor;
    aux = nullptr;
    delete aux;
}

void print(No*& top) {
    No* aux = top;
    while (aux != nullptr) {
        cout << aux -> valor << endl;
        aux = aux -> sucessor;
    }
}

int main() {
    No* top = nullptr;

    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);
    push(top, 5);

    pop(top);
    pop(top);

    print(top);
}