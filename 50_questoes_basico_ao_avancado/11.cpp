#include <iostream>
using namespace std;
int main(){
	int numero;
	cout << "Digite um numero: " << endl;
	cin >> numero;
	if(numero % 2 == 1){
		cout << "Numero impar" << endl;
	}
	else{
		cout << "Numero par" << endl;
	}
	return 0;
}