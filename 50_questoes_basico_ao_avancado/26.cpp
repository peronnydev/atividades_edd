#include <iostream>
#include <vector>
using namespace std;
int fibonacci[15] = {0,1};

int main(){
	for(int i = 2; i < 15 +1; i++){
		fibonacci[i] = fibonacci[i -1] + fibonacci[i -2];
	}
	for(int i = 0; i < 15 +1; i++){
		cout << fibonacci[i] << endl;
	}
	return 0;
}