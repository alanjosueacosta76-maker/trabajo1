import sys

# Definición de la clase Node
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

# Variable global que apunta al primer nodo de la lista
head = None

# --- Funciones de Inserción ---

# Función para insertar un nuevo nodo al principio de la lista
def begin_insert():
    global head
    try:
        item = int(input('\nIngrese valor\n'))
    except ValueError:
        print('\nEntrada inválida. Debe ser un número.')
        return

    newNode = Node(item)

    if head is None:
        # Lista vacía: el nuevo nodo apunta a sí mismo
        head = newNode
        newNode.next = head
    else:
        # Encontrar el último nodo (el que apunta a 'head')
        temp = head
        while temp.next != head:
            temp = temp.next
        
        # 1. El nuevo nodo apunta al 'head' anterior
        newNode.next = head
        # 2. El último nodo apunta al nuevo nodo
        temp.next = newNode
        # 3. 'head' se actualiza al nuevo nodo
        head = newNode
    print('\nNodo insertado al principio')

# Función para insertar un nodo al final de la lista
def last_insert():
    global head
    try:
        item = int(input('\nIngrese valor\n'))
    except ValueError:
        print('\nEntrada inválida. Debe ser un número.')
        return

    newNode = Node(item)

    if head is None:
        # Lista vacía: el nuevo nodo es el head y apunta a sí mismo
        head = newNode
        newNode.next = head
    else:
        # Encontrar el último nodo
        temp = head
        while temp.next != head:
            temp = temp.next

        # 1. El nuevo nodo apunta al head (cierra el círculo)
        newNode.next = head
        # 2. El nodo que era el último ahora apunta al nuevo nodo
        temp.next = newNode
    print('\nNodo insertado al final')

# Función para Insertar un nodo en una posición específica de la lista
def random_insert():
    global head
    if head is None:
        print('\nLa lista está vacía. Use insertar al principio/final.')
        return

    try:
        item = int(input('\nIntroduce el valor del elemento: '))
        loc = int(input('\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: '))
    except ValueError:
        print('\nEntrada inválida. Deben ser números.')
        return
    
    if loc < 0:
        print('\nLa ubicación debe ser un número positivo.')
        return

    newNode = Node(item)
    temp = head
    i = 0

    # Recorrer hasta la posición anterior deseada (loc)
    while i < loc:
        temp = temp.next
        i += 1

        if temp == head:
            print('\nNo se puede insertar. La posición está fuera de rango.')
            return

    # 1. El nuevo nodo apunta al siguiente del nodo actual (temp)
    newNode.next = temp.next
    # 2. El nodo actual (temp) apunta al nuevo nodo
    temp.next = newNode

    print('\nNodo insertado')

# --- Funciones de Eliminación ---

# Función para eliminar el primer nodo de la lista
def begin_delete():
    global head
    if head is None:
        print('\nLa lista está vacía\n')
        return

    if head.next == head:
        # Caso de un solo nodo
        head = None
        print('\nSolo se eliminó un nodo de la lista ...\n')
        return

    # Encontrar el último nodo (el que apunta a 'head')
    lastNode = head
    while lastNode.next != head:
        lastNode = lastNode.next

    # 1. 'head' se mueve al siguiente nodo
    head = head.next
    # 2. El último nodo apunta al nuevo 'head'
    lastNode.next = head

    print('\nNodo eliminado desde el principio ...\n')

# Función para eliminar el último nodo de la lista
def last_delete():
    global head
    if head is None:
        print('\nLa lista está vacía')
        return
    elif head.next == head:
        # Caso especial: solo hay un nodo
        head = None
        print('\nSolo se eliminó un nodo de la lista ...\n')
        return

    ptr = head
    ptr1 = None # ptr1 será el penúltimo

    # Recorre hasta que el siguiente nodo de 'ptr' sea 'head'
    while ptr.next != head:
        ptr1 = ptr
        ptr = ptr.next

    # ptr1 es el penúltimo. 
    # 1. El penúltimo (ptr1) ahora apunta a head (cierra el círculo)
    ptr1.next = head
    
    print('\nNodo eliminado del último ...\n')

# Función para eliminar un nodo después de una posición específica
def random_delete():
    global head
    if head is None or head.next == head:
        print('\nNo se puede eliminar en posición. La lista está vacía o tiene solo un nodo (usa eliminar al principio/final).')
        return

    try:
        loc = int(input('\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n'))
    except ValueError:
        print('\nEntrada inválida. Debe ser un número.')
        return
    
    if loc < 0:
        print('\nLa ubicación debe ser un número positivo.')
        return

    ptr = head
    i = 0

    # Avanza hasta la posición 'loc'
    while i < loc:
        ptr = ptr.next
        i += 1
        
        # Si 'ptr' vuelve a 'head', la posición está fuera de rango
        if ptr == head:
            print('\nNo se puede eliminar. La posición está fuera de rango.')
            return
    
    nodeToDelete = ptr.next
    
    # Manejar el caso si el nodo a eliminar es el último
    if nodeToDelete == head:
        print('\nNo se recomienda eliminar la cabecera (head) con esta función. Use la Opción 4.')
        return

    # 1. 'ptr' salta al nodo siguiente del nodo a eliminar
    ptr.next = nodeToDelete.next
    
    print(f'\nNodo eliminado después de la posición {loc + 1}')

# --- Otras Funciones ---

# Función para buscar un elemento en la lista y mostrar su posición
def search():
    if head is None:
        print('\nLista vacia\n')
        return

    try:
        item = int(input('\nIntroduce el elemento que deseas buscar?\n'))
    except ValueError:
        print('\nEntrada inválida. Debe ser un número.')
        return

    ptr = head
    i = 0
    found = False

    # El bucle se ejecuta hasta que volvemos al inicio
    while True:
        if ptr.data == item:
            print(f'Elemento encontrado en la ubicación {i + 1}')
            found = True
            break
        ptr = ptr.next
        i += 1
        if ptr == head:
            break

    if not found:
        print('Elemento no encontrado\n')

# Función para mostrar todos los elementos de la lista
def display():
    if head is None:
        print('Nada que imprimir')
    else:
        print('\nImprimiendo valores . . . (Lista Circular)')
        ptr = head
        output = ''
        
        while True:
            output += str(ptr.data)
            ptr = ptr.next
            if ptr != head:
                output += ' -> '
            else:
                break
        
        output += ' -> (HEAD)'
        print(output)

# --- Función Principal ---

def main():
    global head
    choice = 0
    while choice != 9:
        print('\n\n******Menú principal (Lista Circular)******')
        print('\nElige una opción de la siguiente lista ...')
        print('\n------------------------------------------')

        print('\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n'
              '5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir')
        
        try:
            choice = int(input('Ingrese su opción?\n'))
        except ValueError:
            print('Opción inválida. Introduce un número del 1 al 9.')
            continue

        if choice == 1: begin_insert()
        elif choice == 2: last_insert()
        elif choice == 3: random_insert()
        elif choice == 4: begin_delete()
        elif choice == 5: last_delete()
        elif choice == 6: random_delete()
        elif choice == 7: search()
        elif choice == 8: display()
        elif choice == 9:
            print('Saliendo del programa.')
            sys.exit(0)
        else:
            print('Introduzca una opción válida..')

if __name__ == "__main__":
    main()