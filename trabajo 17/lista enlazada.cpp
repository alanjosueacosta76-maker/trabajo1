#include <iostream>
#include <cstdlib>
using namespace std;

// Definición de la estructura del nodo para la lista enlazada
struct node {
    int data; // Almacena el valor numérico del nodo
    struct node *next; // Puntero que apunta al siguiente nodo en la lista
};

// Variable global que apunta al primer nodo de la lista
struct node *head;

// Declaración de funciones
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

// Función para insertar un nuevo nodo al principio de la lista
void begin_insert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nIngrese valor\n";
        cin >> item;

        ptr->data = item;
        ptr->next = head;
        head = ptr;
        cout << "\nNodo insertado";
    }
}

// Función para insertar un nodo al final de la lista
void last_insert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nIngrese valor\n";
        cin >> item;

        ptr->data = item;

        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            cout << "\nNodo insertado";
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout << "\nNodo insertado";
        }
    }
}

// Función para Insertar un nodo en una posición específica de la lista
void random_insert()
{
    int i, loc, item;
    struct node *ptr, *temp;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nIntroduce el valor del elemento";
        cin >> item;

        ptr->data = item;

        cout << "\nIntroduce la ubicación después de la cual deseas insertar ";
        cin >> loc;

        temp = head;

        for (i = 0; i < loc; i++)
        {
            temp = temp->next;

            if (temp == NULL)
            {
                cout << "\nNo se puede insertar\n";
                return;
            }
        }

        ptr->next = temp->next;
        temp->next = ptr;
        cout << "\nNodo insertado";
    }
}

// Función para eliminar el primer nodo de la lista
void begin_delete()
{
    struct node *ptr;

    if (head == NULL)
    {
        cout << "\nLa lista está vacía\n";
    }
    else
    {
        ptr = head;
        head = ptr->next;
        delete ptr;
        cout << "\nNodo eliminado desde el principio ...\n";
    }
}

// Función para eliminar el último nodo de la lista
void last_delete()
{
    struct node *ptr, *ptr1;

    if (head == NULL)
    {
        cout << "\nLa lista está vacía";
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "\nSolo se eliminó un nodo de la lista ...\n";
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        delete ptr;
        cout << "\nNodo eliminado del último ...\n";
    }
}

// Función para eliminar un nodo después de una posición específica
void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;

    cout << "\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación. \n";
    cin >> loc;

    ptr = head;

    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            cout << "\nNo se puede eliminar";
            return;
        }
    }

    ptr1->next = ptr->next;
    delete ptr;
    cout << "\nNodo eliminado " << loc + 1;
}

// Función para buscar un elemento en la lista y mostrar su posición
void search()
{
    struct node *ptr;
    int item;
    int i = 0;
    int flag;
    ptr = head;

    if (ptr == NULL)
    {
        cout << "\nLista vacia\n";
    }
    else
    {
        cout << "\nIntroduce el elemento que deseas buscar?\n";
        cin >> item;

        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                cout << "Elemento encontrado en la ubicación " << i + 1;
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 1)
        {
            cout << "Elemento no encontrado\n";
        }
    }
}

// Función para mostrar todos los elementos de la lista
void display()
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        cout << "Nada que imprimir";
    }
    else
    {
        cout << "\nImprimiendo valores . . .\n";
        while (ptr != NULL)
        {
            cout << "\n" << ptr->data;
            ptr = ptr->next;
        }
    }
}

// Función principal
int main()
{
    int choice = 0;
    while (choice != 9)
    {
        cout << "\n\n******Menú principal******\n";
        cout << "\nElige una opción de la siguiente lista ...\n";
        cout << "\n------------------------------------------\n";

        cout << "\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
             << "5. Eliminar desde el último\n6. Eliminar nodo en posicion\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n";
        cout << "\nIngrese su opción?\n";
        cin >> choice;

        switch (choice)
        {
            case 1: begin_insert();
                    break;
            case 2: last_insert();
                    break;
            case 3: random_insert();
                    break;
            case 4: begin_delete();
                    break;
            case 5: last_delete();
                    break;
            case 6: random_delete();
                    break;
            case 7: search();
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
                    break;
            default: cout << "Introduzca una opción válida..";
        }
    }
    return 0;
}