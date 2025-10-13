#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort
using namespace std;

// Función que ordena una cubeta usando el método de inserción
void ordenamiento_insercion(vector<float>& cubeta) {
    for (int j = 1; j < cubeta.size(); j++) {
        float valor = cubeta[j];
        int k = j - 1;

        // Mueve los elementos mayores una posición a la derecha
        while (k >= 0 && cubeta[k] > valor) {
            cubeta[k + 1] = cubeta[k];
            k--;
        }
        cubeta[k + 1] = valor; // Inserta el elemento en su lugar correcto
    }
}

// Función principal del algoritmo Bucket Sort
void ordenamiento_bucket(vector<float>& arreglo) {
    int tamaño = arreglo.size();
    vector<vector<float>> cubetas(tamaño); // Crea lista de cubetas vacías

    // Distribuye los elementos en las cubetas según su valor
    for (float num : arreglo) {
        int indice = int(tamaño * num);
        if (indice == tamaño) // Evita índice fuera de rango
            indice = tamaño - 1;
        cubetas[indice].push_back(num);
    }

    // Ordena cada cubeta individualmente
    for (auto& cubeta : cubetas) {
        ordenamiento_insercion(cubeta);
    }

    // Une todas las cubetas en el arreglo original
    int indice_arreglo = 0;
    for (auto& cubeta : cubetas) {
        for (float num : cubeta) {
            arreglo[indice_arreglo++] = num;
        }
    }
}

int main() {
    vector<float> arreglo = {0.88, 0.16, 0.48, 0.25, 0.75, 0.99, 0.23, 0.11, 0.24, 0.67};

    cout << "Arreglo desordenado:\n";
    for (float num : arreglo) cout << num << " ";
    cout << endl;

    ordenamiento_bucket(arreglo);

    cout << "Arreglo ordenado:\n";
    for (float num : arreglo) cout << num << " ";
    cout << endl;

    return 0;
}
