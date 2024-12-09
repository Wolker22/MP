#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void nuevoElemento(struct lista ** nuevo){
    *nuevo=(struct lista*)malloc(sizeof(struct lista));
}

void insertarDelante(struct lista ** cabeza, int n){
    struct lista * aux = NULL;
    struct lista * ant = NULL;
    struct lista * nuevo = NULL;
    int encontrado = 0;
    nuevoElemento(&nuevo);
    nuevo->n=n;
    if(*cabeza==NULL){
        nuevo->sig=*cabeza;
        *cabeza=nuevo;
    }
    else{
        aux=*cabeza;
        while(aux!=NULL&&encontrado==0){
            if(aux->n>n){
                encontrado=1;
            }
            else{
                ant=aux;
                aux=aux->sig;
            }
        }
        ant->sig=nuevo;
        nuevo->sig=aux;
    }
}

void soloInsertar(struct lista ** cabeza, int c){
    struct lista * aux = *cabeza;
    while(aux!=NULL){
        if(aux->n==c){
            return;
        }
            aux=aux->sig;            
    }
    insertarDelante(cabeza, c);
}

void imprimirLista(struct lista ** cabeza){
    struct lista * aux;
    aux= *cabeza;
    while(aux!=NULL){
        printf("%d\n", aux->n);
        aux=aux->sig;
    }
}

void borrarLista(struct lista ** cabeza){
    struct lista * aux;
    struct lista * ant;
    aux=*cabeza;
    while(aux!=NULL){
        ant=aux;
        aux=aux->sig;
        free(ant);
    }
}