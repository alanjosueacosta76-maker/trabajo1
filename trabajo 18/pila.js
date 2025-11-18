// Tamaño máximo de la pila
const MAX_SIZE = 100;

// Arreglo para almacenar los elementos de la pila
let stack = [];

// Función para agregar un elemento a la pila
function push(item) {
    if (stack.length === MAX_SIZE) { // Verifica si la pila está llena
        console.log("Stack Overflow"); // Mensaje de error
        return;
    }
    stack.push(item); // Agrega el elemento al final (parte superior de la pila)
}

// Función para eliminar y retornar el elemento superior de la pila
function pop() {
    if (stack.length === 0) { // Verifica si la pila está vacía
        console.log("Stack Underflow"); // Mensaje de error
        return -1; // Retorna -1 para indicar que la pila está vacía
    }
    return stack.pop(); // Elimina y retorna el elemento superior
}

// Función para ver el elemento superior sin eliminarlo
function peek() {
    if (stack.length === 0) { // Verifica si la pila está vacía
        console.log("Pila vacía");
        return -1;
    }
    return stack[stack.length - 1]; // Retorna el elemento superior
}

// Función para verificar si la pila está vacía
function isEmpty() {
    return stack.length === 0;
}

// Función para verificar si la pila está llena
function isFull() {
    return stack.length === MAX_SIZE;
}

// Programa principal
function main() {
    push(10); // Agrega elementos a la pila
    push(20);
    push(30);

    console.log("Elemento Superior:", peek()); // Muestra el elemento superior
    console.log("Extrae elemento:", pop()); // Elimina y muestra el elemento superior
    console.log("Elemento Superior:", peek()); // Muestra el nuevo elemento superior
}

// Ejecutar el programa
main();
