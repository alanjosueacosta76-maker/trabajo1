using System;

class Program
{
    static void Main()
    {

        int[] arreglo = { 5, 10, 15, 20 };

        int variable = arreglo[2]; 
        Console.WriteLine($"variable = {variable}");

 
        int[] arreglo2 = new int[3]; 
        for (int i = 0; i < arreglo2.Length; i++)
        {
            Console.WriteLine($"Indice {i} -> {arreglo2[i]}");
        }
    }
}







