#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define medida 4

void suma(int *n1, int n2){
    *n1 = *n1 + 1;
    n2 = n2 + 1;
}
/*void vector(){
    int vector[6];
    int medidaVector = sizeof(vector) / sizeof(vector[0]);
    for (int i = 0; i < medidaVector; i++)
    {
        vector[i] = rand()%(35-27) + 27;
        printf("%i\n", vector[i]);
    }
}
*/
void vectorDos(int v[], int m){
    for (int i = 0; i < m; i++)
    {
        printf("Ingrese el valor a guardar en el lugar %i   ", i+1);
        scanf("%i",&v[i]);
    }
}

void mostrarVector(int *v, int m){
    for (int i = 0; i < m; i++)
    {
        printf("Indice %i - output %i\n",i, v[i]);
    }
    

}

int main(){
    int i = 5;
    int* p;
    p = &(i); //Un puntero es una variable con una direccion de memoria
    printf("%p, %p, %p, %lu\n", &i, p, p+1,sizeof(i));

    char c = 5;
    char* pc;
    pc = &(c);
    printf("%p, %p, %p, %lu\n", &c, pc, pc+1,sizeof(c));
    return 0;

}
