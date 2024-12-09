#ifndef FUNCIONES_H
#define FUNCIONES_H



struct libro{

char nombre [100];
char autor [100];
float precio;
int unidades;

};

void reservarMemoria(struct libro ** v, int nEl);
void rellenarV(struct libro * v, int nEl, FILE * F);


#endif