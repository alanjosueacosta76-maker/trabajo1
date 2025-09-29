using System;

public class Persona
{

    public string Nombre { get; set; }
    public string ApellidoPaterno { get; set; }
    public string ApellidoMaterno { get; set; }


    public Persona(string nombre, string apellidoPaterno, string apellidoMaterno)
    {
        Nombre = nombre;
        ApellidoPaterno = apellidoPaterno;
        ApellidoMaterno = apellidoMaterno;
    }


    public void Imprimir()
    {
        Console.WriteLine($"Nombre completo: {Nombre} {ApellidoPaterno} {ApellidoMaterno}");
    }
}

class Program
{
    static void Main()
    {

        Persona persona1 = new Persona("Alan", "Acosta", "Maro");


        persona1.Imprimir();
    }
}
