using System;
using System.Text;

// Definición de la clase Node
public class Node
{
    public int data;
    public Node next;

    public Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList
{
    // Variable global que apunta al primer nodo de la lista
    public Node head = null;

    // Función para insertar un nuevo nodo al principio de la lista
    public void BeginInsert()
    {
        Console.WriteLine("\nIngrese valor");
        if (!int.TryParse(Console.ReadLine(), out int item))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Node newNode = new Node(item);
        newNode.next = head;
        head = newNode;
        Console.WriteLine("\nNodo insertado");
    }

    // Función para insertar un nodo al final de la lista
    public void LastInsert()
    {
        Console.WriteLine("\nIngrese valor");
        if (!int.TryParse(Console.ReadLine(), out int item))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Node newNode = new Node(item);

        if (head == null)
        {
            head = newNode;
        }
        else
        {
            Node temp = head;
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        Console.WriteLine("\nNodo insertado");
    }

    // Función para Insertar un nodo en una posición específica de la lista
    public void RandomInsert()
    {
        if (head == null)
        {
            Console.WriteLine("\nLista vacía. No se puede insertar en posición.");
            return;
        }

        Console.WriteLine("\nIntroduce el valor del elemento");
        if (!int.TryParse(Console.ReadLine(), out int item))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Console.WriteLine("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar ");
        if (!int.TryParse(Console.ReadLine(), out int loc))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        for (i = 0; i < loc; i++)
        {
            temp = temp.next;

            if (temp == null)
            {
                Console.WriteLine("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }

        newNode.next = temp.next;
        temp.next = newNode;
        Console.WriteLine("\nNodo insertado");
    }

    // Función para eliminar el primer nodo de la lista
    public void BeginDelete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía\n");
        }
        else
        {
            head = head.next;
            Console.WriteLine("\nNodo eliminado desde el principio ...\n");
        }
    }

    // Función para eliminar el último nodo de la lista
    public void LastDelete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía");
        }
        else if (head.next == null)
        {
            head = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
        }
        else
        {
            Node ptr = head;
            Node ptr1 = null;
            while (ptr.next != null)
            {
                ptr1 = ptr;
                ptr = ptr.next;
            }
            ptr1.next = null;
            Console.WriteLine("\nNodo eliminado del último ...\n");
        }
    }

    // Función para eliminar un nodo después de una posición específica
    public void RandomDelete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLista vacía. No se puede eliminar.");
            return;
        }
        
        Console.WriteLine("\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n");
        if (!int.TryParse(Console.ReadLine(), out int loc))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Node ptr = head;
        Node ptr1 = null;
        int i = 0;

        for (i = 0; i < loc; i++)
        {
            ptr1 = ptr;
            ptr = ptr.next;

            if (ptr == null || ptr.next == null)
            {
                Console.WriteLine("\nNo se puede eliminar. La posición está fuera de rango o el nodo a eliminar no existe.");
                return;
            }
        }

        Node nodeToDelete = ptr.next;
        ptr.next = nodeToDelete.next;
        Console.WriteLine("\nNodo eliminado después de la posición " + (loc + 1));
    }

    // Función para buscar un elemento en la lista y mostrar su posición
    public void Search()
    {
        if (head == null)
        {
            Console.WriteLine("\nLista vacia\n");
            return;
        }

        Console.WriteLine("\nIntroduce el elemento que deseas buscar?\n");
        if (!int.TryParse(Console.ReadLine(), out int item))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Node ptr = head;
        int i = 0;
        bool found = false;

        while (ptr != null)
        {
            if (ptr.data == item)
            {
                Console.WriteLine("Elemento encontrado en la ubicación " + (i + 1));
                found = true;
                break;
            }
            ptr = ptr.next;
            i++;
        }

        if (!found)
        {
            Console.WriteLine("Elemento no encontrado\n");
        }
    }

    // Función para mostrar todos los elementos de la lista
    public void Display()
    {
        if (head == null)
        {
            Console.WriteLine("Nada que imprimir");
        }
        else
        {
            Console.WriteLine("\nImprimiendo valores . . .");
            Node ptr = head;
            while (ptr != null)
            {
                Console.WriteLine("\n" + ptr.data);
                ptr = ptr.next;
            }
        }
    }
}

// Función principal
public class Program
{
    public static void Main(string[] args)
    {
        LinkedList list = new LinkedList();
        int choice = 0;

        while (choice != 9)
        {
            Console.WriteLine("\n\n******Menú principal******");
            Console.WriteLine("\nElige una opción de la siguiente lista ...");
            Console.WriteLine("\n------------------------------------------");

            Console.WriteLine("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
                    + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            Console.WriteLine("Ingrese su opción?");
            
            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Opción inválida. Introduce un número del 1 al 9.");
                choice = 0; // Para que el bucle continúe
                continue;
            }

            switch (choice)
            {
                case 1:
                    list.BeginInsert();
                    break;
                case 2:
                    list.LastInsert();
                    break;
                case 3:
                    list.RandomInsert();
                    break;
                case 4:
                    list.BeginDelete();
                    break;
                case 5:
                    list.LastDelete();
                    break;
                case 6:
                    list.RandomDelete();
                    break;
                case 7:
                    list.Search();
                    break;
                case 8:
                    list.Display();
                    break;
                case 9:
                    Console.WriteLine("Saliendo del programa.");
                    break;
                default:
                    Console.WriteLine("Introduzca una opción válida..");
                    break;
            }
        }
    }
}