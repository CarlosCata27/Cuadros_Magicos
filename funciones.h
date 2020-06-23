#ifndef CUADROS_MAGICOS_FUNCIONES_H
#define CUADROS_MAGICOS_FUNCIONES_H

#include <math.h>

void MostrarMatriz(int size, int** a){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d  ",a[i][j]);
        }
        puts("\n");
    }
    printf("Constante Magica(Suma total fila/columna/diagona): %d ", (size * size + 1) * size / 2);
}

void rellenarceros(int size,int **a){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j]=0;
        }
    }
}

void cuadroImpar(int size,int **a){
    int mitad=size/2;
    int ubicacionC=mitad;
    int ubicacionF=0;
    a[ubicacionF][ubicacionC]=1;
    int ubicacionFAct=ubicacionF;
    int ubicacionCAct=ubicacionC;
    for (int i = 2; i <=(pow(size,2)) ; ++i) {
        ubicacionF--;
        ubicacionC--;
        if(ubicacionF<0){
            ubicacionF=size-1;
        }
        if (ubicacionC<0){
            ubicacionC=size-1;
        }
        if (a[ubicacionF][ubicacionC]==0){
            a[ubicacionF][ubicacionC]=i;
        }else{
            ubicacionF=ubicacionFAct+1;
            ubicacionC=ubicacionCAct;
            a[ubicacionF][ubicacionC]=i;
        }
        ubicacionFAct=ubicacionF;
        ubicacionCAct=ubicacionC;
    }
    MostrarMatriz(size,a);
}

void cuadro4n(int size,int **a){
    int i, j;

    for ( i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] = (size * i) + j + 1;
        }
    }

    for ( i = 0; i < size/4; i++) {
        for (j = 0; j < size / 4; j++) {
            a[i][j] = (size * size + 1) - a[i][j];
        }
    }

    for ( i = 0; i < size/4; i++) {
        for (j = 3 * (size / 4); j < size; j++) {
            a[i][j] = (size * size + 1) - a[i][j];
        }
    }

    for ( i = 3 * size/4; i < size; i++) {
        for (j = 0; j < size / 4; j++) {
            a[i][j] = (size * size + 1) - a[i][j];
        }
    }

    for ( i = 3 * size/4; i < size; i++) {
        for (j = 3 * size / 4; j < size; j++) {
            a[i][j] = (size * size + 1) - a[i][j];
        }
    }


    for ( i = size/4; i < 3 * size/4; i++) {
        for (j = size / 4; j < 3 * size / 4; j++) {
            a[i][j] = (size * size + 1) - a[i][j];
        }
    }

    MostrarMatriz(size,a);
}

int** cuadritoImpar(int size,int **result) {
    int mitad=size/2;
    int ubicacionC=mitad;
    int ubicacionF=0;
    result[ubicacionF][ubicacionC]=1;
    int ubicacionFAct=ubicacionF;
    int ubicacionCAct=ubicacionC;

    for (int i = 2; i <=(pow(size,2)) ; ++i) {
        ubicacionF--;
        ubicacionC--;
        if(ubicacionF<0){
            ubicacionF=size-1;
        }
        if (ubicacionC<0){
            ubicacionC=size-1;
        }
        if (result[ubicacionF][ubicacionC]==0){
            result[ubicacionF][ubicacionC]=i;
        }else{
            ubicacionF=ubicacionFAct+1;
            ubicacionC=ubicacionCAct;
            result[ubicacionF][ubicacionC]=i;
        }
        ubicacionFAct=ubicacionF;
        ubicacionCAct=ubicacionC;
    }

    return result;
}

int numDigits(int n){
    int count = 1;

    while(n>=10){
        n /= 10;
        count++;
    }

    return count;
}

void cuadro4n2(int size,int **resultadoFinal){
    int area = size * size;
    int mitadDimension = size / 2;
    int division = area / 4, i;

    int** cuadrito = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        cuadrito[i] = (int *) malloc(size * sizeof(int));
    }
    rellenarceros(mitadDimension,cuadrito);

    cuadrito = cuadritoImpar(mitadDimension,cuadrito);
    int factoresCuadro[] = {0, 2, 3, 1};


    for (int filas = 0; filas < size; filas++) {
        for (int columnas = 0; columnas < size; columnas++) {
            int grid = (filas / mitadDimension) * 2 + (columnas / mitadDimension);
            resultadoFinal[filas][columnas] = cuadrito[filas % mitadDimension][columnas % mitadDimension];
            resultadoFinal[filas][columnas] += factoresCuadro[grid] * division;
        }
    }

    int colsIzq = mitadDimension / 2;
    int colsDer = colsIzq - 1;

    for (int filas = 0; filas < mitadDimension; filas++) {
        for (int columnas = 0; columnas < size; columnas++) {
            if (columnas < colsIzq || columnas >= size - colsDer || (columnas == colsIzq && filas == colsIzq)) {
                if (columnas == 0 && filas == colsIzq) {
                    continue;
                }

                int tmp = resultadoFinal[filas][columnas];
                resultadoFinal[filas][columnas] = resultadoFinal[filas + mitadDimension][columnas];
                resultadoFinal[filas + mitadDimension][columnas] = tmp;
            }
        }
    }

    int x,y;
    for(x=0;x<size;x++){
        for(y=0;y<size;y++){
            printf("%*s%d",size - numDigits(resultadoFinal[x][y]),"",resultadoFinal[x][y]);
        }
        printf("\n");
    }
    printf("\nConstante Magica(Suma total fila/columna/diagona): %d ", (size * size + 1) * size / 2);
}

void CalculoCuadros(int size,int **cuadro){
    if (size%2==1) {
        puts("Por lo tanto aplicamos, el calculo impar.");
        cuadroImpar(size, cuadro);
    }else if (size%4==0) {
        puts("Por lo tanto aplicamos, el calculo par de funcion 4n.");
        cuadro4n(size,cuadro);
    }else {
        puts("Por lo tanto aplicamos, el calculo par de funcion 4n+2.");
        cuadro4n2(size,cuadro);
    }
}

#endif