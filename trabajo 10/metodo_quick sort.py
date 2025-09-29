import random
def quick_sort(arr):
    if len(arr) <= 1:
        return arr  # Caso base: arreglos de 0 o 1 elementos ya están ordenados

    pivot = arr[0]  # Seleccionamos el primer elemento como pivote
    menores = [x for x in arr[1:] if x <= pivot]  # Elementos menores o iguales al pivote
    mayores = [x for x in arr[1:] if x > pivot]   # Elementos mayores al pivote

    return quick_sort(menores) + [pivot] + quick_sort(mayores)
    
lista = [random.randint(1, 100) for _ in range(10)]

print("Lista desordenada:")
print(lista)


lista=quick_sort(lista)

print("Lista ordenada:")
print(lista)
