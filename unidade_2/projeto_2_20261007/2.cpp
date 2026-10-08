#include <iostream>
using namespace std;

string const IGRESSO_FUNK = "Funk";
string const IGRESSO_FORRO = "Forro";
string const IGRESSO_ROCK = "Rock";

struct Pessoa{
	string nome;
	int idade;
	string cidade;
	string ingresso;
	Pessoa* anterior;
	Pessoa* sucessor;
};

void adicionarNoFinal(Pessoa*& head, string nome, int idade, string cidade, string ingresso){
	Pessoa* novaPessoa = new Pessoa;
	novaPessoa->nome = nome;
	novaPessoa->idade = idade;
	novaPessoa->cidade = cidade;
	novaPessoa->ingresso = ingresso;
	novaPessoa->sucessor = NULL;
	novaPessoa->anterior = NULL;
	
	if(head == NULL){
		head = novaPessoa;
		return;
	}
	
	Pessoa* aux = head;
	while(aux->sucessor != NULL){
		aux = aux->sucessor;
	}
	
	aux->sucessor = novaPessoa;
	novaPessoa->anterior = aux;
}

void buscarPorNome(Pessoa*& head, string nome){
	if(head == NULL){
		cout << "Nenhum comprador cadastrado!" << endl;
		return;
	}
	cout << "----Mostrando compradores com o nome " << nome << endl;
	for(Pessoa* aux = head; aux != NULL; aux = aux->sucessor){
		if(aux->nome == nome){
			cout << "Nome:     " << aux->nome << endl;
			cout << "Idade:    " << aux->idade << endl;
			cout << "Cidade:   " << aux->cidade << endl; 
			cout << "Ingresso: " << aux->ingresso << endl;
			cout << "----" << endl;	
		}
	}
}

void removerPorNomeEIngresso(Pessoa*& head, string nome, string ingresso){
	if(head == NULL){
		cout << "Nenhum comprador cadastrado!" << endl;
		return;
	}
	for(Pessoa* aux = head; aux != NULL; aux = aux->sucessor){
		if(aux->nome == nome && aux->ingresso == ingresso){
			cout << "----Removendo o comprador com as caracteristicas abaixo " << endl;
			cout << "Nome:     " << aux->nome << endl;
			cout << "Cidade:   " << aux->cidade << endl;
			cout << "Ingresso: " << aux->ingresso << endl;
			
			if(aux->anterior != NULL){
				aux->anterior->sucessor = aux->sucessor;
			} else {
				head = aux->sucessor;
			}
			if(aux->sucessor != NULL){
				aux->sucessor->anterior = aux->anterior;
			}
			delete aux;
			return;
		}
	}
	cout << "Comprador nao encontrado!" << endl;
}

void verCompradores(Pessoa*& head){
	if(head == NULL){
		cout << "Nenhum comprador cadastrado" << endl;
		return;
	}
	Pessoa* ultimo = NULL;
	cout << "Mostrando compradores do inicio ao fim" << endl;
	for(Pessoa* aux = head; aux != NULL; aux = aux->sucessor){
		cout << "Nome:     " << aux->nome << endl;
		cout << "Idade:    " << aux->idade << endl;
		cout << "Cidade:   " << aux->cidade << endl;
		cout << "Ingresso: " << aux->ingresso << endl;
		cout << "----" << endl;
		ultimo = aux;
	}
	
	cout << "Mostrando compradores do fim ao inicio" << endl;
	for(Pessoa* aux = ultimo; aux != NULL; aux = aux->anterior){
		cout << "Nome:     " << aux->nome << endl;
		cout << "Idade:    " << aux->idade << endl;
		cout << "Cidade:   " << aux->cidade << endl;
		cout << "Ingresso: " << aux->ingresso << endl;
		cout << "----" << endl;
	}
}

string escolherIngresso(){
	int opcao;
	
	cout << "1 - " << IGRESSO_FUNK << endl;
	cout << "2 - " << IGRESSO_FORRO << endl;
	cout << "3 - " << IGRESSO_ROCK << endl;
	cout << "Escolha o show: ";
	cin >> opcao;
	
	if(opcao == 1) return IGRESSO_FUNK;
	if(opcao == 2) return IGRESSO_FORRO;
	return IGRESSO_ROCK;
}

int main(){
	Pessoa* head = NULL;
	
	int opcao = -1;
	while(opcao != 0){
		cout << endl;
		cout << "----Escolha uma opcao" << endl;
		cout << "1 - Cadastrar novo comprador" << endl;
		cout << "2 - Buscar comprador pelo nome" << endl;
		cout << "3 - Excluir comprador" << endl;
		cout << "4 - Visualizar compradores (ordem de cadastro e ordem inversa)" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		
		if(opcao == 1){
			string nome, cidade;
			int idade;
			cout << "Nome: ";
			cin >> nome;
			cout << "Idade: ";
			cin >> idade;
			cout << "Cidade: ";
			cin >> cidade;
			string ingresso = escolherIngresso();
			adicionarNoFinal(head, nome, idade, cidade, ingresso);
			cout << "Comprador cadastrado com sucesso!" << endl;
		}
		else if(opcao == 2){
			string nome;
			cout << "Nome do comprador: ";
			cin >> nome;
			buscarPorNome(head, nome);
		}
		else if(opcao == 3){
			string nome;
			cout << "Nome do comprador a excluir: ";
			cin >> nome;
			string ingresso = escolherIngresso();
			removerPorNomeEIngresso(head, nome, ingresso);
		}
		else if(opcao == 4){
			verCompradores(head);
		}
		else if(opcao == 0){
			cout << "Encerrando o sistema..." << endl;
		}
		else{
			cout << "Opcao invalida!" << endl;
		}
	}
	
	return 0;
}