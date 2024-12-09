#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int tamaño(FILE * F){
    fseek(F, 0, 2);
    int s=ftell(F);
    return(s/sizeof(struct alumno));
}

void reservaMemo(struct alumno ** v, int nEl){
    if((*v=(struct alumno *)malloc(sizeof(struct alumno)*nEl))==NULL){
        printf("ERROR\n");
        exit(0);
    }
}

void rellenaVector(struct alumno * v, int nEle, FILE * F){
    fseek(F, 0, 0);
    if((fread(v, sizeof(struct alumno), nEle, F))!=nEle){
        printf("ERROR al Rellenar Vector\n");
    }
}

int ascendente(int a, int b){
    if(a>b){
        return 1;
    }
    return 0;
}

int descendente(int a, int b){
    if(a<b){
        return 1;
    }
    return 0;
}

void ordenarVector(struct alumno * v, int nEle, int(*funcion)(int, int)){
    struct alumno aux;
    for(int i=0; i<nEle-1; i++){
        for(int j=0; j<nEle-1-i; j++){
            if(funcion(v[j].DNI, v[j+1].DNI==1)){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void imprimirV(struct alumno * v, int nEle){
    for(int i=0; i<nEle; i++){
        printf("nombre: %s.   DNI: %d.   Nota: %f.\n", v[i].nombre, v[i].DNI, v[i].nota);
        printf("\n");
    }
}