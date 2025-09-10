// valores iniciales del arreglo
let arreglo = [5, 10, 15, 20];

// asigna un valor por el índice
arreglo[100] = 40; // ahora arreglo es [5, 10, 15, 20, 40]

// guarda un valor en la variable
let variable = arreglo[2]; // guarda 15 en la variable
console.log("variable = " + variable);

// Inicializar con valores por defecto
let arreglo2 = [0, 0, 0]; // Crea [0, 0, 0]

// Leer un valor (bucle)
for (let i = 0; i < arreglo2.length; i++) {
    console.log("Indice " + i + " -> " + arreglo2[i]);
}