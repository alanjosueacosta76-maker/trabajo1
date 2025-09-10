#include <iostream>
using namespace std;

int main() {
    int arreglo[] = {5, 8, 3, 10, 7, 2, 15, 9};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
    int elemento;
    bool encontrado = false;

    cout << "Ingrese el número a buscar: ";
    cin >> elemento;

    // Búsqueda lineal
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == elemento) {
            cout << "Elemento " << elemento << " encontrado en la posición " << i << "." << endl;
            encontrado = true;
            break; // Detener búsqueda al encontrar el elemento
        }
    }

    if (!encontrado) {
        cout << "Elemento " << elemento << " no encontrado en el arreglo." << endl;
    }

    return 0;
}


