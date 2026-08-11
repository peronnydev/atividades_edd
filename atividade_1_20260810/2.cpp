#include <iostream>
using namespace std;
int main(){
	double nota1;
	double nota2;
	double nota3;
	cout << "Digite sua nota 1" << endl;
	cin >> nota1;
	cout << "Digite sua nota 2" << endl;
	cin >> nota2;
	cout << "Digite dua nota 3" << endl;
	cin >> nota3;
	double media = (nota1 + nota2 + nota3) / 3;
	cout << "Media: " << media << endl;
	if(media >= 7){
		cout << "Aprovado!";
	}
	else if(media >= 5){
		cout << "Recuperacao!";
	}
	else{
		cout << "Reprovado!";
	}
}