import random 
def selection_sort(lista):
    n = len(lista)
    
    for i in range(n):
        # Suponemos que el elemento actual es el mínimo
        min_index = i
        
        # Buscamos el mínimo en el resto de la lista
        for j in range(i + 1, n):
            if lista[j] < lista[min_index]:
                min_index = j
        
        # Si encontramos uno menor, lo intercambiamos
        if min_index != i:
            lista[i], lista[min_index] = lista[min_index], lista[i]

    return lista
    
lista=[random.randint(1,100) for _ in range(10)]
print("Lista desordenada:")
print (lista)
    
selection_sort(lista)
print("Lista ordenada:")    
print(lista)