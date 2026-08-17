#include <iostream>
using namespace std;

void tabuada(int num){
	for(int i = 1; i <= 10; i++){
		cout << num << " - " << i << " = " << num - i << endl;
		cout << num << " + " << i << " = " << num + i << endl;
		cout << num << " * " << i << " = " << num * i << endl;
		cout << num << " / " << i << " = " << num / i << endl;
	};
}

int main(){
	int numero = 10;
	tabuada(numero);
}