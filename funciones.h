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
        puts("\n");
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

void CuadroPar(int size,int **a){

}



#endif