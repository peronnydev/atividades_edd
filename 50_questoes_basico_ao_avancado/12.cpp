#include <iostream>
using namespace std;
int main (){
	double numero;
	cout << "Digite um numero: " << endl;
	cin >> numero;
	if(numero < 0){
		cout << "Numero negativo" << endl;
	}
	else if(numero == 0){
		cout << "Numero 0" << endl;
	}
	else{
		cout << "Numero positivo" << endl;
	}
}