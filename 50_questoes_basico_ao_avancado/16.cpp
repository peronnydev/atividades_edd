#include <iostream>
using namespace std;
int main(){
	double peso;
	double altura;
	double imc;
	cout << "Digite seu peso: " << endl;
	cin >> peso;
	cout << "Digite sua altura: " << endl;
	cin >> altura;
	imc = peso / (altura * altura);
	cout << "IMC = " << imc << endl;
	if(imc >= 40){
		cout << "Obesidade grau 3" << endl;
	} else if(imc >= 35){
		cout << "Obesidade grau 2" << endl;
	} else if(imc >= 30){
		cout << "Obesidade grau 1" << endl;
	} else if(imc >= 25){
		cout << "Sobrepeso" << endl;
	} else if(imc >= 18.5){
		cout << "Peso normal" << endl;
	} else{
		cout << "Abaixo do peso" << endl;
	}
	return 0;
}