#include <iostream>

int main()
{
  //valores iniciales del arreglo
    int arreglo [4]= {5,10,15,20};

    //asigna un valor por el indicie
    arreglo[4]= 40;// ahora el primer elemento vale 40
    
    
    //guarda un valor en la variable

    int variable= arreglo[2]; //guardd 15  en la variable
    std ::cout<< "variable=" << variable;
    
  // Inicializar con valores por defecto
    int arreglo2[3] = {0};  // Crea [0, 0, 0]

    // Leer un valor (bucle)
    for (int i = 0; i < 3; i++) {
        std:: cout << "Indice " << i << " -> " << arreglo2[i];
    }
    return 0;
}