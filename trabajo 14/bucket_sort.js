// Función de ordenamiento por inserción para una cubeta
function ordenamientoInsercion(cubeta) {
    for (let j = 1; j < cubeta.length; j++) {
        const valor = cubeta[j];
        let k = j - 1;

        while (k >= 0 && cubeta[k] > valor) {
            cubeta[k + 1] = cubeta[k];
            k--;
        }
        cubeta[k + 1] = valor;
    }
}

// Función principal del algoritmo Bucket Sort
function ordenamientoBucket(arreglo) {
    const tamaño = arreglo.length;
    const cubetas = Array.from({ length: tamaño }, () => []);

    // Distribuir elementos en cubetas
    for (const num of arreglo) {
        let indice = Math.floor(tamaño * num);
        if (indice === tamaño) indice = tamaño - 1; // Evita índice fuera de rango
        cubetas[indice].push(num);
    }

    // Ordenar cada cubeta
    for (const cubeta of cubetas) {
        ordenamientoInsercion(cubeta);
    }

    // Concatenar cubetas en el arreglo original
    let indiceArreglo = 0;
    for (const cubeta of cubetas) {
        for (const num of cubeta) {
            arreglo[indiceArreglo++] = num;
        }
    }
}


function main() {
    const arreglo = [0.88, 0.16, 0.48, 0.25, 0.75, 0.99, 0.23, 0.11, 0.24, 0.67];

    console.log("Arreglo desordenado:");
    console.log(arreglo.join(" "));

    ordenamientoBucket(arreglo);

    console.log("Arreglo ordenado:");
    console.log(arreglo.join(" "));
}


main();
