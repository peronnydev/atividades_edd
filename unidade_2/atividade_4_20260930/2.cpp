#include <iostream>
using namespace std;

struct No{
	No* sucessor;
	int valor;
	No* anterior;
};

void inserir(No*& head, int valorNovo){
	No* aux = head;
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	No* novoNo = new No;
	novoNo -> anterior = aux;
	novoNo -> sucessor = NULL;
	novoNo -> valor = valorNovo;
	aux -> sucessor = novoNo;
}

int pesquisarValor(No*& head, int valorParaPesquisa){
	int contador = 0;
	No* aux = head;
	while(aux != NULL){
		if(aux -> valor == valorParaPesquisa){
			return aux -> valor;
		}
		contador++;
		aux = aux -> sucessor;
	}
	return -1;
}

int main(){
	No* head = new No;
	head -> sucessor = NULL;
	head -> anterior = NULL;
	head -> valor = 0;
	
	inserir(head, 1);
	inserir(head, 2);
	inserir(head, 3);
	inserir(head, 4);
	inserir(head, 5);
	
	int log = pesquisarValor(head, 0);
	cout << "O numero 0 esta no index: " << log << endl;
	log = pesquisarValor(head, 5);
	cout << "O numero 5 esta no index: " << log << endl;
	log = pesquisarValor(head, 100);
	if(log == -1){
		cout << "O valor pesquisado nao foi encontrado" << endl;
	}
}

