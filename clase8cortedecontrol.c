#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cantidadVentas(int *stockFinal, int tipoDeOperacion, int cantidad, int v[], int mes) {
    if (tipoDeOperacion == 1)
    {
        *stockFinal += cantidad;
    } else {
        *stockFinal -= cantidad;
        v[mes-1]+= cantidad;
    }
}

void stockMayor(int stockEntrante, int codigoEntrante, int *mayorStock, int *codigoMayorStock) {
    if (stockEntrante > *mayorStock) {
        *mayorStock = stockEntrante;
        *codigoMayorStock = codigoEntrante-1;
    }
}

int mesCantidad(int v[]) {
    int mesMasVenta = 0;
    for (int i = 1; i < 12; i++) {
        if (v[i] > v[mesMasVenta]) {
            mesMasVenta = i;
        }
    }
    return mesMasVenta + 1;
}

void corteDeControl(char name[]){
    FILE *arch= fopen(name, "r");

    int vectorMes[12]= {0};
    int codigo_l, dia_l, mes_l, ani_l, tipo_l, canti_l;
    int mayorStock = 0, codigoMayorStock = 0, codigoActual;
    fscanf(arch, " %i %i %i %i %i %i", &codigo_l, &dia_l, &mes_l, &ani_l, &tipo_l, &canti_l);
    while (!feof(arch))
    {
        int stockFinal = 0;
        codigoActual = codigo_l;
        while (codigo_l == codigoActual && !feof(arch))
        {
            cantidadVentas(&stockFinal, tipo_l, canti_l, vectorMes, mes_l);
            fscanf(arch, " %i %i %i %i %i %i", &codigo_l, &dia_l, &mes_l, &ani_l, &tipo_l, &canti_l);
        }
        stockMayor(stockFinal, codigo_l, &mayorStock, &codigoMayorStock);
        printf("\nStock: %i , Repuesto : %i", stockFinal ,codigoActual);
    }
    printf("\nEl producto con mas Stock es: %i, con la cantidad de : %i", codigoMayorStock, mayorStock);
    int mesMasVentas = mesCantidad(vectorMes);
    printf("\nEl mes con mas ventas es el mes numero : %i", mesMasVentas);
    
}

int main()
{
    corteDeControl("r.txt");
    return 0;
}
