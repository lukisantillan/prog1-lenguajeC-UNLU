/* 
    Escrir una funcion para calcular el factorial de un numero el ingreso y el calculo del factorial deben ser funciones 
    separadas al programa principal

    OBJETIVO : Calcular la factorial
    DEVUELVE : el resultado
    Pedir numero
    validar que el numero sea mayor a 0
    factorizamos el numero
    DEVOLVER EL N

    IngresarNumero: 
            n = almaceno el numero
            valido si n <= 0
                si es menor pido el reingreso
            devuelvo  n
    
    calcular:
        inicio= guardar el numero de inicio(1)
        hacer ciclo que inicie en 1 y vaya hasta n:
            inicio*= inicio de for 

            fget() -> para ingresar string 
*/
#include <stdio.h>

int ingresoDeNumero() {
    int n;
    printf("Ingresar el numero a calcular:  ");
    scanf("%i", &n);
    while (n < 0)   {
        printf("reingresar el numero a calcular:  ");
        scanf("%i", &n);
    }
    
    return n;
}

int calculo(int n) {
    int x, i;
    x = 1;
    for (i = 1; i <= n; i++)
    {
        x *= i;
    }
    return x;
}



int main(){
    char s;
    int i,cm=0;
    for (i = 0; i < 10; i++)
    {
        printf("Ingrese sexo:   ");
        scanf("%c",&s);
        while (getchar() !='\n');
        if (s =='m')
        {
            cm++;
        }
    }
    printf("\nLa cantidad de mujeres es %i", cm);
}