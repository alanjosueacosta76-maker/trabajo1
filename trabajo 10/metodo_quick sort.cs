using System;

class Program
{
    // Método Quick Sort
    static void QuickSort(int[] arr, int inicio, int fin)
    {
        if (inicio < fin)
        {
            int indicePivote = Particion(arr, inicio, fin);
            QuickSort(arr, inicio, indicePivote - 1);
            QuickSort(arr, indicePivote + 1, fin);
        }
    }

    static int Particion(int[] arr, int inicio, int fin)
    {
        int pivote = arr[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++)
        {
            if (arr[j] <= pivote)
            {
                i++;
                Intercambiar(arr, i, j);
            }
        }
        Intercambiar(arr, i + 1, fin);
        return i + 1;
    }

    static void Intercambiar(int[] arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static void ImprimirArreglo(int[] arr)
    {
        foreach (int num in arr)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }

    static void Main()
    {
        Random rnd = new Random();
        int tamaño = 10;
        int[] lista = new int[tamaño];

        // Rellenar con números aleatorios entre 1 y 100
        for (int i = 0; i < tamaño; i++)
        {
            lista[i] = rnd.Next(1, 101);
        }

        Console.WriteLine("Lista desordenada:");
        ImprimirArreglo(lista);

        QuickSort(lista, 0, tamaño - 1);

        Console.WriteLine("\nLista ordenada:");
        ImprimirArreglo(lista);
    }
}
