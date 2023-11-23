#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearArchivo(char name[]) {
    char modo[]= "w";
    FILE *file;
    file = fopen(name, modo);
    fclose(file);
}

void cargarManualClima(char name[]){
    char modo[]="a";
    FILE *arch=fopen(name, modo); // Abro archivo
    int anio = 2023; //creo las variables para tener donde almacenar lo que quiero guardar en el archivo
    int dia = 01;
    int mes;
    int presipitaciones;
    int cantidadDeDias;
    printf("mes:   ");
    scanf("%i", &mes);
    printf("Cantidad de dias del mes:   ");
    scanf("%i", &cantidadDeDias);
    fflush(stdin);
    while (dia <= cantidadDeDias) // condicion para saber cuantos datos tendra el archiv(en este caso la cantidad de lineas
    {                              // sera la cantidad de dias del mes)
        fflush(stdin);
        printf("Ingrese las presipitaciones :    ");
        scanf("%i", &presipitaciones);
        fflush(stdin);
        fprintf(arch,  "\n%i %i %i %i", dia, mes, anio, presipitaciones); // escribo los datos en el archivo
        dia++;
    }
    fclose(arch); // cierro archivo
}

void procesamiento(char name[],int *diasMenores, int *diasMayores, int *diasSinLLuvia){
    FILE *arch=fopen(name, "r");
    int dia, mes, anio, presipitaciones;
    fscanf(arch, "%i %i %i %i", &dia, &mes, &anio, &presipitaciones);
    while (!feof(arch))
    {
        if (presipitaciones  == 0)
        {
            *diasSinLLuvia +=1;

        } else if (presipitaciones < 50)
        {
            *diasMenores +=1;
        } else {
            *diasMayores += 1;
        }
        fscanf(arch, "%i %i %i %i", &dia, &mes, &anio, &presipitaciones);  
    }
    fclose(arch);
}

void cargarManualTemp(char name[]){
    char modo[]="a";
    FILE *arch=fopen(name, modo);
    int anio = 2023;
    int dia = 01;
    int mes;
    int temperaturaMaxima;
    int temperaturaMinima;
    int cantidadDeDias;
    printf("mes:   ");
    scanf("%i", &mes);
    printf("Cantidad de dias del mes:   ");
    scanf("%i", &cantidadDeDias);
    fflush(stdin);
    while (dia <= cantidadDeDias)
    {
        int min = 1;
        int max = 100;
        temperaturaMaxima = min + rand() % (max - min + 1);
        temperaturaMinima = rand() % temperaturaMaxima;
        fprintf(arch,  "\n%i %i %i %i", dia, mes, anio, presipitaciones);
        dia++;
    }
    fclose(arch);
}

void procesamientoP2(char name[],int *temperaturaMaxAnual, int *temperaturaMinAnual, int *diaMin, int *diaMax){
    FILE *arch=fopen(name, "r");
    int dia, mes, anio, temperaturaMax, temperaturaMin;
    int flagMax = 0;
    int flagMin= 0;
    fscanf(arch, "%i %i %i %i", &dia, &mes, &anio, &temperaturaMax, &temperaturaMin);
    while (!feof(arch))
    {
        if(flagMax == 0)
        {
            *temperaturaMaxAnual = temperaturaMax;
            *diaMax = dia;
            flagMax = 1;
        }
        if (flagMin == 0)
        {
            *temperaturaMinAnual = temperaturaMin;
            *diaMin = dia;
            flagMin = 1;
        }
        if (flagMax = 1 && temperaturaMax > temperaturaMaxAnual)
        {
             *temperaturaMaxAnual = temperaturaMax;
             *diaMax = dia;
        } else if (flagMin = 1 && temperaturaMin < temperaturaMinAnual)
        {
            *temperaturaMinAnual = temperaturaMin;
            *diaMin = dia;
        }
        fscanf(arch, "%i %i %i %i", &dia, &mes, &anio, &temperaturaMax, &temperaturaMin);  
    }
    fclose(arch);
}

void nuevoArchivoApartirDelOtro(char name[], char nameNewArch[]){
    FILE *arch , *arch2;
    *arch = fopen(name, "r");
    *arch2 = fopen(nameNewArch, "a");
    int dia, mes, anio, temperaturaMax, temperaturaMin, temperaturaPromedio;
    fscanf(arch, "%i %i %i %i", &dia, &mes, &anio, &temperaturaMax, &temperaturaMin);
    while (!feof(arch))
    {
        temperaturaPromedio = (temperaturaMax + temperaturaMin) / 2;
        fprintf(arch2,  "\n %i %i %i %i", dia, mes, anio, temperaturaPromedio);
    }
    fclose(arch);
    fclose(arch2);
}

int main()
{
    srand(time(NULL));
    return 0;
}
