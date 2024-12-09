#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

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
    int nAl=0;
    FILE *archivo;
    int(*orden)(int,int);
    char cadena[50];
    int i=0;

    archivo=fopen(argv[2], "rb");
    if(archivo==NULL){
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
    while (fgets(cadena, 50 , archivo) != NULL) {
        if(cadena[strlen(cadena)-1]=='\n'){
            i++;
        }
    }
    nAl=i/3;


    reservaMemoria(&v, nAl);

    fseek(archivo, 0, 0);
    i=0;
    while (fgets(cadena, 50 , archivo) != NULL) {
        if(cadena[strlen(cadena)-1]=='\n'){
            cadena[strlen(cadena)-1]='\0';
        }
        strcpy(v[i].nombre, cadena);
        fgets(cadena, 50 , archivo);
        v[i].DNI=atoi(cadena);
        fgets(cadena, 50 , archivo);
        v[i].nota=atof(cadena);
        i++;
    }

    if(elec==1){
        orden=&ascendente;
    }
    if(elec==2){
        orden=&descendente;
    }
    ordenar(v, nAl, orden);
    printf("%d\n", nAl);
    for(int i=0; i<nAl; i++){
        printf(" nombre: %s", v[i].nombre);
        printf("DNI: %d", v[i].DNI);
        printf(" nota: %f", v[i].nota);
        printf("\n");
    }
    free(v);
    fclose(archivo);
}