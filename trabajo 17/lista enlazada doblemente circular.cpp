#include <iostream>
#include <cstdlib>

// Definición de la estructura o clase para cada nodo
class Node {
public:
    int data;
    Node* next; // Puntero al siguiente nodo
    Node* prev; // Puntero al nodo anterior

    // Constructor
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Clase que contiene la lógica de la Lista Doblemente Enlazada Circular
class DoublyCircularLinkedList {
private:
    Node* head = nullptr; // Puntero al primer nodo

    /**
     * Encuentra y devuelve el último nodo de la lista.
     * En una lista circular, este es el nodo cuyo 'next' apunta al 'head'.
     * @return Node* El último nodo o nullptr si la lista está vacía.
     */
    Node* getLastNode() {
        if (isEmpty()) {
            return nullptr;
        }
        // En una lista doblemente enlazada circular, el nodo anterior al head es el último.
        return head->prev;
    }

public:
    // Destructor para liberar toda la memoria al final del programa
    ~DoublyCircularLinkedList() {
        if (isEmpty()) return;

        Node* current = head->next;
        Node* last = head;

        // Romper el círculo para recorrer de forma segura
        last->prev->next = nullptr;
        
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        
        // El head es el último que queda, si no ha sido borrado en el bucle
        if (head != nullptr) {
            delete head;
        }
        head = nullptr;
    }

    /**
     * Verifica si la lista está vacía.
     * @return bool true si la lista no contiene nodos.
     */
    bool isEmpty() {
        return head == nullptr;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio (antes del head).
     * @param item El valor a insertar.
     */
    void beginInsert(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            head = newNode;
            // En una lista circular de un solo nodo, apunta a sí mismo
            head->next = head;
            head->prev = head;
        } else {
            Node* last = getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode->next = head;
            newNode->prev = last;

            // 2. Reconexiones de los nodos existentes
            head->prev = newNode;
            last->next = newNode;

            // 3. Mover la cabeza al nuevo nodo
            head = newNode;
        }
        std::cout << "\nNodo " << item << " insertado al principio (nuevo head)." << std::endl;
    }

    /**
     * Inserta un nodo al final (antes del head).
     * @param item El valor a insertar.
     */
    void lastInsert(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            // Reutilizamos la lógica del primer elemento
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode->next = head;
            newNode->prev = last;

            // 2. Reconexiones de los nodos existentes
            last->next = newNode;
            head->prev = newNode;
        }
        std::cout << "\nNodo " << item << " insertado al final." << std::endl;
    }

    /**
     * Inserta un nodo en una posición (índice 0-basado) dada, DESPUÉS del nodo en 'loc'.
     * @param item El valor a insertar.
     * @param loc Índice del nodo ANTERIOR al nuevo.
     */
    void randomInsert(int item, int loc) {
        if (loc < 0) {
            std::cout << "\nLa ubicación debe ser un número positivo o cero." << std::endl;
            return;
        }

        if (isEmpty()) {
            std::cout << "\nLa lista está vacía. Use insertar al principio/final." << std::endl;
            return;
        }

        Node* temp = head;
        int i = 0;

        // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        // Usamos un bucle do-while o un contador para manejar la lista circular.
        do {
            if (i == loc) {
                break; // 'temp' es el nodo previo (posición 'loc')
            }
            temp = temp->next;
            i++;
        } while (temp != head && i <= loc);

        // Si llegamos a 'head' antes de 'loc' (y loc > 0), la posición está fuera de rango
        if (temp == head && i < loc) {
            std::cout << "\nNo se puede insertar. La posición está fuera de rango." << std::endl;
            return;
        }
        
        // Caso: Si temp es el último nodo y loc es su índice, insertamos al final.
        if (temp->next == head && i == loc) {
            lastInsert(item);
            return;
        }

        // Si llegamos aquí, 'temp' es el nodo *anterior* donde queremos insertar.
        // Nodos: A (temp), B (newNode), C (temp->next)
        Node* newNode = new Node(item);
        Node* nextNode = temp->next;

        // 1. Conexiones de B (newNode)
        newNode->next = nextNode;
        newNode->prev = temp;

        // 2. Reconexiones de A (temp)
        temp->next = newNode;

        // 3. Reconexiones de C (nextNode)
        nextNode->prev = newNode;

        std::cout << "\nNodo " << item << " insertado después de la posición " << loc << "." << std::endl;
    }

    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio (el head actual).
     */
    void beginDelete() {
        if (isEmpty()) {
            std::cout << "\nLa lista está vacía" << std::endl;
            return;
        }

        int deletedValue = head->data;

        if (head->next == head) {
            // Caso de un solo nodo
            delete head;
            head = nullptr;
        } else {
            Node* last = getLastNode();
            Node* oldHead = head;
            
            // 1. Mover head al siguiente
            head = head->next;

            // 2. Actualizar el puntero 'prev' del nuevo head (apunta al last)
            head->prev = last;

            // 3. Actualizar el puntero 'next' del last (apunta al nuevo head)
            last->next = head;

            // 4. Liberar la memoria del antiguo head
            delete oldHead;
        }
        
        std::cout << "\nNodo con valor " << deletedValue << " eliminado desde el principio (head) ...\n" << std::endl;
    }

    /**
     * Elimina el último nodo de la lista.
     */
    void lastDelete() {
        if (isEmpty()) {
            std::cout << "\nLa lista está vacía\n" << std::endl;
            return;
        }

        if (head->next == head) {
            // Caso de un solo nodo
            int deletedValue = head->data;
            delete head;
            head = nullptr;
            std::cout << "\nNodo con valor " << deletedValue << " eliminado del final ...\n" << std::endl;
            return;
        }

        Node* last = getLastNode(); // Nodo a eliminar
        int deletedValue2 = last->data;
        Node* newLast = last->prev; // El nuevo último

        // 1. El nuevo último apunta al head
        newLast->next = head;

        // 2. El head apunta su 'prev' al nuevo último
        head->prev = newLast;
        
        // 3. Liberar la memoria del antiguo 'last'
        delete last;

        std::cout << "\nNodo con valor " << deletedValue2 << " eliminado del final ...\n" << std::endl;
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param loc Índice del nodo a eliminar.
     */
    void randomDelete(int loc) {
        if (isEmpty()) {
            std::cout << "\nLista vacía. No se puede eliminar.\n" << std::endl;
            return;
        }

        if (loc < 0) {
            std::cout << "\nLa ubicación debe ser un número positivo.\n" << std::endl;
            return;
        }

        if (loc == 0) {
            // Delegar en la función de eliminación del principio
            beginDelete();
            return;
        }
        
        Node* ptrToDelete = head;
        int i = 0;
        bool found = false;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        do {
            if (i == loc) {
                found = true;
                break;
            }
            ptrToDelete = ptrToDelete->next;
            i++;
        } while (ptrToDelete != head);

        if (!found) {
            std::cout << "\nNo se puede eliminar. La posición está fuera de rango.\n" << std::endl;
            return;
        }
        
        // Si es el head, ya lo manejamos (loc == 0).
        // Si es el último nodo (el nodo anterior al head), delegamos en LastDelete
        if (ptrToDelete->next == head) {
            lastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        int deletedValue = ptrToDelete->data;
        Node* prevNode = ptrToDelete->prev;
        Node* nextNode = ptrToDelete->next;

        // 1. Reconexión A a C
        prevNode->next = nextNode;

        // 2. Reconexión C a A
        nextNode->prev = prevNode;
        
        // 3. Liberar la memoria
        delete ptrToDelete;

        std::cout << "\nNodo con valor " << deletedValue << " en la posición " << loc << " (índice 0-basado) eliminado." << std::endl;
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param item El valor a buscar.
     */
    void search(int item) {
        if (isEmpty()) {
            std::cout << "\nLista vacia\n" << std::endl;
            return;
        }

        Node* ptr = head;
        int i = 0; 
        bool found = false;
        std::string positions = "";

        do {
            if (ptr->data == item) {
                positions += std::to_string(i) + " ";
                found = true;
            }
            ptr = ptr->next;
            i++;
        } while (ptr != head);

        if (found) {
            std::cout << "Elemento " << item << " encontrado en la(s) ubicación(es) (índice 0-basado): " << positions << std::endl;
        } else {
            std::cout << "Elemento " << item << " no encontrado\n" << std::endl;
        }
    }

    /**
     * Muestra todos los elementos de la lista desde head.
     */
    void display() {
        if (isEmpty()) {
            std::cout << "Lista vacía. Nada que imprimir." << std::endl;
        } else {
            std::cout << "\nImprimiendo valores (desde HEAD): " << std::endl;
            Node* ptr = head;
            
            do {
                std::cout << ptr->data;
                
                // Mostrar la flecha si NO es el último nodo
                if (ptr->next != head) {
                    std::cout << " <-> ";
                } else {
                    // Mostrar la conexión circular
                    std::cout << " <-> (Circular) <-> ";
                }
                
                ptr = ptr->next;
            } while (ptr != head);

            // Imprimir el head de nuevo para cerrar el círculo visualmente
            std::cout << "[... " << head->data << " (HEAD) ...]" << std::endl;
        }
    }
};

// Función principal para el menú de interacción
int main() {
    // Para asegurar que los mensajes de std::cout se muestren inmediatamente
    std::ios_base::sync_with_stdio(false); 

    DoublyCircularLinkedList list;
    int choice = 0;
    
    while (choice != 9) {
        std::cout << "\n\n Menú principal (Lista Doblemente Enlazada Circular ) " << std::endl;
        std::cout << "\nElige una opción de la siguiente lista ...\n" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        
        std::cout << "1. Insertar al principio (nuevo head)" << std::endl;
        std::cout << "2. Insertar al final" << std::endl;
        std::cout << "3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)" << std::endl;
        std::cout << "4. Eliminar del principio (head)" << std::endl;
        std::cout << "5. Eliminar desde el final" << std::endl;
        std::cout << "6. Eliminar nodo por posición (índice 0-basado)" << std::endl;
        std::cout << "7. Buscar un elemento" << std::endl;
        std::cout << "8. Mostrar (recorrido circular)" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\nIngrese su opción? ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Opción inválida. Introduce un número del 1 al 9." << std::endl;
            // Limpiar buffer de entrada en caso de error
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        try {
            int item;
            int loc;

            switch (choice) {
                case 1: 
                    std::cout << "\nIngrese valor: ";
                    if (std::cin >> item)
                        list.beginInsert(item);
                    else
                        std::cout << "Entrada inválida. Intente de nuevo.";
                    break;
                case 2: 
                    std::cout << "\nIngrese valor: ";
                    if (std::cin >> item)
                        list.lastInsert(item);
                    else
                        std::cout << "Entrada inválida. Intente de nuevo.";
                    break;
                case 3: 
                    std::cout << "\nIntroduce el valor del elemento: ";
                    if (std::cin >> item) {
                        std::cout << "\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: ";
                        if (std::cin >> loc)
                            list.randomInsert(item, loc);
                        else
                            std::cout << "Entrada de ubicación inválida. Intente de nuevo.";
                    } else {
                        std::cout << "Entrada de valor inválida. Intente de nuevo.";
                    }
                    break;
                case 4: list.beginDelete(); break;
                case 5: list.lastDelete(); break;
                case 6: 
                    std::cout << "\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: ";
                    if (std::cin >> loc)
                        list.randomDelete(loc);
                    else
                        std::cout << "Entrada de ubicación inválida. Intente de nuevo.";
                    break;
                case 7: 
                    std::cout << "\nIntroduce el elemento que deseas buscar: ";
                    if (std::cin >> item)
                        list.search(item);
                    else
                        std::cout << "Entrada de valor inválida. Intente de nuevo.";
                    break;
                case 8: list.display(); break;
                case 9:
                    std::cout << "Saliendo del programa." << std::endl;
                    break;
                default: 
                    std::cout << "Introduzca una opción válida." << std::endl; 
                    break;
            }
        } catch (const std::exception& ex) {
            std::cerr << "\nOcurrió un error: " << ex.what() << std::endl;
        } catch (...) {
            std::cerr << "\nOcurrió un error desconocido." << std::endl;
        }

        // Limpiar el buffer de entrada después de cada operación exitosa para evitar errores en el siguiente loop
        if (choice != 9) {
            std::cin.ignore(10000, '\n');
        }
    }
    
    return 0;
}