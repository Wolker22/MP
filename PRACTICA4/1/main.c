#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
    int n;
    int selec=1;
    int(*funciones)(int);
    if(argc!=2){
        printf("ERROR. Introduce el comando como ./<programa> <N que definira el intervalo>.");
        exit(-1);
    }   
    n=atoi(argv[1]);
        printf("seleccione 1 para: f(x) = 3*ex-2x\n");
        printf("seleccione 2 para: g(x) = -x*sin(x)+1.5\n");
        printf("seleccione 3 para: z(x) = x3-2x+1\n");
        scanf("%u",&selec);
        if(selec==1){
            funciones=&f;
        }
        if(selec==2){
            funciones=&g;
        }
        if(selec==3){
            funciones=&z;
        }
        if(selec!=1 && selec!=2 && selec!=3){
        printf("ERROR\n");
        exit(-1);
        }
    printf("la media del resultado es: %d", ((*funciones)(n)));

}