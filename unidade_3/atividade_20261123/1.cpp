//
// Created by segundo on 23/11/2026.
//
#include <iostream>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota;
};

struct No {
    Aluno aluno;
    No* esq;
    No* dir;
};

No* criarNo(Aluno a) {
    No* novo = new No;
    novo->aluno = a;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, Aluno a) {
    if (raiz == NULL)
        return criarNo(a);

    if (a.matricula < raiz->aluno.matricula)
        raiz->esq = inserir(raiz->esq, a);
    else if (a.matricula > raiz->aluno.matricula)
        raiz->dir = inserir(raiz->dir, a);
    else
        cout << "Matricula " << a.matricula << " ja existe!" << endl;

    return raiz;
}

No* buscar(No* raiz, int matricula) {
    if (raiz == NULL || raiz->aluno.matricula == matricula)
        return raiz;

    if (matricula < raiz->aluno.matricula)
        return buscar(raiz->esq, matricula);
    else
        return buscar(raiz->dir, matricula);
}

No* menorNo(No* raiz) {
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

No* remover(No* raiz, int matricula) {
    if (raiz == NULL) {
        cout << "Matricula " << matricula << " nao encontrada!" << endl;
        return NULL;
    }

    if (matricula < raiz->aluno.matricula) {
        raiz->esq = remover(raiz->esq, matricula);
    } else if (matricula > raiz->aluno.matricula) {
        raiz->dir = remover(raiz->dir, matricula);
    } else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        No* sucessor = menorNo(raiz->dir);
        raiz->aluno = sucessor->aluno;
        raiz->dir = remover(raiz->dir, sucessor->aluno.matricula);
    }
    return raiz;
}

void listar(No* raiz) {
    if (raiz == NULL)
        return;
    listar(raiz->esq);
    cout << "Matricula: " << raiz->aluno.matricula
         << " | Nome: " << raiz->aluno.nome
         << " | Nota: " << raiz->aluno.nota << endl;
    listar(raiz->dir);
}

No* inserirIterativo(No* raiz, Aluno a) {
    No* novo = criarNo(a);

    if (raiz == NULL)
        return novo;

    No* atual = raiz;
    No* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (a.matricula < atual->aluno.matricula) {
            atual = atual->esq;
        } else if (a.matricula > atual->aluno.matricula) {
            atual = atual->dir;
        } else {
            cout << "Matricula " << a.matricula << " ja existe!" << endl;
            delete novo;
            return raiz;
        }
    }

    if (a.matricula < pai->aluno.matricula)
        pai->esq = novo;
    else
        pai->dir = novo;

    return raiz;
}

bool ehBST(No* raiz, No* minimo, No* maximo) {
    if (raiz == NULL)
        return true;

    if (minimo != NULL && raiz->aluno.matricula <= minimo->aluno.matricula)
        return false;
    if (maximo != NULL && raiz->aluno.matricula >= maximo->aluno.matricula)
        return false;

    return ehBST(raiz->esq, minimo, raiz) &&
           ehBST(raiz->dir, raiz, maximo);
}

bool ehBST(No* raiz) {
    return ehBST(raiz, NULL, NULL);
}

int contarNos(No* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

bool todosEstaoEm(No* a, No* b) {
    if (a == NULL)
        return true;
    if (buscar(b, a->aluno.matricula) == NULL)
        return false;
    return todosEstaoEm(a->esq, b) && todosEstaoEm(a->dir, b);
}

bool mesmoConjunto(No* a, No* b) {
    if (contarNos(a) != contarNos(b))
        return false;
    return todosEstaoEm(a, b);
}

void destruir(No* raiz) {
    if (raiz == NULL)
        return;
    destruir(raiz->esq);
    destruir(raiz->dir);
    delete raiz;
}

int main() {
    No* arvore = NULL;

    cout << "===== QUESTAO 1: Inserir, Buscar, Remover, Listar =====" << endl;

    arvore = inserir(arvore, {50, "Ana", 8.5});
    arvore = inserir(arvore, {30, "Bruno", 7.0});
    arvore = inserir(arvore, {70, "Carla", 9.2});
    arvore = inserir(arvore, {20, "Diego", 6.5});
    arvore = inserir(arvore, {40, "Elisa", 8.0});
    arvore = inserir(arvore, {60, "Felipe", 5.5});
    arvore = inserir(arvore, {80, "Gabi", 10.0});

    cout << "\nLista de alunos:" << endl;
    listar(arvore);

    cout << "\nBuscando matricula 40..." << endl;
    No* encontrado = buscar(arvore, 40);
    if (encontrado != NULL)
        cout << "Encontrado: " << encontrado->aluno.nome << endl;
    else
        cout << "Nao encontrado." << endl;

    cout << "\nBuscando matricula 99..." << endl;
    encontrado = buscar(arvore, 99);
    if (encontrado != NULL)
        cout << "Encontrado: " << encontrado->aluno.nome << endl;
    else
        cout << "Nao encontrado." << endl;

    cout << "\nRemovendo 20 (folha), 30 (um filho) e 50 (dois filhos)..." << endl;
    arvore = remover(arvore, 20);
    arvore = remover(arvore, 30);
    arvore = remover(arvore, 50);
    listar(arvore);

    cout << "\n===== QUESTAO 2: Inserir iterativo =====" << endl;

    arvore = inserirIterativo(arvore, {10, "Hugo", 7.5});
    arvore = inserirIterativo(arvore, {55, "Iris", 9.0});
    arvore = inserirIterativo(arvore, {90, "Joao", 6.0});
    arvore = inserirIterativo(arvore, {55, "Repetido", 0.0});
    listar(arvore);

    cout << "\n===== QUESTAO 3: Verificar se e BST =====" << endl;

    if (ehBST(arvore))
        cout << "A arvore principal E uma BST." << endl;
    else
        cout << "A arvore principal NAO e uma BST." << endl;

    No* errada = criarNo({50, "A", 0});
    errada->esq = criarNo({30, "B", 0});
    errada->dir = criarNo({70, "C", 0});
    errada->esq->dir = criarNo({60, "D", 0});

    if (ehBST(errada))
        cout << "A arvore montada a mao E uma BST." << endl;
    else
        cout << "A arvore montada a mao NAO e uma BST." << endl;

    cout << "\n===== QUESTAO 4: Mesmo conjunto de elementos =====" << endl;

    No* arvA = NULL;
    arvA = inserir(arvA, {5, "X", 0});
    arvA = inserir(arvA, {3, "Y", 0});
    arvA = inserir(arvA, {8, "Z", 0});

    No* arvB = NULL;
    arvB = inserir(arvB, {8, "Z", 0});
    arvB = inserir(arvB, {5, "X", 0});
    arvB = inserir(arvB, {3, "Y", 0});

    No* arvC = NULL;
    arvC = inserir(arvC, {5, "X", 0});
    arvC = inserir(arvC, {3, "Y", 0});
    arvC = inserir(arvC, {9, "W", 0});

    if (mesmoConjunto(arvA, arvB))
        cout << "A e B tem o mesmo conjunto de elementos." << endl;
    else
        cout << "A e B NAO tem o mesmo conjunto de elementos." << endl;

    if (mesmoConjunto(arvA, arvC))
        cout << "A e C tem o mesmo conjunto de elementos." << endl;
    else
        cout << "A e C NAO tem o mesmo conjunto de elementos." << endl;

    destruir(arvore);
    destruir(errada);
    destruir(arvA);
    destruir(arvB);
    destruir(arvC);

    return 0;
}