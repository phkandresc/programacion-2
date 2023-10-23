#include <stdio.h>

int main(){
    int i=10, *ptr1=&i, j=50, *ptr4=&j;
    double d=50.5, *ptr2=&d;
    char ch='a', *ptr3=&ch;

    printf("Valor de ptr1 = %u\n", ptr1);
    printf("Valor de ptr2 = %u\n", ptr2);
    printf("Valor de ptr3 = %u\n", ptr3);
    printf("\n");
    printf("Valor de ptr1 +1= %u\n", ptr1+1);
    printf("Valor de ptr2 +1= %u\n", ptr2+1);
    printf("Valor de ptr3 +1= %u\n", ptr3+1);
    printf("\n");
    printf("Valor de ptr1 +2= %u\n", ptr1+2);
    printf("Valor de ptr2 +2= %u\n", ptr2+2);
    printf("Valor de ptr3 +2= %u\n", ptr3+2);
    printf("\n");
    printf("Valor de ptr4 %u\n", ptr4);
    printf("Valor de ptr1 %u\n", ptr1);
    printf("ptr4 - ptr1 = %d\n", ptr4-ptr1);
    printf("ptr1-ptr4 = %d\n", ptr1-ptr4);
    /*
    ptr4-ptr1= -4
    -4/4 bytes que es el numero de bytes para almacenar enteros
    Nos da -1, lo que quiere decir que entre ptr4 y ptr1 entra un entero
    */
}