using System;

class Program
{
    static void CountingSort(int[] arr, int exp)
    {
        int n = arr.Length;
        int[] output = new int[n];
        int[] count = new int[10];

        // Contar la cantidad de ocurrencias de cada dígito
        for (int i = 0; i < n; i++)
        {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        // Sumar los conteos acumulados
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // Construir el arreglo de salida
        for (int i = n - 1; i >= 0; i--)
        {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // Copiar al arreglo original
        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }

    static void RadixSort(int[] arr)
    {
        int max = arr[0];
        foreach (int num in arr)
        {
            if (num > max)
                max = num;
        }

        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            CountingSort(arr, exp);
        }
    }

    static void Main()
    {
        Random rand = new Random();
        int[] arr = new int[20];

        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = rand.Next(1, 10000);  
        }

        Console.WriteLine("Arreglo desordenado:");
        Console.WriteLine(string.Join(", ", arr));

        RadixSort(arr);

        Console.WriteLine("\nArreglo ordenado:");
        Console.WriteLine(string.Join(", ", arr));
    }
}
