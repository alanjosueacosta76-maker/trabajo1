import random
import time

# -------------------- RADIX SORT --------------------
def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # Contar la cantidad de ocurrencias de cada dígito
    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    # Sumar los conteos acumulados
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Construir el arreglo de salida
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    # Copiar los resultados al arreglo original
    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

# Generar lista de números aleatorios
arr = [random.randint(1, 9999) for _ in range(20)]  

print("Arreglo desordenado:")
print(arr)

inicio = time.time()
radix_sort(arr)
fin = time.time()

print("\nArreglo ordenado:")
print(arr)

