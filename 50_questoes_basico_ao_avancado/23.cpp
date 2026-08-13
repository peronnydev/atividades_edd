#include <iostream>
using namespace std;

int main(){
	int numero;
	cout << "Digite um numero: " << endl;
	cin >> numero;
	for(int i = 1; i <= 10; i++){
		cout << numero << " * " <<  i << " = " << numero * i << endl;
	}
}