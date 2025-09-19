def burbuja(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

lista = [5, 3, 8, 4, 2]
ordenada = burbuja(lista)
print("Lista desordenada",lista)
print("Lista ordenada:", ordenada)
