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
        top = novoNo;
        top -> sucessor = novoNo;
        return;
    }
    No* aux = top;

    while (aux -> sucessor != top) {
        aux = aux -> sucessor;
    }
    novoNo -> sucessor = top;
    aux -> sucessor = novoNo;
}

void pop(No*& top) {
    if (top -> sucessor == top) {
        top = nullptr;
        return;
    }
    No* aux = top;
    do {
        aux = aux -> sucessor;
    }while (aux -> sucessor != top);
    aux -> sucessor = top -> sucessor;
    top = top -> sucessor;
}

void print(No* top) {
    No* aux = top;
    do {
        cout << aux -> valor << endl;
        aux = aux -> sucessor;
    }while (aux != top);
}

int main() {
    No* top = nullptr;

    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);

    pop(top);pop(top);


    print(top);
}
