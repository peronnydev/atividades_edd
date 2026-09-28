#include <iostream>
#include <vector>
using namespace std;

vector<int> numerosEmComum = {};
vector<int> vetor1 = {1,2,3,4,5,6,7,8,9,10};
vector<int> vetor2 = {5,5,6,6,7,8,9,10,11,12,13,14,15};

void adicaoUnica(int numero){
	if(numerosEmComum.empty()){
		numerosEmComum.push_back(numero);
		return;
	}
	for(int i = 0; i < numerosEmComum.size(); i++){
		if(numerosEmComum[i] == numero){
			return; 
		}
	}
	numerosEmComum.push_back(numero);
	return;
}

void compararVetores(vector<int> vetor1, vector<int> vetor2){
	for(int i = 0; i < vetor1.size(); i++){
		for(int x = 0; x < vetor2.size(); x++){
			if(vetor1[i] == vetor2[x]){
				adicaoUnica(vetor2[x]);
				break;
			}
		}
	}
	return;
}

int main(){
	compararVetores(vetor1, vetor2);
	for(int i = 0; i < numerosEmComum.size(); i++){
		cout << numerosEmComum[i] << endl;
	}
}