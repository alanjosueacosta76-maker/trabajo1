#include <iostream>
#include <vector>
#include <cstdlib>  // se usa para rand() y srand()
#include <ctime>    // se usa para time()

using namespace std;

// Función para intercambiar elementos
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partición (utiliza el último elemento como pivote)
int particion(vector<int> &arr, int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[fin]);
    return i + 1;
}


void quickSort(vector<int> &arr, int inicio, int fin) {
    if (inicio < fin) {
        int indicePivote = particion(arr, inicio, fin);
        quickSort(arr, inicio, indicePivote - 1);
        quickSort(arr, indicePivote + 1, fin);
    }
}

// Función para imprimir un vector
void imprimirVector(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Función principal
int main() {
    srand(time(0)); // Inicializar semilla aleatoria

    const int tamaño = 10;
    vector<int> lista;

    // Llenar la lista con números aleatorios entre 1 y 100
    for (int i = 0; i < tamaño; i++) {
        lista.push_back(rand() % 100 + 1);
    }

    cout << "Lista desordenada:\n";
    imprimirVector(lista);

    quickSort(lista, 0, lista.size() - 1);

    cout << "\nLista ordenada:\n";
    imprimirVector(lista);

    return 0;
}

