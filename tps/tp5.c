#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char nada[200];

typedef struct
{
    int id;
    char name[30];
    char lastName[30];
    int calification1;
    int calification2;
    int calification3;
    
} t_alumno;

void ingresarDatosAlu(t_alumno *alu) {
    printf("-----INGRESE LOS DATOS DEL ALUMNO----");
    printf("\n Ingrese el nombre: ");
    fgets(((&alu->name)),30,stdin);
    fgets(nada,200,stdin);

    printf("\n Ingrese el Apellido: ");
    fgets(((&alu->lastName)),30,stdin);
    fgets(nada,200,stdin);


    printf("\n Ingrese la primer calificación: ");
    scanf("%i", &alu->calification1);
  

    printf("\n Ingrese la segunda calificación: ");
  
    scanf("%i", &alu->calification2);
  

    printf("\n Ingrese la tercer calificación: ");
  
    scanf("%i", &alu->calification3);
  

}

void guardarDatos(t_alumno listaAlu[], int cantidad) {
    int i;
    for (i = 0; i < cantidad; i++)
    {
        int contador = 1;
        ingresarDatosAlu(&listaAlu[i]);
        if (contador > 1)
        {
            listaAlu[i].id = contador;
            contador += 100;
        } else if (contador == 1)
        {
            listaAlu[i].id = contador;
            contador += 100;
        }
            
    }
    
}

void mostrarAlu(t_alumno listaAlu[], int cantidad){
    int i;
    printf("LEGAJO   NOMBRE   APELLIDO   PROMEDIO   CONDICIÓN");
    printf("\n_________________________________________________");
    for (i = 0; i < cantidad; i++)
    {
        int suma = listaAlu[i].calification1 + listaAlu[i].calification2 + listaAlu[i].calification3;
        float promedio = suma / 3;
        printf("\n%i", listaAlu[i].id);
        printf(" %s", listaAlu[i].name);
        printf(" %s", listaAlu[i].lastName);
        printf(" %.2lf", promedio);
        if (promedio < 4)
        {
            printf(" Libre");
        }else if (promedio >= 4 && promedio < 7)
        {
            printf(" Regular");
        } else if (promedio >=7)
        {
            printf(" Promovido");
        }    
    }
    
}

typedef struct 
{
    char sexo;
    char nombre[20];
    char estadoCivil;
    float salarioBase;
    int edad;
} t_empleados;
 
int procesamientoCantidadSexo(t_empleados empleados[], int cantidad) {
    int i, acumulador = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (empleado[i].sexo == 'M' || empleados[i].sexo == 'm')
        {
            acumulador += 1;
        }
        
    }
    return acumulador;
}

int procesamientoTrabajadorasCasadas(t_empleados empleados[], int cantidad) {
    int i, acumulador = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (empleados[i].sexo == 'f' || empleados[i].sexo == 'f' && empleados[i].estadoCivil == 'C' || empleados[i].estadoCivil == 'c')
        {
            acumulador += 1;
        }
    }
    return acumulador;
}

float procesamientoSueldos(t_empleados empleados[], int cantidad) {
    int i, float acumulador = 0;
    for (i = 0; i < cantidad; i++)
    {
        acumulador += empleados[i].salarioBase;
    }
    return acumulador;
}

void empleadoMasJoves(t_empleados empleados[], int cantidad) {
    int edad = 1000, posicion = -1, i;
    for (i = 0; i < cantidad; i++)
    {
        if (empleados[i].edad < edad)
        {
            edad = empleados[i].edad;
            posicion = i;
        }
    }
    
    printf("El emplead@ con menos edad es: %s", empleados[i].nombre);
}

int main()
{
    int cantidad = 1;
    t_alumno alumnos[cantidad];
    
    guardarDatos(alumnos, cantidad);
    mostrarAlu(alumnos, cantidad);
    return 0;
}
