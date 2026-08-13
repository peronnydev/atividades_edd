#include <iostream>
using namespace std;
int main(){
	double preco;
	double desconto;
	cout << "Digite o preco do produto: " << endl;
	cin >> preco;
	cout << "Digite o valor do desconto (0% a 100%)" << endl;
	cin >> desconto;
	desconto = (desconto/100) * preco;
	preco = preco - desconto;
	cout << "Preco com desconto aplicado = " << preco << endl;
	return 0;
}