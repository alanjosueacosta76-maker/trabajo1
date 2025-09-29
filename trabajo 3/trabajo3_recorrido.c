using System;

class Program
{
    static void Main()
    {
        int[] arreglo = { 10, 20, 30, 40, 50 };

        Console.WriteLine("Recorrido del arreglo:");
        for (int i = 0; i < arreglo.Length; i++)
        {
            Console.WriteLine(arreglo[i]);
        }
    }
}


