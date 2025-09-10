#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Recorrido por columnas:\n");
    for (int j = 0; j < 3; j++) {        // Columnas
        for (int i = 0; i < 3; i++) {    // Filas
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n");
    return 0;
}
