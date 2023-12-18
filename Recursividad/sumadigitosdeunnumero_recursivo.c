#include <stdio.h>

int suma_digitos(int n);
int main()
{
    int num = 123;
    int result = suma_digitos(num);
    printf("Sum of digits in %d is %d\n", num, result);
    return 0;
}

int suma_digitos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
        return (n % 10 + suma_digitos(n / 10));
}