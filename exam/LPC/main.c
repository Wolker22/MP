#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    struct lista * cabeza=NULL;
    int vector1[] = {2, 4, 6, 8, 10};
    int vector2[] = {5, 4, 7, 2, 12};

    int size1 = sizeof(vector1) / sizeof(vector1[0]);
    int size2 = sizeof(vector2) / sizeof(vector2[0]);

    for (int i = 0; i < size1; i++) {
        soloInsertar(&cabeza, vector1[i]);
    }

    for (int i = 0; i < size2; i++) {
        soloInsertar(&cabeza, vector2[i]);
    }

    imprimirLista(&cabeza);
    borrarLista(&cabeza);
}