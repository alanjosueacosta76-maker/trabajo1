def insertion_sort(bucket):
    # Ordena una lista usando el método de inserción
    for j in range(1, len(bucket)):
        valor = bucket[j]
        k = j - 1
        # Mueve los elementos mayores una posición a la derecha
        while k >= 0 and bucket[k] > valor:
            bucket[k + 1] = bucket[k]
            k -= 1
        bucket[k + 1] = valor  # Inserta el elemento en su lugar correcto


def bucket_sort(arreglo):
    # Ordena una lista usando el algoritmo Bucket Sort
    tamaño = len(arreglo)
    buckets = [[] for _ in range(tamaño)]  # Crea una lista de "cubetas" vacías

    # Distribuye los elementos en las cubetas según su valor
    for num in arreglo:
        indice = int(tamaño * num)  # Determina en qué cubeta va el número
        if indice == tamaño:  # Evita índice fuera de rango
            indice = tamaño - 1
        buckets[indice].append(num)

    # Ordena individualmente cada cubeta usando inserción
    for bucket in buckets:
        insertion_sort(bucket)

    # Une todas las cubetas en el arreglo original
    indice_arreglo = 0
    for bucket in buckets:
        for num in bucket:
            arreglo[indice_arreglo] = num
            indice_arreglo += 1



arreglo = [0.88, 0.16, 0.48, 0.25, 0.75, 0.99, 0.23, 0.11, 0.24, 0.67]

print("Arreglo desordenado:")
print(" ".join(map(str, arreglo)))

bucket_sort(arreglo)

print("Arreglo ordenado:")
print(" ".join(map(str, arreglo)))
