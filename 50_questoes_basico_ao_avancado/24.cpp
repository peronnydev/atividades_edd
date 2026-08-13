#include <iostream>
using namespace std;
int main(){
	int numero = 100;
	int controle;
	
	if(numero == 0){
		cout << "O numero deve ser diferente de 0" << endl;
	} else if(numero > 0){
		for(int i = 0; i < numero; i++){
			controle += i;
		}	
	} else if(numero < 0){
		for(int i = 0; i > numero; i--){
			controle += i;
		}
	}
	
	cout << controle << endl;
	return 0;
}