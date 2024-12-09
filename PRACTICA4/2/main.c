#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char * argv[]){
    if(argc!=3){
        printf("ERROR. Ejecuta el programa como ./<programa> <1 para ascendente o 2 para descendente> <nombre del archivo>");
        return(0);
    }    
    int elec=atoi(argv[1]);
    if(elec!=1&&elec!=2){
        printf("ERROR. DEBES DE PONER 1 O 2");
        return(0);
    }

    struct alumno*v;
    int nAl;
    FILE *archivo;
    int(*orden)(const void*, const void*);

    archivo=fopen(argv[2], "rb");
    if(archivo==NULL){
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
    fseek(archivo, 0, 2);
    nAl=ftell(archivo)/sizeof(struct alumno);
        printf("%d\n", nAl);
    reservaMemoria(&v, nAl);
    fseek(archivo, 0, 0);
    int elementos_leidos=fread(v, sizeof(struct alumno), nAl, archivo);
        printf("%d\n", elementos_leidos);
    if (elementos_leidos != nAl) {
        printf("ERROR AL LEER EL ARCHIVO");
    }

    if(elec==1){
        orden=&ascendente;
    }
    if(elec==2){
        orden=&descendente;
    }
    ordenar(v, nAl, orden);

    for(int i=0; i<nAl; i++){
        printf("nombre: %s", v[i].nombre);
        printf("DNI: %d", v[i].DNI);
        printf("nota: %f", v[i].nota);
        printf("\n");
    }
    free(v);
    fclose(archivo);
}