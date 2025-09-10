#include <stdio.h>
#include <string.h>

// Definición del tipo de dato abstracto Persona
typedef struct {
    char nombre[50];
    char apellidoPaterno[50];
    char apellidoMaterno[50];
} Persona;

// Función para crear una persona
Persona crearPersona(const char* nombre, const char* apPaterno, const char* apMaterno) {
    Persona p;

    // Copiar los datos a los campos de la estructura
    strncpy(p.nombre, nombre, sizeof(p.nombre) - 1);
    p.nombre[sizeof(p.nombre) - 1] = '\0'; // Asegurar terminación nula

    strncpy(p.apellidoPaterno, apPaterno, sizeof(p.apellidoPaterno) - 1);
    p.apellidoPaterno[sizeof(p.apellidoPaterno) - 1] = '\0';

    strncpy(p.apellidoMaterno, apMaterno, sizeof(p.apellidoMaterno) - 1);
    p.apellidoMaterno[sizeof(p.apellidoMaterno) - 1] = '\0';

    return p;
}

// Función para imprimir una persona
void imprimirPersona(Persona p) {
    printf("Nombre completo: %s %s %s\n", p.nombre, p.apellidoPaterno, p.apellidoMaterno);
}

int main() {
    // Crear una persona usando el TDA
    Persona persona1 = crearPersona("Alan", "Acosta", "Maro");

    // Imprimir la información
    imprimirPersona(persona1);

    return 0;
}