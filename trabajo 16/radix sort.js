function countingSort(arr, exp) {
    const n = arr.length;
    const output = new Array(n).fill(0);
    const count = new Array(10).fill(0);

    // Contar la cantidad de ocurrencias de cada dígito
    for (let i = 0; i < n; i++) {
        const index = Math.floor(arr[i] / exp) % 10;
        count[index]++;
    }

    // Sumar los conteos acumulados
    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida (de derecha a izquierda para estabilidad)
    for (let i = n - 1; i >= 0; i--) {
        const index = Math.floor(arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copiar los resultados al arreglo original
    for (let i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


function radixSort(arr) {
    let maxNum = Math.max(...arr);

    for (let exp = 1; Math.floor(maxNum / exp) > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}


function main() {
    const arr = Array.from({ length: 20 }, () => Math.floor(Math.random() * 9999) + 1);

    console.log("Arreglo desordenado:");
    console.log(arr.join(", "));

    radixSort(arr);

    console.log("\nArreglo ordenado:");
    console.log(arr.join(", "));
}


main();
