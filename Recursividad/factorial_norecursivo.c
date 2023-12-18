#include <stdio.h>

long factorial(int);

int main()
{
    int number;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &number);
    printf("%d! = %ld\n", number, factorial(number));
    return 0;
}

long factorial(int number)
{
    int c;
    // Se deben multiplicar todos los numeros hasta 1
    long fact = 1;
    // Se multiplica desde 1 hasta el numero ingresado
    for (c = 1; c <= number; c++)
    {
        fact = fact * c;
    }
    return fact;
}