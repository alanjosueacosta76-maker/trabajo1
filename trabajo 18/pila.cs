using System;
using System.Collections.Generic;

class Program
{
    // Tamaño máximo de la pila
    const int MAX_SIZE = 100;

    // Lista para almacenar los elementos de la pila
    static List<int> stack = new List<int>();

    // Función para agregar un elemento a la pila
    static void Push(int item)
    {
        if (stack.Count == MAX_SIZE) // Verifica si la pila está llena
        {
            Console.WriteLine("Stack Overflow"); // Mensaje de error
            return;
        }
        stack.Add(item); // Agrega el elemento al final (parte superior de la pila)
    }

    // Función para eliminar y retornar el elemento superior de la pila
    static int Pop()
    {
        if (stack.Count == 0) // Verifica si la pila está vacía
        {
            Console.WriteLine("Stack Underflow"); // Mensaje de error
            return -1; // Retorna -1 para indicar que la pila está vacía
        }
        int top = stack[stack.Count - 1];
        stack.RemoveAt(stack.Count - 1); // Elimina el último elemento
        return top;
    }

    // Función para ver el elemento superior sin eliminarlo
    static int Peek()
    {
        if (stack.Count == 0)
        {
            Console.WriteLine("Pila vacía");
            return -1;
        }
        return stack[stack.Count - 1];
    }

    // Función para verificar si la pila está vacía
    static bool IsEmpty()
    {
        return stack.Count == 0;
    }

    // Función para verificar si la pila está llena
    static bool IsFull()
    {
        return stack.Count == MAX_SIZE;
    }

    // Programa principal
    static void Main()
    {
        Push(10); // Agrega elementos a la pila
        Push(20);
        Push(30);

        Console.WriteLine("Elemento Superior: " + Peek()); // Muestra el elemento superior
        Console.WriteLine("Extrae elemento: " + Pop()); // Elimina y muestra el elemento superior
        Console.WriteLine("Elemento Superior: " + Peek()); // Muestra el nuevo elemento superior
    }
}
