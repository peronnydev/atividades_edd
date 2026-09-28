#include <iostream>
using namespace std;

bool verificarPar(int num){
	if(num % 2 == 1){
		return false;
	} return true;
}

int main(){
	int num = 100;
	if(verificarPar(num)){
		cout << "Numero par";
	} else{
		cout << "Numero impar";
	}
}