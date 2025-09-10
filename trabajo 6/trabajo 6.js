const matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

console.log("Recorrido por columnas:");
for (let j = 0; j < 3; j++) {         // Columnas
    for (let i = 0; i < 3; i++) {     // Filas
        process.stdout.write(matriz[i][j] + " ");
    }
}
console.log();



