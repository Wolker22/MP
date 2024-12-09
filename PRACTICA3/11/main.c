#include <stdio.h>


int contarCaracter(const char *cadena, char caracter) {
    if (*cadena == '\0') {
        return 0; // Caso base: cadena vacía, la cuenta es 0.
    } else {
        if (*cadena == caracter) {
            return 1 + contarCaracter(cadena + 1, caracter); // Si el carácter coincide, sumamos 1 y continuamos con el resto de la cadena.
        } else {
            return contarCaracter(cadena + 1, caracter); // Si el carácter no coincide, seguimos con el resto de la cadena.
        }
    }
}

int main(){
    printf("%d", contarCaracter("tetotes que vuelen", 'e'));
}