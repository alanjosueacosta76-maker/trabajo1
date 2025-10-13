using System;

class ShellSort
{
    // Muestra los elementos del arreglo en una sola línea
    public static void DisplayArr(int[] arr)
    {
        foreach (int num in arr)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }

    // Ordena un arreglo usando el algoritmo Shell Sort
    public void Sort(int[] arr)
    {
        int size = arr.Length;
        int gapSize = size / 2; // Se empieza con un "salto" grande

        // Mientras el salto sea mayor que cero, seguimos ordenando
        while (gapSize > 0)
        {
            // Recorremos los elementos desde 'gapSize' hasta el final
            for (int j = gapSize; j < size; j++)
            {
                int val = arr[j]; // Elemento actual a comparar
                int k = j;

                // Compara y mueve los elementos que estén fuera de orden
                while (k >= gapSize && arr[k - gapSize] > val)
                {
                    arr[k] = arr[k - gapSize];
                    k = k - gapSize;
                }

                // Inserta el elemento en su posición correcta
                arr[k] = val;
            }

            // Reduce el salto a la mitad en cada iteración
            gapSize = gapSize / 2;
        }
    }
}

class Program
{
    static void Main()
    {
        int[] inputArr = { 36, 38, 44, 11, 19, 30, 28, 50 };

        Console.WriteLine("Arreglo desordenado:");
        ShellSort.DisplayArr(inputArr);

        ShellSort obj = new ShellSort();
        obj.Sort(inputArr);

        Console.WriteLine("Arreglo ordenado:");
        ShellSort.DisplayArr(inputArr);
    }
}
