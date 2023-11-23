#include <stdio.h>

void mostrarMatriz(int matriz[][3], int filas, int columnas){
    int i,j;
    for (i = 0; i < filas; i++)
    {
        printf("\n");
        for (j = 0; j < columnas; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        
    }
    
}
//ejercicio1;
int sumaDeMatriz(int matriz[][4],int filas, int columnas){
    int i;
    int j;
    int sumatoria = 0;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            sumatoria += matriz[i][j]; 
        }
        
    }
    return sumatoria;
    
}
//ejercicio2;
void sumaDeFilasYcolumnas(int matriz[][4],int filas, int columnas){
    int vFila[]={};
    int vColumna[]={};
    for (int i = 0; i < filas; i++)
    {
        int suma = 0;
        for (int j = 0; j < columnas; j++)
        {
            suma += matriz[i][j];
        }
        vFila[i] = suma;   
    }

    for (int l = 0; l < columnas; l++)
    {
        int suma = 0;
        for (int k = 0; k < filas; k++)
        {
            suma += matriz[k][l];
        }
        vFila[l] = suma;
        
    }
    
}
//ejercicio3;
void matrizTranspuesta(int matriz[][3],int filas, int columnas) {
    int i,j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j>i)
            {
            int auxiliar = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = auxiliar;
            }
            mostrarMatriz(matriz, filas, columnas);
            printf("\n");
        }
        
    }
    
    
}
//ejercicio4; 
void temperaturasDelMes(int matrizTemp[], int filas, int columnas){
    int i,j;
    int maximaTemperatura = 0;
    int maximoDia = -1;
    int minimoDia = -1;
    int minimaTemperatura = 100000;
    for ( i = 0; i < filas; i++)
    {
        if (maximaTemperatura < matrizTemp[i])
        {
            maximoDia = i+1;
            maximaTemperatura = matrizTemp[i];
        } else if (minimaTemperatura > matrizTemp[i])
        {
            minimoDia = i+1;
            minimaTemperatura = matrizTemp[i];
        }
        
            
    }
    
}
//ejercicio5;
void alumnos(char datosAlumno[], int matrizCalificaciones[][3], int sizeAlumnos){
    int i,j;
    int nota = 0;
    float promedio;
    for ( i = 0; i < sizeAlumnos; i++){
        for (j = 0; j < 3; j++)
        {
            nota += matrizCalificaciones[i][j];   
        }
        promedio = nota/3;
        printf("El promedio del alumno %c es: %f\n",datosAlumno[i],promedio);
        nota = 0;

    }
    
}

int main()
{
    char alumnosS[] = {"LMT"};
    int notas[][3] = 
    {{10, 9, 8}, 
    {7, 6, 5}, 
    {4, 3, 2}};
    alumnos(alumnosS, notas, 3);
    return 0;
}
