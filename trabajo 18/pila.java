import java.util.ArrayList;
import java.util.List;

public class Main {

    // Tamaño máximo de la pila
    static final int MAX_SIZE = 100;

    // Lista para almacenar los elementos de la pila
    static List<Integer> stack = new ArrayList<>();

    // Función para agregar un elemento a la pila
    static void push(int item) {
        if (stack.size() == MAX_SIZE) { // Verifica si la pila está llena
            System.out.println("Stack Overflow"); // Mensaje de error
            return;
        }
        stack.add(item); // Agrega el elemento al final (parte superior de la pila)
    }

    // Función para eliminar y retornar el elemento superior de la pila
    static int pop() {
        if (stack.isEmpty()) { // Verifica si la pila está vacía
            System.out.println("Stack Underflow"); // Mensaje de error
            return -1; // Retorna -1 para indicar que la pila está vacía
        }
        int top = stack.get(stack.size() - 1);
        stack.remove(stack.size() - 1); // Elimina el último elemento
        return top;
    }

    // Función para ver el elemento superior sin eliminarlo
    static int peek() {
        if (stack.isEmpty()) {
            System.out.println("Pila vacía");
            return -1;
        }
        return stack.get(stack.size() - 1);
    }

    // Función para verificar si la pila está vacía
    static boolean isEmpty() {
        return stack.isEmpty();
    }

    // Función para verificar si la pila está llena
    static boolean isFull() {
        return stack.size() == MAX_SIZE;
    }

    // Programa principal
    public static void main(String[] args) {
        push(10); // Agrega elementos a la pila
        push(20);
        push(30);

        System.out.println("Elemento Superior: " + peek()); // Muestra el elemento superior
        System.out.println("Extrae elemento: " + pop()); // Elimina y muestra el elemento superior
        System.out.println("Elemento Superior: " + peek()); // Muestra el nuevo elemento superior
    }
}
