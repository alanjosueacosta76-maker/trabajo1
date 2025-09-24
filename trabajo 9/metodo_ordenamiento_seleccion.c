#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10  


void generarDatosAleatorios(int arreglo[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        arreglo[i] = rand() % 100 + 1; 
    }
}


void imprimirArreglo(int arreglo[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}


// Función para hacer el ordenamiento por selección
void selecion_sort(int lista[], int n) {
    int i, j, min_index, temp;

    for (i = 0; i < n - 1; i++) {
        // Suponemos que el elemento actual es el mínimo
        min_index = i;

        // Buscamos el mínimo en el resto de la lista
        for (j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }

        // Si encontramos uno menor, lo intercambiamos
        if (min_index != i) {
            temp = lista[i];
            lista[i] = lista[min_index];
            lista[min_index] = temp;
        }
    }
}
int main() {
    int arreglo[TAM];


    srand(time(NULL));


    generarDatosAleatorios(arreglo, TAM);

    printf("Arreglo desordenado:\n");
    imprimirArreglo(arreglo, TAM);

    
    selecion_sort(arreglo, TAM);

    printf("Arreglo ordenado:\n");
    imprimirArreglo(arreglo, TAM);

    return 0;
}