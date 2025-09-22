function burbuja(arr) {
    let n = arr.length;
    let temp;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


function imprimirArreglo(arr) {
    console.log(arr.join(" "));
}


let lista = [5, 3, 8, 4, 2];

console.log("Lista desordenada:");
imprimirArreglo(lista);

burbuja(lista);

console.log("Lista ordenada:");
imprimirArreglo(lista);
