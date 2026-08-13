#include <iostream>
using namespace std;
int main(){
	double nota1;
	double nota2;
	double nota3;
	cout << "Digite a nota 1: " << endl;
	cin >> nota1;
	cout << "Digite a nota 2: " << endl;
	cin >> nota2;
	cout << "Digite a nota 3: " << endl;
	cin >> nota3;
	cout << "Media das notas: " << (nota1 + nota2 + nota3) / 3;
	return 0;
}