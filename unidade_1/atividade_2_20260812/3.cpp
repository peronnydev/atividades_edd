#include <iostream>
#include <vector>
using namespace std;
int main(){
	int consoantes;
	char caracteres[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	for(int i = 0; i < 10; i++){
		if(
		caracteres[i] == 'a' ||
		caracteres[i] == 'e' ||
		caracteres[i] == 'i' ||
		caracteres[i] == 'o' ||
		caracteres[i] == 'u'
		){
			consoantes++;
		}
	}
	cout << "Numero de consoantes = " << consoantes << endl;
	return 0;
}