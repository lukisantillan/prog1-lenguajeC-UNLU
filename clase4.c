#include <stdio.h>

void modificar(int v[], int p, int e) {
    v[p] = e;
}

void agregar(int v[], int e, int *u) {
    v[*u] = e;
    *u+= 1;
}

void mostrar(int v[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d\n", v[i]);
    }
}

void eliminar(int v[], int p, int *u) {
    int i;
    for (i = 0; i < *u; i++)
    {
        if (i >= p)
        {
            v[i] = v[i+1];
        }
        
    }
    *u-= 1;
}

void insertar(int v[], int p, int e, int *u) {
    int i;
    for (i = *u; i>p; i--)
    {
        v[i] = v[i-1];
    }
    v[p] = e;
    *u+=1;
}

int main()
{
    int v[10]= {1,2,3,4,5,6};
    int tamaño = 6;
    mostrar(v, tamaño);
    printf("\n vector original");
    agregar(v, 7, &tamaño);
    printf("\n");
    mostrar(v, tamaño);
    printf("\n vector agregado");
    eliminar(v, 3, &tamaño);
    printf("\n");
    mostrar(v, tamaño);
    printf("\n vector eliminado");
    insertar(v, 3, 4, &tamaño);
    printf("\n");
    mostrar(v, tamaño);
    printf("\n vector insertar");
    
    return 0;
}
