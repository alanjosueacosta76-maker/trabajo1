matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Recorrido por columnas:")
for j in range(len(matriz[0])):
    for i in range(len(matriz)):
        print(matriz[i][j], end=" ")