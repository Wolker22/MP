#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    struct lista * cabeza=NULL;
    int vector1[] = {2, 4, 6, 8, 10};
    int vector2[] = {5, 4, 7, 2, 12};
    int n1=sizeof(vector1)/sizeof(int);
    int n2=sizeof(vector2)/sizeof(int);
    for(int i=0; i<n1; i++){
        unico(vector1[i], &cabeza);
    }
    for(int i=0; i<n2; i++){
        unico(vector2[i], &cabeza);
    }
    imprimirLista(cabeza);



}