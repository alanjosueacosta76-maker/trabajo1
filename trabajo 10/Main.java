import java.util.Random;

public class Main {

    // Método para intercambiar dos elementos
    static void intercambiar(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    // Método de partición
    static int particion(int[] arr, int inicio, int fin) {
        int pivote = arr[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j] <= pivote) {
                i++;
                intercambiar(arr, i, j);
            }
        }
        intercambiar(arr, i + 1, fin);
        return i + 1;
    }

    // Método Quick Sort recursivo
    static void quickSort(int[] arr, int inicio, int fin) {
        if (inicio < fin) {
            int indicePivote = particion(arr, inicio, fin);
            quickSort(arr, inicio, indicePivote - 1);
            quickSort(arr, indicePivote + 1, fin);
        }
    }

    // Método para imprimir el arreglo
    static void imprimirArreglo(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Método principal
    public static void main(String[] args) {
        Random rnd = new Random();
        int tamaño = 10;
        int[] lista = new int[tamaño];

        // Llenar el arreglo con números aleatorios entre 1 y 100
        for (int i = 0; i < tamaño; i++) {
            lista[i] = rnd.nextInt(100) + 1;  // 1 a 100
        }

        System.out.println("Lista desordenada:");
        imprimirArreglo(lista);

        quickSort(lista, 0, tamaño - 1);

        System.out.println("\nLista ordenada:");
        imprimirArreglo(lista);
    }
}
