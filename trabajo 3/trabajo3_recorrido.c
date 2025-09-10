#include <stdio.h>

int main() {
    int arreglo[] = {10, 20, 30, 40, 50};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Recorrido del arreglo:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("%d\n", arreglo[i]);
    }

    return 0;
}
