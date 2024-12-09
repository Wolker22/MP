#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(){   
    struct libro * v;
    int nEl1=0;
    int nEl2=0; 
    FILE * F1;
    FILE * F2;
    FILE * F3;
    if((F1=fopen("1.txt", "r"))==NULL){
        printf("ERROR");
        return 1;
    }
    if((F2=fopen("2.txt", "r"))==NULL){
        printf("ERROR");
        return 1;
    }
    if((F3=fopen("3.txt", "w"))==NULL){
        printf("ERROR");
        return 1;
    }

    nEl1=numeroRegistros(F1);
    nEl2=numeroRegistros(F2);
    int nEl=nEl1+nEl2;
    printf("1: %d\n",nEl1);
    printf("2: %d\n",nEl2);
    printf("3: %d\n",nEl);
    reservaMemo(&v, nEl);
    fseek(F1, 0, 0);
    fseek(F2, 0, 0);
    rellenarV(v, F1, 0);
    rellenarV(v, F2, nEl1);
    imprimirLibros(v, nEl); 
    imprimir(F3, nEl, v);
    free(v);
    fclose(F1);
    fclose(F2);
    fclose(F3);
    
}