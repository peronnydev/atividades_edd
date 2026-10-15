#include <iostream>
using namespace std;

struct pilha{
	pilha* sucessor;
	string valor;
};

int size(pilha*& topo){
	int tamanho = 0;
	for(pilha* aux = topo; aux != NULL; aux = aux -> sucessor){
		tamanho++;
	}
	return tamanho;
}

void push(pilha*& topo, string valorNovo){
	pilha* novoNo = new pilha;
	novoNo -> sucessor = topo;
	novoNo -> valor = valorNovo;
	topo = novoNo;
}

string pop(pilha*& topo){
	pilha* removido = topo;
	string v = removido -> valor;
	topo = topo -> sucessor;
	delete removido;
	return v;
}

void print(pilha*& topo){
	for(pilha* aux = topo; aux != NULL; aux = aux -> sucessor){
		cout << "[" << aux -> valor << "]";
	}
	cout << endl;
}

void deletarElementoDoMeio(pilha*& topo){
	int n = size(topo);
	if(n == 0){
		return;
	}
	int posicao = n / 2;
	if(posicao == 0){
		pop(topo);
		return;
	}
	pilha* aux = topo;
	for(int i = 0; i < posicao - 1; i++){
		aux = aux -> sucessor;
	}
	pilha* removido = aux -> sucessor;
	aux -> sucessor = removido -> sucessor;
	delete removido;
}

string inverterString(string palavra){
	pilha* p = NULL;
	for(int i = 0; palavra[i] != '\0'; i++){
		string letra = "";
		letra += palavra[i];
		push(p, letra);
	}
	string resultado = "";
	while(p != NULL){
		resultado += pop(p);
	}
	return resultado;
}

void removerDuplicados(pilha*& topo){
	for(pilha* atual = topo; atual != NULL; atual = atual -> sucessor){
		pilha* anterior = atual;
		while(anterior -> sucessor != NULL){
			if(anterior -> sucessor -> valor == atual -> valor){
				pilha* removido = anterior -> sucessor;
				anterior -> sucessor = removido -> sucessor;
				delete removido;
			} else {
				anterior = anterior -> sucessor;
			}
		}
	}
}

bool ehPalindromo(string palavra){
	pilha* p = NULL;
	for(int i = 0; palavra[i] != '\0'; i++){
		string letra = "";
		letra += palavra[i];
		push(p, letra);
	}
	bool palindromo = true;
	for(int i = 0; palavra[i] != '\0'; i++){
		string letra = pop(p);
		if(letra[0] != palavra[i]){
			palindromo = false;
		}
	}
	return palindromo;
}

int main(){
	pilha* topo = NULL;
	push(topo, "a");
	push(topo, "b");
	push(topo, "c");
	push(topo, "d");
	cout << "Original:        ";
	print(topo);
	deletarElementoDoMeio(topo);
	cout << "Sem o do meio:   ";
	print(topo);

	cout << "Invertida:       " << inverterString("pilha") << endl;

	pilha* p2 = NULL;
	push(p2, "a");
	push(p2, "b");
	push(p2, "a");
	push(p2, "c");
	push(p2, "b");
	cout << "Com duplicados:  ";
	print(p2);
	removerDuplicados(p2);
	cout << "Sem duplicados:  ";
	print(p2);

	cout << "arara: " << (ehPalindromo("arara") ? "palindromo" : "nao e palindromo") << endl;
	cout << "pilha: " << (ehPalindromo("pilha") ? "palindromo" : "nao e palindromo") << endl;
}