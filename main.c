#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main() {
    int size, **cuadro;

    puts(">>>> Cuadros Magicos <<<<\n"
         "Digite un numero para definir la dimension de la matriz:");
    scanf("%d", &size);
    if (size<3){
        printf("\nError: La dimension del cuadro debe ser mayor a dos.\n\n");
        return -1;
    }
    printf("La Dimension de la matriz es: %d\n", size);

    cuadro = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        cuadro[i] = (int *) malloc(size * sizeof(int));
    }
    rellenarceros(size, cuadro);

    CalculoCuadros(size,cuadro);

    puts("\nMADE BY: Catarino Corralco Carlos Alberto & Calderon Davila Juan Carlos");
    system("pause");
    return 0;
}
