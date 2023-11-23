#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void crearArchivo(char name[]) {
    char modo[]= "w";
    FILE *file;
    file = fopen(name, modo);
    fclose(file);
}

void cargarAutomatico(char name[], int cantidadDeArchivosAcargar){
    char modo[] = "a"
    FILE *arch;
    arch= fopen(name, modo);
    int i = 0;
    //escribo las variables de los datos a cargar
    while (i <= cantidadDeArchivosAcargar)
    {
        i++;
        fprintf(arch, /*tipos de variables a cargar*/, /*variables*/); //instrucion para guardar datos en el archivo.
    }
    fclose(arch);
}

void cargarManual(char name[]){
    char modo[]="a"
    file *arch=fopen(name, modo);
    int i;
    int edad;
    char nombre[30];
    while (i <= 3)
    {
        fflush(stdin);
        printf("Ingrese la edad:    ");
        scanf("%i", &edad);
        fflush(stdin);

        printf("Ingrese el nombre:  ");
        fgets(&nombre, 30, stdin);

        fprintf(arch,  "%i %s", edad, nombre);
    }
    fclose(arch);
}

void leer(char name[], char modo[]){
    FILE *arch=fopen(name, modo);
    fscanf(arch, /*tipos de variables entre comillas*/, /*variables con &*/);
    while (!feof(arch))
    {
        printf(/*tipos de variables*/, /*variables*/);
        fscanf(arch, /*tipos de variables entre comillas*/, /*variables con &*/);   
    }
    fclose(arch);
}


int main()
{
    int opcion;
    printf("\t\t\t\t\t Menú \n\n");
    printf("\t\t 1- Crear archivo\n ");
    printf("\t\t 2- Escribir archivo\n");
    printf("\t\t 3- Leer archivo\n");
    printf("\t\t 0- Salir\n");
    printf("\t\t\t\t\t Ingrese una opcion:  \n");
    scanf("%i", &opcion);

    switch (opcion)
    {
    case 1:
        
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 0:
        /* code */
        break;
    
    default:
        break;
    }

    return 0;
}
