#include <iostream>
using namespace std;
int main(){
	int matriz[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
	cout << "Matriz organizada: " << endl;
	for(int x = 0; x < 3; x++){
		cout << matriz[x][0] << matriz[x][1] << matriz[x][2]  << endl;
	};
	return 0;
}