//
// Created by segundo on 04/11/2026.
//
#include <iostream>
using namespace std;

struct No {
    string valor;
    int prioridade;
    No* sucessor;
    No* anterior;
};

void adicionar(No* &top, string valor, int prioridade){
    No* novo = new No{};
    novo -> valor = valor;
    novo -> prioridade = prioridade;
    novo -> sucessor = nullptr;
    novo -> anterior = nullptr;
    if (top == nullptr) {
        top = novo;
        return;
    }
    No* aux = top;
    while (aux -> sucessor != nullptr) {
        aux = aux -> sucessor;
    }
    aux -> sucessor = novo;
    novo -> anterior = aux;
}

void adicionarNoComeco(No* top, string valor, int prioridade) {
    No* novo = new No;
    novo -> sucessor = top;
    novo -> anterior = nullptr;
    novo -> valor = valor;
    novo -> prioridade = prioridade;

    top = novo;
}

void remover(No* &top) {
    if (top == nullptr) return;
    No* maior = top;
    for (No* aux = top; aux != nullptr; aux = aux -> sucessor) {
        if (aux -> prioridade > maior -> prioridade) {
            maior = aux;
        }
    }
    if (maior -> sucessor == nullptr) {

    }
    No* anterior = maior -> anterior;
    No* sucessor = maior -> sucessor;
    if (anterior == nullptr) {
        top = top -> sucessor;
        return;
    }
    if (sucessor == nullptr) {
        anterior -> sucessor = nullptr;
        return;
    }
    anterior -> sucessor = sucessor;
    sucessor -> anterior = anterior;
}
void print(No* &top) {
    for (No* aux = top; aux != nullptr; aux = aux -> sucessor) {
        cout << aux -> valor << " | ";
    }
    cout << endl;
}

int size(No* &top) {
    int tamanho = 0;
    if (top == nullptr) return tamanho;
    for (No* aux = top; aux != nullptr; aux = aux -> sucessor) {
        tamanho++;
    }
    return tamanho;
}

bool palindromo(No* lista1, No* lista2) {
    if (size(lista1) != size(lista2)) {
        cout << "palindromo = false" << endl;
        return false;
    }
    No* aux1 = lista1;
    No* aux2 = lista2;
    while (aux1 != nullptr && aux2 != nullptr) {
        if (aux1 -> valor != aux2 -> valor) {
            cout << "palindromo = false" << endl;
            return false;
        }
        aux1 = aux1 -> sucessor;
        aux2 = aux2 -> sucessor;
    }
    cout << "palindromo = true" << endl;
    return true;
}

int main() {
    No* lista1 = nullptr;
    adicionar(lista1, "c", 1);
    adicionar(lista1, "a", 1);
    adicionar(lista1, "r", 1);
    adicionar(lista1, "r", 1);
    adicionar(lista1, "o", 1);

    No* lista2 = nullptr;
    adicionarNoComeco(lista2, "a", 1);
    adicionarNoComeco(lista2, "r", 1);
    adicionarNoComeco(lista2, "a", 1);
    adicionarNoComeco(lista2, "a", 1);

    print(lista1);
    print(lista2);
    palindromo(lista1, lista2);

}