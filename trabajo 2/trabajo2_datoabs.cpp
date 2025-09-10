#include <iostream>
#include <string>

using namespace std;

// Definición de la clase Persona
class Persona {
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;

public:
    // Constructor
    Persona(const string& nombre, const string& apPaterno, const string& apMaterno)
        : nombre(nombre), apellidoPaterno(apPaterno), apellidoMaterno(apMaterno) {}

    // Método para imprimir la información de la persona
    void imprimir() const {
        cout << "Nombre completo: " << nombre << " " << apellidoPaterno << " " << apellidoMaterno << endl;
    }
};

int main() {
    // Crear una persona usando la clase
    Persona persona1("Alan", "Acosta", "Maro");

    // Imprimir la información
    persona1.imprimir();

    return 0;
}
