#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    int (*operation)(int, int); // Declaración de un puntero a función

    operation = add;               // Asigna el puntero a función a la función 'add'
    int result1 = operation(5, 3); // Llama a 'add' a través del puntero

    operation = subtract;          // Asigna el puntero a función a la función 'subtract'
    int result2 = operation(7, 2); // Llama a 'subtract' a través del puntero

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    free(operation);
    return 0;
}
