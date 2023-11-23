#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void ordenamiento(int v[], int tam, char opcion[2]) {
    int i, j;
    int aux;
    if (opcion == "A" || opcion == "a")
    {
        for (i = 0; i < tam; i++)
        {
            for ( j = 0; j < tam-1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    aux = v[j+1];
                    v[j+1] = v[j];
                    v[j] = aux;
                }
                
            }
        }
    } else if (opcion == "B" || opcion == "b")
    {
       for (i = 0; i < tam; i++)
        {
            for ( j = 0; j < tam-1; j++)
            {
                if (v[j] < v[j + 1])
                {
                    aux = v[j+1];
                    v[j+1] = v[j];
                    v[j] = aux;
                }
                
            }
        }
    }   
}

int encontrarX(int v[], int *tam, int x){
    int flagEncotro = 0;
    int inferior = 0;
    int superior = *tam-1;
    int resultado;

    while ((inferior <= superior) &&  flagEncotro == 0);
    {
        int centro = (inferior + superior) / 2;
        if (x == v[centro])
        {
            resultado = centro;
            flagEncotro = 1;
        } else {
            if (x < v[centro])
            {
                superior = centro - 1;
            } else {
                inferior = centro + 1;
            }
        }
    }
    int i = 0;
    int aux;
    int aux2;
    while (flagEncotro == 0)
    {
        if (v[i]> x)
        {
            aux = v[i];
            v[i] = x;
            flagEncotro = 1;
        }
        i++;
    }
    *tam +=1;
    for (int k = i + 1; k < tam-1; i++)
        {
            aux2 = v[k];
            v[k+1] = aux;
            aux = aux2;
        }
    resultado = i;
    return resultado;
}


void mostrar(int v[], int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d\t ", v[i]);
    }
    
}

int main()
{
    int arreglo_ordenado[] = {1, 3, 5, 7, 9};
    int n = 5;
    int elemento = 4;
    int posicion = encontrarX(arreglo_ordenado, n, elemento);
    printf("%i", posicion);

    

    return 0;
    return 0;
}
