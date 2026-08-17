#include <iostream>
using namespace std;

double calcularMedia(double nota1, double nota2, double nota3){
	return (nota1 + nota2 + nota3) / 3;
}

int main(){
	int nota1 = 8;
	int nota2 = 9;
	int nota3 = 10;
	double media = calcularMedia(nota1, nota2, nota3);
	if(media >= 7){
		cout << "Aprovado" << endl;
	} else if(media >= 4){
		cout << "Recuperacao" << endl;
	} else{
		cout << "Reprovado";
	}
}