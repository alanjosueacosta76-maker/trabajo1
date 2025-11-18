import sys

# Definición de la clase para cada nodo
class Node:
    """
    Clase para representar un nodo en la lista doblemente enlazada.
    Contiene el dato, y referencias al nodo siguiente y anterior.
    """
    def __init__(self, data):
        self.data = data
        self.next = None # Referencia al siguiente nodo
        self.prev = None # Referencia al nodo anterior

# Clase que contiene la lógica de la Lista Doblemente Enlazada Circular
class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None # Referencia al primer nodo (cabeza)

    def _get_last_node(self):
        """
        Encuentra y devuelve el último nodo de la lista.
        En una lista doblemente enlazada circular no vacía, el último nodo
        es siempre head.prev.
        """
        if self.is_empty():
            return None
        return self.head.prev

    def is_empty(self):
        """
        Verifica si la lista está vacía.
        """
        return self.head is None

    # --- Funciones de Inserción ---

    def begin_insert(self, item):
        """
        Inserta un nodo al principio (antes del head).
        """
        new_node = Node(item)

        if self.is_empty():
            self.head = new_node
            # En una lista circular de un solo nodo, apunta a sí mismo
            self.head.next = self.head
            self.head.prev = self.head
        else:
            last = self._get_last_node()

            # 1. Conexiones del nuevo nodo
            new_node.next = self.head
            new_node.prev = last

            # 2. Reconexiones de los nodos existentes
            self.head.prev = new_node
            last.next = new_node

            # 3. Mover la cabeza al nuevo nodo
            self.head = new_node
            
        print(f"\nNodo {item} insertado al principio (nuevo head).")

    def last_insert(self, item):
        """
        Inserta un nodo al final.
        """
        new_node = Node(item)

        if self.is_empty():
            # Reutilizamos la lógica del primer elemento
            self.head = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            last = self._get_last_node()

            # 1. Conexiones del nuevo nodo
            new_node.next = self.head
            new_node.prev = last

            # 2. Reconexiones de los nodos existentes
            last.next = new_node
            self.head.prev = new_node
            
        print(f"\nNodo {item} insertado al final.")

    def random_insert(self, item, loc):
        """
        Inserta un nodo DESPUÉS del nodo en la posición (índice 0-basado) dada 'loc'.
        """
        if loc < 0:
            print("\nLa ubicación debe ser un número positivo o cero.")
            return

        if self.is_empty():
            print("\nLa lista está vacía. Use insertar al principio/final.")
            return

        # 1. Encontrar el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        prev_node = self.head
        count = 0
        
        while count < loc:
            prev_node = prev_node.next
            count += 1
            if prev_node == self.head and count <= loc:
                # Si damos la vuelta al círculo antes de alcanzar 'loc'
                print("\nNo se puede insertar. La posición está fuera de rango.")
                return

        # Si 'prev_node' es el último nodo y el índice coincide con 'loc', insertamos al final.
        # En una lista circular, esto se maneja con la lógica general de inserción,
        # pero verificamos si 'prev_node' ya es el último
        if prev_node.next == self.head and count == loc:
            self.last_insert(item) # Reutilizar la función de inserción al final
            return

        # 2. 'prev_node' es el nodo *anterior* donde queremos insertar.
        # Nodos: A (prev_node), B (newNode), C (prev_node.next)
        new_node = Node(item)
        next_node = prev_node.next

        # Conexiones: B <-> A
        new_node.prev = prev_node
        prev_node.next = new_node

        # Conexiones: B <-> C
        new_node.next = next_node
        next_node.prev = new_node

        print(f"\nNodo {item} insertado después de la posición {loc}.")

    # --- Funciones de Eliminación ---

    def begin_delete(self):
        """
        Elimina el nodo al principio (el head actual).
        """
        if self.is_empty():
            print("\nLa lista está vacía")
            return

        deleted_value = self.head.data

        if self.head.next == self.head:
            # Caso de un solo nodo
            self.head = None
        else:
            last = self._get_last_node()
            old_head = self.head
            
            # 1. Mover head al siguiente
            self.head = self.head.next

            # 2. Actualizar la conexión circular (last <-> new head)
            self.head.prev = last
            last.next = self.head

            # Nota: En Python, no necesitamos 'delete old_head' explícito,
            # el recolector de basura liberará la memoria cuando no haya referencias.

        print(f"\nNodo con valor {deleted_value} eliminado desde el principio (head) ...")

    def last_delete(self):
        """
        Elimina el último nodo de la lista.
        """
        if self.is_empty():
            print("\nLa lista está vacía")
            return

        if self.head.next == self.head:
            # Caso de un solo nodo
            deleted_value = self.head.data
            self.head = None
            print(f"\nNodo con valor {deleted_value} eliminado del final ...")
            return

        last = self._get_last_node() # Nodo a eliminar
        deleted_value = last.data
        new_last = last.prev # El nuevo último

        # 1. El nuevo último apunta al head
        new_last.next = self.head

        # 2. El head apunta su 'prev' al nuevo último
        self.head.prev = new_last
        
        # Nota: La memoria del nodo 'last' será liberada por el GC de Python.

        print(f"\nNodo con valor {deleted_value} eliminado del final ...")

    def random_delete(self, loc):
        """
        Elimina el nodo en una posición (índice 0-basado) dada.
        """
        if self.is_empty():
            print("\nLista vacía. No se puede eliminar.")
            return

        if loc < 0:
            print("\nLa ubicación debe ser un número positivo.")
            return

        if loc == 0:
            # Delegar en la función de eliminación del principio
            self.begin_delete()
            return
            
        ptr_to_delete = self.head
        count = 0
        found = False

        # Avanza hasta la posición 'loc' (el nodo a eliminar)
        # Usamos un bucle while True para emular el do-while hasta que demos la vuelta
        while True:
            if count == loc:
                found = True
                break
            
            ptr_to_delete = ptr_to_delete.next
            count += 1

            if ptr_to_delete == self.head:
                # Dimos la vuelta y no encontramos el índice
                break

        if not found:
            print("\nNo se puede eliminar. La posición está fuera de rango.")
            return
            
        # Si es el último nodo (el nodo anterior al head), delegamos en last_delete
        if ptr_to_delete.next == self.head:
            self.last_delete()
            return

        # Caso intermedio: Nodos A (prev), B (ptr_to_delete), C (next)
        deleted_value = ptr_to_delete.data
        prev_node = ptr_to_delete.prev
        next_node = ptr_to_delete.next

        # 1. Reconexión A a C
        prev_node.next = next_node

        # 2. Reconexión C a A
        next_node.prev = prev_node
        
        # Nota: La memoria de ptr_to_delete será liberada por el GC de Python.

        print(f"\nNodo con valor {deleted_value} en la posición {loc} (índice 0-basado) eliminado.")

    # --- Otras Funciones ---

    def search(self, item):
        """
        Busca un elemento y reporta su posición.
        """
        if self.is_empty():
            print("\nLista vacía")
            return

        ptr = self.head
        index = 0
        found = False
        positions = []

        # Recorrido circular
        while True:
            if ptr.data == item:
                positions.append(str(index))
                found = True
            
            ptr = ptr.next
            index += 1
            
            if ptr == self.head:
                break

        if found:
            print(f"Elemento {item} encontrado en la(s) ubicación(es) (índice 0-basado): {' '.join(positions)}")
        else:
            print(f"Elemento {item} no encontrado")

    def display(self):
        """
        Muestra todos los elementos de la lista desde head.
        """
        if self.is_empty():
            print("Lista vacía. Nada que imprimir.")
        else:
            print("\nImprimiendo valores (desde HEAD): ")
            ptr = self.head
            
            output = ""
            while True:
                output += str(ptr.data)
                
                # Mostrar la conexión
                if ptr.next != self.head:
                    output += " <-> "
                else:
                    # Mostrar la conexión circular
                    output += " <-> (Circular) <-> "

                ptr = ptr.next
                
                if ptr == self.head:
                    break

            # Imprimir el head de nuevo para cerrar el círculo visualmente
            output += f"[... {self.head.data} (HEAD) ...]"
            print(output)

# Función principal para el menú de interacción
def main():
    list_instance = DoublyCircularLinkedList()
    choice = 0
    
    while choice != 9:
        try:
            print("\n\n Menú principal (Lista Doblemente Enlazada Circular ) ")
            print("\nElige una opción de la siguiente lista ...\n")
            print("------------------------------------------")
            
            print("1. Insertar al principio (nuevo head)")
            print("2. Insertar al final")
            print("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)")
            print("4. Eliminar del principio (head)")
            print("5. Eliminar desde el final")
            print("6. Eliminar nodo por posición (índice 0-basado)")
            print("7. Buscar un elemento")
            print("8. Mostrar (recorrido circular)")
            print("9. Salir")
            print("------------------------------------------")
            
            user_input = input("\nIngrese su opción? ")
            choice = int(user_input)

            if choice == 9:
                print("Saliendo del programa.")
                break

            if choice not in range(1, 9):
                print("Introduzca una opción válida.")
                continue

            item = None
            loc = None

            if choice in [1, 2, 3, 7]: # Requieren un valor (item)
                try:
                    item_input = input("\nIngrese el valor del elemento: ")
                    item = int(item_input)
                except ValueError:
                    print("Entrada de valor inválida. Intente de nuevo.")
                    continue

            if choice in [3, 6]: # Requieren una posición (loc)
                try:
                    loc_input = input("Introduce la ubicación (índice 0-basado): ")
                    loc = int(loc_input)
                except ValueError:
                    print("Entrada de ubicación inválida. Intente de nuevo.")
                    continue

            if choice == 1:
                list_instance.begin_insert(item)
            elif choice == 2:
                list_instance.last_insert(item)
            elif choice == 3:
                # El valor 'item' ya se leyó si se llegó aquí
                list_instance.random_insert(item, loc)
            elif choice == 4:
                list_instance.begin_delete()
            elif choice == 5:
                list_instance.last_delete()
            elif choice == 6:
                list_instance.random_delete(loc)
            elif choice == 7:
                list_instance.search(item)
            elif choice == 8:
                list_instance.display()

        except ValueError:
            print("Opción inválida. Introduce un número del 1 al 9.")
        except Exception as e:
            print(f"\nOcurrió un error inesperado: {e}")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nPrograma terminado por el usuario.")
        sys.exit(0)