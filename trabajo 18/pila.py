# Tamaño máximo de la pila
MAX_SIZE = 100  

# Arreglo para almacenar los elementos de la pila
stack = []  

# Función para agregar un elemento a la pila
def push(item):
    if len(stack) == MAX_SIZE:  # Verifica si la pila está llena
        print("Stack Overflow")  # Mensaje de error
        return
    stack.append(item)  # Agrega el elemento al final (parte superior de la pila)

# Función para eliminar y retornar el elemento superior de la pila
def pop():
    if len(stack) == 0:  # Verifica si la pila está vacía
        print("Stack Underflow")  # Mensaje de error
        return -1  # Retorna -1 para indicar que la pila está vacía
    return stack.pop()  # Retorna y elimina el elemento superior

# Función para ver el elemento superior sin eliminarlo
def peek():
    if len(stack) == 0:  # Verifica si la pila está vacía
        print("Pila vacía")  # Mensaje de error
        return -1
    return stack[-1]  # Retorna el elemento superior

# Función para verificar si la pila está vacía
def is_empty():
    return len(stack) == 0  # Retorna True si está vacía

# Función para verificar si la pila está llena
def is_full():
    return len(stack) == MAX_SIZE  # Retorna True si está llena

# Ejemplo de uso de la pila
if __name__ == "__main__":
    push(10)  # Agrega elementos a la pila
    push(20)
    push(30)

    print("Elemento Superior:", peek())  # Muestra el elemento superior
    print("Extrae elemento:", pop())  # Elimina y muestra el elemento superior
    print("Elemento Superior:", peek())  # Muestra el nuevo elemento superior
