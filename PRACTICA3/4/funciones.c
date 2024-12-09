#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void reservaMemo(struct libro ** v, int nEle){
    if((*v=(struct libro *)malloc(sizeof(struct libro)*nEle))==NULL){
        printf("ERROR\n");
    }
}

int numeroRegistros(FILE * F){
    fseek(F, 0, 0);
    char aux[100];
    int i =0;
    int nEl=0;
    while (fgets(aux, 100 , F) != NULL) {
            i++;
    }
    nEl=i/3;
    return nEl;
}
void rellenarV(struct libro * v, FILE * F, int i){
    char cadena[50];
    while (fgets(v[i].nombre, 50 , F) != NULL) {
        fgets(v[i].autor, 50 , F);
        fgets(cadena, 50 , F);
        sscanf(cadena, "%f %d\n", &v[i].precio, &v[i].unidades);
        i++;
    }
}

void imprimirLibros(struct libro *v, int nEl) {
    for (int i = 0; i < nEl; i++) {
        printf("Libro %d:\n", i + 1);
        printf("Nombre: %s\n", v[i].nombre);
        printf("Autor: %s\n", v[i].autor);
        printf("Precio: %.2f\n", v[i].precio);
        printf("Unidades: %d\n\n", v[i].unidades);
    }
}

void imprimir(FILE * F, int nEl, struct libro * v){
    for(int i=0; i<nEl; i++){
        fputs(v[i].nombre, F);
        fputs(v[i].autor, F);
        fprintf(F, "%f %d\n", v[i].precio, v[i].unidades);
    }
}