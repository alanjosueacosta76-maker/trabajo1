using System;

class Program
{
    static void Burbuja(int[] arr)
    {
        int n = arr.Length;
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

    static void ImprimirArreglo(int[] arr)
    {
        foreach (int num in arr)
        {
            Console.Write($"{num} ");
        }
        Console.WriteLine();
    }

    static void Main()
    {
        int[] lista = { 5, 3, 8, 4, 2 };

        Console.WriteLine("Lista desordenada:");
        ImprimirArreglo(lista);

        Burbuja(lista);

        Console.WriteLine("Lista ordenada:");
        ImprimirArreglo(lista);
    }
}


