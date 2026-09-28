#include <iostream>
using namespace std;

void insertionSort(string vetor[], int n) {
	for(int i = 0; i < n; i++){
		int menorIndex = i;
		
		for(int j = i; j < n; j++){
			if(vetor[j] < vetor[menorIndex]){
				menorIndex = j;		
			}
		}
		
		if(menorIndex != i){
			string temp = vetor[menorIndex];
			vetor[menorIndex] = vetor[i];
			vetor[i] = temp;
		}
	}
}

void imprimirVetor(string vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << ", ";
    }
    cout << endl;
}

int main() {
    string vetor[4] = {"Maria", "Bruna", "Alberto", "Joao"};
    int n = 4;

    cout << "Vetor original: ";
    imprimirVetor(vetor, n);

    insertionSort(vetor, n);

    cout << "Vetor ordenado: ";
    imprimirVetor(vetor, n);

    return 0;
}