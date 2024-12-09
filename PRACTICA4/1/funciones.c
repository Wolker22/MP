#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int n){
    int result=0, media=0;
    int final;
    double e = exp(1.0);
    for(int i=0; i<n; i++){
        result=(3*pow(e, i))-(2*i);
        media=media+result;
    }
    final=media/n;
    return(final);
}

int g(int n){
    int result=0, media=0;
    int final;
    int seno;
    for(int i=0; i<n; i++){
        seno=sin(i);
        result=((-i)*seno)+1.5;
        media=media+result;
    }
    final=media/n;
    return(final);
}

int z(int n){
    int result=0, media=0;
    int final;
    for(int i=0; i<n; i++){
        result=pow(i, 3)-(2*i)+1;
        media=media+result;
    }
    final=media/n;
    return(final);
}