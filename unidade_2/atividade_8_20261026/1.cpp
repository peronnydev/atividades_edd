#include <iostream>
using namespace std;

struct Conteudo {
    string texto;
    Conteudo* prox;
};

struct Disciplina {
    string nome;
    int creditos;
    Conteudo* conteudos;
    Disciplina* prox;
};

struct Aluno {
    string nome;
    string cpf;
    int idade;
    string matricula;
    Disciplina* disciplinas;
    Aluno* prox;
};

struct Fila {
    Aluno* inicio;
    Aluno* fim;
    int tamanho;
};

Conteudo* buscarConteudo(Disciplina* d, string texto) {
    Conteudo* aux = d->conteudos;
    while (aux != NULL) {
        if (aux->texto == texto) return aux;
        aux = aux->prox;
    }
    return NULL;
}

bool adicionarConteudo(Disciplina* d, string texto) {
    if (d == NULL) return false;
    if (buscarConteudo(d, texto) != NULL) return false;

    Conteudo* novo = new Conteudo;
    novo->texto = texto;
    novo->prox = NULL;

    if (d->conteudos == NULL) {
        d->conteudos = novo;
    } else {
        Conteudo* aux = d->conteudos;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
    return true;
}

bool removerConteudo(Disciplina* d, string texto) {
    if (d == NULL) return false;
    Conteudo* ant = NULL;
    Conteudo* atual = d->conteudos;
    while (atual != NULL && !(atual->texto == texto)) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return false;

    if (ant == NULL) d->conteudos = atual->prox;
    else ant->prox = atual->prox;
    delete atual;
    return true;
}

void listarConteudos(Disciplina* d, const char* recuo) {
    if (d->conteudos == NULL) {
        cout << recuo << "(nenhum conteudo cadastrado)\n";
        return;
    }
    int i = 1;
    Conteudo* aux = d->conteudos;
    while (aux != NULL) {
        cout << recuo << i << ". " << aux->texto << "\n";
        aux = aux->prox;
        i++;
    }
}

void liberarConteudos(Disciplina* d) {
    Conteudo* aux = d->conteudos;
    while (aux != NULL) {
        Conteudo* prox = aux->prox;
        delete aux;
        aux = prox;
    }
    d->conteudos = NULL;
}

Disciplina* buscarDisciplina(Aluno* a, string nome) {
    Disciplina* aux = a->disciplinas;
    while (aux != NULL) {
        if (aux->nome == nome) return aux;
        aux = aux->prox;
    }
    return NULL;
}

bool adicionarDisciplina(Aluno* a, string nome, int creditos) {
    if (a == NULL) return false;
    if (buscarDisciplina(a, nome) != NULL) return false;

    Disciplina* nova = new Disciplina;
    nova->nome = nome;
    nova->creditos = creditos;
    nova->conteudos = NULL;
    nova->prox = NULL;

    if (a->disciplinas == NULL) {
        a->disciplinas = nova;
    } else {
        Disciplina* aux = a->disciplinas;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = nova;
    }
    return true;
}

bool removerDisciplina(Aluno* a, string nome) {
    if (a == NULL) return false;
    Disciplina* ant = NULL;
    Disciplina* atual = a->disciplinas;
    while (atual != NULL && !(atual->nome == nome)) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return false;

    if (ant == NULL) a->disciplinas = atual->prox;
    else ant->prox = atual->prox;
    liberarConteudos(atual);
    delete atual;
    return true;
}

void listarDisciplinas(Aluno* a) {
    if (a->disciplinas == NULL) {
        cout << "  (nenhuma disciplina cadastrada)\n";
        return;
    }
    int i = 1;
    Disciplina* aux = a->disciplinas;
    while (aux != NULL) {
        cout << "  " << i << ". " << aux->nome << " - " << aux->creditos << " credito(s)\n";
        aux = aux->prox;
        i++;
    }
}

void liberarDisciplinas(Aluno* a) {
    Disciplina* aux = a->disciplinas;
    while (aux != NULL) {
        Disciplina* prox = aux->prox;
        liberarConteudos(aux);
        delete aux;
        aux = prox;
    }
    a->disciplinas = NULL;
}

void inicializarFila(Fila& f) {
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
}

bool filaVazia(Fila& f) {
    return f.inicio == NULL;
}

int tamanhoFila(Fila& f) {
    return f.tamanho;
}

Aluno* buscarAluno(Fila& f, string matricula) {
    Aluno* aux = f.inicio;
    while (aux != NULL) {
        if (aux->matricula == matricula) return aux;
        aux = aux->prox;
    }
    return NULL;
}

bool enfileirar(Fila& f, string nome, string cpf, int idade, string matricula) {
    if (buscarAluno(f, matricula) != NULL) return false;

    Aluno* novo = new Aluno;
    novo->nome = nome;
    novo->cpf = cpf;
    novo->idade = idade;
    novo->matricula = matricula;
    novo->disciplinas = NULL;
    novo->prox = NULL;

    if (filaVazia(f)) f.inicio = novo;
    else f.fim->prox = novo;
    f.fim = novo;
    f.tamanho++;
    return true;
}

bool desenfileirar(Fila& f) {
    if (filaVazia(f)) return false;
    Aluno* removido = f.inicio;
    f.inicio = removido->prox;
    if (f.inicio == NULL) f.fim = NULL;
    liberarDisciplinas(removido);
    delete removido;
    f.tamanho--;
    return true;
}

Aluno* frente(Fila& f) {
    return f.inicio;
}

Aluno* fimFila(Fila& f) {
    return f.fim;
}

void mostrarDadosAluno(Aluno* a) {
    cout << "Nome: " << a->nome << " | CPF: " << a->cpf
         << " | Idade: " << a->idade << " | Matricula: " << a->matricula << "\n";
}

void exibirFila(Fila& f) {
    if (filaVazia(f)) {
        cout << "Fila vazia.\n";
        return;
    }
    int pos = 1;
    Aluno* aux = f.inicio;
    while (aux != NULL) {
        cout << pos << "o: ";
        mostrarDadosAluno(aux);
        aux = aux->prox;
        pos++;
    }
}

void listarTudo(Fila& f) {
    if (filaVazia(f)) {
        cout << "Fila vazia.\n";
        return;
    }
    int pos = 1;
    Aluno* a = f.inicio;
    while (a != NULL) {
        cout << "\n[" << pos << "] ";
        mostrarDadosAluno(a);
        if (a->disciplinas == NULL) {
            cout << "  (nenhuma disciplina cadastrada)\n";
        } else {
            Disciplina* d = a->disciplinas;
            while (d != NULL) {
                cout << "  - " << d->nome << " (" << d->creditos << " credito(s))\n";
                listarConteudos(d, "      ");
                d = d->prox;
            }
        }
        a = a->prox;
        pos++;
    }
}

void liberarFila(Fila& f) {
    while (!filaVazia(f)) desenfileirar(f);
}

int main() {
    Fila fila;
    inicializarFila(fila);

    enfileirar(fila, "Ana Souza", "111.222.333-44", 20, "2024001");
    enfileirar(fila, "Bruno Lima", "555.666.777-88", 22, "2024002");
    enfileirar(fila, "Carla Mendes", "999.888.777-66", 19, "2024003");

    cout << "=== Fila ===\n";
    exibirFila(fila);
    cout << "Tamanho: " << tamanhoFila(fila) << "\n";
    cout << "Primeiro: ";
    mostrarDadosAluno(frente(fila));
    cout << "Ultimo: ";
    mostrarDadosAluno(fimFila(fila));

    Aluno* ana = buscarAluno(fila, "2024001");
    Aluno* bruno = buscarAluno(fila, "2024002");

    adicionarDisciplina(ana, "Estrutura de Dados", 4);
    adicionarDisciplina(ana, "Calculo I", 6);
    adicionarDisciplina(bruno, "Programacao Orientada a Objetos", 4);

    Disciplina* ed = buscarDisciplina(ana, "Estrutura de Dados");
    adicionarConteudo(ed, "Filas");
    adicionarConteudo(ed, "Pilhas");
    adicionarConteudo(ed, "Listas encadeadas");

    Disciplina* calc = buscarDisciplina(ana, "Calculo I");
    adicionarConteudo(calc, "Limites");
    adicionarConteudo(calc, "Derivadas");

    Disciplina* poo = buscarDisciplina(bruno, "Programacao Orientada a Objetos");
    adicionarConteudo(poo, "Classes e objetos");
    adicionarConteudo(poo, "Heranca");

    cout << "\n=== Disciplinas de " << ana->nome << " ===\n";
    listarDisciplinas(ana);

    cout << "\n=== Conteudos de " << ed->nome << " ===\n";
    listarConteudos(ed, "  ");

    removerConteudo(ed, "Pilhas");
    cout << "\n=== Conteudos de " << ed->nome << " apos remover Pilhas ===\n";
    listarConteudos(ed, "  ");

    removerDisciplina(ana, "Calculo I");
    cout << "\n=== Disciplinas de " << ana->nome << " apos remover Calculo I ===\n";
    listarDisciplinas(ana);

    cout << "\n=== Todos os alunos ===";
    listarTudo(fila);

    desenfileirar(fila);
    cout << "\n=== Todos os alunos apos desenfileirar ===";
    listarTudo(fila);

    liberarFila(fila);
    cout << "\nFila vazia? " << (filaVazia(fila) ? "Sim" : "Nao") << "\n";

    return 0;
}