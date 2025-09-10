# Arreglo inicial
arreglo = [5, 8, 3, 10, 7, 2, 15, 9]

# Solicitar el número a buscar
elemento = int(input("Ingrese el número a buscar: "))
encontrado = False

# Búsqueda lineal
for i in range(len(arreglo)):
    if arreglo[i] == elemento:
        print(f"Elemento {elemento} encontrado en la posición {i}.")
        encontrado = True
        break  # Detener búsqueda al encontrar el elemento

if not encontrado:
    print(f"Elemento {elemento} no encontrado en el arreglo.")
