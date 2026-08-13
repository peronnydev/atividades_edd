#include <iostream>
using namespace std;

const double pi = 3.14159;

double calculadorArea(int raioDoCirculo){
	return pi *  (raioDoCirculo * raioDoCirculo);
}

double calculadorPerimetro(int raioDoCirculo){
	return (pi * 2) * raioDoCirculo;
}

int main() {
	int raioDoCirculo;
	cout << "Digite o raio da circunferencia: " << endl;
	cin >> raioDoCirculo;
	cout << "Perimetro = " << calculadorPerimetro(raioDoCirculo) << endl;
	cout << "Area = " << calculadorArea(raioDoCirculo) << endl;
	return 0;
}