//
// Created by segundo on 29/10/2026.
//
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* sucessor;
};

void push(No*& top, int valor) {
    top = new No{valor, top};
}

void pop(No*& top) {
    if (top == nullptr) return;
    No* remover = top;
    top = top -> sucessor;
    delete remover;
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