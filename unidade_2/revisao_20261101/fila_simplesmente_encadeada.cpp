//
// Created by segundo on 02/11/2026.
//
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* sucessor;
};

void push(No*& top, int valor) {
    No* novoNo = new No{valor, nullptr};
    if (top == nullptr) {
        top = new No{valor, nullptr};
        return;
    }
    No* aux = top;
    while (aux -> sucessor != nullptr) {
        aux = aux -> sucessor;
    }
    aux -> sucessor = novoNo;
}

void pop(No*& top) {
    if (top == nullptr) return;
    if (top -> sucessor == nullptr) {
        top = nullptr;
        delete top;
        return;
    }
    No* aux = top -> sucessor;
    while (aux -> sucessor != nullptr) {
        aux = aux -> sucessor;
    }
    No* ultimoNo = aux -> sucessor;
    aux -> sucessor = nullptr;
    ultimoNo = nullptr;
    delete ultimoNo;
}

void print(No* top) {
    for (No* aux = top; aux != nullptr; aux = aux -> sucessor) {
        cout << aux -> valor << endl;
    }
}

int main() {
    No* top = nullptr;

    push(top, 1);
    push(top, 2);
    push(top, 3);

    pop(top);

    print(top);
}
