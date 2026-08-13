#include <iostream>
using namespace std;

int main(){
	int idade;
	cout << "Digite sua idade: " << endl;
	cin >> idade;
	if(idade <= 12){
		cout << "Criança" << endl;
	} else if(idade <= 17){
		cout << "Adolescente" << endl;
	} else if(idade <= 59){
		cout << "Adulto" << endl;
	} else{
		cout << "Idoso" << endl;
	}	
	return 0;
}