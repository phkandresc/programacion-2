#include <stdio.h>

int addNumbers(int);
int main()
{
    int num;
    printf("Enter an positive integer\n");
    scanf("%d", &num);
    printf("Sum = %d", addNumbers(num));
    return 0;
}

int addNumbers(int n)
{
    int i, sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}