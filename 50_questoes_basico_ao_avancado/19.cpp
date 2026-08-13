#include <iostream>
using namespace std;
int main(){
	char operador;
	double numero1;
	double numero2;
	cout << "Digite o primeiro numero: " << endl;
	cin >> numero1;
	cout << "Digite o segundo numero: " << endl;
	cin >> numero2;
	cout << "Digite um operador (+ | - | * | /): " << endl;
	cin >> operador;
	switch(operador){
		case '+':
			cout << "Operacao de soma: " << numero1 << " + " << numero2 << " = " << numero1 + numero2;
			break;
		case '-':
			cout << "Operacao de subtracao: " << numero1 << " - " << numero2 << " = " << numero1 - numero2;
			break;
		case '*':
			cout << "Operacao de multiplicacao: " << numero1 << " * " << numero2 << " = " << numero1 * numero2;
			break;
		case '/':
			cout << "Operacao de divisao: " << numero1 << " / " << numero2 << " = " << numero1 / numero2;
			break;
		default:
			cout << "Operacao invalida" << endl;
			break;
	}
	return 0;
}