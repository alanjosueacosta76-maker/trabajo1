#include <iostream>
#include <vector>
#include <cstdlib>   

using namespace std;


void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Contar la cantidad de ocurrencias de cada dígito
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Sumar los conteos acumulados
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida (de derecha a izquierda para estabilidad)
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copiar los resultados al arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(vector<int>& arr) {
    int maxNum = arr[0];
    for (int num : arr) {
        if (num > maxNum)
            maxNum = num;
    }

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}


int main() {
    srand(time(nullptr));
    vector<int> arr(20);

    // Generar 20 números aleatorios entre 1 y 9999
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 9999 + 1;
    }

    cout << "Arreglo desordenado:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";
    radixSort(arr);

    cout << "\nArreglo ordenado:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";



    return 0;
}
