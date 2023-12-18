#include <stdio.h>
// Funcion recursiva que calcula el factorial de un numero
long factorial(int);
int main()
{
    long f;
    int n;
    printf("Ingrese un numero para encontrar su factorial\n");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("El factorial de numeros negativos no esta definido.\n");
    }
    else
    {
        f = factorial(n);
        printf("%d! = %ld\n", n, f);
    }
    return 0;
}

long factorial(int n)
{
    // Por definicion. El factorial de 0 es 1
    if (n == 0)
    {
        return 1;
    }
    else
    {
        printf("El valor de n es igual %d\n", n);
        return (n * factorial(n - 1));
    }
}
