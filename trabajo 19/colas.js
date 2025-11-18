const prompt = require("prompt-sync")();

const MAXSIZE = 5;
let queue = new Array(MAXSIZE);
let front = -1, rear = -1;

function insertar() {
    let elemento = parseInt(prompt("\nIngrese el elemento: "));

    if (rear === MAXSIZE - 1) {
        console.log("\nDESBORDAMIENTO (OVERFLOW)");
        return;
    }

    if (front === -1 && rear === -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = elemento;
    console.log("\nElemento insertado correctamente.");
}

function eliminar() {
    if (front === -1 || front > rear) {
        console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)");
        return;
    }

    let elemento = queue[front];

    if (front === rear) {
        front = rear = -1;
    } else {
        front++;
    }

    console.log("\nElemento eliminado: " + elemento);
}

function mostrar() {
    if (front === -1 || front > rear) {
        console.log("\nLa cola está vacía.");
        return;
    }

    console.log("\nElementos en la cola:");
    for (let i = front; i <= rear; i++) {
        console.log(queue[i]);
    }
}

function main() {
    let opcion = 0;

    while (opcion !== 4) {
        console.log("\n*************** MENÚ PRINCIPAL ***************");
        console.log("1. Insertar un elemento");
        console.log("2. Eliminar un elemento");
        console.log("3. Mostrar la cola");
        console.log("4. Salir");
        opcion = parseInt(prompt("Ingrese su opción: "));

        switch (opcion) {
            case 1:
                insertar();
                break;
            case 2:
                eliminar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                console.log("\nSaliendo...");
                break;
            default:
                console.log("\nOpción inválida.");
        }
    }
}

main();
