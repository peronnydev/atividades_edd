//
// Created by segundo on 29/10/2026.
//
#include <iostream>
using namespace std;

struct No{
    int valor;
    No* sucessor;
};

void push(No*&top, int valor) {
    No* novo = new No{valor, nullptr};
    if (top == nullptr) {
        top = novo;
        return;
    }
    No* aux = top;
    while (aux -> sucessor != nullptr) { aux = aux -> sucessor; }
    aux -> sucessor = novo;
}

void pop(No* top) {
    if (top == nullptr) return;
    No* penultimo = top;
    while (penultimo -> sucessor != nullptr) {
        penultimo = penultimo -> sucessor;
    }
    delete penultimo -> sucessor -> sucessor;
    penultimo -> sucessor = nullptr;
}

void print(No* top) {
    for (No* aux = top; aux != nullptr; aux = aux -> sucessor) {
        cout << aux -> valor << endl;
    }
}

int main() {
    No* top = nullptr;

    push(top, 1);
    pop(top);

    push(top, 2);
    push(top, 3);
    pop(top);

    push(top, 4);
    push(top, 5);
    pop(top);

    print(top);
}