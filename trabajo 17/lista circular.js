// Para entrada de datos síncrona en Node.js
const readlineSync = require('readline-sync');

// Definición de la clase Node
class Node {
    constructor(data) {
        this.data = data;
        this.next = null; // En una circular, 'next' apunta al siguiente, incluso si es 'head'
    }
}

// Variable global que apunta al primer nodo de la lista
// Se utiliza 'head' para apuntar al inicio del círculo
let head = null;

// --- Funciones de Inserción ---

// Función para insertar un nuevo nodo al principio de la lista
function begin_insert() {
    let item = parseInt(readlineSync.question('\nIngrese valor\n'));

    if (isNaN(item)) {
        console.log('\nEntrada inválida. Debe ser un número.');
        return;
    }

    const newNode = new Node(item);

    if (head === null) {
        // Si la lista está vacía, el nuevo nodo apunta a sí mismo
        head = newNode;
        newNode.next = head;
    } else {
        // Encontrar el último nodo (el que apunta a 'head')
        let temp = head;
        while (temp.next !== head) {
            temp = temp.next;
        }
        
        // 1. El nuevo nodo apunta al 'head' anterior
        newNode.next = head;
        // 2. El último nodo apunta al nuevo nodo
        temp.next = newNode;
        // 3. 'head' se actualiza al nuevo nodo
        head = newNode;
    }
    console.log('\nNodo insertado al principio');
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
        // Si la lista está vacía, el nuevo nodo es el head y apunta a sí mismo
        head = newNode;
        newNode.next = head;
    } else {
        // Encontrar el último nodo
        let temp = head;
        while (temp.next !== head) {
            temp = temp.next;
        }

        // 1. El nuevo nodo apunta al head (cierra el círculo)
        newNode.next = head;
        // 2. El nodo que era el último ahora apunta al nuevo nodo
        temp.next = newNode;
    }
    console.log('\nNodo insertado al final');
}

// Función para Insertar un nodo en una posición específica de la lista
function random_insert() {
    if (head === null) {
        console.log('\nLa lista está vacía. Use insertar al principio/final.');
        return;
    }

    let item = parseInt(readlineSync.question('\nIntroduce el valor del elemento: '));
    let loc = parseInt(readlineSync.question('\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: '));

    if (isNaN(item) || isNaN(loc) || loc < 0) {
        console.log('\nEntrada inválida. Deben ser un número positivo.');
        return;
    }

    const newNode = new Node(item);
    let temp = head;
    let i = 0;

    // Recorrer hasta la posición anterior deseada (loc)
    while (i < loc) {
        temp = temp.next;
        i++;

        // Si regresamos al inicio antes de llegar a 'loc', la posición es inválida.
        // Solo verificamos 'i > 0' para evitar un bucle infinito en listas pequeñas
        // y permitir la inserción en el head (loc=0, que debe manejarse en 'begin_insert').
        if (temp === head) {
            console.log('\nNo se puede insertar. La posición está fuera de rango.');
            return;
        }
    }

    // El nuevo nodo apunta al siguiente del nodo actual (temp)
    newNode.next = temp.next;
    // El nodo actual (temp) apunta al nuevo nodo
    temp.next = newNode;

    // Si la inserción fue después del último nodo, 'head' no necesita actualizarse.
    console.log('\nNodo insertado');
}

// --- Funciones de Eliminación ---

// Función para eliminar el primer nodo de la lista
function begin_delete() {
    if (head === null) {
        console.log('\nLa lista está vacía\n');
        return;
    }

    if (head.next === head) {
        // Caso de un solo nodo
        head = null;
        console.log('\nSolo se eliminó un nodo de la lista ...\n');
        return;
    }

    // Encontrar el último nodo (el que apunta a 'head')
    let lastNode = head;
    while (lastNode.next !== head) {
        lastNode = lastNode.next;
    }

    // 1. 'head' se mueve al siguiente nodo
    head = head.next;
    // 2. El último nodo apunta al nuevo 'head'
    lastNode.next = head;

    console.log('\nNodo eliminado desde el principio ...\n');
}

// Función para eliminar el último nodo de la lista
function last_delete() {
    if (head === null) {
        console.log('\nLa lista está vacía');
        return;
    } else if (head.next === head) {
        // Caso especial: solo hay un nodo
        head = null;
        console.log('\nSolo se eliminó un nodo de la lista ...\n');
        return;
    }

    let ptr = head;
    let ptr1 = null; // ptr1 será el penúltimo

    // Recorre hasta que el siguiente nodo de 'ptr' sea 'head'
    while (ptr.next !== head) {
        ptr1 = ptr;
        ptr = ptr.next;
    }

    // ptr1 es el penúltimo. ptr es el último.
    // 1. El penúltimo (ptr1) ahora apunta a head (cierra el círculo)
    ptr1.next = head;
    // El nodo 'ptr' (el último) será liberado por el recolector de basura
    console.log('\nNodo eliminado del último ...\n');
}

// Función para eliminar un nodo después de una posición específica
function random_delete() {
    if (head === null || head.next === head) {
        console.log('\nNo se puede eliminar en posición. La lista está vacía o tiene solo un nodo (usa eliminar al principio/final).');
        return;
    }

    let loc = parseInt(readlineSync.question('\nIntroduzca la ubicación (índice 0-basado) del nodo ANTES del que desea eliminar. \n'));
    
    if (isNaN(loc) || loc < 0) {
        console.log('\nEntrada inválida. Debe ser un número positivo.');
        return;
    }

    let ptr = head; // Este es el nodo ANTES del que queremos eliminar
    let i = 0;

    // Avanza hasta la posición 'loc'
    while (i < loc) {
        ptr = ptr.next;
        i++;

        // Si 'ptr.next' es 'head', y aún no llegamos a 'loc', la posición está fuera de rango
        if (ptr === head) {
            console.log('\nNo se puede eliminar. La posición está fuera de rango.');
            return;
        }
    }
    
    // El nodo a eliminar es el siguiente de 'ptr'
    let nodeToDelete = ptr.next;
    
    // Si el nodo a eliminar es el 'head', debemos actualizar 'head'
    if (nodeToDelete === head) {
        console.log('\nNo se recomienda eliminar la cabecera (head) con esta función. Use la Opción 4.');
        return;
    }

    // 1. 'ptr' salta al nodo siguiente del nodo a eliminar
    ptr.next = nodeToDelete.next;
    // nodeToDelete (el nodo eliminado) será liberado por el recolector de basura
    
    console.log(`\nNodo eliminado después de la posición ${loc + 1}`);
}

// --- Otras Funciones ---

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

    do {
        if (ptr.data === item) {
            console.log(`Elemento encontrado en la ubicación ${i + 1}`);
            found = true;
            break;
        }
        ptr = ptr.next;
        i++;
    } while (ptr !== head); // El bucle se ejecuta hasta que volvemos al inicio

    if (!found) {
        console.log('Elemento no encontrado\n');
    }
}

// Función para mostrar todos los elementos de la lista
function display() {
    if (head === null) {
        console.log('Nada que imprimir');
    } else {
        console.log('\nImprimiendo valores . . . (Lista Circular)');
        let ptr = head;
        let output = '';
        
        // Usamos un do-while para asegurar que el nodo 'head' se imprime al menos una vez
        do {
            output += ptr.data;
            ptr = ptr.next;
            if (ptr !== head) {
                output += ' -> ';
            }
        } while (ptr !== head);

        output += ' -> (HEAD)';
        console.log(output);
    }
}

// --- Función Principal ---

function main() {
    let choice = 0;
    while (choice !== 9) {
        console.log('\n\n******Menú principal (Lista Circular)******');
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