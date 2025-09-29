using System;

class Program
{
    static void Main()
    {
        int[,] matriz = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        Console.WriteLine("Recorrido por columnas:");
        for (int j = 0; j < 3; j++) // Columnas
        {
            for (int i = 0; i < 3; i++) // Filas
            {
                Console.Write($"{matriz[i, j]} ");
            }
        }

        Console.WriteLine(); // Nueva línea final
    }
}


