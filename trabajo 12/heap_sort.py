def heapify(arr, n, i):
    largest = i 
    left = 2 * i + 1 
    right = 2 * i + 2  

    # Verificar si el hijo izquierdo es mayor que el nodo actual
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Verificar si el hijo derecho es mayor que el nodo actual
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Si el mayor no es la raíz
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)  # Llamada recursiva


def heapsort(arr):
    n = len(arr)

    # Construir Max Heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extraer elementos uno a uno del heap
    for i in range(n - 1, 0, -1):
        # Mover la raíz al final
        arr[0], arr[i] = arr[i], arr[0]
        # Llamar a heapify sobre el heap reducido
        heapify(arr, i, 0)


if __name__ == "__main__":
    lista = [10, 20, 25, 5, 8, 7]
    print("Arreglo desordenado:", lista)
    heapsort(lista)
    print("Arreglo ordenado:", lista)
