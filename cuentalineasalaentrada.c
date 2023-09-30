#include <stdio.h>

int main(){
    int c;
    printf("En ejecucion\n");
    int nl=0;

    while ((c = getchar()) != EOF)
    {
        if(c == '\n'){
            ++nl;
        }
    }
    printf("\nNumero de nuevas lineas %i\n", nl);
    
}