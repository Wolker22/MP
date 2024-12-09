#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nomina { 
    int codigo; 
    char nombre[100]; 
    float retenciones; 
    float bruto;};
    
int neto(struct nomina * c){
    return(c->bruto-(c->bruto*(c->retenciones/100)));
}

int asc(const void* a, const void *b){
    struct nomina * an=(struct nomina*)a;
    struct nomina * bn=(struct nomina*)b;
    float re1=neto(an)-neto(bn);
    int re2=(int)re1;
    return(re2);
}

int desc(const void* a, const void *b){
    struct nomina * an=(struct nomina*)a;
    struct nomina * bn=(struct nomina*)b;
    return(strcmp(an->nombre, bn->nombre));
}

void apartado1(int nEle, struct nomina * v, int criterio){
    int(*f)(const void *, const void *);
    if(criterio==0){
        f=&asc;
    }
    if(criterio==1){
        f=&desc;
    }
    qsort(v, nEle, sizeof(struct nomina), f);
}

apartado2(int nEle, struct nomina * v){    
    printf("%d\n %s %f\n %f\n\n", v[nEle].codigo, v[nEle].nombre, v[nEle].retenciones, v[nEle].retenciones);
    if(nEle>0){
        apartado2(nEle-1, v);
    }

}



int main(){

}


