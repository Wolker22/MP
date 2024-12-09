#ifndef FUNCIONES_H
#define FUNCIONES_H

struct alumno {
char nombre[50];
int DNI;
float nota;
};

int tamaño(FILE * F);
int ascendente(int a, int b);
int descendente(int a, int b);
void imprimirV(struct alumno * v, int nEle);
void reservaMemo(struct alumno ** v, int nEl);
void rellenaVector(struct alumno * v, int nEle, FILE * F);
void ordenarVector(struct alumno * v, int nEle, int(*funcion)(int, int));

#endif