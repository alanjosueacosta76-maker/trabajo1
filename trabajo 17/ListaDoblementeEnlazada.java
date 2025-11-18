import java.util.Scanner;

/**
 * Clase para representar cada nodo de la lista doblemente enlazada.
 */
class Node {
    public int data;
    public Node next; // Referencia al siguiente nodo
    public Node prev; // Referencia al nodo anterior

    /**
     * Constructor para inicializar un nodo.
     * @param data El valor a almacenar en el nodo.
     */
    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

/**
 * Clase que contiene la lógica de la Lista Doblemente Enlazada.
 */
class DoublyLinkedList {
    private Node head = null; // La cabeza de la lista

    /**
     * Verifica si la lista está vacía.
     * @return true si la lista no contiene nodos, false en caso contrario.
     */
    public boolean isEmpty() {
        return head == null;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio de la lista.
     * @param item El valor a insertar.
     */
    public void beginInsert(int item) {
        Node newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
        } else {
            // 1. El nuevo nodo apunta al head actual
            newNode.next = head;
            
            // 2. El head actual apunta su 'prev' al nuevo nodo
            head.prev = newNode;
            
            // 3. El nuevo nodo se convierte en el head
            head = newNode;
        }
        System.out.println("\nNodo " + item + " insertado al principio");
    }

    /**
     * Inserta un nodo al final de la lista.
     * @param item El valor a insertar.
     */
    public void lastInsert(int item) {
        Node newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
        } else {
            // Encontrar el último nodo
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }

            // Conexiones:
            temp.next = newNode; // El antiguo último apunta al nuevo
            newNode.prev = temp; // El nuevo apunta su 'prev' al antiguo último
        }
        System.out.println("\nNodo " + item + " insertado al final");
    }

    /**
     * Inserta un nodo después de una posición (índice 0-basado) dada.
     * @param item El valor a insertar.
     * @param loc Índice del nodo ANTERIOR al nuevo.
     */
    public void randomInsert(int item, int loc) {
        if (isEmpty()) {
            System.out.println("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        while (i < loc && temp != null) {
            temp = temp.next;
            i++;
        }

        // Si 'temp' es null, es que la posición 'loc' estaba fuera de los límites
        if (temp == null || i != loc) {
            System.out.println("\nNo se puede insertar. La posición está fuera de rango.");
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
        if (nextNode != null) {
            nextNode.prev = newNode;
        }

        System.out.println("\nNodo " + item + " insertado después de la posición " + loc + " (índice 0-basado).");
    }

    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio de la lista.
     */
    public void beginDelete() {
        if (isEmpty()) {
            System.out.println("\nLa lista está vacía\n");
            return;
        }

        if (head.next == null) {
            // Caso de un solo nodo
            head = null;
        } else {
            // Caso de múltiples nodos
            head = head.next; // Mover head al siguiente
            head.prev = null; // El nuevo head tiene 'prev' null
        }
        
        System.out.println("\nNodo eliminado desde el principio ...\n");
    }

    /**
     * Elimina el último nodo de la lista.
     */
    public void lastDelete() {
        if (isEmpty()) {
            System.out.println("\nLa lista está vacía\n");
            return;
        }

        Node ptrToDelete = head;

        if (head.next == null) {
            // Caso de un solo nodo
            head = null;
        } else {
            // Recorrer hasta el último nodo
            while (ptrToDelete.next != null) {
                ptrToDelete = ptrToDelete.next;
            }
            
            // El penúltimo nodo (ptrToDelete.prev) debe apuntar su 'next' a null
            ptrToDelete.prev.next = null;
        }
        
        System.out.println("\nNodo eliminado del final ...\n");
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param loc Índice del nodo a eliminar.
     */
    public void randomDelete(int loc) {
        if (isEmpty()) {
            System.out.println("\nLista vacía. No se puede eliminar.\n");
            return;
        }

        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo.\n");
            return;
        }

        Node ptrToDelete = head;
        int i = 0;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        while (i < loc && ptrToDelete != null) {
            ptrToDelete = ptrToDelete.next;
            i++;
        }

        if (ptrToDelete == null) {
            System.out.println("\nNo se puede eliminar. La posición está fuera de rango.\n");
            return;
        }
        
        // Si es el primer nodo
        if (loc == 0) {
            beginDelete();
            return;
        }
        
        // Si es el último nodo
        if (ptrToDelete.next == null) {
            lastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        Node prevNode = ptrToDelete.prev;
        Node nextNode = ptrToDelete.next;

        // 1. Reconexión A a C
        prevNode.next = nextNode;

        // 2. Reconexión C a A
        nextNode.prev = prevNode;

        System.out.println("\nNodo en la posición " + loc + " (índice 0-basado) eliminado.");
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param item El valor a buscar.
     */
    public void search(int item) {
        if (isEmpty()) {
            System.out.println("\nLista vacia\n");
            return;
        }

        Node ptr = head;
        int i = 0; 
        boolean found = false;

        while (ptr != null) {
            if (ptr.data == item) {
                System.out.println("Elemento " + item + " encontrado en la ubicación (índice 0-basado) " + i);
                found = true;
                break;
            }
            ptr = ptr.next;
            i++;
        }

        if (!found) {
            System.out.println("Elemento " + item + " no encontrado\n");
        }
    }

    /**
     * Muestra todos los elementos de la lista de head a end.
     */
    public void display() {
        if (isEmpty()) {
            System.out.println("Nada que imprimir");
        } else {
            System.out.println("\nImprimiendo valores (HEAD a END): ");
            Node ptr = head;
            
            while (ptr != null) {
                System.out.print(ptr.data);
                if (ptr.next != null) {
                    System.out.print(" <-> ");
                }
                ptr = ptr.next;
            }
            System.out.println();
        }
    }
}

/**
 * Clase principal para el menú de interacción.
 */
public class ListaDoblementeEnlazada { // Nombre de la clase principal
    // NOTA IMPORTANTE: El punto de entrada en Java DEBE llamarse 'main'.
    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        Scanner scanner = new Scanner(System.in);
        int choice = 0;
        
        while (choice != 9) {
            System.out.println("\n\n****** Menú principal (Lista Doblemente Enlazada Java) ******");
            System.out.println("\nElige una opción de la siguiente lista ...\n");
            System.out.println("------------------------------------------");
            
            System.out.println("1. Insertar al principio");
            System.out.println("2. Insertar al final");
            System.out.println("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)");
            System.out.println("4. Eliminar del principio");
            System.out.println("5. Eliminar desde el final");
            System.out.println("6. Eliminar nodo por posición (índice 0-basado)");
            System.out.println("7. Buscar un elemento");
            System.out.println("8. Mostrar");
            System.out.println("9. Salir");
            System.out.println("------------------------------------------");

            System.out.print("\nIngrese su opción? ");
            
            try {
                if (scanner.hasNextInt()) {
                    choice = scanner.nextInt();
                    scanner.nextLine(); 
                } else {
                    String input = scanner.nextLine(); 
                    if (input.trim().isEmpty() && choice != 0) {
                        continue;
                    }
                    choice = 0;
                    System.out.println("Opción inválida. Introduce un número del 1 al 9.");
                    continue;
                }

                if (choice == 9) {
                    System.out.println("Saliendo del programa.");
                    break;
                }
                
                int item;
                int loc;

                switch (choice) {
                    case 1:
                        System.out.print("\nIngrese valor: ");
                        if (scanner.hasNextInt()) {
                            item = scanner.nextInt();
                            scanner.nextLine();
                            list.beginInsert(item);
                        } else {
                            System.out.println("Entrada de valor inválida. Debe ser un número entero.");
                            scanner.nextLine(); 
                        }
                        break;
                    case 2:
                        System.out.print("\nIngrese valor: ");
                        if (scanner.hasNextInt()) {
                            item = scanner.nextInt();
                            scanner.nextLine();
                            list.lastInsert(item);
                        } else {
                            System.out.println("Entrada de valor inválida. Debe ser un número entero.");
                            scanner.nextLine();
                        }
                        break;
                    case 3:
                        System.out.print("\nIntroduce el valor del elemento: ");
                        if (scanner.hasNextInt()) {
                            item = scanner.nextInt();
                            scanner.nextLine();
                            System.out.print("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: ");
                            if (scanner.hasNextInt()) {
                                loc = scanner.nextInt();
                                scanner.nextLine();
                                list.randomInsert(item, loc);
                            } else {
                                System.out.println("Entrada de ubicación inválida. Debe ser un número entero.");
                                scanner.nextLine();
                            }
                        } else {
                            System.out.println("Entrada de valor inválida. Debe ser un número entero.");
                            scanner.nextLine();
                        }
                        break;
                    case 4: 
                        list.beginDelete(); 
                        break;
                    case 5: 
                        list.lastDelete(); 
                        break;
                    case 6:
                        System.out.print("\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: ");
                        if (scanner.hasNextInt()) {
                            loc = scanner.nextInt();
                            scanner.nextLine();
                            list.randomDelete(loc);
                        } else {
                            System.out.println("Entrada de ubicación inválida. Debe ser un número entero.");
                            scanner.nextLine();
                        }
                        break;
                    case 7:
                        System.out.print("\nIntroduce el elemento que deseas buscar: ");
                        if (scanner.hasNextInt()) {
                            item = scanner.nextInt();
                            scanner.nextLine();
                            list.search(item);
                        } else {
                            System.out.println("Entrada de valor inválida. Debe ser un número entero.");
                            scanner.nextLine();
                        }
                        break;
                    case 8: 
                        list.display(); 
                        break;
                    default:
                        System.out.println("Introduzca una opción válida (1-9).");
                }
                
            } catch (Exception e) {
                System.out.println("\nOcurrió un error inesperado. " + e.getMessage());
                if (scanner.hasNextLine()) {
                    scanner.nextLine();
                }
            }
        }
        scanner.close();
    }
}