#include <iostream>
using namespace std;

struct fila{
	int prioridade;
	string nome;
	fila* sucessor;
};

void printFila(fila*& front){
	fila* aux = front;
	int contador = 1;
	for(int i = 4; i >= 0; i--){
		for(fila* aux = front; aux != NULL; aux = aux -> sucessor){
			if(aux -> prioridade == i){
				cout << contador << " - " << aux -> nome << endl;
				contador++; 
			}
		}
	}
}

int size(fila*& front){
	int contador = 0;
	fila* aux = front;
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
		contador++;
	}
	return contador;
}

void pop(fila*& front){
	fila* aux = front;
	int maiorPrioridade = 1;
	
	for(fila* aux = front; aux -> sucessor != NULL; aux = aux -> sucessor){
		if(aux -> prioridade > maiorPrioridade){
			maiorPrioridade = aux -> prioridade;
		}
	}
	
	if(front -> prioridade == maiorPrioridade){
		front = front -> sucessor;
		return;
	}
	
	for(fila* aux = front; aux -> sucessor != NULL; aux = aux -> sucessor){
		if(aux -> sucessor -> prioridade == maiorPrioridade){
			aux -> sucessor = aux -> sucessor -> sucessor;
			return;
		}
	}
	
}

void push(fila*& front, int prioridade, string nome){
	
	fila* novoElemento = new fila;
	novoElemento -> nome = nome;
	novoElemento -> prioridade = prioridade;
	novoElemento -> sucessor = NULL;
	
	if(front == NULL){
		front = novoElemento;
		return;
	}
	
	fila* aux = front;
	while(aux -> sucessor != NULL){
		aux = aux -> sucessor;
	}
	
	aux -> sucessor = novoElemento;
}

int main(){
	fila* front = NULL;
	
	push(front, 3, "Gestante");
	push(front, 1, "Normal");
	push(front, 2, "Autista");
	push(front, 4, "Idoso");
	push(front, 3, "PCD");
	push(front, 2, "Autista");
	push(front, 3, "PCD");
	push(front, 4, "Idoso");
	push(front, 1, "Normal");
	push(front, 3, "Gestante");
	push(front, 4, "Idoso");
	push(front, 2, "Autista");
	push(front, 3, "Gestante");
	push(front, 3, "PCD");
	push(front, 1, "Normal");
	push(front, 2, "Autista");
	push(front, 4, "Idoso");
	push(front, 3, "Gestante");
	push(front, 3, "PCD");
	push(front, 1, "Normal");

	printFila(front);
	
	pop(front);
	pop(front);
	pop(front);
	pop(front);
	pop(front);
	
	cout << "Funcao pop foi chamada 5 vezes" << endl;
	
	printFila(front);
}