// Para entrada de datos síncrona en Node.js
const readlineSync = require('readline-sync');

// Definición de la clase Node
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Variable global que apunta al primer nodo de la lista
let head = null;

// Función para insertar un nuevo nodo al principio de la lista
function begin_insert() {
    let item = parseInt(readlineSync.question('\nIngrese valor\n'));

    if (isNaN(item)) {
        console.log('\nEntrada inválida. Debe ser un número.');
        return;
    }

    const newNode = new Node(item);
    newNode.next = head;
    head = newNode;
    console.log('\nNodo insertado');
}

// Función para insertar un nodo al final de la lista
function last_insert() {
    let item = parseInt(readlineSync.question('\nIngrese valor\n'));

    if (isNaN(item)) {
        console.log('\nEntrada inválida. Debe ser un número.');
        return;
    }

    const newNode = new Node(item);

    if (head === null) {
        head = newNode;
    } else {
        let temp = head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }
    console.log('\nNodo insertado');
}

// Función para Insertar un nodo en una posición específica de la lista
function random_insert() {
    if (head === null) {
        console.log('\nLa lista está vacía. No se puede insertar en posición.');
        return;
    }

    let item = parseInt(readlineSync.question('\nIntroduce el valor del elemento: '));
    let loc = parseInt(readlineSync.question('\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: '));

    if (isNaN(item) || isNaN(loc)) {
        console.log('\nEntrada inválida. Deben ser números.');
        return;
    }

    const newNode = new Node(item);
    let temp = head;
    let i = 0;

    for (i = 0; i < loc; i++) {
        temp = temp.next;

        if (temp === null) {
            console.log('\nNo se puede insertar. La posición está fuera de rango.');
            return;
        }
    }

    newNode.next = temp.next;
    temp.next = newNode;
    console.log('\nNodo insertado');
}

// Función para eliminar el primer nodo de la lista
function begin_delete() {
    if (head === null) {
        console.log('\nLa lista está vacía\n');
    } else {
        head = head.next;
        console.log('\nNodo eliminado desde el principio ...\n');
    }
}

// Función para eliminar el último nodo de la lista
function last_delete() {
    if (head === null) {
        console.log('\nLa lista está vacía');
    } else if (head.next === null) {
        head = null;
        console.log('\nSolo se eliminó un nodo de la lista ...\n');
    } else {
        let ptr = head;
        let ptr1 = null;
        while (ptr.next !== null) {
            ptr1 = ptr;
            ptr = ptr.next;
        }
        ptr1.next = null;
        // El recolector de basura de JS libera el nodo 'ptr'
        console.log('\nNodo eliminado del último ...\n');
    }
}

// Función para eliminar un nodo después de una posición específica
function random_delete() {
    if (head === null) {
        console.log('\nLista vacía. No se puede eliminar.');
        return;
    }

    let loc = parseInt(readlineSync.question('\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n'));
    
    if (isNaN(loc)) {
        console.log('\nEntrada inválida. Debe ser un número.');
        return;
    }

    let ptr = head; // Este es el nodo ANTERIOR al que queremos eliminar
    let ptr1 = null; // No se usa en esta implementación modificada

    for (let i = 0; i < loc; i++) {
        ptr = ptr.next;

        if (ptr === null || ptr.next === null) {
            console.log('\nNo se puede eliminar. La posición está fuera de rango o el nodo a eliminar no existe.');
            return;
        }
    }

    // ptr es el nodo ANTERIOR al que se quiere eliminar
    let nodeToDelete = ptr.next;
    ptr.next = nodeToDelete.next; // Reconexión
    console.log(`\nNodo eliminado después de la posición ${loc + 1}`);
}


// Función para buscar un elemento en la lista y mostrar su posición
function search() {
    if (head === null) {
        console.log('\nLista vacia\n');
        return;
    }

    let item = parseInt(readlineSync.question('\nIntroduce el elemento que deseas buscar?\n'));
    
    if (isNaN(item)) {
        console.log('\nEntrada inválida. Debe ser un número.');
        return;
    }

    let ptr = head;
    let i = 0;
    let found = false;

    while (ptr !== null) {
        if (ptr.data === item) {
            console.log(`Elemento encontrado en la ubicación ${i + 1}`);
            found = true;
            break;
        }
        ptr = ptr.next;
        i++;
    }

    if (!found) {
        console.log('Elemento no encontrado\n');
    }
}

// Función para mostrar todos los elementos de la lista
function display() {
    if (head === null) {
        console.log('Nada que imprimir');
    } else {
        console.log('\nImprimiendo valores . . .');
        let ptr = head;
        while (ptr !== null) {
            console.log('\n' + ptr.data);
            ptr = ptr.next;
        }
    }
}

// Función principal
function main() {
    let choice = 0;
    while (choice !== 9) {
        console.log('\n\n******Menú principal******');
        console.log('\nElige una opción de la siguiente lista ...');
        console.log('\n------------------------------------------');

        console.log('\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar del principio\n' +
                    '5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n');
        
        let choiceStr = readlineSync.question('Ingrese su opción?\n');
        choice = parseInt(choiceStr);
        
        if (isNaN(choice)) {
            console.log('Opción inválida. Introduce un número del 1 al 9.');
            continue;
        }

        switch (choice) {
            case 1: begin_insert(); break;
            case 2: last_insert(); break;
            case 3: random_insert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9:
                console.log('Saliendo del programa.');
                break;
            default: console.log('Introduzca una opción válida..');
        }
    }
}

main();