#include <iostream>
using namespace std;

struct No{
	int value;
	No* next;
};

void inserirNoFinal(No* head, int valor){
	No* novo = new No;
	novo -> value = valor;
	novo -> next = NULL;
	
	if(head -> next == NULL){
		head -> next = novo;
		return;
	}

	No* atual = head -> next;
	while(atual -> next != NULL){
		atual = atual -> next;
	}
	atual -> next = novo;
}

int returnIndexFinal(No*& head){
	if(head -> next == NULL){
		return 0;
	}
	No* atual = head -> next;
	int indexFinal = 1;
	while(atual -> next != NULL){
		atual = atual -> next;
		indexFinal++;
	}
	return indexFinal;
}

int returnIndexMeio(No*& head){
	int indexFinal = returnIndexFinal(head);
	int indexMeio = indexFinal/2;
	No* atual = head -> next;
	for(int i = 1; i <= indexMeio; i++){
		atual = atual -> next;
	}
	cout << "valor do index do meio: " << atual -> value << endl;
}

bool valorExiste(No*& head, int alvo){
	int indexFinal = returnIndexFinal(head);
	
	if(head -> value == alvo){
		return true;
	}
	
	No* atual = head -> next;
	for(int i = 1; i <= indexFinal; i++){
		if(atual -> value == alvo){
			return true;
		}
		atual = atual -> next;
	}
	return false;
}

int main(){
	No* head = new No;
	head -> value = 1;
	head -> next = NULL;
	
	inserirNoFinal(head, 2);
	inserirNoFinal(head, 3);
	inserirNoFinal(head, 4);
	inserirNoFinal(head, 5);
	inserirNoFinal(head, 6);
	
	returnIndexMeio(head);
	
	int alvo = 1;
	cout << "O valor " << alvo << " esta presente no vetor? " << valorExiste(head, alvo) << endl; 
}