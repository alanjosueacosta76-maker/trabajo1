#include <iostream>
using namespace std;

void burbuja(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int lista[] = {5, 3, 8, 4, 2};
    int n = sizeof(lista) / sizeof(lista[0]);

    cout << "Lista desordenada: ";
    imprimirArreglo(lista, n);

    burbuja(lista, n);

    cout << "Lista ordenada: ";
    imprimirArreglo(lista, n);

    return 0;
}
