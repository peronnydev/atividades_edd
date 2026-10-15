#include <iostream>
using namespace std;

struct pilha{
	pilha* sucessor;
	string valor;
};

int size(pilha*& topo){
	int tamanho = 0;
	if(topo == NULL){
		return tamanho;
	}
	for(pilha* aux = topo; aux != NULL; aux = aux -> sucessor){
		tamanho++;
	}
	return tamanho;
}

void push(pilha*& topo, string valorNovo){
	pilha* novoNo = new pilha;
	if(topo == NULL){
		novoNo -> sucessor = NULL;
		novoNo -> valor = valorNovo;
		topo = novoNo;
		return;
	}
	novoNo -> sucessor = topo;
	novoNo -> valor = valorNovo;
	
	topo = novoNo;
}

void deletarElementoDoMeio(pilha*& topo){
	int deletarPosicao = size(topo) % 2;
	pilha* aux = topo;
	for(int i = 0; i < deletarPosicao -1; i++){
		aux = aux -> sucessor;
	};
	aux -> sucessor = aux -> sucessor -> sucessor;
}

void print(pilha*& topo){
	for(pilha* aux = topo; aux != NULL; aux = aux -> sucessor){
		cout << "[" << aux -> valor << "]";
	}
	cout << endl;
}

int main(){
	pilha* topo = NULL;
	push(topo, "a");
	push(topo, "b");
	push(topo, "c");
	push(topo, "d");
	print(topo);
	deletarElementoDoMeio(topo);
	print(topo);
	deletarElementoDoMeio(topo);
	print(topo);
	deletarElementoDoMeio(topo);
	print(topo);
	
}