public class Main {
    public static void main(String[] args) {
        int[] arr = new int[6]; // Arreglo con espacio para insertar un nuevo elemento
        int n = 5;              // Número actual de elementos
        int pos = 2;            // Posición donde insertar (índice)
        int valor = 99;

        // Inicializar los primeros 5 elementos
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        // Mover los elementos una posición a la derecha desde el final hasta la posición deseada
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        // Insertar el nuevo valor
        arr[pos] = valor;
        n++;  // Incrementar el número total de elementos

        // Imprimir el arreglo después de la inserción
        System.out.println("Arreglo después de insertar:");
        for (int i = 0; i < n; i++) {
            System.out.println("Índice " + i + " -> " + arr[i]);
        }
    }
}

