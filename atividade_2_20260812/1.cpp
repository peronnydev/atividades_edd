#include<iostream>
#include<vector>
using namespace std;
int main(){
	int numeros[15] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
	for(int i = 14; i >= 0; i--){
		cout << numeros[i] << endl;
	}
	return 0;
}