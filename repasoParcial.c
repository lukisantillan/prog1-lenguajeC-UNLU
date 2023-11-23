#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define COLUMNAS 3
#define FILAS 1000

/*
 j == 0 rand entre 1 y 2
 j == 1 rand entre 1 y 3
 j == 2 rand entre 1 y 70.
 

 FUNCION 1 - GENERAR LOS DATOS AL AZAR
 INPUT: MATRIZ, CANTIDADFILAS, CANTIDADCOLUMNA
 OUTPUT: void
 La funcion deberá cargar datos aleatorios entre los numeros indicados dependiendo del valor de j. Recibe la matriz y a través de
 dos ciclos for anidados, carga aleatoriamente los datos, verificando el valor de j.

 void funcion(matriz[][], cantidadDefilas, cantidadDeColumnas) {
    paraCada(i = 0; i < cantidadDeFilas; i++) 
    {
        paraCada(j = 0; j < cantidadDeColumnas; j++) 
        {
            si(j == 0)
            {
                matriz[i][j] = rand() % 2;
            }
            si(j == 1)
            {
                matriz[i][j] = rand() % 3:
            }
            si(j == 2)
            {
                matriz[i][j] = rand() % 70;
            }
        }
    }
 }

 OTRA FORMA DE HACERLO
 CON DOS PARAMETROS ENVIADOS (CANTIDAD DE FILAS Y MATRIZ)
 void funcion(matriz[][], cantidadDefilas) {
    paraCada(i = 0; i < cantidadDeFilas; i++) 
    {
        matriz[i][0] = rand() % 2;
        matriz[i][1] = rand() % 3;
        matriz[i][2] = rand() % 70;
    }
 }


 FUNCION 2 - VERIFICAR CUANTAS PERSONAS CUMPLEN CON LOS ARGUMENTOS ENVIADOS.
 INPUT: MATRIZ, CANTIDADFILAS, CANTIDADCOLUMNA, SEXO, ESTADO CIVIL, EDAD
 OUTPUT: CANTIDAD DE PERSONAS QUE CUMPLEN CON LOS ARGUMENTOS.
 La función deberá verificar que las personas que cumplan con los argumentos enviados(sexo, estado civil, edad). Debemos crear una 
 variable auxiliar que aumente en uno cuando las personas cumplan con el requisito para saber cuantas personas hay.

 int funcion2(matriz[][], cantidadDeFilas, Sexo, estadoCivil, edad){
    variableAuxiliar = 0;
    paraCada(i = 0; i < cantidadDeFilas: i++)
    {
        si(matriz[i][0] == sexo && matriz[i][1] == estadoCivil && matriz[i][2] == edad)
        {
            variableAuxiliar += 1;
        }
    }
    devolver variableAuxiliar;
 }

 FUNCION MAIN();
 Deberá tener la inicializacion del srand. Debera tener la matriz declarada. Debemos llamar a la funcion que genere los elementos de
 la matriz, debemos llamar a la funccion que verifique las personas que cumplen. Debe imprimir lo que devuelva la segunda funcion.
 */

void funcionGenerarMatriz(int matriz[FILAS][COLUMNAS], int cantidadFilas, int cantidadColumnas)
{
    int i, j;
    for(i = 0; i < cantidadFilas; i++) 
        {
            for(j = 0; j < cantidadColumnas; j++) 
            {
                if(j == 0)
                {
                    matriz[i][j] = rand() % 2;
                }
                if(j == 1)
                {
                    matriz[i][j] = rand() % 3;
                }
                if(j == 2)
                {
                    matriz[i][j] = rand() % 70;
                }
            }
        }
}

int procesamientoPersonas(int matriz[FILAS][COLUMNAS], int cantidadFilas, int sexo, int estadoCivil,int edad)
{
    int auxiliar = 0, i;
    for (i = 0; i < cantidadFilas; i++)
    {
        if (matriz[i][0] == sexo && matriz[i][1] == estadoCivil && matriz[i][2] == edad)
        {
            auxiliar += 1;
        }
        
    }

    return auxiliar;
}


/*
FUNCION 1
PARAMETROS : matriz[][], cantidad de filas, cantidad de columnas, v[];
OUTPUT : 1 o 0;
precondicion : n > 0;
postcondicion : si el menor numero es > 0 o < 0.
La funcion recibe la matriz la recorre con dos ciclos for anidados, la cantidad de filas y la cantidad de 
columnas. con ayuda de una variable auxiliar, irá comparando y asignando el menor numero de la fila, cuando 
termine cada iteracion del segundo ciclo, la variable auxiliar se almacenara en el vector con el indice
del primer ciclo, al entrar en la siguiente iteracion del segundo ciclo, se reiniciara la variable auxiliar.
necesito otra variable para almacenar el resultado
PSEUDOCODIGO: 
int funcion(matriz[][], cantidadDeFilas, cantidadDeColumnas, v[])
{
    para(i = 0; i < cantidadDeFilas; i++)
    {
        aux= 10000000;
        para(j = 0; j < cantidadDeColumnas; j++)
        {
            si(matriz[i][j] < aux)
            {
                aux = matriz[i][j];
            }
        }
        v[i] = aux;
    }
    resultado = 1;
    para(k = 0; k < cantidadDeFilas; k++)
    {
        si(v[k] < 0)
        {
            resultado = 0-;
        }
    }
    devuelve resultado;
}
*/

int funcionProcesamiento(int matriz[100][100], int cantidadFilas, int cantidadColumnas, int v[]){
    int i,j,k, resultado = 1;
    for (i = 0; i < cantidadFilas; i++)
    {
        int auxiliar = 1000000;
        for (j = 0; j < cantidadColumnas; j++)
        {
            if (matriz[i][j] < auxiliar)
            {
                auxiliar = matriz[i][j];
            }
            if(matriz[i][j] < 0)
            {
                resultado = 0;
            }
        }
        v[i] = auxiliar;
    }
    return resultado;
}

void test_procesamiento(){
    int matriz1[100][100] = {{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[100][100] = {{3,2,1},{6,5,4},{9,-1,100}};
    int matriz3[100][100] = {{-1,-2,-3},{4,5,6},{7,8,9}};
    int filasUtilizadas = 3;
    int columnasUtilizadas = 3;
    int v[filasUtilizadas];
    
    assert(funcionProcesamiento(matriz1, filasUtilizadas, columnasUtilizadas,v) == 1);
    assert(funcionProcesamiento(matriz2, filasUtilizadas, columnasUtilizadas,v) == 0);
    assert(funcionProcesamiento(matriz3, filasUtilizadas, columnasUtilizadas,v) == 0);
    printf("Pruebas pasadas");
}


int main()
{
   test_procesamiento();
   return 0;
}
