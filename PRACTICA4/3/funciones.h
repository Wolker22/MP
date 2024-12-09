#ifndef FUNCIONES_H
#define FUNCIONES_H


struct alumno {
char nombre[50];
int DNI;
float nota;
};
void reservaMemoria(struct alumno**v, int nAl);
void ordenar(struct alumno *v, int nAl, int(*orden)(int, int));
int ascendente(int a, int b);
int descendente(int a, int b);

#endif