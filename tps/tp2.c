#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include "assert.h"
//ejercicio 1;
void almacenarNumeros(int v[], int n, int mayor, int menor) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
         v[i] = rand()%(mayor-menor) + menor;
    }

    for (i = 0; i < n; i++)
    {
        printf("%i\n",v[i]);
    }
    
    
}
//ejercicio 2;
void productoEscalarEntreVectores(int v1[], int v2[], int n){
    int sumatoria = 0, i;
    for (i = 0; i < n; i++)
    {
        sumatoria+= (v1[i] * v2[i]);
    }
    printf("\n\n%d", sumatoria);
    
}
//ejercicio 3;
void sumaEntreVectores(int v1[], int v2[], int n){
    int sumatoria = 0, i;
    for (i = 0; i < n; i++)
    {
        if(i%2 == 0){
        sumatoria += v1[i];
        }
        if (i%2 !=0)
        {
            sumatoria += v2[i];
        }
        
    }
    printf("\n\n%d", sumatoria);
    
}
//ejercicio 4;
void corrimientoAlaDerecha(int v[], int n){
    int i,j;
    int auxiliar;
    for (i = n-1; i >=0; i--)
    {
        if (i == n-1)
        {
            v[i] = auxiliar;
        } else if (i == 0)
        {
            v[i] = auxiliar;
        }
        else v[i] == v[i+1];
    }
    for (j= 0; j < n; j++)
    {
        printf("%i", v[j]);
    }
    
}
// ejercicio 5;
void arrayDeX(){
    char vector[30];
    int i;
    for (i = 0; i < 30; i++){
        vector[i] = 'x';
    }

    srand(time(NULL));
    int indiceA = rand()%30;
    int indiceB = rand()%30;

    vector[indiceA] = 'A';
    vector[indiceB] = 'B';

    printf("vector resultante");
    for (int j = 0; j < 30; j++)
    {
        printf("%c", vector[j]);
    }
    printf("\n");
}
//ejercicio 6;
void distanciaEntreAyB(int v[], int n){
    int i = 0, resultado = 0, posicionA = 0, posicionB = 0;
    bool validarA = true;
    bool validarB = true;
    while (validarA || validarB)
    {
        if (v[i] == 'A')
        {
            posicionA = i;
            validarA = false;
        } else if (v[i] == 'B'){
            posicionB = i;
            validarB = false;
        }
        i++;
    }
    resultado = posicionB - posicionA;
}
//ejercicio 7;
void edadDeMayorFrecuencia(){
    int edad[1000];
    int i;
    int mayorEdad = 0;
    int frecuenciaDeMayorEdad = 0;
    srand(time(NULL));
    for (i = 0; i < 1000; i++){
        edad[i] = rand()%100;
    }
    for (int j = 0; j<1000; j++)
    {
        int edadActual = edad[j];
        int frecuenciaActual = 1;
        for (int k = j+1; k<1000; k++)
        {
            if (edadActual == edad[k])
            {
                frecuenciaActual++;
            }
            
        }
        if (frecuenciaActual > frecuenciaDeMayorEdad)
        {
            mayorEdad = edadActual;
            frecuenciaDeMayorEdad = frecuenciaActual;
        }
        
    }
    
}
//ejercicio 8;
void sonIguales(int v1[], int v2[], int n){
    int i;
    int chequeoIguales = 0;
    for (i = 0; i < n; i++)
    {
        if (v1[i] != v2[i])
        {
            chequeoIguales = 1;
        }
        
    }
    
    if (chequeoIguales == 0)
    {
        printf("Los vectores son idénticos");
    } else 
    printf("Los vectores son diferentes");
    
}
//ejercicio 9;
void elementosRepetidos(int v[], int n) {
    int i,j;
    int cantidadDeModificaciones = 0;
    for ( i = 0; i < n; i++)
    {
        for (j = i + 1 ; j < n; j++)
        {
            if (v[i] == v[j] && v[i] != -1)
            {
                v[j] = -1;
                cantidadDeModificaciones +=1;
            }
            
        }
        
    }
    printf("La cantidad de modificaciones es %d", cantidadDeModificaciones);
}
//ejercicio 10;
int numerosNegativos(int v[], int n) {
    int i;
    int contador = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            contador += 1;
        }
        
    }
    return contador;
}
//ejercicio 11;
int numerosCeros(int v[], int n) {
    int i;
    int contador = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            contador += 1;
        }
        
    }
    return contador;
}
//ejercicio 12;
int numerosPositivos(int v[], int n) {
    int i;
    int contador = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            contador += 1;
        }
        
    }
    return contador;
}
//ejercicio 13;
void procesamientoDeNumeros(int v[], int n) {
    int ceros = numerosCeros(v,n);
    int positivos = numerosPositivos(v, n);
    int negativos = numerosNegativos(v, n);
    printf("El vector tiene %i cantidad de numeros", n);
    printf("\n De los cuales");
    printf("\t\t\t\n%i son negativos", negativos);
    printf("\t\t\t\n%i son positivos", positivos);
    printf("\t\t\t\n%i son cero", ceros);

}
//ejercicio 14;
int numeroMayorDelVector(int v[], int n) {
    int i;
    int mayor= -100000000;
    for (i = 0; i < n; i++)
    {
        if (v[i] > v[i + 1])
        {
            mayor = v[i];
        }
        
    }
    return mayor;
    printf("El mayor numero del array es %d", mayor);
}
void test_mayor(){
    int v1[5] = {1,2,3,4,5};
    int v2[2] = {-100,3};
    int v3[1] = {2};
    int v4[2] = {-100,-40};
    printf("Corriendo el test mayor");
    assert(numeroMayorDelVector(v1,5) == 5);
    assert(numeroMayorDelVector(v2,2) == 3);
    assert(numeroMayorDelVector(v3,1) == 2);
    assert(numeroMayorDelVector(v4,2) == -40);
    printf("\nPasó");
}
//ejercicio 15;
void sumaDeImpares(int v[], int n){
    int i;
    int suma = 0;
    for (i = 0; i < n; i++)
    {
        if (i%2 != 0)
        {
            suma+=v[i];
        }
    }
    printf("La suma de los elementos impares del vector es: %i  ", suma);
}
//ejercicio 16;
int cantidadDeX(int v[],int n, int x) {
    int i;
    int coincidencia = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            coincidencia++;
        }
        
    }
    return coincidencia;
}
int lugarEnlaLista(int v[], int n, int x){
    int lugar;
    bool flag = true;
    int i = 0;
    while (flag || i != n)
    {
        if (v[i] == x)
        {
            lugar = i;
            flag = false;
        }
        i++; 
    }
    if (i == n)
    {
        /* code */
    }
    
    return lugar;
} 
int buscarTodosLosElementos(int v[], int n, int x){
    int i;
    int NuevoVector[] = {};
    for (i = 0; i < n; i++)
    {
        
    }
    

}


void mostrar(int v[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("\n%d", v[i]);
    }
}

int main(){
   test_mayor();
}
