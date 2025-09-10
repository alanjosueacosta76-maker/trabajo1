import java.util.Scanner;

public class BusquedaLineal {
    public static void main(String[] args) {
        int[] arreglo = {5, 8, 3, 10, 7, 2, 15, 9};
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Ingrese el número a buscar: ");
        int elemento = scanner.nextInt();
        
        boolean encontrado = false;
        
        for (int i = 0; i < arreglo.length; i++) {
            if (arreglo[i] == elemento) {
                System.out.println("Elemento " + elemento + " encontrado en la posición " + i + ".");
                encontrado = true;
                break;  // Detener búsqueda al encontrar el elemento
            }
        }
        
        if (!encontrado) {
            System.out.println("Elemento " + elemento + " no encontrado en el arreglo.");
        }
        
        scanner.close();
    }
}
