// Función para intercambiar elementos en el arreglo
function intercambiar(arr, a, b) {
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Función de partición para Quick Sort
function particion(arr, inicio, fin) {
    let pivote = arr[fin];
    let i = inicio - 1;

    for (let j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(arr, i, j);
        }
    }
    intercambiar(arr, i + 1, fin);
    return i + 1;
}

// Función Quick Sort recursiva
function quickSort(arr, inicio, fin) {
    if (inicio < fin) {
        let indicePivote = particion(arr, inicio, fin);
        quickSort(arr, inicio, indicePivote - 1);
        quickSort(arr, indicePivote + 1, fin);
    }
}


function imprimirArreglo(arr) {
    console.log(arr.join(' '));
}



// Generar arreglo con números aleatorios entre 1 y 100
const tamaño = 10;
let lista = [];
for (let i = 0; i < tamaño; i++) {
    lista.push(Math.floor(Math.random() * 100) + 1);
}

console.log("Lista desordenada:");
imprimirArreglo(lista);

quickSort(lista, 0, lista.length - 1);

console.log("\nLista ordenada:");
imprimirArreglo(lista);

