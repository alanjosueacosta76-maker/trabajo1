def merge(a, l, m, r):
    a1 = m - l + 1
    a2 = r - m

    # Crear arreglos temporales
    L = [0] * a1
    R = [0] * a2

    # Copiar datos a los arreglos temporales
    for i in range(a1):
        L[i] = a[l + i]
    for j in range(a2):
        R[j] = a[m + 1 + j]

    # Mezclar los arreglos temporales de vuelta en a[l..r]
    i = 0  # Índice para L[]
    j = 0  # Índice para R[]
    k = l  # Índice para a[]

    while i < a1 and j < a2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    # Copiar los elementos restantes de L[], si hay
    while i < a1:
        a[k] = L[i]
        i += 1
        k += 1

    # Copiar los elementos restantes de R[], si hay
    while j < a2:
        a[k] = R[j]
        j += 1
        k += 1


def mergesort(a, l, r):
    if l < r:
        m = l + (r - l) // 2  # calcular el punto medio de forma segura
        mergesort(a, l, m)
        mergesort(a, m + 1, r)
        merge(a, l, m, r)


# Programa principal
a = [10, 28, 54, 11]
s = len(a)

print("Arreglo desordenado:")
for j in range(s):
    print("%d" % a[j], end=" ")

# Ordenar con Merge Sort
mergesort(a, 0, s - 1)

print("\nArreglo ordenado:")
for j in range(s):
    print("%d" % a[j], end=" ")
