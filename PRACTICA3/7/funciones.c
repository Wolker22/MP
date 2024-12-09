#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void reservarMemoria(struct libro ** v, int nEl){
    *v=(struct libro*)malloc(sizeof(struct libro)*nEl);
}

void rellenarV(struct libro * v, int nEl, FILE * F){
    if((fread(v, sizeof(struct libro), nEl, F))!=nEl){
        printf("ERROR\n");
        exit (1);
    }
}
