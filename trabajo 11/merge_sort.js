// Función para fusionar dos subarreglos
function merge(a, l, m, r) {
    const a1 = m - l + 1;
    const a2 = r - m;

    // Crear arreglos temporales
    const L = new Array(a1);
    const R = new Array(a2);

    // Copiar datos a los arreglos temporales
    for (let i = 0; i < a1; i++) {
        L[i] = a[l + i];
    }
    for (let j = 0; j < a2; j++) {
        R[j] = a[m + 1 + j];
    }

    // Fusionar los arreglos temporales de vuelta en a[l..r]
    let x = 0, y = 0, k = l;

    while (x < a1 && y < a2) {
        if (L[x] <= R[y]) {
            a[k] = L[x];
            x++;
        } else {
            a[k] = R[y];
            y++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay
    while (x < a1) {
        a[k] = L[x];
        x++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay
    while (y < a2) {
        a[k] = R[y];
        y++;
        k++;
    }
}

// Función principal de Merge Sort
function mergeSort(a, l, r) {
    if (l < r) {
        const m = Math.floor(l + (r - l) / 2);
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Programa principal
const a = [10, 28, 54, 11];
const s = a.length;

console.log("Arreglo desordenado:");
console.log(a.join(" "));

mergeSort(a, 0, s - 1);

console.log("Arreglo ordenado:");
console.log(a.join(" "));
