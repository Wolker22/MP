#ifndef FUNCIONES_H
#define FUNCIONES_H



struct libro{

char nombre [100];
char autor [100];
float precio;
int unidades;

};

void reservaMemo(struct libro ** v, int nEle);
int numeroRegistros(FILE * F);
void rellenarV(struct libro * v, FILE * F, int i);
void imprimir(FILE * F, int nEl, struct libro * v);
void imprimirLibros(struct libro *v, int nEl);

#endif