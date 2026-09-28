#include <iostream>
using namespace std;

int main(){
	int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int soma = 0;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			soma = soma + matriz[x][y];
		}
	}
	cout << "Total da soma da matriz : " << soma << endl;
	return 0;
}