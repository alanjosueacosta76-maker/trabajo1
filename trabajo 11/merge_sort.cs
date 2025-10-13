using System;

class Program
{
    // Función para mezclar dos subarreglos
    static void Merge(int[] a, int l, int m, int r)
    {
        int a1 = m - l + 1;
        int a2 = r - m;

        // Crear arreglos temporales
        int[] L = new int[a1];
        int[] R = new int[a2];

        // Copiar datos a los arreglos temporales
        for (int i = 0; i < a1; i++)
            L[i] = a[l + i];
        for (int j = 0; j < a2; j++)
            R[j] = a[m + 1 + j];

        // Mezclar los arreglos temporales de vuelta en a[l..r]
        int x = 0, y = 0, k = l;

        while (x < a1 && y < a2)
        {
            if (L[x] <= R[y])
            {
                a[k] = L[x];
                x++;
            }
            else
            {
                a[k] = R[y];
                y++;
            }
            k++;
        }

        // Copiar los elementos restantes de L[], si hay
        while (x < a1)
        {
            a[k] = L[x];
            x++;
            k++;
        }

        // Copiar los elementos restantes de R[], si hay
        while (y < a2)
        {
            a[k] = R[y];
            y++;
            k++;
        }
    }

    // Función principal de MergeSort
    static void MergeSort(int[] a, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);
            Merge(a, l, m, r);
        }
    }

    // Programa principal
    static void Main()
    {
        int[] a = { 10, 28, 54, 11 };
        int s = a.Length;

        Console.WriteLine("Arreglo desordenado:");
        for (int i = 0; i < s; i++)
            Console.Write(a[i] + " ");

        MergeSort(a, 0, s - 1);

        Console.WriteLine("\nArreglo ordenado:");
        for (int i = 0; i < s; i++)
            Console.Write(a[i] + " ");

        Console.WriteLine();
    }
}
