#include <stdio.h>

int divisionEntera(int dividendo, int divisor) {
    if (dividendo < divisor) {
        return 0; // Caso base: cuando el dividendo es menor que el divisor, la división es 0.
    } else {
        return 1 + divisionEntera(dividendo - divisor, divisor); // Resta sucesiva y recursión.
    }
}

int main(){
    printf("%d\n", divisionEntera(28, 9));
}