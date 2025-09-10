#include <iostream>
using namespace std;

int main()
{
    int arreglo[]= {10, 20, 30, 40, 50};
    int tamaño = sizeof (arreglo) / sizeof(arreglo[0]);
    
    std::cout<<"Recorrido del arreglo:"<< endl;
    for (int i=0; i < tamaño; i++){
        std::cout<< arreglo[i]<<endl;
    }

    return 0;
}