#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 50

void reverse(char s[]);

int main(void)
{
    int c, i;
    char *s;
    s = (char *)malloc(sizeof(char) * NUM);
    if (s == NULL)
    {
        printf("ERROR: No se pudo asignar memoria en el heap\n");
        return 1;
    }
    else
        printf("Direccion de memoria del heap %u\n", &s);
    printf("Bytes a utilizarse para almacenar la variable %d\n", sizeof(char) * NUM);
    for (i = 0; (c = getchar()) != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    printf("La cadena ingresada es: %s\n", s);
    reverse(s);
    printf("Cadena invertida: %s\n", s);
    free(s);
    printf("Memoria liberada correctamente.\n Saliendo...");
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        /* code */
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}