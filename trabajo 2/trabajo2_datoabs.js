class Persona {
    constructor(nombre, apellidoPaterno, apellidoMaterno) {
        this.nombre = nombre;
        this.apellidoPaterno = apellidoPaterno;
        this.apellidoMaterno = apellidoMaterno;
    }

    imprimir() {
        console.log(`Nombre completo: ${this.nombre} ${this.apellidoPaterno} ${this.apellidoMaterno}`);
    }
}

// Función principal (opcional en JS, pero se puede usar para organizar el código)
function main() {
    const persona1 = new Persona("Alan", "Acosta", "Maro");
    persona1.imprimir();
}

// Llamada a la función principal
main();
