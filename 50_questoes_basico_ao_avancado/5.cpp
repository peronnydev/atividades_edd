#include <iostream>
using namespace std;
int main(){
	double temperaturaCelsius;
	double temperaturaFahrenheit;
	cout << "Digite a temperatura em Celsius: " << endl;
	cin >> temperaturaCelsius;
	cout << "Temperatura em Fahrenheit = " << (temperaturaCelsius * 9/5) + 32 << endl;
	return 0;
}