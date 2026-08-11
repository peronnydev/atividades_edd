#include <iostream>
using namespace std;
int main(){
	int numero;
	int menor;
	cout << "Digite um numero inteiro (geracao 1)!" << endl;
	cin >> numero;
	menor = numero;
	for(int i = 2; i < 8; i++){
		cout << "Digite um numero inteiro (geracao " << i << ")!" << endl;
		cin >> numero;
		if(numero < menor){
			menor = numero;
		}
	}
	cout << "Menor: " << menor << endl;
}