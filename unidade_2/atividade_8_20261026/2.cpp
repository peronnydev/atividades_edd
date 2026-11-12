#include <iostream>
using namespace std;

struct Disciplina {
    string nome;
    string professor;
    int quantidadeCreditos;
};

struct NoDisciplina {
    Disciplina* disciplina;
    NoDisciplina* sucessor;
    NoDisciplina* anterior;
};

struct Aluno {
    NoDisciplina* noDisciplina;
    string nome;
    string matricula;
    string cpf;
    int idade;
};

struct NoAluno {
    Aluno* aluno;
    NoAluno* sucessor;
    NoAluno* anterior;
};

void adicionarDisciplina(NoDisciplina*& noDisciplina, Disciplina* disciplina) {
    NoDisciplina* novoNo = new NoDisciplina;
    novoNo -> disciplina = disciplina;
    novoNo -> sucessor = nullptr;
    novoNo -> anterior = nullptr;
    if (noDisciplina == nullptr) {
        noDisciplina = novoNo;
        return;
    }
    NoDisciplina* aux = noDisciplina;
    while (aux -> sucessor != nullptr) {
        aux = aux -> sucessor;
    }
    novoNo -> anterior = aux;
    aux -> sucessor = novoNo;
}

Disciplina* retornarDisciplinaPeloNome(NoDisciplina*& noDisciplina, string nome) {
    for (NoDisciplina* aux = noDisciplina; aux -> sucessor != nullptr; aux = aux -> sucessor) {
        if (aux -> disciplina -> nome == nome) {
            return aux -> disciplina;
        }
    }
    cout << "Disciplina com o nome: " << nome << " não encontrada" << endl;
    return nullptr;
}

void removerDisciplina(NoDisciplina*& noDisciplina, string nome) {
    Disciplina* disciplinaParaRemover = retornarDisciplinaPeloNome(noDisciplina, nome);
    if (noDisciplina -> disciplina == disciplinaParaRemover) {
        noDisciplina = noDisciplina -> sucessor;
        return;
    }
    for (NoDisciplina* aux = noDisciplina; aux != nullptr; aux = aux -> sucessor) {
        if (aux -> disciplina == disciplinaParaRemover) {
            NoDisciplina* anteriorAoQueDeveSerRemovido = aux -> anterior;
            NoDisciplina* sucessorAoQueDeveSerRemovido = aux -> sucessor;
            anteriorAoQueDeveSerRemovido -> sucessor = sucessorAoQueDeveSerRemovido;
            sucessorAoQueDeveSerRemovido -> anterior = anteriorAoQueDeveSerRemovido;
            delete aux;
            return;
        }
    }
}

void adicionarAluno(NoAluno*& noAluno, Aluno* aluno) {
    NoAluno* novoNo = new NoAluno;
    novoNo -> aluno = aluno;
    novoNo -> sucessor = nullptr;

    if (noAluno == nullptr) {
        noAluno = novoNo;
        return;
    }

    NoAluno* aux = noAluno;
    while (aux -> sucessor != nullptr) {
        aux = aux -> sucessor;
    }
    novoNo -> anterior = aux;
    aux -> sucessor = novoNo;
}

Aluno* retornarAlunoPelaMatricula(NoAluno*& noAluno, string matricula) {
    for (NoAluno* aux = noAluno; aux -> sucessor != nullptr; aux = aux -> sucessor) {
        if (aux -> aluno -> matricula == matricula) {
            return aux -> aluno;
        }
    }
    cout << "Aluno com matricula: " << matricula << " não encontrado" << endl;
    return nullptr;
}

void removerAluno(NoAluno*& noAluno, string matricula) {
    Aluno* alunoParaRemover = retornarAlunoPelaMatricula(noAluno, matricula);
    
    for (NoAluno* aux = noAluno; aux != nullptr; aux = aux -> sucessor) {
        if (aux -> aluno == alunoParaRemover) {
            NoAluno* anteriorAoQueDeveSerRemovido = aux -> anterior;
            NoAluno* sucessorAoQueDeveSerRemovido = aux -> sucessor;
            anteriorAoQueDeveSerRemovido -> sucessor = sucessorAoQueDeveSerRemovido;
            sucessorAoQueDeveSerRemovido -> anterior = anteriorAoQueDeveSerRemovido;
            delete aux;
            return;
        }
    }
}

void listarDisciplinas(NoDisciplina*& top) {
    for (NoDisciplina* aux = top; aux != nullptr; aux = aux -> sucessor) {
        cout << "    " << aux -> disciplina -> nome << endl;
    }
}

void listarAlunosComSuasDisciplinas(NoAluno*& top) {
    for (NoAluno* aux = top; aux != nullptr; aux = aux -> sucessor) {
        cout << aux -> aluno -> nome << endl;
        listarDisciplinas(aux -> aluno -> noDisciplina);
    }
}

int main() {
    NoAluno* noAluno = nullptr;
    NoDisciplina* noDisciplina = nullptr;

    Disciplina* d1 = new Disciplina{"Estrutura de Dados", "João", 16};
    Disciplina* d2 = new Disciplina{"Banco de Dados", "Gervasio", 8};
    Disciplina* d3 = new Disciplina{"Programacao Orientada a Objetos", "Erlon", 8};

    adicionarDisciplina(noDisciplina, d1);
    adicionarDisciplina(noDisciplina, d2);
    adicionarDisciplina(noDisciplina, d3);

    Aluno* a1 = new Aluno{noDisciplina, "Peronny", "1", "12312312312", 20};
    Aluno* a2 = new Aluno{noDisciplina, "Kailany", "1", "45645645645", 24};
    Aluno* a3 = new Aluno{noDisciplina, "Zezinho", "3", "78978978978", 22};

    adicionarAluno(noAluno, a1);
    adicionarAluno(noAluno, a2);
    adicionarAluno(noAluno, a3);

    listarAlunosComSuasDisciplinas(noAluno);
}