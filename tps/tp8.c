#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void corteDeControl(char name[]){
    FILE *arch= fopen(name, "r"); //abro archivo y lo guardo en variable arch
    int numeroCuenta, movimiento, numeroActual; //creo variables para almacenar cada dato del archivo
    float importe; // lo mismo que arriba
    fscanf(arch, "%d,%d,%f", &numeroCuenta, &movimiento, &importe); // almaceno el primer datopara empezar
    while (!feof(arch)) // condicion que no sea el el fin de archivo
    {
         double suma = 0;
         numeroActual = numeroCuenta; // condicion para corte de control(ya que tengo el archivo ordenado por numero de cuenta)
         while (numeroActual == numeroCuenta && !feof(arch)) // condicion corte de control, siempre que cambie de numero de cuenta
         {                                                   // ejecuta ciertas instrucciones
            if (movimiento == 1)
            {
                suma += importe;
            } else if (movimiento == 2)
            {
                suma -= importe;
            }            
            fscanf(arch, "%d,%d,%f", &numeroCuenta, &movimiento, &importe); // linea para pisar los valores del dato anterior del 
         }                                                                 // archivo para poner los nuevos
         printf("\n%i\t\t %.2lf", numeroActual, suma);
    }
    fclose(arch); // cierro archivo
}

void corteDeControl2(char name[]){
    FILE *arch= fopen(name, "r");
    int codigoSucursal, codigoDepartamento, codigoEmpleado;
    double sueldo;
    int sucursalActual, departamentoActual;
    fscanf(arch, "%d,%d,%d,%lf", &codigoSucursal, &codigoDepartamento, &codigoEmpleado, &sueldo);
    while (!feof(arch))
    {
         printf("CODIGO DEPARTAMENTO\t CODIGO EMPLEADO\rt SUELDO");
         double totalDepartamento;
         double totalSucursal = 0;
         sucursalActual = codigoSucursal;
         while (sucursalActual == codigoSucursal && !feof(arch))
         {
            departamentoActual = codigoDepartamento;
           while (departamentoActual == codigoDepartamento && !feof(arch))
           {
            totalDepartamento += sueldo;
            fscanf(arch, "%d,%d,%d,%f", &codigoSucursal, &codigoDepartamento, &codigoEmpleado, &sueldo);
           }
           totalSucursal += sueldo;
         }

    }
    fclose(arch);
}

int main()
{
    corteDeControl2("sueldos2.txt");
    return 0;
}
