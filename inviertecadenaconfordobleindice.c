/*
Invierte la cadena s en el mismo lugar
Se hace uso de dos indices en el for
*/
#include <stdio.h>
#include <string.h>
void reverse(char s[]);

int main()
{
    char s[40] = {"Liga de Quito Campeon Sudamericana"};
    reverse(s);
    printf("Reverse: %s", s);
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        // Primero c toma el valor de s desde la posicion 0
        // Guarda este valor en una variable diferente para poder reescribir la posicion inicial
        c = s[i];
        /*
        Una vez hecho el backup de s, se intercambia la letra del principio de
        la cadena por la letra del final de cadena
        */
        s[i] = s[j];
        /*
        Ahora en la ultima posicion, se guarda la letra que estaba en primera
        posicion y guardamos en la variable c.
        */
        s[j] = c;
    }
}