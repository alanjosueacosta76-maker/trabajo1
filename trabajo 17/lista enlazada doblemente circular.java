import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Clase principal que contiene la implementación de la Lista Doblemente Enlazada Circular
 * y el menú de interacción en la consola.
 */
public class DoublyCircularLinkedListApp {

    /**
     * Clase para representar un nodo en la lista doblemente enlazada.
     * Contiene el dato, y referencias al nodo siguiente y anterior.
     */
    class Node {
        int data;
        Node next; // Referencia al siguiente nodo
        Node prev; // Referencia al nodo anterior

        public Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    private Node head; // Referencia al primer nodo (cabeza)

    public DoublyCircularLinkedListApp() {
        this.head = null;
    }

    /**
     * Verifica si la lista está vacía.
     * @return true si la cabeza es null.
     */
    public boolean isEmpty() {
        return head == null;
    }

    /**
     * Encuentra y devuelve el último nodo de la lista.
     * En una lista doblemente enlazada circular no vacía, el último nodo es siempre head.prev.
     * @return El último nodo o null si la lista está vacía.
     */
    private Node getLastNode() {
        if (isEmpty()) {
            return null;
        }
        return head.prev;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio (antes del head).
     * @param item El valor a insertar.
     */
    public void beginInsert(int item) {
        Node newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            // En una lista circular de un solo nodo, apunta a sí mismo
            head.next = head;
            head.prev = head;
        } else {
            Node last = getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode.next = head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            head.prev = newNode;
            last.next = newNode;

            // 3. Mover la cabeza al nuevo nodo
            head = newNode;
        }

        System.out.println("\nNodo " + item + " insertado al principio (nuevo head).");
    }

    /**
     * Inserta un nodo al final.
     * @param item El valor a insertar.
     */
    public void lastInsert(int item) {
        Node newNode = new Node(item);

        if (isEmpty()) {
            // Reutilizamos la lógica del primer elemento
            head = newNode;
            head.next = head;
            head.prev = head;
        } else {
            Node last = getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode.next = head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            last.next = newNode;
            head.prev = newNode;
        }

        System.out.println("\nNodo " + item + " insertado al final.");
    }

    /**
     * Inserta un nodo DESPUÉS del nodo en la posición (índice 0-basado) dada 'loc'.
     * @param item El valor a insertar.
     * @param loc La posición del nodo ANTERIOR al nuevo.
     */
    public void randomInsert(int item, int loc) {
        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        if (isEmpty()) {
            System.out.println("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }
        
        // 1. Encontrar el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        Node prevNode = head;
        int count = 0;

        // Caso especial: si loc es el índice del último nodo, insertamos al final.
        // Pero primero recorremos hasta 'loc'.
        while (count < loc) {
            prevNode = prevNode.next;
            count++;
            
            // Si damos la vuelta al círculo antes de alcanzar 'loc'
            if (prevNode == head && count <= loc) {
                System.out.println("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }
        
        // Si 'prevNode.next' es 'head' y 'count' es la posición 'loc', estamos en el último nodo.
        // En este caso, randomInsert(item, N-1) donde N es el tamaño, es equivalente a lastInsert(item).
        if (prevNode.next == head && count == loc) {
            lastInsert(item); // Reutilizar la función de inserción al final
            return;
        }
        
        // Si la lista no es de un solo elemento y el índice 'loc' está fuera de rango
        if (prevNode == head && loc > 0) {
            System.out.println("\nNo se puede insertar. La posición está fuera de rango.");
            return;
        }
        
        // Caso intermedio:
        // Nodos: A (prevNode), B (newNode), C (prevNode.next)
        Node newNode = new Node(item);
        Node nextNode = prevNode.next;

        // Conexiones: B <-> A
        newNode.prev = prevNode;
        prevNode.next = newNode;

        // Conexiones: B <-> C
        newNode.next = nextNode;
        nextNode.prev = newNode;

        System.out.println("\nNodo " + item + " insertado después de la posición " + loc + ".");
    }

    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio (el head actual).
     */
    public void beginDelete() {
        if (isEmpty()) {
            System.out.println("\nLa lista está vacía");
            return;
        }

        int deletedValue = head.data;

        if (head.next == head) {
            // Caso de un solo nodo
            head = null;
        } else {
            Node last = getLastNode();
            
            // 1. Mover head al siguiente
            head = head.next;

            // 2. Actualizar la conexión circular (last <-> new head)
            head.prev = last;
            last.next = head;
        }

        System.out.println("\nNodo con valor " + deletedValue + " eliminado desde el principio (head) ...");
    }

    /**
     * Elimina el último nodo de la lista.
     */
    public void lastDelete() {
        if (isEmpty()) {
            System.out.println("\nLa lista está vacía");
            return;
        }

        if (head.next == head) {
            // Caso de un solo nodo
            int deletedValue = head.data;
            head = null;
            System.out.println("\nNodo con valor " + deletedValue + " eliminado del final ...");
            return;
        }

        Node last = getLastNode(); // Nodo a eliminar
        int deletedValue = last.data;
        Node newLast = last.prev; // El nuevo último

        // 1. El nuevo último apunta al head
        newLast.next = head;

        // 2. El head apunta su 'prev' al nuevo último
        head.prev = newLast;
        
        // Opcional: Desvincular el nodo eliminado (Java lo maneja con GC, pero es buena práctica en teoría de listas)
        last.next = null;
        last.prev = null;

        System.out.println("\nNodo con valor " + deletedValue + " eliminado del final ...");
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param loc La posición (índice 0-basado) a eliminar.
     */
    public void randomDelete(int loc) {
        if (isEmpty()) {
            System.out.println("\nLista vacía. No se puede eliminar.");
            return;
        }

        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        if (loc == 0) {
            // Delegar en la función de eliminación del principio
            beginDelete();
            return;
        }
        
        Node ptrToDelete = head;
        int count = 0;
        boolean found = false;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        do {
            if (count == loc) {
                found = true;
                break;
            }
            
            ptrToDelete = ptrToDelete.next;
            count++;

        } while (ptrToDelete != head);

        if (!found) {
            System.out.println("\nNo se puede eliminar. La posición está fuera de rango.");
            return;
        }
            
        // Si es el último nodo (el nodo anterior al head), delegamos en lastDelete
        if (ptrToDelete.next == head) {
            lastDelete();
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
        
        // Opcional: Desvincular el nodo eliminado
        ptrToDelete.next = null;
        ptrToDelete.prev = null;

        System.out.println("\nNodo con valor " + deletedValue + " en la posición " + loc + " (índice 0-basado) eliminado.");
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param item El valor a buscar.
     */
    public void search(int item) {
        if (isEmpty()) {
            System.out.println("\nLista vacía");
            return;
        }

        Node ptr = head;
        int index = 0;
        boolean found = false;
        StringBuilder positions = new StringBuilder();

        // Recorrido circular
        do {
            if (ptr.data == item) {
                positions.append(index).append(" ");
                found = true;
            }
            
            ptr = ptr.next;
            index++;
            
        } while (ptr != head);

        if (found) {
            System.out.println("Elemento " + item + " encontrado en la(s) ubicación(es) (índice 0-basado): " + positions.toString().trim());
        } else {
            System.out.println("Elemento " + item + " no encontrado");
        }
    }

    /**
     * Muestra todos los elementos de la lista desde head.
     */
    public void display() {
        if (isEmpty()) {
            System.out.println("Lista vacía. Nada que imprimir.");
        } else {
            System.out.println("\nImprimiendo valores (desde HEAD): ");
            Node ptr = head;
            StringBuilder output = new StringBuilder();
            
            // Recorrido circular
            do {
                output.append(ptr.data);
                
                // Mostrar la conexión
                if (ptr.next != head) {
                    output.append(" <-> ");
                } else {
                    // Mostrar la conexión circular
                    output.append(" <-> (Circular) <-> ");
                }

                ptr = ptr.next;
                
            } while (ptr != head);

            // Imprimir el head de nuevo para cerrar el círculo visualmente
            output.append("[... ").append(head.data).append(" (HEAD) ...]");
            System.out.println(output.toString());
        }
    }

    // Función principal para el menú de interacción
    public static void main(String[] args) {
        DoublyCircularLinkedListApp listInstance = new DoublyCircularLinkedListApp();
        Scanner scanner = new Scanner(System.in);
        int choice = 0;
        
        System.out.println("Iniciando Lista Doblemente Enlazada Circular...");
        
        while (choice != 9) {
            try {
                System.out.println("\n\n Menú principal (Lista Doblemente Enlazada Circular) ");
                System.out.println("\nElige una opción de la siguiente lista ...\n");
                System.out.println("------------------------------------------");
                
                System.out.println("1. Insertar al principio (nuevo head)");
                System.out.println("2. Insertar al final");
                System.out.println("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)");
                System.out.println("4. Eliminar del principio (head)");
                System.out.println("5. Eliminar desde el final");
                System.out.println("6. Eliminar nodo por posición (índice 0-basado)");
                System.out.println("7. Buscar un elemento");
                System.out.println("8. Mostrar (recorrido circular)");
                System.out.println("9. Salir");
                System.out.println("------------------------------------------");
                
                System.out.print("\nIngrese su opción? ");
                choice = scanner.nextInt();

                if (choice == 9) {
                    System.out.println("Saliendo del programa.");
                    break;
                }

                if (choice < 1 || choice > 8) {
                    System.out.println("Introduzca una opción válida (1-9).");
                    continue;
                }

                Integer item = null;
                Integer loc = null;

                if (choice == 1 || choice == 2 || choice == 3 || choice == 7) { 
                    // Requieren un valor (item)
                    System.out.print("\nIngrese el valor (entero) del elemento: ");
                    item = scanner.nextInt();
                }

                if (choice == 3 || choice == 6) { 
                    // Requieren una posición (loc)
                    System.out.print("Introduce la ubicación (índice 0-basado): ");
                    loc = scanner.nextInt();
                }

                switch (choice) {
                    case 1:
                        listInstance.beginInsert(item);
                        break;
                    case 2:
                        listInstance.lastInsert(item);
                        break;
                    case 3:
                        listInstance.randomInsert(item, loc);
                        break;
                    case 4:
                        listInstance.beginDelete();
                        break;
                    case 5:
                        listInstance.lastDelete();
                        break;
                    case 6:
                        listInstance.randomDelete(loc);
                        break;
                    case 7:
                        listInstance.search(item);
                        break;
                    case 8:
                        listInstance.display();
                        break;
                    default:
                        // No debería llegar aquí debido a la verificación previa
                        System.out.println("Opción inválida.");
                        break;
                }

            } catch (InputMismatchException e) {
                // Maneja cuando el usuario ingresa texto en lugar de un número
                System.out.println("\nEntrada inválida. Por favor, ingrese un número entero para la opción/valor/ubicación.");
                scanner.next(); // Consume la entrada incorrecta para evitar un bucle infinito
            } catch (Exception e) {
                System.out.println("\nOcurrió un error inesperado: " + e.getMessage());
                // En un caso real, aquí se imprimiría e.printStackTrace();
            }
        }
        scanner.close(); // Cerrar el scanner al salir del bucle principal
    }
}