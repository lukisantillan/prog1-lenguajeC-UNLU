#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcularSaldo(int imp, int op, double *spp, int cc, int v[]){
    if (op == 1)
    {
        *spp -= imp;
    } else if (op == 2)
    {
        *spp += imp;
    }
    v[cc-1]++;
}

int calcularCajeroConMasMovimientos(int v[]){
    int resultado = 0;
    for (int i = 1; i < 119; i++)
    {
        if (v[i] > v[resultado])
        {
            resultado = i;
        }
    }
    return resultado + 1;
}

void corteDeControl(char name[]) {
    FILE *arch= fopen(name, "r");
    int vectorCajero[120]= {0};
    int codigo_c, anio_c, mes_c, dia_c, codigo_caj, operacion_c;
    double importe_c, saldoPorPersona, saldoTotal = 0;
    fscanf(arch, "%i %i %i %i %i %i %lf", &codigo_c, &anio_c, &mes_c, &dia_c, &codigo_caj, &operacion_c, &importe_c);
    while (!feof(arch))
    {
        int clienteActual = codigo_c;
        saldoPorPersona = 0;
        while (clienteActual == codigo_c && !feof(arch))
        {
            calcularSaldo(importe_c, operacion_c, &saldoPorPersona,codigo_caj, vectorCajero);
            fscanf(arch, "%i %i %i %i %i %i %lf", &codigo_c, &anio_c, &mes_c, &dia_c, &codigo_caj, &operacion_c, &importe_c);
        }
        printf("\n El saldo del cliente : %i es: %.2lf", clienteActual, saldoPorPersona);
        saldoTotal += saldoPorPersona;
    }
    printf("\n El saldo total es : %lf", saldoTotal);
    int cajeroConMasMovimientos = calcularCajeroConMasMovimientos(vectorCajero);
    printf("\n El cajero con mas movimientos es el cajero numero : %i con %i", cajeroConMasMovimientos, vectorCajero[cajeroConMasMovimientos-1]);
    
}

typedef struct
{
    char nombre[20];
    char apellido[20];
    int nota;
    int nota2;
    int promedio;
} t_alumno;

void llenarAlumno(t_alumno *alu) {
    fflush(stdin);
    printf("\nINGRESAR NOMBRE:    ");
    fgets((((*alu)).nombre), 20, stdin);
    fflush(stdin);
    printf("\nINGRESAR APELLIDO:    ");
    fgets((((*alu)).apellido), 20, stdin);
    fflush(stdin);
    printf("\nIngrese nota:   ");
    scanf("%i", &(*alu).nota);
    fflush(stdin);
    printf("\nIngrese nota:   ");
    scanf("%i", &(*alu).nota2);
    (*alu).promedio = ((*alu).nota + (*alu).nota2) / 2;
}

void vectorAlumnos(t_alumno alumnos[], int cantidad) {
    for (int i = 0; i < cantidad; i++)
    {
        llenarAlumno(&alumnos[i]);
    }
    
}

int main()
{
    corteDeControl("operaciones.txt");
    return 0;
}
