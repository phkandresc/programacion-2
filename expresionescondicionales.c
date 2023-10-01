#include <stdio.h>

int main(){
    int a;
    int b;
    int z;
    a=4;
    b=4;
    int n = 1;
    z=(a>b)?a:b;
    printf("el numero mayor es %i\n", z);
    printf("Hay %d elemento%s.\n", n, n == 1 ? "" : "s");
}