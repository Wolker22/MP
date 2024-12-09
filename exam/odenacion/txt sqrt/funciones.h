#ifndef FUNCIONES_H
#define FUNCIONES_H

struct alumno {
char nombre[50];
int DNI;
float nota;
};

void reservMemo(struct alumno ** v, int nEle);
void rellenarV(struct alumno *v, FILE * F);
int ascendente(const void * a, const void * b);
int descendente(const void * a, const void * b);

#endif