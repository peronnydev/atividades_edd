#include <iostream>
using namespace std;
int main(){
	int nota1;
	int nota2;
	int nota3;
	int media;
	cout << "Nota 1: " << endl;
	cin >> nota1;
	cout << "Nota 2: " << endl;
	cin >> nota2;
	cout << "Nota 3: " << endl;
	cin >> nota3;
	media = (nota1 + nota2 + nota3) / 3;
	if(media >= 7){
		cout << "Aprovado" << endl;
	} else if(media >= 5){
		cout << "Recuperacao" << endl;
	} else{
		cout << "Reprovado" << endl;
	}
}