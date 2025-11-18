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

public class CircularLinkedList
{
    // Variable global que apunta al primer nodo de la lista
    public Node head = null;

    // --- Funciones de Inserción ---

    public void BeginInsert()
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
            // Lista vacía: el nuevo nodo apunta a sí mismo
            head = newNode;
            newNode.next = head;
        }
        else
        {
            // Encontrar el último nodo (el que apunta a 'head')
            Node temp = head;
            while (temp.next != head)
            {
                temp = temp.next;
            }
            
            // 1. El nuevo nodo apunta al 'head' anterior
            newNode.next = head;
            // 2. El último nodo apunta al nuevo nodo
            temp.next = newNode;
            // 3. 'head' se actualiza al nuevo nodo
            head = newNode;
        }
        Console.WriteLine("\nNodo insertado al principio");
    }

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
            // Lista vacía: el nuevo nodo es el head y apunta a sí mismo
            head = newNode;
            newNode.next = head;
        }
        else
        {
            // Encontrar el último nodo
            Node temp = head;
            while (temp.next != head)
            {
                temp = temp.next;
            }

            // 1. El nuevo nodo apunta al head (cierra el círculo)
            newNode.next = head;
            // 2. El nodo que era el último ahora apunta al nuevo nodo
            temp.next = newNode;
        }
        Console.WriteLine("\nNodo insertado al final");
    }

    public void RandomInsert()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        Console.WriteLine("\nIntroduce el valor del elemento");
        if (!int.TryParse(Console.ReadLine(), out int item))
        {
            Console.WriteLine("Entrada inválida.");
            return;
        }

        Console.WriteLine("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar ");
        if (!int.TryParse(Console.ReadLine(), out int loc) || loc < 0)
        {
            Console.WriteLine("Entrada inválida o ubicación negativa.");
            return;
        }

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        while (i < loc)
        {
            temp = temp.next;
            i++;

            if (temp == head)
            {
                Console.WriteLine("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }

        // 1. El nuevo nodo apunta al siguiente del nodo actual (temp)
        newNode.next = temp.next;
        // 2. El nodo actual (temp) apunta al nuevo nodo
        temp.next = newNode;

        Console.WriteLine("\nNodo insertado");
    }

    // --- Funciones de Eliminación ---

    public void BeginDelete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía\n");
            return;
        }

        if (head.next == head)
        {
            // Caso de un solo nodo
            head = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
            return;
        }

        // Encontrar el último nodo (el que apunta a 'head')
        Node lastNode = head;
        while (lastNode.next != head)
        {
            lastNode = lastNode.next;
        }

        // 1. 'head' se mueve al siguiente nodo
        head = head.next;
        // 2. El último nodo apunta al nuevo 'head'
        lastNode.next = head;

        Console.WriteLine("\nNodo eliminado desde el principio ...\n");
    }

    public void LastDelete()
    {
        if (head == null)
        {
            Console.WriteLine("\nLa lista está vacía");
            return;
        }
        else if (head.next == head)
        {
            // Caso especial: solo hay un nodo
            head = null;
            Console.WriteLine("\nSolo se eliminó un nodo de la lista ...\n");
            return;
        }

        Node ptr = head;
        Node ptr1 = null; // ptr1 será el penúltimo

        // Recorre hasta que el siguiente nodo de 'ptr' sea 'head'
        while (ptr.next != head)
        {
            ptr1 = ptr;
            ptr = ptr.next;
        }

        // ptr1 es el penúltimo. 
        // 1. El penúltimo (ptr1) ahora apunta a head (cierra el círculo)
        ptr1.next = head;
        
        Console.WriteLine("\nNodo eliminado del último ...\n");
    }

    public void RandomDelete()
    {
        if (head == null || head.next == head)
        {
            Console.WriteLine("\nNo se puede eliminar en posición. La lista está vacía o tiene solo un nodo (usa eliminar al principio/final).");
            return;
        }

        Console.WriteLine("\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n");
        if (!int.TryParse(Console.ReadLine(), out int loc) || loc < 0)
        {
            Console.WriteLine("Entrada inválida o ubicación negativa.");
            return;
        }

        Node ptr = head;
        int i = 0;

        while (i < loc)
        {
            ptr = ptr.next;
            i++;

            if (ptr == head)
            {
                Console.WriteLine("\nNo se puede eliminar. La posición está fuera de rango.");
                return;
            }
        }
        
        Node nodeToDelete = ptr.next;
        
        if (nodeToDelete == head)
        {
            Console.WriteLine("\nNo se recomienda eliminar la cabecera (head) con esta función. Use la Opción 4.");
            return;
        }

        // 1. 'ptr' salta al nodo siguiente del nodo a eliminar
        ptr.next = nodeToDelete.next;
        
        Console.WriteLine($"\nNodo eliminado después de la posición {loc + 1}");
    }

    // --- Otras Funciones ---

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

        do
        {
            if (ptr.data == item)
            {
                Console.WriteLine($"Elemento encontrado en la ubicación {i + 1}");
                found = true;
                break;
            }
            ptr = ptr.next;
            i++;
        } while (ptr != head);

        if (!found)
        {
            Console.WriteLine("Elemento no encontrado\n");
        }
    }

    public void Display()
    {
        if (head == null)
        {
            Console.WriteLine("Nada que imprimir");
        }
        else
        {
            Console.WriteLine("\nImprimiendo valores . . . (Lista Circular)");
            Node ptr = head;
            StringBuilder output = new StringBuilder();
            
            do
            {
                output.Append(ptr.data);
                ptr = ptr.next;
                if (ptr != head)
                {
                    output.Append(" -> ");
                }
            } while (ptr != head);

            output.Append(" -> (HEAD)");
            Console.WriteLine(output.ToString());
        }
    }
}

// --- Función Principal ---

public class Program
{
    public static void Main(string[] args)
    {
        CircularLinkedList list = new CircularLinkedList();
        int choice = 0;

        while (choice != 9)
        {
            Console.WriteLine("\n\n******Menú principal (Lista Circular)******");
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
                case 1: list.BeginInsert(); break;
                case 2: list.LastInsert(); break;
                case 3: list.RandomInsert(); break;
                case 4: list.BeginDelete(); break;
                case 5: list.LastDelete(); break;
                case 6: list.RandomDelete(); break;
                case 7: list.Search(); break;
                case 8: list.Display(); break;
                case 9:
                    Console.WriteLine("Saliendo del programa.");
                    break;
                default: Console.WriteLine("Introduzca una opción válida.."); break;
            }
        }
    }
}