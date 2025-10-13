public class Main {

    // Método para aplicar heapify a un subárbol con raíz en i
    static void heapify(int[] arr, int n, int i) {
        int largest = i;         // Inicializar el más grande como raíz
        int left = 2 * i + 1;    // Hijo izquierdo
        int right = 2 * i + 2;   // Hijo derecho

        // Si el hijo izquierdo es mayor que la raíz
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Si el hijo derecho es mayor que el más grande hasta ahora
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // Si el mayor no es la raíz
        if (largest != i) {
            // Intercambiar
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursivamente heapify el subárbol afectado
            heapify(arr, n, largest);
        }
    }

    // Método principal para ordenar con Heap Sort
    static void heapSort(int[] arr) {
        int n = arr.length;

        // Construir Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extraer elementos uno a uno
        for (int i = n - 1; i > 0; i--) {
            // Mover raíz al final
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Llamar heapify al heap reducido
            heapify(arr, i, 0);
        }
    }

    // Método para imprimir el arreglo
    static void printArray(int[] arr) {
        for (int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }


    public static void main(String[] args) {
        int[] arr = { 10, 20, 25, 5, 8, 7 };

        System.out.println("Arreglo desordenado:");
        printArray(arr);

        heapSort(arr);

        System.out.println("Arreglo ordenado:");
        printArray(arr);
    }
}
