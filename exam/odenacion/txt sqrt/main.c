#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(){
    int(*orden)(const void*, const void*);
    FILE * F;
    struct alumno * v;
    int selec;
    char aux[100];
    int cont=0;
    if((F=fopen("datos.txt", "r"))==NULL){
        printf("ERROR\n");
    }
    while(fgets(aux, sizeof(aux), F)){
        cont++;
    }
    int nEle=cont/3;
    reservMemo(&v, nEle);
    rellenarV(v, F);

    do{
    printf("Introduce 1 para Ascendente y 2 para descendente\n");
    scanf("%d", &selec);
    if(selec==1){
        orden=&ascendente;
    }
    if(selec==2){
        orden=&descendente;
    }
    }while(selec!=1&&selec!=2);

    qsort(v, nEle, sizeof(struct alumno), orden);
    for(int i=0; i<nEle; i++){
        printf("%s%d\n%f\n\n", v[i].nombre, v[i].DNI, v[i].nota);
    }

}