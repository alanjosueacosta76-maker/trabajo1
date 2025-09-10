class Persona {
    private String nombre;
    private String apellidoPaterno;
    private String apellidoMaterno;

    public Persona(String nombre, String apellidoPaterno, String apellidoMaterno) {
        this.nombre = nombre;
        this.apellidoPaterno = apellidoPaterno;
        this.apellidoMaterno = apellidoMaterno;
    }

    public void imprimir() {
        System.out.println("Nombre completo: " + nombre + " " + apellidoPaterno + " " + apellidoMaterno);
    }
}

public class Main {
    public static void main(String[] args) {
        Persona persona1 = new Persona("Alan", "Acosta", "Maro");
        persona1.imprimir();
    }
}

