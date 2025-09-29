using System;

class Program
{
    static void Burbuja(int[] arr, int n)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    static void ImprimirArreglo(int[] arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            Console.Write(arr[i] + " ");
        }
        Console.WriteLine();
    }

    static void Main()
    {
        int[] lista = { 5, 3, 8, 4, 2 };
        int n = lista.Length;

        Console.Write("Lista desordenada: ");
        ImprimirArreglo(lista, n);

        Burbuja(lista, n);

        Console.Write("Lista ordenada: ");
        ImprimirArreglo(lista, n);
    }
}


