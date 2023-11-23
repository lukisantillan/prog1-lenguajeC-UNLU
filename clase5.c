#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Para lograr que el programa funciones correctamente, necesito crear una funcion que vaya intercambiando dos elementos a la vez
para intercambiarlo necesitamos una variable auxiliar que almacene el elemento antes de ser reemplazado, cuando la funcion reemplace
el elemento de la fila por el de la columna, reemplazamos el de la columna por el auxiliar, y asi hasta que termine de reemplazar
todos los elementos de la matriz.

funcion mostrar(mattriz,columnasUsadas, filasUsadas)
        Recibe la matriz, la columnaUsada, la filaUsada. Con dos ciclos amnidados, la recorre y muestra elemento x elemento.

funcion cargarAzar(matriz,filasAusar,columnasAusar)
        Recibe la matriz, la filasAusar, la columnasAusar. Con dos ciclos amnidados, la recorre y carga elemento x elemento usando la 
        funcionRand.

funcion intercambiar(matriz,fila,columna)
        recibe la matriz, la filasUsadas, la columnasUsadas. Usando la variable auxiliar, y realiza la funcion de intercambio.

funcion main()
        definela matriz(tamano total), la columnasUsadas, la filasUsadas.
        llama a cargar
        llama a mostrar
        hacer dos ciclos anidados y en cada ciclo llamar a intercambiar() pasandole la matriz, fila y columna del elemento pporque del otro 
        elemento es columna y fila, y llamas a mostrar en cada vuelta.
        
funcion transpuesta(int matriz[][], int filas, int columnas) {
    para(i = 0; i < filas; i++) {
        para(j = 0; j < columnas; j++) {
            si(i < j) {
                int auxiliar = matriz[i][j];
                matriz[i][j] = matriz[j][i];
                matriz[j][i] = auxiliar;
                mostrar(matriz);
            }
}
*/
void intercambiarLugar(int matriz[][100],int i,int j){
         int aux = matriz[i][j];
         matriz[i][j] = matriz[j][i];
         matriz[j][i] = aux;
}
void mostrarMatriz(int matriz[][100],int filas, int columnas){
    int i,j;
    for (i = 0; i < filas; i++){
        printf("\n");
        for (j = 0; j < columnas; j++)
        {
            printf("%d ",matriz[i][j]);
        }
    }
}
void cargarAzar(int matriz[][100],int filas, int columnas){
    int i,j;
    for (i = 0; i < filas; i++)
    {
        for (j= 0; j < columnas; j++)
        {
            matriz[i][j] = rand()%100;
        }
        
    }
    
}

/*Escribir un script que verifique que una matriz cuadrada es una matriz diagnola dominante.
Una matriz dominante es aquella que cada valor absoluto de un elemento de la diagonal principal 
es mayor que la suma de los valores absolutos del resto de los elementos de su fila mas la suma de los valores absolutos
del resto de los elementos de su columna.
*/

void verLugar(int matrizy[][100],int filas,int columnas)
{
    int i,j;
    char resultado = "Es una matriz diagnola dominante";
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++){
            int suma=0;
            if (i == j)
            {
                for (int k = 1; k < columnas; k++){
                    for (int l = 1; l < filas; l++){
                        suma+= matrizy[k][l];
                        suma+= matrizy[l][k];
                }
                if (matrizy[i][j] < suma)
                {
                    resultado = "No es una matriz diagnola dominante";
                }
                
            }
         }
        }
}
}
int main()
{
    int i,j;
    int matriz[100][100];
    int filas = 3;
    int columnas = 3;
    cargarAzar(matriz,filas,columnas);
    mostrarMatriz(matriz,filas,columnas);
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("\n");
            if (i < j)
            {
                intercambiarLugar(matriz,i,j);
                mostrarMatriz(matriz,filas,columnas);
            }
        }
        
    }
    

    
    return 0;
}
