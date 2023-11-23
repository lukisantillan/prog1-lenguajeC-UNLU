#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char nada[200];

typedef struct{
    int dni;
    char apellido[20];
    char nombre[20];
    float n1;
    float n2;
} t_alumno;

void cargarDato(t_alumno *alumno){
    printf("-----INGRESE LOS DATOS DEL ALUMNO------\n\n");

    printf("\n Ingrese el dni: ");
    scanf("%i", &(*alumno).dni);

    fgets(nada,200,stdin);
    printf("\n Ingrese el nombre:   ");
    fgets((((*alumno)).nombre), 20, stdin);
    fgets(nada,200,stdin);

    if ((*alumno).nombre[strlen((*alumno).nombre) - 1] == '\n')
    {
        (*alumno).nombre[strlen((*alumno).nombre)-1] = '\0';
    }
    
    
    printf("\n Ingrese el apellido:   ");
    fgets((((*alumno)).apellido), 20, stdin);
    fgets(nada,200,stdin);
    if ((*alumno).apellido[strlen((*alumno).apellido) - 1] == '\n')
    {
        (*alumno).apellido[strlen((*alumno).apellido)-1] = '\0';
    }

    printf("\n Ingrese la nota1: ");
    scanf("%f", &(*alumno).n1);
    

    printf("\n Ingrese la nota2: ");
    scanf("%f", &(*alumno).n2);
    
}

void cargarCadaAlumno(t_alumno vectorAl[], int cantidad) {
    int i;
    for (i = 0; i < cantidad; i++)
    {
        cargarDato(&vectorAl[i]);
    }
    
}


void mostrarAlumnos(t_alumno vectorA[], int cantidad){
    int i;
    for (i = 0; i < cantidad; i++)
    {
        printf("\n Nombre: %s", vectorA[i].nombre);
        printf("\n Apellido: %s", vectorA[i].apellido);
        printf("\n Nota 1 %f", vectorA[i].n1);
        printf("\n Nota2 %f", vectorA[i].n2);
        printf("\n DNI %i", vectorA[i].dni);
        printf("\n -----------");  
    }  
}

int main()
{
    t_alumno alu[2];
    cargarCadaAlumno(alu, 2);
    mostrarAlumnos(alu, 2);
    return 0;
}
