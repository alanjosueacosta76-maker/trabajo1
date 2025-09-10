#include <stdio.h>

int main() {
    // valores iniciales del arreglo
    int arreglo[4] = {5, 10, 15, 20};

    // asigna un valor por el índice

    arreglo[100] = 40; // Comportamiento indefinido en C

    // guarda un valor en la variable
    int variable = arreglo[2]; // guarda 15 en la variable
    printf("variable = %d\n", variable);

    // Inicializar con valores por defecto
    int arreglo2[3] = {0}; // Crea [0, 0, 0]

    // Leer un valor (bucle)
    for (int i = 0; i < 3; i++) {
        printf("Indice %d -> %d\n", i, arreglo2[i]);
    }

    return 0;
}






