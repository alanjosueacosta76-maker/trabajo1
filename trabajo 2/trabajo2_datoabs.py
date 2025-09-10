class Persona:
    def __init__(persona, nombre, apellido_paterno, apellido_materno):
        persona.nombre = nombre
        persona.apellido_paterno = apellido_paterno
        persona.apellido_materno = apellido_materno

    def imprimir(self):
        print(f"Nombre completo: {self.nombre} {self.apellido_paterno} {self.apellido_materno}")

def main():
    # Crear una persona usando la clase
    persona1 = Persona("Alan", "Acosta", "Maro")

    # Imprimir la información
    persona1.imprimir()

if __name__ == "__main__":
    main()

