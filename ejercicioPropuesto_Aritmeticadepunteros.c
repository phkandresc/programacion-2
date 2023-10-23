#include <stdio.h>

int main(){
    int i=10, j=20;
    int *ptr1=&i;
    printf("Direccion de i %u\n", &i);
    printf("Direccion de j %u\n", &j);
    j=(*ptr1)++;
    printf("j %d\n", j);
    j=(*ptr1);
    printf("j %d\n", j);
}