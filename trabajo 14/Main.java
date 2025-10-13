import java.util.ArrayList;
import java.util.List;

public class Main {

    // Método de ordenamiento por inserción para una cubeta
    public static void ordenamientoInsercion(List<Float> cubeta) {
        for (int j = 1; j < cubeta.size(); j++) {
            float valor = cubeta.get(j);
            int k = j - 1;

            while (k >= 0 && cubeta.get(k) > valor) {
                cubeta.set(k + 1, cubeta.get(k));
                k--;
            }
            cubeta.set(k + 1, valor);
        }
    }

    // Función principal del algoritmo Bucket Sort
    public static void ordenamientoBucket(List<Float> arreglo) {
        int tamaño = arreglo.size();
        List<List<Float>> cubetas = new ArrayList<>(tamaño);

        // Inicializar cubetas vacías
        for (int i = 0; i < tamaño; i++) {
            cubetas.add(new ArrayList<>());
        }

        // Distribuir elementos en cubetas
        for (float num : arreglo) {
            int indice = (int)(tamaño * num);
            if (indice == tamaño) // Evita índice fuera de rango
                indice = tamaño - 1;
            cubetas.get(indice).add(num);
        }

        // Ordenar cada cubeta
        for (List<Float> cubeta : cubetas) {
            ordenamientoInsercion(cubeta);
        }

        // Concatenar cubetas al arreglo original
        int indiceArreglo = 0;
        for (List<Float> cubeta : cubetas) {
            for (float num : cubeta) {
                arreglo.set(indiceArreglo++, num);
            }
        }
    }

    public static void main(String[] args) {
        List<Float> arreglo = new ArrayList<>();
        arreglo.add(0.88f);
        arreglo.add(0.16f);
        arreglo.add(0.48f);
        arreglo.add(0.25f);
        arreglo.add(0.75f);
        arreglo.add(0.99f);
        arreglo.add(0.23f);
        arreglo.add(0.11f);
        arreglo.add(0.24f);
        arreglo.add(0.67f);

        System.out.println("Arreglo desordenado:");
        for (float num : arreglo) {
            System.out.print(num + " ");
        }
        System.out.println();

        ordenamientoBucket(arreglo);

        System.out.println("Arreglo ordenado:");
        for (float num : arreglo) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
