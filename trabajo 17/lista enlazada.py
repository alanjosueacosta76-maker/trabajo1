import sys

# Definición de la clase Node
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

# Variable global que apunta al primer nodo de la lista
head = None

# Función para insertar un nuevo nodo al principio de la lista
def begin_insert():
    global head
    try:
        item = int(input("\nIngrese valor\n"))
    except ValueError:
        print("\nEntrada inválida. Debe ser un número.")
        return

    # No hay 'malloc' explícito, la instancia de clase maneja la memoria
    new_node = Node(item)

    # La inserción al principio es simple: el nuevo nodo apunta a 'head', y 'head' se convierte en el nuevo nodo.
    new_node.next = head
    head = new_node
    print("\nNodo insertado")

# Función para insertar un nodo al final de la lista
def last_insert():
    global head
    try:
        item = int(input("\nIngrese valor\n"))
    except ValueError:
        print("\nEntrada inválida. Debe ser un número.")
        return

    new_node = Node(item)
    new_node.next = None

    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node
    print("\nNodo insertado")

# Función para Insertar un nodo en una posición específica de la lista
def random_insert():
    global head
    if head is None:
        print("\nLa lista está vacía. Use 'Insertar al principio' o 'Insertar al final'.")
        return

    try:
        item = int(input("\nIntroduce el valor del elemento: "))
        loc = int(input("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: "))
    except ValueError:
        print("\nEntrada inválida. Debe ser un número.")
        return

    new_node = Node(item)
    temp = head
    i = 0

    # Avanza hasta la posición 'loc'
    while i < loc and temp is not None:
        temp = temp.next
        i += 1

    if temp is None:
        print("\nNo se puede insertar. La posición está fuera de rango.")
        return

    # Realiza la Inserción
    new_node.next = temp.next
    temp.next = new_node
    print("\nNodo insertado")

# Función para eliminar el primer nodo de la lista
def begin_delete():
    global head
    if head is None:
        print("\nLa lista está vacía\n")
    else:
        # El recolector de basura de Python libera la memoria del nodo anterior
        # una vez que 'head' ya no apunta a él.
        head = head.next
        print("\nNodo eliminado desde el principio ...\n")

# Función para eliminar el último nodo de la lista
def last_delete():
    global head
    if head is None:
        print("\nLa lista está vacía")
    elif head.next is None:
        # Caso especial: solo hay un nodo
        head = None
        print("\nSolo se eliminó un nodo de la lista ...\n")
    else:
        ptr = head
        ptr1 = None # ptr1 es el penúltimo nodo
        while ptr.next is not None:
            ptr1 = ptr
            ptr = ptr.next
        
        # ptr1 es ahora el penúltimo. Su 'next' se pone a None
        ptr1.next = None
        # El nodo 'ptr' (el último) será liberado por el recolector de basura
        print("\nNodo eliminado del último ...\n")

# Función para eliminar un nodo después de una posición específica
def random_delete():
    global head
    if head is None:
        print("\nLista vacía. No se puede eliminar.")
        return

    try:
        loc = int(input("\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n"))
    except ValueError:
        print("\nEntrada inválida. Debe ser un número.")
        return

    ptr = head
    ptr1 = None
    i = 0

    # Avanza hasta el nodo que está ANTES del que se quiere eliminar (loc)
    # y guarda el nodo a eliminar en 'ptr'
    while i < loc and ptr is not None:
        ptr1 = ptr
        ptr = ptr.next
        i += 1

    if ptr is None or ptr.next is None: # Si 'ptr' es None, o si 'ptr' es el último y se pide eliminar 'ptr.next'
        print("\nNo se puede eliminar. La posición está fuera de rango o el nodo a eliminar no existe.")
        return

    # Realiza la eliminación
    # ptr1 (anterior) apunta al nodo siguiente de ptr (el que se elimina)
    ptr1.next = ptr.next
    print(f"\nNodo eliminado en la posición {loc + 1}")

# Función para buscar un elemento en la lista y mostrar su posición
def search():
    if head is None:
        print("\nLista vacia\n")
        return

    try:
        item = int(input("\nIntroduce el elemento que deseas buscar?\n"))
    except ValueError:
        print("\nEntrada inválida. Debe ser un número.")
        return

    ptr = head
    i = 0
    found = False

    while ptr is not None:
        if ptr.data == item:
            print(f"Elemento encontrado en la ubicación {i + 1}")
            found = True
            break
        ptr = ptr.next
        i += 1

    if not found:
        print("Elemento no encontrado\n")

# Función para mostrar todos los elementos de la lista
def display():
    if head is None:
        print("Nada que imprimir")
    else:
        print("\nImprimiendo valores . . .")
        ptr = head
        while ptr is not None:
            print(f"\n{ptr.data}")
            ptr = ptr.next

# Función principal
def main():
    global head
    choice = 0
    while choice != 9:
        print("\n\n******Menú principal******")
        print("\nElige una opción de la siguiente lista ...")
        print("\n------------------------------------------")

        print("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n"
              "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir")
        
        try:
            choice = int(input("\nIngrese su opción?\n"))
        except ValueError:
            print("Opción inválida. Introduce un número del 1 al 9.")
            continue

        if choice == 1:
            begin_insert()
        elif choice == 2:
            last_insert()
        elif choice == 3:
            random_insert()
        elif choice == 4:
            begin_delete()
        elif choice == 5:
            last_delete()
        elif choice == 6:
            random_delete()
        elif choice == 7:
            search()
        elif choice == 8:
            display()
        elif choice == 9:
            print("Saliendo del programa.")
            sys.exit(0)
        else:
            print("Introduzca una opción válida..")

if __name__ == "__main__":
    main()