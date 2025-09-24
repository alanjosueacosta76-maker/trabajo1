const TAM = 10;


function generarDatosAleatorios(tam) {
    const arreglo = [];
    for (let i = 0; i < tam; i++) {
        arreglo.push(Math.floor(Math.random() * 100) + 1);
    }
    return arreglo;
}


function imprimirArreglo(arreglo) {
    console.log(arreglo.join(" "));
}

// Algoritmo de ordenamiento por selección
function ordenamientoPorSeleccion(lista) {
    const n = lista.length;

    for (let i = 0; i < n - 1; i++) {
        let minIndex = i;

        for (let j = i + 1; j < n; j++) {
            if (lista[j] < lista[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex !== i) {
            let temp = lista[i];
            lista[i] = lista[minIndex];
            lista[minIndex] = temp;
        }
    }
}


let arreglo = generarDatosAleatorios(TAM);

console.log("Arreglo desordenado:");
imprimirArreglo(arreglo);

ordenamientoPorSeleccion(arreglo);

console.log("Arreglo ordenado:");
imprimirArreglo(arreglo);

