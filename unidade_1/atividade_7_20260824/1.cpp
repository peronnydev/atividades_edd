#include <iostream>
using namespace std;

int TAMANHO_DO_VETOR = 11;
int VETOR[11] = {1,2,3,4,5,6,7,8,9,10,11};

int buscaBinaria(int alvo){
	if(alvo >= VETOR[TAMANHO_DO_VETOR/2]){
		for(int i = (TAMANHO_DO_VETOR/2); i < TAMANHO_DO_VETOR; i++){
			if(alvo == VETOR[i]){
				return i;
			}
		}
	}
	for(int i = 0; i < (TAMANHO_DO_VETOR/2); i++){
		if(alvo == VETOR[i]){
			return i;
		}
	}
}

int main(){
	int alvo = 4;
	cout << buscaBinaria(4) << endl;
}