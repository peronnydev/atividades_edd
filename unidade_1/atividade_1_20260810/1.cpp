#include <iostream>
using namespace std;
int main(){
	int anoNascimento;
	int anoAtual;
	cout << "Digite sua data de nascimento: " << endl;
	cin >> anoNascimento;
	cout << "Digite o ano atual: " << endl;
	cin >> anoAtual;
	int idade = anoAtual - anoNascimento;
	if(idade < 18){
		cout << "Voce e menor de idade";
	}
	else{
		cout << "Voce e maior de idade";
	}
	cout << "Idade: " << idade << endl;
	
	return 0;
}