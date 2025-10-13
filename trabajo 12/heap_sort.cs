using System;

class HeapSortExample
{
    // Función para hacer heapify de un subárbol con raíz en el índice i
    static void Heapify(int[] arr, int n, int i)
    {
        int largest = i;       // Inicializar el más grande como raíz
        int left = 2 * i + 1;  // Hijo izquierdo
        int right = 2 * i + 2; // Hijo derecho

        // Si el hijo izquierdo es mayor que la raíz
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Si el hijo derecho es mayor que el más grande hasta ahora
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // Si el mayor no es la raíz
        if (largest != i)
        {
            // Intercambiar
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursivamente hacer heapify al subárbol afectado
            Heapify(arr, n, largest);
        }
    }

    // Función principal para ordenar el arreglo usando Heap Sort
    static void HeapSort(int[] arr)
    {
        int n = arr.Length;

        // Construir Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(arr, n, i);

        // Extraer elementos uno por uno
        for (int i = n - 1; i > 0; i--)
        {
            // Mover la raíz al final
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Aplicar heapify al heap reducido
            Heapify(arr, i, 0);
        }
    }

    // Función para imprimir el arreglo
    static void PrintArray(int[] arr)
    {
        foreach (int num in arr)
            Console.Write(num + " ");
        Console.WriteLine();
    }

    // Método principal
    static void Main()
    {
        int[] arr = { 10, 20, 25, 5, 8, 7 };

        Console.WriteLine("Arreglo desordenado:");
        PrintArray(arr);

        HeapSort(arr);

        Console.WriteLine("Arreglo ordenado:");
        PrintArray(arr);
    }
}
