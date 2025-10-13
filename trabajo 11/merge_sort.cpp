#include <iostream>
using namespace std;

// Función para mezclar dos subarreglos
void merge(int a[], int l, int m, int r) {
    int a1 = m - l + 1;
    int a2 = r - m;

    // Crear arreglos temporales
    int* L = new int[a1];
    int* R = new int[a2];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < a1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < a2; j++)
        R[j] = a[m + 1 + j];

    // Índices para recorrer los subarreglos
    int i = 0, j = 0, k = l;

    // Mezclar los arreglos temporales de vuelta en a[l..r]
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay
    while (i < a1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay
    while (j < a2) {
        a[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria de arreglos temporales
    delete[] L;
    delete[] R;
}

// Función principal de MergeSort
void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Programa principal
int main() {
    int a[] = {10, 28, 54, 11};
    int s = sizeof(a) / sizeof(a[0]);

    cout << "Arreglo desordenado:\n";
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";

    mergesort(a, 0, s - 1);

    cout << "\nArreglo ordenado:\n";
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}
