#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void reservaMemoria(struct alumno**v, int nAl){
    *v=(struct alumno*)malloc(nAl*sizeof(struct alumno));
        if (*v == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
}

void ordenar(struct alumno *v, int nAl, int(*orden)(const void*, const void*)){
    qsort(v, nAl, sizeof(struct alumno), orden);
}

int ascendente(const void* a, const void* b){
    struct alumno* alumno_a = (struct alumno*)a;
    struct alumno* alumno_b = (struct alumno*)b;
    
    return alumno_a->DNI - alumno_b->DNI;
}

int descendente(const void* a, const void* b){
    struct alumno* alumno_a = (struct alumno*)a;
    struct alumno* alumno_b = (struct alumno*)b;
    
    return alumno_b->DNI - alumno_a->DNI;

}