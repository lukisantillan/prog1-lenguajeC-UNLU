 /*
    IF EN C VS PYTHON
        - if(condicion):
            codigo a ejectuar    ->> python

        - if(condición) {
            codigo a ejecutar;
        }                         ->> C, para agregar else escribir y abrir llaves
    
    FOR EN C VS PYTHON
        - for i in range(1,10,2):
        codigo a ejecutar ---> PYTHON

        - for(i = 1; i < 10; i + 3) {
            codigo a ejecutar;
        }                  ---> C 

    WHILE EN C VS PYTHON 
    `   -   while(condicion):
                codigo a ejecutar -> python
        
        - while(condicion){
            codigo a ejecutar;
        } ---> C

    void para no retornar nada

    La ultima instruccion de main siempre es return 0 si todo resulta bien
    stdio.h
    stdlib.h
    string.h


    PSEUDOCODIGO DEL EJERCICIO 7- 
    Salidas = promedio y condiciones 
    1- pedir y validar dos notas
    2- sumar y dividir por 2
    3- evaluar la condición (2 aprobados, (>= promovido, <7 && >=4 regular, libre)
*/
  

#include <stdio.h>

int sumaDeNumeros(int a, int b) {
    int suma;
    suma = a;
    for (int i = a; i <= b; i++)
    {
        suma += i;
    }
    
    return suma;
}
int resta(int a, int b){
    int resta;
    resta= a;
    for (int i = a; i <= b; i++)
    {
        resta -= i;
    }
    return resta;

}

int multiplicacion(int a, int b) {
    int multi;
    multi = a * b;
    return multi;
}

/* como corrección personal, me falto modularizar mas, ademas de tener en cuenta que los numeros tienen que venir como parametros
float notaFinal() {
    float nota1, nota2, sumaDeNotas;
    printf("Ingrese la nota del primer parcial  ");
    scanf("%f", &nota1);
    printf("Ingrese la nota del segundo parcial  ");
    scanf("%f", &nota2);
    sumaDeNotas = (nota1 + nota2) / 2;
    if (sumaDeNotas >= 7)
    {
        printf("Promovido, su promedio es %.1f", sumaDeNotas);
    } else if (sumaDeNotas < 7 && nota1 >= 4 && nota2 >= 4)
    {
        printf("Regular, su promedio es %.1f", sumaDeNotas);
    } else if (nota1 < 4 || nota2 <4)
    {
        printf("Libre", sumaDeNotas);
    }
    return sumaDeNotas;
}*/

float ingresoDeNotas() {
    float nota;
    printf("Ingrese la nota del  parcial  ");
    scanf("%f", &nota);
    while (nota < 1 || nota> 10)
    {
        printf("Reingrese la nota del parcial(1-10)  ");
        scanf("%f", &nota);
    }
    return nota;
}


// Función para determinar la situación del alumno y mostrar el resultado
void determinarSituacion(float nota1, float nota2) {
    float promedio;
    promedio = (nota1 + nota2) / 2;
    if (nota1 >= 4 && nota2 >= 4) {
        if (promedio >= 7) {
            printf("Situación: Promovido\n");
            printf("Nota promedio: %.2f\n", promedio);
        } else {
            printf("Situación: Regular\n");
            printf("Nota promedio: %.2f\n", promedio);
        }
    } else {
        printf("Situación: Libre\n");
    }
}

void tipoDeBomba(int x) {
    switch (x)
    {
    case 0:
        printf("No hay establecido un valor definido para el tipo de bomba");
        break;
    case 1:
        printf("La bomba es una bomba de agua");
        break;
    case 2:
        printf("La bomba es una bomba de gasolina");
        break;
    case 3:
        printf("La bomba es una bomba de hormigón");
        break;
    case 4:
        printf("La bomba es una bomba de pasta alimenticia");
        break;
    default:
        printf("No existe un valor válido para tipo de bomba");
        break;
    }
}

int main(){
    float nota1, nota2;
    nota1 = ingresoDeNotas();
    nota2 = ingresoDeNotas();
    determinarSituacion(nota1,nota2);

    return 0;
}