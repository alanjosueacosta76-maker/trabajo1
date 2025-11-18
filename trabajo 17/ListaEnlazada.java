import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class ListaEnlazada {
    // Variable global que apunta al primer nodo de la lista
    Node head = null;
    Scanner scanner = new Scanner(System.in);

    // Función para insertar un nuevo nodo al principio de la lista
    public void begin_insert() {
        System.out.println("\nIngrese valor");
        int item = scanner.nextInt();

        Node newNode = new Node(item);

        // El 'new' en Java maneja la asignación de memoria
        // No hay riesgo de OVERFLOW en este contexto a menos que la memoria total del sistema se agote

        newNode.next = head;
        head = newNode;
        System.out.println("\nNodo insertado");
    }

    // Función para insertar un nodo al final de la lista
    public void last_insert() {
        System.out.println("\nIngrese valor");
        int item = scanner.nextInt();

        Node newNode = new Node(item);

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        System.out.println("\nNodo insertado");
    }

    // Función para Insertar un nodo en una posición específica de la lista
    public void random_insert() {
        if (head == null) {
            System.out.println("\nLista vacía. No se puede insertar en posición.");
            return;
        }

        System.out.println("\nIntroduce el valor del elemento");
        int item = scanner.nextInt();

        System.out.println("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar ");
        int loc = scanner.nextInt();

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        for (i = 0; i < loc; i++) {
            temp = temp.next;

            if (temp == null) {
                System.out.println("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }

        newNode.next = temp.next;
        temp.next = newNode;
        System.out.println("\nNodo insertado");
    }

    // Función para eliminar el primer nodo de la lista
    public void begin_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía\n");
        } else {
            // El recolector de basura de Java se encarga de liberar el nodo
            head = head.next;
            System.out.println("\nNodo eliminado desde el principio ...\n");
        }
    }

    // Función para eliminar el último nodo de la lista
    public void last_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía");
        } else if (head.next == null) {
            head = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
        } else {
            Node ptr = head;
            Node ptr1 = null; // ptr1 es el penúltimo nodo
            while (ptr.next != null) {
                ptr1 = ptr;
                ptr = ptr.next;
            }
            ptr1.next = null;
            // El nodo 'ptr' (el último) será liberado por el recolector de basura
            System.out.println("\nNodo eliminado del último ...\n");
        }
    }

    // Función para eliminar un nodo después de una posición específica
    public void random_delete() {
        if (head == null) {
            System.out.println("\nLista vacía. No se puede eliminar.");
            return;
        }
        
        System.out.println("\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n");
        int loc = scanner.nextInt();

        Node ptr = head;
        Node ptr1 = null;
        int i = 0;

        for (i = 0; i < loc; i++) {
            ptr1 = ptr;
            ptr = ptr.next;

            if (ptr == null || ptr.next == null) {
                System.out.println("\nNo se puede eliminar. La posición está fuera de rango o el nodo a eliminar no existe.");
                return;
            }
        }

        Node nodeToDelete = ptr.next; // Nodo a eliminar (la posición 'loc' en C++ es el nodo anterior)
        ptr.next = nodeToDelete.next; // Reconecta el nodo anterior con el siguiente del nodo eliminado
        // El recolector de basura se encarga de 'nodeToDelete'
        System.out.println("\nNodo eliminado después de la posición " + (loc + 1));
    }

    // Función para buscar un elemento en la lista y mostrar su posición
    public void search() {
        if (head == null) {
            System.out.println("\nLista vacia\n");
            return;
        }

        System.out.println("\nIntroduce el elemento que deseas buscar?\n");
        int item = scanner.nextInt();

        Node ptr = head;
        int i = 0;
        boolean found = false;

        while (ptr != null) {
            if (ptr.data == item) {
                System.out.println("Elemento encontrado en la ubicación " + (i + 1));
                found = true;
                break;
            }
            ptr = ptr.next;
            i++;
        }

        if (!found) {
            System.out.println("Elemento no encontrado\n");
        }
    }

    // Función para mostrar todos los elementos de la lista
    public void display() {
        if (head == null) {
            System.out.println("Nada que imprimir");
        } else {
            System.out.println("\nImprimiendo valores . . .");
            Node ptr = head;
            while (ptr != null) {
                System.out.println("\n" + ptr.data);
                ptr = ptr.next;
            }
        }
    }

    // Función principal
    public static void main(String[] args) {
        ListaEnlazada list = new ListaEnlazada();
        int choice = 0;

        while (choice != 9) {
            System.out.println("\n\n******Menú principal******");
            System.out.println("\nElige una opción de la siguiente lista ...");
            System.out.println("\n------------------------------------------");

            System.out.println("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
                    + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
            System.out.println("Ingrese su opción?");
            
            try {
                choice = list.scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Opción inválida. Introduce un número del 1 al 9.");
                list.scanner.next(); // Limpia el buffer
                continue;
            }

            switch (choice) {
                case 1:
                    list.begin_insert();
                    break;
                case 2:
                    list.last_insert();
                    break;
                case 3:
                    list.random_insert();
                    break;
                case 4:
                    list.begin_delete();
                    break;
                case 5:
                    list.last_delete();
                    break;
                case 6:
                    list.random_delete();
                    break;
                case 7:
                    list.search();
                    break;
                case 8:
                    list.display();
                    break;
                case 9:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.out.println("Introduzca una opción válida..");
            }
        }
        list.scanner.close();
    }
}