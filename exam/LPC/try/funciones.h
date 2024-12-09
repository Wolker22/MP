#ifndef FUNCIONES_H
#define FUNCIONES_H

struct lista{
    int n;
    struct lista*sig;
};

void imprimirLista(struct lista * cabeza);
void insertarOrden(int v, struct lista ** cabeza);
void unico(int v, struct lista ** cabeza);
struct lista * nuevoEle();
void insertarDelante(int v, struct lista **cabeza);
#endif