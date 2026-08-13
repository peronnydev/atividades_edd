#include <iostream>
#include <set>
using namespace std;

int main(){
	double lado1;
	double lado2;
	double lado3;
	
	cout << "Digite os lados de um triangulo: " << endl;
	cin >> lado1 >> lado2 >> lado3;
	
	set<double> lados = {lado1, lado2, lado3};
	
	if(lados.size() == 1){
		cout << "Equilatero" << endl;
	} else if(lados.size() == 2){
		cout << "Isosceles" << endl;
	} else{
		cout << "Escaleno" << endl;
	}
	
	return 0;
}