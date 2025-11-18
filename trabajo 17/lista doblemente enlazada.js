/**
 * Para simular la lectura de entrada del usuario en la consola (similar a Scanner en Java).
 * Asegúrate de instalarlo si usas Node.js: npm install readline-sync
 */
const readline = require('readline-sync');

/**
 * Clase para representar cada nodo de la lista doblemente enlazada.
 */
class Node {
    /**
     * Constructor para inicializar un nodo.
     * @param {number} data El valor a almacenar en el nodo.
     */
    constructor(data) {
        this.data = data;
        this.next = null; // Referencia al siguiente nodo
        this.prev = null; // Referencia al nodo anterior
    }
}

/**
 * Clase que contiene la lógica de la Lista Doblemente Enlazada.
 */
class DoublyLinkedList {
    constructor() {
        this.head = null; // La cabeza de la lista
    }

    /**
     * Verifica si la lista está vacía.
     * @returns {boolean} true si la lista no contiene nodos, false en caso contrario.
     */
    isEmpty() {
        return this.head === null;
    }

    // --- Funciones de Inserción ---

    /**
     * Inserta un nodo al principio de la lista.
     * @param {number} item El valor a insertar.
     */
    beginInsert(item) {
        const newNode = new Node(item);

        if (this.isEmpty()) {
            this.head = newNode;
        } else {
            // 1. El nuevo nodo apunta al head actual
            newNode.next = this.head;
            
            // 2. El head actual apunta su 'prev' al nuevo nodo
            this.head.prev = newNode;
            
            // 3. El nuevo nodo se convierte en el head
            this.head = newNode;
        }
        console.log(`\nNodo ${item} insertado al principio`);
    }

    /**
     * Inserta un nodo al final de la lista.
     * @param {number} item El valor a insertar.
     */
    lastInsert(item) {
        const newNode = new Node(item);

        if (this.isEmpty()) {
            this.head = newNode;
        } else {
            // Encontrar el último nodo
            let temp = this.head;
            while (temp.next !== null) {
                temp = temp.next;
            }

            // Conexiones:
            temp.next = newNode; // El antiguo último apunta al nuevo
            newNode.prev = temp; // El nuevo apunta su 'prev' al antiguo último
        }
        console.log(`\nNodo ${item} insertado al final`);
    }

    /**
     * Inserta un nodo después de una posición (índice 0-basado) dada.
     * @param {number} item El valor a insertar.
     * @param {number} loc Índice del nodo ANTERIOR al nuevo.
     */
    randomInsert(item, loc) {
        if (this.isEmpty()) {
            console.log("\nLa lista está vacía. Use insertar al principio/final.");
            return;
        }

        if (loc < 0) {
            console.log("\nLa ubicación debe ser un número positivo o cero.");
            return;
        }
        
        // Si loc es 0, es equivalente a insertar al principio
        if (loc === 0) {
            this.beginInsert(item);
            return;
        }

        const newNode = new Node(item);
        let temp = this.head;
        let i = 0;

        // Recorre hasta el nodo en la posición 'loc' (el nodo ANTERIOR al nuevo)
        while (i < loc && temp !== null) {
            temp = temp.next;
            i++;
        }

        // Si 'temp' es null, es que la posición 'loc' estaba fuera de los límites
        if (temp === null || i !== loc) {
            console.log("\nNo se puede insertar. La posición está fuera de rango.");
            return;
        }

        // Si llegamos aquí, 'temp' es el nodo *anterior* donde queremos insertar.
        // Nodos: A (temp), B (newNode), C (temp.next)
        const nextNode = temp.next;

        // 1. Conexiones de B (newNode)
        newNode.next = nextNode;
        newNode.prev = temp;

        // 2. Reconexiones de A (temp)
        temp.next = newNode;

        // 3. Reconexiones de C (nextNode), si existe
        if (nextNode !== null) {
            nextNode.prev = newNode;
        }

        console.log(`\nNodo ${item} insertado después de la posición ${loc} (índice 0-basado).`);
    }

    // --- Funciones de Eliminación ---

    /**
     * Elimina el nodo al principio de la lista.
     */
    beginDelete() {
        if (this.isEmpty()) {
            console.log("\nLa lista está vacía\n");
            return;
        }

        const deletedValue = this.head.data;

        if (this.head.next === null) {
            // Caso de un solo nodo
            this.head = null;
        } else {
            // Caso de múltiples nodos
            this.head = this.head.next; // Mover head al siguiente
            this.head.prev = null; // El nuevo head tiene 'prev' null
        }
        
        console.log(`\nNodo con valor ${deletedValue} eliminado desde el principio ...\n`);
    }

    /**
     * Elimina el último nodo de la lista.
     */
    lastDelete() {
        if (this.isEmpty()) {
            console.log("\nLa lista está vacía\n");
            return;
        }

        let ptrToDelete = this.head;
        let deletedValue;

        if (this.head.next === null) {
            // Caso de un solo nodo
            deletedValue = this.head.data;
            this.head = null;
        } else {
            // Recorrer hasta el último nodo
            while (ptrToDelete.next !== null) {
                ptrToDelete = ptrToDelete.next;
            }
            deletedValue = ptrToDelete.data;
            
            // El penúltimo nodo (ptrToDelete.prev) debe apuntar su 'next' a null
            ptrToDelete.prev.next = null;
        }
        
        console.log(`\nNodo con valor ${deletedValue} eliminado del final ...\n`);
    }

    /**
     * Elimina el nodo en una posición (índice 0-basado) dada.
     * @param {number} loc Índice del nodo a eliminar.
     */
    randomDelete(loc) {
        if (this.isEmpty()) {
            console.log("\nLista vacía. No se puede eliminar.\n");
            return;
        }

        if (loc < 0) {
            console.log("\nLa ubicación debe ser un número positivo.\n");
            return;
        }

        if (loc === 0) {
            // Delegar en la función de eliminación del principio
            this.beginDelete();
            return;
        }

        let ptrToDelete = this.head;
        let i = 0;

        // Avanza hasta la posición 'loc' (el nodo a eliminar)
        while (i < loc && ptrToDelete !== null) {
            ptrToDelete = ptrToDelete.next;
            i++;
        }

        if (ptrToDelete === null || i !== loc) {
            console.log("\nNo se puede eliminar. La posición está fuera de rango.\n");
            return;
        }
        
        const deletedValue = ptrToDelete.data;
        
        // Caso de ser el último nodo (loc > 0)
        if (ptrToDelete.next === null) {
            this.lastDelete();
            return;
        }

        // Caso intermedio: Nodos A (prev), B (ptrToDelete), C (next)
        const prevNode = ptrToDelete.prev;
        const nextNode = ptrToDelete.next;

        // 1. Reconexión A a C
        prevNode.next = nextNode;

        // 2. Reconexión C a A
        if (nextNode !== null) {
            nextNode.prev = prevNode;
        }

        console.log(`\nNodo con valor ${deletedValue} en la posición ${loc} (índice 0-basado) eliminado.`);
    }

    // --- Otras Funciones ---

    /**
     * Busca un elemento y reporta su posición.
     * @param {number} item El valor a buscar.
     */
    search(item) {
        if (this.isEmpty()) {
            console.log("\nLista vacia\n");
            return;
        }

        let ptr = this.head;
        let i = 0; 
        let found = false;
        let positions = [];

        while (ptr !== null) {
            if (ptr.data === item) {
                positions.push(i);
                found = true;
            }
            ptr = ptr.next;
            i++;
        }

        if (found) {
            console.log(`Elemento ${item} encontrado en la(s) ubicación(es) (índice 0-basado) ${positions.join(', ')}`);
        } else {
            console.log(`Elemento ${item} no encontrado\n`);
        }
    }

    /**
     * Muestra todos los elementos de la lista de head a end.
     */
    display() {
        if (this.isEmpty()) {
            console.log("Lista vacía. Nada que imprimir.");
        } else {
            console.log("\nImprimiendo valores (HEAD a END): ");
            let ptr = this.head;
            let output = "";
            
            while (ptr !== null) {
                output += ptr.data;
                if (ptr.next !== null) {
                    output += " <-> ";
                }
                ptr = ptr.next;
            }
            console.log(output);
        }
    }
}

/**
 * Función principal para el menú de interacción en la consola.
 */
function main() {
    const list = new DoublyLinkedList();
    let choice = 0;
    
    while (choice !== 9) {
        console.log("\n\n****** Menú principal (Lista Doblemente Enlazada JS) ******");
        console.log("\nElige una opción de la siguiente lista ...\n");
        console.log("------------------------------------------");
        
        console.log("1. Insertar al principio");
        console.log("2. Insertar al final");
        console.log("3. Insertar en posición (índice 0-basado, *después* del nodo en el índice)");
        console.log("4. Eliminar del principio");
        console.log("5. Eliminar desde el final");
        console.log("6. Eliminar nodo por posición (índice 0-basado)");
        console.log("7. Buscar un elemento");
        console.log("8. Mostrar");
        console.log("9. Salir");
        console.log("------------------------------------------");

        try {
            const input = readline.question("Ingrese su opción? ");
            choice = parseInt(input.trim());

            if (isNaN(choice) || choice < 1 || choice > 9) {
                console.log("Opción inválida. Introduce un número del 1 al 9.");
                continue;
            }

            if (choice === 9) {
                console.log("Saliendo del programa.");
                break;
            }
            
            let item;
            let loc;

            switch (choice) {
                case 1:
                    item = parseInt(readline.question("\nIngrese valor: "));
                    if (!isNaN(item)) {
                        list.beginInsert(item);
                    } else {
                        console.log("Entrada de valor inválida. Debe ser un número entero.");
                    }
                    break;
                case 2:
                    item = parseInt(readline.question("\nIngrese valor: "));
                    if (!isNaN(item)) {
                        list.lastInsert(item);
                    } else {
                        console.log("Entrada de valor inválida. Debe ser un número entero.");
                    }
                    break;
                case 3:
                    item = parseInt(readline.question("\nIntroduce el valor del elemento: "));
                    loc = parseInt(readline.question("\nIntroduce la ubicación (índice 0-basado) después de la cual deseas insertar: "));
                    
                    if (!isNaN(item) && !isNaN(loc)) {
                        list.randomInsert(item, loc);
                    } else {
                        console.log("Entrada de valor o ubicación inválida. Debe ser un número entero.");
                    }
                    break;
                case 4: 
                    list.beginDelete(); 
                    break;
                case 5: 
                    list.lastDelete(); 
                    break;
                case 6:
                    loc = parseInt(readline.question("\nIntroduzca la ubicación (índice 0-basado) del nodo a eliminar: "));
                    if (!isNaN(loc)) {
                        list.randomDelete(loc);
                    } else {
                        console.log("Entrada de ubicación inválida. Debe ser un número entero.");
                    }
                    break;
                case 7:
                    item = parseInt(readline.question("\nIntroduce el elemento que deseas buscar: "));
                    if (!isNaN(item)) {
                        list.search(item);
                    } else {
                        console.log("Entrada de valor inválida. Debe ser un número entero.");
                    }
                    break;
                case 8: 
                    list.display(); 
                    break;
            }
            
        } catch (error) {
            console.log("\nOcurrió un error inesperado. " + error.message);
        }
    }
}

// Ejecutar la función principal para iniciar el menú
main();