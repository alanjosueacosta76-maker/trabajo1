class ShellSort:
    # Muestra los elementos del arreglo en una sola línea
    @staticmethod
    def displayArr(inputArr):
        for k in inputArr:
            print(k, end=" ")
        print()

    # Ordena un arreglo usando el algoritmo Shell Sort
    def sort(self, inputArr):
        size = len(inputArr)
        gapSize = size // 2  # Se empieza con un "salto" grande

        # Mientras el salto sea mayor que cero, seguimos ordenando
        while gapSize > 0:
            # Recorremos los elementos desde 'gapSize' hasta el final
            for j in range(gapSize, size):
                val = inputArr[j]  # Elemento actual a comparar
                k = j
                # Compara y mueve los elementos que estén fuera de orden
                while k >= gapSize and inputArr[k - gapSize] > val:
                    inputArr[k] = inputArr[k - gapSize]
                    k = k - gapSize
                inputArr[k] = val  # Inserta el elemento en su posición correcta

            gapSize = gapSize // 2  # Reduce el salto a la mitad en cada iteración

        return 0


if __name__ == "__main__":
    inputArr = [36, 38, 44, 11, 19, 30, 28, 50]

    print("Arreglo desordenado:")
    ShellSort.displayArr(inputArr)

    obj = ShellSort()
    obj.sort(inputArr)

    print("Arreglo ordenado:")
    ShellSort.displayArr(inputArr)
