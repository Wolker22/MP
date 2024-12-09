#ifndef FUNCIONES_H
#define FUNCIONES_H


struct alumno {
char nombre[50];
int DNI;
float nota;
};
int descendente(const void* a, const void* b);
int ascendente(const void* a, const void* b);
void ordenar(struct alumno *v, int nAl, int(*orden)(const void*, const void*));
void reservaMemoria(struct alumno**v, int nAl);

#endif