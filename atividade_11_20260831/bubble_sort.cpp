#include <iostream>
#include <string>
using namespace std;

void bubble_sort(string vetorPalavras[], int tamanho){
	bool ordenado = false;
	while(!ordenado){
		ordenado = true;
		for(int i = 0; i < tamanho -1; i++){
		if(vetorPalavras[i] > vetorPalavras[i + 1]){
			ordenado = false;
			string temp = vetorPalavras[i];
			vetorPalavras[i] = vetorPalavras[i + 1];
			vetorPalavras[i + 1] = temp;
			}
		}
	}
}

void print_vetor(string palavras[], int tamanho){
	cout << endl << "------------------------";
	for(int i = 0; i < tamanho; i++){
		cout << endl << "vetorPalavras[" << i << "] == " << palavras[i];
	}
}

int main(){
	string vetorPalavras[10] = {"Maria", "Bruna", "Alberto", "Joao", "Carlos", "Fernanda", "Eduardo", "Diana", "Igor", "Helena"};
	int tamanho = 10;
	print_vetor(vetorPalavras, tamanho);
	bubble_sort(vetorPalavras, tamanho);
	print_vetor(vetorPalavras, tamanho);
}
