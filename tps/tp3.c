#include <stdio.h>
#include <stdlib.h>
#define sizeVector 4
#define sizeVector2 5
//ejercicio1;
void estaOrdenado(char v[],int size) {
    int resultado = 1, i;
    for (i = 0; i + 1 < size; i++)
    {
        if (v[i] > v[i + 1])
        {
            resultado = 0;
        }
        
    }
    printf("%i", resultado);
}
//ejercicio2;
void ordenarMenorAmayor(int  v1[], int v2[], int sizeV1, int sizeV2) {
    int sizeNuevoVector = sizeV1 + sizeV2;
    int v3[sizeNuevoVector];
    int i= 0,j = 0, k = 0;
    while (i < sizeV1 && j < sizeV2)
    {
        if (v1[i] < v2[j])
        {
            v3[k] = v1[i];
            k++;
            i++;
        } else if (v2[j] < v1[i])
        {
            v3[k] = v2[j];
            k++;
            j++;
        }
    }

    while (i < sizeV1)
    {
        v3[k] = v1[i];
        i++;
        k++;
    }
    
    while (j < sizeV2)
    {
        v3[k] = v2[j];
        j++;
        k++;
    }

    
    for (int i = 0; i < sizeNuevoVector; i++)
    {
        printf("%i", v3[i]);
    }
    
}
//ejercicio3;
void menu(){
    printf("\t\t\t Ingresar el valor deseado");
    printf("\t I - PARA AGREGAR UN VALOR A LA ULTIMA POSICION");
    printf("\t B- ENCONTRAR EL ELEMENTO Y ELIMINARLO");
    printf("\t A- INGRESAR UN ELEMENTO EN DETERMINADA POSICION");
}
void proccess(int array[],int *amountOfElements, char action, int valueInt) {
    switch (action)
    {
    case 'i':
         array[*amountOfElements] = valueInt;
         *amountOfElements += 1;
        break;
    case 'b':
          int i;
          for (i = 0; i < *amountOfElements; i++)
            {  
                if (i >= valueInt)
                {
                    array[i] = array[i+1];
                }
            }
            *amountOfElements-= 1;
        break;
    case 'a':
          int i, e;
          printf("Ingrese el valor a insertar en la posicion:   ");
          scanf("%d", &e);
          for (i = *
          amountOfElements; i>valueInt; i--)
            {
                array[i] = array[i-1];
            }
            array[valueInt] = e;
            *
            amountOfElements+=1;
        break;
    default:
        break;
    }
}
//ejercicio5;
void proccessStudents(int students[], int califications[], int size){
    int i = 0;
    int j = 0;
    while ( i < size)
    {
        int currentFile = students[i];
        int sumOfNotes = 0;
        int amountOfNotes = 0;
        while (i < size && students[i] == currentFile)
        {
            sumOfNotes += califications[j];
            amountOfNotes++;
            j++;
            if (amountOfNotes == 3)
            {
                float average = sumOfNotes / amountOfNotes;
                printf("\n Legajo %d: Promedio = %.2f", currentFile, average);
                amountOfNotes = 0;
                sumOfNotes = 0;
                i++;
            }
            
            

        }
        
    }

}

int main(){
    int vector1[3] = {1,2,3};
    int vector2[9] = {10,9,8,4,6,8,10,10,4};
    proccessStudents(vector1,vector2, 3);
    return 0;
}

