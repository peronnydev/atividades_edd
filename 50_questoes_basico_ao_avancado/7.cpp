#include <iostream>
using namespace std;
int main(){
	string A;
	string B;
	cout << "Digite o valor para a variavel A: " << endl;
	cin >> A;
	cout << "Digite o valor para a variavel B: " << endl;
	cin >> B;
	cout << "Antes da troca: " << endl << "Variavel A = " << A << endl << "Variavel B = " << B << endl;
	swap(A, B);
	cout << "Depois da troca: " << endl << "Variavel A = " << A << endl << "Variavel B = " << B << endl;
	return 0;
}