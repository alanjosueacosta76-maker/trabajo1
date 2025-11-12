import java.util.Random;

public class Main{

    public static void countingSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10];

        // Contar la cantidad de ocurrencias de cada dígito
        for (int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        // Sumar los conteos acumulados
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Construir el arreglo de salida (de derecha a izquierda para estabilidad)
        for (int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // Copiar los resultados al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    public static void radixSort(int[] arr) {
        int maxNum = arr[0];
        for (int num : arr) {
            if (num > maxNum)
                maxNum = num;
        }

        for (int exp = 1; maxNum / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[20];

        // Generar 20 números aleatorios entre 1 y 9999
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(9999) + 1;
        }

        System.out.println("Arreglo desordenado:");
        for (int num : arr) System.out.print(num + " ");
        System.out.println();

        // Ordenar con Radix Sort
        radixSort(arr);

        System.out.println("\nArreglo ordenado:");
        for (int num : arr) System.out.print(num + " ");
        System.out.println();
    }
}
