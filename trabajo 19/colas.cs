using System;

class Program
{
    const int MAXSIZE = 5;
    static int[] queueArr = new int[MAXSIZE];
    static int front = -1, rear = -1;

    static void Insertar()
    {
        Console.Write("\nIngrese el elemento: ");
        int elemento = int.Parse(Console.ReadLine());

        if (rear == MAXSIZE - 1)
        {
            Console.WriteLine("\nDESBORDAMIENTO (OVERFLOW)");
            return;
        }

        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;

        queueArr[rear] = elemento;
        Console.WriteLine("\nElemento insertado correctamente.");
    }

    static void Eliminar()
    {
        if (front == -1 || front > rear)
        {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)");
            return;
        }

        int elemento = queueArr[front];

        if (front == rear)
            front = rear = -1;
        else
            front++;

        Console.WriteLine("\nElemento eliminado: " + elemento);
    }

    static void Mostrar()
    {
        if (front == -1 || rear == -1 || front > rear)
        {
            Console.WriteLine("\nLa cola está vacía.");
            return;
        }

        Console.WriteLine("\nElementos en la cola:");
        for (int i = front; i <= rear; i++)
            Console.WriteLine(queueArr[i]);
    }

    static void Main()
    {
        int opcion = 0;

        while (opcion != 4)
        {
            Console.WriteLine("\n*************** MENÚ PRINCIPAL ***************");
            Console.WriteLine("1. Insertar un elemento");
            Console.WriteLine("2. Eliminar un elemento");
            Console.WriteLine("3. Mostrar la cola");
            Console.WriteLine("4. Salir");
            Console.Write("Ingrese su opción: ");
            opcion = int.Parse(Console.ReadLine());

            switch (opcion)
            {
                case 1: Insertar(); break;
                case 2: Eliminar(); break;
                case 3: Mostrar(); break;
                case 4: Console.WriteLine("\nSaliendo..."); break;
                default: Console.WriteLine("\nOpción inválida."); break;
            }
        }
    }
}
