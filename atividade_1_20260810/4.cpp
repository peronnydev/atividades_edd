#include <iostream>
using namespace std;
int main() {
	int numero;
	cout << "Digite um numero para mostrar a tabuada dele!" << endl;
	cin >> numero;
	for (int i = 1; i <= 10; i++){
		cout << "Operacao " << i << " * " << numero << " = " << i * numero << endl;
	}
	return 0;
}