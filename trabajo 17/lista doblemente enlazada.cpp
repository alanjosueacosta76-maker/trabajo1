#include <iostream>
#include <cstdlib> // Para exit()

using namespace std;

// Definición de la estructura del nodo doblemente enlazado
struct Node {
    int data;
    Node *next; // Puntero al siguiente nodo
    Node *prev; // ¡Nuevo! Puntero al nodo anterior
};

// Variable global que apunta al primer nodo de la lista
Node *head = NULL;

// Declaración de funciones
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

// --- Funciones de Inserción ---

void begin_insert() {
    int item;
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        cout << "\nOVERFLOW\n";
        return;
    }

    cout << "\nIngrese valor\n";
    cin >> item;

    newNode->data = item;
    newNode->prev = NULL; // El nuevo nodo es el primero, su 'prev' es NULL

    if (head == NULL) {
        // Lista vacía
        newNode->next = NULL;
        head = newNode;
    } else {
        // La lista no está vacía:
        newNode->next = head;
        head->prev = newNode; // El 'prev' del antiguo head apunta al nuevo nodo
        head = newNode;
    }
    cout << "\nNodo insertado al principio\n";
}

void last_insert() {
    int item;
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        cout << "\nOVERFLOW\n";
        return;
    }

    cout << "\nIngrese valor\n";
    cin >> item;

    newNode->data = item;
    newNode->next = NULL; // El nuevo nodo es el último, su 'next' es NULL

    if (head == NULL) {
        // Lista vacía
        newNode->prev = NULL;
        head = newNode;
    } else {
        // Encontrar el último nodo
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Conexiones:
        temp->next = newNode; // El antiguo último nodo apunta al nuevo
        newNode->prev = temp; // El 'prev' del nuevo nodo apunta al antiguo último
    }
    cout << "\nNodo insertado al final\n";
}

void random_insert() {
    if (head == NULL) {
        cout << "\nLa lista está vacía. Use insertar al principio/final.\n";
        return;
    }

    int item, loc;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        cout << "\nOVERFLOW\n";
        return;
    }

    cout << "\nIntroduce el valor del elemento: ";
    cin >> item;
    newNode->data = item;

    cout << "\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: ";
    cin >> loc;

    if (loc < 0) {
        cout << "\nLa ubicación debe ser un número positivo.\n";
        free(newNode);
        return;
    }

    Node *temp = head;
    int i = 0;

    // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
    while (i < loc && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || (i != loc && loc != 0)) {
        cout << "\nNo se puede insertar. La posición está fuera de rango.\n";
        free(newNode);
        return;
    }

    // Nodos involucrados: A (temp), B (newNode), C (temp->next)
    Node *nextNode = temp->next;

    // 1. Conexiones de B (newNode)
    newNode->next = nextNode;
    newNode->prev = temp;

    // 2. Reconexiones de A (temp)
    temp->next = newNode;

    // 3. Reconexiones de C (nextNode), si existe
    if (nextNode != NULL) {
        nextNode->prev = newNode;
    }

    cout << "\nNodo insertado después de la posición " << loc << endl;
}

// --- Funciones de Eliminación ---

void begin_delete() {
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
        return;
    }

    Node *ptrToDelete = head;

    if (head->next == NULL) {
        // Caso de un solo nodo
        head = NULL;
    } else {
        // Caso de múltiples nodos
        head = head->next; // Mover head al siguiente
        head->prev = NULL; // El nuevo head tiene 'prev' NULL
    }

    free(ptrToDelete);
    cout << "\nNodo eliminado desde el principio ...\n";
}

void last_delete() {
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
        return;
    }

    Node *ptrToDelete = head;

    if (head->next == NULL) {
        // Caso de un solo nodo
        head = NULL;
    } else {
        // Recorrer hasta el último nodo
        while (ptrToDelete->next != NULL) {
            ptrToDelete = ptrToDelete->next;
        }
        
        // El penúltimo nodo (ptrToDelete->prev) debe apuntar su 'next' a NULL
        ptrToDelete->prev->next = NULL;
    }
    
    free(ptrToDelete);
    cout << "\nNodo eliminado del último ...\n";
}

void random_delete() {
    if (head == NULL) {
        cout << "\nLista vacía. No se puede eliminar.\n";
        return;
    }

    int loc;
    cout << "\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: \n";
    cin >> loc;

    if (loc < 0) {
        cout << "\nLa ubicación debe ser un número positivo.\n";
        return;
    }

    Node *ptrToDelete = head;
    int i = 0;

    // Avanza hasta la posición 'loc' (el nodo a eliminar)
    while (i < loc && ptrToDelete != NULL) {
        ptrToDelete = ptrToDelete->next;
        i++;
    }

    if (ptrToDelete == NULL) {
        cout << "\nNo se puede eliminar. La posición está fuera de rango.\n";
        return;
    }

    // Si es el primer nodo
    if (ptrToDelete == head) {
        begin_delete();
        return;
    }

    // Si es el último nodo
    if (ptrToDelete->next == NULL) {
        last_delete();
        return;
    }

    // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
    Node *prevNode = ptrToDelete->prev;
    Node *nextNode = ptrToDelete->next;

    // 1. Reconexión A a C
    prevNode->next = nextNode;

    // 2. Reconexión C a A
    nextNode->prev = prevNode;

    free(ptrToDelete);
    cout << "\nNodo en la posición " << (loc + 1) << " eliminado.\n";
}

// --- Otras Funciones ---

void search() {
    if (head == NULL) {
        cout << "\nLista vacia\n";
        return;
    }

    int item;
    cout << "\nIntroduce el elemento que deseas buscar?\n";
    cin >> item;

    Node *ptr = head;
    int i = 0;
    bool found = false;

    while (ptr != NULL) {
        if (ptr->data == item) {
            cout << "Elemento encontrado en la ubicación " << (i + 1) << endl;
            found = true;
            break;
        }
        ptr = ptr->next;
        i++;
    }

    if (!found) {
        cout << "Elemento no encontrado\n";
    }
}

void display() {
    if (head == NULL) {
        cout << "Nada que imprimir";
    } else {
        cout << "\nImprimiendo valores (HEAD a END): \n";
        Node *ptr = head;
        
        while (ptr != NULL) {
            cout << ptr->data;
            if (ptr->next != NULL) {
                cout << " <-> ";
            }
            ptr = ptr->next;
        }
        cout << endl;
    }
}

// --- Función Principal ---

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n\n******Menú principal (Lista Doblemente Enlazada)******\n";
        cout << "\nElige una opción de la siguiente lista ...\n";
        cout << "\n------------------------------------------\n";

        cout << "\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
             << "5. Eliminar desde el último\n6. Eliminar nodo por posición\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n";
        cout << "\nIngrese su opción?\n";
        
        if (!(cin >> choice)) {
            cout << "Opción inválida. Introduce un número del 1 al 9.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: begin_insert(); break;
            case 2: last_insert(); break;
            case 3: random_insert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9:
                cout << "Saliendo del programa.\n";
                exit(0);
                break;
            default: cout << "Introduzca una opción válida..\n";
        }
    }
    return 0;
}