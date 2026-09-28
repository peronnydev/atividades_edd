#include <iostream>
using namespace std;

void selectionSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menorIndice = i; 

        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[menorIndice]) {
                menorIndice = j;
            }
        }

        if (menorIndice != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = temp;
        }
    }
}

void imprimirVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main() {
    int vetor[9] = {9, 5, 1, 4, 3, 8, 2, 7, 6};
    int n = 9;

    cout << "Vetor original: ";
    imprimirVetor(vetor, n);

    selectionSort(vetor, n);

    cout << "Vetor ordenado: ";
    imprimirVetor(vetor, n);

    return 0;
}