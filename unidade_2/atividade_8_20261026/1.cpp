#include <iostream>
using namespace std;

struct Conteudo{
	Conteudo* sucessor;
	string nome;
};

struct Disciplina{
	Disciplina* sucessor;
	Conteudo* conteudo;
	string nome;
	int quantidadeCreditos;
};

struct Aluno{
	Aluno* sucessor;
	Disciplina* disciplina;
	string nome;
	string cpf;
	int idade;
	string matricula;
};

void listarConteudosDisciplina(Conteudo*& top){
	for(Conteudo* aux = top; aux != NULL; aux = aux -> sucessor){
		cout << "      " << aux -> nome << endl;
	}
}

void listarDisciplinasAluno(Disciplina*& top){
	for(Disciplina* aux = top; aux != NULL; aux = aux -> sucessor){
		cout << "    " << aux -> nome << endl;
		listarConteudosDisciplina(aux -> conteudo);
	}
}

void listarAlunos(Aluno*& top){
	for(Aluno* aux = top; aux != NULL; aux = aux -> sucessor){
		cout << "  " << aux -> nome << endl;
		listarDisciplinasAluno(aux -> disciplina);
	}
}

void adicionarDisciplinaAluno(Aluno*& aluno, Disciplina* disciplina){
	if(aluno == NULL || disciplina == NULL){
		cout << "Erro: Aluno ou Disciplina nulo" << endl;
		return;
	}
	
	Disciplina* novaDisciplina = new Disciplina{
		NULL,
		disciplina -> conteudo,
		disciplina -> nome,
		disciplina -> quantidadeCreditos
	};
	
	Disciplina* aux = aluno -> disciplina;
	
	if(aux == NULL){
		aluno -> disciplina = novaDisciplina;
		return;
	}
	
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	
	aux -> sucessor = novaDisciplina;
	
	return;
}

void adicionarConteudoDisciplina(Disciplina*& disciplina, Conteudo* conteudo){
	if(disciplina == NULL || conteudo == NULL){
		cout << "Erro: disciplina ou conteudo nulo" << endl;
		return;
	}
	
	Conteudo* novoConteudo = new Conteudo{
		NULL,
		conteudo -> nome
	};
	
	if(disciplina -> conteudo == NULL){
		disciplina -> conteudo = novoConteudo;
		return;
	}
	
	Conteudo* aux = disciplina -> conteudo;
	
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	
	aux -> sucessor = novoConteudo;
	return;
}

void adicionarAluno(Aluno*& aluno, Aluno* novoAluno){
	if(aluno == NULL || novoAluno == NULL){
		cout << "Erro: Aluno ou novoAluno nulo" << endl;
		return;
	}
	
	Aluno* aux = aluno;
	
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	
	aux -> sucessor = novoAluno;
	return;
}

void removerAluno(Aluno*& alunoTop, string matricula){
	if(alunoTop -> matricula == matricula){
		alunoTop = alunoTop -> sucessor;
		return;
	}
	for(Aluno* aux = alunoTop; aux -> sucessor != NULL; aux = aux -> sucessor){
		if(aux -> sucessor -> matricula == matricula){
			aux -> sucessor = aux -> sucessor -> sucessor;
			return;
		}
	}
	cout << "Erro: Aluno para remover nao encontrado" << endl;
	return;
}

void removerDisciplina(Aluno*& alunoTop, string nome){
	Disciplina*& disciplinaTop = alunoTop -> disciplina;
	if(disciplinaTop -> nome == nome){
		disciplinaTop = disciplinaTop -> sucessor;
		return;
	}
	for(Disciplina* aux = disciplinaTop; aux -> sucessor != NULL; aux = aux -> sucessor){
		if(aux -> sucessor -> nome == nome){
			aux -> sucessor = aux -> sucessor -> sucessor;
			return;
		}
	}
	cout << "Erro: Disciplina para remover nao encontrada" << endl;
	return;
}

void removerConteudo(Disciplina*& disciplinaTop, string nome){
	Conteudo*& conteudoTop = disciplinaTop -> conteudo;
	if(conteudoTop -> nome == nome){
		conteudoTop = conteudoTop -> sucessor;
		return;
	}
	for(Conteudo* aux = conteudoTop; aux -> sucessor != NULL; aux = aux -> sucessor){
		if(aux -> sucessor -> nome == nome){
			aux -> sucessor = aux -> sucessor -> sucessor;
			return;
		}
	}
	cout << "Coteudo para remover nao encontrado" << endl;
	return;
}

int main(){
	Disciplina* edd = new Disciplina{
		NULL,
		NULL,
		"Estrutura de dados",
		8
	};
	
	Disciplina* poo = new Disciplina{
		NULL,
		NULL,
		"Programacao Orientada a Objetos",
		8
	};
	
	Disciplina* db = new Disciplina{
		NULL,
		NULL,
		"Banco de Dados",
		6
	};
	
	Conteudo* c1 = new Conteudo{NULL, "Ponteiros"};
	Conteudo* c2 = new Conteudo{NULL, "Lista"};
	Conteudo* c3 = new Conteudo{NULL, "Fila"};
	Conteudo* c4 = new Conteudo{NULL, "Pilha"};
	
	Conteudo* c5 = new Conteudo{NULL, "Classes"};
	Conteudo* c6 = new Conteudo{NULL, "Objetos"};
	Conteudo* c7 = new Conteudo{NULL, "Polimorfismo"};
	Conteudo* c8 = new Conteudo{NULL, "Eranca"};
	
	Conteudo* c9 = new Conteudo{NULL, "Select"};
	Conteudo* c10 = new Conteudo{NULL, "Join"};
	Conteudo* c11 = new Conteudo{NULL, "Where"};
	Conteudo* c12 = new Conteudo{NULL, "Tables"};
	
	
	adicionarConteudoDisciplina(edd, c1);
	adicionarConteudoDisciplina(edd, c2);
	adicionarConteudoDisciplina(edd, c3);
	adicionarConteudoDisciplina(edd, c4);
	
	adicionarConteudoDisciplina(poo, c5);
	adicionarConteudoDisciplina(poo, c6);
	adicionarConteudoDisciplina(poo, c7);
	adicionarConteudoDisciplina(poo, c8);
	
	adicionarConteudoDisciplina(db, c9);
	adicionarConteudoDisciplina(db, c10);
	adicionarConteudoDisciplina(db, c11);
	adicionarConteudoDisciplina(db, c12);
	
	Aluno* peronny = new Aluno{
		NULL,
		NULL,
		"Peronny",
		"12312312312",
		20,
		"1"
	};
	
	Aluno* kailany = new Aluno{
		NULL,
		NULL,
		"Kailany",
		"45645645645",
		24,
		"2"
	};
	
	Aluno* samurai = new Aluno{
		NULL,
		NULL,
		"Samurai",
		"78978978978",
		14,
		"3"
	};
	
	adicionarAluno(peronny, kailany);
	adicionarAluno(peronny, samurai);
	
	adicionarDisciplinaAluno(peronny, edd);
	adicionarDisciplinaAluno(peronny, db);
	adicionarDisciplinaAluno(kailany, edd);
	adicionarDisciplinaAluno(kailany, db);
	adicionarDisciplinaAluno(kailany, poo);
	adicionarDisciplinaAluno(samurai, db);
	
	removerDisciplina(kailany, "Banco de Dados");
	removerAluno(peronny, "3");
	listarAlunos(peronny);
}