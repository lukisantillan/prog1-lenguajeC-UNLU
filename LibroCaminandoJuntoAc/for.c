#include <stdio.h>
#include <math.h>
#define PULGADA 0.393701
void imprimirDeDiezAuno() {
    int i;
    for (i = 10; i > 0; i--)
    {
        printf("\n%i", i);
    }

}

void potencias() {
    int i,j;
    int potencia;
    for (i = 1; i <= 10; i++)
    {
        printf("Las 3 primeras potencias del numero %i son: \n",i);
        for ( j = 1; j<= 3; j++)
        {
            potencia = pow(i,j);
            printf("%i a la %i es: %i\n", i,j,potencia);
        }
        
    }
}

void tablaDeMultiplicar() {
    int i,x,resultado;
    printf("Ingrese un numero para ver su tabla de multiplicación:  ");
    scanf("%i", &x);
    for (i = 0; i <= 10; i++)
    {
        resultado = x*i;
        printf("\nEl %i multiplicado por %i, da como resultado: %i",x,i,resultado);
    }
    
}

void algoritmo(){
    int sumaX = 0,impares = 0,producto = 0,x,y,i, promedio;
    for (i = 1; i <=10; i++)
    {
        printf("Ingrese x:  ");
        scanf("%i",&x);
        printf("Ingrese y:  ");
        scanf("%i",&y);
        sumaX += x;
        if (y%2 != 0)
        {
            impares +=1;
        }
        if (x*y >= 8 && x*y <= 20)
        {
            producto += 1;
        }
        promedio = sumaX
    }
    

}
int main(){
    tablaDeMultiplicar();
    return 0;
}
