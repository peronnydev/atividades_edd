#include <iostream>
using namespace std;

struct No{
	string nome;
	int idade;
	No* sucessor;
	No* anterior;
};

void inserir(No*& head, string nomeNovo, int idadeNova){
	No* novoAluno = new No;
	novoAluno -> sucessor = NULL;
	novoAluno -> nome = nomeNovo;
	novoAluno -> idade = idadeNova;
	
	No* aux = head;
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	
	aux -> sucessor = novoAluno;
	novoAluno -> anterior = aux;
}

No* pesquisarPorNome(No*& head, string nomePesquisa){
	No* aux = head;
	while(aux != NULL){
		if(aux -> nome == nomePesquisa){
			cout << "-- Aluno pesquisado: " << endl;
			cout << "Nome:  " << aux -> nome << endl;
			cout << "Idade: " << aux -> idade << endl;
			return aux;
		}
		aux = aux -> sucessor;
	}
	return aux; 
}

void imprimirLista(No*& head){
	No* aux = head;
	cout << "-- Alunos cadastrados" << endl;
	while(aux != NULL){
		cout << "Nome:  " << aux -> nome << endl;
		cout << "Idade: " << aux -> idade << endl;
		cout << "------" << endl;
		aux = aux -> sucessor;
	}
}

void removerAlunoPorNome(No*& head, string nome){
	No* alunoParaRemover = pesquisarPorNome(head, nome);
	
	cout << "--Aluno removido: " << endl;
	cout << "Nome:  " << alunoParaRemover -> nome << endl;
	cout << "Idade: " << alunoParaRemover -> idade << endl;
	
	No* anteriorAoRemovido = alunoParaRemover -> anterior;
	No* sucessorAoRemovido = alunoParaRemover -> sucessor;
	
	anteriorAoRemovido -> sucessor = sucessorAoRemovido;
	sucessorAoRemovido -> anterior = anteriorAoRemovido;
}

int main(){
	No* head = new No;
	head -> sucessor = NULL;
	head -> anterior = NULL;
	head -> idade = 20;
	head -> nome = "Peronny Segundo";
	
	inserir(head, "Nicolas", 22);
	inserir(head, "Rene", 48);
	
	imprimirLista(head);
	removerAlunoPorNome(head, "Rene");
	imprimirLista(head);
}