#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main(int argc, char* argv[]){
    FILE* archivo;
    int orden;
    int nAl;
    struct alumno *v;
    int(*selec)(int, int);
    if(argc!=3){
        printf("error");
        return(-1);
    }
    orden=atoi(argv[1]);
    if(orden!=1&&orden!=2){
        printf("error");
        return(-1);
    }
    archivo=fopen(argv[2], "rb");
    if(archivo==NULL){
        printf("error");
    }

    fseek(archivo, 0, 2);
    nAl=ftell(archivo);
    nAl=nAl/sizeof(struct alumno);

    reservaMemoria(&v, nAl);

    fseek(archivo, 0, 0);
    int numero=fread(v, sizeof(struct alumno), nAl, archivo);
    if(numero!=nAl){
        printf("Error");
    }

    if(orden==1){
        selec=&ascendente;
    }
    if(orden==2){
        selec=&descendente;
    }

    ordenar(v, nAl, selec);

    for(int i=0; i<nAl; i++){
        printf(" nombre: %s", v[i].nombre);
        printf("DNI: %d", v[i].DNI);
        printf(" nota: %f", v[i].nota);
        printf("\n");
    }
    free(v);
    fclose(archivo);
    
}
