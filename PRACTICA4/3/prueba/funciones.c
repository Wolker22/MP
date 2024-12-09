#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

void reservaMemoria(struct alumno**v, int nAl){
    *v=(struct alumno*)malloc(nAl*sizeof(struct alumno));
        if (*v == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
}

int ascendente(int a, int b){
    if(a<b){
        return(1);
    }
    else{
        return(0);
    }
}
int descendente(int a, int b){
    if(a>b){
        return(1);
    }
    else{
        return(0);
    }
}

void ordenar(struct alumno * v, int nAl, int(*orden)(int , int)){
    struct alumno aux;
    for(int i=0; i<nAl-1; i++){
        for(int j=0; j<nAl-1-i; j++){
            if(((*orden)(v[j].DNI ,v[j+1].DNI))==1){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}