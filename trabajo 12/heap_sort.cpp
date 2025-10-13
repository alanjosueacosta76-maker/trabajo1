#include <iostream>
using namespace std;

// Función para ajustar el subárbol en forma de Max Heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Inicializar el más grande como raíz
    int left = 2 * i + 1;  // Hijo izquierdo
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo es mayor que la raíz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el mayor no es la raíz
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursivamente hacer heapify al subárbol afectado
        heapify(arr, n, largest);
    }
}

// Función principal para ordenar con Heap Sort
void heapSort(int arr[], int n) {
    // Construir Max Heap (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual al final
        swap(arr[0], arr[i]);

        // Llamar heapify en el heap reducido
        heapify(arr, i, 0);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int arr[] = {10, 20, 25, 5, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo desordenado: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    return 0;
}
