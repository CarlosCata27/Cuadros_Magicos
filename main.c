#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int opc, size;
    int **cuadro;
    puts("Cuadros Magicos\n"
         "Digite un numero para definir el tamanio de la matriz\n");
    scanf("%d", &size);
    printf("El tamanio de la matriz es: %d\n",size);
    if (size % 2 != 0){
        puts("Tamanio impar");
        cuadro=(int**)malloc(size*sizeof(int*));
        for (int i = 0; i <size ; ++i) {
            cuadro[i]=(int*)malloc(size*sizeof(int));
        }
        rellenarceros(size,cuadro);
        CuadroImpar(size,cuadro);
    }
    else{
        puts("Tamanio par");
    }

    puts("Adios :)");


    printf("\n");
    return 0;
}
