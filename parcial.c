#include <stdio.h>

int procesamiento(int f, int c, int matriz[3][3], int v[]){
    int i, j, resultado = 0;
    for (j = 0; j < c; j++)
    {
        int numeroMayor = -10000;
        for ( i = 0; i < f; i++)
        {
            if(matriz[i][j] > numeroMayor){
                numeroMayor = matriz[i][j];
            }
        }
        v[j] = numeroMayor;
    }
    
    return resultado;
}


int main()
{
    int v[3];
    int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    procesamiento(3,3,matriz,v);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", v[i]);
    }
    
    return 0;
}
