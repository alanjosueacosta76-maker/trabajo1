using System;

class Program
{
    static void Main()
    {
        int[] arr = new int[6] { 10, 20, 30, 40, 50, 0 }; // Espacio para un nuevo elemento
        int n = 5;    // Número actual de elementos (los primeros 5 están ocupados)
        int pos = 2;  // Posición donde insertar (índice)
        int valor = 99;

        // Mover los elementos una posición a la derecha desde el final hasta la posición deseada
        for (int i = n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Insertar el nuevo valor
        arr[pos] = valor;
        n++; // Aumentar el conteo

        // Imprimir el arreglo después de la inserción
        Console.WriteLine("Arreglo después de insertar:");
        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"Índice {i} -> {arr[i]}");
        }
    }
}


