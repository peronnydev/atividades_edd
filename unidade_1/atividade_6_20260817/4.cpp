#include <iostream>
#include <vector>
using namespace std;

vector<int> exclusivo = {};

void adicaoUnica(int numero){
	for(int i = 0; i < exclusivo.size(); i++){
		if(numero == exclusivo[i]){
			return;
		}
	}
	exclusivo.push_back(numero);
	return;
}

void compararVetores(vector<int> vetor1, vector<int> vetor2){
	bool isIgual;
	for(int x = 0; x < vetor1.size(); x++){
		isIgual = false;
		for(int y = 0; y < vetor2.size(); y++){
			if(vetor1[x] == vetor2[y]){
				isIgual = true;	
			}
		}
		if(!isIgual){
			adicaoUnica(vetor1[x]);
			isIgual = false;
		}
	}
	return;
}

int main(){
	vector<int> vetor1 = {1,2,3,4,5,6,7,8,9,10,11};
	vector<int> vetor2 = {1,2,3,4,5,6,7,8,9,10,12};
	compararVetores(vetor1, vetor2);
	compararVetores(vetor2, vetor1);
	for(int i = 0; i < exclusivo.size(); i++){
		cout << exclusivo[i] << endl;
	}
	return 0;
}

