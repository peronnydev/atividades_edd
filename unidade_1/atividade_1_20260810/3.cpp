#include <iostream>
using namespace std;
int main(){
	int geracao = 0;
	int pares = 0;
	int impares = 0;
	int soma = 0;
	int numero;
	while(geracao < 5){
		geracao = geracao + 1;
		cout << "Digite o " << geracao << "* numero" << endl;
		cin >> numero;
		soma = soma + numero;
		if((numero % 2) == 1){
			impares++;
		}
		else{
			pares = pares + 1;
		}
	}
	cout << "Numeros pares: " << pares << endl;
	cout << "Numeros impares: " << impares << endl;
	cout << "Soma dos numeros: " << soma;
}