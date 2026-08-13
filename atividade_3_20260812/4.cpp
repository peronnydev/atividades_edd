#include <iostream>
using namespace std;

int main(){
	int matriz[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	int maiorNumero = matriz[0][0];
	int posicaoX;
	int posicaoY;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 4; y++){
			if(matriz[x][y] > maiorNumero){
				maiorNumero = matriz[x][y];
				posicaoX = x;
				posicaoY = y;
			}
		}
	}
	cout << "Maior numero da matriz : " << matriz[posicaoX][posicaoY] << endl;
	cout << "Posicao do maior numero [" << posicaoX << "][" << posicaoY << "]" << endl;
	return 0;
}