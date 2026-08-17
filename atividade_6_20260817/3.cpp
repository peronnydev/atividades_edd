#include <iostream>
#include <vector>
using namespace std;

int contador = 0;

void verificarOcorrencias(vector<int> vetor, int alvo){
	for(int i = 0; i < vetor.size(); i++){
		if(alvo == vetor[i]){
			contador++;
		}
	}
	return;
}

int main(){
	vector<int> vetor = {1,2,5,3,4,5,6,7,8,5,9,10};
	int alvo = 5;
	verificarOcorrencias(vetor, alvo);
	cout << "Numero de ocorrencias = " << contador << endl;
	return 0;
}