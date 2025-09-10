arr = [10, 20, 30, 40, 50]

pos = 2        #posicion del indice donde insertar
valor = 99

arr.insert(pos, valor)

print("Arreglo después de insertar:")

for i in range(len(arr)):
    print(f"Índice {i} -> {arr[i]}")