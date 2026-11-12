//
// Created by segundo on 02/11/2026.
//
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* sucessor;
};

void push(No* &top, int valor) {
    if (top == nullptr) {
        top = new No;
        top -> valor = valor;
        top -> sucessor = top;
        return;
    }
    No* fakeTop = new No{top -> valor, top -> sucessor};
    top -> valor = valor;
    top -> sucessor = fakeTop;
}

void pop(No* &top) {
    if (top == nullptr) return;
    if (top -> sucessor == top) {
        delete top;
        top = nullptr;
        return;
    }
    No* aux = top -> sucessor;
    top -> valor = aux -> valor;
    top -> sucessor = aux -> sucessor;
    delete aux;
}

void printar_cem_primeiros(No* &top) {
    cout << "Printando os 100 primeiros numeros" << endl;
    No* aux = top;
    for (int i = 0; i < 100 && aux != nullptr; i++) {
        cout << aux -> valor << " | ";
        aux = aux -> sucessor;
    }
    cout << endl;
}

int main() {
    No* top = nullptr;

    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);
    push(top, 5);
    push(top, 6);
    push(top, 7);
    push(top, 8);

    pop(top);
    pop(top);

    printar_cem_primeiros(top);
}