using System;

class Program
{
    static void Main()
    {
        int[] arreglo = { 5, 8, 3, 10, 7, 2, 15, 9 };
        int tamaño = arreglo.Length;
        int elemento;
        bool encontrado = false;

        Console.Write("Ingrese el número a buscar: ");
        string entrada = Console.ReadLine();

        // Intentar convertir la entrada a entero
        if (int.TryParse(entrada, out elemento))
        {
            // Búsqueda lineal
            for (int i = 0; i < tamaño; i++)
            {
                if (arreglo[i] == elemento)
                {
                    Console.WriteLine($"Elemento {elemento} encontrado en la posición {i}.");
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                Console.WriteLine($"Elemento {elemento} no encontrado en el arreglo.");
            }
        }
        else
        {
            Console.WriteLine("Entrada inválida. Por favor ingrese un número entero.");
        }
    }
}



