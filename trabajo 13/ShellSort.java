public class ShellSort {

    // Muestra los elementos del arreglo en una sola línea
    public static void mostrarArreglo(int[] arreglo) {
        for (int num : arreglo) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Ordena un arreglo usando el algoritmo Shell Sort
    public void ordenar(int[] arreglo) {
        int tamaño = arreglo.length;
        int salto = tamaño / 2; // Se empieza con un "salto" grande

        // Mientras el salto sea mayor que cero, seguimos ordenando
        while (salto > 0) {
            // Recorremos los elementos desde 'salto' hasta el final
            for (int j = salto; j < tamaño; j++) {
                int valor = arreglo[j]; // Elemento actual a comparar
                int k = j;

                // Compara y mueve los elementos que estén fuera de orden
                while (k >= salto && arreglo[k - salto] > valor) {
                    arreglo[k] = arreglo[k - salto];
                    k = k - salto;
                }

                // Inserta el elemento en su posición correcta
                arreglo[k] = valor;
            }

            // Reduce el salto a la mitad en cada iteración
            salto = salto / 2;
        }
    }

    public static void main(String[] args) {
        int[] arreglo = {36, 38, 44, 11, 19, 30, 28, 50};

        System.out.println("Arreglo desordenado:");
        mostrarArreglo(arreglo);

        ShellSort obj = new ShellSort();
        obj.ordenar(arreglo);

        System.out.println("Arreglo ordenado:");
        mostrarArreglo(arreglo);
    }
}
