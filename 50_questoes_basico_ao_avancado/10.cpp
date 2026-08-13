#include <iostream>
using namespace std;
int main(){
	
	int anos;
	int meses;
	int semanas;
	int dias;
	int horas;
	int minutos;
	double segundos;

	cout << "Digite um valor em segundos: " << endl;
	cin >> segundos;
	
	anos = segundos / 31536000;
	segundos = segundos - (anos * 31536000);
	
	meses = segundos / 2628000;
	segundos = segundos - (meses * 2628000);
	
	semanas = segundos / 604800;
	segundos = segundos - (semanas * 604800);
	
	dias = segundos / 86400;
	segundos = segundos - (dias * 86400);
	
	horas = segundos / 3600;
	segundos = segundos - (horas * 3600);
	
	minutos = segundos / 60;
	segundos = segundos - (minutos * 60);
	
	cout << "Anos: " << anos << endl;
	cout << "Meses: " << meses << endl;
	cout << "Semanas: " << semanas << endl;
	cout << "Dias: " << dias << endl;
	cout << "Horas: " << horas << endl;
	cout << "Minutos: " << minutos << endl;
	cout << "Segundos: " << segundos << endl; 	
	
	return 0;
}