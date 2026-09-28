#include <iostream>
using namespace std;

int const CADEIRAS_FILEIRA = 10;
int const TOTAL_CADEIRAS = 100;
int const PRECO_EM_CENTAVOS = 1550;

void pressioneContinuar(){
	/* Usei função pronta, mas isso interfere apenas na estética */
    cout << "\nPressione alguma tecla para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    cout << "\033[2J\033[1;1H";
}

void povoarVetor(int salaCinema[]){
	for(int i = 0; i < TOTAL_CADEIRAS; i++){
		salaCinema[i] = i+1; 
	}
}

void selectionSort(int vetor[]){
	for(int i = 0; i < TOTAL_CADEIRAS; i++){
		int menorIndex = i;
		for(int j = i; j < TOTAL_CADEIRAS; j++){
			if(vetor[j] < vetor[menorIndex]){
				menorIndex = j;
			}
		}
		if(menorIndex != i){
			int temp = vetor[menorIndex];
			vetor[menorIndex] = vetor[i];
			vetor[i] = temp;
		}
	}
}

int buscaSequencial(int vetor[], int alvo){
	for(int i = 0; i < TOTAL_CADEIRAS; i++){
		if(vetor[i] == alvo){
			return i;
		}
	}
	return -1;
}

void printMapaCinema(int vetor[]){
	int index = 0;
	cout << "--- Mapa do cinema" << endl;
	for(int i = 0; i < CADEIRAS_FILEIRA; i++){
		for(int j = 0; j < CADEIRAS_FILEIRA; j++){
			if(vetor[index] == 0){
				cout << "[ X ] ";
			} else if(vetor[index] < 10){
				cout << "[ " << vetor[index] << " ] ";
			} else if(vetor[index] < 100){
				cout << "[ " << vetor[index] << "] ";
			} else{
				cout << "[" << vetor[index] << "] ";
			}
			index++;
		}
		cout << endl;
	}
}

int venderCadeira(int salaCinema[], int cadeirasVendidas[], int cadeiraVendida, int &totalVendidoCentavos){
	int indexCadeiraVendida = buscaSequencial(salaCinema, cadeiraVendida);
	if(indexCadeiraVendida == -1){
		return -1;
	}
	salaCinema[indexCadeiraVendida] = 0;
	int indexEmBranco = buscaSequencial(cadeirasVendidas, 0);
	cadeirasVendidas[indexEmBranco] = indexCadeiraVendida + 1;
	selectionSort(cadeirasVendidas);
	totalVendidoCentavos += PRECO_EM_CENTAVOS;
	return 1;
}

void venderCadeiraView(int salaCinema[], int cadeirasVendidas[], int &totalVendidoCentavos){
	int cadeiraVendida = 0;
	cout << "--- Painel de vender cadeira" << endl;
	printMapaCinema(salaCinema);
	cout << "- Numero da cadeira vendida: ";
	cin >> cadeiraVendida;
	cout << endl;
	int log = venderCadeira(salaCinema, cadeirasVendidas, cadeiraVendida, totalVendidoCentavos);
	if(log == -1){
		cout << "[Erro] Numero invalido" << endl;
		return;
	}
	cout << "[OK] Cadeira vendida: " << cadeiraVendida << endl;
}

void informacoesVendaView(int cadeirasVendidas[], int totalVendidoCentavos){
	cout << "--- Informacoes de vendas" << endl;
	cout << "Cadeiras vendidas: ";
	for(int i = 0; i < TOTAL_CADEIRAS; i++){
		if(cadeirasVendidas[i] != 0){
			cout << cadeirasVendidas[i] << ", ";
		}
	}
	double totalVendidoReais = double(totalVendidoCentavos) / 100;
	cout << endl << "Total vendido em reais = " << totalVendidoReais << endl;
}

int main(){
	int salaCinema[100] = {0};
	int cadeirasVendidas[100] = {0};
	int totalVendidoCentavos = 0;
	int ativo = true;
	povoarVetor(salaCinema);
	selectionSort(salaCinema);
	while(ativo){
		cout << "\033[2J\033[1;1H";
		cout << "--- Bem vindo ao CineLand" << endl;
		cout << "- 1 - Ver mapa do cinema" << endl;
		cout << "- 2 - Vender cadeira" << endl;
		cout << "- 3 - Ver informacoes de venda" << endl;
		cout << "- 4 - Encerrar sistema" << endl;
		cout << "- Opcao desejada: ";
		int opcao;
		cin >> opcao;
		cout << endl;
		cout << "\033[2J\033[1;1H";
		switch(opcao){
			case 1:
				printMapaCinema(salaCinema);
				pressioneContinuar();
				break;
			case 2:
				venderCadeiraView(salaCinema, cadeirasVendidas, totalVendidoCentavos);
				pressioneContinuar();
				break;
			case 3:
				informacoesVendaView(cadeirasVendidas, totalVendidoCentavos);
				pressioneContinuar();
				break;
			case 4:
				informacoesVendaView(cadeirasVendidas, totalVendidoCentavos);
				cout << "--- Obrigado por usar o systemCineLand" << endl;
				ativo = false;
				break;
			default:
				cout << "[Erro] Opcao invalida" << endl;
				pressioneContinuar();
				break;
		}
	}
}