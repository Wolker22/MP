#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

struct lista * nuevoEle(){
    return((struct lista *)malloc(sizeof(struct lista)));
}

void unico(int v, struct lista ** cabeza){
    struct lista * aux=*cabeza;
    while(aux!=NULL){
        if(aux->n==v){
            return;
        }
        aux=aux->sig;
    }
    insertarDelante(v, cabeza);
}

void insertarOrden(int v, struct lista ** cabeza){

    struct lista * ant=NULL;
    struct lista * aux=NULL;    
    struct lista * nuevo=nuevoEle();
    nuevo->n=v;
    int encontrado=0;
    if(*cabeza==NULL){
        nuevo->sig=*cabeza;
        *cabeza=nuevo;
    }
    else{
        aux=*cabeza;
        while(aux!=NULL&&encontrado==0){
            if((aux->n)>(nuevo->n)){
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

void insertarDelante(int v, struct lista **cabeza){

struct lista * nuevo;
nuevo=nuevoEle();
nuevo->n=v;
nuevo->sig=*cabeza;
*cabeza=nuevo;

}

void imprimirLista(struct lista * cabeza){
        struct lista * aux=cabeza;
        printf("hola\n");
        while(aux->sig!=NULL){
        printf("%d\n",aux->n);
        aux=aux->sig;
    }
}