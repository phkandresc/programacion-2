#include <stdio.h>

#define IN 1  // en una palabra
#define OUT 0// fuera de la palabra

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("Nuevas lineas: %i Palabras: %i Caracteres: %i\n", nl, nw, nc);
}
