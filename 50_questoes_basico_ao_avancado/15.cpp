#include <iostream>
using namespace std;

int main(){
	int ano;
	cout << "Digite um ano: " << endl;
	cin >> ano;
	if((ano % 400) == 0){
		cout << "Ano bisexto" << endl;
	} else if((ano % 100) == 0){
		cout << "Ano normal" << endl;
	} else{
		cout << "Ano normal" << endl;
	}
}