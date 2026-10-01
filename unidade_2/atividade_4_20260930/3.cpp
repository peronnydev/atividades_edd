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

void apagarValor(No*& head, int valorParaApagar){
	No* aux = head;
	if(pesquisarValor(head, valorParaApagar) == -1){
		return;
	}
	while(aux -> valor != valorParaApagar){
		aux = aux -> sucessor;
	}
	No* anteriorAoRemovido = aux -> anterior;
	No* sucessorAoRemovido = aux -> sucessor;
	
	anteriorAoRemovido -> sucessor = sucessorAoRemovido;
	sucessorAoRemovido -> anterior = anteriorAoRemovido;
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
	
	cout << "O valor 3 existe e será apagado." << endl;
	apagarValor(head, 3);
	if(pesquisarValor(head, 3) == -1){
		cout << "O valor 3 foi apagado" << endl;
		return 1;
	}
	cout << "Erro ao apagar o valor" << endl;
}

