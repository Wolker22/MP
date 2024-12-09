#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

void reservMemo(struct alumno ** v, int nEle){
    if((*v=(struct alumno*)malloc(sizeof(struct alumno)*nEle))==NULL){
        printf("ERROR\n");
    }
}

void rellenarV(struct alumno *v, FILE * F){
    fseek(F, 0, 0);
    int i=0;
    while(fgets(v[i].nombre, 50, F)!=NULL){
        fscanf(F, "%d\n%f\n", &v[i].DNI, &v[i].nota);
        i++;
    }
}

int ascendente(const void * a, const void * b){
    struct alumno * alumno_a = (struct alumno *)a;
    struct alumno * alumno_b = (struct alumno *)b;

    return(alumno_a->DNI-alumno_b->DNI);
}

int descendente(const void * a, const void * b){
    struct alumno * alumno_a = (struct alumno *)a;
    struct alumno * alumno_b = (struct alumno *)b;

    return(alumno_b->DNI-alumno_a->DNI);
}