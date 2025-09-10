
public class Main
{
 public static void main(String[] args) {
        // Lista con valores inicializados
        int[] arreglo = {5, 10, 15, 20};

        // Asignar un valor por medio del índice
        arreglo[0] = 40;  // Ahora el primer elemento vale 40

        // Guardar un valor en variable
        int variable = arreglo[2];  // guarda 15 en la variable
        System.out.println("Variable = " + variable);

        // Inicializar con valores por defecto
        int[] arreglo2 = new int[3];   // Crea [0, 0, 0]

        // Leer un valor (bucle)
        for (int i = 0; i < arreglo2.length; i++) {
            System.out.println("Indice " + i + " -> " + arreglo2[i]);
        }
    }
}
