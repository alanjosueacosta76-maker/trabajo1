public class Main {

    // Función para mezclar dos subarreglos
    public static void merge(int[] a, int l, int m, int r) {
        int a1 = m - l + 1;
        int a2 = r - m;

        // Crear arreglos temporales
        int[] L = new int[a1];
        int[] R = new int[a2];

        // Copiar datos a los arreglos temporales
        for (int i = 0; i < a1; i++)
            L[i] = a[l + i];
        for (int j = 0; j < a2; j++)
            R[j] = a[m + 1 + j];

        // Mezclar los arreglos temporales de vuelta en a[l..r]
        int x = 0, y = 0, k = l;

        while (x < a1 && y < a2) {
            if (L[x] <= R[y]) {
                a[k] = L[x];
                x++;
            } else {
                a[k] = R[y];
                y++;
            }
            k++;
        }

        // Copiar los elementos restantes de L[], si hay
        while (x < a1) {
            a[k] = L[x];
            x++;
            k++;
        }

        // Copiar los elementos restantes de R[], si hay
        while (y < a2) {
            a[k] = R[y];
            y++;
            k++;
        }
    }

    // Función principal de MergeSort
    public static void mergeSort(int[] a, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    // Método principal
    public static void main(String[] args) {
        int[] a = { 10, 28, 54, 11 };
        int s = a.length;

        System.out.println("Arreglo desordenado:");
        for (int i = 0; i < s; i++)
            System.out.print(a[i] + " ");

        mergeSort(a, 0, s - 1);

        System.out.println("\nArreglo ordenado:");
        for (int i = 0; i < s; i++)
            System.out.print(a[i] + " ");

        System.out.println();
    }
}
