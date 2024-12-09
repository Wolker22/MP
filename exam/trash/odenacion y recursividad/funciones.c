#include <stdio.h>
#include <stdlib.h>


int comparar(const void * a, const void * b){
    struct nomina nomina_a=(struct nomina*)a;
    struct nomina nomina_b=(struct nomina*)b;

    return(nomina_a->salario - nomina_b->salario);

}

void ordenar(struct nomina * v, int nNom){
    qsort(v, nNom, sizeof(struct nomina), &comparar);
}

void imprimirVectorRecursivo(struct nomina * vector, int n) {
    if (n > 0) {
        imprimirVectorRecursivo(vector, n - 1);
        printf("%d ", vector.nombre[n - 1]);
    }
}