#include <iostream>
#include <string>
using namespace std;

void selection_sort(string vetorPalavras[], int tamanhoVetor){
	for(int i = 0; i < tamanhoVetor; i++){
		string menorPalavra = vetorPalavras[i];
		int posicaoMenorPalavra = i;
		for(int x = i; x < tamanhoVetor; x++){
			if(menorPalavra > vetorPalavras[x]){
				menorPalavra = vetorPalavras[x];
				posicaoMenorPalavra = x;
			}
		}
		string temp = vetorPalavras[i];
		vetorPalavras[i] = menorPalavra;
		vetorPalavras[posicaoMenorPalavra] = temp;
	}
}

void print_vetor(string palavras[], int tamanho){
	cout << endl << "------------------------";
	for(int i = 0; i < tamanho; i++){
		cout << endl << "vetorPalavras[" << i << "] == " << palavras[i];
	}
}

int main(){
	string vetorPalavras[10] = {"Igor", "Helena", "Fernanda", "Eduardo", "Diana", "Carlos", "Bruna", "Alberto", "Zaira", "Ana"};
	int tamanhoVetor = 10;

	print_vetor(vetorPalavras, tamanhoVetor);
	selection_sort(vetorPalavras, tamanhoVetor);
	print_vetor(vetorPalavras, tamanhoVetor);

	return 0;
}
