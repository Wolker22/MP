#ifndef FUNCIONES_H
#define FUNCIONES_H

struct lista{
    int n;
    struct lista*sig;
};

void nuevoElemento(struct lista ** nuevo);
void insertarDelante(struct lista ** cabeza, int n);
void soloInsertar(struct lista ** cabeza, int c);
void imprimirLista(struct lista ** cabeza);
void borrarLista(struct lista ** cabeza);


#endif