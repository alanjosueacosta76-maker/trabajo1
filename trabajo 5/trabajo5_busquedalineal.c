#include <stdio.h>

int main() {
    int arreglo[] = {5, 8, 3, 10, 7, 2, 15, 9};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
    int elemento, encontrado = 0;

    printf("Ingrese el número a buscar: ");
    scanf("%d", &elemento);

    // Búsqueda lineal
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == elemento) {
            printf("Elemento %d encontrado en la posición %d.\n", elemento, i);
            encontrado = 1;
            break; // Detener búsqueda al encontrar el elemento
        }
    }

    if (!encontrado) {
        printf("Elemento %d no encontrado en el arreglo.\n", elemento);
    }

    return 0;
}

