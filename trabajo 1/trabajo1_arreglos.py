# Valores iniciales del arreglo (lista en Python)
arreglo = [5, 10, 15, 20]

# Asigna un valor por el índice
arreglo[3] = 40  # Cambia el último elemento a 40

# Guarda un valor en la variable
variable = arreglo[2]  # Guarda 15 en la variable
print("variable =", variable)

# Inicializar con valores por defecto
arreglo2 = [0] * 3  # Crea [0, 0, 0]

# Leer un valor (bucle)
for i in range(3):
    print(f"Indice {i} -> {arreglo2[i]}")