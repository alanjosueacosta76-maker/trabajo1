/**
 * Implementación de una Lista Doblemente Enlazada Circular (LDEC)
 * en JavaScript para Node.js, con un menú de interacción por consola.
 */

// Módulo necesario para manejar la entrada y salida de la consola de Node.js
const readline = require('readline');

// Configuración de la interfaz de lectura/escritura para la consola
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

/**
 * Clase para representar un nodo en la lista doblemente enlazada.
 * Contiene el dato, y referencias al nodo siguiente y anterior.
 */
class Node {
    constructor(data) {
        this.data = data;
        this.next = null; // Referencia al siguiente nodo
        this.prev = null; // Referencia al nodo anterior
    }
}

/**
 * Clase principal que contiene la implementación de la Lista Doblemente Enlazada Circular.
 */
class DoublyCircularLinkedList {
    constructor() {
        this.head = null; // Referencia al primer nodo (cabeza)
    }

    /**
     * Verifica si la lista está vacía.
     * @returns {boolean} true si la cabeza es null.
     */
    isEmpty() {
        return this.head === null;
    }

    /**
     * Encuentra y devuelve el último nodo de la lista.
     * En una LDEC no vacía, el último nodo es siempre head.prev.
     * @returns {Node | null} El último nodo o null si la lista está vacía.
     */
    getLastNode() {
        if (this.isEmpty()) {
            return null;
        }
        return this.head.prev;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio (antes del head).
     * @param {number} item El valor a insertar.
     */
    beginInsert(item) {
        const newNode = new Node(item);

        if (this.isEmpty()) {
            this.head = newNode;
            // En una lista circular de un solo nodo, apunta a sí mismo
            this.head.next = this.head;
            this.head.prev = this.head;
        } else {
            const last = this.getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode.next = this.head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            this.head.prev = newNode;
            last.next = newNode;

            // 3. Mover la cabeza al nuevo nodo
            this.head = newNode;
        }

        console.log(`\nNodo ${item} insertado al principio (nuevo head).`);
    }

    /**
     * Inserta un nodo al final.
     * @param {number} item El valor a insertar.
     */
    lastInsert(item) {
        const newNode = new Node(item);

        if (this.isEmpty()) {
            // Reutilizamos la lógica del primer elemento
            this.head = newNode;
            this.head.next = this.head;
            this.head.prev = this.head;
        } else {
            const last = this.getLastNode();

            // 1. Conexiones del nuevo nodo
            newNode.next = this.head;
            newNode.prev = last;

            // 2. Reconexiones de los nodos existentes
            last.next = newNode;
            this.head.prev = newNode;
        }

        console.log(`\nNodo ${item} insertado al final.`);
    }

    /**
     * Inserta un nodo DESPUÉS del nodo en la posición (índice 0-basado) dada 'loc'.
     * @param {number} item El valor a insertar.
     * @param {number} loc La posición del nodo ANTERIOR al nuevo.
     */
    randomInsert(item, loc) {
        if (loc < 0) {
            console.log("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        if (this.isEmpty()) {
            console.log("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        const newNode = new Node(item);
        let prevNode = this.head;
        let count = 0;
        let size = 0; // Para determinar el tamaño y la validez del índice

        let current = this.head;
        if (current) {
            do {
                size++;
                current = current.next;
            } while (current !== this.head);
        }

        // Si la posición es el último índice válido (size - 1), insertamos al final
        if (loc === size - 1 && size > 0) {
            this.lastInsert(item);
            return;
        }

        // Caso de un solo nodo: loc debe ser 0. Si loc > 0, está fuera de rango.
        if (size === 1 && loc === 0) {
            this.lastInsert(item); // Insertar después del único nodo es insertar al final.
            return;
        }

        // Recorrer hasta 'loc'
        while (count < loc) {
            prevNode = prevNode.next;
            count++;

            // Si llegamos a la cabeza antes de alcanzar 'loc', la posición es inválida
            if (prevNode === this.head && count < loc) {
                console.log("\nNo se puede insertar. La posición está fuera de rango.");
                return;
            }
        }

        // En este punto, prevNode es el nodo en la posición 'loc'.
        // Insertamos newNode DESPUÉS de prevNode.

        // Si prevNode es el último nodo y no se manejó con lastInsert (caso LDEC vacía)
        if (prevNode.next === this.head && loc === size - 1) {
             this.lastInsert(item);
             return;
        }

        // Si se recorrió más allá del último elemento válido, error.
        if (count >= size) {
            console.log("\nNo se puede insertar. La posición está fuera de rango.");
            return;
        }

        // Caso intermedio:
        // Nodos: A (prevNode), B (newNode), C (prevNode.next)
        const nextNode = prevNode.next;

        // Conexiones: B <-> A
        newNode.prev = prevNode;
        prevNode.next = newNode;

        // Conexiones: B <-> C
        newNode.next = nextNode;
        nextNode.prev = newNode;

        console.log(`\nNodo ${item} insertado después de la posición ${loc}.`);
    }


    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio (el head actual).
     */
    beginDelete() {
        if (this.isEmpty()) {
            console.log("\nLa lista está vacía");
            return;
        }

        const deletedValue = this.head.data;

        if (this.head.next === this.head) {
            // Caso de un solo nodo
            this.head = null;
        } else {
            const last = this.getLastNode();

            // 1. Mover head al siguiente
            this.head = this.head.next;

            // 2. Actualizar la conexión circular (last <-> new head)
            this.head.prev = last;
            last.next = this.head;
        }

        console.log(`\nNodo con valor ${deletedValue} eliminado desde el principio (head)...`);
    }

    /**
     * Elimina el último nodo de la lista.
     */
    lastDelete() {
        if (this.isEmpty()) {
            console.log("\nLa lista está vacía");
            return;
        }

        if (this.head.next === this.head) {
            // Caso de un solo nodo
            const deletedValue = this.head.data;
            this.head = null;
            console.log(`\nNodo con valor ${deletedValue} eliminado del final...`);
            return;
        }

        const last = this.getLastNode(); // Nodo a eliminar
        const deletedValue = last.data;
        const newLast = last.prev; // El nuevo último

        // 1. El nuevo último apunta al head
        newLast.next = this.head;

        // 2. El head apunta su 'prev' al nuevo último
        this.head.prev = newLast;

        // Opcional: Desvincular el nodo eliminado (JS lo maneja con GC)
        last.next = null;
        last.prev = null;

        console.log(`\nNodo con valor ${deletedValue} eliminado del final...`);
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param {number} loc La posición (índice 0-basado) a eliminar.
     */
    randomDelete(loc) {
        if (this.isEmpty()) {
            console.log("\nLista vacía. No se puede eliminar.");
            return;
        }

        if (loc < 0) {
            console.log("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }

        if (loc === 0) {
            // Delegar en la función de eliminación del principio
            this.beginDelete();
            return;
        }

        let ptrToDelete = this.head;
        let count = 0;
        let found = false;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        do {
            if (count === loc) {
                found = true;
                break;
            }

            ptrToDelete = ptrToDelete.next;
            count++;

        } while (ptrToDelete !== this.head);

        if (!found) {
            console.log("\nNo se puede eliminar. La posición está fuera de rango.");
            return;
        }

        // Si es el último nodo (el nodo anterior al head), delegamos en lastDelete
        if (ptrToDelete.next === this.head) {
            this.lastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        const deletedValue = ptrToDelete.data;
        const prevNode = ptrToDelete.prev;
        const nextNode = ptrToDelete.next;

        // 1. Reconexión A a C
        prevNode.next = nextNode;

        // 2. Reconexión C a A
        nextNode.prev = prevNode;

        // Opcional: Desvincular el nodo eliminado
        ptrToDelete.next = null;
        ptrToDelete.prev = null;

        console.log(`\nNodo con valor ${deletedValue} en la posición ${loc} (índice 0-basado) eliminado.`);
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param {number} item El valor a buscar.
     */
    search(item) {
        if (this.isEmpty()) {
            console.log("\nLista vacía");
            return;
        }

        let ptr = this.head;
        let index = 0;
        let found = false;
        const positions = [];

        // Recorrido circular
        do {
            if (ptr.data === item) {
                positions.push(index);
                found = true;
            }

            ptr = ptr.next;
            index++;

        } while (ptr !== this.head);

        if (found) {
            console.log(`Elemento ${item} encontrado en la(s) ubicación(es) (índice 0-basado): ${positions.join(', ')}`);
        } else {
            console.log(`Elemento ${item} no encontrado`);
        }
    }

    /**
     * Muestra todos los elementos de la lista desde head.
     */
    display() {
        if (this.isEmpty()) {
            console.log("Lista vacía. Nada que imprimir.");
        } else {
            console.log("\nImprimiendo valores (desde HEAD): ");
            let ptr = this.head;
            let output = "";

            // Recorrido circular
            do {
                output += ptr.data;

                // Mostrar la conexión
                if (ptr.next !== this.head) {
                    output += " <-> ";
                } else {
                    // Mostrar la conexión circular
                    output += ` <-> (Circular) <-> `;
                }

                ptr = ptr.next;

            } while (ptr !== this.head);

            // Imprimir el head de nuevo para cerrar el círculo visualmente
            output += `[... ${this.head.data} (HEAD) ...]`;
            console.log(output);
        }
    }
}

/**
 * Función principal para el menú de interacción en la consola (Node.js).
 */
async function main() {
    const listInstance = new DoublyCircularLinkedList();
    let choice = 0;

    console.log("Iniciando Lista Doblemente Enlazada Circular en Node.js...");

    const question = (query) => new Promise(resolve => rl.question(query, resolve));

    while (choice !== 9) {
        try {
            console.log("\n\n Menú principal (Lista Doblemente Enlazada Circular) ");
            console.log("\nElige una opción de la siguiente lista ...\n");
            console.log("------------------------------------------");

            console.log("1. Insertar al principio (nuevo head)");
            console.log("2. Insertar al final");
            console.log("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)");
            console.log("4. Eliminar del principio (head)");
            console.log("5. Eliminar desde el final");
            console.log("6. Eliminar nodo por posición (índice 0-basado)");
            console.log("7. Buscar un elemento");
            console.log("8. Mostrar (recorrido circular)");
            console.log("9. Salir");
            console.log("------------------------------------------");

            const choiceStr = await question("\nIngrese su opción? ");
            choice = parseInt(choiceStr);

            if (isNaN(choice)) {
                console.log("Introduzca una opción válida (un número).");
                continue;
            }

            if (choice === 9) {
                console.log("Saliendo del programa.");
                break;
            }

            if (choice < 1 || choice > 8) {
                console.log("Introduzca una opción válida (1-9).");
                continue;
            }

            let item = null;
            let loc = null;

            if ([1, 2, 3, 7].includes(choice)) {
                // Requieren un valor (item)
                const itemStr = await question("\nIngrese el valor (entero) del elemento: ");
                item = parseInt(itemStr);
                if (isNaN(item)) {
                    console.log("Entrada inválida. Por favor, ingrese un número entero para el valor.");
                    continue;
                }
            }

            if ([3, 6].includes(choice)) {
                // Requieren una posición (loc)
                const locStr = await question("Introduce la ubicación (índice 0-basado): ");
                loc = parseInt(locStr);
                if (isNaN(loc)) {
                    console.log("Entrada inválida. Por favor, ingrese un número entero para la ubicación.");
                    continue;
                }
            }

            switch (choice) {
                case 1:
                    listInstance.beginInsert(item);
                    break;
                case 2:
                    listInstance.lastInsert(item);
                    break;
                case 3:
                    listInstance.randomInsert(item, loc);
                    break;
                case 4:
                    listInstance.beginDelete();
                    break;
                case 5:
                    listInstance.lastDelete();
                    break;
                case 6:
                    listInstance.randomDelete(loc);
                    break;
                case 7:
                    listInstance.search(item);
                    break;
                case 8:
                    listInstance.display();
                    break;
                default:
                    console.log("Opción inválida.");
                    break;
            }

        } catch (e) {
            console.log(`\nOcurrió un error inesperado: ${e.message}`);
        }
    }
    rl.close(); // Cerrar la interfaz de lectura al salir del bucle principal
}

// Ejecutar la función principal
main();