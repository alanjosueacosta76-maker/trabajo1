#include <iostream>
#include <cstdlib> // Para exit()

using namespace std;

// Definición de la estructura del nodo
struct Node {
    int data;
    Node *next;
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

    if (head == NULL) {
        // Lista vacía: el nuevo nodo apunta a sí mismo
        head = newNode;
        newNode->next = head;
    } else {
        // Encontrar el último nodo (el que apunta a 'head')
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // 1. El nuevo nodo apunta al 'head' anterior
        newNode->next = head;
        // 2. El último nodo apunta al nuevo nodo
        temp->next = newNode;
        // 3. 'head' se actualiza al nuevo nodo
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

    if (head == NULL) {
        // Lista vacía: el nuevo nodo es el head y apunta a sí mismo
        head = newNode;
        newNode->next = head;
    } else {
        // Encontrar el último nodo
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        // 1. El nuevo nodo apunta al head (cierra el círculo)
        newNode->next = head;
        // 2. El nodo que era el último ahora apunta al nuevo nodo
        temp->next = newNode;
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

    while (i < loc) {
        temp = temp->next;
        i++;

        if (temp == head) {
            cout << "\nNo se puede insertar. La posición está fuera de rango.\n";
            free(newNode);
            return;
        }
    }

    // 1. El nuevo nodo apunta al siguiente del nodo actual (temp)
    newNode->next = temp->next;
    // 2. El nodo actual (temp) apunta al nuevo nodo
    temp->next = newNode;

    cout << "\nNodo insertado\n";
}

// --- Funciones de Eliminación ---

void begin_delete() {
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
        return;
    }

    if (head->next == head) {
        // Caso de un solo nodo
        free(head);
        head = NULL;
        cout << "\nSolo se eliminó un nodo de la lista ...\n";
        return;
    }

    // Encontrar el último nodo (el que apunta a 'head')
    Node *lastNode = head;
    while (lastNode->next != head) {
        lastNode = lastNode->next;
    }

    Node *ptrToDelete = head; // Guardamos el nodo a borrar

    // 1. 'head' se mueve al siguiente nodo
    head = head->next;
    // 2. El último nodo apunta al nuevo 'head'
    lastNode->next = head;

    free(ptrToDelete); // Liberar la memoria
    cout << "\nNodo eliminado desde el principio ...\n";
}

void last_delete() {
    if (head == NULL) {
        cout << "\nLa lista está vacía\n";
        return;
    } else if (head->next == head) {
        // Caso especial: solo hay un nodo
        free(head);
        head = NULL;
        cout << "\nSolo se eliminó un nodo de la lista ...\n";
        return;
    }

    Node *ptr = head;
    Node *ptr1 = NULL; // ptr1 será el penúltimo

    // Recorre hasta que el siguiente nodo de 'ptr' sea 'head'
    while (ptr->next != head) {
        ptr1 = ptr;
        ptr = ptr->next;
    }

    // ptr1 es el penúltimo. ptr es el último.
    // 1. El penúltimo (ptr1) ahora apunta a head (cierra el círculo)
    ptr1->next = head;
    
    free(ptr); // Liberar la memoria del último nodo
    cout << "\nNodo eliminado del último ...\n";
}

void random_delete() {
    if (head == NULL || head->next == head) {
        cout << "\nNo se puede eliminar en posición. La lista está vacía o tiene solo un nodo (usa eliminar al principio/final).\n";
        return;
    }

    int loc;
    cout << "\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n";
    cin >> loc;
    
    if (loc < 0) {
        cout << "\nLa ubicación debe ser un número positivo.\n";
        return;
    }

    Node *ptr = head; // Este es el nodo ANTES del que queremos eliminar
    int i = 0;

    while (i < loc) {
        ptr = ptr->next;
        i++;

        if (ptr == head) {
            cout << "\nNo se puede eliminar. La posición está fuera de rango.\n";
            return;
        }
    }
    
    Node *nodeToDelete = ptr->next;
    
    if (nodeToDelete == head) {
        cout << "\nNo se recomienda eliminar la cabecera (head) con esta función. Use la Opción 4.\n";
        return;
    }

    // 1. 'ptr' salta al nodo siguiente del nodo a eliminar
    ptr->next = nodeToDelete->next;
    
    free(nodeToDelete); // Liberar la memoria
    cout << "\nNodo eliminado después de la posición " << (loc + 1) << endl;
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

    do {
        if (ptr->data == item) {
            cout << "Elemento encontrado en la ubicación " << (i + 1) << endl;
            found = true;
            break;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != head);

    if (!found) {
        cout << "Elemento no encontrado\n";
    }
}

void display() {
    if (head == NULL) {
        cout << "Nada que imprimir\n";
    } else {
        cout << "\nImprimiendo valores . . . (Lista Circular)\n";
        Node *ptr = head;
        
        do {
            cout << ptr->data;
            ptr = ptr->next;
            if (ptr != head) {
                cout << " -> ";
            }
        } while (ptr != head);

        cout << " -> (HEAD)\n";
    }
}

// --- Función Principal ---

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n\n******Menú principal (Lista Circular)******\n";
        cout << "\nElige una opción de la siguiente lista ...\n";
        cout << "\n------------------------------------------\n";

        cout << "\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
             << "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n";
        cout << "\nIngrese su opción?\n";
        
        if (!(cin >> choice)) {
            cout << "Opción inválida. Introduce un número del 1 al 9.\n";
            cin.clear(); // Limpia la bandera de error
            cin.ignore(10000, '\n'); // Descarta la entrada errónea
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