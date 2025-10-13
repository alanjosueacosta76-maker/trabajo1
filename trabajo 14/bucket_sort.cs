using System;
using System.Collections.Generic;

class Program
{
    // Método de ordenamiento por inserción para una cubeta
    static void OrdenamientoInsercion(List<float> cubeta)
    {
        for (int j = 1; j < cubeta.Count; j++)
        {
            float valor = cubeta[j];
            int k = j - 1;

            while (k >= 0 && cubeta[k] > valor)
            {
                cubeta[k + 1] = cubeta[k];
                k--;
            }
            cubeta[k + 1] = valor;
        }
    }

    // Función principal de Bucket Sort
    static void OrdenamientoBucket(List<float> arreglo)
    {
        int tamaño = arreglo.Count;
        List<List<float>> cubetas = new List<List<float>>(tamaño);

        // Inicializar cubetas vacías
        for (int i = 0; i < tamaño; i++)
        {
            cubetas.Add(new List<float>());
        }

        // Distribuir los elementos en cubetas
        foreach (float num in arreglo)
        {
            int indice = (int)(tamaño * num);
            if (indice == tamaño) // Evita índice fuera de rango
                indice = tamaño - 1;

            cubetas[indice].Add(num);
        }

        // Ordenar cada cubeta
        foreach (var cubeta in cubetas)
        {
            OrdenamientoInsercion(cubeta);
        }

        // Concatenar cubetas en el arreglo original
        int indiceArreglo = 0;
        for (int i = 0; i < tamaño; i++)
        {
            foreach (float num in cubetas[i])
            {
                arreglo[indiceArreglo++] = num;
            }
        }
    }

    static void Main()
    {
        List<float> arreglo = new List<float> { 0.88f, 0.16f, 0.48f, 0.25f, 0.75f, 0.99f, 0.23f, 0.11f, 0.24f, 0.67f };

        Console.WriteLine("Arreglo desordenado:");
        foreach (float num in arreglo)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();

        OrdenamientoBucket(arreglo);

        Console.WriteLine("Arreglo ordenado:");
        foreach (float num in arreglo)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }
}
