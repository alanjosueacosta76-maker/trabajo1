MAXSIZE = 5
queue = [0] * MAXSIZE
front = -1
rear = -1

def insertar():
    global front, rear
    elemento = int(input("\nIngrese el elemento: "))

    if rear == MAXSIZE - 1:
        print("\nDESBORDAMIENTO (OVERFLOW)")
        return

    if front == -1 and rear == -1:
        front = rear = 0
    else:
        rear += 1

    queue[rear] = elemento
    print("\nElemento insertado correctamente.")

def eliminar():
    global front, rear
    if front == -1 or front > rear:
        print("\nSUBDESBORDAMIENTO (UNDERFLOW)")
        return

    elemento = queue[front]

    if front == rear:
        front = rear = -1
    else:
        front += 1

    print("\nElemento eliminado:", elemento)

def mostrar():
    if front == -1 or front > rear:
        print("\nLa cola está vacía.")
        return

    print("\nElementos en la cola:")
    for i in range(front, rear + 1):
        print(queue[i])

def main():
    opcion = 0
    while opcion != 4:
        print("\n*************** MENÚ PRINCIPAL ***************")
        print("1. Insertar un elemento")
        print("2. Eliminar un elemento")
        print("3. Mostrar la cola")
        print("4. Salir")
        opcion = int(input("Ingrese su opción: "))

        if opcion == 1:
            insertar()
        elif opcion == 2:
            eliminar()
        elif opcion == 3:
            mostrar()
        elif opcion == 4:
            print("\nSaliendo del programa...")
        else:
            print("\nOpción inválida.")

main()
