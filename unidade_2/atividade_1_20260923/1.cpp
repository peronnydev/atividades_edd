#include <iostream>
using namespace std;

struct No{
	int value;
	No* next;
};

int returnIndexFinal(No*& head){
	if(head -> next == NULL){
		cout << "[" << head -> value << "]" << endl;
		return 0;
	};
	
	cout << "[" << head -> value << "]";
	No* atual = head -> next;
	int contador = 1;
	
	while(atual -> next != NULL){
		cout << "[" << atual -> value << "]";
		atual = atual -> next;
		contador ++;
	}
	cout << "[" << atual -> value << "]" << endl;
	cout << "Numero do index final: " << contador << endl;
	return contador;
}

void inserirNoFinal(No*& cabeca, int valorDoNo){
	No* novoNo = new No;
	novoNo -> next = NULL;
	novoNo -> value = valorDoNo;
	
	if(cabeca -> next == NULL){
		cabeca -> next = novoNo;
		return;
	}
	
	No* temp = new No;
	temp = cabeca -> next;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = novoNo;
}

void removerIndex(No*& head, int index){
	if(index == 0){
		head = head -> next;
		return;
	}
	No* atual = head;
	for(int i = 0; i <= index; i++){
		if(i == index -1){
			No* indexQueSeraRemovido = atual -> next;
			atual -> next = indexQueSeraRemovido -> next;
		}
		atual = atual -> next;
	}
}

int main(){
	No* head = new No;
	head -> value = 1;
	head -> next = NULL;
	
	inserirNoFinal(head, 2);
	inserirNoFinal(head, 3);
	inserirNoFinal(head, 4);
	returnIndexFinal(head);
	removerIndex(head, 2);
	returnIndexFinal(head);
}