#include <stdio.h>

void burbuja(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int lista[] = {5, 3, 8, 4, 2};
    int n = sizeof(lista) / sizeof(lista[0]);

    printf("Lista desordenada:");
    imprimirArreglo(lista, n);

    burbuja(lista, n);

    printf("Lista ordenada: ");
    imprimirArreglo(lista, n);

    return 0;
}
