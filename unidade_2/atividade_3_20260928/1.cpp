#include <iostream>
using namespace std;

struct No{
	No* anterior;
	int valor;
	No* sucessor;
};

void inserirNoFinal(No*& head, int value){
	No* novo = new No;
	novo -> sucessor = NULL;
	novo -> valor = value;
	if(head -> sucessor == NULL){
		head -> sucessor = novo;
		novo -> anterior = head;
		return;
	}
	No* atual = head -> sucessor;
	while(atual -> sucessor != NULL){
		atual = atual -> sucessor;
	}
	atual -> sucessor = novo;
	novo -> anterior = atual;
	return;
}

void inserirNoComeco(No*& head, int value){
	No* novoNo = new No;
	
	novoNo -> valor = head -> valor;
	novoNo -> sucessor = head -> sucessor;
	novoNo -> anterior = head;
	
	head -> sucessor -> anterior = novoNo;
	
	head -> sucessor = novoNo;
	head -> valor = value;
	head -> anterior = NULL;
	
	return;
}

void imprimirLista(No*& head){
	cout << "Imprimindo lista do inicio ao fim" << endl;
	cout << "[" << head -> valor << "]";
	No* atual = head -> sucessor;
	while(atual -> sucessor != NULL){
		cout << "[" << atual -> valor << "]";
		atual = atual -> sucessor;
	}
	cout << "[" << atual -> valor << "]" << endl;
	
	cout << "Imprimindo lista do fim ao inicio" << endl;
	cout << "[" << atual -> valor << "]";
	atual = atual -> anterior;
	while(atual -> anterior != NULL){
		cout << "[" << atual -> valor << "]";
		atual = atual -> anterior;
	}
	cout << "[" << atual -> valor << "]" << endl;
}

int ultimoIndex(No*& head){
	No* proximo = head -> sucessor;
	int contador = 1;
	while(proximo -> sucessor != NULL){
		proximo = proximo -> sucessor;
		contador++;
	}
	return contador;
}

int buscarValor(No*& head, int alvo){
	int contador = 0;
	if(head -> valor == alvo){
		return contador;
	};
	No* proximo = head -> sucessor;
	while(proximo -> sucessor != NULL){
		contador++;
		if(proximo -> valor == alvo){
			return contador;
		}
		proximo = proximo -> sucessor;
	}
	return -1;
}

void removerPeloIndex(No*& head, int index){
	No* aux = head;
	if(index == 0){
		head = head -> sucessor;
		head -> anterior = NULL;
		return;
	}
	for(int i = 0; i < index; i++){
		aux = aux -> sucessor;
	}
	No* noAnterior = aux -> anterior;
	No* noSucessor = aux -> sucessor;
	noAnterior -> sucessor = noSucessor;
	noSucessor -> anterior = noAnterior;
	delete aux;
}

void adicionarPeloIndex(No*& head, int index, int valorNovoNo){
	if(index == 0){
		inserirNoComeco(head, valorNovoNo);
		return;
	}
	if (index == ultimoIndex(head)){
		inserirNoFinal(head, valorNovoNo);
		return;
	}
	No* aux = head;
	for(int i = 1; i < index; i++){
		aux = aux -> sucessor;
	}
	No* novoNo = new No;
	novoNo -> valor = valorNovoNo;
	novoNo -> anterior = aux;
	novoNo -> sucessor = aux -> sucessor;
	aux -> sucessor -> anterior = novoNo;
	aux -> sucessor = novoNo;
}

int main(){
	No* head = new No;
	head -> sucessor = NULL;
	head -> anterior = NULL;
	head -> valor = 1;
	inserirNoFinal(head, 2);
	inserirNoFinal(head, 3);
	inserirNoFinal(head, 4);
	inserirNoFinal(head, 5);
	inserirNoFinal(head, 6);
	inserirNoFinal(head, 7);
	/*
	Para que tudo funcione corretamente a lista deve ter pelo menos 2 elementos
	Não foi feito validação para lista com 1 ou 0 elementos
	NAO É PQ TEM COMENTARIO QUE FOI FEITO POR IA!!!!!!!!
	*/
	
	imprimirLista(head);
	cout << "Tamanho da lista (index): " << ultimoIndex(head) << endl;
	cout << "O valor 4 possui o index: " << buscarValor(head, 4) << endl;
	removerPeloIndex(head, 3);
	cout << "O valor 4 (index 3) foi removido" << endl;
	imprimirLista(head);
	cout << "Inserindo o valor 0 ao comeco" << endl;
	inserirNoComeco(head, 0);
	imprimirLista(head);
	cout << "O index 4 deve ser o valor 90" << endl;
	adicionarPeloIndex(head, 4, 90);
	imprimirLista(head);
	
}