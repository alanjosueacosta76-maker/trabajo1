using System;

// Clase para representar cada nodo de la lista
public class Node
{
    public int data;
    public Node next; // Referencia al siguiente nodo
    public Node prev; // Referencia al nodo anterior

    public Node(int data)
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

// Clase que contiene la lógica de la lista
public class DoublyLinkedList
{
    private Node head = null; // La cabeza de la lista

    // Propiedad para verificar si la lista está vacía
    public bool IsEmpty()
    {
        return head == null;
    }

    // --- Funciones de Inserción ---

    public void BeginInsert(int item)
    {
        Node newNode = new Node(item);

        if (IsEmpty())
        {
            head = newNode;
        }
        else
        {
            // El nuevo nodo apunta al head actual
            newNode.next = head; 
            
            // El head actual apunta su 'prev' al nuevo nodo
            head.prev = newNode; 
            
            // El nuevo nodo se convierte en el head
            head = newNode;
        }
        Console.WriteLine($"\nNodo {item} insertado al principio");
    }

    public void LastInsert(int item)
    {
        Node newNode = new Node(item);

        if (IsEmpty())
        {
            head = newNode;
        }
        else
        {
            // Encontrar el último nodo
            Node temp = head;
            while (temp.next != null)
            {
                temp = temp.next;
            }

            // Conexiones:
            temp.next = newNode; // El antiguo último apunta al nuevo
            newNode.prev = temp; // El nuevo apunta su 'prev' al antiguo último
            // newNode.next ya es null por el constructor
        }
        Console.WriteLine($"\nNodo {item} insertado al final");
    }

    public void RandomInsert(int item, int loc)
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        if (loc < 0)
        {
            Console.WriteLine("\nLa ubicación debe ser un número positivo.");
            return;
        }

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        while (i < loc && temp != null)
        {
            temp = temp.next;
            i++;
        }

        if (temp == null || i != loc)
        {
            Console.WriteLine("\nNo se puede insertar. La posición está fuera de rango.");
            return;
        }
        
        // Nodos: A (temp), B (newNode), C (temp.next)
        Node nextNode = temp.next;

        // 1. Conexiones de B (newNode)
        newNode.next = nextNode;
        newNode.prev = temp;

        // 2. Reconexiones de A (temp)
        temp.next = newNode;

        // 3. Reconexiones de C (nextNode), si existe
        if (nextNode != null)
        {
            nextNode.prev = newNode;
        }

        Console.WriteLine($"\nNodo {item} insertado después de la posición {loc}");
    }

    // --- Funciones de Eliminación ---

    public void BeginDelete()
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía\n");
            return;
        }

        Node ptrToDelete = head;

        if (head.next == null)
        {
            // Caso de un solo nodo
            head = null;
        }
        else
        {
            // Caso de múltiples nodos
            head = head.next; // Mover head al siguiente
            head.prev = null; // El nuevo head tiene 'prev' NULL
        }

        // El Garbage Collector de C# liberará la memoria de ptrToDelete automáticamente.
        Console.WriteLine("\nNodo eliminado desde el principio ...\n");
    }

    public void LastDelete()
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía\n");
            return;
        }

        Node ptrToDelete = head;

        if (head.next == null)
        {
            // Caso de un solo nodo
            head = null;
        }
        else
        {
            // Recorrer hasta el último nodo
            while (ptrToDelete.next != null)
            {
                ptrToDelete = ptrToDelete.next;
            }
            
            // El penúltimo nodo (ptrToDelete.prev) debe apuntar su 'next' a null
            ptrToDelete.prev.next = null;
        }
        
        Console.WriteLine("\nNodo eliminado del último ...\n");
    }

    public void RandomDelete(int loc)
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLista vacía. No se puede eliminar.\n");
            return;
        }

        if (loc < 0)
        {
            Console.WriteLine("\nLa ubicación debe ser un número positivo.\n");
            return;
        }

        Node ptrToDelete = head;
        int i = 0;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        while (i < loc && ptrToDelete != null)
        {
            ptrToDelete = ptrToDelete.next;
            i++;
        }

        if (ptrToDelete == null)
        {
            Console.WriteLine("\nNo se puede eliminar. La posición está fuera de rango.\n");
            return;
        }

        // Si es el primer nodo (llamamos al método que ya lo maneja)
        if (ptrToDelete == head)
        {
            BeginDelete();
            return;
        }

        // Si es el último nodo (llamamos al método que ya lo maneja)
        if (ptrToDelete.next == null)
        {
            LastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        Node prevNode = ptrToDelete.prev;
        Node nextNode = ptrToDelete.next;

        // 1. Reconexión A a C
        prevNode.next = nextNode;

        // 2. Reconexión C a A
        nextNode.prev = prevNode;

        Console.WriteLine($"\nNodo en la posición {loc + 1} eliminado.");
    }

    // --- Otras Funciones ---

    public void Search(int item)
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLista vacia\n");
            return;
        }

        Node ptr = head;
        int i = 0;
        bool found = false;

        while (ptr != null)
        {
            if (ptr.data == item)
            {
                Console.WriteLine($"Elemento encontrado en la ubicación {i + 1}");
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

    public void Display()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Nada que imprimir");
        }
        else
        {
            Console.WriteLine("\nImprimiendo valores (HEAD a END): ");
            Node ptr = head;
            
            while (ptr != null)
            {
                Console.Write(ptr.data);
                if (ptr.next != null)
                {
                    Console.Write(" <-> ");
                }
                ptr = ptr.next;
            }
            Console.WriteLine();
        }
    }
}

// Clase principal para el menú de interacción
public class Program
{
    public static void Main(string[] args)
    {
        DoublyLinkedList list = new DoublyLinkedList();
        int choice = 0;
        
        while (choice != 9)
        {
            Console.WriteLine("\n\n******Menú principal (Lista Doblemente Enlazada C#)******");
            Console.WriteLine("\nElige una opción de la siguiente lista ...\n");
            Console.WriteLine("------------------------------------------\n");

            Console.WriteLine("1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio");
            Console.WriteLine("5. Eliminar desde el último\n6. Eliminar nodo por posición\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            Console.Write("\nIngrese su opción? ");
            
            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Opción inválida. Introduce un número del 1 al 9.");
                continue;
            }

            switch (choice)
            {
                case 1: 
                    Console.Write("\nIngrese valor: ");
                    if (int.TryParse(Console.ReadLine(), out int item1))
                        list.BeginInsert(item1);
                    break;
                case 2: 
                    Console.Write("\nIngrese valor: ");
                    if (int.TryParse(Console.ReadLine(), out int item2))
                        list.LastInsert(item2);
                    break;
                case 3: 
                    Console.Write("\nIntroduce el valor del elemento: ");
                    if (int.TryParse(Console.ReadLine(), out int item3))
                    {
                        Console.Write("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: ");
                        if (int.TryParse(Console.ReadLine(), out int loc3))
                            list.RandomInsert(item3, loc3);
                    }
                    break;
                case 4: list.BeginDelete(); break;
                case 5: list.LastDelete(); break;
                case 6: 
                    Console.Write("\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: ");
                    if (int.TryParse(Console.ReadLine(), out int loc6))
                        list.RandomDelete(loc6);
                    break;
                case 7: 
                    Console.Write("\nIntroduce el elemento que deseas buscar?\n");
                    if (int.TryParse(Console.ReadLine(), out int item7))
                        list.Search(item7);
                    break;
                case 8: list.Display(); break;
                case 9:
                    Console.WriteLine("Saliendo del programa.");
                    Environment.Exit(0);
                    break;
                default: Console.WriteLine("Introduzca una opción válida.."); break;
            }
        }
    }
}