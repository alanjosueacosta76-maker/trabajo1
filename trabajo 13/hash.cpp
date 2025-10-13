#include <iostream>
using namespace std;

class ShellSort {
public:
    // Muestra los elementos del arreglo en una sola línea
    static void displayArr(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Ordena un arreglo usando el algoritmo Shell Sort
    void sort(int arr[], int size) {
        int gapSize = size / 2; // Se empieza con un "salto" grande

        // Mientras el salto sea mayor que cero, seguimos ordenando
        while (gapSize > 0) {
            // Recorremos los elementos desde 'gapSize' hasta el final
            for (int j = gapSize; j < size; j++) {
                int val = arr[j]; // Elemento actual a comparar
                int k = j;

                // Compara y mueve los elementos que estén fuera de orden
                while (k >= gapSize && arr[k - gapSize] > val) {
                    arr[k] = arr[k - gapSize];
                    k = k - gapSize;
                }

                // Inserta el elemento en su posición correcta
                arr[k] = val;
            }

            // Reduce el salto a la mitad en cada iteración
            gapSize = gapSize / 2;
        }
    }
};

int main() {
    int inputArr[] = {36, 38, 44, 11, 19, 30, 28, 50};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);

    cout << "Arreglo desordenado:" << endl;
    ShellSort::displayArr(inputArr, size);

    ShellSort obj;
    obj.sort(inputArr, size);

    cout << "Arreglo ordenado:" << endl;
    ShellSort::displayArr(inputArr, size);

    return 0;
}
