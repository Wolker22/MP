#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main(int argc, char* argv[]){
    FILE* archivo;
    int orden;
    int nAl=0;
    int i=0;
    char cadena[50];
    int cont=0;
    struct alumno *v;
    int(*selec)(int, int);

    if(argc!=3){
        printf("error");
        return(-1);
    }

    orden=atoi(argv[1]);
    if(orden!=1&&orden!=2){
        printf("error");
        return(-1);
    }

    archivo=fopen(argv[2], "rb");
    if(archivo==NULL){
        printf("error");
    }

    while((fgets(cadena, sizeof(cadena), archivo))!=NULL){
        if(cadena[strlen(cadena)-1]=='\n'){
            cont++;
        }
    }
    nAl=cont/3;

    reservaMemoria(&v, nAl);

    fseek(archivo, 0, 0);
    i=0;
    while((fgets(cadena, sizeof(cadena), archivo))!=NULL){
        if(cadena[strlen(cadena)-1]=='\n'){
            cadena[strlen(cadena)-1]='\0';
        }
        strcpy(v[i].nombre, cadena);
        fgets(cadena, sizeof(cadena), archivo);
        v[i].DNI=atoi(cadena);
        fgets(cadena, sizeof(cadena), archivo);
        v[i].nota=atof(cadena);
        i++;
    }

    if(orden==1){
        selec=&ascendente;
    }
    if(orden==2){
        selec=&descendente;
    }

    ordenar(v, nAl, selec);

    for(int i=0; i<nAl; i++){
        printf(" nombre: %s", v[i].nombre);
        printf("DNI: %d", v[i].DNI);
        printf(" nota: %f", v[i].nota);
        printf("\n");
    }
    free(v);
    fclose(archivo);
    
}
