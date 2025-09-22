public class Main {


    public static void burbuja(int[] arr) {
        int n = arr.length;
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
            
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }


    public static void imprimirArreglo(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {
        int[] lista = {5, 3, 8, 4, 2};

        System.out.print("Lista desordenada: ");
        imprimirArreglo(lista);

        burbuja(lista);

        System.out.print("Lista ordenada: ");
        imprimirArreglo(lista);
    }
}
