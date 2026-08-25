#include <iostream>
using namespace std;

int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
int tamanhoDoVetor = 10;
int contador = 0;

void ordenarLista(int vetor[]){
	while(contador < tamanhoDoVetor){
		for(int i = 0; i < (tamanhoDoVetor - 1); i++){
			int numeroAtual = vetor[i];
			contador++;
			if(numeroAtual < vetor[i + 1]){
				contador = 0;
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = numeroAtual;
			}
		}
	}
}

int main(){
	ordenarLista(vetor);
	for(int i = 0; i < tamanhoDoVetor; i++){
		cout << vetor[i];
	}
}