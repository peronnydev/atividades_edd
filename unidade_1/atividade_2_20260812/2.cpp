#include <iostream>
#include <vector>
using namespace std;
int main(){
	int soma = 0;
	int subtracao = 0;
	int multiplicacao = 1;
	int numeros[5] = {10,20,30,40,50};
	for(int i = 0; i < 5; i++){
		soma =+ numeros[i];
		subtracao =-  numeros[i];
		multiplicacao = multiplicacao * numeros[i];
	}
	cout << "Soma = " << soma << endl;
	cout << "Subtracao = " << subtracao << endl;
	cout << "Multiplicacao = " << multiplicacao << endl;
	return 0;
}