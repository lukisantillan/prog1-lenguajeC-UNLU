#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarVector(int v[], int cantidad) {
    int i;
    int valorInicial= 0;
    for (i = 0; i < cantidad; i++)
    {
        int x = valorInicial + rand()%10;
        if (x == valorInicial)
        {
            x += 1;
        }
        
        v[i] = x;
        valorInicial = x;
    }
    
}

void mostrarVector(int v[], int cantidad) {
    int i;
    for (i = 0; i < cantidad; i++)
    {
        printf("%i , ", v[i]);
    }
}


int buscarBin(int v[], int elemento, int cantidad){
    int valorInicial = 0;
    int valorFinal = cantidad - 1;
    int encontrado = 0;
    int resultado = -1;
    int i= 0;
    int centro;
    printf("\nINICIO:     VALOR INICIAL: %i   VALOR FINAL: %i", valorInicial, valorFinal);
    while ((valorInicial <= valorFinal) && encontrado == 0)
    {
        centro = (valorFinal + valorInicial) / 2;
        if (elemento == v[centro])
        {
            resultado = centro;
            encontrado = 1;
        } else {
            if (elemento < v[centro])
            {
                valorFinal = centro - 1;
            } else if (elemento > v[centro])
            {
               valorInicial = centro + 1;
            }
        }
         i++;
        printf("\n\t\t\t %i", centro);
        printf("\n\nVALOR INICIAL: %i   VALOR FINAL: %i", valorInicial, valorFinal);
    }
    printf("\n\n\t\tCANTIDAD DE ITERACIONES: %i ", i);
    return resultado;
    
} 
int main()
{
    srand(time(NULL));
    int vector[1000];
    int cantidadUsada = 500;
    cargarVector(vector, cantidadUsada);
    mostrarVector(vector, cantidadUsada);
    int elementoAbuscar;
    printf("\nIngrese el elemento a encontrar : ");
    scanf("%i", &elementoAbuscar);
    int resultado = buscarBin(vector, elementoAbuscar, cantidadUsada);
    if (resultado == -1)
    {
        printf("\n EL NUMERO NO SE ENCUENTRA EN EL VECTOR ");
    } else {
        printf("\nEl numero encontrado esta en en lugar %i", resultado+1);
    }

    
    return 0;
}
