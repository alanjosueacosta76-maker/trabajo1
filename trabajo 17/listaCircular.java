import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class listaCircular{
    // Variable global que apunta al primer nodo de la lista
    Node head = null;
    Scanner scanner = new Scanner(System.in);

    // --- Funciones de Inserción ---

    public void begin_insert() {
        System.out.println("\nIngrese valor");
        int item = scanner.nextInt();

        Node newNode = new Node(item);

        if (head == null) {
            // Lista vacía: el nuevo nodo apunta a sí mismo
            head = newNode;
            newNode.next = head;
        } else {
            // Encontrar el último nodo (el que apunta a 'head')
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            
            // 1. El nuevo nodo apunta al 'head' anterior
            newNode.next = head;
            // 2. El último nodo apunta al nuevo nodo
            temp.next = newNode;
            // 3. 'head' se actualiza al nuevo nodo
            head = newNode;
        }
        System.out.println("\nNodo insertado al principio");
    }

    public void last_insert() {
        System.out.println("\nIngrese valor");
        int item = scanner.nextInt();

        Node newNode = new Node(item);

        if (head == null) {
            // Lista vacía: el nuevo nodo es el head y apunta a sí mismo
            head = newNode;
            newNode.next = head;
        } else {
            // Encontrar el último nodo
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }

            // 1. El nuevo nodo apunta al head (cierra el círculo)
            newNode.next = head;
            // 2. El nodo que era el último ahora apunta al nuevo nodo
            temp.next = newNode;
        }
        System.out.println("\nNodo insertado al final");
    }

    public void random_insert() {
        if (head == null) {
            System.out.println("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        System.out.println("\nIntroduce el valor del elemento");
        int item = scanner.nextInt();

        System.out.println("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar ");
        int loc = scanner.nextInt();

        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo.");
            return;
        }

        Node newNode = new Node(item);
        Node temp = head;
        int i = 0;

        while (i < loc) {
            temp = temp.next;
            i++;

            if (temp == head) {
                System.out.println("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }

        // 1. El nuevo nodo apunta al siguiente del nodo actual (temp)
        newNode.next = temp.next;
        // 2. El nodo actual (temp) apunta al nuevo nodo
        temp.next = newNode;

        System.out.println("\nNodo insertado");
    }

    // --- Funciones de Eliminación ---

    public void begin_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía\n");
            return;
        }

        if (head.next == head) {
            // Caso de un solo nodo
            head = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
            return;
        }

        // Encontrar el último nodo (el que apunta a 'head')
        Node lastNode = head;
        while (lastNode.next != head) {
            lastNode = lastNode.next;
        }

        // 1. 'head' se mueve al siguiente nodo
        head = head.next;
        // 2. El último nodo apunta al nuevo 'head'
        lastNode.next = head;

        System.out.println("\nNodo eliminado desde el principio ...\n");
    }

    public void last_delete() {
        if (head == null) {
            System.out.println("\nLa lista está vacía");
            return;
        } else if (head.next == head) {
            // Caso especial: solo hay un nodo
            head = null;
            System.out.println("\nSolo se eliminó un nodo de la lista ...\n");
            return;
        }

        Node ptr = head;
        Node ptr1 = null; // ptr1 será el penúltimo

        // Recorre hasta que el siguiente nodo de 'ptr' sea 'head'
        while (ptr.next != head) {
            ptr1 = ptr;
            ptr = ptr.next;
        }

        // ptr1 es el penúltimo. 
        // 1. El penúltimo (ptr1) ahora apunta a head (cierra el círculo)
        ptr1.next = head;
        
        System.out.println("\nNodo eliminado del último ...\n");
    }

    public void random_delete() {
        if (head == null || head.next == head) {
            System.out.println("\nNo se puede eliminar en posición. La lista está vacía o tiene solo un nodo (usa eliminar al principio/final).");
            return;
        }

        System.out.println("\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n");
        int loc = scanner.nextInt();
        
        if (loc < 0) {
            System.out.println("\nLa ubicación debe ser un número positivo.");
            return;
        }

        Node ptr = head;
        int i = 0;

        while (i < loc) {
            ptr = ptr.next;
            i++;

            if (ptr == head) {
                System.out.println("\nNo se puede eliminar. La posición está fuera de rango.");
                return;
            }
        }
        
        Node nodeToDelete = ptr.next;
        
        if (nodeToDelete == head) {
            System.out.println("\nNo se recomienda eliminar la cabecera (head) con esta función. Use la Opción 4.");
            return;
        }

        // 1. 'ptr' salta al nodo siguiente del nodo a eliminar
        ptr.next = nodeToDelete.next;
        
        System.out.println("\nNodo eliminado después de la posición " + (loc + 1));
    }

    // --- Otras Funciones ---

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

        do {
            if (ptr.data == item) {
                System.out.println("Elemento encontrado en la ubicación " + (i + 1));
                found = true;
                break;
            }
            ptr = ptr.next;
            i++;
        } while (ptr != head); // El bucle se ejecuta hasta que volvemos al inicio

        if (!found) {
            System.out.println("Elemento no encontrado\n");
        }
    }

    public void display() {
        if (head == null) {
            System.out.println("Nada que imprimir");
        } else {
            System.out.println("\nImprimiendo valores . . . (Lista Circular)");
            Node ptr = head;
            StringBuilder output = new StringBuilder();
            
            do {
                output.append(ptr.data);
                ptr = ptr.next;
                if (ptr != head) {
                    output.append(" -> ");
                }
            } while (ptr != head);

            output.append(" -> (HEAD)");
            System.out.println(output.toString());
        }
    }

    // --- Función Principal ---

    public static void main(String[] args) {
        listaCircular list = new listaCircular();
        int choice = 0;

        while (choice != 9) {
            System.out.println("\n\n******Menú principal (Lista Circular)******");
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
                case 1: list.begin_insert(); break;
                case 2: list.last_insert(); break;
                case 3: list.random_insert(); break;
                case 4: list.begin_delete(); break;
                case 5: list.last_delete(); break;
                case 6: list.random_delete(); break;
                case 7: list.search(); break;
                case 8: list.display(); break;
                case 9:
                    System.out.println("Saliendo del programa.");
                    break;
                default: System.out.println("Introduzca una opción válida..");
            }
        }
        list.scanner.close();
    }
}