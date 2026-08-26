#include <iostream>
using namespace std;

/*string vetorAlfabetico[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};*/
int vetorNumerico[10] = {9,8,7,6,5,4,3,2,1,0};
int TAMANHO_DO_VETOR = 10;

void selection_sort(int vetor[], int n){
	for(int i = 0; i < n; i++){
		int menorIndex = i;
		
		for(int j = i; j < n; j++){
			if(vetor[menorIndex] > vetor[j]){
				menorIndex = j;
			}
		}
		
		if(vetor[i] > vetor[menorIndex]){
			int temp = vetor[i];
			vetor[i] = vetor[menorIndex];
			vetor[menorIndex] = temp;
		}
	}
}

void print_vetor(int vetor[], int n){
	cout << "------------------" << endl;
	for(int i = 0; i < n; i++){
		cout << vetor[i] << ", ";
	}
	cout << endl;
}

int main(){
	print_vetor(vetorNumerico, TAMANHO_DO_VETOR);
	selection_sort(vetorNumerico, TAMANHO_DO_VETOR);
	print_vetor(vetorNumerico, TAMANHO_DO_VETOR);
}