#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(int argc, char*argv[]){    
    int(*funcion)(int, int);
    struct alumno *v;
    if(argc!=3){
        printf("ERROR <./programa> <1 ascendente o 2 descendete> <nombre fichero>;\n");
        exit(0);
    }
    int n=atoi(argv[1]);
    if(n!=1&&n!=2){
        printf("ERROR escriba 1 o 2\n");
        exit(0);
    }

    FILE* F;
    if((F=fopen(argv[2], "rb"))==NULL){
        printf("ERROR al abrir\n");
    }
    int nEl=tamaño(F);

    reservaMemo(&v, nEl);
    rellenaVector(v, nEl, F);

    if(n==1){
        funcion=&ascendente;
    }

    if(n==2){
        funcion=&descendente;
    }
    ordenarVector(v, nEl, funcion);
    imprimirV(v, nEl);
    free(v);
    fclose(F);
}