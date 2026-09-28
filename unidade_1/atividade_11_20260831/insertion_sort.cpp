#include <iostream>
#include <string>
using namespace std;

void insertion_sort(string vetorPalavras[], int tamanho){
	for(int i = 1; i < tamanho; i++){
		string chave = vetorPalavras[i];
		int j = i - 1;

		while(j >= 0 && vetorPalavras[j] > chave){
			vetorPalavras[j + 1] = vetorPalavras[j];
			j--;
		}
		vetorPalavras[j + 1] = chave;
	}
}

void print_vetor(string vetorPalavras[], int tamanho){
	cout << "----------------------" << endl;
	for(int i = 0; i < tamanho; i++){
		cout << "vetorPalavras[" << i << "] = " << vetorPalavras[i] << endl;
	}
}

int main(){
	string vetorPalavras[10] = {"Igor", "Helena", "Fernanda", "Eduardo", "Diana", "Carlos", "Bruna", "Alberto", "Zaira", "Ana"};
	int tamanho = 10;
	print_vetor(vetorPalavras, tamanho);
	insertion_sort(vetorPalavras, tamanho);
	print_vetor(vetorPalavras, tamanho);
	return 0;
}
