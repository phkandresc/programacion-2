#include <stdio.h>
/* Este programa permite ingresar desde el teclado caracteres
los cuales se almacenan como una variable int, que representa
el codigo ascii que cada caracter, y despues con la funcion
putchar escribe el caracter en pantalla.
EOF significa end of file, su valor entero es -1, indica fin
de archivo*/
int main(){
    int c;
    while ((c = getchar()) != EOF){
        putchar(c);
        printf("Codigo ascii : %i\n", c);
    }
    printf("EOF\n");//Ctrl+D indica EOF
    return 0;
}