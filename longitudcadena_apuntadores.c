#include <stdio.h>
#include <stdlib.h>
int strlen(char *);

int main()
{
    char s[14] = {"Hola, a todos"};
    printf("longitud de cadena: %d", strlen(s));
    /*Se puede pasar como argumento la direccion de una
    parte del arreglo*/
}

/*Regresa la longitud de la cadena s*/
int strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++){
        n++;
    }
    return n;
}