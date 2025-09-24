import java.util.Random;

public class Main {
    static final int TAM = 10;

    public static void generarDatosAleatorios(int[] arreglo) {
        Random rand = new Random();
        for (int i = 0; i < arreglo.length; i++) {
            arreglo[i] = rand.nextInt(100) + 1;
        }
    }

    public static void imprimirArreglo(int[] arreglo) {
        for (int i = 0; i < arreglo.length; i++) {
            System.out.print(arreglo[i] + " ");
        }
        System.out.println();
    }


    // Método de ordenamiento por selección
    public static void ordenamientoPorSeleccion(int[] lista) {
        int n = lista.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            // Buscar el índice del valor mínimo en el resto del arreglo
            for (int j = i + 1; j < n; j++) {
                if (lista[j] < lista[minIndex]) {
                    minIndex = j;
                }
            }

            // Intercambiar si encontramos un valor menor
            if (minIndex != i) {
                int temp = lista[i];
                lista[i] = lista[minIndex];
                lista[minIndex] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arreglo = new int[TAM];
        generarDatosAleatorios(arreglo);
        System.out.println("Arreglo desordenado:");
        imprimirArreglo(arreglo);
        ordenamientoPorSeleccion(arreglo);
        System.out.println("Arreglo ordenado:");
        imprimirArreglo(arreglo);
    }
}

