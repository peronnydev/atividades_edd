#include <iostream>
using namespace std;
int main(){
	double altura;
	double base;
	cout << "Digite a altura do retangulo: " << endl;
	cin >> altura;
	cout << "Digite a base do retangulo: " << endl;
	cin >> base;
	cout << "Altura do retangulo = " << base * altura << endl;
	cout << "Perimetro do retangulo = " << (base * 2) + (altura * 2) << endl;
	return 0;
}