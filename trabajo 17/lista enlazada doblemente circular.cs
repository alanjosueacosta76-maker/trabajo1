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

// Clase que contiene la lógica de la Lista Doblemente Enlazada Circular
public class DoublyCircularLinkedList
{
    // Usamos el 'head' como punto de entrada, o 'last' para un acceso más fácil al final.
    // Aquí usamos 'head'.
    private Node head = null;

    /**
     * Verifica si la lista está vacía.
     * @returns {bool} true si la lista no contiene nodos.
     */
    public bool IsEmpty()
    {
        return head == null;
    }

    /**
     * Encuentra y devuelve el último nodo de la lista.
     * En una lista circular, este es el nodo cuyo 'next' apunta al 'head'.
     * @returns {Node} El último nodo o null si la lista está vacía.
     */
    private Node GetLastNode()
    {
        if (IsEmpty())
        {
            return null;
        }
        // El último nodo es el que apunta al head a través de 'prev' del head.
        // O más directo: es el nodo anterior al head.
        return head.prev;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio (antes del head).
     * @param {int} item El valor a insertar.
     */
    public void BeginInsert(int item)
    {
        Node newNode = new Node(item);

        if (IsEmpty())
        {
            head = newNode;
            // En una lista circular, un solo nodo apunta a sí mismo
            head.next = head;
            head.prev = head;
        }
        else
        {
            Node last = GetLastNode();

            // 1. Conexiones del nuevo nodo
            newNode.next = head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            head.prev = newNode;
            last.next = newNode;

            // 3. Mover la cabeza al nuevo nodo
            head = newNode;
        }
        Console.WriteLine($"\nNodo {item} insertado al principio (nuevo head).");
    }

    /**
     * Inserta un nodo al final (antes del head).
     * @param {int} item El valor a insertar.
     */
    public void LastInsert(int item)
    {
        Node newNode = new Node(item);

        if (IsEmpty())
        {
            // Reutilizamos la lógica del primer elemento
            head = newNode;
            head.next = head;
            head.prev = head;
        }
        else
        {
            Node last = GetLastNode();

            // Nodos: A (last), B (newNode), C (head)

            // 1. Conexiones del nuevo nodo
            newNode.next = head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            last.next = newNode;
            head.prev = newNode;
        }
        Console.WriteLine($"\nNodo {item} insertado al final.");
    }

    /**
     * Inserta un nodo en una posición (índice 0-basado) dada.
     * @param {int} item El valor a insertar.
     * @param {int} loc Índice del nodo ANTERIOR al nuevo.
     */
    public void RandomInsert(int item, int loc)
    {
        if (loc < 0)
        {
            Console.WriteLine("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        if (loc == 0)
        {
            // Insertar después del head (posición 0), es decir, en la posición 1.
            // Para ser coherentes con la implementación anterior, el loc indica el nodo previo.
            // Si loc=0, el nodo previo es el head.
            
            Node newNode = new Node(item);
            Node nextNode = head.next; // El nodo después del head

            // Nodos: A (head), B (newNode), C (nextNode)

            // 1. Conexiones de B (newNode)
            newNode.next = nextNode;
            newNode.prev = head;

            // 2. Reconexiones de A (head)
            head.next = newNode;

            // 3. Reconexiones de C (nextNode)
            nextNode.prev = newNode;

            Console.WriteLine($"\nNodo {item} insertado después de la posición {loc} (head).");
            return;
        }

        Node temp = head;
        int i = 0;

        // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        while (i < loc && temp.next != head) // El bucle se detiene ANTES de volver al head
        {
            temp = temp.next;
            i++;
        }

        // Si llegamos al final del recorrido (temp.next == head) y i no es 'loc', la posición es inválida.
        if (i != loc)
        {
            Console.WriteLine("\nNo se puede insertar. La posición está fuera de rango.");
            return;
        }

        // Si llegamos aquí, 'temp' es el nodo *anterior* donde queremos insertar.
        // Nodos: A (temp), B (newNode), C (temp.next)
        Node newNode2 = new Node(item);
        Node nextNode2 = temp.next;

        // 1. Conexiones de B (newNode2)
        newNode2.next = nextNode2;
        newNode2.prev = temp;

        // 2. Reconexiones de A (temp)
        temp.next = newNode2;

        // 3. Reconexiones de C (nextNode2)
        nextNode2.prev = newNode2;

        Console.WriteLine($"\nNodo {item} insertado después de la posición {loc}.");
    }

    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio (el head actual).
     */
    public void BeginDelete()
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía\n");
            return;
        }

        int deletedValue = head.data;

        if (head.next == head)
        {
            // Caso de un solo nodo
            head = null;
        }
        else
        {
            Node last = GetLastNode();
            
            // 1. Mover head al siguiente
            head = head.next;

            // 2. Actualizar el puntero 'prev' del nuevo head (apunta al last)
            head.prev = last;

            // 3. Actualizar el puntero 'next' del last (apunta al nuevo head)
            last.next = head;
        }
        
        Console.WriteLine($"\nNodo con valor {deletedValue} eliminado desde el principio (head) ...\n");
    }

    /**
     * Elimina el último nodo de la lista.
     */
    public void LastDelete()
    {
        if (IsEmpty())
        {
            Console.WriteLine("\nLa lista está vacía\n");
            return;
        }

        if (head.next == head)
        {
            // Caso de un solo nodo
            int deletedValue = head.data;
            head = null;
            Console.WriteLine($"\nNodo con valor {deletedValue} eliminado del final ...\n");
            return;
        }

        Node last = GetLastNode();
        int deletedValue2 = last.data;
        Node newLast = last.prev; // El nuevo último

        // 1. El nuevo último apunta al head
        newLast.next = head;

        // 2. El head apunta su 'prev' al nuevo último
        head.prev = newLast;
        
        // El Garbage Collector de C# liberará la memoria del antiguo 'last'.
        Console.WriteLine($"\nNodo con valor {deletedValue2} eliminado del final ...\n");
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param {int} loc Índice del nodo a eliminar.
     */
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

        if (loc == 0)
        {
            // Delegar en la función de eliminación del principio
            BeginDelete();
            return;
        }

        Node ptrToDelete = head;
        int i = 0;
        bool found = false;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        do
        {
            if (i == loc)
            {
                found = true;
                break;
            }
            ptrToDelete = ptrToDelete.next;
            i++;
        } while (ptrToDelete != head);


        if (!found)
        {
            Console.WriteLine("\nNo se puede eliminar. La posición está fuera de rango.\n");
            return;
        }
        
        // Si es el head, ya lo manejamos arriba (loc == 0).
        // Si es el último nodo (el nodo anterior al head), delegamos.
        if (ptrToDelete.next == head)
        {
            LastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        int deletedValue = ptrToDelete.data;
        Node prevNode = ptrToDelete.prev;
        Node nextNode = ptrToDelete.next;

        // 1. Reconexión A a C
        prevNode.next = nextNode;

        // 2. Reconexión C a A
        nextNode.prev = prevNode;

        Console.WriteLine($"\nNodo con valor {deletedValue} en la posición {loc} (índice 0-basado) eliminado.");
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param {int} item El valor a buscar.
     */
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
        string positions = "";

        do
        {
            if (ptr.data == item)
            {
                positions += $"{i} ";
                found = true;
            }
            ptr = ptr.next;
            i++;
        } while (ptr != head);

        if (found)
        {
            Console.WriteLine($"Elemento {item} encontrado en la(s) ubicación(es) (índice 0-basado): {positions.Trim()}");
        }
        else
        {
            Console.WriteLine($"Elemento {item} no encontrado\n");
        }
    }

    /**
     * Muestra todos los elementos de la lista desde head.
     */
    public void Display()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Lista vacía. Nada que imprimir.");
        }
        else
        {
            Console.WriteLine("\nImprimiendo valores (desde HEAD): ");
            Node ptr = head;
            
            do
            {
                Console.Write(ptr.data);
                
                // Mostrar la flecha si NO es el último nodo (que es el head.prev)
                if (ptr.next != head)
                {
                    Console.Write(" <-> ");
                }
                else
                {
                    // Mostrar la conexión circular
                    Console.Write(" <-> (Circular) <-> ");
                }
                
                ptr = ptr.next;
            } while (ptr != head);

            // Se imprime el head de nuevo al final para cerrar el círculo, pero lo omitimos en la lógica de la flecha.
            // Para mostrar el ciclo claramente, terminamos imprimiendo el head de nuevo.
            Console.WriteLine($"[... {head.data} (HEAD) ...]");
        }
    }
}

// Clase principal para el menú de interacción
public class Program
{
    public static void Main(string[] args)
    {
        DoublyCircularLinkedList list = new DoublyCircularLinkedList();
        int choice = 0;
        
        while (choice != 9)
        {
            Console.WriteLine("\n\n****** Menú principal (Lista Doblemente Enlazada Circular C#) ******");
            Console.WriteLine("\nElige una opción de la siguiente lista ...\n");
            Console.WriteLine("------------------------------------------");
            
            Console.WriteLine("1. Insertar al principio (nuevo head)");
            Console.WriteLine("2. Insertar al final");
            Console.WriteLine("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)");
            Console.WriteLine("4. Eliminar del principio (head)");
            Console.WriteLine("5. Eliminar desde el final");
            Console.WriteLine("6. Eliminar nodo por posición (índice 0-basado)");
            Console.WriteLine("7. Buscar un elemento");
            Console.WriteLine("8. Mostrar (recorrido circular)");
            Console.WriteLine("9. Salir");
            Console.WriteLine("------------------------------------------");
            Console.Write("\nIngrese su opción? ");
            
            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Opción inválida. Introduce un número del 1 al 9.");
                continue;
            }

            try
            {
                int item;
                int loc;

                switch (choice)
                {
                    case 1: 
                        Console.Write("\nIngrese valor: ");
                        if (int.TryParse(Console.ReadLine(), out item))
                            list.BeginInsert(item);
                        else
                            Console.WriteLine("Entrada inválida. Intente de nuevo.");
                        break;
                    case 2: 
                        Console.Write("\nIngrese valor: ");
                        if (int.TryParse(Console.ReadLine(), out item))
                            list.LastInsert(item);
                        else
                            Console.WriteLine("Entrada inválida. Intente de nuevo.");
                        break;
                    case 3: 
                        Console.Write("\nIntroduce el valor del elemento: ");
                        if (int.TryParse(Console.ReadLine(), out item))
                        {
                            Console.Write("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: ");
                            if (int.TryParse(Console.ReadLine(), out loc))
                                list.RandomInsert(item, loc);
                            else
                                Console.WriteLine("Entrada de ubicación inválida. Intente de nuevo.");
                        }
                        else
                            Console.WriteLine("Entrada de valor inválida. Intente de nuevo.");
                        break;
                    case 4: list.BeginDelete(); break;
                    case 5: list.LastDelete(); break;
                    case 6: 
                        Console.Write("\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: ");
                        if (int.TryParse(Console.ReadLine(), out loc))
                            list.RandomDelete(loc);
                        else
                            Console.WriteLine("Entrada de ubicación inválida. Intente de nuevo.");
                        break;
                    case 7: 
                        Console.Write("\nIntroduce el elemento que deseas buscar: ");
                        if (int.TryParse(Console.ReadLine(), out item))
                            list.Search(item);
                        else
                            Console.WriteLine("Entrada de valor inválida. Intente de nuevo.");
                        break;
                    case 8: list.Display(); break;
                    case 9:
                        Console.WriteLine("Saliendo del programa.");
                        break;
                    default: 
                        Console.WriteLine("Introduzca una opción válida."); 
                        break;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"\nOcurrió un error: {ex.Message}");
            }
        }
    }
}