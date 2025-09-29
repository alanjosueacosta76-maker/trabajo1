using System;

class Program
{
    const int TAM = 10;

    static void GenerarDatosAleatorios(int[] arreglo, int tamaño)
    {
        Random rnd = new Random();
        for (int i = 0; i < tamaño; i++)
        {
            arreglo[i] = rnd.Next(1, 101); 
        }
    }

    static void ImprimirArreglo(int[] arreglo, int tamaño)
    {
        for (int i = 0; i < tamaño; i++)
        {
            Console.Write(arreglo[i] + " ");
        }
        Console.WriteLine();
    }

    static void SeleccionSort(int[] lista, int n)
    {
        int i, j, min_index, temp;

        for (i = 0; i < n - 1; i++)
        {
            min_index = i;

            for (j = i + 1; j < n; j++)
            {
                if (lista[j] < lista[min_index])
                {
                    min_index = j;
                }
            }

            if (min_index != i)
            {
                temp = lista[i];
                lista[i] = lista[min_index];
                lista[min_index] = temp;
            }
        }
    }

    static void Main()
    {
        int[] arreglo = new int[TAM];

        GenerarDatosAleatorios(arreglo, TAM);

        Console.WriteLine("Arreglo desordenado:");
        ImprimirArreglo(arreglo, TAM);

        SeleccionSort(arreglo, TAM);

        Console.WriteLine("Arreglo ordenado:");
        ImprimirArreglo(arreglo, TAM);
    }
}
