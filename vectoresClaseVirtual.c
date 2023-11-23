// Ejemplo de Menu en C
#include <stdio.h>
#include <stdlib.h>
#define N 10
void mostrarMenu(){
    system("clear"); // BORRA
    printf("\n\t\t\t Menú Principal\n"); // \t para que tabule
    printf("\t\t 1. Ingresar 10 Números\n");
    printf("\t\t 2. Ver los nūmeros ingresados\n");
    printf("\t\t 3. Mostrar la suma de todos\n");
    printf("\t\t 4. Mostrar el promedio\n");
    printf("\t\t 5. Mostrar el menor y su posición\n");
    printf("\t\t 6. Mostrar el mayor y su posición\n");
    printf("\t\t 7. Modificar un valor\n");
    printf("\n\t\t\t 0. Salir\n");
}

void cargar(int v[], int tam) {
    int i;
    for (i= 0; i < tam; i++)
    {
        printf("Ingrese el valor %i  :     ", i+1);
        scanf("%d", &v[i]);

    }
}

void mostrar(int v[], int tam) {
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\t\t\t%i", v[i]);
    }
    
}

void suma(int v[], int tam) {
    int acumulador = 0, i;
    for (i = 0; i < tam; i++)
    {
        acumulador += v[i];
    }
    printf("La suma de todos los elementos es %i", acumulador);
}

void promedio(int v[], int tam){
    int acumulador = 0, i;
    float promedio;
    for (i = 0; i < tam; i++)
    {
        acumulador += v[i];
    }
    promedio = acumulador / tam;
    printf("El promedio de los elementos del vector es: %.2f", promedio);
    
}

void mayor(int v[], int tam){
    int posicion,mayor,i;
    posicion=0;
    mayor = v[0];
    for (i = 0; i < tam; i++)
    {
        if (v[i] > mayor)
        {
            posicion = i;
            mayor = v[i];
        }
        
    }
    printf("El elemento mas grande del array es %i y esta en la posición %i", mayor,posicion);
}

void menor(int v[], int tam){
    int posicion,menor,i;
    posicion=0;
    menor = v[0];
    for (i = 0; i < tam; i++)
    {
        if (v[i] < menor)
        {
            posicion = i;
            menor = v[i];
        }
    }
    printf("El elemento mas chico del array es %i y esta en la posición %i", menor,posicion);
}

void modificar(int v[], int tam) {
    int numeroAmodificar, i, numeroNuevo;
    printf("Ingrese el numero que quiere modificar: ");
    scanf("%d", &numeroAmodificar);
    printf("Ingrese el numero por el que lo quiere reemplazar: ");
    scanf("%d", &numeroNuevo);
    for (i = 0; i < tam; i++)
    {
        if (numeroAmodificar == v[i])
        {
            v[i] = numeroNuevo;
        }
        
    }
    
}

int main(void){
    int numeros[N];
    int salir=1,opcion;
    while (salir!= 0)
    {
        mostrarMenu();
        printf("\nIngrese una opción:   ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cargar(numeros,N);
        break;
        
        case 2:
            mostrar(numeros,N);
        break;
        case 3:
            suma(numeros,N);
        break;
        
        case 4:
            promedio(numeros,N);
        break;
        case 5:
            menor(numeros,N);
        break;
        case 6:
            mayor(numeros,N);
        break;
        case 7:
            modificar(numeros,N);
        break;
        case 0:
            salir = 0;
        break;

        default:
        printf("%d Es una opcion incorrecta\n", opcion); 
            break;
        }
    }
    
    return 0;
}
