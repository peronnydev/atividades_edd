#include <iostream>
using namespace std;
int main(){
	int numero1;
	int numero2;
	int numero3;
	int menor;
	cout << "Digite o primeiro numero: " << endl;
	cin >> numero1;
	menor = numero1;
	cout << "Digite o segundo numero: " << endl;
	cin >> numero2;
	if(numero2 < menor){
		menor = numero2;
	}
	cout << "Digite o terceiro numero: " << endl;
	cin >> numero3;
	if(numero3 < menor){
		menor = numero3;
	}
	cout << "Menor numero = " << menor << endl;
	return 0;
}