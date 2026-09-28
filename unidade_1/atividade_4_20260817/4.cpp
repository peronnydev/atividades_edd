#include <iostream>
using namespace std;

int maiorNumero(int numeros[]){
	int maior = numeros[0];
	for(int i = 0; i <= 9; i++){
		if(numeros[i] > maior){
			maior = numeros[i];
		}
	}
	return maior;
}

int main(){
	int numeros[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << maiorNumero(numeros) << endl;
}