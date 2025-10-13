class ShellSort {
    // Muestra los elementos del arreglo en una sola línea
    static mostrarArreglo(arreglo) {
        console.log(arreglo.join(" "));
    }

    // Ordena un arreglo usando el algoritmo Shell Sort
    ordenar(arreglo) {
        let tamaño = arreglo.length;
        let salto = Math.floor(tamaño / 2); // Se empieza con un "salto" grande

        // Mientras el salto sea mayor que cero, seguimos ordenando
        while (salto > 0) {
            // Recorremos los elementos desde 'salto' hasta el final
            for (let j = salto; j < tamaño; j++) {
                let valor = arreglo[j]; // Elemento actual a comparar
                let k = j;

                // Compara y mueve los elementos que estén fuera de orden
                while (k >= salto && arreglo[k - salto] > valor) {
                    arreglo[k] = arreglo[k - salto];
                    k = k - salto;
                }

                // Inserta el elemento en su posición correcta
                arreglo[k] = valor;
            }

            // Reduce el salto a la mitad en cada iteración
            salto = Math.floor(salto / 2);
        }
    }
}


function main() {
    let arreglo = [36, 38, 44, 11, 19, 30, 28, 50];

    console.log("Arreglo desordenado:");
    ShellSort.mostrarArreglo(arreglo);

    const obj = new ShellSort();
    obj.ordenar(arreglo);

    console.log("Arreglo ordenado:");
    ShellSort.mostrarArreglo(arreglo);
}

main();
