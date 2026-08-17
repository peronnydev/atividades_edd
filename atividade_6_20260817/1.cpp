#include <iostream>
using namespace std;

int pesquisarNumero(int numero, int numeros[]){
	for(int i = 0; i < 10; i++){
		if(numero == numeros[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	int numeroPesquisa = 6;
	int vetorDeNumeros[10] = {1,2,3,4,5,6,7,8,9,10};
	int resultadoPesquisa = pesquisarNumero(numeroPesquisa, vetorDeNumeros);
	if(resultadoPesquisa == -1){
		cout << "Numero pesquisado nao encontrado" << endl;
	} else{
		cout << "Posicao do numero procurado = " << resultadoPesquisa << endl;	
	}
	return 1;
}