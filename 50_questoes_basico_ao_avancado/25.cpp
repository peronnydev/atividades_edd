#include <iostream>
using namespace std;
int main(){
	int numero;
	cout << "Digite um numero: " << endl;
	cin >> numero;
	cout << "Fatorial de " << numero << " = ";
	for(int i = numero - 1; i > 0; i--){
		numero *= i;
	}
	cout << numero << endl;
	return 0;
}