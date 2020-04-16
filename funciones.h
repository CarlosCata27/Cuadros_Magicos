#ifndef CUADROS_MAGICOS_FUNCIONES_H
#define CUADROS_MAGICOS_FUNCIONES_H

#include <math.h>

void MostrarMatriz(int size, int** a){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d\t",a[i][j]);
        }
        puts("\n");
    }
}

void rellenarceros(int size,int **a){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j]=0;
        }
    }
}

void CuadroImpar(int size,int **a){
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

void CuadroPar4n(int size,int **a) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            a[i][j] = (size * i) + j + 1;

    for (int i = 0; i < size / 4; ++i)
        for (int j = 0; j < size / 4; ++j)
            a[i][j] = (size * size + 1) - a[i][j];

    for (int i = 0; i < size / 4; i++)
        for (int j = 3 * (size / 4); j < size; j++)
            a[i][j] = (size * size + 1) - a[i][j];

    for (int i = 3 * size / 4; i < size; i++)
        for (int j = 0; j < size / 4; j++)
            a[i][j] = (size * size + 1) - a[i][j];

    for (int i = 3 * size / 4; i < size; i++)
        for (int j = 3 * size / 4; j < size; j++)
            a[i][j] = (size * size + 1) - a[i][j];

    for (int i = size / 4; i < 3 * size / 4; i++)
        for (int j = size / 4; j < 3 * size / 4; j++)
            a[i][j] = (size * size + 1) - a[i][j];

    MostrarMatriz(size,a);
}

void CuadroPar4n2(int size,int **a){

}

#endif