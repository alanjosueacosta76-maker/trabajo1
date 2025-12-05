#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura del Nodo
struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

// Clase Arbol Binario de Busqueda
class ArbolBinarioBusqueda {
public:
    Nodo* raiz;

    ArbolBinarioBusqueda() { raiz = NULL; }

    // Insertar nodo
    Nodo* agregarNodo(Nodo* nodoActual, int nuevoDato) {
        if (nodoActual == NULL) {
            Nodo* nuevoNodo = new Nodo();
            nuevoNodo->dato = nuevoDato;
            nuevoNodo->izq = NULL;
            nuevoNodo->der = NULL;
            return nuevoNodo;
        }
        if (nuevoDato < nodoActual->dato)
            nodoActual->izq = agregarNodo(nodoActual->izq, nuevoDato);
        else if (nuevoDato > nodoActual->dato)
            nodoActual->der = agregarNodo(nodoActual->der, nuevoDato);

        return nodoActual;
    }

    // Buscar nodo con ruta
    void buscarNodo(Nodo* nodoActual, int datoBuscado, string ruta) {
        if (nodoActual == NULL) {
            cout << ruta << " -> X (No encontrado)\n";
            return;
        }

        ruta += to_string(nodoActual->dato);

        if (nodoActual->dato == datoBuscado)
            cout << ruta << " (Encontrado!)\n";

        else if (datoBuscado < nodoActual->dato)
            buscarNodo(nodoActual->izq, datoBuscado, ruta + " -> Izq -> ");

        else
            buscarNodo(nodoActual->der, datoBuscado, ruta + " -> Der -> ");
    }

    // Encontrar valor minimo (auxiliar para eliminar)
    Nodo* obtenerMinimo(Nodo* nodoActual) {
        while (nodoActual->izq != NULL)
            nodoActual = nodoActual->izq;
        return nodoActual;
    }

    // Eliminar nodo
    Nodo* eliminarNodo(Nodo* nodoActual, int datoEliminar) {
        if (nodoActual == NULL) return nodoActual;

        if (datoEliminar < nodoActual->dato)
            nodoActual->izq = eliminarNodo(nodoActual->izq, datoEliminar);

        else if (datoEliminar > nodoActual->dato)
            nodoActual->der = eliminarNodo(nodoActual->der, datoEliminar);

        else {
            if (nodoActual->izq == NULL) {
                Nodo* temp = nodoActual->der;
                delete nodoActual;
                return temp;
            }
            else if (nodoActual->der == NULL) {
                Nodo* temp = nodoActual->izq;
                delete nodoActual;
                return temp;
            }

            Nodo* temp = obtenerMinimo(nodoActual->der);
            nodoActual->dato = temp->dato;
            nodoActual->der = eliminarNodo(nodoActual->der, temp->dato);
        }

        return nodoActual;
    }

    // Recorridos
    void recorridoInorden(Nodo* nodoActual) {
        if (nodoActual != NULL) {
            recorridoInorden(nodoActual->izq);
            cout << nodoActual->dato << " ";
            recorridoInorden(nodoActual->der);
        }
    }

    void recorridoPreorden(Nodo* nodoActual) {
        if (nodoActual != NULL) {
            cout << nodoActual->dato << " ";
            recorridoPreorden(nodoActual->izq);
            recorridoPreorden(nodoActual->der);
        }
    }

    void recorridoPostorden(Nodo* nodoActual) {
        if (nodoActual != NULL) {
            recorridoPostorden(nodoActual->izq);
            recorridoPostorden(nodoActual->der);
            cout << nodoActual->dato << " ";
        }
    }

    // Altura y Tamano
    int calcularAltura(Nodo* nodoActual) {
        if (nodoActual == NULL) return 0;
        return 1 + max(calcularAltura(nodoActual->izq), calcularAltura(nodoActual->der));
    }

    int calcularTamano(Nodo* nodoActual) {
        if (nodoActual == NULL) return 0;
        return 1 + calcularTamano(nodoActual->izq) + calcularTamano(nodoActual->der);
    }

    // Exportar a archivo
    void guardarInorden(Nodo* nodoActual, ofstream& archivo) {
        if (nodoActual != NULL) {
            guardarInorden(nodoActual->izq, archivo);
            archivo << nodoActual->dato << " ";
            guardarInorden(nodoActual->der, archivo);
        }
    }
};

// Funcion principal
int main() {
    ArbolBinarioBusqueda arbol;
    string lineaTexto, instruccion;
    int numero;

    cout << "--- Gestor BST (Modo Consola) ---\n";
    cout << "Escriba 'help' para ver los comandos disponibles.\n";

    while (true) {
        cout << "BST> ";
        if (!getline(cin, lineaTexto)) break;
        if (lineaTexto.empty()) continue;

        stringstream ss(lineaTexto);
        ss >> instruccion;

        if (instruccion == "exit") break;

        else if (instruccion == "help") {
            cout << "Comandos disponibles:\n";
            cout << "  insert <n>   : Agrega un numero al arbol.\n";
            cout << "  search <n>   : Busca un numero mostrando la ruta.\n";
            cout << "  delete <n>   : Elimina un numero del arbol.\n";
            cout << "  inorder      : Muestra recorrido Inorden.\n";
            cout << "  preorder     : Muestra recorrido Preorden.\n";
            cout << "  postorder    : Muestra recorrido Postorden.\n";
            cout << "  height       : Muestra la altura del arbol.\n";
            cout << "  size         : Muestra la cantidad de nodos.\n";
            cout << "  export       : Guarda el inorden en 'arbol_cpp.txt'.\n";
            cout << "  exit         : Cierra el programa.\n";
        }

        else if (instruccion == "insert") {
            if (ss >> numero) {
                arbol.raiz = arbol.agregarNodo(arbol.raiz, numero);
                cout << "Insertado: " << numero << endl;
            } else cout << "Error: Falta el numero (ej: insert 5)\n";
        }

        else if (instruccion == "search") {
            if (ss >> numero) {
                cout << "Ruta: ";
                arbol.buscarNodo(arbol.raiz, numero, "");
            } else cout << "Error: Falta el numero (ej: search 5)\n";
        }

        else if (instruccion == "delete") {
            if (ss >> numero) {
                arbol.raiz = arbol.eliminarNodo(arbol.raiz, numero);
                cout << "Eliminado: " << numero << endl;
            } else cout << "Error: Falta el numero (ej: delete 5)\n";
        }

        else if (instruccion == "inorder") {
            cout << "Inorden: ";
            arbol.recorridoInorden(arbol.raiz);
            cout << endl;
        }

        else if (instruccion == "preorder") {
            cout << "Preorden: ";
            arbol.recorridoPreorden(arbol.raiz);
            cout << endl;
        }

        else if (instruccion == "postorder") {
            cout << "Postorden: ";
            arbol.recorridoPostorden(arbol.raiz);
            cout << endl;
        }

        else if (instruccion == "height") {
            cout << "Altura: " << arbol.calcularAltura(arbol.raiz) << endl;
        }

        else if (instruccion == "size") {
            cout << "Tamano: " << arbol.calcularTamano(arbol.raiz) << endl;
        }

        else if (instruccion == "export") {
            ofstream archivo("arbol_cpp.txt");
            if (archivo.is_open()) {
                arbol.guardarInorden(arbol.raiz, archivo);
                archivo.close();
                cout << "Guardado en arbol_cpp.txt\n";
            } else cout << "Error al abrir archivo.\n";
        }

        else {
            cout << "Comando no reconocido. Escriba 'help'.\n";
        }
    }

    return 0;
}
