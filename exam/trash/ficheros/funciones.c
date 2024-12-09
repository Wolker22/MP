#include <stdio.h>
#include <stdlib.h>




struct alumno * apartado1(int * nEle, char * nFAL, char * nNot){
    struct alumno * v;
    char aux 100;
    int nAl;
    FILE * F1;
    FILE * F2;
    F1=fopen(nFAL, "r");
    F2=fopen(nNot, "r");
    char aux[100];
    while(fgets(aux, 100, F1)!=NULL){
        nAl++;
    }
    reserva_memoria(&v, nAl);
    fseek(F1, 0, 0);
    int i=0;
    while(fgets(v[i].nombre, 100, F1)!=NULL){
        fgets(aux, 100, F2);
        v[i].DNI=atoi(aux);
        i++;
    }

}

void reserva_memoria(struct alumno **v, int nAl){
    *v=(struct alumno *)malloc(sizeof(struct alumno)*nAl);
}

void imprimir(int nAl, struct alumno * v){
    FILE * F3;
    fopen("archivo.txt", "w");
    for(int i=0; i<nAl; i++){
        fprintf(F3, "El nombre es: %s. Y la nota es: %d\n". v[i].nombre, v[i].nota);
    }
}