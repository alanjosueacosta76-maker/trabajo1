// Función para hacer heapify en un subárbol con raíz en el índice i
function heapify(arr, n, i) {
    let largest = i;
    const left = 2 * i + 1;
    const right = 2 * i + 2;

    // Si el hijo izquierdo es mayor que la raíz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Si el mayor no es la raíz
    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]]; // Intercambiar
        heapify(arr, n, largest); // Heapify recursivo
    }
}

// Función principal de Heap Sort
function heapSort(arr) {
    const n = arr.length;

    // Construir Max Heap
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos uno por uno
    for (let i = n - 1; i > 0; i--) {
        [arr[0], arr[i]] = [arr[i], arr[0]]; // Mover raíz al final
        heapify(arr, i, 0); // Heapify al heap reducido
    }
}

// Función para imprimir el arreglo
function printArray(arr) {
    console.log(arr.join(" "));
}

// Programa principal
const arr = [10, 20, 25, 5, 8, 7];

console.log("Arreglo desordenado:");
printArray(arr);

heapSort(arr);

console.log("Arreglo ordenado:");
printArray(arr);
