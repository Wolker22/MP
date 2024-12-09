#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(){
    struct libro * v;
    FILE * F1;
    FILE * F2;
    FILE * F3;
    if((F1=fopen("1.txt", "r"))==NULL){
        printf("ERROR\n");
    }
    if((F2=fopen("2.txt", "r"))==NULL){
        printf("ERROR\n");
    }
    if((F3=fopen("3.txt", "w"))==NULL){
        printf("ERROR\n");
    }
    fseek(F1, 0, 2);
    int nEL1=(ftell(F1)/sizeof(struct libro));
    fseek(F1, 0, 0);
    fseek(F2, 0, 2);
    int nEL2=(ftell(F2)/sizeof(struct libro));
    fseek(F2, 0, 0);
    int nEl=nEL1+nEL2;
    reservarMemoria(&v, nEl);
    rellenarV(v, nEl, F1);
    rellenarV(v, nEl, F2);
    fwrite(v, sizeof(struct libro), nEl, F3);



}