// Arreglo original
let arr = [10, 20, 30, 40, 50];
let pos = 2;      // Posición donde insertar
let valor = 99;

// Insertar el valor en la posición especificada
arr.splice(pos, 0, valor);  // 0 indica que no se eliminará ningún elemento

// Imprimir el arreglo después de la inserción
console.log("Arreglo después de insertar:");
for (let i = 0; i < arr.length; i++) {
    console.log(`Índice ${i} -> ${arr[i]}`);
}


