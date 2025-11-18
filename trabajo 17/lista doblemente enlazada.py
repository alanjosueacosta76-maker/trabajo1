import sys

# Clase para representar cada nodo de la lista
class Node:
    """
    Representa un nodo en la lista doblemente enlazada.
    """
    def __init__(self, data):
        self.data = data
        self.next = None  # Referencia al siguiente nodo
        self.prev = None  # Referencia al nodo anterior

# Clase que contiene la lógica de la lista
class DoublyLinkedList:
    """
    Implementación de la Lista Doblemente Enlazada.
    """
    def __init__(self):
        self.head = None  # La cabeza de la lista

    def is_empty(self):
        """Verifica si la lista está vacía."""
        return self.head is None

    # --- Funciones de Inserción ---

    def begin_insert(self, item):
        """Inserta un nodo al principio de la lista."""
        new_node = Node(item)

        if self.is_empty():
            self.head = new_node
        else:
            # El nuevo nodo apunta al head actual
            new_node.next = self.head
            
            # El head actual apunta su 'prev' al nuevo nodo
            self.head.prev = new_node
            
            # El nuevo nodo se convierte en el head
            self.head = new_node
            
        print(f"\nNodo {item} insertado al principio")

    def last_insert(self, item):
        """Inserta un nodo al final de la lista."""
        new_node = Node(item)

        if self.is_empty():
            self.head = new_node
        else:
            # Encontrar el último nodo
            temp = self.head
            while temp.next is not None:
                temp = temp.next

            # Conexiones:
            temp.next = new_node  # El antiguo último apunta al nuevo
            new_node.prev = temp  # El nuevo apunta su 'prev' al antiguo último
            # new_node.next ya es None por el constructor
            
        print(f"\nNodo {item} insertado al final")

    def random_insert(self, item, loc):
        """Inserta un nodo después de una posición (índice 0-basado) dada."""
        if self.is_empty():
            print("\nLa lista está vacía. Use insertar al principio/final.")
            return

        if loc < 0:
            print("\nLa ubicación debe ser un número positivo.")
            return

        # Si loc es 0, significa insertar *después* del primer elemento.
        # Si loc es -1, se podría interpretar como insertar *antes* del primer elemento (begin_insert),
        # pero para mantener la lógica original (insertar después de loc), nos enfocamos en el índice del nodo anterior.
        
        new_node = Node(item)
        temp = self.head
        i = 0

        # Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        while i < loc and temp is not None:
            temp = temp.next
            i += 1

        if temp is None or i != loc:
            print("\nNo se puede insertar. La posición está fuera de rango.")
            return

        # Nodos: A (temp), B (new_node), C (temp.next)
        next_node = temp.next

        # 1. Conexiones de B (new_node)
        new_node.next = next_node
        new_node.prev = temp

        # 2. Reconexiones de A (temp)
        temp.next = new_node

        # 3. Reconexiones de C (next_node), si existe
        if next_node is not None:
            next_node.prev = new_node

        print(f"\nNodo {item} insertado después de la posición {loc}")

    # --- Funciones de Eliminación ---

    def begin_delete(self):
        """Elimina el nodo al principio de la lista."""
        if self.is_empty():
            print("\nLa lista está vacía\n")
            return

        ptr_to_delete = self.head

        if self.head.next is None:
            # Caso de un solo nodo
            self.head = None
        else:
            # Caso de múltiples nodos
            self.head = self.head.next  # Mover head al siguiente
            self.head.prev = None  # El nuevo head tiene 'prev' None
            
        # Python se encarga de liberar la memoria de ptr_to_delete
        print("\nNodo eliminado desde el principio ...\n")

    def last_delete(self):
        """Elimina el último nodo de la lista."""
        if self.is_empty():
            print("\nLa lista está vacía\n")
            return

        ptr_to_delete = self.head

        if self.head.next is None:
            # Caso de un solo nodo
            self.head = None
        else:
            # Recorrer hasta el último nodo
            while ptr_to_delete.next is not None:
                ptr_to_delete = ptr_to_delete.next
            
            # El penúltimo nodo (ptr_to_delete.prev) debe apuntar su 'next' a None
            ptr_to_delete.prev.next = None
            
        # Python se encarga de liberar la memoria
        print("\nNodo eliminado del último ...\n")

    def random_delete(self, loc):
        """Elimina el nodo en una posición (índice 0-basado) dada."""
        if self.is_empty():
            print("\nLista vacía. No se puede eliminar.\n")
            return

        if loc < 0:
            print("\nLa ubicación debe ser un número positivo.\n")
            return

        ptr_to_delete = self.head
        i = 0

        # Avanza hasta la posición 'loc' (el nodo a eliminar)
        while i < loc and ptr_to_delete is not None:
            ptr_to_delete = ptr_to_delete.next
            i += 1

        if ptr_to_delete is None:
            print("\nNo se puede eliminar. La posición está fuera de rango.")
            return
        
        # Si es el primer nodo
        if ptr_to_delete == self.head:
            self.begin_delete()
            return

        # Si es el último nodo
        if ptr_to_delete.next is None:
            self.last_delete()
            return

        # Caso intermedio: Nodos A (prev), B (ptr_to_delete), C (next)
        prev_node = ptr_to_delete.prev
        next_node = ptr_to_delete.next

        # 1. Reconexión A a C
        prev_node.next = next_node

        # 2. Reconexión C a A
        next_node.prev = prev_node

        print(f"\nNodo en la posición {loc + 1} eliminado.")

    # --- Otras Funciones ---

    def search(self, item):
        """Busca un elemento y reporta su posición."""
        if self.is_empty():
            print("\nLista vacia\n")
            return

        ptr = self.head
        i = 1  # Usamos índice 1-basado para el usuario
        found = False

        while ptr is not None:
            if ptr.data == item:
                print(f"Elemento encontrado en la ubicación {i}")
                found = True
                break
            ptr = ptr.next
            i += 1

        if not found:
            print("Elemento no encontrado\n")

    def display(self):
        """Muestra todos los elementos de la lista de head a end."""
        if self.is_empty():
            print("Nada que imprimir")
        else:
            print("\nImprimiendo valores (HEAD a END): ")
            ptr = self.head
            
            output = []
            while ptr is not None:
                output.append(str(ptr.data))
                ptr = ptr.next
            
            print(" <-> ".join(output))

# Función principal para el menú de interacción
def main():
    """Ejecuta el menú principal interactivo."""
    list = DoublyLinkedList()
    
    while True:
        print("\n\n******Menú principal (Lista Doblemente Enlazada Python)******")
        print("\nElige una opción de la siguiente lista ...\n")
        print("------------------------------------------\n")

        print("1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio")
        print("5. Eliminar desde el último\n6. Eliminar nodo por posición\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n")
        
        try:
            choice = int(input("\nIngrese su opción? "))
        except ValueError:
            print("Opción inválida. Introduce un número del 1 al 9.")
            continue

        if choice == 9:
            print("Saliendo del programa.")
            sys.exit(0)
            
        try:
            if choice == 1:
                item = int(input("\nIngrese valor: "))
                list.begin_insert(item)
            elif choice == 2:
                item = int(input("\nIngrese valor: "))
                list.last_insert(item)
            elif choice == 3:
                item = int(input("\nIntroduce el valor del elemento: "))
                loc = int(input("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: "))
                list.random_insert(item, loc)
            elif choice == 4:
                list.begin_delete()
            elif choice == 5:
                list.last_delete()
            elif choice == 6:
                loc = int(input("\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: "))
                list.random_delete(loc)
            elif choice == 7:
                item = int(input("\nIntroduce el elemento que deseas buscar?\n"))
                list.search(item)
            elif choice == 8:
                list.display()
            else:
                print("Introduzca una opción válida..")
                
        except ValueError:
            print("Entrada de valor inválida. Asegúrese de ingresar un número entero.")
        except Exception as e:
            print(f"Ocurrió un error inesperado: {e}")

if __name__ == "__main__":
    main()