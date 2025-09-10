#include <stdio.h>

int main() {
    int arr[6] = {10, 20, 30, 40, 50};  // Arreglo con espacio para insertar un nuevo elemento
    int n = 5;                          // Número actual de elementos
    int pos = 2;                        // Posición donde insertar (índice)
    int valor = 99;

    // Mover los elementos una posición a la derecha desde el final hasta la posición deseada
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insertar el nuevo valor
    arr[pos] = valor;
    n++;  // Incrementar el número total de elementos

    // Imprimir el arreglo después de la inserción
    printf("Arreglo después de insertar:\n");
    for (int i = 0; i < n; i++) {
        printf("Índice %d -> %d\n", i, arr[i]);
    }

    return 0;
}
